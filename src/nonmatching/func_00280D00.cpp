// NONMATCHING: func_00280D00 -- retail 176 / ours 177 instructions, 64 in changed runs
// 64 instrs, all block layout (+0x10 frame): logic is right (lifter's version had 270 instrs). MWCC parks the body of 'if (1914 == 0 && 8DB && !8E0) {...}' after the tail, retail keeps it inline (bnez to the tail). Tried nested ifs, inverted ||-with-empty-then, bool temp, pointer/bool field types, swapping the func_00131E40 if/else.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// from build/vt\try_func_00280D00_best.cpp
// func_00280D00 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

#include "b3/GtMathPs2.h"

class CGtSoundVoiceParams;
enum ESoundWorldCrashSurfaceType {};

class CGtSoundVirtualVoice;
class CGtSoundVoiceManager;
struct UnkStruct_00280D00;
struct UnkStruct_00280D00_1;
struct UnkStruct_00280D00_2;
struct UnkStruct_00280D00_3;
struct UnkStruct_00280D00_a2;
struct UnkStruct_00280D00_e0;
struct UnkStruct_D_004E1364;
struct UnkStruct_D_004EE040;
struct UnkStruct_D_00522680;

class CGtSoundVoiceManager {
public:
    int TriggerVoice(const CGtSoundVoiceParams*);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CGtSoundVirtualVoice {
public:
    void SetPriority(float);
    void IgnoreGlobalPitch();
};

struct UnkStruct_00280D00_a2 {
    unsigned char pad_0[0xB0];
    u_long128 field_B0;
    unsigned char pad_C0[0x130];
    float field_1F0;
    unsigned char pad_1F4[0x10];
    UnkStruct_00280D00_1 * field_204;
    unsigned char pad_208[0x8];
    unsigned char field_210;
    unsigned char pad_211[0x1];
    unsigned char field_212;
    unsigned char pad_213[0x11E1];
    UnkStruct_00280D00_3 * field_13F4;
    unsigned char pad_13F8[0x148];
    unsigned char field_1540;
};

struct UnkStruct_00280D00_1 {
    unsigned char pad_0[0x30];
    GtMathPs2::CGtV3d field_30;
};

struct UnkStruct_00280D00_2 {
    unsigned char pad_0[0x18];
    int field_18;
    float field_1C;
    unsigned char pad_20[0x24];
    unsigned char field_44;
    unsigned char field_45;
    unsigned char pad_46[0x2A];
};

struct UnkStruct_00280D00_3 {
    unsigned char pad_0[0x1914];
    int field_1914;
    unsigned char pad_1918[0x94];
    signed char field_19AC;
};

struct UnkStruct_D_00522680 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004E1364 {
    float field_0;
};

struct UnkStruct_00280D00_e0 {
    unsigned char pad_0[0x40];
};

struct UnkStruct_D_004EE040 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00280D00 {
    unsigned char pad_0[0x10];
    UnkStruct_00280D00_e0 field_10[1];  // [G] element count unknown
    unsigned char pad_50[0x80C];
    int field_85C;
    unsigned char pad_860[0x1C];
    CGtSoundVirtualVoice * field_87C;
    unsigned char pad_880[0x28];
    float field_8A8;
    unsigned char pad_8AC[0x2F];
    unsigned char field_8DB;
    unsigned char pad_8DC[0x4];
    unsigned char field_8E0;
    unsigned char pad_8E1[0x3];
    unsigned char field_8E4;
    unsigned char pad_8E5[0x3];
    float field_8E8;
};

extern UnkStruct_D_00522680 D_00522680;
extern UnkStruct_D_004E1364 D_004E1364;
extern CGtSoundVoiceManager D_01E7569C;
extern UnkStruct_D_004EE040 D_004EE040;

extern "C" void Construct__19CGtSoundVoiceParamsFv(void *);  // CGtSoundVoiceParams::Construct()
extern "C" void SetInfo__14CB3SoundScrapeF27ESoundWorldCrashSurfaceTypeffPQ29GtMathPs26CGtV3d(void *, ESoundWorldCrashSurfaceType, float, float, GtMathPs2::CGtV3d *);  // CB3SoundScrape::SetInfo(ESoundWorldCrashSurfaceType,float,float,GtMathPs2::CGtV3d*)
extern "C" void func_0027E570(UnkStruct_00280D00 *, GtMathPs2::CGtV3d *, float);
extern "C" void func_0027E170(UnkStruct_00280D00 *, GtMathPs2::CGtV3d *, int, float);
extern "C" void func_0027BCE0(UnkStruct_00280D00 *, GtMathPs2::CGtV3d *);
extern "C" int func_00131E40(void *);

// 0x00280D00
extern "C" void func_00280D00(UnkStruct_00280D00 * self, int p0, UnkStruct_00280D00_a2 * p1, float f0)
{
    GtMathPs2::CGtV3d pos = p1->field_204->field_30;
    UnkStruct_00280D00_2 params;
    if (p1->field_13F4->field_1914 == 0) {
        GtMathPs2::CGtV4d v(p1->field_B0);
        SetInfo__14CB3SoundScrapeF27ESoundWorldCrashSurfaceTypeffPQ29GtMathPs26CGtV3d(&self->field_10[p1->field_13F4->field_19AC], (ESoundWorldCrashSurfaceType)0, 1.0f, v.f[3], &pos);
    }
    if (p1->field_210 != 0) {
        if (p1->field_13F4->field_1914 == 0 && self->field_8DB != 0 && self->field_8E0 == 0) {
            if (func_00131E40(&D_004EE040) == 0) {
                func_0027BCE0(self, &pos);
            } else {
                if (p1->field_1540 != 0) {
                    Construct__19CGtSoundVoiceParamsFv(&params);
                    if (self->field_8E4 == 0) {
                        self->field_8E8 = D_00522680.field_0;
                        params.field_18 = self->field_85C;
                        params.field_1C = 0.7f;
                        params.field_45 = 1;
                        params.field_44 = 2;
                        self->field_87C = (CGtSoundVirtualVoice *)D_01E7569C.TriggerVoice((const CGtSoundVoiceParams*)&params);
                        self->field_87C->SetPriority(1.0f);
                        if (self->field_87C != 0) {
                            self->field_87C->IgnoreGlobalPitch();
                        }
                    }
                    self->field_8E4 = 1;
                    if (D_00522680.field_0 - self->field_8E8 < 1.0f) return;
                }
                if (p1->field_212 != 0 && self->field_8A8 > 15.0f) {
                    func_0027BCE0(self, &pos);
                }
            }
        }
        if (p1->field_13F4->field_1914 == 0) {
            func_0027E170(self, &pos, 0, f0 / p1->field_1F0);
        } else {
            func_0027E170(self, &pos, 0, 0.5f * (f0 / p1->field_1F0));
        }
    } else {
        if (p1->field_13F4->field_1914 == 0) {
            func_0027E570(self, &pos, 10.0f * (f0 / p1->field_1F0));
        } else {
            func_0027E570(self, &pos, 0.5f * (f0 / p1->field_1F0));
        }
    }
}
