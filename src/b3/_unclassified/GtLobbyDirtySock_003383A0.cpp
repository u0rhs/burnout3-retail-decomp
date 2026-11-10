// CGtLobbyPS2DirtySock::JoinLobbyCallback(DirtySock::LobbyApiRefT*,DirtySock::LobbyApiMsgT*,void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtLobbyDirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (static callback: error code is msg->field_C (int) passed to static ConvertDirtySockError(int); p2 is the lobby object (the this LobbyApiRequestCB is given)).

namespace DirtySock { class LobbyApiRefT; }
namespace DirtySock { class LobbyApiMsgT; }

class CGtLobbyPS2DirtySock;

struct DirtySock::LobbyApiRefT {
    unsigned char pad_0[0x1];  // [G]
};

struct DirtySock::LobbyApiMsgT {
    unsigned char pad_0[0xC];
    int field_C;
};

class CGtLobbyPS2DirtySock {
public:
    static void JoinLobbyCallback(DirtySock::LobbyApiRefT* p0, DirtySock::LobbyApiMsgT* p1, void* p2);
    static int ConvertDirtySockError(int);

    unsigned char pad_0[0x110];
    unsigned char field_110;
    unsigned char field_111;
    unsigned char field_112;
    unsigned char pad_113[0x1];
    int field_114;
};

// 0x003383A0
void CGtLobbyPS2DirtySock::JoinLobbyCallback(DirtySock::LobbyApiRefT* p0, DirtySock::LobbyApiMsgT* p1, void* p2)
{
    CGtLobbyPS2DirtySock * self = (CGtLobbyPS2DirtySock *)p2;
    if (p1->field_C != 0) {
        int r0 = ConvertDirtySockError(p1->field_C);
        self->field_112 = 1;
        self->field_110 = 0;
        self->field_114 = r0;
    } else {
        self->field_111 = 1;
    }
}
