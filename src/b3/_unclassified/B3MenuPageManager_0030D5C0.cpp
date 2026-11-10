// CB3MenuPageManager::SetMenuPage(CB3MenuPageBase*,bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3MenuPageManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a70: self-contained class decls (page vfunc C = Release, component list walk, embedded string buffer at 0x1F8), compare against &D_01E9583C).

// CB3MenuPageManager::SetMenuPage(CB3MenuPageBase*, bool)
class CB3MenuPageBase {
public:
    virtual void Update() = 0;
    virtual void Release();
};

class CB3MenuStringBuffer {
public:
    void Prepare();
    unsigned char pad_0[0x10];
};

class CB3MenuComponentBase {
public:
    virtual void Update(float) = 0;
    virtual void Release();
    CB3MenuComponentBase * field_4;
    short field_8;
    bool field_A;
    bool field_B;
};

struct UnkStruct_D_01E9583C {
    unsigned char pad_0[0x10];
};
extern UnkStruct_D_01E9583C D_01E9583C;

class CB3MenuPageManager {
public:
    void SetMenuPage(CB3MenuPageBase * page, bool b);

    unsigned char pad_0[0x1D8];
    CB3MenuComponentBase * field_1D8;
    int field_1DC;
    unsigned char pad_1E0[0x4];
    int field_1E4;
    unsigned char pad_1E8[0x8];
    CB3MenuPageBase * field_1F0;
    unsigned char pad_1F4[0x4];
    CB3MenuStringBuffer field_1F8;
    unsigned char pad_208[0x17F5];
    unsigned char field_19FD;
    unsigned char pad_19FE[0x1];
    unsigned char field_19FF;
};

// 0x0030D5C0
void CB3MenuPageManager::SetMenuPage(CB3MenuPageBase * page, bool b)
{
    if ((void *)field_1F0 == (void *)&D_01E9583C) {
        field_1E4 = 6;
        field_1F0->Release();
        field_1F0 = 0;
        for (CB3MenuComponentBase * n = field_1D8; n != 0; n = n->field_4) {
            if (n->field_A != 0) {
                n->Release();
            }
        }
        field_1F8.Prepare();
        field_19FD = 0;
    }
    field_1F0 = page;
    field_19FF = 0;
    field_1DC = 0;
    if (b) {
        field_1E4 = 0;
    } else {
        field_1E4 = 2;
    }
}
