// CGtLobbyPS2DirtySock::GetGameParams(CGtLobbyCreateGameParams*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtLobbyDirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (hand-written).

class CGtLobbyCreateGameParams {
public:
    char *field_0; char *field_4; int field_8; int field_C[8]; int field_2C[4];
};
class CGtLobbyPS2DirtySock {
public:
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
    virtual void vfunc_90();
    virtual void vfunc_94();
    virtual void vfunc_98();
    virtual void vfunc_9C();
    virtual void vfunc_A0();
    virtual void vfunc_A4();
    virtual void vfunc_A8();
    virtual int vfunc_AC();
    void GetGameParams(CGtLobbyCreateGameParams *p0);
    unsigned char pad_4[0x130];
    struct UnkStruct_134 * field_134;
    unsigned char pad_138[0x32C];
    char field_464[4];
    unsigned char pad_468[0xE8];
    int field_550;
    int field_554;
    int field_558;
    int field_55C;
};
struct UnkStruct_134 { unsigned char pad_0[4]; char f4[0x88]; char f8C[0x90]; int f11C; };
extern "C" char *strcpy(char *, const char *);
extern "C" int strlen(const char *);
extern "C" int atoi(const char *);
extern "C" void func_00128BE8(char *, void *);
struct UnkStruct_D_004C5990 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_004C5990 D_004C5990;

// 0x00337B10
void CGtLobbyPS2DirtySock::GetGameParams(CGtLobbyCreateGameParams *p0)
{
    int vals[9];
    char buf[0x90];
    char *s = field_134->f8C;
    for (int i = 0; i < 9; i++) {
        strcpy(buf, s);
        func_00128BE8(buf, &D_004C5990);
        vals[i] = atoi(buf);
        s += strlen(buf) + 1;
    }
    p0->field_0 = field_134->f4;
    p0->field_4 = field_464;
    p0->field_8 = field_134->f11C;
    p0->field_C[0] = vals[0];
    p0->field_C[1] = vals[1];
    p0->field_C[2] = vals[2];
    p0->field_C[3] = vals[3];
    p0->field_C[4] = vals[4];
    p0->field_C[5] = vals[5];
    p0->field_C[6] = vals[6];
    p0->field_C[7] = vals[7];
    p0->field_2C[0] = field_550;
    p0->field_2C[1] = field_554;
    p0->field_2C[2] = field_558;
    p0->field_2C[3] = field_55C;
    vfunc_14();
}
