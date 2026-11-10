// func_00422070 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (Hand-written memory-card read state machine: outer switch in source order 0,3,4,5,2 with returns, inner switch on field_14, block-form if (r == 0) {...} (early returns pushed the bodies out of line), error dialog as a static inline, func_00420B60 gets p0 itself, buffer descriptor typed char* / unsigned int (fixes the field_4-before-field_8 load order)).

// func_00422070 -- hand-written from the retail structure (lifted draft failed to compile: D_01ECD580.field_0
// typed as a struct pointer but compared with &D_01ECD56C, "type mismatch").
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

enum EMemDevPollOrWait {};

class CMemoryCardFileBase;
class CMemoryDevicePS2;
struct UnkStruct_00422070;
struct UnkStruct_00422070_4;
struct UnkStruct_00422070_5;
struct UnkStruct_00422070_6;
struct UnkStruct_D_01EB5D00;
struct UnkStruct_D_01ECD520;
struct UnkStruct_D_01ECD57C;
struct UnkStruct_D_01ECD580;

class CMemoryCardFileBase {
public:
    const char * GetFullFilename();

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CMemoryDevicePS2 {
public:
    int OpenFile(const char*, unsigned int, unsigned int);
    int Sync(EMemDevPollOrWait, int*);
    int Read(char*, unsigned int, unsigned int);
    int CloseFile();

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01ECD57C {
    void * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01ECD580 {
    void * field_0;
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

struct UnkStruct_00422070_4 {
    unsigned char pad_0[0x4];
};

struct UnkStruct_00422070_5 {
    unsigned char pad_0[0x14];
    int field_14;
};

struct UnkStruct_00422070_6 {
    unsigned char pad_0[0x4];
    char * field_4;
    unsigned int field_8;
};

struct UnkStruct_D_01ECD520 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00422070 {
    unsigned char pad_0[0x14];
    int field_14;
};

extern UnkStruct_D_01ECD57C D_01ECD57C;
extern UnkStruct_D_01ECD580 D_01ECD580;
extern UnkStruct_D_01EB5D00 D_01EB5D00;
extern UnkStruct_D_01ECD520 D_01ECD520;
extern CMemoryCardFileBase D_01ECD56C;
extern CMemoryDevicePS2 D_005185A0;

extern "C" void func_00420B60(void *, int, int, int);
extern "C" int func_00420FC0(void *, int);

// [G] inlined error path, placeholder name
static inline void func_00422070_inl1(UnkStruct_00422070 * self)
{
    ((UnkStruct_D_01EB5D00 *)&D_01EB5D00)->vfunc_14(15, 0);
    self->field_14 = 3;
}

// 0x00422070
extern "C" void func_00422070(UnkStruct_00422070 * self, int p0)
{
    int status;
    switch (p0) {
    case 0:
        return;
    case 3:
        func_00420B60(&D_01ECD520, p0, 4, 2);
        D_01ECD57C.field_0 = &D_01ECD57C;
        D_01ECD580.field_0 = &D_01ECD56C;
        if (D_005185A0.OpenFile(D_01ECD56C.GetFullFilename(), 1, 0) == 0) {
            func_00422070_inl1(self);
        } else {
            self->field_14 = 0;
        }
        break;
    case 4:
        switch (self->field_14) {
        case 3:
            return;
        case 4:
            return;
        case 0: {
            int r = D_005185A0.Sync((EMemDevPollOrWait)0, &status);
            if (r == 4) {
                return;
            }
            if (r == 13) {
                func_00422070_inl1(self);
                break;
            }
            if (r == 0) {
                UnkStruct_00422070_6 * f = (UnkStruct_00422070_6 *)D_01ECD580.field_0;
                if (D_005185A0.Read((char *)f->field_4, f->field_8, 0) == 0) {
                    func_00422070_inl1(self);
                } else {
                    self->field_14 = 1;
                }
            }
            break;
        }
        case 1: {
            int r = D_005185A0.Sync((EMemDevPollOrWait)0, &status);
            if (r == 7) {
                return;
            }
            if (r == 13) {
                func_00422070_inl1(self);
                break;
            }
            if (r == 0) {
                if (D_005185A0.CloseFile() == 0) {
                    func_00422070_inl1(self);
                } else {
                    self->field_14 = 2;
                }
            }
            break;
        }
        case 2: {
            int r = D_005185A0.Sync((EMemDevPollOrWait)0, &status);
            if (r == 5) {
                return;
            }
            if (r == 13) {
                func_00422070_inl1(self);
                break;
            }
            if (r == 0 && D_01ECD580.field_0 == &D_01ECD56C) {
            switch (func_00420FC0(&D_01ECD520, 0)) {
            case 0:
                ((UnkStruct_D_01EB5D00 *)&D_01EB5D00)->vfunc_14(16, 0);
                self->field_14 = 4;
                break;
            case 1:
                ((UnkStruct_D_01EB5D00 *)&D_01EB5D00)->vfunc_14(17, 0);
                self->field_14 = 4;
                break;
            case 2:
                ((UnkStruct_D_01EB5D00 *)&D_01EB5D00)->vfunc_14(18, 0);
                self->field_14 = 3;
                break;
            }
            }
            break;
        }
        }
        break;
    case 5:
        return;
    case 2:
        return;
    }
}
