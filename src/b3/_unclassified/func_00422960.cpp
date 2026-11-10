// func_00422960 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (nested switches (returns vs breaks per case), r==9/r==10 if-chain, file-record cursor advanced with ++ into a local, p < end then-block first, 528 > 584 compare order).

// func_00422960 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
enum EMemDevPollOrWait {};
class CMemoryCardFileBase;
class CMemoryDevicePS2;
struct UnkStruct_00422960;
struct UnkStruct_00422960_5;
struct UnkStruct_00422960_6;
struct UnkStruct_00422960_7;
struct UnkStruct_D_01EB5D00;
struct UnkStruct_D_01ECD520;
struct UnkStruct_D_01ECD528;
struct UnkStruct_D_01ECD56C;
struct UnkStruct_D_01ECD57C;
struct UnkStruct_D_01ECD580;
struct UnkStruct_D_01ECD584;
class CMemoryDevicePS2 {
public:
    int GetFreeSpace();
    int GetFileSize(const char*);
    int Sync(EMemDevPollOrWait, int*);
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};
class CMemoryCardFileBase {
public:
    const char * GetFullFilename();
    unsigned char pad_0[0x8];
    int field_8;
    unsigned char pad_C[0x4];
};
struct UnkStruct_D_01ECD57C {
    CMemoryCardFileBase * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};
struct UnkStruct_D_01ECD580 {
    CMemoryCardFileBase * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};
struct UnkStruct_D_01ECD584 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};
struct UnkStruct_D_01EB5D00 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14(int, int);
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};
struct UnkStruct_00422960_5 {
    int field_0;
};

struct UnkStruct_00422960_7 {
    unsigned char pad_0[0x14];
    int field_14;
};
struct UnkStruct_D_01ECD528 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};
struct UnkStruct_D_01ECD520 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00422960 {
    unsigned char pad_0[0x10];
    int field_10;
};
extern UnkStruct_D_01ECD57C D_01ECD57C;
extern UnkStruct_D_01ECD580 D_01ECD580;
extern UnkStruct_D_01ECD584 D_01ECD584;
extern UnkStruct_D_01EB5D00 D_01EB5D00;
extern UnkStruct_D_01ECD528 D_01ECD528;
extern UnkStruct_D_01ECD520 D_01ECD520;
extern CMemoryCardFileBase D_01ECD56C;
extern CMemoryCardFileBase D_01ECD52C;
extern CMemoryDevicePS2 D_005185A0;
extern "C" void func_00420B60(void *);
extern "C" int func_0030A8C0(void *);

// 0x00422960
extern "C" void func_00422960(UnkStruct_00422960 * self, int p0)
{
    switch (p0) {
    case 0:
        return;
    case 3:
        func_00420B60(&D_01ECD520);
        D_01ECD57C.field_0 = &D_01ECD56C;
        D_01ECD580.field_0 = &D_01ECD52C;
        D_01ECD584.field_0 = D_005185A0.GetFreeSpace();
        if (D_005185A0.GetFileSize(D_01ECD52C.GetFullFilename()) != 0) {
            self->field_10 = 1;
        } else {
            ((UnkStruct_D_01EB5D00 *)&D_01EB5D00)->vfunc_14(6, 0);
            self->field_10 = 0;
        }
        break;
    case 4:
        switch (self->field_10) {
        case 1: {
            int n;
            switch (D_005185A0.Sync((EMemDevPollOrWait)0, &n)) {
            case 11:
                return;
            case 13:
                int r = func_0030A8C0(&D_005185A0);
                if (r == 9) {
                    if (D_01ECD580.field_0->field_8 != 0) {
                        ((UnkStruct_D_01EB5D00 *)&D_01EB5D00)->vfunc_14(9, 0);
                    } else if (D_01ECD528.field_0 > D_01ECD584.field_0) {
                        ((UnkStruct_D_01EB5D00 *)&D_01EB5D00)->vfunc_14(7, 0);
                    } else {
                        ((UnkStruct_D_01EB5D00 *)&D_01EB5D00)->vfunc_14(8, 0);
                    }
                    self->field_10 = 2;
                } else if (r == 10) {
                    ((UnkStruct_D_01EB5D00 *)&D_01EB5D00)->vfunc_14(9, 0);
                    self->field_10 = 2;
                } else {
                    ((UnkStruct_D_01EB5D00 *)&D_01EB5D00)->vfunc_14(6, 0);
                    self->field_10 = 0;
                }
                break;
            case 0:
                if (n != D_01ECD580.field_0->field_8) {
                    ((UnkStruct_D_01EB5D00 *)&D_01EB5D00)->vfunc_14(9, 0);
                    self->field_10 = 2;
                    return;
                }
                CMemoryCardFileBase * p = ++D_01ECD580.field_0;
                if (p < D_01ECD57C.field_0) {
                    if (D_005185A0.GetFileSize(p->GetFullFilename()) == 0) {
                        ((UnkStruct_D_01EB5D00 *)&D_01EB5D00)->vfunc_14(6, 0);
                        self->field_10 = 0;
                    }
                } else {
                    ((UnkStruct_D_01EB5D00 *)&D_01EB5D00)->vfunc_14(5, 0);
                    self->field_10 = 2;
                    break;
                }
                return;
            }
            break;
        }
        case 0:
            return;
        case 2:
            return;
        }
        break;
    case 5:
        return;
    case 2:
        return;
    }
}
