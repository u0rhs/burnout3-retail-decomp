// CGt2dObjectTable::Prepare(const CGt2dObjectTableData*,const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,const GtMathPs2::CGtV2d&,GtMathPs2::CGtV4d) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> Gt2dObjectTable.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (extern C mangled, Image::Prepare sibling shape, base Prepare(pos-size*anchor)).

#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"

using namespace GtMathPs2;

class CGt2dObjectTableData;
struct UnkStruct_Gt2dObjectTable_20 {
    CGtV2d field_0;
    CGtV2d field_8;
    const CGt2dObjectTableData *field_10;
    unsigned int field_14;
};

class CGt2dObjectTable : public CGt2dObject {
public:
    UnkStruct_Gt2dObjectTable_20 &Data() { return *(UnkStruct_Gt2dObjectTable_20 *)mauDataBlock; }
    static void _Render(const CGt2dObjectSpace &, const void *);
    void RecalculateSize();
};

extern "C" void Prepare__16CGt2dObjectTableFPC20CGt2dObjectTableDataRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4d(
    CGt2dObjectTable *self, const CGt2dObjectTableData *data, const CGtV2d &pos, const CGtV2d &anchor, const CGtV2d &size, const CGtV4d colour)
{
    self->Data().field_10 = data;
    self->Data().field_14 = (unsigned int)self->mpFrame;
    self->Data().field_0 = pos;
    self->Data().field_8 = anchor;
// 0x0033F0E0
    self->CGt2dObject::Prepare(pos - size * anchor, size, colour, CGt2dObjectTable::_Render, 0x40, 0x18);
    self->RecalculateSize();
}
