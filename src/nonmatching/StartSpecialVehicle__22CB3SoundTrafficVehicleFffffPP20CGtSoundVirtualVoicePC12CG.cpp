// NONMATCHING: StartSpecialVehicle__22CB3SoundTrafficVehicleFffffPP20CGtSoundVirtualVoicePC12CGtSoundWave -- retail 87 / ours 87 instructions, 2 in changed runs
// a225: params split into its own struct (prm) + three 16B union temps (vel,pos,cp) reproduces frame 0xD0 and regs; 2 off = sq cp scheduled one slot early vs lwc1 pos.x
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// from build/vt\try_StartSpecialVehicle__22CB3SoundTrafficVe_best.cpp
// CB3SoundTrafficVehicle::StartSpecialVehicle(float,float,float,float,CGtSoundVirtualVoice**,const CGtSoundWave*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundTrafficVehicle.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

#include "b3/GtMathPs2.h"

class CGtSoundVirtualVoice;
class CGtSoundWave;
class CGtSoundVoiceParams;

class CB3SoundTrafficVehicle;
class CGtSoundListenerManager;
class CGtSoundVoiceManager;
struct UnkStruct_002789C0_1;
struct UnkStruct_D_00665EA0;

class CGtSoundVoiceManager {
public:
    CGtSoundVirtualVoice * AllocVirtualVoice();
    CGtSoundVirtualVoice * TriggerVoice(const CGtSoundVoiceParams*);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CGtSoundListenerManager {
public:
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};


struct UnkStruct_002789C0_prm {
    float field_0;
    float field_4;
    float field_8;
    float field_C;
    float field_10;
    float field_14;
    const CGtSoundWave * field_18;
    float field_1C;
    unsigned char pad_20[0x4];
    float field_24;
    unsigned char pad_28[0x10];
    float field_38;
    float field_3C;
    unsigned char pad_40[0x4];
    unsigned char field_44;
    unsigned char field_45;
    unsigned char pad_46[0xA];
};

struct UnkStruct_002789C0_tmp { float field_0; float field_4; float field_8; unsigned char pad_C[4]; float field_10; float field_14; float field_18; unsigned char pad_1C[4]; u_long128 field_20; };
union UnkStruct_002789C0_uv { u_long128 q; float f[4]; };
struct UnkStruct_D_00665EA0 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3SoundTrafficVehicle {
public:
    void StartSpecialVehicle(float p0, float p1, float p2, float p3, CGtSoundVirtualVoice** p4, const CGtSoundWave* p5);

    unsigned char pad_0[0xB0];
    u_long128 field_B0;
};

extern UnkStruct_D_00665EA0 D_00665EA0;
extern CGtSoundVoiceManager D_01E7569C;
extern CGtSoundListenerManager D_01E75688;

// [L] CGtSoundListenerManager::GetNearestListener(GtMathPs2::CGtV3d) const -- retail passes &field_B0 (hidden reference), declared by pointer to avoid a by-value copy
extern "C" void * GetNearestListener__23CGtSoundListenerManagerCFQ29GtMathPs26CGtV3d(const void *, const void *);
extern "C" void Construct__19CGtSoundVoiceParamsFv(void *);  // CGtSoundVoiceParams::Construct()
extern "C" void GetVelocity__16CGtSoundListenerCFPQ29GtMathPs26CGtV3d(void *, void *);  // CGtSoundListener::GetVelocity(GtMathPs2::CGtV3d*) const
extern "C" float CalcFrequency__12CGtSoundWaveCFv(const void *);  // CGtSoundWave::CalcFrequency() const

// 0x002789C0
void CB3SoundTrafficVehicle::StartSpecialVehicle(float p0, float p1, float p2, float p3, CGtSoundVirtualVoice** p4, const CGtSoundWave* p5)
{
    UnkStruct_002789C0_prm prm;
    UnkStruct_002789C0_uv vel;
    UnkStruct_002789C0_uv pos;
    UnkStruct_002789C0_uv cp;
    if (p5 == 0) {
        *p4 = D_01E7569C.AllocVirtualVoice();
        return;
    }
    Construct__19CGtSoundVoiceParamsFv(&prm);
    void * r2 = GetNearestListener__23CGtSoundListenerManagerCFQ29GtMathPs26CGtV3d(&D_01E75688, &field_B0);
    GetVelocity__16CGtSoundListenerCFPQ29GtMathPs26CGtV3d(r2, (GtMathPs2::CGtV3d*)&vel);
    pos.q = field_B0;
    prm.field_0 = pos.f[0];
    cp.q = vel.q;
    prm.field_4 = pos.f[1];
    prm.field_18 = p5;
    prm.field_8 = pos.f[2];
    float t4 = cp.f[0];
    float t5 = cp.f[1];
    float t6 = cp.f[2];
    float *vp = &prm.field_C;
    float &w = prm.field_38;
    vp[0] = t4;
    vp[1] = t5;
    vp[2] = t6;
    w = p1;
    prm.field_1C = p0;
    prm.field_3C = p2;
    float r4 = CalcFrequency__12CGtSoundWaveCFv(p5);
    prm.field_45 = 1;
    prm.field_44 = 8;
    unsigned char t7 = D_00665EA0.field_0;
    prm.field_24 = (p3 * r4);
    if (t7 != 0) {
        w = w * 10.0f;
    }
    *p4 = D_01E7569C.TriggerVoice((const CGtSoundVoiceParams*)&prm);
}

