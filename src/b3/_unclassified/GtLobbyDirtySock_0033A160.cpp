// CGtLobbyPS2DirtySock::GameCreatedCallback(DirtySock::LobbyApiRefT*,DirtySock::LobbyApiMsgT*,void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtLobbyDirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (plain if/else static callback).

namespace DirtySock { class LobbyApiRefT; }
namespace DirtySock { class LobbyApiMsgT; }
class CGtLobbyPS2DirtySock;
struct UnkStruct_D_004C59E8 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_004C5850 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_004C5968 { unsigned char pad_0[0x10]; };
struct DirtySock::LobbyApiMsgT {
    unsigned char pad_0[0xC];
    int field_C;
    int field_10;
};
class CGtLobbyPS2DirtySock {
public:
    static void GameCreatedCallback(DirtySock::LobbyApiRefT* p0, DirtySock::LobbyApiMsgT* p1, void* p2);
    static int ConvertDirtySockError(int);
    unsigned char pad_0[0x110];
    unsigned char field_110;
    unsigned char field_111;
    unsigned char field_112;
    unsigned char pad_113[0x1];
    int field_114;
    unsigned char pad_118[0x4];
    unsigned char field_11C;
    unsigned char pad_11D[0x4];
    unsigned char field_121;
    unsigned char pad_122[0x6];
    int field_128;
    int field_12C;
    unsigned char pad_130[0x314];
    char field_444[0x20];
};
extern UnkStruct_D_004C59E8 D_004C59E8;
extern UnkStruct_D_004C5850 D_004C5850;
extern UnkStruct_D_004C5968 D_004C5968;
extern "C" void * TagFieldFind(int, void *);
extern "C" int TagFieldGetNumber(void *, int);
extern "C" int TagFieldGetString(void *, char *, int, void *);

// 0x0033A160
void CGtLobbyPS2DirtySock::GameCreatedCallback(DirtySock::LobbyApiRefT* p0, DirtySock::LobbyApiMsgT* p1, void* p2)
{
    CGtLobbyPS2DirtySock * self = (CGtLobbyPS2DirtySock *)p2;
    if (p1->field_C == 0) {
        self->field_121 = 0;
        self->field_128 = 0;
        self->field_11C = 1;
        self->field_12C = TagFieldGetNumber(TagFieldFind(p1->field_10, &D_004C59E8), -1);
        TagFieldGetString(TagFieldFind(p1->field_10, &D_004C5850), self->field_444, 0x20, &D_004C5968);
    } else {
        int r = ConvertDirtySockError(p1->field_C);
        self->field_112 = 1;
        self->field_110 = 0;
        self->field_114 = r;
    }
}
