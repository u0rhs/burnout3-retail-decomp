// NONMATCHING: Update__14CB3CrashPickupFf -- retail 484 / ours 478 instructions, 402 in changed runs
// psweep: scoped #pragma inline_depth(3) [G] improves 440 -> 426
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"
// [G] N182: scoped optimiser pragma found by the pragma sweep (psweep_all.py)
#pragma push
#pragma inline_depth(3)
using namespace GtMathPs2;

struct UnkStruct_003A1010_cmb { unsigned char pad_0[0x1338]; void *field_1338; };
struct UnkStruct_003A1010_t { unsigned char pad_0[0x10]; unsigned char field_10; };
struct UnkStruct_003A1010_p { UnkStruct_003A1010_t *field_0; float field_4; unsigned char field_8; unsigned char field_9; signed char field_A; };
struct UnkStruct_003A1010_sc { unsigned char pad_0[0x13F4]; };
struct UnkStruct_003A1010_cr {
    unsigned char pad_0[0x1D0];
    u_long128 field_1D0;
    u_long128 field_1E0;
    unsigned char pad_1F0[0x14];
    CGtMatrix3x4 *field_204;
};
struct UnkStruct_003A1010_car {
    unsigned char pad_0[0x1D0];
    u_long128 field_1D0;
    u_long128 field_1E0;
    unsigned char pad_1F0[0x14];
    CGtMatrix3x4 *field_204;
    unsigned char pad_208[0xD];
    signed char field_215;
    unsigned char pad_216[0x11DE];
    UnkStruct_003A1010_cmb *field_13F4;
};
struct UnkStruct_003A1010_g { unsigned char pad_0[0x12AD28]; void *field_12AD28[1]; };
struct UnkStruct_003A1010_cnt { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_003A1010_pl { unsigned char pad_0[0x30]; };
struct UnkStruct_003A1010_16 { unsigned char pad_0[0x10]; };
struct UnkStruct_003A1010_vt { unsigned char pad_0[0x10]; void (*vfunc_10)(void *, int, int); unsigned char pad_14[0x14]; void (*vfunc_28)(void *, int); unsigned char pad_2C[0x78]; unsigned char (*vfunc_A4)(void *); unsigned char (*vfunc_A8)(void *); };
struct UnkStruct_003A1010_o { UnkStruct_003A1010_vt *field_0; };
struct UnkStruct_003A1010_bb { unsigned char pad_0[0x1B4]; UnkStruct_003A1010_o *field_1B4; };
struct UnkStruct_003A1010_ent { unsigned char pad_0[0x4F0A]; unsigned char field_4F0A; unsigned char field_4F0B; unsigned char pad_4F0C[4]; int field_4F10; };
struct UnkStruct_003A1010_k { unsigned char pad_0[0x118C]; };
extern UnkStruct_003A1010_g D_00522660;
extern UnkStruct_003A1010_cnt D_0064D37C;
extern UnkStruct_003A1010_cnt D_01E32B08;
extern UnkStruct_003A1010_16 D_01E7A800;
extern UnkStruct_003A1010_16 D_004EE040;
extern UnkStruct_003A1010_16 D_0064CE40;
extern UnkStruct_003A1010_16 D_0055E948;
extern UnkStruct_003A1010_16 D_01E32AE0;
extern unsigned char D_01E65499;
extern unsigned char D_0064D33B;
extern float D_00522680;
extern UnkStruct_003A1010_bb *D_0051BA88;
extern float D_004E117C;
extern float D_004E1280;
extern "C" int IntersectSphere__14GtIntersectionFQ29GtMathPs29CGtSphereRC17CGtAxisAlignedBox(CGtSphere, const void *);
extern "C" int func_00131CA0(void *);
extern "C" void AddPickupToCombo__13CB3CrashComboFv(void *);
extern "C" void SetInfiniteBoost__7CB3BurnFb(void *, int);
extern "C" int OnEvent__13CB3ScoreBonusF16EScoreBonusEventiib(void *, int, int, int, int);
extern "C" void AddCrashScore__13CB3CrashScoreF20ECrashModePickupTypei(void *, int, int);
extern "C" void AddCrashMultiplier__13CB3CrashScoreF20ECrashModePickupTypei(void *, int, int);
extern "C" void func_00284BD0(void *);
extern "C" void func_00284B60(void *);
extern "C" void func_00284B20(void *);
extern "C" void func_00284C40(void *);
extern "C" void CrashModeMultiplier__18CB3HUDSoundManagerFv(void *);
extern "C" UnkStruct_003A1010_ent *func_002366D0(void *, int);
extern "C" void StartRaceCarCrashing__22CB3CrashActionDirectorFP17CB3RaceCarPhysicsiP16CB3CollidingPairP17CB3CrashStartInfo(void *, void *, int, void *, void *);


static inline void func_003A1010_infl(int, int) {}
extern "C" void Update__14CB3CrashPickupFf(UnkStruct_003A1010_p *self, float p0)
{
    float kA = D_004E117C;
    float kB = D_004E1280;
    for (int i = 0; i < D_0064D37C.field_0; i++) {
        UnkStruct_003A1010_car *car = *(UnkStruct_003A1010_car **)((char *)&D_00522660 + i * 0x30 + 0x40000 - 0x3674);
        if (self->field_8 != 0) {
            UnkStruct_003A1010_car *c4 = (UnkStruct_003A1010_car *)D_00522660.field_12AD28[i];
            if (*(int *)((char *)c4 + 0x1914) == 0 && i == self->field_A && self->field_0->field_10 == 0) {
                if (p0 - self->field_4 < 30.0f) *((unsigned char *)car + 0x4584) = 1;
                else *((unsigned char *)car + 0x4584) = 0;
            }
            continue;
        }
        CGtV3d d = car->field_204->mPos - *(CGtV3d *)self->field_0;
        if (!(d.GetLength() < 15.0f)) continue;
        u_long128 box0 = car->field_1D0;
        u_long128 box1 = car->field_1E0;
        CGtMatrix3x4 *m = car->field_204;
        CGtMatrix3x4 inv;
        float *r = (float *)m;
        float *o = (float *)&inv;
        o[0] = r[0]; o[1] = r[4]; o[2] = r[8];
        o[4] = r[1]; o[5] = r[5]; o[6] = r[9];
        o[8] = r[2]; o[9] = r[6]; o[10] = r[10];
        inv.mPos = -(TransformVector(inv, m->mPos));
        CGtSphere s;
        CGtV3d c = TransformPoint(inv, *(CGtV3d *)self->field_0);
        s.SetPosition(c);
        if (self->field_0->field_10 == 4) s.SetRadius(kA);
        else if (func_00131CA0(&D_004EE040) == 0 && D_01E65499 == 0) s.SetRadius(2.5f);
        else s.SetRadius(kB);
        if (IntersectSphere__14GtIntersectionFQ29GtMathPs29CGtSphereRC17CGtAxisAlignedBox(s, &box0) == 0) continue;
        UnkStruct_003A1010_o *bo = D_0051BA88->field_1B4;
        unsigned char f8 = bo->field_0->vfunc_A8(bo);
        unsigned char f4 = bo->field_0->vfunc_A4(bo);
        self->field_8 = 1;
        self->field_9 = 1;
        self->field_A = i;
        if (car->field_13F4->field_1338 != 0) AddPickupToCombo__13CB3CrashComboFv(car->field_13F4->field_1338);
        self->field_4 = p0;
        char *sc = (char *)car->field_13F4;
        switch (self->field_0->field_10) {
        case 0:
            SetInfiniteBoost__7CB3BurnFb(sc + 0x118C, 1);
            OnEvent__13CB3ScoreBonusF16EScoreBonusEventiib(sc + 0x11E4, 0xC8, 0, -1, 1);
            break;
        case 1:
            AddCrashScore__13CB3CrashScoreF20ECrashModePickupTypei(&D_0064CE40, 1, i);
            OnEvent__13CB3ScoreBonusF16EScoreBonusEventiib(sc + 0x11E4, 0xC9, 0, -1, 1);
            func_00284BD0(&D_01E7A800);
            break;
        case 2:
            AddCrashScore__13CB3CrashScoreF20ECrashModePickupTypei(&D_0064CE40, 2, i);
            OnEvent__13CB3ScoreBonusF16EScoreBonusEventiib(sc + 0x11E4, 0xCA, 0, -1, 1);
            func_00284BD0(&D_01E7A800);
            break;
        case 3:
            AddCrashScore__13CB3CrashScoreF20ECrashModePickupTypei(&D_0064CE40, 3, i);
            OnEvent__13CB3ScoreBonusF16EScoreBonusEventiib(sc + 0x11E4, 0xCB, 0, -1, 1);
            func_00284BD0(&D_01E7A800);
            break;
        case 4:
            AddCrashMultiplier__13CB3CrashScoreF20ECrashModePickupTypei(&D_0064CE40, 4, i);
            OnEvent__13CB3ScoreBonusF16EScoreBonusEventiib(sc + 0x11E4, 0xCC, 0, -1, 1);
            if (f4 != 0) {
                int j = (i == 0);
                UnkStruct_003A1010_car *c2 = *(UnkStruct_003A1010_car **)((char *)&D_00522660 + j * 0x30 + 0x40000 - 0x3674);
                AddCrashMultiplier__13CB3CrashScoreF20ECrashModePickupTypei(&D_0064CE40, 4, j);
                OnEvent__13CB3ScoreBonusF16EScoreBonusEventiib((char *)c2->field_13F4 + 0x11E4, 0xCC, 0, -1, 1);
            }
            func_00284B60(&D_01E7A800);
            break;
        case 5:
            AddCrashMultiplier__13CB3CrashScoreF20ECrashModePickupTypei(&D_0064CE40, 5, i);
            OnEvent__13CB3ScoreBonusF16EScoreBonusEventiib(sc + 0x11E4, 0xCD, 0, -1, 1);
            CrashModeMultiplier__18CB3HUDSoundManagerFv(&D_01E7A800);
            break;
        case 6:
            AddCrashMultiplier__13CB3CrashScoreF20ECrashModePickupTypei(&D_0064CE40, 6, i);
            OnEvent__13CB3ScoreBonusF16EScoreBonusEventiib(sc + 0x11E4, 0xCE, 0, -1, 1);
            CrashModeMultiplier__18CB3HUDSoundManagerFv(&D_01E7A800);
            break;
        case 7: {
            int w = i;
            if (*(int *)((char *)D_00522660.field_12AD28[w] + 0x1914) == 0) {
                if (f8 != 0) {
                    w = (i == 0);
                    for (int k = 0; k < D_01E32B08.field_0; k++) {
                        UnkStruct_003A1010_ent *e = func_002366D0(&D_01E32AE0, k);
                        if (e != 0) { e->field_4F10 = 5; e->field_4F0A = 1; }
                    }
                }
                if (*(int *)((char *)D_00522660.field_12AD28[w] + 0x1914) == 0) {
                    UnkStruct_003A1010_o *pc = *(UnkStruct_003A1010_o **)((char *)&D_00522660 + w * 0x30 + 0x40000 - 0x3674);
                    StartRaceCarCrashing__22CB3CrashActionDirectorFP17CB3RaceCarPhysicsiP16CB3CollidingPairP17CB3CrashStartInfo(&D_0055E948, pc, w, (void *)(0), (void *)(0));
                    pc->field_0->vfunc_10(pc, w, 0);
                    pc->field_0->vfunc_28(pc, 1);
                    *(float *)((char *)pc + 0x3534) = D_00522680;
                }
            }
            func_00284B20(&D_01E7A800);
            break;
        }
        case 8:
            if (car->field_215 == 3) return;
            D_0064D33B = 1;
            if (D_01E65499 != 0) {
                OnEvent__13CB3ScoreBonusF16EScoreBonusEventiib(sc + 0x11E4, 0xD0, 0, -1, 1);
                func_00284C40(&D_01E7A800);
                for (int k = 0; k < D_01E32B08.field_0; k++) {
                    UnkStruct_003A1010_ent *e = func_002366D0(&D_01E32AE0, k);
                    if (e != 0) { e->field_4F10 = 5; e->field_4F0B = 1; }
                }
            }
            break;
        }
    }
}

#pragma pop
