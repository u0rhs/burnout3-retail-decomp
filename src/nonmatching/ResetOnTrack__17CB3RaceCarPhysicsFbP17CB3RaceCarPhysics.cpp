// NONMATCHING: ResetOnTrack__17CB3RaceCarPhysicsFbP17CB3RaceCarPhysics -- retail 1017 / ours 983 instructions, 393 in changed runs
// draftB: written from the asm; 983 vs 1017, call set identical, line test out of line as retail; left: op= byte-loop copy of the rebuilt matrix (N263 shape), field_215 compare chain, frame 0xA10 vs 0xBF0
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm, every branch, call and store accounted for; inlined bodies are the proven func_001BEEE0 and the archived func_001BED00

// CB3RaceCarPhysics::ResetOnTrack(bool, CB3RaceCarPhysics*) -- draftB, written from the retail asm (0x1BFE80, 0xFE4).
// [C] name: the mangled symbol in retail's tables; [L] file B3RaceCarPhysics.cpp (its proven neighbours
// ResetOnTrackWhileCrashing 0x1BFE00 / Destruct 0x1C0E70 live there). Parameter names lbRollingStart / lpSpeedMatchCar and
// the bool return: Revenge STABS (ResetOnTrack__17CB4RaceCarPhysicsbP17CB4RaceCarPhysics) [L].
// Structure [C asm]: clear the per-reset state, field_216 = TestPosition (-1 = off the track: types 2/3 give up), drop a
// line from +4 to -5 in y through the car's position onto the track unit; miss -> zero velocity (func_001BEEE0's proven
// body inlined) and settle the wheels, return false; hit -> rebuild the car matrix on the hit normal (point + normal *
// wheel 0's field_0), OrthoNormalise, func_001AB610, then RollingStart (func_001BED00's body inlined, [L] DNAT name) at
// Max(speed-match car's speed - 9, 24.5872) or a zero velocity, settle the wheels, return true.
// Residue: retail copies the rebuilt matrix through an op= level with 3 byte loops (rows 1-3; N263 shape, not reproduced
// here), frame 0xA10 vs 0xBF0, the field_215 compare chain (retail beq 2 / beq 3 / bne 1), scheduling.
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
using namespace GtMathPs2;

struct UnkStruct_001BFE80_1 {
    unsigned char pad_0[0x27C9];
    unsigned char field_27C9;
};
struct UnkStruct_001BFE80_e {             // per-wheel block, stride 0xC0 (as func_001BEEE0's)
    float field_0;
    unsigned char pad_4[0x8];
    float field_C;
    float field_10;
    float field_14;
    unsigned char pad_18[0xA8];
};
struct CGtLine {                          // [C] class name from the mangled IntersectLineNearestWithUnit; layout [G]
    CGtV3d field_0;
    CGtV3d field_10;
};
struct CGtPolygonIntersectionResult {     // [C] class name (mangled callee); layout [G] (0x70 bytes at most: next slot)
    CGtV3d field_0;                       // hit point [G]
    CGtV3d field_10;                      // hit normal [G]
    unsigned char pad_20[0x50];
};

class CB3RaceCarPhysics {
public:
    bool ResetOnTrack(bool, CB3RaceCarPhysics *);
    void CacheWorldTriangles(int);

    unsigned char pad_0[0xB0];
    CGtV3dPlus field_B0;                  // velocity with its length in w [G] (func_001BEEE0)
    CGtV3d field_C0;                      // direction [G]
    CGtV3d field_D0;
    CGtV3d field_E0;
    CGtV3d field_F0;
    CGtV3d field_100;
    CGtV3d field_110;
    CGtV3d field_120;
    unsigned char pad_130[0xD4];
    CGtMatrix3x4 * field_204;
    unsigned char pad_208[0xD];
    signed char field_215;
    signed char field_216;
    signed char field_217;
    unsigned char pad_218[0x658];
    UnkStruct_001BFE80_e field_870[1];    // [G] element count unknown (stride 0xC0)
    unsigned char pad_930[0xC0];
    float field_9F0;
    unsigned char pad_9F4[0x775];
    signed char field_1169;
    unsigned char pad_116A[0x226];
    float field_1390;
    unsigned char pad_1394[0x60];
    UnkStruct_001BFE80_1 * field_13F4;
    unsigned char pad_13F8[0x24];
    int field_141C;
    int field_1420;
    int field_1424;
    int field_1428;
    int field_142C;
    float field_1430;
    int field_1434;
    int field_1438;
    int field_143C;
    float field_1440;
    unsigned char field_1444;
    unsigned char field_1445;
    unsigned char field_1446;
    unsigned char pad_1447[0x1];
    unsigned char field_1448[0x44];
    float field_148C;
    float field_1490;
    unsigned char pad_1494[0x8];
    float field_149C;
    float field_14A0;
    float field_14A4;
    unsigned char pad_14A8[0x20];
    int field_14C8;
    unsigned char pad_14CC[0x4];
    float field_14D0;
    float field_14D4;
    unsigned char pad_14D8[0x4C];
    int field_1524;
};

struct UnkStruct_D_0052267C { float field_0; };
extern UnkStruct_D_0052267C D_0052267C;
extern unsigned char D_00522660[];
extern "C" int TestPosition__16CB3StreamedTrackFQ29GtMathPs26CGtV3d(void *, CGtV3d *, signed char);
extern "C" bool IntersectLineNearestWithUnit__16CB3StreamedTrackFUiRC7CGtLineP28CGtPolygonIntersectionResult(
    void *, unsigned int, const CGtLine &, CGtPolygonIntersectionResult *);
extern "C" void CollideWheels__17CB3VehiclePhysicsFv(void *);
extern "C" void UpdateSuspension__17CB3VehiclePhysicsFf(void *, float);
extern "C" void func_001AB010(void *);
extern "C" void func_001AB610(void *, void *);
extern "C" int func_001C6F30(void *, float, float);

// [L] N185 stand-in for CGtV3d::NormaliseGetLength() (func_001BEEE0's proven body)
static inline XAxisType func_001BFE80_inl1(CGtV3d &v)
{
    XAxisType l = v.GetSquaredLength();
    u_long128 t, r;
    float f;
    asm(".set noreorder");
    asm("qmtc2 %0, $vf1" : : "r"(l.lVector));
    asm(".set noreorder" "\n\t" "vrsqrt $Q, $vf0w, $vf1x" "\n\t" "qmfc2 %1, $vf1" "\n\t" "mtc1 %1, %2" "\n\t" "sqrt.s %2, %2" "\n\t" "mfc1 %1, %2" "\n\t"
        "qmtc2 %1, $vf1" "\n\t" "qmfc2 %1, $vf1" "\n\t" "vwaitq" "\n\t" "qmtc2 %3, $vf1" "\n\t" "vmulq.xyz $vf1, $vf1, $Q" "\n\t"
        "qmfc2 %0, $vf1" "\n\t" ".set reorder" : "=r"(t), "=&r"(r), "=&f"(f) : "r"(v.mData));
    asm(".set reorder");
    v.mData = t;
    return XAxisType(r);
}
// [L] func_001BEEE0's proven body inlined: set the velocity, its length into w (zero: w = 0 and the matrix's at row as
// the direction), then each wheel's field_C = speed / field_0
static inline void func_001BFE80_inl2(CB3RaceCarPhysics * self, const CGtV3d * p1)
{
    self->field_B0.SetGtV3d(*p1);
    if (p1->GetSquaredLength() < 2.3283064e-10f) {
        self->field_B0.SetPlus(0.0f);
        self->field_C0 = self->field_204->mAt;
    } else {
        self->field_C0 = *p1;
        self->field_B0.SetPlus(func_001BFE80_inl1(self->field_C0));
    }
    float w = ((CGtV4d *)&self->field_B0)->W();
    for (int i = 0; i < self->field_1169; i++) {
        self->field_870[i].field_C = w / self->field_870[i].field_0;
    }
}
// [L] func_001BED00's body inlined ([L] DNAT CB3RaceCarPhysics::RollingStart(float), research/proto/new_names.csv, low)
static inline void func_001BFE80_inl3(CB3RaceCarPhysics * self, float speed)
{
    union { float f; unsigned int i; } u;
    u.f = speed;
    if ((u.i & 0x7F800000) <= 0x37800000) speed = 0.0f;
    CGtV3d v = self->field_204->mAt * speed;
    func_001BFE80_inl2(self, &v);
    self->field_149C = 0.5f * (self->field_148C + self->field_1490);
    self->field_14C8 = func_001C6F30(self->field_1448, self->field_9F0, ((CGtV4d *)&self->field_B0)->W());
    self->field_14D0 = -1.0f;
    self->field_14D4 = 1.0f;
    self->field_14A0 = -1.0f;
    self->field_14A4 = 0.0f;
}

// [G] a matrix from three rows, returned by value (its position row left unset: retail copies an unwritten slot)
static inline CGtMatrix3x4 func_001BFE80_inl4(CGtV3d right, CGtV3d up, CGtV3d at)
{
    CGtMatrix3x4 r;
    r.mRight = right;
    r.mUp = up;
    r.mAt = at;
    return r;
}

// [G] an empty inline: retail keeps the tests of a block that compiles to nothing (a release-build no-op)
static inline void func_001BFE80_inl5() {}

// 0x001BFE80
bool CB3RaceCarPhysics::ResetOnTrack(bool lbRollingStart, CB3RaceCarPhysics * lpSpeedMatchCar)
{
    field_141C = 0;
    field_1420 = 0;
    field_1424 = 0;
    field_1428 = 0;
    field_142C = 0;
    field_1430 = field_1390;
    field_1440 = field_1390;
    field_1434 = 0;
    field_1438 = 0;
    field_143C = 0;
    field_1444 = 0;
    field_1445 = 0;
    field_1446 = 0;
    field_1524 = 0;
    field_D0.Zero();
    field_E0.Zero();
    field_F0.Zero();
    field_100.Zero();
    field_110.Zero();
    field_120.Zero();
    field_C0 = field_204->mAt;
    field_216 = TestPosition__16CB3StreamedTrackFQ29GtMathPs26CGtV3d(D_00522660 + field_217 * 460 + 0x12A348, &field_204->mPos, field_217);
    if (field_216 == -1) {
        switch (field_215) {
        case 1:
            if (field_13F4 != 0 && field_13F4->field_27C9 != 0)
                func_001BFE80_inl5();
            break;
        case 3:
        case 2:
            return false;
        }
    }
    CGtLine lLine;
    lLine.field_0 = field_204->mPos;
    lLine.field_0.SetY(field_204->mPos.Y() + 4.0f);
    lLine.field_10 = field_204->mPos;
    lLine.field_10.SetY(field_204->mPos.Y() + -5.0f);
    CGtPolygonIntersectionResult lPolygonIntersection;
    if (!IntersectLineNearestWithUnit__16CB3StreamedTrackFUiRC7CGtLineP28CGtPolygonIntersectionResult(
            D_00522660 + field_217 * 460 + 0x12A348, field_216, lLine, &lPolygonIntersection)) {
        CGtV3d z;
        z.Zero();
        func_001BFE80_inl2(this, &z);
        CacheWorldTriangles(0);
        CollideWheels__17CB3VehiclePhysicsFv(this);
        for (int i = 0; i < field_1169; i++)
            field_870[i].field_10 = field_870[i].field_14;
        func_001AB010(this);
        UpdateSuspension__17CB3VehiclePhysicsFf(this, D_0052267C.field_0);
        return false;
    }
    CGtV3d pos = lPolygonIntersection.field_0 + lPolygonIntersection.field_10 * field_870[0].field_0;
    CGtV3d up = lPolygonIntersection.field_10;
    CGtV3d right = CrossProduct(up, field_204->mAt);
    right.Normalise();
    *field_204 = func_001BFE80_inl4(right, up, CrossProduct(right, up));
    field_204->mPos = pos;
    field_204->OrthoNormalise();
    func_001AB610(this, field_204);
    field_C0 = field_204->mAt;
    if (lbRollingStart) {
        float speed;
        if (lpSpeedMatchCar)
            speed = GtMath::Max((float)((CGtV4d *)&lpSpeedMatchCar->field_B0)->W() - 9.0f, 24.5872f);
        else
            speed = 24.5872f;
        func_001BFE80_inl3(this, speed);
    } else {
        CGtV3d z;
        z.Zero();
        func_001BFE80_inl2(this, &z);
    }
    CacheWorldTriangles(0);
    CollideWheels__17CB3VehiclePhysicsFv(this);
    for (int i = 0; i < field_1169; i++)
        field_870[i].field_10 = field_870[i].field_14;
    func_001AB010(this);
    UpdateSuspension__17CB3VehiclePhysicsFf(this, D_0052267C.field_0);
    return true;
}
