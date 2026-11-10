// func_003EDEE0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CB3HUDSoundManager;
class CB3OnScreenKeyboardComponent;
struct UnkStruct_003EDEE0;
struct UnkStruct_D_004F507F;
struct UnkStruct_D_0051BF9C;
struct UnkStruct_D_01E8CA94;
struct UnkStruct_D_01ECD520;

class CB3OnScreenKeyboardComponent {
public:
    void Show(bool, bool);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3HUDSoundManager {
public:
    void FESelect();

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8CA94 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051BF9C {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004F507F {
    signed char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01ECD520 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003EDEE0 {
    unsigned char pad_0[0x4];
    unsigned char field_4;
    unsigned char pad_5[0x3];
    int field_8;
    int field_C;
    unsigned char pad_10[0x10];
    int field_20;
    int field_24;
};

extern UnkStruct_D_01E8CA94 D_01E8CA94;
extern UnkStruct_D_0051BF9C D_0051BF9C;
extern UnkStruct_D_004F507F D_004F507F;
extern UnkStruct_D_01ECD520 D_01ECD520;
extern CB3OnScreenKeyboardComponent D_01E899C0;
extern CB3HUDSoundManager D_01E7A800;

extern "C" int Length__10CGtUnicodeFPCUs(int);
extern "C" void func_0013B740(int, int);
extern "C" int func_0013B730(void *);
extern "C" void Save__24CB3MemCardControllerBaseFUiPUsi(void *, int, void *, int);
extern "C" void func_003EE470(UnkStruct_003EDEE0 *, int);

// 0x003EDEE0
extern "C" void func_003EDEE0(UnkStruct_003EDEE0 * self)
{
    if (self->field_8 == 14) {
        int r0 = Length__10CGtUnicodeFPCUs(D_01E8CA94.field_0);
        if (r0 == 0) {
        } else {
            func_0013B740(D_0051BF9C.field_0, D_01E8CA94.field_0);
            self->field_8 = 5;
            self->field_24 = 0;
            if (self->field_4 != 0) {
                self->field_20 = D_004F507F.field_0;
                D_004F507F.field_0 = 1;
            }
            int r2 = func_0013B730((void *)(D_0051BF9C.field_0));
            Save__24CB3MemCardControllerBaseFUiPUsi(&D_01ECD520, self->field_C, (void *)(r2), 0);
            D_01E899C0.Show(0, 0);
            func_003EE470(self, 4);
            D_01E7A800.FESelect();
        }
    } else {
    }
}
