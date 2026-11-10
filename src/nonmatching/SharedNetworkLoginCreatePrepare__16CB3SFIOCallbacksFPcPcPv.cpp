// NONMATCHING: SharedNetworkLoginCreatePrepare__16CB3SFIOCallbacksFPcPcPv -- retail 70 / ours 70 instructions, 5 in changed runs
// 5 instrs: same as Save/Load siblings: inlined Close result in v1 (lbu/move/move-after-jal) vs retail v0 with nop delay; memset must follow gmbOpenedFile=0 (sb in memset delay slot)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)


struct UnkStruct_D_01EA3FA0 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01EA3FB1 { unsigned char pad_0[0x10]; };
struct UnkStruct_SFIOOpenArgs { void *field_0; int field_4; };
extern UnkStruct_D_01EA3FA0 D_01EA3FA0;
extern UnkStruct_D_01EA3FB1 D_01EA3FB1;
extern char D_004C74B0[];
extern unsigned char D_004E2E10;
extern unsigned char D_004E2E14;
extern "C" char * strcpy(char *, const char *);
extern "C" int func_00465910();
extern "C" int func_00465960(UnkStruct_SFIOOpenArgs *);
extern "C" int func_00465740(void *, void *);
extern "C" void *memset(void *, int, unsigned);
extern char D_01EA4020[];
extern "C" int func_004656D0(void *);
struct UnkStruct_gmCallbacks { void *pad_0[4]; };
extern "C" UnkStruct_gmCallbacks gmCallbacks__16CB3SFIOCallbacks;
class CB3SFIOCallbacks {
public:
    static int gmnOffset;
    static int gmnFreeSpace;
    static unsigned char gmbOpenedFile;
    static int SharedNetworkLoginCreatePrepare(char *, char *, void *);
    static int SharedNetworkLoginLoadPrepare();
};
static inline int func_003615B0_inl1()
{
    if (CB3SFIOCallbacks::gmbOpenedFile == 0) {
        return 0;
    }
    CB3SFIOCallbacks::gmbOpenedFile = 0;
    return func_00465910();
}
// [C] returns the last call's status (0 = opened), as retail does: v0 at `jr $ra` (0x361700) is func_00465740's result
// after either open (0x3616B0 / 0x3616D0, only an sb follows), func_00465960's when it is neither 0 nor 0x13 (0x361678
// `bne $v0, $v1, .L003616F4`) or fails on the retry (0x3616A0), or the inlined close's (func_00465910) when it fails
// (0x361690 `bnez $v0`). func_0037D1F0 tests it at 0x37D3F4 (`beqz $v0`).
int CB3SFIOCallbacks::SharedNetworkLoginCreatePrepare(char *p0, char *p1, void *p2)
{
    strcpy((char *)&D_01EA3FA0, p0);
    strcpy((char *)&D_01EA3FB1, p1);
    UnkStruct_SFIOOpenArgs args;
    args.field_4 = 0;
    args.field_0 = &gmCallbacks__16CB3SFIOCallbacks;
    CB3SFIOCallbacks::gmnOffset = 0;
    CB3SFIOCallbacks::gmnFreeSpace = -1;
    D_004E2E10 = 0;
    D_004E2E14 = 0;
    CB3SFIOCallbacks::gmbOpenedFile = 0;
    memset(D_01EA4020, 0, 0x3A);
    int r = func_00465960(&args);
    if (r == 0) {
        r = func_00465740(p2, (void *)&D_01EA3FA0);
        CB3SFIOCallbacks::gmbOpenedFile = 1;
    } else if (r == 0x13) {
        r = func_003615B0_inl1();
        if (r == 0) {
            r = func_00465960(&args);
            if (r == 0) {
                r = func_00465740(p2, (void *)&D_01EA3FA0);
                CB3SFIOCallbacks::gmbOpenedFile = 1;
            }
        }
    }
    return r;
}
