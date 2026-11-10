// CGtLobbyPS2DirtySock::ReJoinLobbyCallback(DirtySock::LobbyApiRefT*,DirtySock::LobbyApiMsgT*,void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtLobbyDirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (static callback; message field_C an int error code (bnez order), user data p2 is the lobby object).

namespace DirtySock { class LobbyApiRefT; }
namespace DirtySock { class LobbyApiMsgT; }

class CGtLobbyPS2DirtySock;

struct DirtySock::LobbyApiMsgT {
    unsigned char pad_0[0xC];
    int field_C;
};

class CGtLobbyPS2DirtySock {
public:
    static void ReJoinLobbyCallback(DirtySock::LobbyApiRefT* p0, DirtySock::LobbyApiMsgT* p1, void* p2);
    int ConvertDirtySockError(int);

    unsigned char pad_0[0x110];
    unsigned char field_110;
    unsigned char field_111;
    unsigned char field_112;
    unsigned char pad_113[0x1];
    int field_114;
};

// 0x003383F0
// [L] static: a0 is the LobbyApiRefT, never `this`; a1 is the message (field_C read), a2 the user data, which
// is the lobby object itself (its field_110..field_114 are the class's, include/b3/classes/CGtLobbyPS2DirtySock.h).
// [G] field_C is an int error code: ConvertDirtySockError compares its a0 with FourCCs ('self', 'down', ...),
// so it is really static too; it is kept as the shared header declares it, with a1 left holding p1 (as
// func_0033AC60 calls it), and an int-typed field_C gives retail's bnez block order.
void CGtLobbyPS2DirtySock::ReJoinLobbyCallback(DirtySock::LobbyApiRefT* p0, DirtySock::LobbyApiMsgT* p1, void* p2)
{
    CGtLobbyPS2DirtySock * lobby = (CGtLobbyPS2DirtySock *)p2;
    int t0 = p1->field_C;
    if (t0 != 0) {
        int r2 = ((CGtLobbyPS2DirtySock *)t0)->ConvertDirtySockError((int)p1);
        lobby->field_112 = 1;
        lobby->field_110 = 0;
        lobby->field_114 = r2;
    } else {
        lobby->field_111 = 1;
    }
}
