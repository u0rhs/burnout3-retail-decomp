// CB3OnScreenKeyboardComponent::AddCharToString(unsigned short) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnScreenKeyboardComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (AddCharToString; [G] int pun on field_C test).

#include "b3/classes/CB3MenuFlowFSM.h"
extern "C" {
void *memset(void *, int, unsigned int);
int Length__10CGtUnicodeFPCUs(const unsigned short *);
unsigned short *CopyN__10CGtUnicodeFPUsiPCUs(unsigned short *, int, unsigned short *);
int AppendN__10CGtUnicodeFPUsiPCUs(unsigned short *, int, unsigned short *);
unsigned short *PrintUTFChar__15CGtUnicodeUtilsFPUsUs(unsigned short *, unsigned short);
}
extern CB3MenuFlowFSM D_01EA2970;
class CB3OnScreenKeyboardComponent {
public:
    void AddCharToString(unsigned short);
    void MoveCursorLeft();
    void MoveCursorRight();
    unsigned char pad_0[0xC];
    int field_C;
    unsigned char pad_10[0xD];
    unsigned char field_1D;
    unsigned char field_1E;
    unsigned char pad_1F;
    int field_20;
    unsigned char pad_24[0x30A8];
    unsigned short *field_30CC;
    unsigned short *field_30D0;
    unsigned short *field_30D4;
    unsigned char pad_30D8[0x134];
    int field_320C;
};
// 0x0034D910
void CB3OnScreenKeyboardComponent::AddCharToString(unsigned short ch)
{
    unsigned short buf[0x40];
    if (field_1D != 0 && ch != 10) {
        field_1D = 0;
        memset(field_30D4, 0, 0x40);
        field_30CC = field_30D4;
        field_30D0 = field_30D4;
        field_C = 0;
    }
    switch (ch) {
    case 10:
        D_01EA2970.ApplyEvent(0x1B, 0);
        *field_30D4 = 0;
        field_C = 0;
        field_30CC = field_30D4;
        field_30D0 = field_30D4;
        break;
    case 8:
        if (*(const int *)&field_C > 0) {
            unsigned short *r = CopyN__10CGtUnicodeFPUsiPCUs(buf, field_C, field_30D4);
            AppendN__10CGtUnicodeFPUsiPCUs(r, field_320C, field_30D4 + field_C);
            CopyN__10CGtUnicodeFPUsiPCUs(field_30D4, field_320C, buf);
            field_30D0 = field_30D0 - 1;
            MoveCursorLeft();
            field_1E = 1;
            field_20 = 0;
        }
        break;
    case 7: case 9: case 11: case 12: case 13:
        break;
    default:
        if (Length__10CGtUnicodeFPCUs(field_30D4) < field_320C - 1) {
            unsigned short *r = CopyN__10CGtUnicodeFPUsiPCUs(buf, field_C + 1, field_30D4);
            AppendN__10CGtUnicodeFPUsiPCUs(PrintUTFChar__15CGtUnicodeUtilsFPUsUs(r, ch), field_320C, field_30D4 + field_C);
            CopyN__10CGtUnicodeFPUsiPCUs(field_30D4, field_320C, buf);
            field_30D0 = field_30D0 + 1;
            MoveCursorRight();
        }
    }
}
