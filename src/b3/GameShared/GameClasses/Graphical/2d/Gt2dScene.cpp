// NOT WIRED IN, NOT PROVEN HERE: seeded partial from the earlier research repo (`linked: false` there; docs/known.md N16). Its
// functions (e.g. DestructObject) are still asm in the build.
// Gt2dScene.cpp (E map), retail 0x1D7560-0x1D7A70: the whole file. Local fork unit (docs/conventions.md "Original structure").
// Render (0x1D75C0) not written yet: it needs VU0 colour helpers (vmul/vmini) not reconstructed yet.
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dScene.h"

// The frame hierarchy's own set-up (0x1D4680), name not recovered: (hierarchy, frames, memory, memory size) [L].
extern "C" char *func_001D4680(CGt2dFrameHierarchy*, int, void*, unsigned int);

// 0x1D7560
void CGt2dScene::DestructObject(int layer, CGt2dObject* object)
{
    field_2c[layer].field_4.RemoveLink((CGtFreeListLink*)object - 1);
}

// 0x1D7580: the object lives right after its link
CGt2dObject* CGt2dScene::ConstructObject(int layer, CGt2dFrame* frame)
{
    CGtFreeListLink* link = field_2c[layer].field_4.AddLink();
    CGt2dObject* object = (CGt2dObject*)link->GetData();
    object->mpFrame = frame;
    return object;
}

// 0x1D78F0
void CGt2dScene::Prepare()
{
    for (int i = 0; i < field_30; i++) {
        UnkStruct_Gt2dScene_2C& layer = field_2c[i];
        layer.field_0 = 0;
        layer.field_c = 0;
        layer.field_4.RemoveAllLinks();
    }
    CGt2dFrameHierarchy::Prepare();
    field_18.SortFree();
}

// 0x1D7960: carve the memory: layer records, the object pool, then the frame hierarchy's share
void CGt2dScene::Construct(int numLayers, int maxObjects, int frames, void* memory, unsigned int memorySize)
{
    unsigned int layersSize = (numLayers * sizeof(UnkStruct_Gt2dScene_2C) + 15) & ~15;
    unsigned int poolSize = (CGtFreeListPool::_GetRequiredMemory(maxObjects, 0x40, 0x10) + 15) & ~15;
    char* pool = (char*)memory + layersSize;
    unsigned int left = memorySize - layersSize;
    field_2c = (UnkStruct_Gt2dScene_2C*)memory;
    field_30 = numLayers;
    field_18.Construct(maxObjects, 0x40, 0x10, 0, pool, left);
    func_001D4680(this, frames, pool + poolSize, left - poolSize);
    for (int i = 0; i < numLayers; i++) {
        UnkStruct_Gt2dScene_2C& layer = field_2c[i];
        layer.field_0 = 0;
        layer.field_c = 0;
        layer.field_4.Construct(&field_18);
    }
}
