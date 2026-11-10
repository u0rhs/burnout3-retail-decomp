// Hand-written; the lifter refused it (const CGtSphere by-value param (lq above sd ra, sdra rule 1) + inline helper flattened to goto-join arms (BRIEF a171)).

// [L] DNAT: CB3StreamedTrack::IntersectSphereWithUnit(unsigned int,GtMathPs2::CGtSphere,bool (*)(const CGtPolygonIntersectionResult&, void*),void*) (research/proto/new_names.csv, high)
struct CGtPolygonIntersectionResult;
typedef unsigned int u_long128 __attribute__((mode(TI)));
struct CGtSphere { u_long128 mData; };
struct UnkStruct_00301B00_u {
    unsigned char pad_0[0x90];
    void * field_90;
};

struct UnkStruct_00301B00_t {
    unsigned char pad_0[0xC];
    int field_C;
    unsigned char pad_10[0x14];
    int field_24;
    unsigned char pad_28[0x4];
    int field_2C;
    unsigned char pad_30[0x14C];
    UnkStruct_00301B00_u * field_17C[1];
};

extern "C" void func_003BE9B0(void *, CGtSphere, bool (*)(const CGtPolygonIntersectionResult &, void *), void *);

static inline UnkStruct_00301B00_u * func_00301B00_inl1(UnkStruct_00301B00_t * self, int idx)
{
    if (idx >= 0 && idx < self->field_C) {
        UnkStruct_00301B00_u * x = self->field_17C[idx];
        if (*(int *)((unsigned int)x | 0x20000000) == 2) {
            return x;
        }
        return 0;
    }
    return 0;
}

struct UnkStruct_00301B00_pad {
    unsigned char field_0[0x4];
    UnkStruct_00301B00_pad() {}
    ~UnkStruct_00301B00_pad() {}
};

// 0x00301B00
extern "C" int func_00301B00(UnkStruct_00301B00_t * self, unsigned int p0, const CGtSphere p1, bool (*p2)(const CGtPolygonIntersectionResult &, void *), void * p3)
{
    UnkStruct_00301B00_pad pad;  // [G] unused local object: retail keeps 0x10 unused frame bytes (known.md N140)
    UnkStruct_00301B00_u * u;
    if (self->field_24 != self->field_2C && (int)p0 == self->field_24 % self->field_C) {
        u = 0;
    } else {
        int idx = (int)p0;
        if (idx >= 0 && idx < self->field_C) {
            UnkStruct_00301B00_u * x = self->field_17C[idx];
            if (*(int *)((unsigned int)x | 0x20000000) == 2) {
                u = x;
                goto test;
            }
            u = 0;
            goto test;
        }
        u = 0;
        goto test;
    }
test:
    if (u != 0) {
        func_003BE9B0(u->field_90, p1, p2, p3);
        return 1;
    }
    return 0;
}
