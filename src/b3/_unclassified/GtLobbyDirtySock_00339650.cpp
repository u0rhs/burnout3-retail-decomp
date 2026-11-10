// Hand-written; the lifter refused it (static DirtySock callback in the siblings' form; TagFieldGetNumber(TagFieldFind(msg->field_10, &D_004C5A10), 0)).

// CGtLobbyPS2DirtySock::SearchForGamesCallback(DirtySock::LobbyApiRefT*,DirtySock::LobbyApiMsgT*,void*)
// [C] name: the mangled symbol in retail's tables; file: research/retail_names.csv -> GtLobbyDirtySock.cpp (cf. siblings).
// Area not evidenced, so _unclassified/ (docs/conventions.md). Field names are placeholders, every type is [G] (instruction widths).
// [L] a DirtySock lobby callback: static (no `this`), a0 = ref, a1 = msg, a2 = the user pointer, which is
// the CGtLobbyPS2DirtySock (cf. CGtLobbyPS2DirtySock::PlayerParametersUpdateCallback).

namespace DirtySock { class LobbyApiRefT; }
namespace DirtySock { class LobbyApiMsgT; }

class CGtLobbyPS2DirtySock;
struct UnkStruct_D_004C5A10;

struct DirtySock::LobbyApiMsgT {
    unsigned char pad_0[0xC];
    int field_C;
    int field_10;
};

struct UnkStruct_D_004C5A10 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CGtLobbyPS2DirtySock {
public:
    static void SearchForGamesCallback(DirtySock::LobbyApiRefT* p0, DirtySock::LobbyApiMsgT* p1, void* p2);
    static int ConvertDirtySockError(int);

    unsigned char pad_0[0x110];
    unsigned char field_110;
    unsigned char field_111;
    unsigned char field_112;
    unsigned char pad_113[0x1];
    int field_114;
    unsigned char pad_118[0x4E0];
    int field_5F8;
};

extern UnkStruct_D_004C5A10 D_004C5A10;

extern "C" int TagFieldFind(int, void *);
extern "C" int TagFieldGetNumber(int, int);

// 0x00339650
void CGtLobbyPS2DirtySock::SearchForGamesCallback(DirtySock::LobbyApiRefT* p0, DirtySock::LobbyApiMsgT* p1, void* p2)
{
    CGtLobbyPS2DirtySock * self = (CGtLobbyPS2DirtySock *)p2;
    if (p1->field_C == 0) {
        self->field_5F8 = TagFieldGetNumber(TagFieldFind(p1->field_10, &D_004C5A10), 0);
        self->field_111 = 1;
    } else {
        self->field_5F8 = 0;
        int r = ConvertDirtySockError(p1->field_C);
        self->field_112 = 1;
        self->field_110 = 0;
        self->field_114 = r;
    }
}
