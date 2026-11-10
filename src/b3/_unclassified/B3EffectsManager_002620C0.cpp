// CB3EffectsManager::RenderPreFogEffects(int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3EffectsManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (element pointer local e=&D_00522660.field_12A980[p0]; N140 unused ctor/dtor local UnkStruct_002620C0_pad for the 0x50 frame).

// CB3EffectsManager::RenderPreFogEffects(int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3EffectsManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3DebrisArray;

class CB3DebrisRenderer;
class CB3EffectsManager;
struct UnkStruct_002620C0_e0;
struct UnkStruct_002620C0_e1;
struct UnkStruct_D_00522660;
struct UnkStruct_D_00665F2C;

class CB3DebrisRenderer {
public:
    static void RenderDebrisArray(CB3DebrisArray*, float);
    static void EndRender();
};

struct UnkStruct_D_00665F2C {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_002620C0_e0 {
    unsigned char pad_0[0x1CBA];
    unsigned char field_1CBA;
    unsigned char pad_1CBB[0xB15];
};

struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x12A980];
    UnkStruct_002620C0_e0 field_12A980[1];  // [G] element count unknown
};

struct UnkStruct_002620C0_e1 {
    unsigned char pad_0[0x30];
};

struct UnkStruct_002620C0_pad { UnkStruct_002620C0_pad() {} ~UnkStruct_002620C0_pad() {} };

class CB3EffectsManager {
public:
    void RenderPreFogEffects(int p0);

    UnkStruct_002620C0_e1 field_0[1];  // [G] element count unknown
    unsigned char pad_30[0x1F818];
    float field_1F848;
};

extern UnkStruct_D_00665F2C D_00665F2C;
extern UnkStruct_D_00522660 D_00522660;

extern "C" void BeginRender__17CB3DebrisRendererFv(void *);  // CB3DebrisRenderer::BeginRender()
extern "C" void Render__15CB3ScrapeSystemFv(void *, int);  // CB3ScrapeSystem::Render(), passed 1 more argument(s) [G]
extern "C" void func_002BD560(void *);

// 0x002620C0
void CB3EffectsManager::RenderPreFogEffects(int p0)
{
    UnkStruct_002620C0_pad g;
    if (D_00665F2C.field_0 == 0) {
        return;
    }
    BeginRender__17CB3DebrisRendererFv(this);
    for (int i = 0; (i < 4); i++) {
        CB3DebrisRenderer::RenderDebrisArray((CB3DebrisArray*)((char *)&field_0[i] + 0xB0), field_1F848);
    }
    CB3DebrisRenderer::EndRender();
    func_002BD560(((char *)this + 0x2600));
    UnkStruct_002620C0_e0 *e = &D_00522660.field_12A980[p0];
    if (e->field_1CBA != 0) {
        Render__15CB3ScrapeSystemFv(((char *)this + 0x16C80), (p0 * 10192));
    }
}
