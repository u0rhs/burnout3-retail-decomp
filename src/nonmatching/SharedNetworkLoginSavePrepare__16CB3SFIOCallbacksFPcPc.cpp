// NONMATCHING: SharedNetworkLoginSavePrepare__16CB3SFIOCallbacksFPcPc -- retail 61 / ours 61 instructions, 5 in changed runs
// a103: 61/61, 5 instrs: inlined Close (func_003615B0) result lives in v1 (lbu/move/move-after-jal), retail keeps it in v0 with a nop delay
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
extern "C" int func_004655C0(void *);
extern "C" int func_004656D0(void *);
struct UnkStruct_gmCallbacks { void *pad_0[4]; };
extern "C" UnkStruct_gmCallbacks gmCallbacks__16CB3SFIOCallbacks;
class CB3SFIOCallbacks {
public:
    static int gmnOffset;
    static int gmnFreeSpace;
    static unsigned char gmbOpenedFile;
    static void SharedNetworkLoginSavePrepare(char *, char *);
    static int SharedNetworkLoginLoadPrepare();
};
static inline int func_003615B0_inl1()
{
    if (CB3SFIOCallbacks::gmbOpenedFile == 0) {
        return 0;
    }
    CB3SFIOCallbacks::gmbOpenedFile = 0;
    int r0 = func_00465910();
    return r0;
}
void CB3SFIOCallbacks::SharedNetworkLoginSavePrepare(char *p0, char *p1)
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
    int r = func_00465960(&args);
    if (r == 0) {
        func_004655C0((void *)&D_01EA3FA0);
        CB3SFIOCallbacks::gmbOpenedFile = 1;
        return;
    }
    if (r == 0x13) {
        if (func_003615B0_inl1() == 0) {
            if (func_00465960(&args) == 0) {
                func_004655C0((void *)&D_01EA3FA0);
                CB3SFIOCallbacks::gmbOpenedFile = 1;
            }
        }
    }
}
