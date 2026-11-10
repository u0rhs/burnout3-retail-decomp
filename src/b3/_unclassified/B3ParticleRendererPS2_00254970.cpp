// CB3ParticleRenderer::RenderParticleArray(CB3ParticleArray*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ParticleRendererPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (first guard tests D_004E29E4 != 0 (a70 misread the branch sense)).


// CB3ParticleRenderer::RenderParticleArray(CB3ParticleArray*)
class CB3ParticleArray;

struct UnkStruct_D_004E29E4 {
    unsigned char field_0;
};
extern UnkStruct_D_004E29E4 D_004E29E4;

struct UnkStruct_RPA_1 {
    unsigned char pad_0[0x5D];
    unsigned char field_5D;
};

class CB3ParticleArray {
public:
    unsigned char pad_0[0xE4];
    UnkStruct_RPA_1 * field_E4;
    char field_E8[0x28];
    int field_110;
    char field_114[0x28];
    int field_13C;
};

struct UnkStruct_D_01D9D010 {
    CB3ParticleArray * field_0;
    void * field_4[2];
    int field_C;
};
extern UnkStruct_D_01D9D010 D_01D9D010[];

class CB3ParticleRenderer {
public:
    static int mnDMANumQW;
    static int mnNumRenderableArrays;
    static unsigned char mbIsCrash;
    static void RenderParticleArray(CB3ParticleArray * p0);
};

// 0x00254970
void CB3ParticleRenderer::RenderParticleArray(CB3ParticleArray * p0)
{
    if (p0->field_E4->field_5D == 0 && D_004E29E4.field_0 != 0) {
        return;
    }
    UnkStruct_D_01D9D010 * e = &D_01D9D010[mnNumRenderableArrays];
    e->field_C = 0;
    if (p0->field_110 != 0) {
        e->field_4[e->field_C++] = p0->field_E8;
        mnDMANumQW += 0x16;
    }
    if (mbIsCrash != 0 && p0->field_13C != 0) {
        e->field_4[e->field_C++] = p0->field_114;
        mnDMANumQW += 0x16;
    }
    if (e->field_C != 0) {
        e->field_0 = p0;
        mnNumRenderableArrays++;
    }
}
