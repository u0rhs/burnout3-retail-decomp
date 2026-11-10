// NONMATCHING: AddLink__11CGtFreeListFv -- retail 25 / ours 24 instructions, 4 in changed runs
// gaps1b: hand-drafted from the asm
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// gaps1b (2026-11-02): hand-drafted from the retail asm (0x2B6DA0). Takes a free link to the front of the list (0 when the pool
// is empty). The taken link's prev is left as it was when the list is empty [C 0x2B6DF4].
// Name: the asm symbol; config/symbol_addrs.txt says these come from Burnout 2's symbols, with the parameter types
// of GtLListPoolCalculateSize / GtLListPoolCreateInMemory changed upstream (Burnout 2: __Fiii, __FP14GtLListPoolTagPviiiPv).
// [L] research/retail_names.csv (B3's E map, high): CGtFreeList::AddLink().
// TRACK: clean
// EQUIV: [L] written from the retail asm: every branch, store and call accounted for

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

// 0x002B6DA0
extern "C" GtLLLinkTag * AddLink__11CGtFreeListFv(GtLListTag * list)
{
    GtLListPoolTag * p = list->field_0;
    GtLLLinkTag * l = p->field_10;
    if (l == 0) {
        return 0;
    }
    p->field_10 = l->field_0;
    if (l->field_0 != 0) {
        l->field_0->field_4 = 0;
    }
    if (list->field_4 != 0) {
        l->field_0 = list->field_4;
        l->field_0->field_4 = l;
    } else {
        l->field_0 = 0;
    }
    list->field_4 = l;
    return l;
}
