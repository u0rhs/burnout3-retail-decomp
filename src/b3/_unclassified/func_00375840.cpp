// Hand-written; the lifter refused it (near25: AddTrailSegment sibling shape (goto append in first nest, 0+e14+k*dt madd, CGtV4d W(), a116 RNG step)).

// near25: cloned from the proven sibling CB3TrailSystem::AddTrailSegment (simfind 0.43): first-test nest with the goto append label
// inside it, `float k = 1.5f; lim = 0.0f + e14; lim += k * dt;` (adda/madd order), `if (e == 0) return;`, CGtV4d segments
// read with W(), and the a116 RNG step (`a += field_4; field_4 += a; field_0 = a;`).
// func_00375840 -- CB3ScrapeSystem::AddScrapeSegment(CB3ScrapeEmitterData*,CGtV3d,CGtV3d,EB3ScrapeType,const CGtMatrix*) [L] DNAT
#include "b3/GtMathPs2.h"
struct UnkStruct_00375840_seg { GtMathPs2::CGtV4d field_0; GtMathPs2::CGtV4d field_10; };
struct UnkStruct_00375840_buf {
    int field_0;
    unsigned char pad_4[0xC];
    UnkStruct_00375840_seg field_10[16];
};
struct UnkStruct_00375840_em {
    int field_0;
    float field_4;
    int field_8;
    void * field_C;
    short field_10;
    short field_12;
    unsigned char pad_14[0xC];
    UnkStruct_00375840_buf field_20[2];
    UnkStruct_00375840_buf * field_440;
    UnkStruct_00375840_buf * field_444;
};
struct UnkStruct_00375840_ed {
    unsigned char pad_0[0x10];
    UnkStruct_00375840_em * field_10;
    float field_14;
};
struct UnkStruct_00375840_grp { UnkStruct_00375840_em * field_0[32]; int field_80; int field_84; };
struct UnkStruct_00375840 {
    unsigned char pad_0[0x8A00];
    UnkStruct_00375840_em ** field_8A00;
    int field_8A04;
    unsigned char pad_8A08[0x84];
    UnkStruct_00375840_grp field_8A8C[1];
};
struct UnkStruct_00375840_rnd { int field_0; int field_4; };
struct UnkStruct_D_01EA4910 { unsigned char pad_0[0x40]; };
struct UnkStruct_F { float field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_F D_00522680, D_0052267C;
extern UnkStruct_D_01EA4910 D_01EA4910[];
extern "C" UnkStruct_00375840_rnd mRandom__17CB3ScrapeRenderer;
extern "C" void AddScrapeSegment__16CB3ScrapeEmitterFQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dPCQ29GtMathPs212CGtMatrix3x4(void *, const void *, const void *, const void *);

// [L] DNAT: CB3ScrapeSystem::AddScrapeSegment(...) (research/proto/new_names.csv, high)
// 0x00375840
extern "C" void func_00375840(UnkStruct_00375840 * self, UnkStruct_00375840_ed * ed, const u_long128 * pa, const u_long128 * pb, int type, const void * mat)
{
    u_long128 va = *pa;
    u_long128 vb = *pb;
    
    float now = D_00522680.field_0;
    if (ed->field_14 != -1.0f) {
        float dt = D_0052267C.field_0;
        float k = 1.5f;
        float lim = 0.0f + ed->field_14;
        lim += k * dt;
        if (now <= lim) {
            UnkStruct_00375840_em * cur = ed->field_10;
            if (type == cur->field_8 && cur->field_444->field_0 != 16) {
            append:
                ed->field_14 = now;
                AddScrapeSegment__16CB3ScrapeEmitterFQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3dPCQ29GtMathPs212CGtMatrix3x4(ed->field_10, &va, &vb, mat);
                return;
            }
        }
    }
    {
        UnkStruct_00375840_em * e;
        if (self->field_8A04 != 0) {
            int n = self->field_8A04 - 1;
            self->field_8A04 = n;
            e = self->field_8A00[n];
            e->field_4 = -1.0f;
            e->field_C = &D_01EA4910[type];
            e->field_12 = 0;
            e->field_10 = 0;
            e->field_20[0].field_0 = 0;
            e->field_20[1].field_0 = 0;
            e->field_440 = &e->field_20[0];
            e->field_444 = &e->field_20[1];
            int a = mRandom__17CB3ScrapeRenderer.field_0;
            a = (a << 16) + (a >> 16);
            a += mRandom__17CB3ScrapeRenderer.field_4;
            mRandom__17CB3ScrapeRenderer.field_4 += a;
            mRandom__17CB3ScrapeRenderer.field_0 = a;
            e->field_0 = a & 3;
            self->field_8A8C[type].field_0[self->field_8A8C[type].field_80++] = e;
            e->field_8 = type;
        } else {
            e = 0;
        }
        if (e == 0) {
            return;
        }
        if (ed->field_10 != 0) {
            float dt = D_0052267C.field_0;
            float k = 1.5f;
            float lim = 0.0f + ed->field_14;
            lim += k * dt;
            if (now <= lim) {
                UnkStruct_00375840_buf * ob = ed->field_10->field_440;
                if (ob->field_0 == 16) {
                    UnkStruct_00375840_buf * nb = e->field_444;
                    nb->field_10[nb->field_0].field_0 = ob->field_10[15].field_0;
                    nb->field_10[nb->field_0].field_10 = ob->field_10[15].field_10;
                    nb->field_0++;
                    e->field_4 = ob->field_10[15].field_10.W();
                    e->field_10 = e->field_10 | 2;
                }
            }
        }
        ed->field_10 = e;
        goto append;
    }
}
