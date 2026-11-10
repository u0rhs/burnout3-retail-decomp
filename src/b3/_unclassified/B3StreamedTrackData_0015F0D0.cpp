// CB3StreamedTrackLODAndCollisionData::FixUp(int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3StreamedTrackData.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (offset fields typed void*; base pointers this+0x50/this+0x98 taken before their tests; element pointer for first loop).

// lifter variant 0
// CB3StreamedTrackLODAndCollisionData::FixUp(int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3StreamedTrackData.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3StreamedTrackLODAndCollisionData;
class CGtCollisionKDTree;
struct UnkStruct_0015F0D0_e0;
struct UnkStruct_0015F0D0_e2;

class CGtCollisionKDTree {
public:
    void FixUp();
};

struct UnkStruct_0015F0D0_e0 {
    unsigned char pad_0[0xC];
    void * field_C;
    unsigned char pad_10[0xC];
    void * field_1C;
    unsigned char pad_20[0x20];
};

struct UnkStruct_0015F0D0_e2 {
    unsigned char pad_0[0x1];
};

class CB3StreamedTrackLODAndCollisionData {
public:
    void FixUp(int p0);

    unsigned char pad_0[0x50];
    short field_50;
    unsigned char pad_52[0x2];
    UnkStruct_0015F0D0_e0 * field_54;
    int field_58;
    unsigned char pad_5C[0x34];
    CGtCollisionKDTree * field_90;
    void * field_94;
    void * field_98;
    void * * field_9C;
};

// 0x0015F0D0
void CB3StreamedTrackLODAndCollisionData::FixUp(int p0)
{
    char * base = (char *)this + 0x50;
    if (field_50 > 0) {
        field_54 = (UnkStruct_0015F0D0_e0 *)((char *)field_54 + (int)base);
        for (int i = 0; i < field_50; i++) {
            UnkStruct_0015F0D0_e0 * e = &field_54[i];
            if (e->field_C != 0) {
                e->field_C = (char *)e->field_C + (int)e;
            }
            if (e->field_1C != 0) {
                e->field_1C = (char *)e->field_1C + (int)e;
            }
        }
    }
    field_58 = 1;
    if (field_94 != 0) {
        field_94 = (char *)field_94 + (int)this;
    }
    if (field_90 != 0) {
        field_90 = (CGtCollisionKDTree *)((char *)field_90 + (int)this);
        field_90->FixUp();
    }
    char * base2 = (char *)this + 0x98;
    if (p0 != 0) {
        field_98 = (char *)field_98 + (int)base2;
        field_9C = (void **)((char *)field_9C + (int)base2);
    }
    for (int i1 = 0; i1 < p0; i1++) {
        if (field_9C[i1] != 0) {
            field_9C[i1] = base2 + (int)field_9C[i1];
        }
    }
}
