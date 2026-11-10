. "$(dirname "${BASH_SOURCE[0]:-$0}")/env.sh"
# Shared CodeWarrior flags for every compile in this repo (sourced by tools/compile_*.sh, compile_variant.sh,
# build_c_units.sh). -O4 -Cpp_exceptions off: N1. -inline level=8: N86 -- retail inlined deeper than the
# compiler's default (level 4); every proven unit compiles identically at 8, and the B3HeadingComponent
# render callbacks need >= 6.
MWCC_FLAGS="-O4 -str readonly -Cpp_exceptions off -inline level=8"

# Compile host (N165). MWCC b119's register tie-breaks differ between wine and native Windows; wibo
# (decompals/wibo, ~/tools/wibo/wibo) behaves exactly as native Windows. Retail was built natively on Windows, so the
# reference host is native/wibo. MWCC_HOST picks the default; a source's first-lines marker
# `// BUILD-HOST: wine` or `// BUILD-HOST: wibo` overrides it for that file.
MWCC_HOST="${MWCC_HOST:-wibo}"

_mwcc_unz() {   # Z:\some\path -> /some/path (wine-style path to a Linux path); anything else unchanged
    case "$1" in [Zz]:*) printf '%s' "${1#?:}" | tr '\\' '/' ;; *) printf '%s' "$1" ;; esac
}

# mwcc_run <mwccps2 arguments, wine-style Z:\ paths allowed>: run mwccps2.exe from the current directory (the
# compiler's) under the host the source asks for.
mwcc_run() {
    local a next=0 src="" host="$MWCC_HOST" lsrc
    for a in "$@"; do
        if [ $next = 1 ]; then src="$a"; next=0; fi
        [ "$a" = "-c" ] && next=1
    done
    lsrc=$(_mwcc_unz "$src")
    if [ -f "$lsrc" ]; then
        if head -5 "$lsrc" | grep -q '^// BUILD-HOST: wine'; then host=wine; fi
        if head -5 "$lsrc" | grep -q '^// BUILD-HOST: wibo'; then host=wibo; fi
    fi
    if [ "$host" = wine ]; then
        WINEDEBUG=-all wine mwccps2.exe "$@"
        return
    fi
    local args=()
    for a in "$@"; do args+=("$(_mwcc_unz "$a")"); done
    MWCIncludes="$(_mwcc_unz "${MWCIncludes:-Z:${B3_ROOT_WIN}\\include}")" \
    LM_LICENSE_FILE=${B3_LICENSE} \
        "$HOME/tools/wibo/wibo" "$PWD/mwccps2.exe" "${args[@]}"
}
