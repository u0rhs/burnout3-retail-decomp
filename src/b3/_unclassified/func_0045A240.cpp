// func_0045A240 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (if/else-if chain on result (4,5,0); bool stack local for IsWannaBeHisBuddy; self+4 as char array member field_4).

// func_0045A240 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CB3HUDSoundManager;
class CGtBuddiesPS2DirtySock;
struct UnkStruct_0045A240;
struct UnkStruct_0045A240_3;
struct UnkStruct_D_01E898E8;
struct UnkStruct_func_0045A1B0;

class CB3HUDSoundManager {
public:
    void FEBack();
    void FESelect();

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CGtBuddiesPS2DirtySock {
public:
    void IsWannaBeHisBuddy(char*, bool*);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E898E8 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0045A240_3 {
    unsigned char pad_0[0xC];
    int field_C;
};

struct UnkStruct_func_0045A1B0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0045A240 {
    unsigned char pad_0[0x4];
    char field_4[0xD49];
    unsigned char field_D4D;
};

extern UnkStruct_D_01E898E8 D_01E898E8;
extern CB3HUDSoundManager D_01E7A800;
extern CGtBuddiesPS2DirtySock D_01E3D390;
extern UnkStruct_func_0045A1B0 func_0045A1B0;

extern "C" int func_0032B2C0(void *, int, int);
extern "C" void func_0045A9F0(UnkStruct_0045A240 *);
extern "C" void func_0032D080(void *, int, int, int, int);
extern "C" int func_0035F520(void *, void *, void *, UnkStruct_0045A240 *);

// 0x0045A240
extern "C" void func_0045A240(UnkStruct_0045A240 * self)
{
    bool buddy;
    int r = func_0032B2C0(&D_01E898E8, 0, 1);
    if (r == 4) {
        D_01E7A800.FESelect();
        D_01E3D390.IsWannaBeHisBuddy(self->field_4, &buddy);
        if (buddy) {
            if (func_0035F520(&D_01E3D390, self->field_4, &func_0045A1B0, self) == 0) {
                ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
                func_0032D080(&D_01E898E8, 0, 51, 15, 0);
            } else {
                ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
                func_0032D080(&D_01E898E8, 2, 53, 0, 0);
            }
        } else {
            ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
            func_0032D080(&D_01E898E8, 2, 53, 0, 0);
        }
    } else if (r == 5) {
        D_01E7A800.FEBack();
        self->field_D4D = 1;
        func_0045A9F0(self);
    } else if (r == 0) {
        D_01E7A800.FESelect();
        self->field_D4D = 1;
        func_0045A9F0(self);
    }
}
