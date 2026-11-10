// CGtLobbyPS2DirtySock::PersonaCreateCallback(DirtySock::LobbyApiRefT*,DirtySock::LobbyApiMsgT*,void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtLobbyDirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a67: static lobby callback, a2=self, a1->field_C error code, if/else-if chain).

namespace DirtySock { class LobbyApiRefT; }
namespace DirtySock { class LobbyApiMsgT; }

struct DirtySock::LobbyApiMsgT {
    unsigned char pad_0[0xC];
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

class CGtLobbyPS2DirtySock {
public:
    static void PersonaCreateCallback(DirtySock::LobbyApiRefT* p0, DirtySock::LobbyApiMsgT* p1, void* p2);
    static int ConvertDirtySockError(int);

    unsigned char pad_0[0x110];
    unsigned char field_110;
    unsigned char field_111;
    unsigned char field_112;
    unsigned char pad_113[0x1];
    int field_114;
    unsigned char pad_118[0x258];
    char field_370[5][16];
};

extern UnkStruct_D_004E2DAC D_004E2DAC;
extern UnkStruct_D_004C5AE8 D_004C5AE8;
extern UnkStruct_D_004C5968 D_004C5968;
extern UnkStruct_D_004C5990 D_004C5990;

extern "C" char * strncpy(char *, const char *, unsigned int);
extern "C" int TagFieldFind(int, void *);
extern "C" void TagFieldGetString(int, int, int, void *);
extern "C" const char * func_00128BE8(int, void *);

// 0x0033A9A0
void CGtLobbyPS2DirtySock::PersonaCreateCallback(DirtySock::LobbyApiRefT* p0, DirtySock::LobbyApiMsgT* p1, void* p2)
{
    CGtLobbyPS2DirtySock * self = (CGtLobbyPS2DirtySock *)p2;
    int err = p1->field_C;
    if (err == 0) {
        self->field_111 = 1;
    } else if (err != 0x6475706C) {
        int r = ConvertDirtySockError(err);
        self->field_112 = 1;
        self->field_110 = 0;
        self->field_114 = r;
    } else {
        self->field_112 = 1;
        int f = TagFieldFind(p1->field_10, &D_004C5AE8);
        TagFieldGetString(f, D_004E2DAC.field_0, 1024, &D_004C5968);
        const char * name = func_00128BE8(D_004E2DAC.field_0, &D_004C5990);
        for (int i = 0; i < 5; i++) {
            strncpy(self->field_370[i], name, 16);
            name = func_00128BE8(0, &D_004C5990);
        }
        int r = ConvertDirtySockError(p1->field_C);
        self->field_112 = 1;
        self->field_110 = 0;
        self->field_114 = r;
    }
}
