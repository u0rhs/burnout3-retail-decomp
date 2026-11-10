// func_00435DB0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (single result var + shared call tail; inner switch cases 1,2,3 then default; element sub-struct at +0x3D0 via hoisted pointer; bool a==b compare).

// func_00435DB0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00435DB0;
struct UnkStruct_00435DB0_1;
struct UnkStruct_00435DB0_2;
struct UnkStruct_00435DB0_3;
struct UnkStruct_00435DB0_e0;
struct UnkStruct_D_0051BA44;
struct UnkStruct_D_00522660;

struct UnkStruct_00435DB0_1 {
    unsigned char pad_0[0x174];
    int field_174;
};

struct UnkStruct_00435DB0_2 {
    short field_0;
    unsigned char pad_2[0x6];
    int field_8;
};

struct UnkStruct_00435DB0_3 {
    unsigned char pad_0[0x27C0];
    int field_27C0;
};

struct UnkStruct_00435DB0_e0_3D0 {
    unsigned char pad_0[0x10C8];
    int field_10C8;
    unsigned char pad_10CC[0x5FC];
    int field_16C8;
};

struct UnkStruct_00435DB0_e0 {
    unsigned char pad_0[0x3D0];
    UnkStruct_00435DB0_e0_3D0 field_3D0;  // [G] sub-struct: retail addresses both fields from +0x3D0
    unsigned char pad_1A9C[0xD34];
};

struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x12A980];
    UnkStruct_00435DB0_e0 field_12A980[1];  // [G] element count unknown
};

struct UnkStruct_D_0051BA44 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00435DB0 {
    unsigned char pad_0[0x4];
    UnkStruct_00435DB0_1 * field_4;
    unsigned char pad_8[0x1C];
    UnkStruct_00435DB0_2 * field_24;
    UnkStruct_00435DB0_3 * field_28;
    unsigned char pad_2C[0x104];
    int field_130;
    int field_134;
};

extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_D_0051BA44 D_0051BA44;

extern "C" int func_00271A00(void *, int);
extern "C" void func_003D0960(void *, int, void *, int);

// 0x00435DB0
extern "C" int func_00435DB0(UnkStruct_00435DB0 * self)
{
    int r;
    switch (self->field_4->field_174) {
    case 2:
        r = func_00271A00(&D_0051BA44, self->field_24->field_0 + 813);
        self->field_134 = 1;
        switch (self->field_24->field_0) {
        case 1:
            self->field_130 = 1;
            break;
        case 2:
            self->field_130 = 2;
            break;
        case 3:
            self->field_130 = 3;
            break;
        default:
            self->field_130 = 4;
            break;
        }
        break;
    case 8: {
        UnkStruct_00435DB0_e0_3D0 * e = &D_00522660.field_12A980[1 - self->field_28->field_27C0].field_3D0;
        if (e->field_10C8 == 0) {
            return 0;
        }
        bool b = e->field_16C8 == 5;
        bool a = self->field_24->field_8 == 5;
        if (a == b) {
            r = func_00271A00(&D_0051BA44, 622);
            self->field_130 = 1;
        } else if (a) {
            r = func_00271A00(&D_0051BA44, 876);
            self->field_130 = 1;
        } else {
            r = func_00271A00(&D_0051BA44, 877);
            self->field_130 = 4;
        }
        break;
    }
    default:
        return 0;
    }
    func_003D0960(((char *)self + 0x30), 128, (void *)(r), 1);
    return 1;
}
