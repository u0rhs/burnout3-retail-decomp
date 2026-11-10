// NONMATCHING: Construct__15CGtFreeListPoolFUiUiUiPCvPvUi -- retail 62 / ours 62 instructions, 21 in changed runs
// gaps1b: hand-drafted from the asm
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// gaps1b (2026-11-02): hand-drafted from the retail asm (0x2B6EF0). Lays count
// links of size payload bytes out in mem (aligned; align 0 -> 1), all on the free list, each payload copied from init
// when given.
// Name: the asm symbol; config/symbol_addrs.txt says these come from Burnout 2's symbols, with the parameter types
// of GtLListPoolCalculateSize / GtLListPoolCreateInMemory changed upstream (Burnout 2: __Fiii, __FP14GtLListPoolTagPviiiPv).
// [L] research/retail_names.csv (B3's E map, high): CGtFreeListPool::Construct(unsigned int,unsigned int,unsigned int,const void*,void*,unsigned int) (medium).
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

// 0x002B6EF0
extern "C" void Construct__15CGtFreeListPoolFUiUiUiPCvPvUi(GtLListPoolTag * p, unsigned int count, unsigned int size, unsigned int align,
                               const void * init, void * mem)
{
    if (align == 0) {
        p->field_C = 1;
    } else {
        p->field_C = align;
    }
    if (count == 0) {
        p->field_0 = 0;
        p->field_4 = size;
        p->field_8 = 0;
        p->field_10 = 0;
        return;
    }
    GtLLLinkTag * first = (GtLLLinkTag *)((((unsigned int)mem + 7 + p->field_C) & ~(p->field_C - 1)) - 8);
    p->field_0 = first;
    p->field_10 = first;
    unsigned int stride = ~(p->field_C - 1) & (size + 8 + p->field_C - 1);
    GtLLLinkTag * c = p->field_10;
    c->field_4 = 0;
    for (unsigned int i = 1; i < count; i++) {
        GtLLLinkTag * prev = c;
        c = (GtLLLinkTag *)((unsigned char *)c + stride);
        prev->field_0 = c;
        c->field_4 = prev;
    }
    c->field_0 = 0;
    if (init != 0) {
        for (GtLLLinkTag * l = p->field_10; l != 0; l = l->field_0) {
            unsigned char * d = (unsigned char *)l + 8;
            const unsigned char * s = (const unsigned char *)init;
            for (unsigned int k = size; k != 0; k--) {
                *d++ = *s++;
            }
        }
    }
    p->field_4 = stride;
    p->field_8 = count;
}
