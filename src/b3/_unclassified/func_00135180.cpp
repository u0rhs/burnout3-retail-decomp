// func_00135180 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CB3HUDManager;
struct UnkStruct_00135180;
struct UnkStruct_00135180_2;
struct UnkStruct_D_004EB1E0;
struct UnkStruct_D_004EB1E1;
struct UnkStruct_D_004F509C;
struct UnkStruct_D_0051BAA5;
struct UnkStruct_D_0051BAA6;
struct UnkStruct_D_0051BAA8;
struct UnkStruct_D_0051BACC;
struct UnkStruct_D_0064EC9A;

class CB3HUDManager {
public:
    void Update(float);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004EB1E0 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00135180_2 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual void vfunc_20();
    virtual void vfunc_24();
    virtual int vfunc_28();
};

struct UnkStruct_D_0051BACC {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0064EC9A {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051BAA6 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051BAA8 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051BAA5 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004F509C {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004EB1E1 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00135180 {
    unsigned char pad_0[0x1B4];
    UnkStruct_00135180_2 * field_1B4;
};

extern UnkStruct_D_004EB1E0 D_004EB1E0;
extern UnkStruct_D_0051BACC D_0051BACC;
extern UnkStruct_D_0064EC9A D_0064EC9A;
extern UnkStruct_D_0051BAA6 D_0051BAA6;
extern UnkStruct_D_0051BAA8 D_0051BAA8;
extern UnkStruct_D_0051BAA5 D_0051BAA5;
extern UnkStruct_D_004F509C D_004F509C;
extern UnkStruct_D_004EB1E1 D_004EB1E1;
extern CB3HUDManager D_0066A3D0;

extern "C" void func_00134660(UnkStruct_00135180 *);

// 0x00135180
extern "C" void func_00135180(UnkStruct_00135180 * self)
{
    if (D_004EB1E0.field_0 != 0) {
        func_00134660(self);
        int r1 = self->field_1B4->vfunc_28();
        if (r1 != 0) {
            D_0051BACC.field_0 = 12;
        }
        if (D_0064EC9A.field_0 != 0) {
            if (D_0051BAA6.field_0 == 0) {
                D_0051BAA8.field_0 = 0;
                D_0051BAA5.field_0 = 1;
            }
        } else {
            if (D_0051BAA6.field_0 != 0) {
                D_0051BAA8.field_0 = 1;
                D_0051BAA5.field_0 = 0;
            }
        }
    }
    D_0066A3D0.Update(D_004F509C.field_0);
    if (D_004EB1E1.field_0 != 0) {
        self->field_1B4->vfunc_14();
    }
}
