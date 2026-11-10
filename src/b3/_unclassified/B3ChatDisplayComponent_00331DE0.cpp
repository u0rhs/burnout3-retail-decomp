// CB3ChatDisplayComponent::CheckTextLengths(int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ChatDisplayComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a126: first try; do-while wrap loop).

#include "b3/GtMathPs2.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.h"
using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;
enum EB3ChatDisplayOrientation {};
struct UnkStruct_D_01E903E0 { unsigned char pad_0[0x30]; };
struct UnkStruct_D_00665ED8 { CGt2dFont *pFont; unsigned char pad[0xC]; };
extern UnkStruct_D_01E903E0 D_01E903E0;
extern UnkStruct_D_00665ED8 D_00665ED8;
extern "C" void *memcpy(void *, const void *, unsigned);

class CB3ChatDisplayComponent {
public:
    void CheckTextLengths(int p0);
    unsigned char pad_0[0xA];
    unsigned char field_A;
    unsigned char pad_B[0x9D];
    float field_A8;
    float field_AC;
    unsigned char pad_B0[4];
    float field_B4;
    unsigned char pad_B8[0x734];
    unsigned short *field_7EC[21];
    CGtV2d field_840;
    CGtV2d field_848;
    CGtV2d field_850;
    CGtV2d field_858;
};

// 0x00331DE0
void CB3ChatDisplayComponent::CheckTextLengths(int p0)
{
    if (&D_01E903E0 == 0 || field_A == 0)
        return;
    float limit = (field_858.X() - (field_B4 + (field_AC + field_A8))) / 23.0f;
    for (int i = p0; i > 0; i--) {
        unsigned short *text = field_7EC[11 + i];
        if (text[0] == 0)
            continue;
        if (D_00665ED8.pFont->GetStringWidth(text) <= limit)
            continue;
        unsigned short buf[0x40];
        const unsigned short *cur;
        const unsigned short *end;
        memcpy(buf, field_7EC[11 + i], 0x80);
        cur = buf;
        do {
            D_00665ED8.pFont->GetStringStartAndEnd(cur, limit, &cur, &end, true);
            if (cur == end)
                break;
            memcpy(field_7EC[11 + i], cur, (end - cur) * 2);
            field_7EC[11 + i][end - cur] = 0;
            cur = end;
            if (*cur != 0) {
                for (int j = 1; j <= i; j++) {
                    memcpy(field_7EC[j], field_7EC[j + 1], 0x20);
                    memcpy(field_7EC[10 + j], field_7EC[10 + j + 1], 0x80);
                }
                field_7EC[i + 1][0] = 0x20;
                field_7EC[i + 1][1] = 0;
            }
        } while (*end != 0);
    }
}
