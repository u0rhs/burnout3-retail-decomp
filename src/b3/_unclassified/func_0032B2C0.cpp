// func_0032B2C0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (early returns; (Up&&f)||(Down&&f) share one return 15; GetMenuConfirm bool; if(t!=8) v=table else v=C+6).

// lifter variant 0
// func_0032B2C0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CB3InputManager;
struct UnkStruct_0032B2C0;
struct UnkStruct_0032B2C0_e0;
struct UnkStruct_D_004A4A10;

class CB3InputManager {
public:
    int GetMenuUp(signed char);
    int GetMenuDown(signed char);
    bool GetMenuConfirm(signed char);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0032B2C0_e0 {
    int field_0[1];  // [G] element count unknown
    unsigned char pad_4[0x4];
};

struct UnkStruct_D_004A4A10 {
    UnkStruct_0032B2C0_e0 field_0[1];  // [G] element count unknown
    unsigned char pad_8[0x8];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0032B2C0 {
    unsigned char pad_0[0xA];
    unsigned char field_A;
    unsigned char pad_B[0x1];
    unsigned short field_C;
    unsigned char pad_E[0x86];
    signed char field_94;
};

extern UnkStruct_D_004A4A10 D_004A4A10;
extern CB3InputManager D_004F50C0;

extern "C" int func_00319360(void *);
extern "C" int func_00319330(void *);

// 0x0032B2C0
extern "C" int func_0032B2C0(UnkStruct_0032B2C0 * self, int p0)
{
    if (self->field_A == 0) return 15;
    if ((D_004F50C0.GetMenuUp((signed char)p0) && func_00319360((char *)self + 0xC)) ||
        (D_004F50C0.GetMenuDown((signed char)p0) && func_00319330((char *)self + 0xC))) return 15;
    if (D_004F50C0.GetMenuConfirm((signed char)p0) != false) {
        signed char t = self->field_94;
        int v;
        if (t != 8) v = D_004A4A10.field_0[t].field_0[self->field_C];
        else v = self->field_C + 6;
        return v;
    }
    return 15;
}
