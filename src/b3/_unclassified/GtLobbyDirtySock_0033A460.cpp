// CGtLobbyPS2DirtySock::ServerLoginCallback(DirtySock::LobbyApiRefT*,DirtySock::LobbyApiMsgT*,void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtLobbyDirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (static lobby callback written by hand (lifter refused); assignment inside the if condition ((t = TagFieldFind(..)) != 0) makes beqz test v0).

namespace DirtySock { class LobbyApiRefT; }
namespace DirtySock { class LobbyApiMsgT; }

class CGtLobbyPS2DirtySock;
struct UnkStruct_D_004C5A08 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_004C5A88 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_004C5A90 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_004C5AA0 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_004C5968 { unsigned char pad_0[0x10]; };

struct DirtySock::LobbyApiMsgT {
    unsigned char pad_0[0xC];
    int field_C;
    int field_10;
};

class CGtLobbyPS2DirtySock {
public:
    static void ServerLoginCallback(DirtySock::LobbyApiRefT* p0, DirtySock::LobbyApiMsgT* p1, void* p2);
    static int ConvertDirtySockError(int);

    unsigned char pad_0[0x110];
    unsigned char field_110;
    unsigned char field_111;
    unsigned char field_112;
    unsigned char pad_113[0x1];
    int field_114;
    unsigned char pad_118[0x6];
    unsigned char field_11E;
    unsigned char pad_11F[0x3A6];
    char field_4C5[0x80];
    unsigned char field_545;
    unsigned char field_546;
    unsigned char pad_547[0x1];
    void (*field_548)(char *, int);
    int field_54C;
    unsigned char pad_550[0x40];
    unsigned char field_590;
    char field_591[0x21];
};

extern UnkStruct_D_004C5A08 D_004C5A08;
extern UnkStruct_D_004C5A88 D_004C5A88;
extern UnkStruct_D_004C5A90 D_004C5A90;
extern UnkStruct_D_004C5AA0 D_004C5AA0;
extern UnkStruct_D_004C5968 D_004C5968;

extern "C" void * TagFieldFind(int, void *);
extern "C" int TagFieldGetString(void *, char *, int, void *);
extern "C" int TagFieldGetDelim(void *, char *, int, void *, int, int);
extern "C" int strlen(const char *);
extern "C" void CheatCalcResponse(char *, int, char *, int);

// 0x0033A460
void CGtLobbyPS2DirtySock::ServerLoginCallback(DirtySock::LobbyApiRefT* p0, DirtySock::LobbyApiMsgT* p1, void* p2)
{
    CGtLobbyPS2DirtySock * self = (CGtLobbyPS2DirtySock *)p2;
    if (p1->field_C == 0) {
        char yn[3];
        char buf[0x40];
        char buf2[0x100];
        TagFieldGetString(TagFieldFind(p1->field_10, &D_004C5A08), self->field_4C5, 0x40, &D_004C5968);
        TagFieldGetString(TagFieldFind(p1->field_10, &D_004C5A88), yn, 3, &D_004C5968);
        self->field_545 = yn[0] == 'Y';
        self->field_546 = yn[1] == 'Y';
        self->field_111 = 1;
        self->field_11E = 1;
        for (int i = 0; i < 4; i++) {
            if (TagFieldGetDelim(TagFieldFind(p1->field_10, &D_004C5A90), buf, 0x40, &D_004C5968, i, ',') != 0) {
                self->field_548(buf, self->field_54C);
            }
        }
        void * t;
        if ((t = TagFieldFind(p1->field_10, &D_004C5AA0)) != 0) {
            self->field_590 = 1;
            TagFieldGetString(t, buf2, 0x100, &D_004C5968);
            CheatCalcResponse(buf2, strlen(buf2), self->field_591, 0x21);
        } else {
            self->field_590 = 0;
        }
    } else {
        int r = ConvertDirtySockError(p1->field_C);
        self->field_112 = 1;
        self->field_110 = 0;
        self->field_114 = r;
    }
}
