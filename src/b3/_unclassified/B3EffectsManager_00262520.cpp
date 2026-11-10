// CB3EffectsManager::BeginUpdate() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3EffectsManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (near11: .lit4 externs as float literals (non-aliasing loads hoist)).

// CB3EffectsManager::BeginUpdate() -- near11: [C] .lit4 externs D_004E12BC/D_004E12C0/D_004E0F74 written as float literals
// (21.052631f, 27.067669f, 0.017453292f, read from retail's .lit4); N140 pad for the frame.

struct UnkStruct_D_0052267C { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_00262520_e0 { unsigned char pad_0[0x150]; };
struct UnkStruct_00262520_pad { unsigned char field_0[0x4]; UnkStruct_00262520_pad() {} ~UnkStruct_00262520_pad() {} };
class CB3EffectsManager {
public:
    void BeginUpdate();
    UnkStruct_00262520_e0 field_0[1];
    unsigned char pad_150[0x1F6F0];
    float field_1F840;
    float field_1F844;
    float field_1F848;
    float field_1F84C;
    float field_1F850;
    int field_1F854;
};
extern UnkStruct_D_0052267C D_0052267C;
extern "C" float sinf(float);
extern "C" void BeginUpdate__16CB3ParticleArrayFf(void *, float);
extern "C" void func_002BD6A0(void *);
extern "C" void Update__15CB3ScrapeSystemFv(void *);
// 0x00262520
void CB3EffectsManager::BeginUpdate()
{
    UnkStruct_00262520_pad pad;
    field_1F84C = D_0052267C.field_0;
    field_1F850 = 1.0f / field_1F84C;
    field_1F854 = field_1F854 + 1;
    float s = sinf(0.017453292f * (21.052631f * field_1F848));
    field_1F840 = sinf(0.017453292f * (27.067669f * field_1F848));
    field_1F844 = s;
    for (int i = 0; i < 24; i++) {
        BeginUpdate__16CB3ParticleArrayFf((char *)&field_0[i] + 0x170, field_1F848);
    }
    func_002BD6A0((char *)this + 0x2600);
    Update__15CB3ScrapeSystemFv((char *)this + 0x16C80);
}
