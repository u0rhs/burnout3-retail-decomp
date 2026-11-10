// func_003F4160 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CB3OnScreenKeyboardComponent;
struct UnkStruct_003F4160;
struct UnkStruct_D_0051BF9C;
struct UnkStruct_D_01E8CA94;

class CB3OnScreenKeyboardComponent {
public:
    void Show(bool, bool);

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

struct UnkStruct_003F4160 {
    unsigned char pad_0[0x4];
    int field_4;
};

extern UnkStruct_D_01E8CA94 D_01E8CA94;
extern UnkStruct_D_0051BF9C D_0051BF9C;
extern CB3OnScreenKeyboardComponent D_01E899C0;

extern "C" int Length__10CGtUnicodeFPCUs(int);
extern "C" void func_0013B740(int, int);
extern "C" void func_003F4600(UnkStruct_003F4160 *, int);

// 0x003F4160
extern "C" void func_003F4160(UnkStruct_003F4160 * self)
{
    if (self->field_4 == 17) {
        int t0 = D_01E8CA94.field_0;
        int r0 = Length__10CGtUnicodeFPCUs(t0);
        if (r0 == 0) {
        } else {
            func_0013B740(D_0051BF9C.field_0, t0);
            D_01E899C0.Show(0, 0);
            self->field_4 = 10;
            func_003F4600(self, 6);
        }
    } else {
    }
}
