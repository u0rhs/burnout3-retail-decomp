// CB3StreamedTrack::IntersectLineWithUnit(unsigned int,const CGtLine&,bool (*)(const CGtPolygonIntersectionResult&, void*),void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3StreamedTrack.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (flattened inline with goto test per arm).

// a73: frame solved with UnkStruct_00301BC0_pad (ctor+dtor local, N140). Left: 2 branch targets: retail's two 'b BF0; move a0,0' blocks jump straight to the join, ours chain through the found-block's 'b'; (without the pad the targets matched and the frame was 0x10 short)

struct CGtPolygonIntersectionResult;
struct CGtLine;
// [L] DNAT: CB3StreamedTrack::IntersectLineWithUnit(unsigned int,const CGtLine&,bool (*)(const CGtPolygonIntersectionResult&, void*),void*) (research/proto/new_names.csv, high)
struct UnkStruct_00301BC0_u {
    unsigned char pad_0[0x90];
    void * field_90;
};

struct UnkStruct_00301BC0_t {
    unsigned char pad_0[0xC];
    int field_C;
    unsigned char pad_10[0x14];
    int field_24;
    unsigned char pad_28[0x4];
    int field_2C;
    unsigned char pad_30[0x14C];
    UnkStruct_00301BC0_u * field_17C[1];
};

extern "C" void IntersectLine__18CGtCollisionKDTreeCFRC7CGtLinePFRC28CGtPolygonIntersectionResultPv_bPv(void *, const CGtLine &, bool (*)(const CGtPolygonIntersectionResult &, void *), void *);

struct UnkStruct_00301BC0_pad {
    unsigned char field_0[0x4];
    UnkStruct_00301BC0_pad() {}
    ~UnkStruct_00301BC0_pad() {}
};

extern "C" int IntersectLineWithUnit__16CB3StreamedTrackFUiRC7CGtLinePFRC28CGtPolygonIntersectionResultPv_bPv(UnkStruct_00301BC0_t * self, unsigned int p0, const CGtLine & p1, bool (*p2)(const CGtPolygonIntersectionResult &, void *), void * p3)
{
    UnkStruct_00301BC0_pad pad;  // [G] unused local object: retail keeps 0x10 unused frame bytes (known.md N140)
    UnkStruct_00301BC0_u * u;
    if (self->field_24 != self->field_2C && (int)p0 == self->field_24 % self->field_C) {
        u = 0;
        goto test;
    }
    if ((int)p0 >= 0 && (int)p0 < self->field_C) {
        UnkStruct_00301BC0_u * x = self->field_17C[(int)p0];
        if (*(int *)((unsigned int)x | 0x20000000) == 2) { u = x; goto test; }
        u = 0;
        goto test;
    }
    u = 0;
test: // [G] goto-per-arm form (flattened inlined lookup), keeps retail's direct branches to the u test
    if (u != 0) {
        IntersectLine__18CGtCollisionKDTreeCFRC7CGtLinePFRC28CGtPolygonIntersectionResultPv_bPv(u->field_90, p1, p2, p3);
        return 1;
    }
    return 0;
}
