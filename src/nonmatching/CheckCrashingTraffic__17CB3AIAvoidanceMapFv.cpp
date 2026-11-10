// NONMATCHING: CheckCrashingTraffic__17CB3AIAvoidanceMapFv -- retail 265 / ours 274 instructions, 245 in changed runs
// draftAN fork C C-first: the crashing-traffic sibling of CheckVehicle (its class slice and AddCarToMap link-name list reused): per crash-list body, relative velocity (player velocity - mAt * speed) -> direction / closing speed (fallback field_20 / 0.01), height band and side-plane skips, beyond 12 m the closing / time-to-contact / lead-time (<= 8) tests, then AddCarToMap(risk 3, side distance, dist, lead, pos + v*a, that + v*(a + D_01E75538), mAt x2, the D_00527440 record's box); 274/265, calls identical, no non-stack stores; every compare sense as retail (one c.le arm placed inverted)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm: the nine compares (operands, c.lt/c.le, branch sense), the constants (2^-32, 0.01, 12, 0.5, 8), the stack matrix pair at 0x230/0x1F0 and all ten AddCarToMap argument registers traced

// CheckCrashingTraffic__17CB3AIAvoidanceMapFv -- draftAN fork C (C-first draft). 0x13E920, 0x424. [C] name: the mangled symbol
// in retail's tables (B3AIAvoidance.cpp). The crashing-traffic sibling of CheckVehicle__17CB3AIAvoidanceMap (archived; its class
// slice, globals and AddCarToMap link-name declaration reused). What it does [L]: for each body in the crash list (D_00522660
// +0x122A10, count +0x122B1C, as CollisionIsCameraInVehicle's archive), the relative velocity (player body field_B0 minus the
// crashing body's mAt * its speed, field_B0.w) gives a direction and closing speed (fallback field_454->field_20 / 0.01 below
// 2^-32); skip when the body is out of the height band (|rel.y| > D_01E75534) or behind the player's side plane (Dot(field_1AE0,
// rel) < -field_2438); beyond 12 m skip when not closing (Dot(dir, fwd) < 0.01) or its time to contact t = dist / (facing * len)
// is negative, else lead time a = max(t - 0.5 * D_01E75538, 0) must be <= 8; then AddCarToMap with risk 3 and the body's matrix
// moved by velocity * a and that plus velocity * (a + D_01E75538), its box from D_00527440's per-index record (body +0x242B).
// Types and meanings [G].
#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"
using namespace GtMathPs2;

enum EAIAvoidanceRisk {};
class CGtAxisAlignedBox;
struct UnkStruct_0013E920_body {          // [L] CB3TrafficPhysics / CB3CollidingBody (crash list entry)
    unsigned char pad_0[0xB0];
    CGtV3dPlus field_B0;                  // [L] linear velocity, speed in w
    unsigned char pad_C0[0x144];
    CGtMatrix3x4 *field_204;              // world matrix
    unsigned char pad_208[0x2223];
    signed char field_242B;               // index of its record in D_00527440 (box)
};
struct UnkStruct_0013E920_y { unsigned char pad_0[0x30]; CGtV3d field_30; };
struct UnkStruct_0013E920_pl {            // the player's body (as CheckVehicle's UnkStruct_0013F090_x)
    unsigned char pad_0[0xB0];
    CGtV3dPlus field_B0;                  // [L] linear velocity
    unsigned char pad_C0[0x144];
    UnkStruct_0013E920_y *field_204;
};
struct UnkStruct_0013E920_own {           // as CheckVehicle's UnkStruct_0013F090_own
    unsigned char pad_0[0x20];
    CGtV3d field_20;
    unsigned char pad_30[0x1AB0];
    CGtV3d field_1AE0;
    unsigned char pad_1AF0[0x940];
    UnkStruct_0013E920_pl *field_2430;
    unsigned char pad_2434[4];
    float field_2438;
};
struct UnkStruct_D_00522660 {             // [G] the traffic system (crash list)
    unsigned char pad_0[0x122A10];
    UnkStruct_0013E920_body *field_122A10[(0x122B1C - 0x122A10) / 4];
    int field_122B1C;
};
struct UnkStruct_0013E920_rp { unsigned char pad_0[0xE80]; unsigned char field_E80[0x20]; };   // CGtAxisAlignedBox at +0xE80
struct UnkStruct_0013E920_rec { UnkStruct_0013E920_rp *field_0; unsigned char pad_4[0x17C]; };  // 0x180 per record
struct UnkStruct_D_00527440 {
    unsigned char pad_0[0x12880];
    UnkStruct_0013E920_rec field_12880[1];   // [G] count unknown (indexed by a signed byte)
};
extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_D_00527440 D_00527440;
class CB3AIAvoidanceMap {
public:
    void CheckCrashingTraffic();
    unsigned char pad_0[0x20];
    CGtV3d field_20;
    unsigned char pad_30[0x424];
    UnkStruct_0013E920_own *field_454;
};
extern float D_01E75534[];
extern float D_01E75538[];
extern "C" void AddCarToMap__17CB3AIAvoidanceMapF16EAIAvoidanceRiskfffQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dRC17CGtAxisAlignedBox(
    CB3AIAvoidanceMap *, EAIAvoidanceRisk, float, float, float, const CGtV3d &, const CGtV3d &, const CGtV3d &, const CGtV3d &,
    const CGtAxisAlignedBox &);

// 0x0013E920
void CB3AIAvoidanceMap::CheckCrashingTraffic()
{
    for (int i = 0; i < D_00522660.field_122B1C; i++) {
        UnkStruct_0013E920_body *body = D_00522660.field_122A10[i];
        CGtV3dPlus vel = body->field_B0;
        float speed = vel.Plus();
        CGtV3d d = field_454->field_2430->field_B0.GtV3d() - body->field_204->mAt * speed;
        CGtV3d fwd;
        float len;
        if (d.GetSquaredLength() < 2.3283064e-10f) {
            fwd = field_454->field_20;
            len = 0.01f;
        } else {
            len = d.NormaliseGetLength();
            fwd = d;
            if (len < 0.01f) len = 0.01f;
        }
        CGtV3d rel = body->field_204->mPos - field_20;
        if (!(GtMath::Abs(rel.Y()) <= D_01E75534[0])) continue;
        if (DotProduct(field_454->field_1AE0, rel) < -field_454->field_2438) continue;
        float dist = rel.NormaliseGetLength();
        float a;
        if (dist < 12.0f) {
            a = 0.0f;
        } else {
            float facing = DotProduct(rel, fwd);
            if (facing < 0.01f) continue;
            float t = dist / (facing * len);
            if (t < 0.0f) continue;
            a = t - 0.5f * D_01E75538[0];
            if (a < 0.0f) a = 0.0f;
            if (!(a <= 8.0f)) continue;
        }
        CGtMatrix3x4 m1 = *body->field_204;
        m1.mPos += body->field_B0.GtV3d() * a;
        CGtMatrix3x4 m2 = m1;
        m2.mPos += body->field_B0.GtV3d() * (a + D_01E75538[0]);
        AddCarToMap__17CB3AIAvoidanceMapF16EAIAvoidanceRiskfffQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dRC17CGtAxisAlignedBox(
            this, (EAIAvoidanceRisk)3, DotProduct(field_454->field_1AE0, m1.mPos - field_454->field_2430->field_204->field_30), dist, a,
            m1.mPos, m2.mPos, m1.mAt, m2.mAt,
            *(const CGtAxisAlignedBox *)D_00527440.field_12880[body->field_242B].field_0->field_E80);
    }
}
