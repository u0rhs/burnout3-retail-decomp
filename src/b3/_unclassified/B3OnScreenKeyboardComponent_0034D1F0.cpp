// CB3OnScreenKeyboardComponent::MoveCursorLeft() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnScreenKeyboardComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (peeled first width test via do-while; arg reload via const-pointer pun [G]).

extern "C" {
unsigned short *CopyN__10CGtUnicodeFPUsiPCUs(unsigned short *, int, unsigned short *);
float GetStringWidth__9CGt2dFontCFPCUs(void *, const unsigned short *);
}
struct UnkStruct_D_00665ED8 { void *field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_00665ED8 D_00665ED8;
class CB3OnScreenKeyboardComponent {
public:
    void MoveCursorLeft();

    unsigned char pad_0[0xC];
    int field_C;
    unsigned char pad_10[0x30BC];
    unsigned short *field_30CC;
    unsigned short *field_30D0;
    unsigned short *field_30D4;
};
// 0x0034D1F0
void CB3OnScreenKeyboardComponent::MoveCursorLeft()
{
    unsigned short buf[0x40];
    if (field_C == 0) return;
    field_C = field_C - 1;
    int c = field_C;
    unsigned short *base = field_30D4;
    if (base + (c + 1) == field_30CC) {
        if (c > 10) field_30CC = base + (c - 0xA);
        else field_30CC = base;
    }
    if (*field_30CC == 0) return;
    CopyN__10CGtUnicodeFPUsiPCUs(buf, (field_30D0 - field_30CC) + 1, *(unsigned short *const *)&field_30CC);
    if (29.0f * GetStringWidth__9CGt2dFontCFPCUs(D_00665ED8.field_0, buf) <= 497) return;
    do {
        field_30D0 = field_30D0 - 1;
        if (field_30D0 == field_30CC) return;
        CopyN__10CGtUnicodeFPUsiPCUs(buf, (field_30D0 - field_30CC) + 1, *(unsigned short *const *)&field_30CC);
    } while (29.0f * GetStringWidth__9CGt2dFontCFPCUs(D_00665ED8.field_0, buf) > 497);
}
