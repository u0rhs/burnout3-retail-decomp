// CGtLobbyPS2DirtySock::PersonaLoggedInCallback(DirtySock::LobbyApiRefT*,DirtySock::LobbyApiMsgT*,void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtLobbyDirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a126: three-way callback, first try).

namespace DirtySock { class LobbyApiRefT; }
namespace DirtySock { class LobbyApiMsgT; }
class CGtLobbyPS2DirtySock;
struct UnkStruct_Pers_Slot { char c[0x10]; };
struct UnkStruct_Pers {
    unsigned char pad_0[0x104];
    int field_104;
    int field_108;
    int field_10C;
    unsigned char field_110;
    unsigned char field_111;
    unsigned char field_112;
    unsigned char pad_113[0x1];
    int field_114;
    unsigned char pad_118[6];
    unsigned char field_11E;
    unsigned char pad_11F[0x251];
    UnkStruct_Pers_Slot field_370[5];
    char field_3C0[0x80];
    unsigned char pad_440[0x64];
    char field_4A4[0x20];
    unsigned char pad_4C4[0x168];
    void *field_62C;
};
struct DirtySock::LobbyApiMsgT {
    unsigned char pad_0[0xC];
    int field_C;
    int field_10;
};
struct UnkStruct_D_004E2DAC { char * field_0; };
struct UnkStruct_Dy { unsigned char pad_0[0x10]; };
extern UnkStruct_D_004E2DAC D_004E2DAC;
extern UnkStruct_Dy D_004C5AE8, D_004C5968, D_004C5990, D_004C5AF0, D_004C58E0, D_004C5AF8;
extern "C" void *TagFieldFind(int, void *);
extern "C" void TagFieldGetString(void *, char *, int, void *);
extern "C" char *func_00128BE8(char *, void *);
extern "C" char *strncpy(char *, const char *, unsigned);
extern "C" void *_LobbyStatbookCreate(int, int);
extern "C" int func_0040E8B0(void *);
extern "C" int func_0040E738(void *, int);
extern "C" void func_0040E500(void *);
extern "C" void func_0040E538(void *, void *);

class CGtLobbyPS2DirtySock {
public:
    static void PersonaLoggedInCallback(DirtySock::LobbyApiRefT* p0, DirtySock::LobbyApiMsgT* p1, void* p2);
    static int ConvertDirtySockError(int);
};

// 0x0033AAB0
void CGtLobbyPS2DirtySock::PersonaLoggedInCallback(DirtySock::LobbyApiRefT* p0, DirtySock::LobbyApiMsgT* p1, void* p2)
{
    UnkStruct_Pers *self = (UnkStruct_Pers *)p2;
    int e = p1->field_C;
    if (e == 0) {
        TagFieldGetString(TagFieldFind(p1->field_10, &D_004C5AF0), self->field_3C0, 0x80, &D_004C5968);
        TagFieldGetString(TagFieldFind(p1->field_10, &D_004C58E0), self->field_4A4, 0x20, &D_004C5968);
        self->field_10C = 1;
        if (self->field_62C == 0) {
            self->field_62C = _LobbyStatbookCreate(self->field_104, 10);
        }
        if (func_0040E8B0(self->field_62C) == 0 || func_0040E738(self->field_62C, 0) == 0)
            func_0040E500(self->field_62C);
        func_0040E538(self->field_62C, &D_004C5AF8);
    } else if (e == 0x6475706C) {
        TagFieldGetString(TagFieldFind(p1->field_10, &D_004C5AE8), D_004E2DAC.field_0, 0x400, &D_004C5968);
        char *t = func_00128BE8(D_004E2DAC.field_0, &D_004C5990);
        for (int i = 0; i < 5; i++) {
            strncpy(self->field_370[i].c, t, 0x10);
            t = func_00128BE8(0, &D_004C5990);
        }
        self->field_112 = 1;
        self->field_110 = 0;
        self->field_114 = -7;
    } else {
        self->field_11E = 0;
        int r = CGtLobbyPS2DirtySock::ConvertDirtySockError(p1->field_C);
        self->field_112 = 1;
        self->field_110 = 0;
        self->field_114 = r;
    }
}
