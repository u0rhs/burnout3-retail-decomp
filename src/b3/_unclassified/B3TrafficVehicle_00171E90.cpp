// CB3TrafficVehicle::ResetMemberVariables() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficVehicle.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (ResetMemberVariables: local class, vadd.xyz zero / vaddw lane asm via =j/+j; zero of field_60 placed after field_17B).

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
extern "C" void *memset(void *, int, unsigned int);
extern unsigned char _gu8NextFlashPattern;
class CB3TrafficVehicle {
public:
    void ResetMemberVariables();
    unsigned char pad_0[0x60];
    CGtV3d field_60;
    CGtV3d field_70;
    CGtV3d field_80;
    CGtV3d field_90;
    CGtV3d field_A0;
    int field_B0;
    int field_B4;
    float field_B8;
    int field_BC;
    float field_C0;
    int field_C4;
    unsigned char field_C8;
    unsigned char field_C9;
    unsigned char pad_CA[0x26];
    int field_F0[6];
    int field_108;
    int field_10C;
    int field_110;
    int field_114;
    int field_118;
    float field_11C;
    int field_120;
    float field_124;
    int field_128;
    int field_12C;
    int field_130;
    int field_134;
    int field_138;
    int field_13C;
    float field_140;
    float field_144;
    float field_148;
    int field_14C;
    int field_150;
    int field_154;
    int field_158;
    int field_15C;
    int field_160;
    int field_164;
    int field_168;
    int field_16C;
    signed char field_170;
    unsigned char field_171;
    unsigned char field_172;
    unsigned char field_173;
    unsigned char field_174;
    unsigned char field_175;
    unsigned char field_176;
    unsigned char field_177;
    unsigned char field_178;
    unsigned char field_179;
    unsigned char field_17A;
    unsigned char field_17B;
};

// 0x00171E90
void CB3TrafficVehicle::ResetMemberVariables()
{
    { u_long128 r; asm("vadd.xyz %0, $vf0, $vf0" : "=j"(r)); field_70.mData = r; }
    { u_long128 r; asm("vadd.xyz %0, $vf0, $vf0" : "=j"(r)); field_80.mData = r; }
    { u_long128 r; asm("vadd.xyz %0, $vf0, $vf0" : "=j"(r)); field_90.mData = r; }
    { u_long128 r; asm("vadd.xyz %0, $vf0, $vf0" : "=j"(r)); field_A0.mData = r; }
    { u_long128 r = field_70.mData; asm("vaddw.x %0, $vf0, $vf0w" : "+j"(r)); field_70.mData = r; }
    { u_long128 r = field_80.mData; asm("vaddw.y %0, $vf0, $vf0w" : "+j"(r)); field_80.mData = r; }
    { u_long128 r = field_90.mData; asm("vaddw.z %0, $vf0, $vf0w" : "+j"(r)); field_90.mData = r; }
    field_114 = 0;
    field_C4 = 0;
    field_118 = 0;
    field_11C = -1.0f;
    memset(&field_70, 0, 0x80);
    field_BC = 0;
    field_C0 = 1.0f;
    field_B4 = 0;
    field_B8 = 1.0f;
    field_C8 = 0;
    field_128 = 0;
    field_12C = 0;
    field_130 = 0;
    field_17A |= 1;
    field_175 = 0;
    field_17B = 0;
    { u_long128 r; asm("vadd.xyz %0, $vf0, $vf0" : "=j"(r)); field_60.mData = r; }
    field_120 = 0;
    field_177 = 0;
    field_124 = 1.0f;
    field_13C = 0;
    field_172 = 0;
    field_170 = -1;
    field_140 = -1.0f;
    field_144 = -1.0f;
    field_148 = -1.0f;
    field_14C = 0;
    field_150 = 0;
    field_154 = 0;
    field_158 = 0;
    field_15C = 0;
    field_168 = 0;
    field_16C = 0;
    field_173 = 0;
    field_C9 = 0;
    field_10C = 0;
    field_110 = 0;
    field_B0 = 0;
    field_160 = 0;
    field_164 = 0;
    field_134 = 0;
    field_138 = 0;
    field_108 = 0;
    field_174 = 0;
    for (int i = 0; i < 6; i++) field_F0[i] = 0;
    field_176 = 0;
    field_171 = 0;
    field_179 = 0;
    field_178 = 0;
    _gu8NextFlashPattern = 0;
}
