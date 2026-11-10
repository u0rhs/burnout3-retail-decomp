// NONMATCHING: CacheWorldTriangles__17CB3RaceCarPhysicsFi -- retail 171 / ours 159 instructions, 133 in changed runs
// gaps1c: hand-drafted from the asm
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// gaps1c (2026-11-02): hand-drafted from the retail asm (0x1C5080..0x1C5328) with the Ghidra aid. Name [C]: the mangled
// symbol in retail's tables (research/retail_names.csv: B3RaceCarPhysics.cpp, medium). Builds the car's query sphere
// (centre = the body position +0x204->+0x30, radius = |+0x1D0| + the distance travelled this tick, x n sub-steps when
// the car's +0x1914 mode is on), asks the streamed track for the triangles in it (func_00301B00 with func_001C5330 as
// the per-triangle callback), then appends the car's own 6 cached triangles (+0x11D0, 0x40 each) once.
// TRACK: clean
// EQUIV: [L] written from the asm: the radius as retail's VU length (GetLength) plus the FPU-equivalent lane products;
// the sphere's w is the radius, xyz the position; the 6-entry copy and the flag word (low byte 0x26 for 0-1, 0x1A else)

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

struct UnkStruct_001C5080_q { float x, y, z, w; };
struct UnkStruct_001C5080_tri { UnkStruct_001C5080_q field_0[4]; };   // [C] 0x40 bytes: 4 quads (lq/sq)
struct UnkStruct_001C5080_cache {
    int field_0;                              // [C] the triangle count
    UnkStruct_001C5080_tri * field_4;
    unsigned short * field_8;                 // [C] one flag halfword per triangle
};
struct UnkStruct_001C5080_body { unsigned char pad_0[0x30]; UnkStruct_001C5080_q field_30; };
struct UnkStruct_001C5080_rc { unsigned char pad_0[0x1914]; int field_1914; };

class CB3RaceCarPhysics {
public:
    void CacheWorldTriangles(int);

    unsigned char pad_0[0xB0];
    UnkStruct_001C5080_q field_B0;            // [C] lqc2 0xB0, its w lane used ([G] the speed)
    unsigned char pad_C0[0x1D0 - 0xC0];
    CGtV3d field_1D0;                         // [C] lqc2 0x1D0: its length is the sphere's base radius
    unsigned char pad_1E0[0x200 - 0x1E0];
    UnkStruct_001C5080_cache * field_200;
    UnkStruct_001C5080_body * field_204;
    unsigned char pad_208[0x216 - 0x208];
    signed char field_216;                    // [C] TestPosition's result (sb), read back with lb
    signed char field_217;                    // [C] lb: the streamed-track index (0x1CC each)
    unsigned char pad_218[0x11D0 - 0x218];
    UnkStruct_001C5080_tri field_11D0[6];
    unsigned char pad_1350[0x1];
    unsigned char field_1351;                 // [C] the cached triangles are appended while set
    unsigned char pad_1352[0x13F4 - 0x1352];
    UnkStruct_001C5080_rc * field_13F4;
};

extern float D_0052267C;                      // [C] the world timer's dt (D_00522660 + 0x1C)
extern unsigned char D_00522660[];            // [C] the CB3World; + 0x12A348 = its CB3StreamedTrack array (0x1CC each)
extern unsigned char D_004E2704;              // [C] gp-relative byte, cleared before the query

extern "C" unsigned char TestPosition__16CB3StreamedTrackFQ29GtMathPs26CGtV3d(void *, UnkStruct_001C5080_q *);
extern "C" void func_00301B00(void *, int, UnkStruct_001C5080_q *, void *, CB3RaceCarPhysics *);
extern "C" void func_001C5330();

// 0x001C5080
void CB3RaceCarPhysics::CacheWorldTriangles(int n)
{
    float extra;
    if (field_13F4->field_1914 == 0) {
        extra = field_B0.w * D_0052267C;
    } else if (n > 0) {
        extra = field_B0.w * D_0052267C * (float)n;
    } else {
        extra = 0.0f;
    }
    UnkStruct_001C5080_q sphere;
    sphere.x = field_204->field_30.x;
    sphere.y = field_204->field_30.y;
    sphere.z = field_204->field_30.z;
    sphere.w = 1.0f * ((float)field_1D0.GetLength() + extra);   // retail: vmulx.w by vf0.w

    field_200->field_0 = 0;
    D_004E2704 = 0;
    field_216 = TestPosition__16CB3StreamedTrackFQ29GtMathPs26CGtV3d(D_00522660 + 0x12A348 + field_217 * 0x1CC,
                                                                     &field_204->field_30);
    func_00301B00(D_00522660 + 0x12A348 + field_217 * 0x1CC, field_216, &sphere, (void *)func_001C5330, this);
    if (field_1351 == 0) {
        return;
    }
    if (!(field_200->field_0 < 0x5A)) {
        field_1351 = 0;
        return;
    }
    for (int i = 0; i < 6; i++) {
        UnkStruct_001C5080_tri * d = &field_200->field_4[field_200->field_0];
        for (int k = 0; k < 3; k++) {
            d->field_0[k] = field_11D0[i].field_0[k];
        }
        d->field_0[3] = field_11D0[i].field_0[3];
        field_200->field_8[field_200->field_0] = 0;
        unsigned short * f = &field_200->field_8[field_200->field_0];
        *f = *f & 0xFF00;
        *f = *f | (i < 2 ? 0x26 : 0x1A);
        field_200->field_0 = field_200->field_0 + 1;
    }
}
