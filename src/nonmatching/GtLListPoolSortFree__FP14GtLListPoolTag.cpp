// NONMATCHING: SortFree__15CGtFreeListPoolFv -- retail 38 / ours 40 instructions, 21 in changed runs
// gaps1b: hand-drafted from the asm
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// gaps1b (2026-11-02): hand-drafted from the retail asm (0x2B6E20). Rebuilds the free list in address order: marks the free
// links (prev = 1), then walks the pool by stride relinking the marked ones.
// Name: the asm symbol; config/symbol_addrs.txt says these come from Burnout 2's symbols, with the parameter types
// of GtLListPoolCalculateSize / GtLListPoolCreateInMemory changed upstream (Burnout 2: __Fiii, __FP14GtLListPoolTagPviiiPv).
// [L] research/retail_names.csv (B3's E map, high): CGtFreeListPool::SortFree().
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

// 0x002B6E20
extern "C" void SortFree__15CGtFreeListPoolFv(GtLListPoolTag * p)
{
    if (p->field_0 == 0) {
        return;
    }
    GtLLLinkTag * f = p->field_10;
    if (f == 0) {
        return;
    }
    int n = 0;
    do {
        f->field_4 = (GtLLLinkTag *)1;
        n++;
        f = f->field_0;
    } while (f != 0);
    GtLLLinkTag * c = p->field_0;
    GtLLLinkTag * last = 0;
    for (;;) {
        while (c->field_4 != (GtLLLinkTag *)1) {
            c = (GtLLLinkTag *)((unsigned char *)c + p->field_4);
        }
        if (last != 0) {
            last->field_0 = c;
            c->field_4 = last;
        } else {
            p->field_10 = c;
            c->field_4 = 0;
        }
        n--;
        last = c;
        if (n == 0) {
            c->field_0 = 0;
            return;
        }
        c = (GtLLLinkTag *)((unsigned char *)c + p->field_4);
    }
}
