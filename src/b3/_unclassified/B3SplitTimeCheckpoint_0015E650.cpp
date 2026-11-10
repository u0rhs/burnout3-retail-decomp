// BUILD-HOST: wine
// N165 [C]: temporary exception -- this source matches retail only under wine; under the reference host
// (native Windows / wibo) two registers swap. To do: re-shape the source to match natively, then drop the marker.
// CB3SplitTimeCheckpoint::Prepare(CB3PlanarTriggerStruct*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SplitTimeCheckpoint.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (find-by-name via static inline helper with blk->field_18 (N113); field_4 typed void* (int flips block layout); bool callee result held in a bool temp).

class CB3PlanarTriggerStruct;
struct UnkStruct_0015E650_2;
struct UnkStruct_0015E650_e0;

struct UnkStruct_D_00518688 {
    UnkStruct_0015E650_2 * field_0;
    unsigned char pad_4[0xC];
};

struct UnkStruct_0015E650_2 {
    unsigned char pad_0[0x8];
    int field_8;
    UnkStruct_0015E650_e0 * field_C;
};

struct UnkStruct_0015E650_e0 {
    unsigned char pad_0[0x8];
    int field_8;
    unsigned char pad_C[0x4];
};

struct UnkStruct_D_004B7100 {
    unsigned char pad_0[0x10];
};

class CB3SplitTimeCheckpoint {
public:
    bool Prepare(CB3PlanarTriggerStruct* p0);

    unsigned char pad_0[0x4];
    void * field_4;
};

extern UnkStruct_D_00518688 D_00518688;
extern UnkStruct_D_004B7100 D_004B7100;

extern "C" bool Prepare__17CB3SpatialTriggerFP22CB3PlanarTriggerStruct(void *, void *);
extern "C" int strcasecmp(const char *, const void *);

struct UnkStruct_0015E650_blk {
    unsigned char pad_0[0x18];
    char field_18[8];
};

static inline void * func_0015E650_inl1()
{
    UnkStruct_0015E650_2 * t0 = D_00518688.field_0;
    for (int i = 0; i < t0->field_8; i++) {
        int t2 = t0->field_C[i].field_8;
        if (strcasecmp(((UnkStruct_0015E650_blk *)(t2 + 0x90))->field_18, &D_004B7100) == 0) {
            return (void *)t2;
        }
    }
    return 0;
}

// 0x0015E650
bool CB3SplitTimeCheckpoint::Prepare(CB3PlanarTriggerStruct* p0)
{
    if (field_4 == 0) {
        field_4 = func_0015E650_inl1();
    }
    bool r = Prepare__17CB3SpatialTriggerFP22CB3PlanarTriggerStruct(this, p0);
    return r;
}
