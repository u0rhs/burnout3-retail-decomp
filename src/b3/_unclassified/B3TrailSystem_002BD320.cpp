// CB3TrailSystem::AddTrailSegment(CB3TrailEmitterData*,GtMathPs2::CGtV3d,GtMathPs2::CGtV3d,EB3TrailType,const GtMathPs2::CGtMatrix3x4*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrailSystem.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (group as member array field_13C0C[type] + idx*3+base addu order).

// near5: the per-type group as a real 0x208-byte member array (field_13C0C[type], count field_200, [G] layout) with `g.field_0[g.field_200++] = em` in one statement, and `idx * 3 + (signed char *)d->field_100` for retail's addu operand order (a223's float/madd shape kept).


#include "b3/GtMathPs2.h"
enum EB3TrailType { UnkEnum_TT_0 };
struct UnkStruct_D_00522680 { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_0052267C { float field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_00522680 D_00522680;
extern UnkStruct_D_0052267C D_0052267C;

struct UnkStruct_BD000_data {
    GtMathPs2::CGtV4d field_0[16];
    signed char field_100[16][3];
};
struct UnkStruct_BD000_em {
    float field_0;
    void * field_4;
    UnkStruct_BD000_data * field_8;
    unsigned char pad_C[4];
    signed char field_10;
    signed char field_11;
    unsigned char field_12;
};
class CB3TrailEmitterData {
public:
    unsigned char pad_0[0x10];
    UnkStruct_BD000_em * field_10;
    float field_14;
};
struct UnkStruct_BD000_grp {
    UnkStruct_BD000_em * field_0[0x80];
    int field_200;
    unsigned char pad_204[4];
};
class CB3TrailSystem {
public:
    void AddTrailSegment(CB3TrailEmitterData *, GtMathPs2::CGtV3d, GtMathPs2::CGtV3d, EB3TrailType, const GtMathPs2::CGtMatrix3x4 *);
    static unsigned char mgaDefaultParams[];

    unsigned char pad_0[0x13A00];
    UnkStruct_BD000_em ** field_13A00;
    int field_13A04;
    unsigned char pad_13A08[4];
    unsigned char pad_13A0C[0x200];
    UnkStruct_BD000_grp field_13C0C[1];  // [G] element count unknown (stride 0x208 [C] from the multiply)
};
extern "C" void AddTrailSegment__15CB3TrailEmitterFQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dPCQ29GtMathPs212CGtMatrix3x4(void *, const void *, const void *, const void *);

// 0x002BCF60
void CB3TrailSystem::AddTrailSegment(CB3TrailEmitterData * e, GtMathPs2::CGtV3d pos, GtMathPs2::CGtV3d dir, EB3TrailType type, const GtMathPs2::CGtMatrix3x4 * m)
{
    GtMathPs2::CGtV3d p = pos;
    GtMathPs2::CGtV3d d = dir;
    float now = D_00522680.field_0;
    if (e->field_14 != -1.0f) {
        float dt = D_0052267C.field_0;
        float k = 1.5f;
        float lim = 0.0f + e->field_14;
        lim += k * dt;
        if (now <= lim) {
            UnkStruct_BD000_em * cur = e->field_10;
            if (type == cur->field_11 && cur->field_10 != 16) {
            append:
                e->field_14 = now;
                AddTrailSegment__15CB3TrailEmitterFQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dPCQ29GtMathPs212CGtMatrix3x4(e->field_10, &p, &d, m);
                return;
            }
        }
    }
    {
        UnkStruct_BD000_em * em;
        if (field_13A04 != 0) {
            int n = field_13A04 - 1;
            field_13A04 = n;
            em = field_13A00[n];
            em->field_0 = -1.0f;
            em->field_4 = mgaDefaultParams + type * 0x50;
            em->field_12 = 0;
            em->field_10 = 0;
            field_13C0C[type].field_0[field_13C0C[type].field_200++] = em;
            em->field_11 = type;
        } else {
            em = 0;
        }
        if (em == 0) {
            return;
        }
        if (e->field_10 != 0) {
            float dt = D_0052267C.field_0;
            float k = 1.5f;
        float lim = 0.0f + e->field_14;
        lim += k * dt;
            if (now <= lim) {
                UnkStruct_BD000_em * cur = e->field_10;
                if (cur->field_10 == 16) {
                    int last = cur->field_10 - 1;
                    int idx = em->field_10;
                    UnkStruct_BD000_data * sd = cur->field_8;
                    UnkStruct_BD000_data * dd = em->field_8;
                    GtMathPs2::CGtV4d * q = &sd->field_0[last];
                    dd->field_0[idx] = *q;
                    signed char * s3 = last * 3 + (signed char *)sd->field_100;
                    signed char * d3 = idx * 3 + (signed char *)dd->field_100;
                    d3[0] = s3[0];
                    d3[1] = s3[1];
                    d3[2] = s3[2];
                    em->field_10 = em->field_10 + 1;
                    em->field_0 = q->W();
                    em->field_12 = em->field_12 | 2;
                }
            }
        }
        e->field_10 = em;
        goto append;
    }
}
