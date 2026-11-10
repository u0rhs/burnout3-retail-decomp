// CB3EffectsManager::Alloc(unsigned int,unsigned int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3EffectsManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (a244: r = D+off; off += p0; store off (pointer taken before the increment)).

class CB3EffectsManager {
public:
    static void * Alloc(unsigned int p0, unsigned int p1);
};
extern unsigned int _gnEffectsMemoryAllocation;
extern unsigned char D_01DBCA80[];

// 0x002630F0
void * CB3EffectsManager::Alloc(unsigned int p0, unsigned int p1)
{
    unsigned int m = p1 - 1;
    unsigned int cur = _gnEffectsMemoryAllocation;
    unsigned int off = cur + m;
    off &= ~m;
    unsigned char *r = D_01DBCA80 + off;
    off += p0;
    _gnEffectsMemoryAllocation = off;
    return r;
}
