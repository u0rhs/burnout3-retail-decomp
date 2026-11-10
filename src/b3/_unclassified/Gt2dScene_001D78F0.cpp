// CGt2dScene::Prepare() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> Gt2dScene.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (seeded whole-file function as is, 0 off as its own unit (gt2d, N167)).

#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dScene.h"

extern "C" char *func_001D4680(CGt2dFrameHierarchy*, int, void*, unsigned int);

// 0x1D78F0
// 0x001D78F0
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
