// CGtFreeList / CGtFreeListPool / CGtFreeListLink (E map: GtFreeList.cpp) as our sources use them.
// The functions are linked under upstream's names (their d4/pool unit, Burnout 2-era names, unaudited:
// docs/upstream.md); the E-map methods below are inline wrappers so our sources read with Criterion's names while the
// object code calls the symbols the build has. When upstream's unit is audited, only this header changes.
// Header name/folder: project convention (K18/K19).
#ifndef B3_GTFREELIST_H
#define B3_GTFREELIST_H

#include "b3/B3Ptr.h"

// Upstream's link names (mangled exactly as their C units define them).
struct GtLListTag;
struct GtLLLinkTag;
struct GtLListPoolTag;
extern "C" GtLLLinkTag* AddLink__11CGtFreeListFv(GtLListTag*);
extern "C" void RemoveLink__11CGtFreeListFP15CGtFreeListLink(GtLListTag*, GtLLLinkTag*);
extern "C" void RemoveAllLinks__11CGtFreeListFv(GtLListTag*);
extern "C" void Construct__11CGtFreeListFP15CGtFreeListPool(GtLListTag*, GtLListPoolTag*);
extern "C" void SortFree__15CGtFreeListPoolFv(GtLListPoolTag*);
extern "C" unsigned int _GetRequiredMemory__15CGtFreeListPoolFUiUiUi(unsigned int, unsigned int, unsigned int);
// Upstream's GtLListPoolCreateInMemory(GtLListPoolTag*, Ui, Ui, Ui, const void*, void*) by its symbol, with the
// parameter Burnout 3 really has (E map: CGtFreeListPool::Construct(..., unsigned int)); extern "C" = that exact symbol.
class CGtFreeListPool;
extern "C" void Construct__15CGtFreeListPoolFUiUiUiPCvPvUi(CGtFreeListPool*, unsigned int, unsigned int,
                                                                        unsigned int, const void*, void*, unsigned int);

class CGtFreeListLink {
public:
    B3_PTR(CGtFreeListLink) field_0;         // [C] next link (CGt2dScene::Render walks +0x0)
    unsigned int field_4;                    // not seen yet
    void* GetData() { return this + 1; }     // E map: CGtFreeListLink::GetData() const; data follows the 8-byte link [C]
};
B3_CHECK_SIZE(CGtFreeListLink, 0x8);

class CGtFreeListPool {
public:
    // E map: CGtFreeListPool::_GetRequiredMemory(unsigned int, unsigned int, unsigned int) (static) = upstream's
    // GtLListPoolCalculateSize
    static unsigned int _GetRequiredMemory(unsigned int count, unsigned int size, unsigned int align)
    {
        return _GetRequiredMemory__15CGtFreeListPoolFUiUiUi(count, size, align);
    }
    // E map: CGtFreeListPool::Construct(unsigned int, unsigned int, unsigned int, const void*, void*, unsigned int):
    // the 6th parameter (memory size) is missing from upstream's Burnout 2-era GtLListPoolCreateInMemory, so it is called
    // through the symbol declared above with 7 parameters.
    void Construct(unsigned int count, unsigned int size, unsigned int align, const void* init, void* memory,
                   unsigned int memorySize)
    {
        Construct__15CGtFreeListPoolFUiUiUiPCvPvUi(this, count, size, align, init, memory, memorySize);
    }
    void SortFree() { SortFree__15CGtFreeListPoolFv((GtLListPoolTag*)this); }   // E map: CGtFreeListPool::SortFree()
    unsigned char field_0[0x14];             // [C] size 0x14 (CGt2dScene: pool at +0x18, next member +0x2C)
};
B3_CHECK_SIZE(CGtFreeListPool, 0x14);

class CGtFreeList {
public:
    void Construct(CGtFreeListPool* pool) { Construct__11CGtFreeListFP15CGtFreeListPool((GtLListTag*)this, (GtLListPoolTag*)pool); }
    CGtFreeListLink* AddLink() { return (CGtFreeListLink*)AddLink__11CGtFreeListFv((GtLListTag*)this); }
    void RemoveLink(CGtFreeListLink* link) { RemoveLink__11CGtFreeListFP15CGtFreeListLink((GtLListTag*)this, (GtLLLinkTag*)link); }
    void RemoveAllLinks() { RemoveAllLinks__11CGtFreeListFv((GtLListTag*)this); }
    CGtFreeListLink* GetFirstLink() { return field_4; }   // E map: CGtFreeList::GetFirstLink() const [L: +0x4 per Render]
    unsigned int field_0;                    // not seen yet
    B3_PTR(CGtFreeListLink) field_4;         // [C] first link (CGt2dScene::Render reads layer +0x8 = list +0x4)
};
B3_CHECK_SIZE(CGtFreeList, 0x8);

#endif
