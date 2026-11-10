// NONMATCHING: func_00330370 -- retail 1517 / ours 1521 instructions, 1643 in changed runs
// draftAE C-first ([L] CB3AIAggressionBehaviour::Update): 1521/1517, call multiset identical (5x UpdateTargetData, 7x CanBlock, 15 GetTotalRaceDist ...), order differs by block layout; op counts agree except GtMath::Sign's stack-word round trip (retail sw/lw of the qmfc2 result, ours dsll32/dsra32 x3), header operator+ vmoves (3), two sqc2 temporaries (the side offset and UpdateBlock's first field_10 store). Left: jump-table case layout, frame 0x300 vs 0x3D0
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm with Ghidra as reading aid; every case of the 8-state FSM, call, store and constant accounted for; inlined map members SetState/UpdateTargetData/CanBlock/IsSafeToAttack/UpdateBlock as class inlines (bodies from the archived StopAttacking/ClearState/UpdateSlam); header DotProduct/Sign/NormaliseGetLength/operator*,+,-

// func_00330370 -- draftAE (0x330370, 0x17B4) -- [L] CB3AIAggressionBehaviour::Update() (research/retail_names.csv, low:
// direct order+sim; the E map's Update() 0x854 sits between Prepare and Release as here). Kept under its asm label.
// Written from the retail asm with the Ghidra draft as reading aid. Revenge's Update (B4AIAggressionBehaviour.cpp, 0x6CC) was
// reworked, so only its lbStateFinished-style flags guided the names [G].
// Inlined members, names [C] B3O0PCH map, bodies [L]/[G] from retail (and the archived StopAttacking / ClearState / UpdateSlam):
//   SetState(EAIAggressionState, float)  0xBC: state, start time, end time (-1 = none)
//   UpdateTargetData()                    0xE0: separations, CanSlam, CanBlock, CanStickySpeedMatch
//   CanBlock()                            0x1E4: target within 20 mph and inside the along-track window, lane segment unclaimed
//   IsSafeToAttack()                      0x124: func_001419B0, not slammed within 2 s, lane segment free or field_1C02 clear
//   UpdateBlock()                         0x260 [G]: CanBlock, then the block point beside the target
// Placeholders: func_00330370_inl1 (look for a player car to attack: field_1640 index into D_0064D388), _inl2 (the side-swipe
// point beside our car with field_34's sign).
// Types and field meanings [G] (instruction widths, use).
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

class CB3RaceCar;
class CB3Score {
public:
    float GetTotalRaceDistFromAILaneStart();
    int WasSlammedWithinTime(float);
    unsigned char pad_0[0xC];
    float field_C;                  // [G] race distance
};
class CB3AICar {
public:
    float CalcSeparationAcrossTrack(CB3RaceCar *);
    float CalcSeparationAlongTrack(CB3RaceCar *);
};
struct UnkStruct_00330370_seg { unsigned char pad_0[2]; unsigned char field_2; unsigned char pad_3[7]; };
struct UnkStruct_00330370_l2 { unsigned char pad_0[8]; UnkStruct_00330370_seg * field_8; };
struct UnkStruct_00330370_l1 { unsigned char pad_0[4]; UnkStruct_00330370_l2 * field_4; };
// [G] the physics body (D_0055EFEC entries, car field_2430): velocity with w = speed
struct UnkStruct_00330370_body { unsigned char pad_0[0xB0]; CGtV4d field_B0; unsigned char pad_C0[0x147D]; unsigned char field_153D; };
struct UnkStruct_00330370_car {
    CGtV3d field_0;                 // [G] world matrix rows: right
    unsigned char pad_10[0x10];
    CGtV3d field_20;                // [G] at
    CGtV3d field_30;                // [G] position
    unsigned char pad_40[0x1080];
    CB3Score field_10C0;
    unsigned char pad_10D0[0x26C];
    int field_133C;                 // [G] car state (0 inactive)
    unsigned char pad_1340[0x290];
    float field_15D0[8];            // [G] per player
    unsigned char pad_15F0[0x50];
    int field_1640;                 // [G] player car index, -1 none
    unsigned char pad_1644[0x270];
    UnkStruct_00330370_l1 * field_18B4;
    unsigned short field_18B8;
    unsigned char pad_18BA[0x30];
    unsigned char field_18EA;
    unsigned char pad_18EB[0x29];
    int field_1914;
    unsigned char pad_1918[0x94];
    signed char field_19AC;
    unsigned char pad_19AD[0x234];
    unsigned char field_1BE1;
    unsigned char pad_1BE2[0x20];
    unsigned char field_1C02;
    unsigned char pad_1C03[0x7CD];
    float field_23D0;
    unsigned char pad_23D4[0x5C];
    UnkStruct_00330370_body * field_2430;
    unsigned char pad_2434[0x4];
    float field_2438;
    unsigned char pad_243C[0x4];
    void * field_2440;
};
struct UnkStruct_00330370_ent { UnkStruct_00330370_body * field_0; unsigned char pad_4[0x2C]; };
extern UnkStruct_00330370_ent D_0055EFEC[];
struct UnkStruct_00330370_f { float field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_00330370_f D_00522680;     // [G] game time
extern UnkStruct_00330370_f D_01E755CC, D_01E755D0, D_01E755D4, D_01E755D8, D_01E755E0, D_01E755EC, D_01E755F0, D_01E755F4;   // [G] tuning
extern UnkStruct_00330370_car * D_0064D388[];  // [G] player car per index
struct UnkStruct_D_0064D3A0 { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_0064D3A0 D_0064D3A0;       // [G] player count
struct UnkStruct_00330370_pl { signed char field_0; unsigned char pad_1[0x27CF]; };
struct UnkStruct_D_00522660 { unsigned char pad_0[0x12C6FC]; UnkStruct_00330370_pl field_12C6FC[8]; };   // [G] per-player records
extern UnkStruct_D_00522660 D_00522660;
extern "C" int func_001419B0(void *);
// [G] a + (b - a) t with retail's `0 +` (adda.s from $zero, then madd.s) at both sites
static inline float func_00330370_inl3(float a, float b, float t) { return 0.0f + a + t * (b - a); }

enum EAIAggressionState {};   // [C] name: B3O0PCH map (SetState's parameter); values 0..7 below [G]

class CB3AIAggressionBehaviour {
public:
    void Update();
    void UpdateAggressiveHornBlast();
    void StopAttacking(bool, bool);
    bool CanSlam();
    bool CanStickySpeedMatch() const;
    bool FindTarget();
    bool MoveToTarget();
    void UpdateSlam();

    void SetState(EAIAggressionState s, float d) {
        field_0 = s;
        field_30 = D_00522680.field_0;
        if (-1.0f == d)
            field_2C = -1.0f;
        else
            field_2C = field_30 + d;
    }
    bool CanBlock() {
        UnkStruct_00330370_car * tg = field_48;
        if (tg == 0)
            return false;
        if (GtMath::Abs(2.236936331f * (float)D_0055EFEC[tg->field_19AC].field_0->field_B0.W()  // [C] retail FPU form, not a VU lane op: mula.s/msub.s (0x3304CC..), 0x3314BC mul.s (the cast keeps the port's PS2 float model)
                        - 2.236936331f * (float)D_0055EFEC[field_44->field_19AC].field_0->field_B0.W()) <= 20.0f) {  // [C] retail FPU form, not a VU lane op: mula.s/msub.s (0x3304CC..), 0x3314BC mul.s (the cast keeps the port's PS2 float model)
            float d = tg->field_10C0.GetTotalRaceDistFromAILaneStart();
            float e = -(d - field_44->field_10C0.GetTotalRaceDistFromAILaneStart());
            float h = field_44->field_2438;
            if (e < 9.999999747e-05f + h || !(e <= h + D_01E755D8.field_0))
                return false;
            if (field_44->field_18B4->field_4->field_8[field_44->field_18B8].field_2 != 0xFF)
                return false;
            return true;
        }
        return false;
    }
    void UpdateTargetData() {
        if (field_48 != 0) {
            field_38 = ((CB3AICar *)field_44)->CalcSeparationAcrossTrack((CB3RaceCar *)field_48);
            field_3C = ((CB3AICar *)field_44)->CalcSeparationAlongTrack((CB3RaceCar *)field_48);
            field_40 = CanSlam();
            field_41 = CanBlock();
            field_42 = CanStickySpeedMatch();
        } else {
            field_38 = 0;
            field_3C = 0;
            field_40 = 0;
            field_41 = 0;
            field_42 = 0;
        }
    }
    bool IsSafeToAttack() {
        if (func_001419B0(field_44) == 0) return false;
        if (field_44->field_10C0.WasSlammedWithinTime(2.0f)) return false;
        UnkStruct_00330370_car * car = field_44;
        if (car->field_18B4->field_4->field_8[car->field_18B8].field_2 == 0xFF) return true;
        if (car->field_1C02 != 0) return false;
        return true;
    }
    bool UpdateBlock() {
        if (!CanBlock())
            return false;
        UnkStruct_00330370_car * me = field_44;
        CGtV3d d = me->field_30 - field_48->field_30;
        d.NormaliseGetLength();
        float td = field_48->field_10C0.GetTotalRaceDistFromAILaneStart();
        float md = me->field_10C0.GetTotalRaceDistFromAILaneStart();
        float s = GtMath::Sign(DotProduct(d, me->field_0));
        float k = func_00330370_inl3(15.0f, 30.0f, -(td - md) / (me->field_2438 + D_01E755D8.field_0));
        field_10 = field_48->field_30 + field_48->field_20 * k;
        float one = 1.0f;
        field_10 = field_10 + field_48->field_0 * (-s * one);
        field_20 = IsSafeToAttack();
        return true;
    }

    int field_0;                    // [G] EAIAggressionState
    unsigned char pad_4[0xC];
    CGtV3d field_10;                // [G] the point to steer for
    unsigned char field_20;         // [G] safe to attack
    unsigned char field_21;
    unsigned char field_22;
    unsigned char field_23;
    unsigned char field_24;
    unsigned char pad_25[0x7];
    float field_2C;                 // [G] state end time (-1 none)
    float field_30;                 // [G] state start time
    float field_34;                 // [G] side (+-1)
    float field_38;                 // [G] separation across the track
    float field_3C;                 // [G] separation along the track
    unsigned char field_40;         // [G] can slam
    unsigned char field_41;         // [G] can block
    unsigned char field_42;         // [G] can sticky speed match
    unsigned char pad_43;
    UnkStruct_00330370_car * field_44;   // [G] our AI car
    UnkStruct_00330370_car * field_48;   // [G] the target
};

// [G] look for a player car to attack (the AI car's field_1640 index); on success it becomes the target and the slam (4) or
// approach (3) state starts by the separation across the track
static inline bool func_00330370_inl1(CB3AIAggressionBehaviour * b)
{
    UnkStruct_00330370_car * me = b->field_44;
    if (me->field_2440 == 0) {
        int i = me->field_1640;
        if (i != -1) {
            UnkStruct_00330370_car * p = D_0064D388[i];
            if (p != 0 && p->field_1914 == 1) {
                b->field_48 = p;
                b->UpdateTargetData();
                b->field_40 = 1;
                float f4 = D_01E755F4.field_0;
                float f0 = D_01E755F0.field_0;
                if (b->field_38 > 1.0f)
                    b->SetState((EAIAggressionState)4, f4);
                else
                    b->SetState((EAIAggressionState)3, f0);
                return true;
            }
        }
    }
    return false;
}

// [G] the side-swipe point: ahead of our car by its speed, offset sideways by `side` (+-1)
static inline void func_00330370_inl2(CB3AIAggressionBehaviour * b, float side)
{
    UnkStruct_00330370_car * me = b->field_44;
    CGtV3d o = me->field_0 * D_01E755EC.field_0 * side;
    b->field_10 = me->field_30 + me->field_20 * (0.15f * (float)me->field_2430->field_B0.W()) + o;  // [C] retail FPU form, not a VU lane op: mula.s/msub.s (0x3304CC..), 0x3314BC mul.s (the cast keeps the port's PS2 float model)
}

extern "C" void func_00330370(CB3AIAggressionBehaviour * self)
{
    bool lbIdle = true;
    UnkStruct_00330370_car * me = self->field_44;
    if (!((me->field_1914 != 0 || me->field_133C == 3) && me->field_133C != 0)) {
        self->field_20 = 0;
        self->field_24 = 0;
        return;
    }
    self->UpdateAggressiveHornBlast();
    bool lbStateFinished = false;
    if (self->field_2C != -1.0f && !(D_00522680.field_0 < self->field_2C)) {
        lbStateFinished = true;
    }
    if (self->field_48 != 0 && self->field_48->field_18EA != 0) {
        self->StopAttacking(false, true);
    }
    self->UpdateTargetData();

    switch (self->field_0) {
    case 0:
        self->field_20 = 0;
        lbIdle = false;
        if (self->FindTarget()) {
            self->field_21 = 1;
            self->SetState((EAIAggressionState)1, D_01E755E0.field_0);
        }
        break;
    case 1:
        if (!func_00330370_inl1(self)) {
            self->field_22 = self->field_42;
            float f4 = D_01E755F4.field_0;
            float f0 = D_01E755F0.field_0;
            lbIdle = false;
            if (!self->field_40) {
                if (self->MoveToTarget()) {
                    if (self->CanBlock()) {
                        float t = self->field_44->field_23D0;
                        self->SetState((EAIAggressionState)7, func_00330370_inl3(D_01E755D0.field_0, D_01E755D4.field_0, t));
                    }
                }
            } else if (self->field_38 > 2.5f) {
                self->SetState((EAIAggressionState)4, f4);
            } else {
                self->SetState((EAIAggressionState)3, f0);
            }
        }
        break;
    case 2:
        if (!func_00330370_inl1(self)) {
            lbIdle = false;
            self->field_22 = self->field_42;
            float f4 = D_01E755F4.field_0;
            float f0 = D_01E755F0.field_0;
            if (lbStateFinished || self->field_40) {
                if (!self->field_40)
                    self->StopAttacking(false, false);
                else if (self->field_38 > 2.5f)
                    self->SetState((EAIAggressionState)4, f4);
                else
                    self->SetState((EAIAggressionState)3, f0);
            } else {
                self->MoveToTarget();
            }
        }
        break;
    case 3:
        lbIdle = false;
        self->field_22 = self->field_42;
        if (lbStateFinished) {
            D_0055EFEC[self->field_48->field_19AC].field_0->field_153D = 0;
            self->SetState((EAIAggressionState)4, D_01E755F4.field_0);
        } else {
            UnkStruct_00330370_car * c = self->field_44;
            self->field_34 = GtMath::Sign(DotProduct(c->field_30 - self->field_48->field_30, c->field_0));
            func_00330370_inl2(self, self->field_34);
            self->field_20 = self->IsSafeToAttack();
        }
        break;
    case 4:
        lbIdle = false;
        self->field_22 = 1;
        self->field_44->field_1BE1 = 1;
        if (lbStateFinished)
            self->StopAttacking(false, false);
        else
            self->UpdateSlam();
        break;
    case 5:
        lbIdle = false;
        if (lbStateFinished) {
            self->SetState((EAIAggressionState)0, -1.0f);
            self->field_20 = 0;
            self->field_21 = 0;
            self->field_22 = 0;
            self->field_44->field_1BE1 = 0;
            self->field_48 = 0;
            self->UpdateTargetData();
        }
        break;
    case 6:
        self->field_22 = 0;
        lbIdle = false;
        if (lbStateFinished) {
            self->StopAttacking(false, false);
        } else {
            func_00330370_inl2(self, GtMath::Sign(-self->field_34));
            self->field_20 = self->IsSafeToAttack();
        }
        break;
    case 7:
        self->field_22 = 0;
        self->field_21 = 1;
        if (!func_00330370_inl1(self)) {
            if (!lbStateFinished && self->UpdateBlock()) {
                float f4 = D_01E755F4.field_0;
                float f0 = D_01E755F0.field_0;
                if (self->field_40) {
                    if (self->field_38 > 1.0f)
                        self->SetState((EAIAggressionState)4, f4);
                    else
                        self->SetState((EAIAggressionState)3, f0);
                }
                break;
            }
            self->SetState((EAIAggressionState)1, D_01E755E0.field_0);
        }
        break;
    }

    if (lbIdle) {
        self->field_23 = 1;
    } else {
        bool lbNear = false;
        for (int i = 0; i < D_0064D3A0.field_0; i++) {
            if (self->field_44->field_10C0.field_C < self->field_44->field_15D0[D_00522660.field_12C6FC[i].field_0] + D_01E755CC.field_0)
                lbNear = true;
        }
        if (lbNear)
            self->field_23 = 1;
        else
            self->field_23 = 0;
    }
    self->field_24 = 0;
}
