// CB3SoundTrafficVehicle::UpdateDoppler(float*,float*,float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundTrafficVehicle.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (ghvu4: Ghidra draft; GtMath Max/Min clamp, header DotProduct x2, named vel/pos locals for VU numbering, 0x40 N140 pad).

#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"
using namespace GtMathPs2;

struct UnkStruct_00278830_car { unsigned char pad_0[0xB0]; CGtV4d field_B0; unsigned char pad_C0[0x144]; CGtMatrix3x4 * field_204; };
struct UnkStruct_00278830_pl { UnkStruct_00278830_car * field_0; unsigned char pad_4[0x2C]; };
struct UnkStruct_D_0055EFEC { UnkStruct_00278830_pl field_0[4]; };
struct UnkStruct_00278830_tv { unsigned char pad_0[0x90]; CGtV3d field_90; CGtV3d field_A0; unsigned char pad_B0[0x14]; float field_C4; unsigned char pad_C8[0xAF]; unsigned char field_177; };
struct UnkStruct_00278830_dt { float field_0[0xFE]; };
extern UnkStruct_D_0055EFEC D_0055EFEC;
extern UnkStruct_00278830_dt D_0055B894[];
class CB3SoundDoppler {
public:
    void Update(float, float, float, float, float *, float *);
    unsigned char pad_0[0xC];
};
class CB3SoundTrafficVehicle {
public:
    void UpdateDoppler(float *, float *, float);
    UnkStruct_00278830_tv * field_0;
    unsigned char pad_4[0x4C];
    CB3SoundDoppler field_50;
    unsigned char pad_5C[0x80];
    float field_DC;
    unsigned char pad_E0[0x14];
    float field_F4;
    float field_F8;
    float field_FC;
    unsigned char pad_100[0x4];
    float field_104;
    unsigned char pad_108[0x4];
    float field_10C;
    unsigned char pad_110[0x1C];
    signed char field_12C;
};

// [G] N140 frame pad: retail's frame keeps four more unused 16-byte slots (dead by-value copies of the vector maths), one 0x40 pad.
struct UnkStruct_00278830_pad { int x[16]; UnkStruct_00278830_pad() {} ~UnkStruct_00278830_pad() {} };

// 0x00278830
void CB3SoundTrafficVehicle::UpdateDoppler(float * pitch, float * vol, float dt)
{
    UnkStruct_00278830_pad pad;
    const float k40 = 40.0f;
    UnkStruct_00278830_tv * tv = field_0;
    unsigned char k = tv->field_177;
    UnkStruct_00278830_car * car = D_0055EFEC.field_0[field_12C].field_0;
    float f = tv->field_C4 / k40;
    f = GtMath::Max(f, 0.0f);
    f = GtMath::Min(f, 1.0f);
    field_F4 = field_104 * f;
    field_F8 = field_10C * f;
    field_DC = D_0055B894[field_12C].field_0[k];
    CGtV3d vel = *(const CGtV3d *)&car->field_B0;  // [G] the car's velocity (CGtV4d, w = speed) read as a CGtV3d
    CGtV3d v = field_0->field_90 * field_0->field_C4;
    CGtV3d pos = car->field_204->mPos;
    CGtV3d d = (pos - field_0->field_A0) * (1.0f / field_DC);
    field_FC = DotProduct(vel, d) - DotProduct(v, d);
    // [L] 2.236936331f: m/s -> mph on field_B0.W() (near18)
    field_50.Update(field_DC, field_FC, 2.236936331f * (float)D_0055EFEC.field_0[field_12C].field_0->field_B0.W(), dt, pitch, vol);  // [C] retail FPU form, not a VU lane op: 0x2789A4 lwc1 / 0x2789AC mul.s (the cast keeps the port's PS2 float model)
}
