// CB3SparkRenderer::Prepare() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SparkRendererPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (nested loop of CGtV4d::SetX(float) over 2 rows x 0x12 elems (0x60 stride); header SetX hoists qmtc2.ni by itself).

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
struct UnkStruct_00263B80_e { unsigned char pad_0[0x50]; CGtV4d field_50; unsigned char pad_60[0x0]; };
struct UnkStruct_00263B80_row { UnkStruct_00263B80_e field_0[0x12];  };
struct UnkStruct_D_01E31A30 { UnkStruct_00263B80_row field_0[2]; };
struct UnkStruct_D_00522680 { float field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_01E31A30 D_01E31A30;
extern UnkStruct_D_00522680 D_00522680;
class CB3SparkRenderer { public: int Prepare(); };
// 0x00263B80
int CB3SparkRenderer::Prepare()
{
    float v = D_00522680.field_0;
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < 0x12; i++) {
            D_01E31A30.field_0[j].field_0[i].field_50.SetX(v);
        }
    }
    return 1;
}
