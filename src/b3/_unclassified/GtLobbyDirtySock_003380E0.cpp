// CGtLobbyPS2DirtySock::GetGameNewsCallback(DirtySock::LobbyApiRefT*,DirtySock::LobbyApiMsgT*,void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtLobbyDirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (static lobby callback (a2=self); callback arg compare written with (unsigned) casts on both sides).

namespace DirtySock { class LobbyApiRefT; }
namespace DirtySock { class LobbyApiMsgT; }

struct DirtySock::LobbyApiMsgT {
    unsigned char pad_0[0xC];
    int field_C;
    int field_10;
};

class CGtLobbyPS2DirtySock {
public:
    static void GetGameNewsCallback(DirtySock::LobbyApiRefT* p0, DirtySock::LobbyApiMsgT* p1, void* p2);
    static int ConvertDirtySockError(int);

    unsigned char pad_0[0x110];
    unsigned char field_110;
    unsigned char field_111;
    unsigned char field_112;
    unsigned char pad_113[0x1];
    int field_114;
    unsigned char pad_118[0x4D0];
    int field_5E8;
    void (*field_5EC)(bool, int, int);
    int field_5F0;
};

// 0x003380E0
void CGtLobbyPS2DirtySock::GetGameNewsCallback(DirtySock::LobbyApiRefT* p0, DirtySock::LobbyApiMsgT* p1, void* p2)
{
    CGtLobbyPS2DirtySock * self = (CGtLobbyPS2DirtySock *)p2;
    if (p1->field_C == self->field_5E8 + 0x6E657730) {
        self->field_111 = 1;
    } else {
        int r = ConvertDirtySockError(p1->field_C);
        self->field_112 = 1;
        self->field_110 = 0;
        self->field_114 = r;
    }
    if (self->field_5EC != 0) {
        self->field_5EC((unsigned)p1->field_C == (unsigned)(self->field_5E8 + 0x6E657730), p1->field_10, self->field_5F0);
        self->field_5EC = 0;
        self->field_5F0 = 0;
    }
}
