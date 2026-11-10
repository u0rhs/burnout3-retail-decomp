// NONMATCHING: Draw__15CB3RacePositionFi -- retail 256 / ours 256 instructions, 27 in changed runs
// stabs3: 44 -> 27. Revenge-driven: one rank index shared by the ranking and draw loops (Revenge lnRenderIndex; fixed the s2/s4 swap), loop indices i/j shared across loops (lnRaceCarIndex1/2), p read before order[i] = -1. Left: loop-1 colouring (i a0 vs retail t0, -1 t0 vs a3) tied to the camera-position copy (const& form colours right but drops the stack copy, 255 instrs)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (logic unchanged from the b2l archive)

// CB3RacePosition::Draw(int) -- hand-written from the retail asm (the lifter refused it: else-branch shape,
// vaddy.y). Control flow cross-checked against Burnout 2's CRacePosition (github.com/b3dllc/burnout2 @
// 61e466e295e34abf3de7816c220e4b09ba95022d, src/gamesource/Race/CRacePosition.cpp): Burnout 2's Update computes each car's
// distance from the camera and ranks them (closest last, ties broken by index) -- Burnout 3 does that ranking here, per
// draw, then draws a marker for every other car in rank order. No Burnout 2 name is used for any Burnout 3 symbol
// (provenance rule). Types and field meanings are [G] (instruction widths).
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

class CB3Score {
public:
    bool IsAheadOf(CB3Score *);
    short field_0;
    unsigned char pad_2[0x6];
};
class CB3RaceCar {
public:
    unsigned char pad_0[0x10C0];
    CB3Score field_10C0;
    int field_10C8;
    unsigned char pad_10CC[0x94];
    unsigned char field_1160;
    unsigned char pad_1161[0x789];
    unsigned char field_18EA;
    unsigned char pad_18EB[0xC1];
    signed char field_19AC;
    unsigned char pad_19AD[0xE23];
};
struct UnkStruct_00154350_bb { unsigned char pad_0[0xE80]; CGtV3d field_E80; };
struct UnkStruct_00154350_att { unsigned char pad_0[0x40]; UnkStruct_00154350_bb * field_40; };
struct UnkStruct_00154350_phys {
    unsigned char pad_0[0x204];
    CGtMatrix3x4 * field_204;
    unsigned char pad_208[0xAB8];
    UnkStruct_00154350_att * field_CC0;
};
struct UnkStruct_00154350_ent { UnkStruct_00154350_phys * field_0; unsigned char pad_4[0x2C]; };
struct UnkStruct_D_00522660_rp {
    unsigned char pad_0[0x3C98C];
    UnkStruct_00154350_ent field_3C98C[4];
    unsigned char pad_3CA4C[0xEE2DC];
    CB3RaceCar * field_12AD28[4];
    unsigned char pad_12AD38[0x18];
    CB3RaceCar field_12AD50[2];
};
struct UnkStruct_00154350_cam { unsigned char pad_0[0x20]; CGtV3d field_20; };
struct UnkStruct_00154350_view { unsigned char pad_0[0x68]; UnkStruct_00154350_cam * field_68; };
struct UnkStruct_00154350_net {
    virtual void vfunc_8(); virtual void vfunc_C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18();
    virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24(); virtual void vfunc_28(); virtual void vfunc_2C();
    virtual void vfunc_30(); virtual void vfunc_34(); virtual void vfunc_38(); virtual void vfunc_3C(); virtual void vfunc_40();
    virtual void vfunc_44(); virtual void vfunc_48(); virtual void vfunc_4C(); virtual void vfunc_50(); virtual void vfunc_54();
    virtual void vfunc_58(); virtual void vfunc_5C(); virtual void vfunc_60(); virtual void vfunc_64(); virtual void vfunc_68();
    virtual void vfunc_6C(); virtual void vfunc_70(); virtual void vfunc_74(); virtual void vfunc_78(); virtual void vfunc_7C();
    virtual void vfunc_80(); virtual void vfunc_84(); virtual void vfunc_88(); virtual void vfunc_8C(); virtual void vfunc_90();
    virtual void vfunc_94(); virtual void vfunc_98(); virtual void vfunc_9C(); virtual void vfunc_A0(); virtual void vfunc_A4();
    virtual void vfunc_A8(); virtual void vfunc_AC(); virtual void vfunc_B0(); virtual void vfunc_B4(); virtual bool vfunc_B8();
};
struct UnkStruct_00154350_game { unsigned char pad_0[0x1B4]; UnkStruct_00154350_net * field_1B4; };
struct UnkStruct_D_0051BA88 { UnkStruct_00154350_game * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_0051A9E0 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_0051BA44 { unsigned char pad_0[0x10]; };

class CB3RacePosition {
public:
    void Draw(int);
    void DrawPositionMarker(CGtV3d, const unsigned short *, int, CB3RaceCar *, CB3RaceCar *, float, bool, bool, bool, float);
    unsigned char pad_0[0x20];
    int field_20;
};

extern UnkStruct_D_00522660_rp D_00522660;
extern UnkStruct_D_0051BA88 D_0051BA88;
extern UnkStruct_D_0051A9E0 D_0051A9E0;
extern UnkStruct_D_0051BA44 D_0051BA44;
struct UnkStruct_D_00666270 { UnkStruct_00154350_view * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_0064D37C { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_00666270 D_00666270;
extern UnkStruct_D_0064D37C D_0064D37C;
extern CB3RaceCar * D_0064D388[];
extern "C" void Begin__12Gt2dRendererFv();
extern "C" void func_00217E70(int);
extern "C" void End__12Gt2dRendererFv();
extern "C" void SetTextureFilterMode__12Gt2dRendererFQ212Gt2dRenderer19EGt2dRendererFilter(int);
extern "C" void EnableZTest__12Gt2dRendererFb(bool);
extern "C" const unsigned short * func_00271A00(void *, int);
// [G] link-name call: retail passes the marker position by address (no caller copy) and leaves the third bool unset (no
// stack store; DrawPositionMarker never reads it), so the call goes through the mangled name with the eight register
// arguments retail sets.
extern "C" void DrawPositionMarker__15CB3RacePositionFQ29GtMathPs26CGtV3dPCUsiP10CB3RaceCarP10CB3RaceCarfbbbf(CB3RacePosition *, const CGtV3d &, const unsigned short *, int, CB3RaceCar *, CB3RaceCar *, float, bool, bool, float);
// [G] N140 frame pad: retail's frame keeps one more unused 16-byte slot below the marker position.
struct UnkStruct_00154350_pad { int x[4]; UnkStruct_00154350_pad() {} ~UnkStruct_00154350_pad() {} };

// 0x00154350
void CB3RacePosition::Draw(int cam)
{
    bool began = false;
    if (field_20 == 0) {
        return;
    }
    if ((void *)D_0051BA88.field_0 == (void *)&D_0051A9E0) {
        return;
    }
    CB3RaceCar * player = &D_00522660.field_12AD50[cam];
    int me = player->field_19AC;
    if (player->field_18EA != 0) {
        return;
    }
    if (player->field_10C8 != 0) {
        return;
    }
    float dist[8];
    int order[8];
    CGtV3d c = D_00666270.field_0->field_68->field_20;
    int n = D_0064D37C.field_0;
    int pos;
    int i;
    int j;
    int r;
    for (i = 0; i < n; i++) {
        UnkStruct_00154350_phys * p = D_00522660.field_3C98C[i].field_0;
        order[i] = -1;
        if (p == 0) {
            dist[i] = 0.0f;
        } else {
            CGtV3d d = p->field_204->mPos;
            d -= c;
            dist[i] = d.GetLength();
        }
    }
    for (i = 0; i < n; i++) {
        float * pd = &dist[i];
        r = n - 1;
        for (j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            if (*pd > dist[j]) {
                r--;
            } else if (*pd == dist[j] && i < j) {
                r--;
            }
        }
        order[r] = i;
    }
    for (r = 0; r < n; r++) {
        i = order[r];
        if (i < 0) {
            continue;
        }
        if (i == me) {
            continue;
        }
        CB3RaceCar * car = D_00522660.field_12AD28[i];
        if (car->field_18EA != 0) {
            continue;
        }
        if (D_0051BA88.field_0 != 0 && D_0051BA88.field_0->field_1B4 != 0 && D_0051BA88.field_0->field_1B4->vfunc_B8()) {
            CB3RaceCar ** l = D_0064D388;
            pos = 0;
            for (j = 0; j < n; j++) {
                CB3RaceCar * o = l[j];
                if (o != car && o->field_10C0.IsAheadOf(&car->field_10C0) && o->field_1160 == 0) {
                    pos++;
                }
            }
        } else {
            pos = car->field_10C0.field_0 - 1;
        }
        if (pos < 0 || pos >= n) {
            continue;
        }
        UnkStruct_00154350_phys * p = D_00522660.field_3C98C[i].field_0;
        CGtV3d v = p->field_204->mPos;
        UnkStruct_00154350_pad q;
        v.SetY(v.Y() + p->field_CC0->field_40->field_E80.Y());
        if (!began) {
            began = true;
            Begin__12Gt2dRendererFv();
            func_00217E70(0);
            SetTextureFilterMode__12Gt2dRendererFQ212Gt2dRenderer19EGt2dRendererFilter(0);
            EnableZTest__12Gt2dRendererFb(true);
        }
        DrawPositionMarker__15CB3RacePositionFQ29GtMathPs26CGtV3dPCUsiP10CB3RaceCarP10CB3RaceCarfbbbf(this, v, func_00271A00(&D_0051BA44, pos + 0x7DE), r, car, player, 0.0f, false, false, 0.5f);
    }
    if (began) {
        End__12Gt2dRendererFv();
    }
}


