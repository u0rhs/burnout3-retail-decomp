// CB3ChatDisplayComponent::AddNewMessage(char*,const unsigned short*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ChatDisplayComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a126: goto into loop body, bool named set before RecalculateSize).

#include "b3/GtMathPs2.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.h"
using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;
enum EB3ChatDisplayOrientation {};
struct UnkStruct_D_01E903E0 { unsigned char pad_0[0x30]; };
struct UnkStruct_D_00665ED8 { CGt2dFont *pFont; unsigned char pad[0xC]; };
extern UnkStruct_D_01E903E0 D_01E903E0;
extern UnkStruct_D_00665ED8 D_00665ED8;
struct UnkStruct_Fmt { unsigned char pad_0[0x10]; };
extern UnkStruct_Fmt D_004C5748;
extern "C" int strlen(const char *);
extern "C" int snprintf(char *, int, const void *, ...);
extern "C" void ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(char *, unsigned short *, int);
extern "C" void RecalculateSize__16CGt2dObjectTableFv(void *);
extern "C" void *memcpy(void *, const void *, unsigned);

class CB3ChatDisplayComponent {
public:
    void CheckTextLengths(int p0);
    void AddNewMessage(char *p0, const unsigned short *p1);
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
    void *field_860;
};

// 0x00331FE0
void CB3ChatDisplayComponent::AddNewMessage(char *p0, const unsigned short *p1)
{
    int j;
    int rows = 10;
    bool named = false;
    char tmpbuf[0x11];
    const unsigned short *cur;
    const unsigned short *end;
    if (&D_01E903E0 == 0 || field_A == 0)
        return;
    float limit = (field_858.X() - (field_B4 + (field_AC + field_A8))) / 23.0f;
    cur = p1;
    D_00665ED8.pFont->GetStringStartAndEnd(p1, limit, &cur, &end, true);
    if (cur == end)
        return;
    for (;;) {
        rows--;
        for (j = 1; j < 10; j++) {
            memcpy(field_7EC[j], field_7EC[j + 1], 0x20);
            memcpy(field_7EC[10 + j], field_7EC[11 + j], 0x80);
        }
        if (!named) {
            if (strlen(p0) != 0) {
                snprintf(tmpbuf, 0x11, &D_004C5748, p0);
                ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(tmpbuf, field_7EC[10], 0x11);
                named = true;
                RecalculateSize__16CGt2dObjectTableFv(field_860);
                rows = 9;
                limit = (field_858.X() - (field_B4 + (field_AC + field_A8))) / 23.0f;
                goto cont;
            }
        }
        field_7EC[10][0] = 0x20;
        field_7EC[10][1] = 0;
cont:
        D_00665ED8.pFont->GetStringStartAndEnd(cur, limit, &cur, &end, true);
        if (cur == end)
            break;
        memcpy(field_7EC[20], cur, (end - cur) * 2);
        field_7EC[20][end - cur] = 0;
        cur = end;
        if (*cur == 0)
            break;
    }
    CheckTextLengths(rows - 1);
    RecalculateSize__16CGt2dObjectTableFv(field_860);
}
