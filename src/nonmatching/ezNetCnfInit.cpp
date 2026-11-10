// NONMATCHING: ezNetCnfInit -- retail 56 / ours 54 instructions, 15 in changed runs
// structure right (out-of-line error arms, do-while rebind); remaining: retail tests BindRpc result with 'slt at,v0,zero; bnez' (ours bltz) and first test is bltz v0 w/ move s0 in delay slot, join bgez s0/move s0,0 layout
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

extern "C" {
extern char D_004C6B48[];
extern char D_004C6B58[];
extern char D_004C6B38[];
extern char D_004C6B60[];
extern char D_004C6B80[];
extern int D_004E2DEC;
extern int D_004E2DE8;
extern char D_01EA39C0[];
struct UnkStruct_01EA39E4 { int field_0; int pad[3]; };
extern UnkStruct_01EA39E4 D_01EA39E4;
int sceSifSearchModuleByName(char *);
int sceSifBindRpc(void *, unsigned int, unsigned int);
int scePrintf(char *, ...);
int ezNetCnfInit()
{
    int r = D_004E2DEC = sceSifSearchModuleByName(D_004C6B48);
    if (r < 0) {
        scePrintf(D_004C6B58, D_004C6B38);
        scePrintf(D_004C6B60, D_004C6B48);
        D_004E2DE8 = 0;
    } else {
        do {
            if (sceSifBindRpc(D_01EA39C0, 0x75499128, 0) < 0) {
                scePrintf(D_004C6B58, D_004C6B38);
                scePrintf(D_004C6B80);
            }
        } while (D_01EA39E4.field_0 == 0);
        D_004E2DE8 = 1;
    }
    if (r >= 0) r = 0;
    return r;
}
}
