// NONMATCHING: Apply__23CB3SoundEsmGraphOutputsCFUi -- retail 52 / ours 52 instructions, 5 in changed runs
// logic complete 52/52; do-while unsigned i, row ptr, float k=65536 local, i declared before row; remaining 5 instrs: temp regs of (p0*17)<<4 and lui D (retail idx in v1, base a2; ours a1/v1). for-loop form unrolls (64 instrs)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CB3SoundEsmGraphOutputs::Apply(unsigned int) const -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundESMStruct.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3SoundEsmGraphOutputs;
struct UnkStruct_002FB3E0_e0;
struct UnkStruct_D_01E7AA40;

struct UnkStruct_002FB3E0_e0 {
    unsigned char pad_0[0x34];
    int field_34;
    int field_38;
    int field_3C;
    int field_40;
    unsigned char pad_44[0xCC];
};

struct UnkStruct_D_01E7AA40 {
    UnkStruct_002FB3E0_e0 field_0[1];  // [G] element count unknown
};

class CB3SoundEsmGraphOutputs {
public:
    void Apply(unsigned int p0) const;

    unsigned char pad_0[0x10];
    float field_10;
    float field_14;
    float field_18;
    float field_1C;
    float field_20[1];  // [G] element count unknown
};

extern UnkStruct_D_01E7AA40 D_01E7AA40;

extern "C" void SetParam__20CB3SoundDSPDataBlockFif(void *, int, float);  // CB3SoundDSPDataBlock::SetParam(int,float)

// 0x002FB3E0
void CB3SoundEsmGraphOutputs::Apply(unsigned int p0) const
{
    unsigned int i;
    UnkStruct_002FB3E0_e0 *row = &D_01E7AA40.field_0[p0];
    float k = 65536.0f;
    row->field_3C = (int)(k * field_1C);
    row->field_40 = (int)(k * field_18);
    row->field_34 = (int)(k * field_14);
    row->field_38 = (int)(k * field_10);
    i = 0;
    do {
        SetParam__20CB3SoundDSPDataBlockFif(row, i, field_20[i]);
        i++;
    } while (i < 13);
}
