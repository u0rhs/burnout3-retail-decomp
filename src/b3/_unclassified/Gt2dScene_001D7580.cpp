// CGt2dScene::ConstructObject(int,CGt2dFrame*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> Gt2dScene.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (seeded whole-file function as is, 0 off as its own unit (gt2d, N167)).

#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dScene.h"

extern "C" char *func_001D4680(CGt2dFrameHierarchy*, int, void*, unsigned int);

// 0x1D7580: the object lives right after its link
// 0x001D7580
CGt2dObject* CGt2dScene::ConstructObject(int layer, CGt2dFrame* frame)
{
    CGtFreeListLink* link = field_2c[layer].field_4.AddLink();
    CGt2dObject* object = (CGt2dObject*)link->GetData();
    object->mpFrame = frame;
    return object;
}
