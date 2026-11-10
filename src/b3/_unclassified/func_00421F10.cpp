// func_00421F10 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (nested switch on field_10 (cases 1,2/3 reverse order), r3 tests nested under r3!=9, func_00420B60 one arg).

// func_00421F10 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

enum EMemDevPollOrWait {};

class CMemoryDevicePS2;
struct UnkStruct_00421F10;
struct UnkStruct_00421F10_3;
struct UnkStruct_D_01EB5D00;
struct UnkStruct_D_01ECD520;

class CMemoryDevicePS2 {
public:
    int Format();
    int Sync(EMemDevPollOrWait, int*);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EB5D00 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14(int, int);
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00421F10_3 {
    unsigned char pad_0[0x14];
    int field_14;
};

struct UnkStruct_D_01ECD520 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00421F10 {
    unsigned char pad_0[0x10];
    int field_10;
};

extern UnkStruct_D_01EB5D00 D_01EB5D00;
extern UnkStruct_D_01ECD520 D_01ECD520;
extern CMemoryDevicePS2 D_005185A0;

extern "C" void func_00420B60(void *);

// 0x00421F10
extern "C" void func_00421F10(UnkStruct_00421F10 * self, int p0)
{
    int local;
    switch (p0) {
    case 3:
        func_00420B60(&D_01ECD520);
        if (D_005185A0.Format() == 0) {
            ((UnkStruct_D_01EB5D00 *)&D_01EB5D00)->vfunc_14(13, 0);
            self->field_10 = 2;
        } else {
            self->field_10 = 1;
        }
        break;
    case 4:
        switch (self->field_10) {
        case 1:
            int r3 = D_005185A0.Sync((EMemDevPollOrWait)0, &local);
            if (r3 != 9) {
                if (r3 == 13) {
                    ((UnkStruct_D_01EB5D00 *)&D_01EB5D00)->vfunc_14(13, 0);
                    self->field_10 = 2;
                } else if (r3 == 0) {
                    ((UnkStruct_D_01EB5D00 *)&D_01EB5D00)->vfunc_14(14, 0);
                    self->field_10 = 3;
                }
            }
            break;
        case 2:
        case 3:
            return;
        }
        break;
    case 5:
    case 2:
        return;
    default:
        break;
    }
}
