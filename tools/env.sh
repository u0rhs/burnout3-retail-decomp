# Sourced by the tools/*.sh scripts. Machine-specific settings go in tools/local.env (git-ignored), e.g.:
#   B3_MWCC_DIR=$HOME/compilers/mwcps2-3.0.1b119p   # folder holding mwccps2.exe (see docs/SETUP.md)
#   B3_LICENSE=$HOME/licenses/my-licence-file         # your own CodeWarrior licence file
_b3_here="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
[ -f "$_b3_here/local.env" ] && . "$_b3_here/local.env"
export B3_ROOT="${B3_ROOT:-$(dirname "$_b3_here")}"
export B3_ROOT_WIN="${B3_ROOT//\//\\}"          # wine-style form of B3_ROOT (after the Z: drive letter)
[ -n "${B3_MWCC_DIR:-}" ] && export B3_MWCC_DIR
if [ -n "${B3_LICENSE:-}" ]; then
    export B3_LICENSE
    export B3_LICENSE_WIN="Z:${B3_LICENSE//\//\\}"
fi
