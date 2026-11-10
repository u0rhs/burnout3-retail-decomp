// CB3OnScreenKeyboardComponent::FindKey(unsigned short,CB3OnScreenKeyboardCell*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnScreenKeyboardComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (FindKey: globals read inline in ternary).

extern "C" {
int FindUTFChar__15CGtUnicodeUtilsFPUsUs(void *, unsigned short);
}
class CB3OnScreenKeyboardCell { public: int field_0; int field_4; };
struct UnkStruct_kKey { CB3OnScreenKeyboardCell c; int pad[2]; };
extern const UnkStruct_kKey kB3OnScreenKeyboardLeftArrowKey;
extern const UnkStruct_kKey kB3OnScreenKeyboardBackspaceKey;
struct UnkStruct_row { unsigned char pad_0[0x30DC]; void *k[15]; };
class CB3OnScreenKeyboardComponent {
public:
    bool FindKey(unsigned short, CB3OnScreenKeyboardCell *);
    unsigned char pad_0[0x30DC];
    void *field_30DC[4][15];
};
// 0x0034D6F0
bool CB3OnScreenKeyboardComponent::FindKey(unsigned short ch, CB3OnScreenKeyboardCell *out)
{
    int row = 1; int col;
    for (row = 1; row < 4; row++) {
        int lim = row < 3 ? kB3OnScreenKeyboardLeftArrowKey.c.field_4 : kB3OnScreenKeyboardBackspaceKey.c.field_4;
        char *rp = (char *)this + row * 60;
        for (col = 2; col < lim; col++) {
            if (FindUTFChar__15CGtUnicodeUtilsFPUsUs(*(void **)(rp + 0x30DC + col * 4), ch) != 0) {
                out->field_0 = row; out->field_4 = col; return true;
            }
        }
    }
    for (row = 1; row < 4; row++) {
        char *rp = (char *)this + row * 60;
        for (col = 12; col < 15; col++) {
            if (FindUTFChar__15CGtUnicodeUtilsFPUsUs(*(void **)(rp + 0x30DC + col * 4), ch) != 0) {
                out->field_0 = row; out->field_4 = col; return true;
            }
        }
    }
    if (ch == 0x30) {
        *out = kB3OnScreenKeyboardLeftArrowKey.c;
        out->field_4 = out->field_4 + 1;
        return true;
    }
    return false;
}
