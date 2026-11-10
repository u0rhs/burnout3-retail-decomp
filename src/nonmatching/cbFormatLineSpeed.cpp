// NONMATCHING: cbFormatLineSpeed -- retail 40 / ours 40 instructions, 2 in changed runs
// s321: 40/40, 2 off. 'char *p = s + n;' before the z test fills retail's bnez delay slot (was nop, 41/40); left: p lands in a1 (retail reuses z's v1). Tried p before/after z, split decls, function-scope decls, inline isspace, char/ptr temps, goto, 8 opt_* pragmas
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

extern "C" {
extern char D_004B3458[];
int strlen(const char *);
void snprintf(char *, int, char *, int);
void cbFormatLineSpeed(char *buf, int size, char *fmt, int a3, char *base)
{
    char *s = base + 0x15C;
    int n = strlen(s);
    for (;;) {
        int z = (n != 0) ^ 1;
        char *p = s + n;
        if (z) break;
        if ((D_004B3458[1 + p[-1]] & 8) == 0) break;
        n--; s[n] = 0;
    }
    snprintf(buf, size, fmt, (int)s);
}
}
