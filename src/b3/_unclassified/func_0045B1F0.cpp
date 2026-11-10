// func_0045B1F0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

enum EB3BackgroundType {};
class CGt2dObjectTableData;

class CB3OnScreenKeyboardComponent;
class CB3PromptBarComponent;
class CB3TableComponent;
struct UnkStruct_0045B1F0;
struct UnkStruct_D_004D35D8;
struct UnkStruct_D_004D35E0;
struct UnkStruct_D_004D35E8;
struct UnkStruct_D_01E3D4B4;
struct UnkStruct_D_01E88A80;
struct UnkStruct_D_01E89518;
struct UnkStruct_D_01E89544;
struct UnkStruct_D_01E8954E;
struct UnkStruct_D_01E89800;
struct UnkStruct_D_01E898E8;
struct UnkStruct_D_01E898F2;
struct UnkStruct_D_01E8D45A;
struct UnkStruct_D_01E8D490;
struct UnkStruct_D_01E8D49A;
struct UnkStruct_D_01E90438;

class CB3PromptBarComponent {
public:
    void Prepare();

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3OnScreenKeyboardComponent {
public:
    void RegisterKeyboardCallbacks();

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3TableComponent {
public:
    void RecalculateSize();

    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8954E {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E89544 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8D45A {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8D49A {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8D490 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E898F2 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E898E8 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E90438 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E3D4B4 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E88A80 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E89800 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004D35D8 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004D35E0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004D35E8 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E89518 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0045B1F0 {
    unsigned char pad_0[0xCA4];
    short field_CA4;
    short field_CA6;
    unsigned char pad_CA8[0x4C];
    int field_CF4[1];  // [G] element count unknown
    unsigned char pad_CF8[0x24];
    int field_D1C[1];  // [G] element count unknown
    unsigned char pad_D20[0x24];
    int field_D44;
    int field_D48;
    unsigned char pad_D4C[0x1];
    unsigned char field_D4D;
};

extern UnkStruct_D_01E8954E D_01E8954E;
extern UnkStruct_D_01E89544 D_01E89544;
extern UnkStruct_D_01E8D45A D_01E8D45A;
extern CB3TableComponent D_01E8D450;
extern UnkStruct_D_01E8D49A D_01E8D49A;
extern UnkStruct_D_01E8D490 D_01E8D490;
extern UnkStruct_D_01E898F2 D_01E898F2;
extern UnkStruct_D_01E898E8 D_01E898E8;
extern UnkStruct_D_01E90438 D_01E90438;
extern UnkStruct_D_01E3D4B4 D_01E3D4B4;
extern UnkStruct_D_01E88A80 D_01E88A80;
extern CB3PromptBarComponent D_01E894FC;
extern UnkStruct_D_01E89800 D_01E89800;
extern CB3OnScreenKeyboardComponent D_01E899C0;
extern UnkStruct_D_004D35D8 D_004D35D8;
extern UnkStruct_D_004D35E0 D_004D35E0;
extern UnkStruct_D_004D35E8 D_004D35E8;
extern UnkStruct_D_01E89518 D_01E89518;

extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);  // CB3MenuPageBase::Prepare(bool)
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, EB3BackgroundType);  // CB3BackgroundComponent::Prepare(EB3BackgroundType)
extern "C" void PrepareSplitBackground__17CB3TableComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPC20CGt2dObjectTableDatab(void *, const void *, const void *, const void *, const void *, bool);  // CB3TableComponent::PrepareSplitBackground(const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,const CGt2dObjectTableData*,bool)
extern "C" int AllocUTF16String__19CB3MenuStringBufferFi(void *, int);
extern "C" int func_0026C790(void *);
extern "C" int func_0026C8B0(void *, int);
extern "C" void ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(int, int, int);
extern "C" bool func_0031ECD0(void *, unsigned long, int);
extern "C" void func_00459910(UnkStruct_0045B1F0 *);
extern "C" int func_003517F0(void *);
extern "C" void func_00319C80(void *, int, int);

// 0x0045B1F0
extern "C" int func_0045B1F0(UnkStruct_0045B1F0 * self)
{
    Prepare__15CB3MenuPageBaseFb(self, 0);
    for (int i = 0; (i < 10); i++) {
        int r1 = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 16);
        self->field_CF4[i] = r1;
        int r2 = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 16);
        self->field_D1C[i] = r2;
    }
    int r3 = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 16);
    self->field_D44 = r3;
    int r4 = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 32);
    self->field_D48 = r4;
    for (int i1 = 0; (i1 < func_0026C790(&D_01E3D4B4)); i1++) {
        int r5 = func_0026C8B0(&D_01E3D4B4, (i1 & 255));
        ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(r5, self->field_CF4[i1], 16);
    }
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)0);
    D_01E894FC.Prepare();
    func_0031ECD0(&D_01E89800, 325, 3);
    func_00459910(self);
    func_003517F0(&D_01E899C0);
    D_01E899C0.RegisterKeyboardCallbacks();
    int r14 = func_0026C790(&D_01E3D4B4);
    self->field_CA4 = 0;
    self->field_CA6 = r14;
    self->field_D4D = 0;
    if (D_01E8954E.field_0 != 0) {
        ((UnkStruct_D_01E89544 *)&D_01E89544)->vfunc_C();
    }
    if (D_01E8D45A.field_0 != 0) {
        ((CB3TableComponent *)&D_01E8D450)->vfunc_C();
    }
    if (D_01E8D49A.field_0 != 0) {
        ((UnkStruct_D_01E8D490 *)&D_01E8D490)->vfunc_C();
    }
    if (D_01E898F2.field_0 != 0) {
        ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
    }
    PrepareSplitBackground__17CB3TableComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPC20CGt2dObjectTableDatab(&D_01E8D450, &D_004D35D8, &D_004D35E0, &D_004D35E8, (const CGt2dObjectTableData*)((char *)self + 0x18), 0);
    D_01E8D450.RecalculateSize();
    func_00319C80(&D_01E89518, 708, 14);
    return 1;
}
