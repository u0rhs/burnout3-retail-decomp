// NONMATCHING: _GetRequiredMemory__15CGtFreeListPoolFUiUiUi -- retail 10 / ours 10 instructions, 4 in changed runs
// gaps1b: hand-drafted from the asm
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// gaps1b (2026-11-02): hand-drafted from the retail asm (0x2B6EC0). n links of (size + 8) rounded up
// to align, plus align for the start alignment.
// Name: the asm symbol; config/symbol_addrs.txt says these come from Burnout 2's symbols, with the parameter types
// of GtLListPoolCalculateSize / GtLListPoolCreateInMemory changed upstream (Burnout 2: __Fiii, __FP14GtLListPoolTagPviiiPv).
// [L] research/retail_names.csv (B3's E map, high): CGtFreeListPool::_GetRequiredMemory(unsigned int,unsigned int,unsigned int).
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

// 0x002B6EC0
extern "C" unsigned int _GetRequiredMemory__15CGtFreeListPoolFUiUiUi(unsigned int n, unsigned int size, unsigned int align)
{
    unsigned int s = size + 8;
    if (align != 0) {
        s = ~(align - 1) & (size + 8 + align - 1);
    }
    return align + s * n;
}
