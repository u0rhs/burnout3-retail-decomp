// CGtLobbyPS2DirtySock::AccountRegisterCallback(DirtySock::LobbyApiRefT*,DirtySock::LobbyApiMsgT*,void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtLobbyDirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a66: static callback (a1 = msg with field_C error code, a2 = lobby object); declaration fix of lifter's non-static/duplicate ConvertDirtySockError overload; if/else-if chain with identical error tails in both arms; names as char field_370[5][16]).

// CGtLobbyPS2DirtySock::AccountRegisterCallback -- hand-matched (a66).
// [L] static DirtySock callback: a0 = ref, a1 = msg (field_C int error code, field_8 FourCC type, field_10 tag list), a2 = the lobby object.
namespace DirtySock { class LobbyApiRefT; }
namespace DirtySock { class LobbyApiMsgT; }

class CGtLobbyPS2DirtySock;

struct DirtySock::LobbyApiMsgT {
    unsigned char pad_0[0x8];
    int field_8;
    int field_C;
    int field_10;
};

struct UnkStruct_D_004E2DAC {
    int field_0;
};

struct UnkStruct_D_004C5AE8 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004C5968 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004C5990 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004C5B30 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CGtLobbyPS2DirtySock {
public:
    static void AccountRegisterCallback(DirtySock::LobbyApiRefT* p0, DirtySock::LobbyApiMsgT* p1, void* p2);
    static int ConvertDirtySockError(int);

    unsigned char pad_0[0x110];
    unsigned char field_110;
    unsigned char field_111;
    unsigned char field_112;
    unsigned char pad_113[0x1];
    int field_114;
    unsigned char pad_118[0x258];
    char field_370[5][16];
    unsigned char pad_3C0[0x145];
    char field_505[0x20];
    char field_525[1];  // [G] length unknown
};

extern UnkStruct_D_004E2DAC D_004E2DAC;
extern UnkStruct_D_004C5AE8 D_004C5AE8;
extern UnkStruct_D_004C5968 D_004C5968;
extern UnkStruct_D_004C5990 D_004C5990;
extern UnkStruct_D_004C5B30 D_004C5B30;

extern "C" char * strncpy(char *, const char *, unsigned int);
extern "C" int TagFieldFind(int, void *);
extern "C" void TagFieldGetString(int, int, int, void *);
extern "C" char * func_00128BE8(int, void *);
extern "C" void snprintf(void *, int, void *, int);

// 0x0033B050
void CGtLobbyPS2DirtySock::AccountRegisterCallback(DirtySock::LobbyApiRefT* p0, DirtySock::LobbyApiMsgT* p1, void* p2)
{
    CGtLobbyPS2DirtySock * self = (CGtLobbyPS2DirtySock *)p2;
    if (p1->field_C == 0) {
        if (p1->field_8 == 0x65646974) {
            strncpy(self->field_505, self->field_525, 32);
        }
        self->field_111 = 1;
    } else if (p1->field_C == 0x6475706C) {
        int r2 = TagFieldFind(p1->field_10, &D_004C5AE8);
        TagFieldGetString(r2, D_004E2DAC.field_0, 1024, &D_004C5968);
        char * name = func_00128BE8(D_004E2DAC.field_0, &D_004C5990);
        for (int i = 0; i < 5; i++) {
            if (name == 0) {
                snprintf(self->field_370[i], 16, &D_004C5B30, i);
            } else {
                strncpy(self->field_370[i], name, 16);
            }
            name = func_00128BE8(0, &D_004C5990);
        }
        int r8 = ConvertDirtySockError(p1->field_C);
        self->field_112 = 1;
        self->field_110 = 0;
        self->field_114 = r8;
    } else {
        int r1 = ConvertDirtySockError(p1->field_C);
        self->field_112 = 1;
        self->field_110 = 0;
        self->field_114 = r1;
    }
}
