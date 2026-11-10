// NONMATCHING: cbFormatPPPStatus -- retail 29 / ours 30 instructions, 3 in changed runs
// 3 instrs off (30 vs 29): retail fills the bnez delay slot with the join block's 'daddu a0,s3' (buf arg); ours leaves nop and does addiu s0,6 after; ternary/else/split-call forms all identical
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

extern char D_004C69D8[];
extern "C" int strncmp(const char *, const char *, unsigned int);
extern "C" int snprintf(char *, unsigned int, const char *, ...);

extern "C" void cbFormatPPPStatus(char *buf, unsigned int size, const char *fmt, int unused, char *data)
{
    const char *s = data + 0x10C;
    if (strncmp(s, D_004C69D8, 5) == 0) {
        s += 6;
    }
    snprintf(buf, size, fmt, s);
}
