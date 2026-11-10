// CGtLobbyPS2DirtySock::ChatCallback(DirtySock::LobbyApiRefT*,DirtySock::LobbyApiMsgT*,void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtLobbyDirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a126: else-if chain falls off end vs early return).

namespace DirtySock { class LobbyApiRefT; }
namespace DirtySock { class LobbyApiMsgT; }
class CGtLobbyPS2DirtySock;
struct UnkStruct_Chat {
    unsigned char pad_0[0x11C];
    unsigned char field_11C;
    unsigned char pad_11D[0x4E7];
    void (*field_604)(char *, char *, void *);
    void *field_608;
    unsigned char pad_60C[0x3E];
    unsigned char field_64A;
};
struct DirtySock::LobbyApiMsgT {
    unsigned char pad_0[0xC];
    unsigned int field_C;
    int field_10;
};
struct UnkStruct_D_004E2DAC { char * field_0; };
struct UnkStruct_Dy { unsigned char pad_0[0x10]; };
struct UnkStruct_Arb { char c[8][64]; };
extern UnkStruct_D_004E2DAC D_004E2DAC;
extern UnkStruct_Arb D_01EA37C0;
extern UnkStruct_Dy D_004C5B98, D_004C5BA0, D_004C5968, D_004C5990;
extern "C" int mnNumArbPacketsBuffered__20CGtLobbyPS2DirtySock;
extern "C" void func_00406920();
extern "C" void *TagFieldFind(int, void *);
extern "C" void TagFieldGetString(void *, char *, int, void *);
extern "C" char *func_00128BE8(char *, void *);
extern "C" char *strcpy(char *, const char *);
extern "C" int atoi(const char *);
extern "C" int strlen(const char *);

class CGtLobbyPS2DirtySock {
public:
    static void ChatCallback(DirtySock::LobbyApiRefT* p0, DirtySock::LobbyApiMsgT* p1, void* p2);
};

// 0x0033C390
void CGtLobbyPS2DirtySock::ChatCallback(DirtySock::LobbyApiRefT* p0, DirtySock::LobbyApiMsgT* p1, void* p2)
{
    UnkStruct_Chat *self = (UnkStruct_Chat *)p2;
    char str[0x101];
    char tmp[0x110];
    char name[0x40];
    func_00406920();
    TagFieldGetString(TagFieldFind(p1->field_10, &D_004C5B98), name, 0x40, &D_004C5968);
    TagFieldGetString(TagFieldFind(p1->field_10, &D_004C5BA0), str, 0x101, &D_004C5968);
    unsigned int f = p1->field_C;
    bool hasflag = (f & 0x200000) == 0x200000;
    unsigned int arb = f & 0x8000000;
    if (arb != 0 && !hasflag && mnNumArbPacketsBuffered__20CGtLobbyPS2DirtySock < 8) {
        char *p = str;
        strcpy(tmp, p);
        func_00128BE8(tmp, &D_004C5990);
        int n = atoi(tmp);
        p += strlen(tmp) + 1;
        char *row = D_01EA37C0.c[mnNumArbPacketsBuffered__20CGtLobbyPS2DirtySock];
        for (int i = 0; i < n; i++) {
            strcpy(tmp, p);
            func_00128BE8(tmp, &D_004C5990);
            *row++ = atoi(tmp);
            p += strlen(tmp) + 1;
        }
        mnNumArbPacketsBuffered__20CGtLobbyPS2DirtySock++;
    } else if (f & 0x20000000) {
        self->field_64A = 1;
    } else if (f & 0x40000000) {
        unsigned char c = self->field_11C;
        if ((c != 0 && (f & 0x80) != 0) || (c == 0 && (f & 0x80) == 0)) {
            TagFieldGetString(TagFieldFind(p1->field_10, &D_004C5BA0), D_004E2DAC.field_0, 0x400, &D_004C5968);
            if (self->field_604 == 0)
                return;
            self->field_604(name, D_004E2DAC.field_0, self->field_608);
        }
    } else {
        if (arb != 0)
            return;
        unsigned char c = self->field_11C;
        if ((c != 0 && (f & 0x80) != 0) || (c == 0 && (f & 0x80) == 0)) {
            if (self->field_604 == 0)
                return;
            self->field_604(name, D_004E2DAC.field_0, self->field_608);
        }
    }
}
