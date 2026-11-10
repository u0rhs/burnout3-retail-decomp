// NONMATCHING: DrawCollisionTriangleCache__22CB3PhysicsManagerDebugFv -- retail 150 / ours 147 instructions, 115 in changed runs
// a258: logic complete; first loop (green, per-cache triangles) matches exactly, frame 0x110 matches (line + col declared once at function top, col reassigned from CGtV4d(0,1,0,1)/(1,1,1,1); per-site CGtV4d va/vb temps). Open: second loop (white, extra triangle at this+field_1B38[s1]->field_20D*0xD84+n*36): retail reloads field_1B38[s1] and field_20D after the line store for both vertices (second one with mult1) and precomputes n*36 into s4, this+s1*4 in s3; ours CSEs the reload (147 vs 150) and keeps n. volatile on the pointer array over-reloads (153).
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
struct UnkStruct_DCTC_line { u_long128 field_0; u_long128 field_10; };
struct UnkStruct_DCTC_slot { unsigned char pad_0[0xDB0]; unsigned int field_DB0; };
struct UnkStruct_DCTC_prop { unsigned char pad_0[0x20D]; unsigned char field_20D; };
struct UnkStruct_D_004EB1E0 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_004EB1E0 D_004EB1E0;
extern "C" void DrawLine__15CB3DebugManagerFRC7CGtLineQ29GtMathPs26CGtV4d(void *, UnkStruct_DCTC_line *, CGtV4d *);
class CB3PhysicsManagerDebug {
public:
    void DrawCollisionTriangleCache();
    unsigned char pad_0[0x1B38];
    UnkStruct_DCTC_prop *field_1B38[2];
    unsigned int field_1B40;
};
void CB3PhysicsManagerDebug::DrawCollisionTriangleCache()
{
    UnkStruct_DCTC_line line;
    CGtV4d col;
    for (unsigned int s1 = 0; s1 < field_1B40; s1++) {
        col = CGtV4d(0.0f, 1.0f, 0.0f, 1.0f);
        char *s0 = (char *)this + s1 * 0xD84;
        unsigned int n = 0;
        for (; n < ((UnkStruct_DCTC_slot *)s0)->field_DB0; n++) {
            char *t = s0 + n * 36;
            unsigned int k = 1;
            for (unsigned int j = 0; j < 3; j++) {
                float *a = (float *)(t + 0x30 + j * 12);
                float *b = (float *)(t + 0x30 + k * 12);
                CGtV4d va; va.f[0] = a[0]; va.f[1] = a[1]; va.f[2] = a[2];
                line.field_0 = va.mData;
                CGtV4d vb; vb.f[0] = b[0]; vb.f[1] = b[1]; vb.f[2] = b[2];
                line.field_10 = vb.mData;
                DrawLine__15CB3DebugManagerFRC7CGtLineQ29GtMathPs26CGtV4d(&D_004EB1E0, &line, &col);
                k = (k + 1) % 3;
            }
        }
        col = CGtV4d(1.0f, 1.0f, 1.0f, 1.0f);
        unsigned int k = 1;
        for (unsigned int j = 0; j < 3; j++) {
            float *a = (float *)((char *)this + field_1B38[s1]->field_20D * 0xD84 + n * 36 + 0x30 + j * 12);
            float *b = (float *)((char *)this + field_1B38[s1]->field_20D * 0xD84 + n * 36 + 0x30 + k * 12);
            CGtV4d va; va.f[0] = a[0]; va.f[1] = a[1]; va.f[2] = a[2];
            line.field_0 = va.mData;
            CGtV4d vb; vb.f[0] = b[0]; vb.f[1] = b[1]; vb.f[2] = b[2];
            line.field_10 = vb.mData;
            DrawLine__15CB3DebugManagerFRC7CGtLineQ29GtMathPs26CGtV4d(&D_004EB1E0, &line, &col);
            k = (k + 1) % 3;
        }
    }
    field_1B40 = 0;
}
