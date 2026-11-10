// BUILD-HOST: wine
// N165 [C]: temporary exception -- this source matches retail only under wine; under the reference host
// (native Windows / wibo) two registers swap. To do: re-shape the source to match natively, then drop the marker.
// CB3PopcornArray::Prepare() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3PopcornRendererPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (find-by-name as a static inline helper (N113 block cast); int literal -9999 stored to a float (kept cvt.s.w); index i & 4 as in retail's andi 4).

struct UnkStruct_00366050_4;
struct UnkStruct_00366050_e0;

struct UnkStruct_D_00518688 {
    UnkStruct_00366050_4 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00366050_4 {
    unsigned char pad_0[0x8];
    int field_8;
    UnkStruct_00366050_e0 * field_C;
};

struct UnkStruct_00366050_e0 {
    unsigned char pad_0[0x8];
    int field_8;
    unsigned char pad_C[0x4];
};

struct UnkStruct_00366050_p {
    const char * field_0;
};

struct UnkStruct_00366050_q {
    float field_0[36];
};

// [G] the block at +0x90 of each entry's object; a name at +0x18 (cf. N113).
struct UnkStruct_00366050_blk {
    unsigned char pad_0[0x18];
    char field_18[8];
};

class CB3PopcornArray {
public:
    int Prepare();

    unsigned char pad_0[0x1C];
    UnkStruct_00366050_q * field_1C;
    unsigned char pad_20[0x4];
    int field_24;
    int field_28;
    int field_2C;
    UnkStruct_00366050_p * field_30;
};

extern UnkStruct_D_00518688 D_00518688;

extern "C" int strcasecmp(const char *, const char *);

static inline int func_00366050_inl1(const char * name)
{
    UnkStruct_00366050_4 * t0 = D_00518688.field_0;
    for (int i = 0; i < t0->field_8; i++) {
        int t2 = t0->field_C[i].field_8;
        if (strcasecmp(((UnkStruct_00366050_blk *)(t2 + 0x90))->field_18, name) == 0) {
            return t2;
        }
    }
    return 0;
}

// 0x00366050
int CB3PopcornArray::Prepare()
{
    field_2C = func_00366050_inl1(field_30->field_0);
    for (int i = 0; i < field_24; i++) {
        field_1C[i / 4].field_0[i & 4] = -9999;
    }
    field_28 = 0;
    return 1;
}
