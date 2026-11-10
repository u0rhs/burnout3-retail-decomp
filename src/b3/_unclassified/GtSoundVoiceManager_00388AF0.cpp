// CGtSoundVoiceManager::SetGroupTransition(unsigned int,const CGtSoundVoiceGroup*,float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundVoiceManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (void return; element pointer into D_01EA4B00).

// lifter variant 0
// CGtSoundVoiceManager::SetGroupTransition(unsigned int,const CGtSoundVoiceGroup*,float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundVoiceManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtSoundVoiceGroup;

class CGtSoundVoiceManager;
struct UnkStruct_00388AF0_e0;
struct UnkStruct_00388AF0_e1;
struct UnkStruct_00388AF0_e2;
struct UnkStruct_D_01EA4B00;

struct UnkStruct_00388AF0_e0 {
    float field_0;
    float field_4;
};

struct UnkStruct_D_01EA4B00 {
    UnkStruct_00388AF0_e0 field_0[1];  // [G] element count unknown
    unsigned char pad_8[0x8];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00388AF0_e1 {
    unsigned char pad_0[0xC];
    float field_C;
    float field_10;
};

struct UnkStruct_00388AF0_e2 {
    const CGtSoundVoiceGroup * field_0;
    float field_4;
    float field_8;
    unsigned char pad_C[0x8];
};

class CGtSoundVoiceManager {
public:
    void SetGroupTransition(unsigned int p0, const CGtSoundVoiceGroup* p1, float p2);

    unsigned char pad_0[0x1BF8];
    UnkStruct_00388AF0_e1 field_1BF8[1];  // [G] element count unknown
    UnkStruct_00388AF0_e2 field_1C0C[1];  // [G] element count unknown
};

extern UnkStruct_D_01EA4B00 D_01EA4B00;

// 0x00388AF0
void CGtSoundVoiceManager::SetGroupTransition(unsigned int p0, const CGtSoundVoiceGroup* p1, float p2)
{
    UnkStruct_00388AF0_e0 * e = &D_01EA4B00.field_0[p0];
    field_1BF8[p0].field_C = e->field_0;
    field_1BF8[p0].field_10 = e->field_4;
    field_1C0C[p0].field_0 = p1;
    field_1C0C[p0].field_4 = p2;
    field_1C0C[p0].field_8 = p2;
}
