// CGtLobbyPS2DirtySock::DisconnectFromServer() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtLobbyDirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtLobbyPS2DirtySock;

class CGtLobbyPS2DirtySock {
public:
    void DisconnectFromServer();

    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    unsigned char pad_4[0x100];
    int field_104;
    unsigned char pad_108[0x16];
    unsigned char field_11E;
};

extern "C" void LobbyApiDisconnect(int, int);

// 0x0033A210
void CGtLobbyPS2DirtySock::DisconnectFromServer()
{
    LobbyApiDisconnect(field_104, 0);
    field_11E = 0;
    vfunc_14();
}
