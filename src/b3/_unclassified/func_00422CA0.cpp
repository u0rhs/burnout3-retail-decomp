// func_00422CA0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (a66: CB3MCSlaveCheckForCardState::Action [L] DNAT medium; fix = single int Sync overload (void clash removed), one int local n for both Sync out-params, all cases break with default: return (the 'b L24; ld ra' exit), inner switches case 0 before 13 / 1,2,3 ascending (reverse test order)).

// lifter variant 0
// func_00422CA0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

enum EMemDevPollOrWait {};

class CMemoryDevicePS2;
struct UnkStruct_00422CA0_0;
struct UnkStruct_00422CA0_2;
struct UnkStruct_D_01EB5D00;
struct UnkStruct_D_01ECD520;

class CMemoryDevicePS2 {
public:
    int Sync(EMemDevPollOrWait, int*);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00422CA0_0 {
    unsigned char pad_0[0x4];
};

struct UnkStruct_D_01EB5D00 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14(int, int);
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00422CA0_2 {
    unsigned char pad_0[0x14];
    int field_14;
};

struct UnkStruct_D_01ECD520 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern UnkStruct_D_01EB5D00 D_01EB5D00;
extern UnkStruct_D_01ECD520 D_01ECD520;
extern CMemoryDevicePS2 D_005185A0;

extern "C" void func_00420B60(void *);
extern "C" int func_0030A8C0(void *);

// 0x00422CA0
extern "C" void func_00422CA0(UnkStruct_00422CA0_0 * self, int p0)
{
    int n;
    switch (p0) {
    case 0:
        break;
    case 3:
        func_00420B60(&D_01ECD520);
        D_005185A0.Sync((EMemDevPollOrWait)0, &n);
        break;
    case 4:
        switch (D_005185A0.Sync((EMemDevPollOrWait)0, &n)) {
        case 0:
            ((UnkStruct_D_01EB5D00 *)&D_01EB5D00)->vfunc_14(0, 0);
            break;
        case 13: {
            int r4 = func_0030A8C0(&D_005185A0);
            if (r4 == 9) {
                break;
            }
            switch (r4) {
            case 1:
                ((UnkStruct_D_01EB5D00 *)&D_01EB5D00)->vfunc_14(1, 0);
                break;
            case 2:
                ((UnkStruct_D_01EB5D00 *)&D_01EB5D00)->vfunc_14(3, 0);
                break;
            case 3:
                ((UnkStruct_D_01EB5D00 *)&D_01EB5D00)->vfunc_14(2, 0);
                break;
            default:
                ((UnkStruct_D_01EB5D00 *)&D_01EB5D00)->vfunc_14(4, 0);
                break;
            }
            break;
        }
        }
        break;
    case 5:
        break;
    case 2:
        break;
    default:
        return;
    }
}
