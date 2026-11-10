// CB3ParticleArray::EndUpdate(float,const GtMathPs2::CGtV2d&) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ParticleRendererPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a188: volatile read of field_60 stops CSE; local VU asm).

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
struct UnkStruct_254C90_cfg { unsigned char pad_0[0x48]; float field_48; };
class CB3ParticleArray {
public:
    class CB3ParticleBank {
    public:
        void Update(CB3ParticleArray *, float, float);
        unsigned char pad_0[0x2C];
    };
    void EndUpdate(float t, const CGtV2d &v);
    unsigned char pad_0[0x60];
    CGtV4d field_60;
    unsigned char pad_70[0xC];
    float field_7C;
    unsigned char pad_80[0x64];
    UnkStruct_254C90_cfg *field_E4;
    CB3ParticleBank field_E8;
    CB3ParticleBank field_114;
};
// 0x00254C90
void CB3ParticleArray::EndUpdate(float t, const CGtV2d &v)
{
    float dt = t - field_7C;
    field_E8.Update(this, field_7C, dt);
    field_114.Update(this, field_7C, dt);
    float k = field_E4->field_48;
    // [G] volatile read: keeps retail's second lqc2 of field_60 (no CSE/vmove); local asm: SetX/SetZ on vf3 "+j" and vadd.xyz keep-w assign (no header API)
    CGtV3d r(*(volatile u_long128 *)&field_60.mData);
    float kx = k * v.marValues[0];
    float kz = k * v.marValues[1];
    asm("qmtc2.ni %1, $vf2\n\tvaddx.x %0, $vf0, $vf2x" : "+j"(r.mData) : "r"(kx));
    asm("qmtc2.ni %1, $vf2\n\tvaddx.z %0, $vf0, $vf2x" : "+j"(r.mData) : "r"(kz));
    asm("vadd.xyz %0, $vf0, %1" : "+j"(field_60.mData) : "j"(r.mData));
}
