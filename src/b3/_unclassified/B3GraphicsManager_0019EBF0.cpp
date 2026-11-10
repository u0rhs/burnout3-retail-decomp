// CB3GraphicsManagerBase::Prepare() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3GraphicsManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (fresh: texture-find inline cloned from Construct, int return 1 (retail leaves v0=1)).

// CB3GraphicsManagerBase::Prepare() -- hand-written (fresh2).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3GraphicsManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Field names are placeholders and every type is [G].
// Texture-find inline cloned from CB3GraphicsManagerBase::Construct (B3GraphicsManager_0019EE40.cpp).

class CGtTexture;
struct UnkStruct_0019EBF0_e0;

struct UnkStruct_0019EBF0_dic {
    unsigned char pad_0[0x8];
    int field_8;
    UnkStruct_0019EBF0_e0 * field_C;
};

struct UnkStruct_0019EBF0_e0 {
    unsigned char pad_0[0x8];
    int field_8;
    unsigned char pad_C[0x4];
};

// [G] the block at +0x90 of each entry's object; a name at +0x18 (cf. N113).
struct UnkStruct_0019EBF0_blk {
    unsigned char pad_0[0x18];
    char field_18[8];
};

struct UnkStruct_D_00518688 {
    UnkStruct_0019EBF0_dic * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3RadialBlur {
public:
    void Prepare();
    unsigned char pad_0[0x50];
};

class CB3Bloom {
public:
    void Prepare();
    unsigned char pad_0[0x10];
};

class CB3DirectionalBlurBase {
public:
    void Prepare();
    unsigned char pad_0[0x30];
};

class CB3VehicleRenderer {
public:
    void Prepare();
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3GraphicsManagerBase {
public:
    int Prepare();

    unsigned char pad_0[0x40];
    CGtTexture * field_40;
    CGtTexture * field_44;
    CGtTexture * field_48;
    CGtTexture * field_4C;
    unsigned char field_50;
    unsigned char pad_51[0x3];
    int field_54;
    unsigned char pad_58[0x4];
    unsigned char field_5C;
    unsigned char field_5D;
    unsigned char field_5E;
    unsigned char field_5F;
    unsigned char field_60;
    unsigned char field_61;
    unsigned char field_62;
    unsigned char field_63;
    unsigned char field_64;
    unsigned char field_65;
    unsigned char field_66;
    unsigned char field_67;
    unsigned char field_68;
    unsigned char field_69;
    unsigned char field_6A;
    unsigned char field_6B;
    unsigned char field_6C;
    unsigned char pad_6D[0x17];
    int field_84;
    int field_88;
    unsigned char pad_8C[0x144];
    CB3RadialBlur field_1D0;
    CB3Bloom field_220;
    CB3DirectionalBlurBase field_230;
    int field_260;
    int field_264;
    float field_268;
    unsigned char pad_26C[0x4];
    CB3RadialBlur field_270;
    CB3Bloom field_2C0;
    CB3DirectionalBlurBase field_2D0;
    int field_300;
    int field_304;
    float field_308;
};

extern UnkStruct_D_00518688 D_00518688;
extern CB3VehicleRenderer gVehicleRenderer;
extern char D_004B7328[];
extern char D_004B7338[];
extern char D_004B7348[];
extern char D_004B7360[];

extern "C" int strcasecmp(const char *, const char *);

static inline CGtTexture * func_0019EBF0_inl1(UnkStruct_0019EBF0_dic * t0, const char * name)
{
    for (int i = 0; i < t0->field_8; i++) {
        int t2 = t0->field_C[i].field_8;
        if (strcasecmp(((UnkStruct_0019EBF0_blk *)(t2 + 0x90))->field_18, name) == 0) {
            return (CGtTexture *)t2;
        }
    }
    return 0;
}

// 0x0019EBF0
int CB3GraphicsManagerBase::Prepare()
{
    field_84 = 0;
    field_40 = func_0019EBF0_inl1(D_00518688.field_0, D_004B7328);
    field_44 = func_0019EBF0_inl1(D_00518688.field_0, D_004B7338);
    field_48 = func_0019EBF0_inl1(D_00518688.field_0, D_004B7348);
    field_4C = func_0019EBF0_inl1(D_00518688.field_0, D_004B7360);
    field_1D0.Prepare();
    field_220.Prepare();
    field_230.Prepare();
    field_260 = 0;
    field_264 = 0;
    field_268 = 1.0f;
    field_270.Prepare();
    field_2C0.Prepare();
    field_2D0.Prepare();
    field_300 = 0;
    field_304 = 0;
    field_308 = 1.0f;
    gVehicleRenderer.Prepare();
    field_50 = 0;
    field_54 = 0;
    field_5D = 1;
    field_5E = 1;
    field_5F = 1;
    field_60 = 1;
    field_61 = 1;
    field_62 = 1;
    field_63 = 1;
    field_64 = 0;
    field_65 = 1;
    field_66 = 1;
    field_67 = 1;
    field_68 = 1;
    field_69 = 1;
    field_6A = 1;
    field_6B = 1;
    field_6C = 1;
    field_5C = 1;
    field_88 = 23;
    return 1;
}
