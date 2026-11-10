// CB3CoronaRenderer::RenderDynamicArray(CB3CoronaDynamicArray*,CGtTexture*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CoronaRendererPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (element pointer to field_2A held in a local, computed as (short*)((char*)this+0x2A)+t0 (index-first addu)).

// CB3CoronaRenderer::RenderDynamicArray(CB3CoronaDynamicArray*,CGtTexture*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CoronaRendererPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3CoronaDynamicArray;
class CGtTexture;

class CB3CoronaRenderer;
struct UnkStruct_003073A0_e2;

struct UnkStruct_003073A0_e2 {
    int field_0[1];  // [G] element count unknown
    unsigned char pad_4[0x4];
};

class CB3CoronaRenderer {
public:
    void RenderDynamicArray(CB3CoronaDynamicArray* p0, CGtTexture* p1);
    static int mnPlayer;
    static int mnNumPackets;

    UnkStruct_003073A0_e2 field_0[1];  // [G] element count unknown
    unsigned char pad_8[0x22];
    short field_2A[1];  // [G] element count unknown
    unsigned char pad_2C[0x2];
    signed char field_2E[1];  // [G] element count unknown
};

extern int D_01E88900[];  // [G] element count unknown
extern CB3CoronaDynamicArray * D_01E88920[];  // [G] element count unknown
extern short D_01E88940[];  // [G] element count unknown

// 0x003073A0
void CB3CoronaRenderer::RenderDynamicArray(CB3CoronaDynamicArray* p0, CGtTexture* p1)
{
    int t0 = CB3CoronaRenderer::mnPlayer;
    short *pp = (short *)((char *)this + 0x2A) + t0;
    if (*pp == 0) return;
    int t1 = CB3CoronaRenderer::mnNumPackets;
    D_01E88900[t1] = field_0[t0].field_0[field_2E[t0]];
    D_01E88920[t1] = (CB3CoronaDynamicArray *)p0;
    D_01E88940[t1] = *pp;
    CB3CoronaRenderer::mnNumPackets = (t1 + 1);
}
