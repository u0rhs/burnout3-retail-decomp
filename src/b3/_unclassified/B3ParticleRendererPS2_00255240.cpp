// CB3ParticleArray::Construct(EParticleArrayID) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ParticleRendererPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (near23: N140 pad inside a by-value SetGtV3d wrapper inline (frame slot order exact)).

// Hand-finished by near23 from v302's archive: the SetGtV3d call goes through a by-value wrapper (func_00255240_inl6) holding the
// N140 pad [G], which puts retail's two dead slots between the depth-1 'one' temp and the depth-2 temps (frame exact).

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

enum EParticleArrayID {};

struct UnkStruct_255240_params {
    unsigned char pad_0[0x4];
    unsigned char field_4;
    unsigned char pad_5[0x3];
    int field_8;
    int field_C;
    float field_10;
    float field_14;
    unsigned char field_18[4];
    unsigned char field_1C[4];
    unsigned char field_20[4];
    unsigned char field_24;
    unsigned char pad_25[0x3];
    float field_28;
    float field_2C;
    float field_30;
    float field_34;
    float field_38;
    float field_3C;
    float field_40;
    float field_44;
    unsigned char pad_48[0x4];
    float field_4C;
    unsigned char pad_50[0x10];
    unsigned int field_60;
    unsigned int field_64;
    unsigned int field_68;
    float field_6C;
    float field_70;
    float field_74;
    float field_78;
    unsigned char pad_7C[0x4];
};

// [L] N185: stands in for CGtV4d::operator*=(CGtV4d) (B3O0PCH map, 76 bytes; not in GtMathPs2.h yet):
// one in-place vmul, the argument by value.
static inline void func_00255240_inl1(CGtV4d &d, CGtV4d s) { asm("vmul.xyzw %0, %0, %1" : "+j"(d.mData) : "j"(s.mData)); }

// [L] N185: stands in for CGtV4d::Set(float,float,float,float) (B3O0PCH map, 80 bytes; not in GtMathPs2.h yet).
static inline void func_00255240_inl4(CGtV4d &d, float x, float y, float z, float w) { d = CGtV4d(x, y, z, w); }

// N140 pad [G]: an unused 16-byte local (empty ctor/dtor, no code) standing in for retail's dead frame slots.
struct UnkStruct_00255240_pad { int x[4]; UnkStruct_00255240_pad() {} ~UnkStruct_00255240_pad() {} };
// [G] by-value wrapper: its N140 pad lands below the depth-1 temps, as retail's dead slots do
static inline void func_00255240_inl6(CGtV3dPlus &d, CGtV3d v) { UnkStruct_00255240_pad p; d.SetGtV3d(v); }
static inline void func_00255240_inl5(CGtV3dPlus &d, float x, float y, float z) { func_00255240_inl6(d, CGtV3d(x, y, z)); }

class CB3ParticleArrayBase {
public:
    static UnkStruct_255240_params maStandardParams[];
};

class CB3ParticleArray {
public:
    class CB3ParticleBank {
    public:
        void Construct(unsigned int);
        unsigned char pad_0[0x2C];
    };
    void Construct(EParticleArrayID id);
    CGtV4d field_0;
    CGtV4d field_10;
    CGtV4d field_20;
    CGtV4d field_30;
    CGtV4d field_40;
    CGtV3dPlus field_50;
    CGtV3dPlus field_60;
    int field_70;
    float field_74;
    float field_78;
    float field_7C;
    float field_80;
    float field_84;
    float field_88;
    float field_8C;
    float field_90;
    float field_94;
    float field_98;
    float field_9C;
    float field_A0;
    int field_A4;
    unsigned long field_A8;
    u_long128 field_B0;
    u_long128 field_C0;
    unsigned char pad_D0[0x10];
    int field_E0;
    UnkStruct_255240_params *field_E4;
    CB3ParticleBank field_E8;
    CB3ParticleBank field_114;
    float field_140;
    float field_144;
};

// 0x00255240
void CB3ParticleArray::Construct(EParticleArrayID id)
{
    field_E4 = &CB3ParticleArrayBase::maStandardParams[id];
    field_E8.Construct(field_E4->field_60);
    field_114.Construct(field_E4->field_64);
    field_E0 = 0;
    field_0 = CGtV4d((int)field_E4->field_18[0], (int)field_E4->field_18[1], (int)field_E4->field_18[2], (int)field_E4->field_18[3]);
    field_10 = CGtV4d((int)field_E4->field_1C[0], (int)field_E4->field_1C[1], (int)field_E4->field_1C[2], (int)field_E4->field_1C[3]);
    field_20 = CGtV4d((int)field_E4->field_20[0], (int)field_E4->field_20[1], (int)field_E4->field_20[2], (int)field_E4->field_20[3]);
    CGtV4d scale;
    UnkStruct_00255240_pad p;
    if (field_E4->field_24)
        func_00255240_inl4(scale, 0.5f, 0.5f, 0.5f, 0.501960814f);
    else
        func_00255240_inl4(scale, 0.250980407f, 0.250980407f, 0.250980407f, 0.501960814f);
    func_00255240_inl1(field_0, scale);
    func_00255240_inl1(field_10, scale);
    func_00255240_inl1(field_20, scale);
    field_40 = CGtV4d(0.0f, 0.0f, 0.0f, 0.0f);
    field_30 = CGtV4d(1.0f, 1.0f, 1.0f, 1.0f);
    func_00255240_inl5(field_50, 0.0f, 0.0f, 0.0f);
    field_50.SetPlus(field_E4->field_70);
    func_00255240_inl5(field_60, 0.0f, field_E4->field_44, 0.0f);
    field_60.SetPlus(0.5f * field_E4->field_74);
    field_7C = 0.0f;
    field_74 = field_E4->field_10;
    field_78 = field_E4->field_14;
    field_88 = field_E4->field_34;
    field_8C = field_E4->field_38;
    field_80 = field_E4->field_3C;
    field_84 = field_E4->field_40;
    field_94 = field_E4->field_28;
    field_98 = field_E4->field_2C;
    field_9C = field_E4->field_30;
    field_90 = field_E4->field_6C;
    field_A0 = field_E4->field_4C;
    switch (field_E4->field_8) {
    case 0:
        field_70 = field_E4->field_4 ? 2 : 0;
        break;
    case 1:
        field_70 = field_E4->field_4 ? 3 : 1;
        break;
    case 2:
        field_70 = 4;
        break;
    case 3:
        field_70 = 5;
        break;
    }
    switch (field_E4->field_C) {
    case 0: {
        u_long128 q;
        asm("pcpyld %0, %2, %1" : "=r"(q) : "r"(0x44), "r"(0x42));
        field_B0 = q;
        break;
    }
    case 2: {
        u_long128 q;
        asm("pcpyld %0, %2, %1" : "=r"(q) : "r"(0x48), "r"(0x42));
        field_B0 = q;
        break;
    }
    case 1: {
        u_long128 q;
        asm("pcpyld %0, %1, %2" : "=r"(q) : "r"(0x42), "r"(0x42));
        field_B0 = q;
        break;
    }
    }
    switch (field_70) {
    case 0:
    case 1:
        field_A4 = 0x502B4000;
        field_A8 = 0x42412;
        break;
    case 2:
    case 3:
    case 5:
        field_A4 = 0x902A4000;
        field_A8 = 0x424242412UL;
        break;
    case 4:
        field_A4 = 0xC02E4000;
        field_A8 = 0x412412412412UL;
        break;
    }
    {
        u_long128 q;
        asm("pcpyld %0, %2, %1" : "=r"(q) : "r"(((unsigned long)field_E4->field_68 << 4) | 0x5100D), "r"(0x47));
        field_C0 = q;
    }
    field_144 = field_74;
    field_140 = field_74 * field_E4->field_78;
}
