// CB3BehaviourInterpolate::Construct(CB3PlayerCameraManager*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3BehaviourInterpolate.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

#include "b3/GtMathPs2.h"

class CB3PlayerCameraManager;

class CB3BehaviourInterpolate;

class CB3BehaviourInterpolate {
public:
    void Construct(CB3PlayerCameraManager* p0);

    unsigned char pad_0[0x110];
    GtMathPs2::CGtV3d field_110;
    CB3PlayerCameraManager * field_120;
};

extern "C" void Construct__18CB3CameraBehaviourFv(void *);  // CB3CameraBehaviour::Construct()

// 0x00374240
void CB3BehaviourInterpolate::Construct(CB3PlayerCameraManager* p0)
{
    Construct__18CB3CameraBehaviourFv(this);
    field_120 = (CB3PlayerCameraManager *)p0;
    field_110.SetX(0.0f);
    field_110.SetY(0.0f);
    field_110.SetZ(0.0f);
}
