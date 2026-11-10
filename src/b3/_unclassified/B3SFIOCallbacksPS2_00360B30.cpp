// CB3SFIOCallbacks::SFIOProcessCallback(SFIOProcessE*,int*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3SFIOCallbacksPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (re-queued after the jtbl_retarget 2-table fix (from build/vt/hand/SFIOProcessCallback__16CB3SFIOCa_0ac08fd_l264sf0.cpp)).

enum EMemDevPollOrWait {};
enum SFIOProcessE {};
class CMemoryDevicePS2 {
public:
    int GetFreeSpace();
    int Sync(EMemDevPollOrWait, int*);
    unsigned char pad_0[0x10];
};
extern CMemoryDevicePS2 D_005185A0;
struct UnkStruct_D_01EA3FD0 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_01EA3FD0 D_01EA3FD0;
struct UnkStruct_003610B0_0 { int field_0; };
extern "C" int func_0030A8C0(CMemoryDevicePS2 *);
extern "C" int func_00467010(void *);
extern "C" int SLoginStatePreviousGet(int *);
extern unsigned char D_004E2E14;
extern unsigned char D_004E2E10;
class CB3SFIOCallbacks {
public:
    static int SFIOProcessCallback(SFIOProcessE *, int *);
    static int gmeError;
    static int gmeLastOperation;
    static int gmeProcess;
    static int gmnFreeSpace;
    static int gmnOffset;
};

static inline void func_00360B30_inl1(int r)
{
    switch (r) {
    case 1: CB3SFIOCallbacks::gmeProcess = 2; CB3SFIOCallbacks::gmeError = 3; break;
    case 2: CB3SFIOCallbacks::gmeError = 0; CB3SFIOCallbacks::gmeProcess = 1; break;
    case 3: CB3SFIOCallbacks::gmeProcess = 2; CB3SFIOCallbacks::gmeError = 3; break;
    case 4: CB3SFIOCallbacks::gmeProcess = 2; CB3SFIOCallbacks::gmeError = 0xB; break;
    case 5: CB3SFIOCallbacks::gmeProcess = 2; CB3SFIOCallbacks::gmeError = 0xA; break;
    case 6: CB3SFIOCallbacks::gmeProcess = 2; CB3SFIOCallbacks::gmeError = 0xA; break;
    case 7: CB3SFIOCallbacks::gmeProcess = 2; CB3SFIOCallbacks::gmeError = 0x11; break;
    case 8: CB3SFIOCallbacks::gmeProcess = 2; CB3SFIOCallbacks::gmeError = 9; break;
    case 9: CB3SFIOCallbacks::gmeError = 0; CB3SFIOCallbacks::gmeProcess = 2; break;
    case 10: CB3SFIOCallbacks::gmeProcess = 2; CB3SFIOCallbacks::gmeError = 0xA; break;
    case 11: CB3SFIOCallbacks::gmeProcess = 2; CB3SFIOCallbacks::gmeError = 0xE; break;
    case 12: CB3SFIOCallbacks::gmeProcess = 2; CB3SFIOCallbacks::gmeError = 0xA; break;
    case 0:
    default: CB3SFIOCallbacks::gmeProcess = 2; CB3SFIOCallbacks::gmeError = 0x11; break;
    }
}

// 0x00360B30
int CB3SFIOCallbacks::SFIOProcessCallback(SFIOProcessE *p0, int *p1)
{
    int res;
    int prev;
    SLoginStatePreviousGet(&prev);
    *p1 = 0;
    if (D_004E2E14 != 0) {
        int r = D_005185A0.Sync((EMemDevPollOrWait)0, &res);
        switch (r) {
        case 0:
            gmeProcess = 2;
            D_004E2E14 = 0;
            gmeError = 0;
            *p1 = D_005185A0.GetFreeSpace();
            break;
        case 13:
            func_00360B30_inl1(func_0030A8C0(&D_005185A0));
            break;
        default:
            break;
        }
    } else if (gmeLastOperation == 0) {
        int fs = gmnFreeSpace;
        if (fs != -1) {
            gmeError = 0;
            gmeProcess = 2;
            *p1 = fs;
            gmnFreeSpace = -1;
        }
    } else {
        int r = D_005185A0.Sync((EMemDevPollOrWait)0, &res);
        switch (r) {
        case 0:
            switch (gmeLastOperation) {
            case 2: gmeError = 0; gmeProcess = 2; break;
            case 3: gmeError = 0; gmeProcess = 2; break;
            case 4: gmeError = 0; D_004E2E10 = 1; gmeProcess = 2; break;
            case 5: D_004E2E10 = 0; gmeProcess = 2; gmeError = 0; break;
            case 6: gmeError = 0; gmeProcess = 2; break;
            case 8:
                gmeError = 0; gmeProcess = 2; *p1 = res;
                if (prev == 0) {
                    if (gmnOffset == 0 || gmnOffset == 29) {
                        if (res == 0x3A) *p1 = 0x1D;
                    }
                }
                break;
            case 9: gmeError = 0; gmeProcess = 2; break;
            case 10: gmeError = 0; gmeProcess = 2; break;
            case 11: gmeError = 0; gmeProcess = 2; break;
            case 7: gmeError = 0; gmeProcess = 2; *p1 = res; break;
            case 12:
                if (func_00467010(&D_01EA3FD0) != 0) {
                    gmeError = 0; gmeProcess = 2; *p1 = 1;
                } else {
                    gmeProcess = 2; gmeError = 4;
                }
                break;
            case 1: gmeError = 0; gmeProcess = 2; break;
            case 0:
                if (D_005185A0.GetFreeSpace() > -1) {
                    gmnFreeSpace = D_005185A0.GetFreeSpace();
                }
                break;
            }
            break;
        case 13:
            func_00360B30_inl1(func_0030A8C0(&D_005185A0));
            break;
        case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10: case 11: case 12:
            break;
        default:
            break;
        }
    }
    *p0 = (SFIOProcessE)gmeProcess;
    return gmeError;
}
