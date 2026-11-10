// CGtNetworkPlayerManager::SetGameID(int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtNetworkPlayerManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (func_0022D9F0 takes one arg; element pointer local for clear/test, call arg as a separate (field_0-based) address so it is not CSE'd with the local; loop 2 clears field_3A0 (retail bug kept)).

// CGtNetworkPlayerManager::SetGameID(int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtNetworkPlayerManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtNetworkPlayerManager;
struct UnkStruct_00236A00_1;
struct UnkStruct_00236A00_e0;
struct UnkStruct_00236A00_e1;
struct UnkStruct_00236A00_e2;

struct UnkStruct_00236A00_1 {
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
    virtual void vfunc_3C(int);
};

struct UnkStruct_00236A00_e0 {
    unsigned char field_0;
    unsigned char field_1;
    unsigned char pad_2[0xE];
};

struct UnkStruct_00236A00_e1 {
    unsigned char field_0;
    unsigned char field_1;
    unsigned char pad_2[0xE];
};

struct UnkStruct_00236A00_e2 {
    unsigned char pad_0[0x10];
};

class CGtNetworkPlayerManager {
public:
    void SetGameID(int p0);

    UnkStruct_00236A00_e2 field_0[1];  // [G] element count unknown
    unsigned char pad_10[0x6C];
    UnkStruct_00236A00_1 * field_7C;
    unsigned char pad_80[0xC];
    unsigned char field_8C;
    unsigned char pad_8D[0x313];
    UnkStruct_00236A00_e0 field_3A0[1];  // [G] element count unknown
    unsigned char pad_3B0[0x90];
    UnkStruct_00236A00_e1 field_440[1];  // [G] element count unknown
};

extern "C" void func_0022D9F0(void *);

// 0x00236A00
void CGtNetworkPlayerManager::SetGameID(int p0)
{
    field_8C = p0;
    if (field_8C == 255) {
        field_8C = 0;
    }
    field_7C->vfunc_3C(p0);
    for (int i = 0; i < 10; i++) {
        UnkStruct_00236A00_e0 *e = &field_3A0[i];
        if ((field_3A0[i].field_0 & 1) == 1) {
            e->field_0 = e->field_0 & -2;
        }
        if ((e->field_0 & 2) == 2) {
            func_0022D9F0((char *)&field_0[i] + 0x3A0);
        }
        field_3A0[i].field_1 = 0;
    }
    for (int i = 0; i < 10; i++) {
        UnkStruct_00236A00_e1 *e = &field_440[i];
        if ((field_440[i].field_0 & 1) == 1) {
            field_3A0[i].field_0 = field_3A0[i].field_0 & -2;
        }
        if ((e->field_0 & 2) == 2) {
            func_0022D9F0((char *)&field_0[i] + 0x440);
        }
        field_440[i].field_1 = 0;
    }
}
