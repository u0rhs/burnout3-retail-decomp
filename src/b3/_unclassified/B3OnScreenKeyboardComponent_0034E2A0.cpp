// CB3OnScreenKeyboardComponent::KeyboardCharacterCallback(char,void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnScreenKeyboardComponent.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (static cb; case order 10,8,0x20; 4-byte slot for ushort out).

extern "C" {
void ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(char *, unsigned short *, int);
int func_00271A00(void *, int);
void *FindUTFChar__15CGtUnicodeUtilsFPUsUs(void *, int);
}
struct UnkStruct_D_01E8E8AA { unsigned char field_0; unsigned char pad_1[0xF]; };
extern UnkStruct_D_01E8E8AA D_01E8E8AA;
struct UnkStruct_D_0051BA44 { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_0051BA44 D_0051BA44;
class CB3OnScreenKeyboardCell { public: int field_0; int field_4; };
struct UnkStruct_kKey { CB3OnScreenKeyboardCell c; int pad[2]; };
extern const UnkStruct_kKey kB3OnScreenKeyboardDoneKey;
extern const UnkStruct_kKey kB3OnScreenKeyboardBackspaceKey;
extern const UnkStruct_kKey kB3OnScreenKeyboardSpaceKey;
class CB3OnScreenKeyboardComponent {
public:
    static void KeyboardCharacterCallback(char, void *);
    void PressKey(CB3OnScreenKeyboardCell);
    bool FindKey(unsigned short, CB3OnScreenKeyboardCell *);
    void AddCharToString(unsigned short);

    unsigned char pad_0[0x3208];
    int field_3208;
};
// 0x0034E2A0
void CB3OnScreenKeyboardComponent::KeyboardCharacterCallback(char c, void *p)
{
    CB3OnScreenKeyboardComponent *self = (CB3OnScreenKeyboardComponent *)p;
    char s[2];
    struct { unsigned short h; unsigned short pad; } wv;
    CB3OnScreenKeyboardCell cell;
    if (D_01E8E8AA.field_0 != 0) return;
    switch (c) {
    case 10:
        self->PressKey(kB3OnScreenKeyboardDoneKey.c);
        break;
    case 8:
        self->PressKey(kB3OnScreenKeyboardBackspaceKey.c);
        break;
    case 0x20:
        self->PressKey(kB3OnScreenKeyboardSpaceKey.c);
        break;
    default:
        s[0] = c;
        s[1] = 0;
        ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(s, &wv.h, 2);
        if (FindUTFChar__15CGtUnicodeUtilsFPUsUs((void *)(func_00271A00(&D_0051BA44, self->field_3208)), wv.h) != 0) {
            if (self->FindKey(wv.h, &cell)) self->PressKey(cell);
            else self->AddCharToString(wv.h);
        }
    }
}
