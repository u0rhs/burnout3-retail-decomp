// CB3MenuPageManager::ReleaseCurrentMenu() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3MenuPageManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a76: list walk with virtual Release).

// [C] name CB3MenuPageManager::ReleaseCurrentMenu() (mangled symbol); component list head +0x1D8 linked via +4 (cf. AddComponent), flag byte +0xA (CB3MenuComponentBase::field_A), slot 0xC = Release; layout [G]. No DNAT row.
class CB3MenuStringBuffer {
public:
    void Prepare();
};

class UnkStruct_0030DD70_comp {
public:
    virtual void vfunc_8(float) = 0;
    virtual void vfunc_C();
    UnkStruct_0030DD70_comp * field_4;
    short field_8;
    bool field_A;
    bool field_B;
};

class UnkStruct_0030DD70_obj {
public:
    virtual void vfunc_8(float) = 0;
    virtual void vfunc_C();
};

class CB3MenuPageManager {
public:
    void ReleaseCurrentMenu();
    unsigned char pad_0[0x1D8];
    UnkStruct_0030DD70_comp * field_1D8;
    unsigned char pad_1DC[0x8];
    int field_1E4;
    unsigned char pad_1E8[0x8];
    UnkStruct_0030DD70_obj * field_1F0;
    unsigned char pad_1F4[0x4];
    CB3MenuStringBuffer field_1F8;
};

// 0x0030DD70
void CB3MenuPageManager::ReleaseCurrentMenu()
{
    field_1E4 = 6;
    field_1F0->vfunc_C();
    field_1F0 = 0;
    for (UnkStruct_0030DD70_comp * p = field_1D8; p != 0; p = p->field_4) {
        if (p->field_A != false) {
            p->vfunc_C();
        }
    }
    field_1F8.Prepare();
}
