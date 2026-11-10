// CB3OnScreenKeyboardComponent::SetDisplayText(char*,bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnScreenKeyboardComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi into stack buf; same loop).

extern "C" {
unsigned short *CopyN__10CGtUnicodeFPUsiPCUs(unsigned short *, int, unsigned short *);
int Length__10CGtUnicodeFPCUs(unsigned short *);
void ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(char *, unsigned short *, int);
}
class CB3OnScreenKeyboardComponent {
public:
    void SetDisplayText(char *, bool);
    void MoveCursorRight();

    unsigned char pad_0[0xC];
    int field_C;
    unsigned char pad_10[0xD];
    bool field_1D;
    unsigned char pad_1E[0x30B2];
    unsigned short *field_30D0;
    unsigned short *field_30D4;
    unsigned char pad_30D8[0x134];
    int field_320C;
};
// 0x0034CF90
void CB3OnScreenKeyboardComponent::SetDisplayText(char *text, bool flag)
{
    unsigned short buf[0x40];
    ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(text, buf, 0x40);
    CopyN__10CGtUnicodeFPUsiPCUs(field_30D4, 0x40, buf);
    field_30D0 = field_30D4 + Length__10CGtUnicodeFPCUs(field_30D4);
    int c = field_C;
    while (c != Length__10CGtUnicodeFPCUs(field_30D4) && c < field_320C && !flag) {
        MoveCursorRight();
        c = field_C;
    }
    field_1D = flag;
}
