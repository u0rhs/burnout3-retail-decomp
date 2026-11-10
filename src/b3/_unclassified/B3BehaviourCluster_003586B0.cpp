// CB3BehaviourCluster::SetInterpRig(CB3ClusterRig*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3BehaviourCluster.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

#include "b3/GtMathPs2.h"

class CB3ClusterRig;

class CB3BehaviourCluster;
struct CB3ClusterRig;

struct CB3ClusterRig {
    u_long128 field_0[4];
    u_long128 field_40[4];
    int field_80;
    int field_84;
    GtMathPs2::CGtV3d field_90;
    GtMathPs2::CGtV3d field_A0;
    float field_B0;
    float field_B4;
    float field_B8;
    float field_BC;
    float field_C0;
    int field_C4;
    int field_C8;
    int field_CC;
    unsigned char field_D0;
};

class CB3BehaviourCluster {
public:
    void SetInterpRig(CB3ClusterRig* p0);

    unsigned char pad_0[0xF0];
    CB3ClusterRig field_F0;
    unsigned char pad_1D0[0x11];
    unsigned char field_1E1;
};

// 0x003586B0
void CB3BehaviourCluster::SetInterpRig(CB3ClusterRig* p0)
{
    field_F0 = *p0;
    field_1E1 = 1;
}
