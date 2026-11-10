// NONMATCHING: ezNetCnfGetCombinationList -- retail 74 / ours 75 instructions, 2 in changed runs
// son2: 10 -> 2. Clean source (no mwperm temps): scoped opt_propagation off [G], 'int v = c;' after the init test, InvalidDCache(c, v + 0x7FF) (retail a0 = original a2). Left: retail fills the beqz delay slot with 'move a0,a2' (ours nop, move placed before jal; +1 instr); tried e=v+0x7FF, v declaration, 0x7FF+v, 15-pragma sweep
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

extern "C" {
extern char D_004C6B58[];
extern char D_004C6BD0[];
extern char D_004C6BF0[];
extern char D_004C6BA0[];
extern char D_004C6BC0[];
extern int D_004E2DE8;
struct UnkStruct_01EA39C0 { int field_0; char pad_4[0xC]; };
extern UnkStruct_01EA39C0 D_01EA39C0;
struct UnkStruct_01EA3A00 { int field_0; char *field_4; char pad_8[8]; char field_10[0x100]; };
extern UnkStruct_01EA3A00 D_01EA3A00;
int scePrintf(char *, ...);
void InvalidDCache(int, int);
char *strncpy(char *, const char *, unsigned);
int sceSifCallRpc(void *, int, int, void *, int, void *, int, void *, void *);
#pragma push
#pragma opt_propagation off
int ezNetCnfGetCombinationList(char *a, int b_, void *c_)
{
    char * b = (char *)b_;
    int c = (int)c_;
    UnkStruct_01EA3A00 *p = &D_01EA3A00;
    if (D_004E2DE8 == 0) {
        scePrintf(D_004C6B58, D_004C6BD0);
        scePrintf(D_004C6BA0);
        return -1;
    }
    
    int v = c;
    if (v & 0x3F) {
        scePrintf(D_004C6B58, D_004C6BD0);
        scePrintf(D_004C6BF0, v, 0x40);
        return -22;
    }
    InvalidDCache(c, v + 0x7FF);
    p->field_0 = v;
    p->field_4 = b;
    strncpy(p->field_10, a, 0xFF);
    sceSifCallRpc(&D_01EA39C0, 1, 0, p, 0x180, p, 4, 0, 0);
    scePrintf(D_004C6B58, D_004C6BD0);
    scePrintf(D_004C6BC0, p->field_0);
    return p->field_0;
}
#pragma pop
}
