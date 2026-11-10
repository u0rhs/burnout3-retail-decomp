// CB3CrashCombo::OnCrashStart(const CB3CrashStartInfo*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CrashCombo.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (rewritten: void, inline ring-buffer push helper (entry pointer before field_100++ so field_108 reloads), pointer fields 0x10C-0x114, if/else with else-arm early returns).

// lifter variant 0
// CB3CrashCombo::OnCrashStart(const CB3CrashStartInfo*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CrashCombo.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

typedef unsigned int u_long128 __attribute__((mode(TI)));

class CB3CrashStartInfo;

class CB3CrashCombo;
struct CB3CrashStartInfo;
struct UnkStruct_00363C90_11;
struct UnkStruct_00363C90_1;
struct UnkStruct_00363C90_5;
struct UnkStruct_00363C90_6;
struct UnkStruct_00363C90_7;
struct UnkStruct_00363C90_8;
struct UnkStruct_00363C90_e0;
struct UnkStruct_00363C90_e1;
struct UnkStruct_D_00522680;
struct UnkStruct_D_0055EFEC;

struct UnkStruct_00363C90_1 {
    unsigned char pad_0[0x15C6];
    unsigned char field_15C6;
    unsigned char pad_15C7[0x3E5];
    signed char field_19AC;
};

struct UnkStruct_00363C90_e0 {
    int field_0;
    unsigned char pad_4[0x2C];
};

struct UnkStruct_D_0055EFEC {
    UnkStruct_00363C90_e0 field_0[1];  // [G] element count unknown
};

struct UnkStruct_D_00522680 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00363C90_5 {
    unsigned char pad_0[0x204];
    UnkStruct_00363C90_6 * field_204;
    unsigned char pad_208[0x1338];
    unsigned char field_1540;
};

struct UnkStruct_00363C90_6 {
    unsigned char pad_0[0x30];
    u_long128 field_30;
};

struct UnkStruct_00363C90_7 {
    unsigned char pad_0[0x30];
    u_long128 field_30;
};

struct UnkStruct_00363C90_8 {
    unsigned char pad_0[0x30];
    u_long128 field_30;
};

struct UnkStruct_00363C90_e1 {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
};

struct CB3CrashStartInfo {
    unsigned char field_0;
    unsigned char pad_1[0x7];
    UnkStruct_00363C90_11 * field_8;
};

struct UnkStruct_00363C90_11 {
    unsigned char pad_0[0x173];
    signed char field_173;
};

class CB3CrashCombo {
public:
    void OnCrashStart(const CB3CrashStartInfo* p0);
    void ResetData();
    // [G] inlined "next combo entry" ring-buffer push (no name in any table)
    inline UnkStruct_00363C90_e1 * func_00363C90_inl1()
    {
        UnkStruct_00363C90_e1 * e = &field_0[field_108];
        field_100++;
        field_108 = (field_108 + 1) % 16;
        if (field_108 == field_104) {
            field_104 = (field_104 + 1) % 16;
        }
        if (field_110 == e) {
            field_110 = 0;
        }
        if (field_114 == e) {
            field_114 = 0;
        }
        field_118 = 1;
        field_10C = e;
        return e;
    }

    UnkStruct_00363C90_e1 field_0[16];
    int field_100;
    int field_104;
    int field_108;
    UnkStruct_00363C90_e1 * field_10C;
    UnkStruct_00363C90_e1 * field_110;
    UnkStruct_00363C90_e1 * field_114;
    unsigned char field_118;
    unsigned char field_119;
    unsigned char field_11A;
    unsigned char field_11B;
    unsigned char field_11C;
    unsigned char pad_11D[0x3];
    float field_120;
    unsigned char pad_124[0x4];
    float field_128;
    int field_12C;
    u_long128 field_130;
    u_long128 field_140;
    unsigned char pad_150[0x90];
    u_long128 field_1E0;
    unsigned char pad_1F0[0x30];
    int field_220;
    UnkStruct_00363C90_1 * field_224;
    UnkStruct_00363C90_5 * field_228;
};

extern UnkStruct_D_0055EFEC D_0055EFEC;
extern UnkStruct_D_00522680 D_00522680;

// 0x00363C90
void CB3CrashCombo::OnCrashStart(const CB3CrashStartInfo* p0)
{
    ResetData();
    field_228 = (UnkStruct_00363C90_5 *)D_0055EFEC.field_0[field_224->field_19AC].field_0;
    field_119 = 0;
    field_11A = 1;
    field_11B = field_224->field_15C6;
    field_120 = D_00522680.field_0;
    field_130 = field_228->field_204->field_30;
    field_140 = field_228->field_204->field_30;
    field_1E0 = field_228->field_204->field_30;
    field_220 = 1;
    field_11C = 0;
    field_12C = 0;
    if (field_228->field_1540 != 0) {
        UnkStruct_00363C90_e1 * e = func_00363C90_inl1();
        e->field_0 = 0;
        e->field_4 = 2;
        e->field_8 = 0;
        e->field_C = 0;
        field_128 = 0.1f + D_00522680.field_0;
    } else {
        if (p0 == 0) return;
        if (p0->field_0 != 0) {
            field_11C = 1;
            UnkStruct_00363C90_e1 * e = func_00363C90_inl1();
            e->field_0 = 0;
            e->field_4 = 0;
            e->field_8 = 0;
            e->field_C = 0;
        }
        if (p0->field_8 != 0) {
            field_12C = p0->field_8->field_173;
        }
    }
}
