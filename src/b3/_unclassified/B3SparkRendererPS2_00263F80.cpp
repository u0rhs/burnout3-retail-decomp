// BUILD-HOST: wine
// N165 [C]: temporary exception -- this source matches retail only under wine; under the reference host
// (native Windows / wibo) two registers swap. To do: re-shape the source to match natively, then drop the marker.
// CB3SparkArray::Prepare() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SparkRendererPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (find-by-name as a static inline helper (strcasecmp(((blk*)(int+0x90))->field_18), N113); the inline keeps li v0,1 ahead of ld ra; CSparkBank nested at 0 and 0x4C).

struct UnkStruct_00263F80_4;
struct UnkStruct_00263F80_e0;
struct UnkStruct_00263F80_p;

struct UnkStruct_D_00518688 {
    UnkStruct_00263F80_4 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00263F80_4 {
    unsigned char pad_0[0x8];
    int field_8;
    UnkStruct_00263F80_e0 * field_C;
};

struct UnkStruct_00263F80_e0 {
    unsigned char pad_0[0x8];
    int field_8;
    unsigned char pad_C[0x4];
};

struct UnkStruct_00263F80_p {
    unsigned char pad_0[0x68];
    const char * field_68;
};

// [G] the block at +0x90 of each entry's object; a name at +0x18 (cf. N113).
struct UnkStruct_00263F80_blk {
    unsigned char pad_0[0x18];
    char field_18[8];
};

class CB3SparkArray {
public:
    class CSparkBank {
    public:
        void Prepare();
        unsigned char pad_0[0x4C];
    };
    int Prepare();

    CSparkBank field_0;
    CSparkBank field_4C;
    UnkStruct_00263F80_p * field_98;
    int field_9C;
};

extern UnkStruct_D_00518688 D_00518688;

extern "C" int strcasecmp(const char *, const char *);

static inline int func_00263F80_inl1(const char * name)
{
    UnkStruct_00263F80_4 * t0 = D_00518688.field_0;
    for (int i = 0; i < t0->field_8; i++) {
        int t2 = t0->field_C[i].field_8;
        if (strcasecmp(((UnkStruct_00263F80_blk *)(t2 + 0x90))->field_18, name) == 0) {
            return t2;
        }
    }
    return 0;
}

// 0x00263F80
int CB3SparkArray::Prepare()
{
    field_9C = func_00263F80_inl1(field_98->field_68);
    field_0.Prepare();
    field_4C.Prepare();
    return 1;
}
