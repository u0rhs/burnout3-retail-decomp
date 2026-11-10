// NONMATCHING: ezNetCnfGetProperties -- retail 77 / ours 78 instructions, 2 in changed runs
// 2 off (pass3a: InvalidDCache(c, v+0x133F) took 3->2): retail fills the alignment beqz delay slot with InvalidDCache's 'move a0,a2' (from the target block); ours leaves nop and keeps the move before the jal. Tried pointer-typed c, extra copies of c before the test (int w = c), inline test helper, goto/empty-then forms, full 15-pragma sweep: no change
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// [G] N182: scoped optimiser pragma found by the pragma sweep (psweep_all.py)
#pragma push
#pragma opt_propagation off
extern "C" {
extern char D_004C6B58[];
extern char D_004C6C80[];
extern char D_004C6BF0[];
extern char D_004C6BA0[];
extern char D_004C6BC0[];
extern int D_004E2DE8;
struct UnkStruct_01EA39C0 { int field_0; char pad_4[0xC]; };
extern UnkStruct_01EA39C0 D_01EA39C0;
struct UnkStruct_01EA3A00 { int field_0; char pad_4[0xC]; char field_10[0x100]; char field_110[0x70]; };
extern UnkStruct_01EA3A00 D_01EA3A00;
int scePrintf(char *, ...);
void InvalidDCache(int, int);
char *strncpy(char *, const char *, unsigned);
int sceSifCallRpc(void *, int, int, void *, int, void *, int, void *, void *);
int ezNetCnfGetProperties(char *a, char *b, void *c_)
{
    int c = (int)c_;
    UnkStruct_01EA3A00 *p = &D_01EA3A00;
    if (D_004E2DE8 == 0) {
        scePrintf(D_004C6B58, D_004C6C80);
        scePrintf(D_004C6BA0);
        return -1;
    }
    int v = c;
    if ((v & 0x3F) != 0) {
        scePrintf(D_004C6B58, D_004C6C80);
        scePrintf(D_004C6BF0, v, 0x40);
        return -22;
    }
    InvalidDCache(c, v + 0x133F);
    p->field_0 = v;
    strncpy(p->field_10, a, 0xFF);
    strncpy(p->field_110, b, 0x6F);
    sceSifCallRpc(&D_01EA39C0, 2, 0, p, 0x180, p, 4, 0, 0);
    scePrintf(D_004C6B58, D_004C6C80);
    scePrintf(D_004C6BC0, p->field_0);
    return p->field_0;
}
}

#pragma pop
