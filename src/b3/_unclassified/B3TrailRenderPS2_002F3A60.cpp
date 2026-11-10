// CB3TrailRenderer::Construct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrailRenderPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (5-iteration precompute of trail render constants; tables addressed via (unsigned)&arr[i] | 0x30000000).

// CB3TrailRenderer::Construct() -- hand-written (a69; the lifter refused the 'or 0x30000000' address form).
// Precomputes, for each of the 5 default trail parameter sets, the derived render constants into D_01E865E0
// (both tables addressed through the uncached-accelerated mirror, | 0x30000000). Layouts [G] from instruction widths.
struct UnkStruct_TrailParams {          // CB3TrailSystem::mgaDefaultParams element, stride 0x50
    unsigned char pad_0[0x24];
    float field_24;
    float field_28;
    float field_2C;
    float field_30;
    float field_34;
    float field_38;
    float field_3C;
    float field_40;
    float field_44;
    float field_48;
    float field_4C;
};
struct UnkStruct_TrailDerived {         // D_01E865E0 element, stride 0x30
    float field_0;
    float field_4;
    float field_8;
    float field_C;
    float field_10;
    float field_14;
    float field_18;
    float field_1C;
    float field_20;
    float field_24;
    float field_28;
    float field_2C;
};

class CB3TrailSystem {
public:
    static UnkStruct_TrailParams mgaDefaultParams[5];
};
extern UnkStruct_TrailDerived D_01E865E0[5];

class CB3TrailRenderer {
public:
    void Construct();
};

// 0x002F3A60
void CB3TrailRenderer::Construct()
{
    for (int i = 0; i < 5; i++) {
        UnkStruct_TrailParams *p = (UnkStruct_TrailParams *)((unsigned int)&CB3TrailSystem::mgaDefaultParams[i] | 0x30000000);
        UnkStruct_TrailDerived *o = (UnkStruct_TrailDerived *)((unsigned int)&D_01E865E0[i] | 0x30000000);
        o->field_0 = p->field_24 / 2.0f;
        o->field_4 = (p->field_28 - p->field_24) / p->field_4C / 2.0f;
        o->field_8 = 1.0f / p->field_4C;
        o->field_10 = p->field_2C;
        o->field_14 = p->field_30;
        o->field_18 = p->field_34;
        o->field_1C = p->field_38;
        o->field_20 = p->field_3C - p->field_2C;
        o->field_24 = p->field_40 - p->field_30;
        o->field_28 = p->field_44 - p->field_34;
        o->field_2C = p->field_48 - p->field_38;
    }
}
