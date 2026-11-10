// func_0013CBC0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CB3HUDManager;
struct UnkStruct_0013CBC0;
struct UnkStruct_0013CBC0_3;
struct UnkStruct_D_004EB1E0;
struct UnkStruct_D_004EB1E1;
struct UnkStruct_D_004F509C;
struct UnkStruct_D_0051BACC;

class CB3HUDManager {
public:
    void Update(float);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004EB1E0 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004F509C {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0013CBC0_3 {
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

struct UnkStruct_D_004EB1E1 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0013CBC0 {
    unsigned char pad_0[0x1B4];
    UnkStruct_0013CBC0_3 * field_1B4;
};

extern UnkStruct_D_004EB1E0 D_004EB1E0;
extern UnkStruct_D_004F509C D_004F509C;
extern UnkStruct_D_0051BACC D_0051BACC;
extern UnkStruct_D_004EB1E1 D_004EB1E1;
extern CB3HUDManager D_0066A3D0;

extern "C" void func_00134660(UnkStruct_0013CBC0 *);

// 0x0013CBC0
extern "C" void func_0013CBC0(UnkStruct_0013CBC0 * self)
{
    if (D_004EB1E0.field_0 != 0) {
        func_00134660(self);
        D_0066A3D0.Update(D_004F509C.field_0);
        int r2 = self->field_1B4->vfunc_28();
        if (r2 != 0) {
            D_0051BACC.field_0 = 12;
        }
    }
    if (D_004EB1E1.field_0 != 0) {
        self->field_1B4->vfunc_14();
    }
}
