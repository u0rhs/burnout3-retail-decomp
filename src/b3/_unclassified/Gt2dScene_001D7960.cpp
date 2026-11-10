// CGt2dScene::Construct(int,int,int,void*,unsigned int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> Gt2dScene.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a95's match; seeded member form from Gt2dScene.cpp, installed by gt2d (N167)).

#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dScene.h"

extern "C" char *func_001D4680(CGt2dFrameHierarchy*, int, void*, unsigned int);

// 0x1D7960: carve the memory: layer records, the object pool, then the frame hierarchy's share
// 0x001D7960
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
