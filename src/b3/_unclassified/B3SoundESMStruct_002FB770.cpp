// CB3SoundESMStruct::Update(const CB3SoundESMGraphInputs&,CB3SoundEsmGraphOutputs*) const -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundESMStruct.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (near24: index p1[i] directly at every use (no element-pointer local) fixes s0/s1/s2).

class CB3SoundESMGraphInputs;

class CB3SoundESMStruct;
struct UnkStruct_002FB770_e1;
struct UnkStruct_002FB770_e2;

class CB3SoundEsmGraphOutputs {
public:
    float field_0;
    float field_4;
    float field_8;
    float field_C;
    float field_10;
    float field_14;
    float field_18;
    float field_1C;
    float field_20;
    float field_24;
    float field_28;
    float field_2C;
    float field_30;
    float field_34;
    float field_38;
    float field_3C;
    float field_40;
    float field_44;
    float field_48;
    float field_4C;
};

struct UnkStruct_002FB770_e1 {
    unsigned char pad_0[0x8];
    UnkStruct_002FB770_e2 * field_8;
    unsigned char field_C;
    unsigned char pad_D[0x3];
};

struct UnkStruct_002FB770_e2 {
    unsigned char pad_0[0x8];
};

class CB3SoundESMStruct {
public:
    void Update(const CB3SoundESMGraphInputs& p0, CB3SoundEsmGraphOutputs* p1) const;

    unsigned char pad_0[0x3C];
    UnkStruct_002FB770_e1 * field_3C;
    unsigned char field_40;
};

extern "C" void Update__22CB3SoundESMGraphStructCFRC22CB3SoundESMGraphInputsR23CB3SoundEsmGraphOutputs(void *, const void *, void *);  // CB3SoundESMGraphStruct::Update(const CB3SoundESMGraphInputs&,CB3SoundEsmGraphOutputs&) const

// 0x002FB770
void CB3SoundESMStruct::Update(const CB3SoundESMGraphInputs& p0, CB3SoundEsmGraphOutputs* p1) const
{
    for (int i = 0; ((unsigned int)i < (unsigned int)field_40); i++) {
        p1[i].field_0 = 1.0f;
        p1[i].field_4 = 1.0f;
        p1[i].field_8 = 1.0f;
        p1[i].field_C = 1.0f;
        p1[i].field_10 = 1.0f;
        p1[i].field_14 = 1.0f;
        p1[i].field_18 = 1.0f;
        p1[i].field_1C = 1.0f;
        p1[i].field_20 = 1.0f;
        p1[i].field_24 = 1.0f;
        p1[i].field_28 = 1.0f;
        p1[i].field_2C = 1.0f;
        p1[i].field_30 = 1.0f;
        p1[i].field_34 = 1.0f;
        p1[i].field_38 = 1.0f;
        p1[i].field_3C = 1.0f;
        p1[i].field_40 = 1.0f;
        p1[i].field_44 = 1.0f;
        p1[i].field_48 = 1.0f;
        p1[i].field_4C = 1.0f;
        UnkStruct_002FB770_e1 * e = &field_3C[i];
        for (int j = 0; ((unsigned int)j < (unsigned int)e->field_C); j++) {
            Update__22CB3SoundESMGraphStructCFRC22CB3SoundESMGraphInputsR23CB3SoundEsmGraphOutputs(&e->field_8[j], &p0, &p1[i]);
        }
    }
}
