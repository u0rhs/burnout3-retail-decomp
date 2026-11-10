// CB3ChatDisplayComponent::SetOrientation(EB3ChatDisplayOrientation) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ChatDisplayComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (rewritten with CGtV2d members/consts: per-case struct copies, id=0 default, tl declared up front then tl = pos - size*handle, SetY(2+Y), frame pos/size copies).

// CB3ChatDisplayComponent::SetOrientation(EB3ChatDisplayOrientation)
#include "b3/GtMathPs2.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

enum EB3ChatDisplayOrientation {};
class CGt2dObjectTableData;

struct UnkStruct_00332610_frame {
    CGtV2d field_0;
    CGtV2d field_8;
};

struct UnkStruct_D_01E90240 {
    unsigned char pad_0[0x100];
    CGtV4d field_100;
};

class CB3ChatDisplayComponent {
public:
    void SetOrientation(EB3ChatDisplayOrientation p0);
    void CheckTextLengths(int);

    unsigned char pad_0[0x10];
    CGtV2d field_10;
    unsigned char pad_18[0x90];
    float field_A8;
    unsigned char pad_AC[0x794];
    CGtV2d field_840;
    CGtV2d field_848;
    CGtV2d field_850;
    CGtV2d field_858;
    void * field_860;
    void * field_864;
    UnkStruct_00332610_frame * field_868;
};

extern const CGtV2d kB3ChatDisplayTopPos;
extern const CGtV2d kB3ChatDisplayTopHandle;
extern const CGtV2d kB3ChatDisplayTopSize;
extern const CGtV2d kB3ChatDisplayTopMaxSize;
extern const CGtV2d kB3ChatDisplayRightPos;
extern const CGtV2d kB3ChatDisplayRightHandle;
extern const CGtV2d D_004C5700;  // [L] kB3ChatDisplayRightSize in the E build's map (same slot after RightHandle)
extern const CGtV2d D_004C5708;
extern const CGtV2d D_004C5710;
extern const CGtV2d D_004C5718;
extern const CGtV2d D_004C5720;
extern const CGtV2d kB3ChatDisplayLobbyPos;
extern const CGtV2d kB3ChatDisplayLobbyHandle;
extern const CGtV2d kB3ChatDisplayLobbySize;
extern const CGtV2d kB3ChatDisplayLobbyMaxSize;
extern UnkStruct_D_01E90240 D_01E90240;

extern "C" void Prepare__16CGt2dObjectTableFPC20CGt2dObjectTableDataRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4d(void *, const CGt2dObjectTableData *, const CGtV2d &, const CGtV2d &, const CGtV2d &, CGtV4d);
extern "C" bool Prepare__23CB3RoundedPanel2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dUi(void *, const CGtV2d &, const CGtV2d &, const CGtV2d &, unsigned int, int);  // passed 1 more argument [G]

// 0x00332610
void CB3ChatDisplayComponent::SetOrientation(EB3ChatDisplayOrientation p0)
{
    UnkStruct_D_01E90240 * const mgr = &D_01E90240;
    CGtV2d tl;  // declared up front and assigned later: the operator- result gets its own slot (retail frame layout)
    unsigned int id = 0;
    switch (p0) {
    case 0:
        field_840 = kB3ChatDisplayTopPos;
        field_848 = kB3ChatDisplayTopHandle;
        field_850 = kB3ChatDisplayTopSize;
        field_858 = kB3ChatDisplayTopMaxSize;
        field_10 = field_858;
        field_A8 = 16.0f;
        id = 29;
        break;
    case 1:
        field_840 = kB3ChatDisplayRightPos;
        field_848 = kB3ChatDisplayRightHandle;
        field_850 = D_004C5700;
        field_858 = D_004C5700;
        field_10 = field_858;
        field_A8 = 9.0f;
        id = 30;
        break;
    case 2:
        field_840 = D_004C5708;
        field_848 = D_004C5710;
        field_850 = D_004C5718;
        field_858 = D_004C5720;
        field_10 = field_858;
        field_A8 = 80.0f;
        break;
    case 3:
        field_840 = kB3ChatDisplayLobbyPos;
        field_848 = kB3ChatDisplayLobbyHandle;
        field_850 = kB3ChatDisplayLobbySize;
        field_858 = kB3ChatDisplayLobbyMaxSize;
        field_10 = field_858;
        field_A8 = 80.0f;
        break;
    }
    Prepare__16CGt2dObjectTableFPC20CGt2dObjectTableDataRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4d(
        field_860, (const CGt2dObjectTableData *)&field_10, CGtV2d(field_840.X(), field_840.Y() - 1.0f), field_848, field_858, mgr->field_100);
    tl = field_840 - field_850 * field_848;
    tl.SetY(2.0f + tl.Y());
    field_868->field_0 = tl;
    field_868->field_8 = CGtV2d(field_850.X(), field_850.Y());
    Prepare__23CB3RoundedPanel2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dUi(field_864, field_840, field_848, field_850, id, 0);
    CheckTextLengths(9);
}
