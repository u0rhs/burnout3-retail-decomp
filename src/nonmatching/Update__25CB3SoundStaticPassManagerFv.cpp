// NONMATCHING: Update__25CB3SoundStaticPassManagerFv -- retail 314 / ours 315 instructions, 203 in changed runs
// psweep: scoped #pragma inline_depth(3) [G] improves 214 -> 207
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CB3SoundStaticPassManager::Update() -- hand-written (v305); the lifter refused it.
// [C] name: the mangled symbol in retail's tables; file: research/retail_names.csv -> B3SoundStaticPassManager.cpp.
// Per race car (D_00522660 + i*0x27D0, cars from +0x12AD50): speed test, a line test against the streamed track, then the
// "big whoosh" voice. Field names are placeholders and every type is [G] (instruction widths).

#include "b3/GtMathPs2.h"
// [G] N182: scoped optimiser pragma found by the pragma sweep (psweep_all.py)
#pragma push
#pragma inline_depth(3)
using namespace GtMathPs2;

class CGtLine {
public:
    CGtV3d field_0;
    CGtV3d field_10;
};
struct UnkStruct_0041D3E0_mat {
    unsigned char pad_0[0x4];
    unsigned short field_4;
};
class CGtPolygonIntersectionResult {
public:
    unsigned char pad_0[0x60];
    UnkStruct_0041D3E0_mat * field_60;
    unsigned char pad_64[0xC];
};
class CB3StreamedTrack {
public:
    bool IntersectLineNearestWithUnit(unsigned int p0, const CGtLine & p1, CGtPolygonIntersectionResult * p2);
};
class CGtSoundVoiceParams {
public:
    float field_0;
    float field_4;
    float field_8;
    unsigned char pad_C[0xC];
    void * field_18;
    float field_1C;
    unsigned char pad_20[0x4];
    float field_24;
    unsigned char pad_28[0x10];
    float field_38;
    unsigned char pad_3C[0x8];
    unsigned char field_44;
    unsigned char field_45;
    unsigned char pad_46[0x1A];
};
struct UnkStruct_0041D3E0_obj {
    unsigned char pad_0[0xB0];
    CGtV3d field_B0;
};
struct UnkStruct_0041D3E0_rcp {
    unsigned char pad_0[0x1164];
    float field_1164;
};
// [G] a view of D_00522660 at one race car's stride (0x27D0): the cars start at +0x12AD50
struct UnkStruct_0041D3E0_car {
    unsigned char pad_0[0x12AD50];
    CGtV3d field_12AD50;
    unsigned char pad_12AD60[0x10];
    CGtV3d field_12AD70;
    CGtV3d field_12AD80;
    unsigned char pad_12AD90[0x12BF2E - 0x12AD90];
    unsigned char field_12BF2E;
    unsigned char pad_12BF2F[0x12C6FC - 0x12BF2F];
    signed char field_12C6FC;
    unsigned char pad_12C6FD[0x12D180 - 0x12C6FD];
    UnkStruct_0041D3E0_obj * field_12D180;
};
struct UnkStruct_D_00522660 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_00522680 { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_0064D3A0 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_00645170 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E77730 { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E75640 { unsigned char pad_0[0x20F0]; float field_20F0[8]; };
struct UnkStruct_kB3BigWhooshID { unsigned long field_0; unsigned char pad_8[0x8]; };
struct UnkStruct_D_0057BAF0 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_D_00522680 D_00522680;
extern UnkStruct_D_0064D3A0 D_0064D3A0;
extern UnkStruct_D_00645170 D_00645170;
extern UnkStruct_D_01E77730 D_01E77730;
extern UnkStruct_D_01E75640 D_01E75640;
extern UnkStruct_kB3BigWhooshID kB3BigWhooshID;
extern UnkStruct_D_0057BAF0 D_0057BAF0;
struct UnkStruct_D_01E75648 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E7569C { unsigned char pad_0[0x10]; };
extern UnkStruct_D_01E75648 D_01E75648;
extern UnkStruct_D_01E7569C D_01E7569C;

extern "C" unsigned int TestPosition__16CB3StreamedTrackFQ29GtMathPs26CGtV3d(void *, const void *);
extern "C" void Construct__19CGtSoundVoiceParamsFv(CGtSoundVoiceParams *);
extern "C" void * FindWave__19CGtSoundBankManagerCFRCUlb(void *, const void *, bool);
extern "C" float CalcFrequency__12CGtSoundWaveCFv(void *);
extern "C" void *TriggerVoice__20CGtSoundVoiceManagerFPC19CGtSoundVoiceParams(void *, const CGtSoundVoiceParams *);

class CB3SoundStaticPassManager {
public:
    void Update();
    float field_0;
    float field_4;
};
struct UnkStruct_0041D3E0_v3 { float x, y, z; };
// [L] N185: CGtV3d::operator+ on compiler-chosen registers (the header's body works on $vf1/$vf2)
static inline CGtV3d v305_add(const CGtV3d &a, const CGtV3d &b) { u_long128 r; asm("vadd.xyz %0, %1, %2" : "=j"(r) : "j"(a.mData), "j"(b.mData)); return CGtV3d(r); }
// [G] placeholder: the voice position set from a vector (by value: retail copies it to a stack temporary first)
static inline void func_0041D3E0_inl1(CGtSoundVoiceParams * pr, CGtV3d v) { *(UnkStruct_0041D3E0_v3 *)&pr->field_0 = *(UnkStruct_0041D3E0_v3 *)&v; }
// [L] N185: stands in for operator +(YAxisType, float) (B3O0PCH map, 80 bytes; the header has the operator- form):
// the scalar moved by its own statement, then `vaddx.y r, a, sx` on compiler-chosen registers
static inline YAxisType v305_addy(YAxisType a, float f)
{
    u_long128 s, r;
    asm("qmtc2.ni %1, %0" : "=j"(s) : "r"(f));
    asm("vaddx.y %0, %1, %2x" : "=j"(r) : "j"(a.lVector), "j"(s));
    return YAxisType(r);
}

// 0x0041D3E0
void CB3SoundStaticPassManager::Update()
{
    void * mgr = 0 < D_00645170.field_0 ? &D_0057BAF0 : 0;   // [G] dead: an inlined manager lookup whose result is unused
    int i = 0;
top:
    if (!(i < D_0064D3A0.field_0)) return;
    {
        UnkStruct_0041D3E0_car * car = (UnkStruct_0041D3E0_car *)((char *)&D_00522660 + i * 0x27D0);
        UnkStruct_0041D3E0_obj * obj = car->field_12D180;
        if (obj == 0) goto next;
        if (car->field_12BF2E == 0) goto next;
        if (obj->field_B0.GetLength() < 25.0f) goto next;
        int k = car->field_12C6FC;
        void * trk = (char *)&D_00522660 + i * 0x1CC + 0x12A348;
        unsigned int unit = TestPosition__16CB3StreamedTrackFQ29GtMathPs26CGtV3d(trk, &car->field_12AD80);
        car = (UnkStruct_0041D3E0_car *)((char *)&D_00522660 + (unsigned int)i * 0x27D0);
        CGtLine line;
        CGtPolygonIntersectionResult res;
        line.field_0 = car->field_12AD80;
        float w = ((UnkStruct_0041D3E0_rcp *)*(void **)((char *)&D_00522660 + k * 0x30 + 0x3C98C))->field_1164 / 10.0f;
        line.field_10 = v305_add(car->field_12AD80, car->field_12AD50 * w);
        line.field_0.SetY(v305_addy(line.field_0.Y(), 5.0f));
        line.field_10.SetY(v305_addy(line.field_10.Y(), 15.0f));
        bool hit = ((CB3StreamedTrack *)trk)->IntersectLineNearestWithUnit(unit, line, &res);
        if (hit) {
            unsigned short m = res.field_60->field_4;
            if ((((m & 0x100) != 0) ^ 1) == 0) goto next;
            if ((m & 0xFF) == 0x21 || (m & 0xFF) == 0x20) goto next;
            if (D_00522680.field_0 <= field_4) goto next;
            if (!(0.0f == field_0)) goto next;
            CGtV3d p = car->field_12AD80;
            p += car->field_12AD70 * 10.0f;
            float f = 0.0f + 0.8f + 0.4000000358f * (1.0f + D_01E75640.field_20F0[i]);
            CGtSoundVoiceParams params;
            Construct__19CGtSoundVoiceParamsFv(&params);
            params.field_1C = 1.0f;
            params.field_44 = 10;
            params.field_38 = 64.0f;
            func_0041D3E0_inl1(&params, p);
            params.field_45 = 0;
            void * wave = params.field_18 = FindWave__19CGtSoundBankManagerCFRCUlb(&D_01E75648, &kB3BigWhooshID, 1);
            params.field_24 = f * CalcFrequency__12CGtSoundWaveCFv(wave);
            TriggerVoice__20CGtSoundVoiceManagerFPC19CGtSoundVoiceParams(&D_01E7569C, &params);
            field_4 = 0.5f + D_00522680.field_0;
            field_0 = D_00522680.field_0;
        } else {
            if (field_0 != 0.0f && !(D_00522680.field_0 - field_0 <= 0.5f)) {
                CGtV3d p = car->field_12AD80;
                p += car->field_12AD70 * 10.0f;
                float f = 0.0f + 0.8f + 0.4000000358f * (1.0f + D_01E77730.field_0);
                CGtSoundVoiceParams params;
                Construct__19CGtSoundVoiceParamsFv(&params);
                params.field_1C = 1.0f;
                params.field_44 = 10;
                params.field_38 = 64.0f;
                func_0041D3E0_inl1(&params, p);
                params.field_45 = 0;
                void * wave = params.field_18 = FindWave__19CGtSoundBankManagerCFRCUlb(&D_01E75648, &kB3BigWhooshID, 1);
                params.field_24 = f * CalcFrequency__12CGtSoundWaveCFv(wave);
                TriggerVoice__20CGtSoundVoiceManagerFPC19CGtSoundVoiceParams(&D_01E7569C, &params);
            }
            field_0 = 0.0f;
        }
    }
next:
    i++;
    goto top;
}

#pragma pop
