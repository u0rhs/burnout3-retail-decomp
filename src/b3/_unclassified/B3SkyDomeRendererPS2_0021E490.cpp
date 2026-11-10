// CB3SkyDomeRenderer::CB3SkyDomeHemisphereParams::Construct(CB3SkyDomeRendererBase::ESkyComponent) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SkyDomeRendererPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (gif4: else-arm locals (fa, b, fb, k) before the field stores (fa ahead of field_20 = 0)).

// fresh2: maDefinitions as static const (loads hoist above the this-> stores); pass2e: b read into a local.
// CB3SkyDomeRenderer::CB3SkyDomeHemisphereParams::Construct(CB3SkyDomeRendererBase::ESkyComponent) -- hand-written (fresh2).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SkyDomeRendererPS2.cpp.
// [C] maDefinitions__18CB3SkyDomeRenderer: config/symbol_addrs_b3names.txt. Area not evidenced, so _unclassified/.
// Field names are placeholders and every type is [G] (instruction widths). The lifter refused it (movn).
// GIF quads with the one-line pcpyld asm (BRIEF gifq); 0x47 TEST_1 / 0x42 ALPHA_1 register numbers [L].

typedef unsigned int u_long128 __attribute__((mode(TI)));

class CB3SkyDomeRendererBase {
public:
    enum ESkyComponent { ESkyComponent_0 };  // [G] values unknown
};

struct UnkStruct_0021E490_def {
    float field_0;
    float field_4;
    int field_8;
    float field_C;
    float field_10;
    float field_14;
    float field_18;
    unsigned char field_1C;
    unsigned char field_1D;
    unsigned char field_1E;
    unsigned char field_1F;
};

class CB3SkyDomeRenderer {
public:
    static const UnkStruct_0021E490_def maDefinitions[];

    class CB3SkyDomeHemisphereParams {
    public:
        void Construct(CB3SkyDomeRendererBase::ESkyComponent p0);

        float field_0;
        float field_4;
        unsigned int field_8;
        int field_C;
        float field_10;
        float field_14;
        unsigned int field_18;
        unsigned int field_1C;
        float field_20;
        float field_24;
        float field_28;
        float field_2C;
        int field_30;
        int field_34;
        int field_38;
        int field_3C;
        u_long128 field_40;
        u_long128 field_50;
        u_long128 field_60;
        unsigned char pad_70[0x10];
        unsigned long field_80;
        unsigned long field_88;
    };
};

// 0x0021E490
void CB3SkyDomeRenderer::CB3SkyDomeHemisphereParams::Construct(CB3SkyDomeRendererBase::ESkyComponent p0)
{
    const UnkStruct_0021E490_def * d = &maDefinitions[p0];
    field_0 = 1.0f / (unsigned int)d->field_1C;
    field_4 = d->field_C;
    field_8 = d->field_1C;
    field_C = d->field_8;
    field_10 = (d->field_4 - d->field_0) / (unsigned int)d->field_1D;
    field_14 = d->field_0;
    field_18 = d->field_1D;
    field_1C = d->field_1E;
    if (field_1C == 1) {
        field_20 = 0.0f;
        field_24 = 0.0f;
        field_28 = 0.0f;
        field_2C = 0.0f;
    } else {
        // gif4: the locals first, then the field stores in offset order (fa before field_20 = 0 lets retail's lbu of
        // field_1C schedule early; 54 statement orders swept, the 4 exact ones all compute fa first).
        float fa = 0.0f + (d->field_0 + d->field_0) - d->field_0 * d->field_0;
        float b = d->field_4;
        float fb = 0.0f + (b + b) - b * b;
        float k = 1.0f / (fb - fa);
        field_20 = 0.0f;
        field_24 = d->field_10 / (unsigned int)d->field_1C;
        field_28 = k * (d->field_14 * fb - d->field_18 * fa);
        field_2C = k * (d->field_18 - d->field_14);
    }
    asm("pcpyld %0, %2, %1" : "=r"(field_60) : "r"(4), "r"(8));
    field_88 = 0;
    if (d->field_1F == 0) {
        asm("pcpyld %0, %2, %1" : "=r"(field_40) : "r"(0x30000), "r"(0x47));
        asm("pcpyld %0, %2, %1" : "=r"(field_50) : "r"(0x2A), "r"(0x42));
        field_30 = 0x80;
        field_34 = 0x80;
        field_38 = 0x80;
        field_3C = (p0 == 0) ? 0x20 : 0;
        field_80 = 0;
    } else {
        asm("pcpyld %0, %2, %1" : "=r"(field_40) : "r"(0x3140B), "r"(0x47));
        asm("pcpyld %0, %2, %1" : "=r"(field_50) : "r"(0x44), "r"(0x42));
        field_30 = 0x40;
        field_34 = field_30;
        field_38 = field_30;
        field_3C = 0x80;
        field_80 = 0xFF00000000000000UL;
    }
}
