// CB3OnlineJoinGamePage::Prepare(char*,char*,char*,int,bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineJoinGamePage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a148: if(p0) block then 'reg:' shared tail, else block gotos back; row view struct (pad 0x15E8, a/b rows 0x288 apart) accessed as rp->a/b (no pointer locals); r1 stored before 2nd Alloc).

struct UnkStruct_P { unsigned char pad_0[0x10]; };
struct UnkStruct_B { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_I { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_Net {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual void vfunc_20();
    virtual void vfunc_24();
    virtual void vfunc_28();
    virtual void vfunc_2C();
    virtual void vfunc_30();
    virtual void vfunc_34();
    virtual void vfunc_38();
    virtual void vfunc_3C();
    virtual void vfunc_40();
    virtual void vfunc_44(int, int, int, void *, void *);
    virtual void vfunc_48();
    virtual void vfunc_4C();
    virtual void vfunc_50();
    virtual void vfunc_54();
    virtual void vfunc_58();
    virtual void vfunc_5C();
    virtual void vfunc_60();
    virtual void vfunc_64();
    virtual void vfunc_68();
    virtual void vfunc_6C();
    virtual void vfunc_70();
    virtual void vfunc_74();
    virtual void vfunc_78();
    virtual void vfunc_7C();
    virtual void vfunc_80();
    virtual void vfunc_84();
    virtual void vfunc_88();
    virtual void vfunc_8C();
    virtual void vfunc_90();
    virtual void vfunc_94();
    virtual void vfunc_98();
    virtual void vfunc_9C();
    virtual void vfunc_A0(char *);
    unsigned char pad_4[0xC];
};
class CB3PromptBarComponent {
public:
    void Prepare();
    unsigned char pad_0[0x10];
};
struct UnkStruct_Row {
    unsigned long field_0;
    unsigned long field_8;
    char field_10[0x20];
    int field_30;
    int field_34;
    int field_38;
    int field_3C;
    int field_40;
    unsigned char field_44;
    unsigned char pad_45[3];
};
struct UnkStruct_RowPair {
    unsigned char pad_0[0x15E8];
    UnkStruct_Row a;
    unsigned char pad_48[0x288 - 0x48];
    UnkStruct_Row b;
};
class CB3OnlineJoinGamePage {
public:
    int Prepare(char * p0, char * p1, char * p2, int p3, bool p4);
    unsigned char pad_0[0x1220];
    int field_1220[10];
    int field_1248[10];
    int field_1270;
    int field_1274;
    unsigned char pad_1278[0x15A4 - 0x1278];
    char field_15A4[0x20];
    char field_15C4[0x20];
    unsigned char pad_15E4[0x4];
    UnkStruct_Row field_15E8[18];
    unsigned short field_1AF8;
    unsigned short field_1AFA;
    unsigned char pad_1AFC[0x4];
    int field_1B00;
    int field_1B04;
    int field_1B08;
    int field_1B0C;
    int field_1B10;
    unsigned char field_1B14;
    signed char field_1B15;
};
extern UnkStruct_Net D_01E3CD44;
extern UnkStruct_P D_01E90438;
extern UnkStruct_P D_01E89518;
extern UnkStruct_P D_01E88A80;
extern UnkStruct_P D_0051BA44;
extern UnkStruct_P D_01E89788;
extern UnkStruct_P D_01E89800;
extern CB3PromptBarComponent D_01E894FC;
extern UnkStruct_P D_01E8D4B0;
extern UnkStruct_P D_01E899C0;
extern UnkStruct_P D_01E898E8;
extern UnkStruct_B D_01E3D596;
extern UnkStruct_I D_01EA2F08;
extern UnkStruct_P krTextPosition;
extern UnkStruct_P krTextHandle;
extern UnkStruct_P krTextBackgroundPosition;
extern UnkStruct_P krTextBackgroundHandle;
extern UnkStruct_P krTextBackgroundSize;
extern char D_004C5610[];
extern "C" void Prepare__15CB3MenuPageBaseFb(void *, bool);
extern "C" int Prepare__22CB3BackgroundComponentF17EB3BackgroundType(void *, int);
extern "C" void Prepare__19CB3HelpBarComponentFPCUsbf(void *, const unsigned short *, bool, float);
extern "C" int AllocUTF16String__19CB3MenuStringBufferFi(void *, int);
extern "C" void func_00319C80(void *, int, int);
extern "C" int func_00271A00(void *, int);
extern "C" int Length__10CGtUnicodeFPCUs(int);
extern "C" bool func_0031ECD0(void *, unsigned long, int);
extern "C" int func_003517F0(void *);
extern "C" void SetupTable__21CB3OnlineJoinGamePageFv(void *);
extern "C" bool func_00351F00(void *, void *, void *, void *, void *, void *, int, int, int, int, int, float, float);
extern "C" char * strcpy(char *, const char *);
extern "C" int sprintf(char *, const char *, ...);
extern "C" void func_0032D080(void *, int, int, int, int);
extern "C" void RegisterKeyboardCallbacks__28CB3OnScreenKeyboardComponentFv(void *);
extern "C" int func_0032A5C0(char *, int, int, int, int, int, int, int, signed char, int, int, int, int, void *, void *);

// 0x0032AAB0
int CB3OnlineJoinGamePage::Prepare(char * p0, char * p1, char * p2, int p3, bool p4)
{
    int i;
    Prepare__15CB3MenuPageBaseFb(this, 0);
    field_1270 = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 0x20);
    for (i = 1; i < 10; i++) {
        int r1 = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 0x20);
        field_1248[i] = r1;
        field_1220[i] = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, 6);
    }
    field_1274 = AllocUTF16String__19CB3MenuStringBufferFi(&D_01E90438, Length__10CGtUnicodeFPCUs(func_00271A00(&D_0051BA44, 0x62)) + 0x20);
    func_00319C80(&D_01E89518, 0x39F, 0xE);
    Prepare__22CB3BackgroundComponentF17EB3BackgroundType(&D_01E88A80, 0);
    func_0031ECD0(&D_01E89800, 0x41, 0);
    D_01E894FC.Prepare();
    func_003517F0(&D_01E899C0);
    SetupTable__21CB3OnlineJoinGamePageFv(this);
    int r = func_00271A00(&D_0051BA44, 0x5F);
    Prepare__19CB3HelpBarComponentFPCUsbf(&D_01E89788, (const unsigned short *)r, 1, 80.0f);
    func_00351F00(&D_01E8D4B0, &krTextPosition, &krTextHandle, &krTextBackgroundPosition, &krTextBackgroundHandle, &krTextBackgroundSize, 0x5F, 3, 1, 103, 0, 32.0f, 496.0f);
    D_01E3D596.field_0 = 0;
    if (p0 != 0) {
        field_1B15 = 3;
        field_1B10 = p3;
        strcpy(field_15C4, p0);
        strcpy(field_15A4, p2);
        func_0032D080(&D_01E898E8, 0, 0x19, 0xF, 0);
        ((UnkStruct_Net *)&D_01E3CD44)->vfunc_A0(p1);
        D_01EA2F08.field_0 = (int)p1;
    reg:
        RegisterKeyboardCallbacks__28CB3OnScreenKeyboardComponentFv(&D_01E899C0);
        return 1;
    } else {
        field_1B00 = 0;
        field_1B04 = 0;
        field_1B14 = 0;
        field_1AF8 = 0;
        field_1AFA = 1;
        field_15C4[0] = 0;
        field_15A4[0] = 0;
        field_1B10 = -1;
        field_1B08 = 0;
        field_1B0C = 0;
        for (i = 0; i < 9; i++) {
            UnkStruct_RowPair * rp = (UnkStruct_RowPair *)((char *)this + i * 72);
            rp->b.field_3C = 0;
            sprintf(rp->b.field_10, D_004C5610);
            rp->b.field_0 = 0;
            rp->b.field_8 = 0;
            rp->b.field_34 = 0;
            rp->b.field_38 = 0;
            rp->b.field_44 = 0;
            rp->b.field_40 = -1;
            rp->a.field_3C = 0;
            sprintf(rp->a.field_10, D_004C5610);
            rp->a.field_0 = 0;
            rp->a.field_8 = 0;
            rp->a.field_34 = -1;
            rp->a.field_38 = -1;
            rp->a.field_44 = 0;
            rp->a.field_30 = 5;
            rp->a.field_40 = -1;
        }
        field_15A4[0] = 0;
        ((UnkStruct_Net *)&D_01E3CD44)->vfunc_44(field_1B04, 9, 0x3C, (void *)func_0032A5C0, this);
        field_1B15 = 0;
        goto reg;
    }
}
