// CB3MenuImages::CacheGlobalTextures() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3MenuImages.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (int-held record + char field_18[8] blk cast (unfolded 0x90/0x18); v0 declared before t0).

// lifter variant 0
// CB3MenuImages::CacheGlobalTextures() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3MenuImages.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3MenuImages;
struct UnkStruct_003717A0_3;
struct UnkStruct_003717A0_e1;
struct UnkStruct_D_00518688;
struct UnkStruct_003717A0_blk { unsigned char pad_0[0x18]; char field_18[8]; };

struct UnkStruct_D_00518688 {
    UnkStruct_003717A0_3 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003717A0_3 {
    unsigned char pad_0[0x8];
    int field_8;
    UnkStruct_003717A0_e1 * field_C;
};

struct UnkStruct_003717A0_e1 {
    unsigned char pad_0[0x8];
    int field_8;
    unsigned char pad_C[0x4];
};

class CB3MenuImages {
public:
    void CacheGlobalTextures();

    unsigned char pad_0[0x640];
    int field_640[1];  // [G] element count unknown
};

extern char * D_004C8E60[];  // [G] element count unknown
extern UnkStruct_D_00518688 D_00518688;

extern "C" int strcasecmp(const char *, const char *);

// 0x003717A0
void CB3MenuImages::CacheGlobalTextures()
{
    for (int i = 0; (i < 32); i++) {
        int v0;
        char * t0 = D_004C8E60[i];
        UnkStruct_003717A0_3 * t1 = D_00518688.field_0;
        for (int i1 = 0; (i1 < t1->field_8); i1++) {
            UnkStruct_003717A0_e1 * t2 = t1->field_C;
            int t3 = t2[i1].field_8;
            int r0 = strcasecmp(((UnkStruct_003717A0_blk *)(t3 + 0x90))->field_18, t0);
            if (r0 == 0) {
                v0 = t3;
                goto g39;
            }
        }
        v0 = 0;
g39:;
        field_640[i] = v0;
    }
}
