// CGtLobbyPS2DirtySock::LostAccountCallback(DirtySock::LobbyApiRefT*,DirtySock::LobbyApiMsgT*,void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtLobbyDirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (static callback (a1=msg, a2=user data) + static ConvertDirtySockError(msg->field_C); if(err==0) arm first).

// CGtLobbyPS2DirtySock::LostAccountCallback(DirtySock::LobbyApiRefT*,DirtySock::LobbyApiMsgT*,void*) -- tiny-function batch (tools/tiny_batch.py, lifted, hand-finished).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtLobbyDirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// [L] static: a DirtySock callback (a0 = the lobby ref, unused; a1 = the message; a2 = the user data, i.e. the
// object). ConvertDirtySockError is static too (a0 = the int error code, as in func_003366E0).

namespace DirtySock { class LobbyApiRefT; }
namespace DirtySock { class LobbyApiMsgT; }

class CGtLobbyPS2DirtySock;
struct UnkStruct_00338960_a2;

struct DirtySock::LobbyApiMsgT {
    unsigned char pad_0[0xC];
    int field_C;
};

struct UnkStruct_00338960_a2 {
    unsigned char pad_0[0x110];
    unsigned char field_110;
    unsigned char field_111;
    unsigned char field_112;
    unsigned char pad_113[0x1];
    int field_114;
};

class CGtLobbyPS2DirtySock {
public:
    static void LostAccountCallback(DirtySock::LobbyApiRefT* p0, DirtySock::LobbyApiMsgT* p1, void* p2);
    static int ConvertDirtySockError(int);
};

// 0x00338960
void CGtLobbyPS2DirtySock::LostAccountCallback(DirtySock::LobbyApiRefT* p0, DirtySock::LobbyApiMsgT* p1, void* p2)
{
    UnkStruct_00338960_a2 * self = (UnkStruct_00338960_a2 *)p2;
    int t0 = p1->field_C;
    if (t0 == 0) {
        self->field_111 = 1;
    } else {
        int r0 = CGtLobbyPS2DirtySock::ConvertDirtySockError(t0);
        self->field_112 = 1;
        self->field_110 = 0;
        self->field_114 = r0;
    }
}
