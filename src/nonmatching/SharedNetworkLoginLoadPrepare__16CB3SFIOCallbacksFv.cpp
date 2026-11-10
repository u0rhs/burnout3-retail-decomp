// NONMATCHING: SharedNetworkLoginLoadPrepare__16CB3SFIOCallbacksFv -- retail 59 / ours 59 instructions, 5 in changed runs
// near9: inline Close corrected to the proven func_003615B0 body (old archive returned gmbOpenedFile when set: wrong logic). Still 5 off like Create/SavePrepare: inline result joined in v1 (retail v0, call result used directly); ~25 shapes (if/else, switch, result locals, bool/uchar, auto_inline) no change
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// NONMATCHING: SharedNetworkLoginLoadPrepare__16CB3SFIOCallbacksFv -- retail 59 / ours 59 instructions, 5 in changed runs
// a103: 59/59, 5 instrs: same inlined-Close result register v1 vs v0 as SavePrepare | guard: ok | mwperm: 17 -> 5 ('if (CB3SFIOCallbacks::gmbOpenedFile == 0) {' -> 'if (CB3SFIOCallbacks::gmbOpenedFile) {')
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

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
// [C] returns the last call's status (0 = opened), as retail does: v0 at `jr $ra` (0x3618F4) is func_004656D0's result
// after either open (0x3618B0 / 0x3618CC, only an sb follows), func_00465960's when it is neither 0 nor 0x13 (0x36187C
// `bne $v0, $v1, .L003618F0`) or fails on the retry (0x3618A4), or the inlined close's (func_00465910) when it fails
// (0x361894 `bnez $v0`). CB3OnlineSelectLoginPage::UpdateRetrieveLogin tests it at 0x3476F4 (`beqz $v0`).
int CB3SFIOCallbacks::SharedNetworkLoginLoadPrepare()
{
    strcpy((char *)&D_01EA3FA0, D_004C74B0);
    strcpy((char *)&D_01EA3FB1, D_004C74B0);
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
        r = func_004656D0((void *)&D_01EA3FA0);
        CB3SFIOCallbacks::gmbOpenedFile = 1;
    } else if (r == 0x13) {
        r = func_003615B0_inl1();
        if (r == 0) {
            r = func_00465960(&args);
            if (r == 0) {
                r = func_004656D0((void *)&D_01EA3FA0);
                CB3SFIOCallbacks::gmbOpenedFile = 1;
            }
        }
    }
    return r;
}
