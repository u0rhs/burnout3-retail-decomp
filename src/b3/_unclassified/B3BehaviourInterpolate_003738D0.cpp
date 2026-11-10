// CB3BehaviourInterpolate::GetTimeScale() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3BehaviourInterpolate.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (scale loaded into a local before the switch; uninit end in default).

struct UnkStruct_Mgr { unsigned char pad_0[0xB88]; float field_B88; float field_B8C; };
class CB3BehaviourInterpolate {
public:
    float GetTimeScale();
    unsigned char pad_0[0x120];
    UnkStruct_Mgr *field_120;
    float field_124;
    float field_128;
    float field_12C;
    unsigned char pad_130[0x14];
    int field_144;
};
// 0x003738D0
float CB3BehaviourInterpolate::GetTimeScale()
{
    float d = field_128;
    float a;
    switch (field_144) {
    case 0: a = field_120->field_B88; break;
    case 1: a = field_120->field_B8C; break;
    case 2: a = field_12C; break;
    }
    return (a - field_124) / d;
}
