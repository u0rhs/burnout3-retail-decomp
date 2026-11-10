// NONMATCHING: Update__17CB3RaceCarPhysicsFf -- retail 491 / ours 470 instructions, 442 in changed runs
// fix3 (2026-11-01): car layout: field_27C8 pad 0x1000 long (read +0x37C8), field_178C read from +0xCC4+0x1770 instead of the car (+0x13F4)+0x178C, F0 zeroing lanes x/z not x/y; D_004E0E4C copied as float (0.35) | Before: audit1 (2026-11-01): func_001C6F90 call had its arguments in the wrong registers (pointer in a2, f12/f13 never set) [C] retail 0x1C4D94: a0 = this+0x1448, f12 = f13 = 0, a1 = a2 = 0 (prototype as GetDrivingControls' archive) | Before: son8: first archive. Complete control flow from asm+Ghidra: crashing (0x210!=0) branch vs normal branch, 2-substep mode (car+0x1914==0, or ==2 with the two D_0051B7xx objects) that saves/restores two 32-byte-per-wheel quads at +0x820/+0x830 -> +0x850/+0x860, hinged-part loop, UpdateAggressiveReaction, car-state mirror stores into +0xCC4, crash start (+0x19AC) and the 0x26-wheel-state realistic-MoI crash with StartInfo{1,0,0x26}. Left: frame 0x190 vs 0x150 (stack arrays/StartInfo order), 21 instrs fewer, F0/B0 zeroing lanes guessed (SetX/SetY)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] fix3: reviewed end to end against retail asm (every branch, store and call)




#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_001C4890_vt { unsigned char pad_0[0x2C]; void (*vfunc_2C)(void *); };
struct UnkStruct_001C4890_cu {
    unsigned char pad_0[0x178C]; int field_178C;   // fix3 [C] retail 0x1C4B24: lw 0x13F4(s2); lw 0x178C (the car, not +0xCC4)
    unsigned char pad_1790[0x15F]; unsigned char field_18EF;
    unsigned char pad_18F0[0x24]; int field_1914;
    unsigned char pad_1918[0x74]; unsigned char field_198C;
    unsigned char pad_198D[0xB]; unsigned char field_1998;
    unsigned char pad_1999[0x13]; signed char field_19AC;
    unsigned char pad_19AD[0xE1B]; unsigned char field_27C8;   // fix3 [C] retail 0x1C497C lbu 0x27C8 (pad was 0x1000 long)
};
struct UnkStruct_001C4890_cz { unsigned char pad_0[0x40]; };
struct UnkStruct_001C4890_cc { unsigned char pad_0[0x40]; struct UnkStruct_001C4890_cd *field_40; unsigned char pad_44[0x10]; float field_54; unsigned char field_58; };
struct UnkStruct_001C4890_cd { unsigned char pad_0[0xC]; signed char field_C; };
struct UnkStruct_001C4890_cm {
    unsigned char pad_0[0x4B2]; unsigned char field_4B2[1];
    unsigned char pad_4B3[0xB68]; unsigned char field_101B; unsigned char pad_101C[0xC]; int field_1028; int field_102C;
    unsigned char field_1030; unsigned char field_1031; unsigned char field_1032; unsigned char field_1033;
};
struct UnkStruct_001C4890_w { unsigned char pad_0[0x820]; };
struct UnkStruct_001C4890_ci { unsigned char field_0; unsigned char field_1; unsigned char pad_2[2]; int field_4; int field_8; int field_C; };
struct UnkStruct_001C4890_p {
    UnkStruct_001C4890_vt *field_0;
    unsigned char pad_4[0xAC];
    CGtV4d field_B0;
    unsigned char pad_C0[0x3C];
    float field_FC;
    unsigned char pad_100[0x104];
    unsigned char field_204_pad[1];
};

extern float D_00522680;
extern float D_004E0CC8, D_004E0C18, D_004E0E30, D_004E0790, D_004E09BC, D_004E0E14;
extern float D_004E0E4C;   // 0.35 (0x3EB33333), lwc1/swc1 in retail 0x1C4E50
extern int D_0051BA88;
extern unsigned char D_0051B714[], D_0051B788[];
extern unsigned char D_0055E948[];
extern unsigned char D_004EE040[];
extern int D_006485C8[];
extern "C" void CacheWorldTriangles__17CB3RaceCarPhysicsFi(void *, int);
extern "C" void ApplyDrivingForces__17CB3RaceCarPhysicsFf(void *, float);
extern "C" int DoDrivingWorldCollision__17CB3RaceCarPhysicsFv(void *);
extern "C" void CollideWheels__17CB3VehiclePhysicsFv(void *);
extern "C" void UpdateSuspension__17CB3VehiclePhysicsFf(void *, float);
extern "C" void Update__16CB3CollidingBodyFf(void *, float);
extern "C" void func_001C8290(void *, int);
extern "C" void UpdateHingedPart__17CB3VehiclePhysicsFif(void *, int, float);
extern "C" void UpdateAggressiveReaction__10CB3RaceCarFv(void *);
extern "C" void UpdateWheelStates__17CB3RaceCarPhysicsFv(void *);
extern "C" void StartRaceCarCrashing__22CB3CrashActionDirectorFP17CB3RaceCarPhysicsiP16CB3CollidingPairP17CB3CrashStartInfo(void *, void *, int, void *, void *);
extern "C" int func_00131E40(void *);
extern "C" void SetRealisticMomentsOfInertia__16CB3CollidingBodyFv(void *);
extern "C" void func_001CC520(float, void *, int, int);
extern "C" float func_001C6F90(void *, float, float, int, int);   // audit1: (trans, f12, f13, a1, a2) as GetDrivingControls' archive and retail 0x1C4D94
extern "C" void GetCrashingDrivingControls__19CB3PlayerCarPhysicsFv(void *);
extern "C" void Update__17CB3VehiclePhysicsFf(void *, float);

extern "C" void Update__17CB3RaceCarPhysicsFf(UnkStruct_001C4890_p *self, float p0)
{
    char *b = (char *)self;
    UnkStruct_001C4890_cu *car = *(UnkStruct_001C4890_cu **)(b + 0x13F4);
    UnkStruct_001C4890_cc *cc = *(UnkStruct_001C4890_cc **)(b + 0xCC0);
    UnkStruct_001C4890_cm *cm = *(UnkStruct_001C4890_cm **)(b + 0xCC4);
    if (car->field_1998 == 0) return;
    if (*(signed char *)(b + 0x210) == 0) {
        if (*(unsigned char *)(b + 0x153F) != 0) {
            if (D_004E0CC8 < D_00522680 - *(float *)(b + 0x1538))
                *(unsigned char *)(b + 0x153F) = 0;
            else
                *(unsigned char *)(b + 0x1353) |= 0x10;
        }
        CacheWorldTriangles__17CB3RaceCarPhysicsFi(self, 0);
        self->field_0->vfunc_2C(self);
        cc->field_58 = 0;
        if ((signed char)*(int *)(b + 0x210) == 0 && cm->field_101B == 0) {
            if (*(int *)(b + 0x14C8) != 0) {
                int m = car->field_1914;
                if (m == 1 || (m == 0 && car->field_27C8 != 0)) {
                    if (*(unsigned char *)(b + 0x1552) != 0) cc->field_58 |= 0x10;
                } else if (D_004E0C18 < *(float *)(b + 0x1420)) {
                    cc->field_58 |= 0x10;
                }
            }
            if (*(int *)(b + 0x14C8) == -1) cc->field_58 |= 0x80;
            cc->field_58 |= car->field_18EF;
        }
        bool sub = car->field_1914 == 0;
        if (car->field_1914 == 2) {
            int o = *(int *)(D_0051BA88 + 0x1B4);
            if (o != 0 && (o == (int)D_0051B714 || o == (int)D_0051B788)) sub = true;
        }
        float k = D_004E0C18;
        int n;
        u_long128 s60[6];
        u_long128 sc0[6];
        if (sub) {
            signed char cnt = *(signed char *)(b + 0x1169);
            n = 2;
            p0 = p0 * 0.5f;
            for (long i = 0; i < cnt; i++) {
                s60[i] = *(u_long128 *)(b + 0x820 + i * 0xC0);
                sc0[i] = *(u_long128 *)(b + 0x830 + i * 0xC0);
            }
        } else {
            n = 1;
        }
        for (; n > 0; n--) {
            ApplyDrivingForces__17CB3RaceCarPhysicsFf(self, p0);
            *(unsigned char *)(b + 0x212) = 0;
            *(unsigned char *)(b + 0x213) = 0;
            if (DoDrivingWorldCollision__17CB3RaceCarPhysicsFv(self) == 0) {
                if (*(int *)(b + 0x1524) == 3) *(int *)(b + 0x1524) = 0;
            } else {
                *(int *)(b + 0x1524) = 3;
                *(unsigned char *)(b + 0x212) = 1;
            }
            CollideWheels__17CB3VehiclePhysicsFv(self);
            UpdateSuspension__17CB3VehiclePhysicsFf(self, p0);
            if ((*(float *)(b + 0xBC) < 0.5f && *(float *)(b + 0x1400) <= k) || car->field_178C == 0 || car->field_178C == 2) {
                self->field_B0.Zero();
                CGtV4d *f0 = (CGtV4d *)(b + 0xF0);
                f0->SetX(0.0f);
                f0->SetZ(0.0f);   // fix3 [C] retail 0x1C4B5C/60: vaddx.x / vaddx.z
            }
            Update__16CB3CollidingBodyFf(self, p0);
        }
        if (sub) {
            for (long i = 0; i < *(signed char *)(b + 0x1169); i++) {
                *(u_long128 *)(b + 0x850 + i * 0xC0) = s60[i];
                *(u_long128 *)(b + 0x860 + i * 0xC0) = sc0[i];
            }
            p0 = p0 * 2.0f;
        }
        if (D_004E0E30 <= *(float *)(b + 0x152C)) *(float *)(b + 0x152C) = *(float *)(b + 0x152C) - p0;
        for (long i = 0; i < cc->field_40->field_C; i++) {
            if (cm->field_4B2[i] == 2) {
                func_001C8290(self, i);
                UpdateHingedPart__17CB3VehiclePhysicsFif(self, i, p0);
            }
        }
        UpdateAggressiveReaction__10CB3RaceCarFv(car);
        cc->field_54 = *(float *)(b + 0xBC);
        cm->field_1028 = *(int *)(b + 0x14C8);
        cm->field_102C = (int)(D_004E0790 * *(float *)(b + 0x149C));
        cm->field_1030 = (unsigned char)*(int *)(b + 0x1168);
        cm->field_1032 = (unsigned int)(*(int *)(b + 0x1524) - 1) < 2;
        cm->field_1031 = (unsigned char)*(int *)(b + 0x1444);
        cm->field_1033 = *(unsigned char *)(b + 0x1446);
        UpdateWheelStates__17CB3RaceCarPhysicsFv(self);
        if (*(float *)(*(char **)(b + 0x204) + 0x14) < 0.5f && *(signed char *)(b + 0x215) != 3) {
            StartRaceCarCrashing__22CB3CrashActionDirectorFP17CB3RaceCarPhysicsiP16CB3CollidingPairP17CB3CrashStartInfo(D_0055E948, self, car->field_19AC, 0, 0);
        }
        if (func_00131E40(D_004EE040) != 0 && *(signed char *)(b + 0x215) != 3) {
            if (*(signed char *)(b + 0x1540) == 0) {
                for (long i = 0; i < *(signed char *)(b + 0x1169); i++) {
                    if (*(signed char *)(b + 0x8D0 + i * 0xC0) == 0x26) {
                        *(unsigned char *)(b + 0x1540) = 1;
                        return;
                    }
                }
            } else {
                SetRealisticMomentsOfInertia__16CB3CollidingBodyFv(self);
                bool ok = true;
                for (long i = 0; i < *(signed char *)(b + 0x1169); i++) {
                    if (*(unsigned char *)(b + 0x8D3 + i * 0xC0) != 0) { ok = false; break; }
                }
                if (ok) {
                    UnkStruct_001C4890_ci info;
                    info.field_0 = 1;
                    info.field_1 = 0;
                    info.field_4 = 0x26;
                    info.field_8 = 0;
                    info.field_C = 0;
                    StartRaceCarCrashing__22CB3CrashActionDirectorFP17CB3RaceCarPhysicsiP16CB3CollidingPairP17CB3CrashStartInfo(D_0055E948, self, car->field_19AC, 0, &info);
                    int *mode = &D_006485C8[car->field_19AC];
                    if (*mode == 2) {
                        func_001CC520(D_004E09BC, self, 0x10, 1);
                        func_001CC520(D_004E0E14, self, 8, 1);
                    } else if (*mode == 3) {
                        func_001CC520(D_004E09BC, self, 0x10, 1);
                        func_001CC520(D_004E0E14, self, 4, 1);
                    }
                }
            }
        }
    } else {
        *(float *)(b + 0x1530) = *(float *)(b + 0x1530) + p0;
        float c = D_004E0E4C;
        if (*(int *)(b + 0x14C8) != 0) {
            *(int *)(b + 0x14C8) = 0;
            *(int *)(b + 0x14A4) = 1;
            *(float *)(b + 0x14A0) = c;
        }
        func_001C6F90(b + 0x1448, 0.0f, 0.0f, 0, 0);   // audit1 [C] retail 0x1C4D94..0x1C4DA4: a0 = this+0x1448, f12 = f13 = 0, a1 = a2 = 0
        if (car->field_1914 == 0) GetCrashingDrivingControls__19CB3PlayerCarPhysicsFv(self);
        Update__17CB3VehiclePhysicsFf(self, p0);
        cc->field_54 = *(float *)(b + 0xBC);
        cm->field_1028 = *(int *)(b + 0x14C8);
        cm->field_102C = (int)(D_004E0790 * *(float *)(b + 0x149C));
        cm->field_1030 = (unsigned char)*(int *)(b + 0x1168);
        cm->field_1032 = (unsigned int)(*(int *)(b + 0x1524) - 1) < 2;
        cm->field_1031 = (unsigned char)*(int *)(b + 0x1444);
        cm->field_1033 = *(unsigned char *)(b + 0x1446);
    }
}
