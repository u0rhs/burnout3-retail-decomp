// Hand-written; the lifter refused it (a117: menu page Prepare; while (i < (n = field_4)) loop, n reused for field_50, 0x80000105UL arg).

// [L] DNAT: CB3OnlineCompCrash... none; see unit (placeholder)
enum EB3BackgroundType {};
class CB3PromptBarComponent {
public:
    void Prepare();
    unsigned char pad_0[0x10];
};
struct UnkStruct_D_0051BA44 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_004F50C0 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E89518 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E88A80 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E89800 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E89544 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_0051AEC0 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E8F298 { unsigned char pad_0[0x10]; };
struct UnkStruct_00445530_e {
    int field_0;
    unsigned char field_4;
    unsigned char field_5;
    unsigned char pad_6[2];
};
struct UnkStruct_00445530 {
    unsigned char pad_0[0x4];
    int field_4;
    int field_8;
    int field_C;
    int field_10[10];
    unsigned char field_38[10];
    unsigned char field_42[10];
    unsigned char field_4C;
    unsigned char pad_4D;
    short field_4E;
    short field_50;
    unsigned char pad_52[2];
    UnkStruct_00445530_e field_54[1];
};
extern UnkStruct_D_0051BA44 D_0051BA44;
extern UnkStruct_D_004F50C0 D_004F50C0;
extern UnkStruct_D_01E89518 D_01E89518;
extern UnkStruct_D_01E88A80 D_01E88A80;
extern UnkStruct_D_01E89800 D_01E89800;
extern UnkStruct_D_01E89544 D_01E89544;
extern UnkStruct_D_0051AEC0 D_0051AEC0;
extern UnkStruct_D_01E8F298 D_01E8F298;
extern CB3PromptBarComponent D_01E894FC;
extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);
extern "C" void Prepare__19CB3VSelectComponentFPC29CB3MenuComponentSelectionDataP28CB3VSelectComponentEntryData(void *, const void *, void *, float);
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, EB3BackgroundType);
extern "C" int func_00271A00(void *, int);
extern "C" signed char func_0022D1E0(void *);
extern "C" void func_00319C80(void *, int, int);
extern "C" bool func_0031ECD0(void *, unsigned long, int);
extern "C" int func_0013C8A0(void *);
extern "C" void func_00445CA0(void *);

// 0x00445530
extern "C" int func_00445530(UnkStruct_00445530 * self)
{
    Prepare__15CB3MenuPageBaseFb(self, 0);
    signed char r = func_0022D1E0(&D_004F50C0);
    self->field_4C = r < 2;
    int i = 0;
    int n;
    while (i < (n = self->field_4)) {
        unsigned char c = (self->field_4C != 0 && self->field_42[i] != 0) || self->field_38[i] != 0;
        int v = func_00271A00(&D_0051BA44, self->field_10[i]);
        UnkStruct_00445530_e * e = (UnkStruct_00445530_e *)((char *)self + i * 8 + 0x54);
        i++;
        e->field_0 = v;
        e->field_4 = c;
        e->field_5 = 0;
    }
    self->field_4E = self->field_8;
    self->field_50 = n;
    Prepare__19CB3VSelectComponentFPC29CB3MenuComponentSelectionDataP28CB3VSelectComponentEntryData(&D_01E89544, (char *)self + 0x4E, (char *)self + 0x54, 640.0f);
    func_00319C80(&D_01E89518, self->field_C, 14);
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, (EB3BackgroundType)0);
    func_0031ECD0(&D_01E89800, 0x80000105UL, 3);
    D_01E894FC.Prepare();
    if (func_0013C8A0(&D_0051AEC0) != 0) {
        func_00445CA0(&D_01E8F298);
    }
    return 1;
}
