// NONMATCHING: func_0022B120 -- retail 264 / ours 264 instructions, 23 in changed runs
// 23 off: logic, frame, s-registers and the strip-copy loop exact; left: one inner-loop block's VU numbering/scheduling -- retail keeps the X-lane product (operator*(XAxisType,float)) on its own VF register (v on vf4, pos vf3, product vf2, scalar vf1) where ours reuses the scalar's (v vf3/pos vf2/product vf1), which also moves the v store (sqc2) and the 0.25/2.0 constant loads; =&j stand-in, Set(x,y,z), statement order and pragmas don't change it
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_0022B120 -- hand-written (ghvu15) from the Ghidra draft and retail. [L] DNAT: _PartialHemisphereCreate(int,float,float)
// (research/proto/new_names.csv, high; B3GraphicsManagerPS2.cpp): builds a (rows+1) x (cols+1) grid of hemisphere vertices
// (position + texture coordinate, 32 bytes each) just below scratchpad 0x70004000, then writes them as one triangle strip
// (with degenerate joins) from scratchpad 0x70000000, returning the strip's vertex count. Unnamed in our symbol tables, so a
// placeholder with C linkage (the asm label). Every type is [G] (instruction widths). Shape notes (ghvu15): both loops share
// `i` and `j` (declared at the top; a separate k/inner j rotate the copy loop's temporaries), p->field_10's second write through
// its own pointer (retail's fp), `c` after the first lane write, six N140 pads for retail's 0x140 frame.
#include "b3/GtMathPs2.h"

using GtMathPs2::CGtV3d;

extern "C" float sqrtf(float);
extern "C" float floorf(float);

struct UnkStruct_0022B120_pad { int x[4]; UnkStruct_0022B120_pad() {} ~UnkStruct_0022B120_pad() {} };
struct UnkStruct_0022B120_v {
    CGtV3d field_0;
    CGtV3d field_10;
};

// 0x0022B120
extern "C" int func_0022B120(int n, float radius, float angle)
{
    float s = sqrtf((float)n);
    int rows = (int)floorf(s);
    float frac = s - (float)rows;
    int cols = rows;
    if (frac <= 0.75f) {
        if (!(frac <= 0.25f)) cols = rows + 1;
    } else {
        cols = rows + 1;
        rows = cols;
    }
    int out = 0;
    UnkStruct_0022B120_v * base = (UnkStruct_0022B120_v *)0x70004000 - (cols + 1) * (rows + 1);
    int idx = 0;
    CGtV3d v;
    UnkStruct_0022B120_pad p0, p1, p2, p3, p4, p5;  // N140 [G]: six 16-byte slots retail keeps below v (frame 0x140)
    int j;
    int i;
    for (i = 0; i <= rows; i++) {
        float a = 0.017453292f * ((float)i * (180.0f / (float)(rows * 2)));
        v.SetY(radius * cosf(a));
        float r = radius * sinf(a);
        float t = (1.0f / (float)rows) * (float)i;
        for (j = 0; j <= cols; j++) {
            float b = 0.017453292f * ((float)j * (angle / (float)cols));
            v.SetX(sinf(b));
            v.SetZ(cosf(b));
            UnkStruct_0022B120_v * p = &base[idx];
            p->field_0.SetX(v.X() * r);
            float c = 2.0f * (3.1415927f * ((0.25f / (float)cols) * (float)j));
            p->field_0.SetY(v.Y());
            p->field_0.SetZ(v.Z() * r);
            p->field_10.SetX(t * sinf(c));
            CGtV3d * q = &p->field_10;
            q->SetY(t * cosf(c));
            idx++;
        }
    }
    UnkStruct_0022B120_v * dst = (UnkStruct_0022B120_v *)0x70000000;
    for (i = 0; i < rows; i++) {
        int a = i * (cols + 1);
        int b = (i + 1) * (cols + 1);
        if (i > 0) {
            UnkStruct_0022B120_v * sp = &base[a];
            dst[out++] = *sp;
        }
        dst[out] = base[a];
        dst[out + 1] = base[b];
        out += 2;
        for (j = 0; j < cols; j++) {
            a++;
            b++;
            dst[out] = base[a];
            dst[out + 1] = base[b];
            out += 2;
        }
        if (i < rows - 1) {
            dst[out++] = base[b];
        }
    }
    return out;
}
