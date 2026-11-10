// CGtLobbyPS2DirtySock::GetPlayerParams(CGtLobbyJoinGameParams*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtLobbyDirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (a67: players table row ptr, found-loop with && found==0, i declared before found).

class CGtLobbyJoinGameParams;

class CGtLobbyPS2DirtySock;
struct CGtLobbyJoinGameParams;
struct UnkStruct_00337C40_1;
struct UnkStruct_00337C40_2;
struct UnkStruct_00337C40_4;
struct UnkStruct_00337C40_e0;

struct UnkStruct_00337C40_row {
    unsigned char pad_0[0x4];
    char field_4[0x3C];
    char field_40[0x24];
};

struct UnkStruct_00337C40_1 {
    unsigned char pad_0[0x1BC];
    int field_1BC;
    UnkStruct_00337C40_row field_1C0[1];  // [G] element count unknown
};

struct UnkStruct_00337C40_2 {
    int field_0;
    int field_4;
    int field_8;
    unsigned char pad_C[0x4];
};

struct CGtLobbyJoinGameParams {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
};

struct UnkStruct_00337C40_4 {
    unsigned char pad_0[0x14];
    int field_14;
};

struct UnkStruct_00337C40_e0 {
    unsigned char pad_0[0x64];
};

class CGtLobbyPS2DirtySock {
public:
    void GetPlayerParams(CGtLobbyJoinGameParams* p0);

    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
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
    virtual int vfunc_68();
    unsigned char pad_4[0x130];
    UnkStruct_00337C40_1 * field_134;
    unsigned char pad_138[0x36C];
    char field_4A4[0x20];
    unsigned char pad_4C4[0x8C];
    int field_550;
    int field_554;
    int field_558;
    int field_55C;
};

extern "C" void LoadFromString__35CGtLobbyDirtySockCachedPlayerParamsFPc(void *, char*);  // CGtLobbyDirtySockCachedPlayerParams::LoadFromString(char*)
extern "C" int strcasecmp(const char *, const char *);

// 0x00337C40
void CGtLobbyPS2DirtySock::GetPlayerParams(CGtLobbyJoinGameParams* p0)
{
    UnkStruct_00337C40_2 local;
    int i = 0;
    UnkStruct_00337C40_row * found = 0;
    for (; i < field_134->field_1BC && found == 0; i++) {
        if (strcasecmp(field_134->field_1C0[i].field_4, field_4A4) == 0) {
            found = &field_134->field_1C0[i];
        }
    }
    LoadFromString__35CGtLobbyDirtySockCachedPlayerParamsFPc(&local, found->field_40);
    p0->field_0 = vfunc_68();
    p0->field_4 = (int)((char *)field_134 + 4);
    p0->field_8 = 0;
    p0->field_C = local.field_0;
    p0->field_10 = local.field_4;
    p0->field_14 = local.field_8;
    p0->field_18 = field_550;
    p0->field_1C = field_554;
    p0->field_20 = field_558;
    p0->field_24 = field_55C;
    vfunc_14();
}
