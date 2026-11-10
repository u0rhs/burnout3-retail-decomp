// CGtFreeList::TakeLinkFromList(CGtFreeListLink*,CGtFreeList*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtFreeList.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (gaps1b: hand-written from the asm, exact).

// gaps1b (2026-11-02): hand-drafted from the retail asm (0x2B6D20). Moves l from src to the front of dst.
// Name: the asm symbol; config/symbol_addrs.txt says these come from Burnout 2's symbols, with the parameter types
// of GtLListPoolCalculateSize / GtLListPoolCreateInMemory changed upstream (Burnout 2: __Fiii, __FP14GtLListPoolTagPviiiPv).
// [L] research/retail_names.csv (B3's E map, high): CGtFreeList::TakeLinkFromList(CGtFreeListLink*,CGtFreeList*).

// [C] layouts from the accesses: a link {next, prev, then the payload at +8}, a list {pool, head}, a pool {base, stride,
// count, align, free list}
struct GtLLLinkTag { GtLLLinkTag * field_0; GtLLLinkTag * field_4; };
struct GtLListPoolTag {
    GtLLLinkTag * field_0;        // the first link (base)
    unsigned int field_4;         // stride
    unsigned int field_8;         // count
    unsigned int field_C;         // alignment
    GtLLLinkTag * field_10;       // free links
};
struct GtLListTag { GtLListPoolTag * field_0; GtLLLinkTag * field_4; };

// 0x002B6D20
extern "C" void TakeLinkFromList__11CGtFreeListFP15CGtFreeListLinkP11CGtFreeList(GtLListTag * dst, GtLLLinkTag * l, GtLListTag * src)
{
    if (l->field_0 != 0) {
        l->field_0->field_4 = l->field_4;
    }
    if (l->field_4 != 0) {
        l->field_4->field_0 = l->field_0;
    } else if (l->field_0 != 0) {
        src->field_4 = l->field_0;
    } else {
        src->field_4 = 0;
    }
    if (dst->field_4 != 0) {
        l->field_0 = dst->field_4;
        l->field_0->field_4 = l;
    } else {
        l->field_0 = 0;
    }
    l->field_4 = 0;
    dst->field_4 = l;
}
