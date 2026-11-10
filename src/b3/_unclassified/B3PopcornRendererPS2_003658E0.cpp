// CB3PopcornRenderer::RenderPopcornArray(CB3PopcornArray*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3PopcornRendererPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (static method storing p0 (a0); D[mn++] = p0).

class CB3PopcornArray;
class CB3PopcornRenderer;
class CB3PopcornRenderer {
public:
    static void RenderPopcornArray(CB3PopcornArray* p0);
    static int mnNumRenderableArrays;
};
extern CB3PopcornArray * D_01EA4060[];  // [G] element count unknown

// 0x003658E0
void CB3PopcornRenderer::RenderPopcornArray(CB3PopcornArray* p0)
{
    D_01EA4060[mnNumRenderableArrays++] = p0;
}
