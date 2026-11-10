// CGt2dScene::DestructObject(int,CGt2dObject*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> Gt2dScene.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (seeded whole-file function as is, 0 off as its own unit (gt2d, N167)).

#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dScene.h"

extern "C" char *func_001D4680(CGt2dFrameHierarchy*, int, void*, unsigned int);

// 0x1D7560
// 0x001D7560
void CGt2dScene::DestructObject(int layer, CGt2dObject* object)
{
    field_2c[layer].field_4.RemoveLink((CGtFreeListLink*)object - 1);
}
