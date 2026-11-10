// CB3BehaviourInterpolate::SetParameters(EB3PlayerCameraBehaviour,EB3PlayerCameraBehaviour,float,EB3InterpolationType,EB3InterpolationTimeMode) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3BehaviourInterpolate.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (switch on mode sets field_124/12C; enum params with placeholder enums).

enum EB3PlayerCameraBehaviour { UnkEnum_PCB_0 };
enum EB3InterpolationType { UnkEnum_IT_0 };
enum EB3InterpolationTimeMode { UnkEnum_ITM_0 };
struct UnkStruct_Mgr { unsigned char pad_0[0xB80]; unsigned long field_B80; float field_B88; float field_B8C; };
class CB3PlayerCameraManager;
extern "C" void ActivateBehaviour__22CB3PlayerCameraManagerFi(void *, int);
class CB3BehaviourInterpolate {
public:
    void SetParameters(EB3PlayerCameraBehaviour p0, EB3PlayerCameraBehaviour p1, float p2, EB3InterpolationType p3, EB3InterpolationTimeMode p4);
    unsigned char pad_0[0x120];
    UnkStruct_Mgr *field_120;
    float field_124;
    float field_128;
    float field_12C;
    int field_130;
    int field_134;
    unsigned char pad_138[0x8];
    int field_140;
    int field_144;
};
// 0x003741A0
void CB3BehaviourInterpolate::SetParameters(EB3PlayerCameraBehaviour p0, EB3PlayerCameraBehaviour p1, float p2, EB3InterpolationType p3, EB3InterpolationTimeMode p4)
{
    field_130 = p0;
    field_134 = p1;
    field_140 = p3;
    field_144 = p4;
    field_128 = p2;
    switch (field_144) {
    case 0: field_124 = field_120->field_B88; break;
    case 1: field_124 = field_120->field_B8C; break;
    case 2: field_124 = 0.0f; field_12C = 0.0f; break;
    }
    field_120->field_B80 &= ~(1UL << field_130);
    ActivateBehaviour__22CB3PlayerCameraManagerFi(field_120, 10);
}
