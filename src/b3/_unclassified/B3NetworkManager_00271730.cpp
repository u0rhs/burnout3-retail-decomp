// CB3NetworkManager::Construct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3NetworkManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (member layout from offsets; int i declared before s1).

struct UnkStruct_271730_obj {
    virtual void vfunc_8(int);
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
    virtual void vfunc_44();
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
    virtual void vfunc_90(void *, void *);
};
struct UnkStruct_271730_el { unsigned char pad_0[0x4F20]; };
extern unsigned char D_01E6D4E0[];
extern unsigned char D_01E654E0[];
extern "C" int func_00271910();
extern "C" void func_0022F660(void *);
extern "C" void func_0022D2B0(void *, void *, int, int);
extern "C" void func_0023F860(void *, void *, void *);
extern "C" void func_00236EA0(void *, void *, int, void *, int, int);
extern "C" void func_00240A60(void *, void *);
extern "C" void func_00240C90(void *, void *, int, void *);
extern "C" void func_0022D3A0(void *);
extern "C" int func_0026DA60(int, void *);
extern "C" bool ShouldWeEncryptMessageContents__17CB3NetworkManagerFi(int);
class CB3NetworkManager {
public:
    void Construct();
    unsigned char pad_0[0xFAC];
    unsigned char field_FAC[1];
    unsigned char pad_FAD[0x9B40 - 0xFAD];
    unsigned char field_9B40[0x10];
    unsigned char pad_9B50[0xA264 - 0x9B50];
    UnkStruct_271730_obj field_A264;
    unsigned char pad_A268[0xAAB5 - 0xA268];
    unsigned char field_AAB5;
    unsigned char pad_AAB6[0xAAC0 - 0xAAB6];
    UnkStruct_271730_el field_AAC0[8];
    int field_323C0[8];
    unsigned char pad_323E0[0x32664 - 0x323E0];
    int field_32664;
    unsigned char pad_32668[8];
    unsigned char field_32670[1];
    unsigned char pad_32671[0x328F0 - 0x32671];
    unsigned char field_328F0[1];
    unsigned char pad_328F1[0x32970 - 0x328F1];
    unsigned char field_32970[1];
    unsigned char pad_32971[0x329A9 - 0x32971];
    unsigned char field_329A9;
    unsigned char field_329AA;
    unsigned char field_329AB;
    unsigned char field_329AC;
    unsigned char pad_329AD[0x329E2 - 0x329AD];
    unsigned char field_329E2;
    unsigned char field_329E3;
    unsigned char pad_329E4[4];
    int field_329E8;
    unsigned char pad_329EC[0x329F8 - 0x329EC];
    int field_329F8;
};
// 0x00271730
void CB3NetworkManager::Construct()
{
    int i;
    field_329AB = 0;
    int s1 = func_00271910();
    func_0022F660(field_9B40);
    func_0022D2B0(field_9B40, D_01E6D4E0, 0x8000, s1);
    for (i = 0; i < 8; i++) {
        void *s0 = &field_AAC0[i];
        func_0023F860(s0, this, field_FAC);
        field_323C0[i] = (int)s0;
    }
    func_00236EA0(this, field_323C0, 8, D_01E654E0, 0x8000, s1);
    field_A264.vfunc_8(8);
    func_00240A60(field_328F0, this);
    func_00240C90(field_32970, field_32670, 8, this);
    field_329A9 = 0;
    field_329AA = 0;
    field_32664 = 1;
    field_A264.vfunc_90((void *)func_0026DA60, this);
    field_329AC = 0;
    field_329E8 = 0;
    field_329E2 = 0;
    field_329E3 = 0;
    field_329F8 = 0x3C;
    func_0022D3A0((void *)ShouldWeEncryptMessageContents__17CB3NetworkManagerFi);
    field_AAB5 = 0;
}
