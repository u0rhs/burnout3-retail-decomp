// CB3OnlineSelectLoginPage::PrepareExistingAccountControls() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineSelectLoginPage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (rewritten: two inline bool validity helpers with early returns (|| groups share one false block), char name/password arrays, bool arg to func_003BC360).

// lifter variant 0
// CB3OnlineSelectLoginPage::PrepareExistingAccountControls() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineSelectLoginPage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3OnlineSelectLoginPage;
struct UnkStruct_D_004C6EB0;
struct UnkStruct_D_0051BA44;
struct UnkStruct_D_01E89518;
struct UnkStruct_D_01E89522;
struct UnkStruct_D_01E89544;
struct UnkStruct_D_01E8954E;
struct UnkStruct_D_01E8961C;
struct UnkStruct_D_01E89626;
struct UnkStruct_D_01E89788;
struct UnkStruct_D_01E898E8;
struct UnkStruct_D_01E898F2;
struct UnkStruct_D_01E8D4F0;
struct UnkStruct_D_01E8D4FA;

struct UnkStruct_D_01E89522 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E89518 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8D4FA {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8D4F0 {
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

struct UnkStruct_D_01E89626 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8961C {
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

struct UnkStruct_D_0051BA44 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E89788 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004C6EB0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern "C" unsigned int strlen(const char *);
extern "C" int strcmp(const char *, const char *);

extern UnkStruct_D_004C6EB0 D_004C6EB0;

class CB3OnlineSelectLoginPage {
public:
    // [G] inlined validity checks (no names in any table)
    inline bool func_00348D10_inl1()
    {
        if (strlen(field_4) < 4 || strlen(field_4) >= 17) return false;
        if (field_4[0] < '0' || field_4[0] > '9') return true;
        return false;
    }
    inline bool func_00348D10_inl2()
    {
        if (strlen(field_4) < 4 || strlen(field_4) >= 17) return false;
        if (field_4[0] >= '0' && field_4[0] <= '9') return false;
        if (strlen(field_36) > 16 || strlen(field_36) < 4) return false;
        if (strcmp(field_4, (const char *)&D_004C6EB0) == 0 || strcmp(field_36, (const char *)&D_004C6EB0) == 0) return false;
        return true;
    }
    void PrepareExistingAccountControls();

    unsigned char pad_0[0x4];
    char field_4[0x32];
    char field_36[0x32];
    unsigned char pad_68[0x8];
    unsigned char field_70;
    unsigned char pad_71[0x7F];
    short field_F0;
    short field_F2;
    unsigned char pad_F4[0x4];
    int field_F8;
    int field_FC;
    int field_100;
    unsigned char field_104;
    unsigned char field_105;
    unsigned char field_106;
    unsigned char pad_107[0x1];
    int field_108;
    int field_10C;
    int field_110;
    int field_114;
    unsigned char field_118;
    unsigned char field_119;
    unsigned char field_11A;
    unsigned char pad_11B[0x1];
    int field_11C;
    int field_120;
    int field_124;
    int field_128;
    unsigned char field_12C;
    unsigned char field_12D;
    unsigned char field_12E;
    unsigned char pad_12F[0x1];
    int field_130;
    int field_134;
    int field_138;
    int field_13C;
    unsigned char field_140;
    unsigned char field_141;
    unsigned char field_142;
    unsigned char pad_143[0x1];
    int field_144;
    int field_148;
    int field_14C;
    int field_150;
    unsigned char field_154;
    unsigned char field_155;
    unsigned char field_156;
    unsigned char pad_157[0x1];
    int field_158;
    int field_15C;
    int field_160;
};

extern UnkStruct_D_01E89522 D_01E89522;
extern UnkStruct_D_01E89518 D_01E89518;
extern UnkStruct_D_01E8D4FA D_01E8D4FA;
extern UnkStruct_D_01E8D4F0 D_01E8D4F0;
extern UnkStruct_D_01E8954E D_01E8954E;
extern UnkStruct_D_01E89544 D_01E89544;
extern UnkStruct_D_01E89626 D_01E89626;
extern UnkStruct_D_01E8961C D_01E8961C;
extern UnkStruct_D_01E898F2 D_01E898F2;
extern UnkStruct_D_01E898E8 D_01E898E8;
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_01E89788 D_01E89788;
extern UnkStruct_D_004C6EB0 D_004C6EB0;

extern "C" void SetString__19CB3HelpBarComponentFPCUsbbf(void *, const unsigned short*, bool, bool, float);  // CB3HelpBarComponent::SetString(const unsigned short*,bool,bool,float)
extern "C" void func_00319C80(void *, int, int);
extern "C" int func_00271A00(void *, int);
extern "C" int func_003BE5A0(void *, void *, void *);
extern "C" void func_003BC360(void *, int, bool);

// 0x00348D10
void CB3OnlineSelectLoginPage::PrepareExistingAccountControls()
{
    if (D_01E89522.field_0 != 0) {
        ((UnkStruct_D_01E89518 *)&D_01E89518)->vfunc_C();
    }
    if (D_01E8D4FA.field_0 != 0) {
        ((UnkStruct_D_01E8D4F0 *)&D_01E8D4F0)->vfunc_C();
    }
    if (D_01E8954E.field_0 != 0) {
        ((UnkStruct_D_01E89544 *)&D_01E89544)->vfunc_C();
    }
    if (D_01E89626.field_0 != 0) {
        ((UnkStruct_D_01E8961C *)&D_01E8961C)->vfunc_C();
    }
    if (D_01E898F2.field_0 != 0) {
        ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
    }
    func_00319C80(&D_01E89518, 69, 14);
    field_70 = 1;
    field_F0 = 0;
    field_F2 = 5;
    int t0 = field_15C;
    int r6 = func_00271A00(&D_0051BA44, 72);
    field_F8 = r6;
    field_100 = t0;
    field_104 = 1;
    field_105 = 1;
    field_106 = 0;
    field_108 = 0;
    field_FC = 0;
    int t1 = field_160;
    int r7 = func_00271A00(&D_0051BA44, 73);
    field_10C = r7;
    field_114 = t1;
    field_118 = 1;
    field_119 = 1;
    field_11A = 0;
    field_11C = 0;
    field_110 = 0;
    int r8 = func_00271A00(&D_0051BA44, 74);
    field_120 = r8;
    field_128 = 0;
    field_12C = 0;
    field_12D = 0;
    field_12E = 1;
    field_130 = 0;
    field_124 = 0;
    int r9 = func_00271A00(&D_0051BA44, 75);
    field_134 = r9;
    field_13C = 0;
    field_140 = 0;
    field_141 = 0;
    field_142 = 0;
    field_144 = 0;
    field_138 = 0;
    int r10 = func_00271A00(&D_0051BA44, 446);
    field_148 = r10;
    field_150 = 0;
    field_154 = 0;
    field_155 = 0;
    field_156 = 1;
    field_158 = 0;
    field_14C = 0;
    func_003BE5A0(&D_01E8961C, ((char *)this + 0xF0), ((char *)this + 0xF8));
    int r12 = func_00271A00(&D_0051BA44, 102);
    SetString__19CB3HelpBarComponentFPCUsbbf(&D_01E89788, (const unsigned short*)r12, 0, 0, 80.0f);
    func_003BC360(&D_01E8961C, 4, func_00348D10_inl2());
    func_003BC360(&D_01E8961C, 2, func_00348D10_inl1());
}
