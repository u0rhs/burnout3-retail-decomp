// BUILD-HOST: wine
// N165 [C]: temporary exception -- this source matches retail only under wine; under the reference host
// (native Windows / wibo) two registers swap. To do: re-shape the source to match natively, then drop the marker.
// CB3StartFinishLine::Prepare(CB3PlanarTriggerStruct*,bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3StartFinishLine.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (find-by-name via static inline helper with blk->field_18 (N113); field_8 typed void* (int flips block layout); bool callee result in a bool temp).

class CB3PlanarTriggerStruct;
struct UnkStruct_0015E7C0_2;
struct UnkStruct_0015E7C0_e0;

struct UnkStruct_D_00518688 {
    UnkStruct_0015E7C0_2 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0015E7C0_2 {
    unsigned char pad_0[0x8];
    int field_8;
    UnkStruct_0015E7C0_e0 * field_C;
};

struct UnkStruct_0015E7C0_e0 {
    unsigned char pad_0[0x8];
    int field_8;
    unsigned char pad_C[0x4];
};

struct UnkStruct_D_004B7108 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3StartFinishLine {
public:
    bool Prepare(CB3PlanarTriggerStruct* p0, bool p1);

    unsigned char pad_0[0x8];
    void * field_8;  // [G] only null-tested and stored (pointer: an int flips the block layout)
    bool field_C;
};

extern UnkStruct_D_00518688 D_00518688;
extern UnkStruct_D_004B7108 D_004B7108;

extern "C" bool Prepare__22CB3SplitTimeCheckpointFP22CB3PlanarTriggerStruct(void *, void *);  // CB3SplitTimeCheckpoint::Prepare(CB3PlanarTriggerStruct*)
extern "C" int strcasecmp(const char *, const void *);

// [G] the block at +0x90 of each entry's object; a name at +0x18 (cf. N113, B3SunRendererPS2_0024D390).
struct UnkStruct_0015E7C0_blk {
    unsigned char pad_0[0x18];
    char field_18[8];
};

static inline void * func_0015E7C0_inl1()
{
    UnkStruct_0015E7C0_2 * t0 = D_00518688.field_0;
    for (int i = 0; i < t0->field_8; i++) {
        int t2 = t0->field_C[i].field_8;
        if (strcasecmp(((UnkStruct_0015E7C0_blk *)(t2 + 0x90))->field_18, &D_004B7108) == 0) {
            return (void *)t2;
        }
    }
    return 0;
}

// 0x0015E7C0
bool CB3StartFinishLine::Prepare(CB3PlanarTriggerStruct* p0, bool p1)
{
    field_C = p1;
    if (field_8 == 0 && field_C) {
        field_8 = func_0015E7C0_inl1();
    }
    bool r = Prepare__22CB3SplitTimeCheckpointFP22CB3PlanarTriggerStruct(this, p0);
    return r;
}
