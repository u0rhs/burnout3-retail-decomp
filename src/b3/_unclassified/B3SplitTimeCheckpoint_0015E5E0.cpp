// CB3SplitTimeCheckpoint::Draw() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SplitTimeCheckpoint.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

#include "b3/GtMathPs2.h"

class CGtTexture;

class CB3SplitTimeCheckpoint;

class CB3SplitTimeCheckpoint {
public:
    void Draw();
    void DrawCheckpoint(CGtTexture*, GtMathPs2::CGtV4d);

    unsigned char pad_0[0x4];
    int field_4;
};

// 0x0015E5E0
void CB3SplitTimeCheckpoint::Draw()
{
    DrawCheckpoint((CGtTexture*)field_4, GtMathPs2::CGtV4d(0.375f, 0.125f, 0.125f, 1.0f));
}
