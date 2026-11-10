// CB3OnlineSelectPersonaPage::OnKeyboardDone() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineSelectPersonaPage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (rewritten: whole body inside if (field_8C == 2), char field_D0[32], length checks as two if blocks with error arm written twice, shared trailing Show).

// lifter variant 0
// CB3OnlineSelectPersonaPage::OnKeyboardDone() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineSelectPersonaPage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3OnScreenKeyboardComponent;
class CB3OnlineSelectPersonaPage;
class CGtLobbyPS2DirtySock;
struct UnkStruct_003404B0_4;
struct UnkStruct_D_01E898E8;
struct UnkStruct_D_01E898F2;
struct UnkStruct_D_01E8CA94;

class CB3OnScreenKeyboardComponent {
public:
    void Show(bool, bool);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CGtLobbyPS2DirtySock {
public:
    void CreatePersona(char*);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8CA94 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E898F2 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E898E8 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003404B0_4 {
    unsigned char pad_0[0xC];
    int field_C;
};

class CB3OnlineSelectPersonaPage {
public:
    void OnKeyboardDone();

    unsigned char pad_0[0x8C];
    int field_8C;
    unsigned char pad_90[0x40];
    char field_D0[0x20];
};

extern UnkStruct_D_01E8CA94 D_01E8CA94;
extern UnkStruct_D_01E898F2 D_01E898F2;
extern UnkStruct_D_01E898E8 D_01E898E8;
extern CB3OnScreenKeyboardComponent D_01E899C0;
extern CGtLobbyPS2DirtySock D_01E3CD44;

extern "C" unsigned int strlen(const char *);
extern "C" int Length__10CGtUnicodeFPCUs(int);
extern "C" void ConvertUTF16toUTF8Fast__10CGtUnicodeFPCUsPUci(int, void *, int);
extern "C" void func_0032D080(void *, int, int, int, int);
extern "C" char * strchr(const char *, int);

// 0x003404B0
void CB3OnlineSelectPersonaPage::OnKeyboardDone()
{
    if (field_8C == 2) {
        if (Length__10CGtUnicodeFPCUs(D_01E8CA94.field_0) > 0) {
            ConvertUTF16toUTF8Fast__10CGtUnicodeFPCUsPUci(D_01E8CA94.field_0, field_D0, 32);
            if (strlen(field_D0) < 3 || strlen(field_D0) >= 13) {
                field_D0[0] = 0;
                D_01E899C0.Show(false, false);
                if (D_01E898F2.field_0 != 0) {
                    ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
                }
                func_0032D080(&D_01E898E8, 2, 0x424, 0, 0);
                field_8C = 5;
                return;
            } else if (strlen(field_D0) == 3 && strchr(field_D0, ' ') != 0) {
                field_D0[0] = 0;
                D_01E899C0.Show(false, false);
                if (D_01E898F2.field_0 != 0) {
                    ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
                }
                func_0032D080(&D_01E898E8, 2, 0x424, 0, 0);
                field_8C = 5;
                return;
            }
            D_01E3CD44.CreatePersona(field_D0);
            if (D_01E898F2.field_0 != 0) {
                ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
            }
            func_0032D080(&D_01E898E8, 0, 0xB5, 0xF, 0);
            field_8C = 3;
        } else {
            field_8C = 0;
        }
        D_01E899C0.Show(false, false);
    }
}
