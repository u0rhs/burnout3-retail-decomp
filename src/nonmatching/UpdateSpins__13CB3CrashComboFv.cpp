// NONMATCHING: UpdateSpins__13CB3CrashComboFv -- retail 776 / ours 771 instructions, 307 in changed runs
// draftAK C-first: local angular velocity (TransformVector(inverse matrix, angular velocity)), per-axis sign-flip/reset flags (GtMath::Sign), half-turn integration by pi with spin counters, finished spins -> combo events 6/7 (X), 9/8/0xD (Y, AngleBetweenVectors(mUp, kYAxis) with retail's double <=50 / <=130 test), 5/4/3 (Z), the UpdateSkids event append inlined; 771/776, calls identical (acosf = func_0011E328); left: the reset-flag chain shape, TransformVector row loads (lq+qmtc2 in retail), frame 0x270 vs 0x260
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm (Ghidra draft as a reading aid); every branch sense, event type/value, counter and store traced; field_150 keeps the frame-time-scaled vector as retail stores it

// CB3CrashCombo::UpdateSpins() -- draftAK (C-first draft). 0x362340, 0xC20.
// [C] name: the mangled symbol in retail's tables. Written from the retail asm (Ghidra's draft as a reading aid). Layout from
// the proven UpdateSkids (B3CrashCombo_003620B0.cpp): 16 event records, ring indices field_104/108, field_10C last event.
// What it does [L]: the crashing car's angular velocity in its own frame (inverse matrix * angular velocity) is integrated
// per axis into field_18C[3]; each half-turn (pi either way, wrapping by pi) bumps the axis's spin counters
// (field_164/170, total field_17C, per-mode field_19C, backward flips field_1B8). When the sense of rotation about an axis
// changes (or the combo is reset: field_119, field_334 > 0), the finished spin count is turned into a combo event:
// X axis 6/7 (by the previous sense), Y axis 9 (car not upright: > 130 degrees from kYAxis) or 8 / 0xD (by field_1BE and
// field_198), Z axis 5 (full turns, value = count / 2) or 4 / 3 (a half turn, by field_198). Positive-rotation time per
// axis accumulates in field_180[3].
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
using namespace GtMathPs2;

extern float D_0052267C;   // [L] frame time
extern CGtV3d kYAxis;

struct UnkStruct_00362340_rec {             // a combo event (as UpdateSkids)
    int field_0;
    int field_4;                            // type
    int field_8;                            // value
    int field_C;
};
struct UnkStruct_00362340_phys {            // [G] CB3VehiclePhysics
    unsigned char pad_0[0x70];
    CGtMatrix3x4 field_70;                  // [L] Revenge mInverseMatrix
    unsigned char pad_B0[0x20];
    CGtV3d field_D0;                        // [L] Revenge mAngularVelocity
    unsigned char pad_E0[0x124];
    CGtMatrix3x4 *field_204;                // [L] Revenge mpMatrix
};

class CB3CrashCombo {
public:
    void UpdateSpins();

    UnkStruct_00362340_rec field_0[16];
    int field_100;                          // events added
    int field_104;                          // ring start
    int field_108;                          // ring end
    UnkStruct_00362340_rec *field_10C;      // last event
    UnkStruct_00362340_rec *field_110;
    UnkStruct_00362340_rec *field_114;
    unsigned char field_118;                // [G] new event
    unsigned char field_119;                // [G] reset
    unsigned char pad_11A[0x36];
    CGtV3d field_150;                       // previous frame's local angular rotation (times frame time)
    unsigned char pad_160[0x4];
    int field_164[3];                       // half-turns in the current spin, per axis
    int field_170[3];                       // half-turns in total, per axis
    int field_17C;                          // half-turns in total
    float field_180[3];                     // [G] time spinning the positive way, per axis
    float field_18C[3];                     // angle turned in the current spin, per axis
    int field_198;                          // [G] combo mode
    int field_19C[7];                       // half-turns about Y per mode
    int field_1B8;                          // backward X half-turns
    unsigned char field_1BC;
    unsigned char pad_1BD;
    unsigned char field_1BE;
    unsigned char pad_1BF[0x69];
    UnkStruct_00362340_phys *field_228;
    unsigned char pad_22C[0x108];
    int field_334;
};

// [L] the event append of UpdateSkids (same stores, same ring arithmetic), inlined at every site.
static inline void func_00362340_inl1(CB3CrashCombo *c, int type, int value)
{
    UnkStruct_00362340_rec *e = &c->field_0[c->field_108];
    c->field_100++;
    c->field_108 = (c->field_108 + 1) % 16;
    if (c->field_108 == c->field_104)
        c->field_104 = (c->field_104 + 1) % 16;
    if (c->field_110 == e)
        c->field_110 = 0;
    if (c->field_114 == e)
        c->field_114 = 0;
    c->field_118 = 1;
    c->field_10C = e;
    e->field_0 = 0;
    e->field_4 = type;
    e->field_8 = value;
    e->field_C = 0;
}

void CB3CrashCombo::UpdateSpins()
{
    CGtV3d w = TransformVector(field_228->field_70, field_228->field_D0);
    bool flip[3];
    bool reset = field_119 != 0 || field_334 > 0;
    flip[0] = reset || GtMath::Sign(w.X()) != GtMath::Sign(field_150.X());
    flip[1] = reset || GtMath::Sign(w.Y()) != GtMath::Sign(field_150.Y());
    flip[2] = reset || GtMath::Sign(w.Z()) != GtMath::Sign(field_150.Z());
    if (GtMath::Sign(w.X()) > 0.01f)
        field_180[0] += D_0052267C;
    if (GtMath::Sign(w.Y()) > 0.01f)
        field_180[1] += D_0052267C;
    if (GtMath::Sign(w.Z()) > 0.01f)
        field_180[2] += D_0052267C;

    int i = 3;
    while (i--) {
        bool hit = false;
        if (flip[i]) {
            if (!(GtMath::Abs(field_18C[i]) < 2.3561945f))     // [C] 0x4016CBE4 (3*pi/4)
                hit = true;
        } else {
            float a = field_18C[i];
            if (!(a < 3.1415927f)) {
                hit = true;
                field_18C[i] = a - 3.1415927f;
            } else if (a <= -3.1415927f) {
                hit = true;
                field_18C[i] += 3.1415927f;
            }
        }
        if (hit) {
            field_164[i]++;
            field_170[i]++;
            field_17C++;
            if (i == 1 && field_1BC != 0)
                field_19C[field_198]++;
            if (i == 0 && field_150.X() < 0.0f)
                field_1B8++;
        }
    }

    i = 3;
    while (i--) {
        if (flip[i]) {
            int *cnt = &field_164[i];
            int n = *cnt;
            if (n > 0) {
                switch (i) {
                case 0:
                    if (field_150.X() > 0.0f)
                        func_00362340_inl1(this, 6, n);
                    else
                        func_00362340_inl1(this, 7, n);
                    break;
                case 1: {
                    float ang = AngleBetweenVectors(field_228->field_204->mUp, kYAxis);
                    if (ang <= 50.0f || ang <= 130.0f) {     // [C] retail tests both (c.le.s 50.0, then 130.0)
                        if (field_1BE != 0) {
                            if (field_198 == 1 || field_198 == 2)
                                func_00362340_inl1(this, 8, *cnt);
                        } else if (field_198 == 2) {
                            func_00362340_inl1(this, 0xD, *cnt);
                        }
                    } else {
                        func_00362340_inl1(this, 9, *cnt);
                    }
                    break;
                }
                case 2: {
                    int half = n / 2;
                    if (half > 0) {
                        func_00362340_inl1(this, 5, half);
                    } else if (n & 1) {
                        if (field_198 == 1)
                            func_00362340_inl1(this, 4, 0);
                        else if (field_198 == 2)
                            func_00362340_inl1(this, 3, 0);
                    }
                    break;
                }
                }
            }
            field_18C[i] = 0.0f;
            *cnt = 0;
        }
    }

    w = w * D_0052267C;
    field_18C[0] += w.X();
    field_18C[1] += w.Y();
    field_18C[2] += w.Z();
    field_150 = w;
}
