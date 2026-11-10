// NONMATCHING: ezNetCtlInit -- retail 56 / ours 57 instructions, 2 in changed runs
// son3: r=t coalesced via 'int t = r = search()'; tail ret var; left: retail steals lui a0 into bnez delay (1 instr shorter)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)



extern "C" {
extern char D_004C6CA8[];
extern char D_004C6CB8[];
extern char D_004C6C98[];
extern char D_004C6CC0[];
extern char D_004C6CE0[];
extern int m_modId;
extern int m_rpcRunning;
extern char D_01EA3D80[];
struct UnkStruct_01EA39E4 { int field_0; int pad[3]; };
extern UnkStruct_01EA39E4 D_01EA3DA4;
int sceSifSearchModuleByName(char *);
int sceSifBindRpc(void *, unsigned int, unsigned int);
int scePrintf(char *, ...);
int ezNetCtlInit()
{
    int r;
    int t = r = sceSifSearchModuleByName(D_004C6CA8);
    m_modId = t;
    if (t < 0) {
        scePrintf(D_004C6CB8, D_004C6C98);
        scePrintf(D_004C6CC0, D_004C6CA8);
        m_rpcRunning = 0;
    } else {
        do {
            int rc = sceSifBindRpc(D_01EA3D80, 0x75488909, 0);
            if (0 > rc) {
                scePrintf(D_004C6CB8, D_004C6C98);
                scePrintf(D_004C6CE0);
            }
        } while (D_01EA3DA4.field_0 == 0);
        m_rpcRunning = 1;
    }
    int ret;
    if (r < 0) ret = r; else { r = 0; ret = r; }
    return ret;
}
}
