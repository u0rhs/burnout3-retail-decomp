// CGtLobbyPS2DirtySock::RespCallback(DirtySock::LobbyApiRefT*,DirtySock::LobbyApiMsgT*,void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtLobbyDirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (if-chain kick first).

namespace DirtySock { class LobbyApiRefT; }
namespace DirtySock { class LobbyApiMsgT; }
class CGtLobbyPS2DirtySock;
struct UnkStruct_D_004C5BA8 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_004C5AB8 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_004C5BB8 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_004C5968 { unsigned char pad_0[0x10]; };
struct DirtySock::LobbyApiMsgT {
    unsigned char pad_0[0x8];
    int field_8;
    unsigned char pad_C[0x4];
    int field_10;
};
class CGtLobbyPS2DirtySock {
public:
    static void RespCallback(DirtySock::LobbyApiRefT* p0, DirtySock::LobbyApiMsgT* p1, void* p2);
};
extern UnkStruct_D_004C5BA8 D_004C5BA8;
extern UnkStruct_D_004C5AB8 D_004C5AB8;
extern UnkStruct_D_004C5BB8 D_004C5BB8;
extern UnkStruct_D_004C5968 D_004C5968;
extern "C" void * TagFieldFind(int, void *);
extern "C" int TagFieldGetString(void *, char *, int, void *);

// 0x0033C740
void CGtLobbyPS2DirtySock::RespCallback(DirtySock::LobbyApiRefT* p0, DirtySock::LobbyApiMsgT* p1, void* p2)
{
    char a[3];
    char b[8];
    char c[0x40];
    int k = p1->field_8;
    if (k == 0x6B69636B) {
        TagFieldGetString(TagFieldFind(p1->field_10, &D_004C5BB8), a, 3, &D_004C5968);
    } else if (k == 0x6E657773) {
        TagFieldGetString(TagFieldFind(p1->field_10, &D_004C5BA8), c, 0x40, &D_004C5968);
        TagFieldGetString(TagFieldFind(p1->field_10, &D_004C5AB8), b, 8, &D_004C5968);
    }
}
