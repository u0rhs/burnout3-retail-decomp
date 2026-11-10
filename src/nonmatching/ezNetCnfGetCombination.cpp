// NONMATCHING: ezNetCnfGetCombination -- retail 44 / ours 45 instructions, 1 in changed runs
// 1 nop left: retail fills blez delay with 'slt at,v0,s0' from the next block; ours leaves nop (bnez slot now matches via m=n-1 in the || comma). Tried bool/int precomputed compare (slt v0), nested ifs, goto, else-forms, 15-pragma sweep
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// logic exact; delay slots: retail blez-delay=slt at, bnez-delay=addiu v1,s0,-1; ours puts addiu in blez delay and nop after bnez (1 changed run)

extern "C" {
extern char D_004C6B58[];
extern char D_004C6C20[];
extern char D_004C6C40[];
extern char D_004C6C50[];
int scePrintf(char *, ...);
struct UnkStruct_Cnf { int field_0; };
struct UnkStruct_Cnf_e { char pad_0[0xC8]; };
void *ezNetCnfGetCombination(UnkStruct_Cnf *p, int n)
{
    if (p == 0 || p->field_0 == 0) {
        scePrintf(D_004C6B58, D_004C6C20);
        scePrintf(D_004C6C40);
        return 0;
    }
    int m;
    if (n <= 0 || (m = n - 1, n > p->field_0)) {
        scePrintf(D_004C6B58, D_004C6C20);
        scePrintf(D_004C6C50, n);
        return 0;
    }
    return (char *)p + m * 0xC8 + 0x30;
}
}
