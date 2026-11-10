// CB3HUD::SetHUDMode(EHUDMode) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3HUDManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (rewritten: early else (field_C=p0) via field_0>0 guard, car record via char* base + cast, reload of field_4 for field_8 [G], bool b flag).

enum EHUDMode {};

struct UnkStruct_001A00B0_m {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C(bool, int, int, float);
    virtual void vfunc_10(bool, int, int);
    unsigned char pad_4[0x8];
    UnkStruct_001A00B0_m * field_C;
    unsigned char pad_10[0x4];
    int field_14;
};

struct UnkStruct_001A00B0_car {
    unsigned char pad_0[0x133C];
    int field_133C;
};

struct UnkStruct_001A00B0_e2 {
    unsigned char pad_0[0x27D0];
};
struct UnkStruct_001A00B0_e1 {
    unsigned char pad_0[0x170C];
    int field_170C;
    unsigned char pad_1710[0x10C0];
};
struct UnkStruct_D_00522660 {
    UnkStruct_001A00B0_e2 field_0[1];  // [G] element count unknown
    unsigned char pad_27D0[0x1281B0];
    UnkStruct_001A00B0_e1 field_12A980[1];  // [G] element count unknown
};

class CB3HUD {
public:
    void SetHUDMode(EHUDMode p0);

    float field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    unsigned char pad_14[0x54];
    UnkStruct_001A00B0_m * field_68;
};

extern float D_004E0C50;
extern int _kxHUDModeFlags[];  // [G] element count unknown
extern UnkStruct_D_00522660 D_00522660;

// 0x001A00B0
void CB3HUD::SetHUDMode(EHUDMode p0)
{
    if (field_4 == p0) return;
    if (field_0 > 0.0f) {
        field_C = p0;
        return;
    }
    if (p0 != 4) {
        int t0 = field_10;
        char * e = (char *)&D_00522660.field_0[t0];  // [G] race-car record at +0x12AD50 (cf. func_001D0CB0)
        if ((e + 0x12AD50) != 0 && ((UnkStruct_001A00B0_car *)(e + 0x12AD50))->field_133C == 3) return;
    }
    field_8 = *(int *)&field_4;  // [G] retail reloads field_4 here (not CSEd with the entry compare)
    field_4 = p0;
    field_C = 6;
    bool b = true;
    if (field_4 == 2 || field_8 == 2) b = false;
    if (b) {
        field_0 = D_004E0C50;
    } else {
        field_0 = 0.0f;
    }
    int flags = _kxHUDModeFlags[field_4];
    for (UnkStruct_001A00B0_m * m = field_68; m != 0; m = m->field_C) {
        bool on = (m->field_14 & flags) != 0;
        m->vfunc_10(on, field_4, field_8);
        m->vfunc_C(on, field_4, field_8, 0.0f);
    }
}
