// CB3CrashAnalyser::UpdateCollidingPairs() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CrashAnalyser.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (inline bool bit-test helper (t<5u, (1<<t)&0x17); bools computed before field_2C test; pairs = D_00645180.field_0 declared after count; s = &field_0[j]+0x2E0).

// CB3CrashAnalyser::UpdateCollidingPairs() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CrashAnalyser.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3CrashAnalyser;
struct UnkStruct_00354760_3;
struct UnkStruct_00354760_4;
struct UnkStruct_00354760_e0;
struct UnkStruct_00354760_e1;
struct UnkStruct_D_00645180;
struct UnkStruct_D_00648180;

struct UnkStruct_D_00648180 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00354760_e0 {
    unsigned char pad_0[0x20];
    float field_20;
    UnkStruct_00354760_3 * field_24;
    UnkStruct_00354760_4 * field_28;
    unsigned char field_2C;
    unsigned char pad_2D[0x3];
};

struct UnkStruct_D_00645180 {
    UnkStruct_00354760_e0 field_0[1];  // [G] element count unknown
};

struct UnkStruct_00354760_3 {
    signed char field_0;
    unsigned char pad_1[0xB];
    int field_C;
};

struct UnkStruct_00354760_4 {
    signed char field_0;
    unsigned char pad_1[0xB];
    int field_C;
};

struct UnkStruct_00354760_e2 {
    unsigned char pad_0[0x44];
    int field_44;
    int field_48;
    float field_4C;
    int field_50;
    int field_54;
    unsigned char pad_58[0x10];
    unsigned char field_68;
};

struct UnkStruct_00354760_e3 {
    unsigned char pad_0[0x70];
};

struct UnkStruct_00354760_e1 {
    unsigned char pad_0[0x10];
    int field_10;
    int field_14;
    int field_18;
    float field_1C;
    int field_20;
    int field_24;
    unsigned char pad_28[0x10];
    unsigned char field_38;
    unsigned char pad_39[0x37];
};

class CB3CrashAnalyser {
public:
    void UpdateCollidingPairs();

    UnkStruct_00354760_e3 field_0[1];
    unsigned char pad_70[0x2A0];
    UnkStruct_00354760_e1 field_310[1];  // [G] element count unknown
    unsigned char pad_380[0xCB0];
    int field_1030;
};

extern UnkStruct_D_00648180 D_00648180;
extern UnkStruct_D_00645180 D_00645180;

static inline bool func_00354760_inl1(signed char t)
{
    bool r = false;
    if ((unsigned int)t < 5) { if ((1 << t) & 0x17) r = true; }
    return r;
}

// 0x00354760
void CB3CrashAnalyser::UpdateCollidingPairs()
{
    int i;
    int n = D_00648180.field_0;
    UnkStruct_00354760_e0 * pairs = D_00645180.field_0;
    for (i = 0; i < n; i++) {
        bool b1 = func_00354760_inl1(pairs[i].field_24->field_0);
        bool b2 = func_00354760_inl1(pairs[i].field_28->field_0);
        if (pairs[i].field_2C != 0 && b1 && b2) {
            for (int j = 0; j < field_1030; j++) {
                UnkStruct_00354760_e2 * s = (UnkStruct_00354760_e2 *)((char *)&field_0[j] + 0x2E0);
                if (field_310[j].field_10 == pairs[i].field_24->field_C) {
                    s->field_4C = pairs[i].field_20;
                    s->field_48 = 0;
                    s->field_50 = 0;
                    s->field_54 = 0;
                    s->field_44 = 0;
                    s->field_68 = 1;
                } else if (field_310[j].field_10 == pairs[i].field_28->field_C) {
                    s->field_4C = pairs[i].field_20;
                    s->field_48 = 0;
                    s->field_50 = 0;
                    s->field_54 = 0;
                    s->field_44 = 0;
                    s->field_68 = 1;
                }
            }
        }
    }
}
