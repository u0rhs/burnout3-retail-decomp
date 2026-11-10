// NONMATCHING: func_002294D0 -- retail 246 / ours 240 instructions, 254 in changed runs
// draftK: return type fixed to int (returns the strip vertex count k in v0 [C asm 0x002297A4..]); v301 logic otherwise; residue: retail stores each set vector immediately, keeps loop-1 Interpolate results unfolded, frame 0x80 vs 0xC0
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed


// func_002294D0 -- hand-written (lifter refused). Builds an n x n grid of (position, uv) vertex pairs at the top of the
// scratchpad (0x70004000 - n*n*32): the first and last rows interpolated between fixed corners, the columns between
// them, then copies the rows out as one triangle strip from 0x70000000 (a degenerate vertex before and after each
// row pair).
#include "b3/GtMathPs2.h"

using GtMathPs2::CGtV3d;

// [G] one grid vertex: position then uv (32 bytes; both copied with lq/sq pairs).
struct UnkStruct_002294D0 {
    CGtV3d field_0;
    CGtV3d field_10;
};

// 0x002294D0
extern "C" int func_002294D0(int n)
{
    UnkStruct_002294D0 *grid = (UnkStruct_002294D0 *)0x70004000 - n * n;
    CGtV3d pB0;
    CGtV3d pA0;
    CGtV3d p90;
    CGtV3d p80;
    CGtV3d uv70;
    CGtV3d uv60;
    CGtV3d uv50;
    CGtV3d uv40;
    p90.SetX(-1.0f);
    p90.SetY(1.0f);
    p90.SetZ(1.0f);
    pA0.SetX(1.0f);
    pA0.SetY(-1.0f);
    pA0.SetZ(1.0f);
    uv40.SetX(0.0f);
    uv40.SetY(0.0f);
    uv40.SetZ(0.0f);
    pB0.SetX(-1.0f);
    pB0.SetY(-1.0f);
    pB0.SetZ(1.0f);
    p80.SetX(1.0f);
    p80.SetY(1.0f);
    p80.SetZ(1.0f);
    uv60.SetX(0.0f);
    uv60.SetY(1.0f);
    uv60.SetZ(0.0f);
    uv50.SetX(1.0f);
    uv50.SetY(0.0f);
    uv50.SetZ(0.0f);
    uv70.SetX(1.0f);
    uv70.SetY(1.0f);
    uv70.SetZ(0.0f);
    int i;
    for (i = 0; i < n; i++) {
        float t = (float)i / (float)(n - 1);
        grid[i].field_0 = GtMathPs2::Interpolate(p80, p90, t);
        grid[i].field_10 = GtMathPs2::Interpolate(uv40, uv50, t);
    }
    UnkStruct_002294D0 *last = &grid[n * n - n];
    for (i = 0; i < n; i++) {
        float t = (float)i / (float)(n - 1);
        last[i].field_0 = GtMathPs2::Interpolate(pA0, pB0, t);
        last[i].field_10 = GtMathPs2::Interpolate(uv60, uv70, t);
    }
    for (int j = 0; j < n; j++) {
        for (i = 0; i < n; i++) {
            float t = (float)i / (float)(n - 1);
            grid[j + i * n].field_0 = GtMathPs2::Interpolate(grid[j].field_0, last[j].field_0, t);
            grid[j + i * n].field_10 = GtMathPs2::Interpolate(grid[j].field_10, last[j].field_10, t);
        }
    }
    UnkStruct_002294D0 *out = (UnkStruct_002294D0 *)0x70000000;
    int k = 0;
    for (int r = 0; r < n - 1; r++) {
        if (r > 0) {
            out[k] = grid[r * n];
            k++;
        }
        UnkStruct_002294D0 *row0 = &grid[r * n];
        UnkStruct_002294D0 *row1 = &grid[(r + 1) * n];
        for (i = 0; i < n; i++) {
            out[k] = row0[i];
            out[k + 1] = row1[i];
            k += 2;
        }
        if (r < n - 2) {
            out[k] = out[k - 1];
            k++;
        }
    }
    return k;
}
