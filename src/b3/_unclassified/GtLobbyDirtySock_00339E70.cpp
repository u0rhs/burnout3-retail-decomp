// CGtLobbyPS2DirtySock::JoinGameCallback(DirtySock::LobbyApiRefT*,DirtySock::LobbyApiMsgT*,void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtLobbyDirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

namespace DirtySock { class LobbyApiRefT; }
namespace DirtySock { class LobbyApiMsgT; }

class CGtLobbyPS2DirtySock;
struct UnkStruct_D_004C5850;
struct UnkStruct_D_004C5968;

struct DirtySock::LobbyApiRefT {
    unsigned char pad_0[0xC];
    CGtLobbyPS2DirtySock * field_C;
    int field_10;
};

struct DirtySock::LobbyApiMsgT {
    unsigned char pad_0[0x110];
    unsigned char field_110;
    unsigned char pad_111[0x1];
    unsigned char field_112;
    unsigned char pad_113[0x1];
    int field_114;
    unsigned char pad_118[0x4];
    unsigned char field_11C;
    unsigned char pad_11D[0x4];
    unsigned char field_121;
    unsigned char pad_122[0x6];
    int field_128;
};

struct UnkStruct_D_004C5850 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004C5968 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CGtLobbyPS2DirtySock {
public:
    void JoinGameCallback(DirtySock::LobbyApiRefT* p0, DirtySock::LobbyApiMsgT* p1, void* p2);
    int ConvertDirtySockError(int);
};

extern UnkStruct_D_004C5850 D_004C5850;
extern UnkStruct_D_004C5968 D_004C5968;

extern "C" int TagFieldFind(int, void *, DirtySock::LobbyApiMsgT *, void*);
extern "C" void TagFieldGetString(int, void *, int, void *);

// 0x00339E70
void CGtLobbyPS2DirtySock::JoinGameCallback(DirtySock::LobbyApiRefT* p0, DirtySock::LobbyApiMsgT* p1, void* p2)
{
    CGtLobbyPS2DirtySock * t0 = p0->field_C;
    if (t0 == 0) {
        p1->field_11C = 1;
        p1->field_121 = 0;
        p1->field_128 = 0;
        int r0 = TagFieldFind(p0->field_10, &D_004C5850, p1, p2);
        TagFieldGetString(r0, ((char *)p1 + 0x444), 32, &D_004C5968);
    } else {
        int r2 = t0->ConvertDirtySockError((int)p0);
        p1->field_112 = 1;
        p1->field_110 = 0;
        p1->field_114 = r2;
    }
}
