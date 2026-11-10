// CB3StreamedTrack::IntersectLineNearestWithUnit(unsigned int,const CGtLine&,CGtPolygonIntersectionResult*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3StreamedTrack.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (slot: N140 pad object reserves the 0x10 slot; its dtor keeps separate return blocks; GetUnit inlined by hand with u assigned on every path).

class CB3StreamedTrack;
class CGtLine;
class CGtCollisionKDTree;
struct CGtPolygonIntersectionResult;
struct UnkStruct_00301C80_u;

struct UnkStruct_00301C80_u {
    unsigned char pad_0[0x90];
    CGtCollisionKDTree * field_90;
};

class CB3StreamedTrack {
public:
    int IntersectLineNearestWithUnit(unsigned int p0, const CGtLine& p1, CGtPolygonIntersectionResult* p2);

    unsigned char pad_0[0xC];
    int field_C;
    unsigned char pad_10[0x14];
    int field_24;
    unsigned char pad_28[0x4];
    int field_2C;
    unsigned char pad_30[0x14C];
    UnkStruct_00301C80_u * field_17C[1];  // [G] element count unknown
};

extern "C" int IntersectLineNearest__18CGtCollisionKDTreeCFRC7CGtLineP28CGtPolygonIntersectionResult(const CGtCollisionKDTree *, const CGtLine&, CGtPolygonIntersectionResult*);

struct UnkStruct_00301C80_pad {
    unsigned char field_0[0x4];
    UnkStruct_00301C80_pad() {}
    ~UnkStruct_00301C80_pad() {}
};
// 0x00301C80
int CB3StreamedTrack::IntersectLineNearestWithUnit(unsigned int p0, const CGtLine& p1, CGtPolygonIntersectionResult* p2)
{
    UnkStruct_00301C80_pad pad;  // [G] an unused local object: retail's frame keeps 0x10 unused bytes (N140); its destructor also keeps the two separate return-0 blocks
    UnkStruct_00301C80_u * u;
    int idx = (int)p0;
    if (field_24 != field_2C && idx == field_24 % field_C) {
        u = 0;
    } else if (idx >= 0 && idx < field_C) {
        UnkStruct_00301C80_u * x = field_17C[idx];
        if (*(int *)((unsigned int)x | 0x20000000) == 2) u = x;
        else u = 0;
    } else {
        u = 0;
    }
    if (u != 0) {
        if (IntersectLineNearest__18CGtCollisionKDTreeCFRC7CGtLineP28CGtPolygonIntersectionResult(u->field_90, p1, p2) == 1) return 1;
        return 0;
    }
    return 0;
}
