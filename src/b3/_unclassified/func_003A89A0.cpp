// ZoomIn__18CB3SatNavComponentFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (func_003F5A20 returns an 8-byte pair by value, lanes read through inline accessors; constant pair built in a temporary and copied).

// lifter variant 0
// ZoomIn__18CB3SatNavComponentFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_003A89A0;
struct UnkStruct_003A89A0_1;
struct UnkStruct_003A89A0_3;
struct UnkStruct_D_004E2EA8;
struct UnkStruct_D_01E7A800;

struct UnkStruct_003A89A0_1 {
    float field_0;
    int field_4;
    unsigned char pad_8[0x4];
    float field_C;
    float field_10;
    unsigned char pad_14[0x4];
};

struct UnkStruct_D_004E2EA8 {
    int field_0;
};

struct UnkStruct_003A89A0_3 {
    float field_0;
    float field_4;
};

struct UnkStruct_D_01E7A800 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003A89A0 {
    unsigned char pad_0[0x18];
    float field_18;
    float field_1C;
    float field_20;
    float field_24;
    unsigned char pad_28[0x224];
    UnkStruct_003A89A0_3 * field_24C;
    unsigned char pad_250[0x4];
    int field_254;
    unsigned char pad_258[0x24];
    int field_27C;
    unsigned char pad_280[0x484];
    int field_704;
    unsigned char pad_708[0x1DC];
    unsigned char field_8E4;
    unsigned char pad_8E5[0x2];
    unsigned char field_8E7;
    unsigned char pad_8E8[0xCC];
    int field_9B4;
    int field_9B8;
};

extern UnkStruct_D_004E2EA8 D_004E2EA8;
extern UnkStruct_D_01E7A800 D_01E7A800;

extern "C" float func_003F58D0(int, int);
// [G] an 8-byte (x, y) pair returned by value (hidden result pointer in a0); likely a CGtV2d-like vector. The
// inline accessors are placeholders for unnamed inlines (retail reads each lane through an address register).
struct UnkStruct_003A89A0_V { float field_0[2]; UnkStruct_003A89A0_V() {} float func_003A89A0_inl0() const { return field_0[0]; } float func_003A89A0_inl1() const { return field_0[1]; } UnkStruct_003A89A0_V(float x, float y) { field_0[0] = x; field_0[1] = y; } };
extern "C" UnkStruct_003A89A0_V func_003F5A20(int, int);
extern "C" void func_003AB850(UnkStruct_003A89A0 *);
extern "C" void func_00284F50(void *);

extern "C" void ZoomIn__18CB3SatNavComponentFv(UnkStruct_003A89A0 * self)
{
    float s = 416.0f / func_003F58D0(self->field_254, self->field_27C);
    self->field_18 = s;
    self->field_1C = s;
    self->field_8E7 = 0;
    float a = func_003F5A20(self->field_254, self->field_27C).func_003A89A0_inl0();
    float b = func_003F5A20(self->field_254, self->field_27C).func_003A89A0_inl1();
    self->field_20 = -s * a;
    self->field_24 = -s * b;
    self->field_8E4 = 5;
    self->field_704 = 0;
    D_004E2EA8.field_0 = 0;
    self->field_9B4 = 0;
    self->field_9B8 = 0;
    func_003AB850(self);
    UnkStruct_003A89A0_3 * t2 = self->field_24C;
    if (t2 != 0) {
        *(UnkStruct_003A89A0_V *)t2 = UnkStruct_003A89A0_V(656.0f, 0.0f);
    }
    func_00284F50(&D_01E7A800);
}
