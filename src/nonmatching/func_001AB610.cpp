// NONMATCHING: func_001AB610 -- retail 39 / ours 49 instructions, 60 in changed runs
// gaps1c: hand-drafted from the asm
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// gaps1c (2026-11-02): hand-drafted from the retail asm (0x1AB610..0x1AB6A8). Unnamed; file B3CollidingBody.cpp per
// research/retail_names.csv (high). [L] the colliding body's SetTransform by its effect: the 4-row matrix at a1 is copied
// to the pose object (+0x204) and to +0x70..+0xA0, which is then inverted in place: rows 0-2 transposed, row 3 =
// -(r0 * p.x + r1 * p.y + r2 * p.z) over the transposed rows. [C] row 3's w lane ends as row 1's w (retail stores the
// whole quad of the sum, whose w came from the transposed row 1).
// TRACK: clean
// EQUIV: [L] written from the asm: the lane moves exact, the products and sums as retail's VU ops (GtMathPs2)

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;

typedef unsigned int u_long128 __attribute__((mode(TI)));
typedef struct { float x, y, z, w; } UnkStruct_001AB610_q;
struct UnkStruct_001AB610_m { u_long128 field_0[4]; };
struct UnkStruct_001AB610 {
    unsigned char pad_0[0x70];
    UnkStruct_001AB610_m field_70;
    unsigned char pad_B0[0x204 - 0xB0];
    UnkStruct_001AB610_m * field_204;
};

// 0x001AB610
extern "C" void func_001AB610(UnkStruct_001AB610 * self, const UnkStruct_001AB610_m * m)
{
    u_long128 a = m->field_0[0], b = m->field_0[1], c = m->field_0[2], d = m->field_0[3];
    UnkStruct_001AB610_m * o = self->field_204;
    o->field_0[0] = a;
    o->field_0[1] = b;
    o->field_0[2] = c;
    o->field_0[3] = d;
    self->field_70.field_0[0] = a;
    self->field_70.field_0[1] = b;
    self->field_70.field_0[2] = c;
    self->field_70.field_0[3] = d;
    UnkStruct_001AB610_q * r = (UnkStruct_001AB610_q *)self->field_70.field_0;
    float r0y = r[0].y, r0z = r[0].z, r1x = r[1].x, r1z = r[1].z, r2x = r[2].x, r2y = r[2].y;
    r[0].y = r1x;
    r[0].z = r2x;
    r[1].x = r0y;
    r[1].z = r2y;
    r[2].x = r0z;
    r[2].y = r1z;
    const CGtV3d & t0 = *(const CGtV3d *)&r[0];
    const CGtV3d & t1 = *(const CGtV3d *)&r[1];
    const CGtV3d & t2 = *(const CGtV3d *)&r[2];
    const CGtV3d & p = *(const CGtV3d *)&r[3];
    CGtV3d s = -((t0 * p.X() + t1 * p.Y()) + t2 * p.Z());
    float w = r[1].w;                          // [C] retail's stored sum keeps row 1's w
    UnkStruct_001AB610_q * q = (UnkStruct_001AB610_q *)&s;
    r[3].x = q->x;
    r[3].y = q->y;
    r[3].z = q->z;
    r[3].w = w;
}
