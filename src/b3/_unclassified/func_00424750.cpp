// func_00424750 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (inlined bool helper: v==24 || v==1 early-return true (daddiu, out-of-line true block)).

// func_00424750 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

enum EB3BackgroundType {};

class CB3PromptBarComponent;
struct UnkStruct_00424750;
struct UnkStruct_D_0051A6A8;
struct UnkStruct_D_0051A9A0;
struct UnkStruct_D_01E88A80;
struct UnkStruct_D_01E89518;
struct UnkStruct_D_01E89800;

class CB3PromptBarComponent {
public:
    void Prepare();

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051A9A0 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051A6A8 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E88A80 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E89518 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E89800 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00424750 {
    unsigned char pad_0[0x4];
    int field_4;
    float field_8;
    unsigned char field_C;
    unsigned char field_D;
    unsigned char field_E;
    unsigned char field_F;
};

extern UnkStruct_D_0051A9A0 D_0051A9A0;
extern UnkStruct_D_0051A6A8 D_0051A6A8;
extern UnkStruct_D_01E88A80 D_01E88A80;
extern UnkStruct_D_01E89518 D_01E89518;
extern CB3PromptBarComponent D_01E894FC;
extern UnkStruct_D_01E89800 D_01E89800;

extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);  // CB3MenuPageBase::Prepare(bool)
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, EB3BackgroundType);  // CB3BackgroundComponent::Prepare(EB3BackgroundType)
extern "C" void func_00130C70(void *);
extern "C" void func_00130D00(void *);
extern "C" void func_00130C30(void *, int);
extern "C" void func_00319C80(void *, int, int);
extern "C" bool func_0031ECD0(void *, unsigned long, int);

static inline bool func_00424750_inl1()  // [G] placeholder: inlined helper, name unknown
{
    int v = D_0051A9A0.field_0;
    if (v == 24 || v == 1) return true;
    return false;
}

// 0x00424750
extern "C" int func_00424750(UnkStruct_00424750 * self, int p0, int p1, int p2, float f0)
{
    Prepare__15CB3MenuPageBaseFb(self, 0);
    if (!func_00424750_inl1()) {
        func_00130C70(&D_0051A6A8);
        func_00130D00(&D_0051A6A8);
    }
    func_00130C30(&D_0051A6A8, p0);
    self->field_4 = 0;
    self->field_C = p1;
    self->field_D = 0;
    self->field_E = 0;
    self->field_F = ((p2 ^ 4005) != 0);
    self->field_8 = f0;
    if (self->field_F == 0) {
        Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)3);
    } else {
        func_00319C80(&D_01E89518, p2, 5);
        D_01E894FC.Prepare();
        Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)4);
        if (self->field_C != 0) {
            func_0031ECD0(&D_01E89800, 16, 3);
        }
    }
    return 1;
}
