// CGtLobbyPS2DirtySock::GameLeaveCallback(DirtySock::LobbyApiRefT*,DirtySock::LobbyApiMsgT*,void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtLobbyDirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (static lobby callback (a2=self, msg->field_C error code); three-way || on the error code).

namespace DirtySock { class LobbyApiRefT; }
namespace DirtySock { class LobbyApiMsgT; }

struct DirtySock::LobbyApiMsgT {
    unsigned char pad_0[0xC];
    int field_C;
};

class CGtLobbyPS2DirtySock {
public:
    static void GameLeaveCallback(DirtySock::LobbyApiRefT* p0, DirtySock::LobbyApiMsgT* p1, void* p2);
    static int ConvertDirtySockError(int);

    unsigned char pad_0[0x110];
    unsigned char field_110;
    unsigned char field_111;
    unsigned char field_112;
    unsigned char pad_113[0x1];
    int field_114;
    unsigned char pad_118[0x4];
    unsigned char field_11C;
    unsigned char field_11D;
    unsigned char pad_11E[0x3];
    unsigned char field_121;
    unsigned char pad_122[0x6];
    int field_128;
    int field_12C;
    unsigned char pad_130[0x4];
    int field_134;
    unsigned char pad_138[0x30C];
    unsigned char field_444;
};

// 0x00339BC0
void CGtLobbyPS2DirtySock::GameLeaveCallback(DirtySock::LobbyApiRefT* p0, DirtySock::LobbyApiMsgT* p1, void* p2)
{
    CGtLobbyPS2DirtySock * self = (CGtLobbyPS2DirtySock *)p2;
    if (p1->field_C == 0 || p1->field_C == 0x6A6F696E || p1->field_C == 0x7567616D) {
        self->field_11C = 0;
        self->field_11D = 0;
        self->field_12C = -1;
        self->field_134 = 0;
        self->field_121 = 0;
        self->field_128 = 0;
        self->field_444 = 0;
        self->field_111 = 1;
    } else {
        int r = ConvertDirtySockError(p1->field_C);
        self->field_112 = 1;
        self->field_110 = 0;
        self->field_114 = r;
    }
}
