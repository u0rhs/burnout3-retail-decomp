// NONMATCHING: ezNetCtlWaitEventTO -- retail 49 / ours 50 instructions, 2 in changed runs
// exact except one delay slot: retail hoists lui a0 (D_004C6CB8) of the error block into the bne delay slot; ours nop + lui in block (1 changed run, 2 instrs); 12 variants
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

extern "C" {
extern int m_rpcRunning;
extern char D_004C6CB8[];
extern char D_004C6E10[];
extern char D_004C6D30[];
extern char D_004C6D18[];
struct UnkStruct_01EA3DC0 { int field_0; int pad[3]; };
extern UnkStruct_01EA3DC0 D_01EA3DC0;
extern char D_01EA3D80[];
int scePrintf(char *, ...);
int sceSifCallRpc(void *, int, int, void *, int, void *, int, int, int);
int ezNetCtlWaitEventTO(int to)
{
    UnkStruct_01EA3DC0 *p = &D_01EA3DC0;
    if (m_rpcRunning == 0) {
        scePrintf(D_004C6CB8, D_004C6E10);
        scePrintf(D_004C6D30);
        return -1;
    }
    p->field_0 = to;
    sceSifCallRpc(D_01EA3D80, 4, 0, p, 4, p, 4, 0, 0);
    if (p->field_0 != -1) {
        scePrintf(D_004C6CB8, D_004C6E10);
        scePrintf(D_004C6D18, p->field_0);
    }
    return p->field_0;
}
}
