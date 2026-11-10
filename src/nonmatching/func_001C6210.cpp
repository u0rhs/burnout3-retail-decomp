// NONMATCHING: func_001C6210 -- retail 250 / ours 248 instructions, 184 in changed runs
// 184 off, first draft: logic per retail (online 0x26 key filter out of line, 3 TransformPoints, |n.y|<0.2 degenerate-edge inline x3, ClipPolyToAABB, centroid into two sets, smallest key kept; key is an unsigned short kept in s3). Left: retail frame 0x460 has ~19 dead 16-byte slots (lane copies at 0x2E0/0x180/0x160/0x140..0xF0 and gaps) vs ours 0x390; the edge inline's bool is materialised (b; daddiu 1 / daddu 0; bnez) with the x/z test falling through, ours puts it out of line; Y-lane reads go through a second pointer register where retail folds lwc1 0x144(sp)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// func_001C6210 -- hand-written (ghvu15) from the Ghidra draft and retail. Unnamed in every table, so a placeholder with C
// linkage (the asm label); file and Area unknown, so _unclassified/. Reads as: skip a surface whose 2-byte key (p2, its first
// byte 0x26) is excluded while func_00131E40(&D_004EE040) holds; transform the triangle's three corners by the matrix at the head
// of `out`, drop it when it is near-vertical-normal-free and any edge is short in x/z, clip it to out's box
// (func_002BEDC0, [L] DNAT ClipPolyToAABB, medium), and accumulate the clipped centroid into one of two sets by the normal's
// y; the smallest key is kept. Structs carry only the fields touched; every type is [G] (instruction widths).
#include "b3/GtMath.h"
#include "b3/GtMathPs2.h"

using namespace GtMathPs2;

struct UnkStruct_001C6210_t {
    CGtV3d field_0[3];
    CGtV3d field_30;
};
struct UnkStruct_001C6210_k {
    unsigned char field_0;
    unsigned char field_1;
};
struct UnkStruct_001C6210_box {
    CGtV3d field_0;
    CGtV3d field_10;
};
struct UnkStruct_001C6210_o {
    CGtMatrix3x4 field_0;
    CGtV3d field_40;
    CGtV3d field_50;
    CGtV3d field_60;
    CGtV3d field_70;
    CGtV3d field_80;
    unsigned char pad_90[0x20];
    UnkStruct_001C6210_box field_B0;
    int field_D0;
    int field_D4;
    unsigned char pad_D8[0x4];
    unsigned short field_DC;
};
struct UnkStruct_001C6210_e {
    unsigned char field_0;
    unsigned char pad_1[0xBF];
};
struct UnkStruct_001C6210 {
    unsigned char pad_0[0x8D0];
    UnkStruct_001C6210_e field_8D0[11];
    unsigned char pad_1110[0x59];
    signed char field_1169;
};
struct UnkStruct_D_004EE040 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern UnkStruct_D_004EE040 D_004EE040;
extern "C" int func_00131E40(void *);
extern "C" int func_002BEDC0(void *out, int max, const UnkStruct_001C6210_box *box, void *in);  // [L] DNAT ClipPolyToAABB

static inline bool func_001C6210_inl1(CGtV3d a, CGtV3d b)
{
    CGtV3d d = a - b;
    if (GtMath::Abs(d.Y()) < 0.5f) {
        float x = d.X();
        float z = d.Z();
        if (x * x + z * z < 0.2f) return true;
    }
    return false;
}

// 0x001C6210
extern "C" void func_001C6210(UnkStruct_001C6210 * self, const UnkStruct_001C6210_t * tri, unsigned short key, UnkStruct_001C6210_o * out)
{
    if (func_00131E40(&D_004EE040) != 0) {
        if (*(unsigned char *)&key == 0x26) return;
        for (int i = 0; i < self->field_1169; i++) {
            if (self->field_8D0[i].field_0 == 0x26) return;
        }
    }
    CGtV3d t[3];
    for (int i = 0; i < 3; i++) {
        t[i] = TransformPoint(out->field_0, tri->field_0[i]);
    }
    if (GtMath::Abs(tri->field_30.Y()) < 0.2f) {
        if (func_001C6210_inl1(t[0], t[1])) return;
        if (func_001C6210_inl1(t[0], t[2])) return;
        if (func_001C6210_inl1(t[1], t[2])) return;
    }
    CGtV3d buf[15];
    int n = func_002BEDC0(buf, 15, &out->field_B0, t);
    if (n < 3) return;
    bool up = !(tri->field_30.Y() <= 0.7f);
    CGtV3d c = buf[0];
    for (int i = 1; i < n; i++) {
        c += buf[i];
    }
    c = c * (1.0f / (float)n);
    if (!up) {
        out->field_70 = Min(out->field_70, tri->field_30);
        out->field_80 = Max(out->field_80, tri->field_30);
        out->field_40 += c;
        out->field_D0++;
    } else {
        if (!(c.Y() <= 0.35f)) return;
        out->field_60 += tri->field_30;
        out->field_50 += c;
        out->field_D4++;
    }
    if (*(unsigned char *)&out->field_DC == 0 || *(unsigned char *)&key < *(unsigned char *)&out->field_DC) {
        out->field_DC = key;
    }
}
