// NONMATCHING: Update__20CB3SoundCrashManagerFv -- retail 458 / ours 451 instructions, 206 in changed runs
// draftAO (2026-11-01): complete: the scalar quaternion stand-in replaced by retail's CGtQuatPos::ConvertToMatrix of D_00517050[i] (q * sqrt 2 via the out-of-line CGtV4d(u_long128) ctor, retail's (1-yy)-zz order, row w lanes unset as retail where the stand-in wrote 0) into field_250[i] (CGtMatrix3x4, 0x40 stride); player count read as retail from D_00522660 + 0x12AD40 (the draft named a D_0064D3A0 symbol retail does not have); calls identical, behaviour_audit quiet | Before: fix2 (2026-11-01): player entries read at D_00522660 + 0x12AD50 + i*0x27D0 (+0x18EA byte, +0x16B4 float) where the draft read D_0064EA00 +0x1A/+0x24 [C] retail 0x2812F0..0x281338; car position row from +0x10 of the 0xBB0 entry (0x517060), not +0x20 [C] 0x2813A8 | Before: audit1 (2026-11-01): manager layout: pad_190 was 0x84, not 0x384, so field_514..field_92C read 0x300 low (behaviour_audit: Stop/...
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the asm (0x281160..0x281884): every call, branch and non-stack store traced (store census equal); behaviour_audit quiet




// CB3SoundCrashManager::Update -- son7 first archive, completed by draftAO fork C. Ticks the manager's byte cooldown counters,
// finds whether any local player is racing / wrecked, rebuilds each player's matrix (this+0x250 + i*0x40) from the car's
// CGtQuatPos (D_004EE040 + 0x29010 + i*0xBB0 = D_00517050[i]) through CGtQuatPos::ConvertToMatrix [C retail 0x281350..0x281544:
// q * sqrt(2) through the out-of-line CGtV4d(u_long128) ctor, rows (1-yy-zz, xy+wz, xz-wy) / (xy-wz, 1-xx-zz, yz+wx) /
// (xz+wy, yz-wx, 1-xx-yy) lane by lane, mPos = the car position quad; the rows' w lanes are never written (stale stack lanes)],
// runs the sub-updaters, updates the glass voices and the scrape objects, and finally the crash stream. Field names are
// placeholders and every type is [G].
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
using namespace GtMathPs2;

struct UnkStruct_Update_v3 { float x; float y; float z; };
struct UnkStruct_Update_params {
    UnkStruct_Update_v3 field_0; unsigned char pad_C[0xC];
    int field_18; float field_1C; unsigned char pad_20[0x24];
    unsigned char field_44; unsigned char field_45; unsigned char pad_46[0xA];
};
struct UnkStruct_Update_voice { unsigned char pad_0[0xC]; int field_C; };
// [C] stride 0xBB0, a CGtQuatPos at +0 (retail 0x281370..0x2813A8: quat lqc2 +0, position lq +0x10)
struct UnkStruct_Update_car { CGtQuatPos field_0; unsigned char pad_20[0xB90]; };
// [C] the player entries at D_00522660 + 0x12AD50, stride 0x27D0 (retail 0x2812F0..0x281338: lbu +0x18EA, lwc1 +0x16B4)
struct UnkStruct_Update_ply { unsigned char pad_0[0x16B4]; float field_16B4; unsigned char pad_16B8[0x232]; unsigned char field_18EA; unsigned char pad_18EB[0xEE5]; };
struct UnkStruct_Update_scrape { unsigned char pad_0[0x40]; };

class CB3SoundCrashManager {
public:
    void Update();
    void UpdateDeadMansHorn();
    void UpdateParticulateGlass();
    void UpdateSteam();
    void UpdateFire();
    void UpdateKerbBounces();
    void UpdateCrashStream(bool);
    unsigned char pad_0[0x10];
    UnkStruct_Update_scrape field_10[6];
    unsigned char pad_190[0xC0];
    CGtMatrix3x4 field_250[4];      // [C] per-player car matrix (0x40 stride, retail sqc2 0x250/0x260/0x270 + sq 0x280 off this + i*0x40); [G] count (room to 0x350)
    unsigned char pad_350[0x1C4];   // audit1: field_514 at 0x514 [C] retail 0x281824 / 0x281594 offsets
    unsigned char field_514[8];
    unsigned char pad_51C[0x344];
    void *field_860;
    void *field_864;
    unsigned char pad_868[0xC];
    UnkStruct_Update_voice *field_874;
    void *field_878;
    unsigned char pad_87C[0x30];
    int field_8AC;
    unsigned char pad_8B0[0x12];
    unsigned char field_8C2, field_8C3, field_8C4, field_8C5, field_8C6, field_8C7, field_8C8, field_8C9, field_8CA, field_8CB, field_8CC, field_8CD, field_8CE, field_8CF, field_8D0;
    unsigned char pad_8D1[5];
    unsigned char field_8D6;
    unsigned char pad_8D7[3];
    unsigned char field_8DA;
    unsigned char pad_8DB[2];
    unsigned char field_8DD;
    unsigned char pad_8DE;
    unsigned char field_8DF;
    unsigned char field_8E0;
    unsigned char pad_8E1[0xB];
    UnkStruct_Update_v3 field_8EC[4];
    void *field_91C[4];
    unsigned char pad_92C[0x11];
    unsigned char field_93D;
};

struct UnkStruct_D_0051BA88 { unsigned char pad_0[0x1B4]; void **field_1B4; };
extern UnkStruct_D_0051BA88 *D_0051BA88;
extern unsigned char D_00522660[];
extern UnkStruct_Update_car D_00517050[];
extern CGtV3d D_0064D3E0;   // [C] lq (the listener position [G])
extern float D_004E1240;
extern float D_004E127C;
extern int D_00522678;
extern "C" void Construct__19CGtSoundVoiceParamsFv(void *);
extern "C" void Stop__20CGtSoundVirtualVoiceFv(void *);
extern "C" int IsPlaying__20CGtSoundVirtualVoiceFv(void *);
extern "C" void Update__20CGtSoundVirtualVoiceFPC19CGtSoundVoiceParams(void *, const void *);
extern "C" void Update__14CB3SoundScrapeFb(void *, bool);

// 0x00281520
void CB3SoundCrashManager::Update()
{
    UnkStruct_D_0051BA88 *owner = D_0051BA88;
    long play = 0;
    bool wrecked = false;
    bool all = false;
    if (field_8C5 != 0) field_8C5--;
    if (field_8C6 != 0) field_8C6--;
    if (field_8C7 != 0) field_8C7--;
    if (field_8C8 != 0) field_8C8--;
    if (field_8C9 != 0) field_8C9--;
    if (field_8CA != 0) field_8CA--;
    if (field_8CB != 0) field_8CB--;
    if (field_8CC != 0) field_8CC--;
    if (field_8CD != 0) field_8CD--;
    if (field_8C3 != 0) field_8C3--;
    if (field_8C4 != 0) field_8C4--;
    if (field_8CE != 0) field_8CE--;
    if (field_8CF != 0) field_8CF--;
    if (field_8C2 != 0) field_8C2--;
    if (field_8D0 != 0) field_8D0--;
    for (int i = 0; i < 8; i++) {
        if (field_514[i] != 0) field_514[i]--;
    }
    if (owner != 0 && owner->field_1B4 != 0 && ((long (*)(void *))((void **)*owner->field_1B4)[0x98 / 4])(owner->field_1B4) == 3) all = true;
    int i = 0;
    float k = D_004E1240;
    while (i < *(int *)(D_00522660 + 0x12AD40)) {   // [C] the local player count (retail lw D_00522660 + 0x12AD40 each pass)
        UnkStruct_Update_ply *ply = (UnkStruct_Update_ply *)(D_00522660 + 0x12AD50) + i;
        if (ply->field_18EA != 0) play = 1;
        if (all && ply->field_16B4 <= 0.0f) {
            play = 0;
            wrecked = true;
        }
        field_250[i] = D_00517050[i].field_0.ConvertToMatrix();
        i++;
    }
    field_8DF = D_00522678 != 1;
    UpdateDeadMansHorn();
    if (wrecked) {
        if (field_864 != 0) { Stop__20CGtSoundVirtualVoiceFv(field_864); field_864 = 0; }
        if (field_860 != 0) { Stop__20CGtSoundVirtualVoiceFv(field_860); field_860 = 0; }
        if (field_878 != 0) { Stop__20CGtSoundVirtualVoiceFv(field_878); field_878 = 0; }
    } else {
        UpdateParticulateGlass();
        UpdateSteam();
        UpdateFire();
    }
    UpdateKerbBounces();
    for (unsigned char u = 0; u < field_93D; u = u + 1) {
        UnkStruct_Update_params p;
        Construct__19CGtSoundVoiceParamsFv(&p);
        p.field_0 = field_8EC[u];
        p.field_45 = 1;
        p.field_1C = D_004E127C;
        Update__20CGtSoundVirtualVoiceFPC19CGtSoundVoiceParams(field_91C[u], &p);
    }
    if (play == 0) {
        if (field_8D6 != 0) {
            field_8D6 = 0;
            field_8DA = 0;
        }
    } else if (*(int *)(D_00522660 + 0x12AD40) == 1) {
        CGtV3d lPos = D_0064D3E0;
        UnkStruct_Update_v3 pv;
        pv.x = lPos.X(); pv.y = lPos.Y(); pv.z = lPos.Z();
        if (field_874 != 0 && field_8AC == field_874->field_C && IsPlaying__20CGtSoundVirtualVoiceFv(field_874) != 0) {
            UnkStruct_Update_params p;
            Construct__19CGtSoundVoiceParamsFv(&p);
            p.field_0 = pv;
            Update__20CGtSoundVirtualVoiceFPC19CGtSoundVoiceParams(field_874, &p);
        } else {
            field_874 = 0;
        }
    }
    for (int j = 0; j < 6; j++) Update__14CB3SoundScrapeFb(&field_10[j], play != 0);
    if (play == 0 && field_8E0 != 0) field_8E0 = 0;
    if (play != 0 && field_8DD != 0) play = 0;
    UpdateCrashStream(play != 0);
}
