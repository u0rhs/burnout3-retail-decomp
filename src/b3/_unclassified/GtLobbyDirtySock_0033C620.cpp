// CGtLobbyPS2DirtySock::EventStatusCallback(DirtySock::LobbyApiRefT*,DirtySock::LobbyApiMsgT*,void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtLobbyDirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

namespace DirtySock { class LobbyApiRefT; }
namespace DirtySock { class LobbyApiMsgT; }

class CGtLobbyPS2DirtySock;
struct UnkStruct_D_01EA32B0;

struct DirtySock::LobbyApiRefT {
    unsigned char pad_0[0x8];
    int field_8;
    unsigned char pad_C[0x4];
    int field_10;
};

struct UnkStruct_D_01EA32B0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CGtLobbyPS2DirtySock {
public:
    void EventStatusCallback(DirtySock::LobbyApiRefT* p0, DirtySock::LobbyApiMsgT* p1, void* p2);
};

extern UnkStruct_D_01EA32B0 D_01EA32B0;

extern "C" void LobbyApiExtractPlayRecord(void *, int, DirtySock::LobbyApiMsgT*, void*);

// 0x0033C620
void CGtLobbyPS2DirtySock::EventStatusCallback(DirtySock::LobbyApiRefT* p0, DirtySock::LobbyApiMsgT* p1, void* p2)
{
    if (p0->field_8 == 0x706C6179) {
        LobbyApiExtractPlayRecord(&D_01EA32B0, p0->field_10, p1, p2);
    }
}
