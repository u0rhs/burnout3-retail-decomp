// CGtTextureCache::Destruct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtTextureCachePS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (global and ourGlobals field typed void* instead of int: int gave a duplicated tail).

class CGtTextureCache;
struct UnkStruct_ourGlobals {
    unsigned char pad_0[0x98];
    void *field_98;
};
class CGtTextureCache {
public:
    void Destruct();
    void FlushCache();
    int field_0;
};
extern void *D_004E2938;
extern UnkStruct_ourGlobals ourGlobals;

// 0x002220E0
void CGtTextureCache::Destruct()
{
    FlushCache();
    void *t0 = D_004E2938;
    if (t0 != 0) {
        D_004E2938 = 0;
        ourGlobals.field_98 = t0;
    }
    field_0 = 0;
}
