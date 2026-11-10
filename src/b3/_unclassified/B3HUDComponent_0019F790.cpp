// CB3HUDComponent::Prepare() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3HUDComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (arith1: scoped #pragma opt_arithtransformation off [G] (N182, N236)).

// CB3HUDComponent::Prepare() -- hand-written (L265; lifter refused).
// [C] name: the mangled symbol in retail's tables (high); statics and kpc*/kapc* names: config/symbol_addrs_b3names.txt.
// The texture find is the inlined find-by-name of B3GraphicsManager_0019EE40 (placeholder inline, [G]).

// [G] N182: scoped optimiser pragma (arith1 file-wide retry)
#pragma push
#pragma opt_arithtransformation off
class CGtTexture;

struct UnkStruct_0019F790_e0 {
    unsigned char pad_0[0x8];
    int field_8;
    unsigned char pad_C[0x4];
};

struct UnkStruct_0019F790_dic {
    unsigned char pad_0[0x8];
    int field_8;
    UnkStruct_0019F790_e0 * field_C;
};

struct UnkStruct_D_00518688 {
    UnkStruct_0019F790_dic * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

// [G] the block at +0x90 of each entry's object; a name at +0x18 (cf. N113).
struct UnkStruct_0019F790_blk {
    unsigned char pad_0[0x18];
    char field_18[8];
};

// [G] a const char * name/format global, padded so it is addressed with lui (N50).
struct UnkStruct_kpcB3HUDName {
    const char * field_0;
    unsigned char pad_4[0xC];
};

class CB3HUDComponent {
public:
    int Prepare();

    static CGtTexture * mapBoostFireCoreTextures[30];
    static CGtTexture * mapBoostFireEdgeTextures[41];
    static CGtTexture * mapBoostFireOverTextures[20];
    static CGtTexture * mapIconTextures[17];
    static CGtTexture * mpBoostBitsTexture;
    static CGtTexture * mpBoostBlueFlameTexture;
    static CGtTexture * mpHUDTexture;
    static CGtTexture * mpBoostFlareTexture;
    static CGtTexture * mpHealthBarTexture;
    static CGtTexture * mpHUDAftertouchTexture;
    static CGtTexture * mpHUDBackgroundTexture;
    static CGtTexture * mpBoostStarsTexture;
};

extern UnkStruct_D_00518688 D_00518688;
extern const UnkStruct_kpcB3HUDName kpcB3HUDBoostFireCoreTextureFormat;
extern const UnkStruct_kpcB3HUDName kpcB3HUDBoostFireEdgeTextureFormat;
extern const UnkStruct_kpcB3HUDName kpcB3HUDBoostFireOverTextureFormat;
extern const UnkStruct_kpcB3HUDName kpcB3HUDBoostBitsTextureName;
extern const UnkStruct_kpcB3HUDName kpcB3HUDBoostBlueFlameTextureName;
extern const UnkStruct_kpcB3HUDName kpcB3HUDHUDTextureName;
extern const UnkStruct_kpcB3HUDName kpcB3HUDBoostFlareTextureName;
extern const UnkStruct_kpcB3HUDName kpcB3HUDHealthBarTextureName;
extern const UnkStruct_kpcB3HUDName kpcB3HUDAftertouchTextureName;
extern const UnkStruct_kpcB3HUDName kpcB3HUDBackgroundTextureName;
extern const UnkStruct_kpcB3HUDName kpcB3HUDBoostStarstextureName;
extern const char * const kapcB3HUDIconTextureNames[];

extern "C" int sprintf(char *, const char *, ...);
extern "C" int strcasecmp(const char *, const char *);

static inline CGtTexture * func_0019F790_inl1(UnkStruct_0019F790_dic * t0, const char * name)
{
    for (int i = 0; i < t0->field_8; i++) {
        int t2 = t0->field_C[i].field_8;
        if (strcasecmp(((UnkStruct_0019F790_blk *)(t2 + 0x90))->field_18, name) == 0) {
            return (CGtTexture *)t2;
        }
    }
    return 0;
}

// 0x0019F790
int CB3HUDComponent::Prepare()
{
    char buf[16];
    int i;
    for (i = 0; i < 30; i++) {
        sprintf(buf, kpcB3HUDBoostFireCoreTextureFormat.field_0, i + 1);
        mapBoostFireCoreTextures[i] = func_0019F790_inl1(D_00518688.field_0, buf);
    }
    for (i = 0; i < 41; i++) {
        sprintf(buf, kpcB3HUDBoostFireEdgeTextureFormat.field_0, i + 1);
        mapBoostFireEdgeTextures[i] = func_0019F790_inl1(D_00518688.field_0, buf);
    }
    for (i = 0; i < 20; i++) {
        sprintf(buf, kpcB3HUDBoostFireOverTextureFormat.field_0, i + 1);
        mapBoostFireOverTextures[i] = func_0019F790_inl1(D_00518688.field_0, buf);
    }
    mpBoostBitsTexture = func_0019F790_inl1(D_00518688.field_0, kpcB3HUDBoostBitsTextureName.field_0);
    mpBoostBlueFlameTexture = func_0019F790_inl1(D_00518688.field_0, kpcB3HUDBoostBlueFlameTextureName.field_0);
    for (i = 0; i < 17; i++) {
        mapIconTextures[i] = func_0019F790_inl1(D_00518688.field_0, kapcB3HUDIconTextureNames[i]);
    }
    mpHUDTexture = func_0019F790_inl1(D_00518688.field_0, kpcB3HUDHUDTextureName.field_0);
    mpBoostFlareTexture = func_0019F790_inl1(D_00518688.field_0, kpcB3HUDBoostFlareTextureName.field_0);
    mpHealthBarTexture = func_0019F790_inl1(D_00518688.field_0, kpcB3HUDHealthBarTextureName.field_0);
    mpHUDAftertouchTexture = func_0019F790_inl1(D_00518688.field_0, kpcB3HUDAftertouchTextureName.field_0);
    mpHUDBackgroundTexture = func_0019F790_inl1(D_00518688.field_0, kpcB3HUDBackgroundTextureName.field_0);
    mpBoostStarsTexture = func_0019F790_inl1(D_00518688.field_0, kpcB3HUDBoostStarstextureName.field_0);
    return 1;
}

#pragma pop
