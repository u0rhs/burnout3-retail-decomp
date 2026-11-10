// CGtLobbyPS2DirtySock::PlayerParametersUpdateCallback(DirtySock::LobbyApiRefT*,DirtySock::LobbyApiMsgT*,void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtLobbyDirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (static callback: a1 = msg (error at +0xC), a2 = user (the lobby object); plain if/else on the error (same as DefaultCallback)).

// CGtLobbyPS2DirtySock::PlayerParametersUpdateCallback(DirtySock::LobbyApiRefT*,DirtySock::LobbyApiMsgT*,void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtLobbyDirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// [L] a DirtySock lobby callback: static (no `this`), a0 = ref, a1 = msg, a2 = the user pointer, which is
// the CGtLobbyPS2DirtySock passed to LobbyApiRequestCB (cf. CGtLobbyPS2DirtySock::LostPassword).

namespace DirtySock { class LobbyApiRefT; }
namespace DirtySock { class LobbyApiMsgT; }

class CGtLobbyPS2DirtySock;

struct DirtySock::LobbyApiMsgT {
    unsigned char pad_0[0xC];
    int field_C;
};

class CGtLobbyPS2DirtySock {
public:
    static void PlayerParametersUpdateCallback(DirtySock::LobbyApiRefT* p0, DirtySock::LobbyApiMsgT* p1, void* p2);
    static int ConvertDirtySockError(int);

    unsigned char pad_0[0x110];
    unsigned char field_110;
    unsigned char field_111;
    unsigned char field_112;
    unsigned char pad_113[0x1];
    int field_114;
};

// 0x00337F40
void CGtLobbyPS2DirtySock::PlayerParametersUpdateCallback(DirtySock::LobbyApiRefT* p0, DirtySock::LobbyApiMsgT* p1, void* p2)
{
    CGtLobbyPS2DirtySock * self = (CGtLobbyPS2DirtySock *)p2;
    if (p1->field_C == 0) {
        self->field_111 = 1;
    } else {
        int r = ConvertDirtySockError(p1->field_C);
        self->field_112 = 1;
        self->field_110 = 0;
        self->field_114 = r;
    }
}
