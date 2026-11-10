// BUILD-HOST: wine
// N165 [C]: temporary exception -- this source matches retail only under wine; under the reference host
// (native Windows / wibo) two registers swap. To do: re-shape the source to match natively, then drop the marker.
// CB3HUDImpactTime::Prepare(int,EHUDAlign,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3HUDImpactTime.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (inlined find-by-name returning int record address; strcasecmp(((blk*)(t2+0x90))->field_18) per N113).

// CB3HUDImpactTime::Prepare(int,EHUDAlign,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3HUDImpactTime.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

enum EHUDAlign {};

class CB3HUDImpactTime;
struct UnkStruct_003D6AB0_2;
struct UnkStruct_003D6AB0_5;
struct UnkStruct_003D6AB0_e0;
struct UnkStruct_D_004CA848;
struct UnkStruct_D_004EE040;
struct UnkStruct_D_00518688;
struct UnkStruct_D_0051B934;

struct UnkStruct_D_00518688 {
    UnkStruct_003D6AB0_2 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003D6AB0_2 {
    unsigned char pad_0[0x8];
    int field_8;
    UnkStruct_003D6AB0_e0 * field_C;
};

struct UnkStruct_003D6AB0_e0 {
    unsigned char pad_0[0x8];
    int field_8;
    unsigned char pad_C[0x4];
};

struct UnkStruct_D_0051B934 {
    UnkStruct_003D6AB0_5 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003D6AB0_5 {
    unsigned char pad_0[0x8];
    unsigned long field_8;
};

struct UnkStruct_D_004CA848 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004EE040 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3HUDImpactTime {
public:
    int Prepare(int p0, EHUDAlign p1, int p2);

    unsigned char pad_0[0x20];
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
    unsigned char field_30;
};

extern UnkStruct_D_00518688 D_00518688;
extern UnkStruct_D_0051B934 D_0051B934;
extern UnkStruct_D_004CA848 D_004CA848;
extern UnkStruct_D_004EE040 D_004EE040;

extern "C" void Prepare__15CB3HUDComponentFiiii9EHUDAligni(void *, int, int, int, int, EHUDAlign, int);  // CB3HUDComponent::Prepare(int,int,int,int,EHUDAlign,int)
extern "C" int strcasecmp(const char *, const void *);

// [G] the block at +0x90 of each entry's object; a name at +0x18 (cf. N113, B3SunRendererPS2_0024D390).
struct UnkStruct_003D6AB0_blk {
    unsigned char pad_0[0x18];
    char field_18[8];
};
extern "C" int func_00131CE0(void *);
extern "C" int func_003E9700(unsigned long);

static inline int func_003D6AB0_inl1()  // [G] placeholder: an inlined find-by-name
{
    UnkStruct_003D6AB0_2 * t0 = D_00518688.field_0;
    for (int i = 0; i < t0->field_8; i++) {
        int t2 = t0->field_C[i].field_8;
        if (strcasecmp(((UnkStruct_003D6AB0_blk *)(t2 + 0x90))->field_18, &D_004CA848) == 0) {
            return t2;
        }
    }
    return 0;
}

// 0x003D6AB0
int CB3HUDImpactTime::Prepare(int p0, EHUDAlign p1, int p2)
{
    Prepare__15CB3HUDComponentFiiii9EHUDAligni(this, 1, 3, 0, p0, p1, p2);
    field_24 = 0;
    field_20 = 0;
    field_28 = 0;
    int t2 = func_003D6AB0_inl1();
    field_2C = t2;
    field_30 = 0;
    if (func_00131CE0(&D_004EE040) != 0) {
        UnkStruct_003D6AB0_5 * t3 = D_0051B934.field_0;
        if (t3 != 0) {
            field_30 = func_003E9700(t3->field_8);
        }
    }
    return 1;
}
