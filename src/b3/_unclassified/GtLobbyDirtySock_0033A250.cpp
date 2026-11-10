// CGtLobbyPS2DirtySock::ConnectToServer(char*,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtLobbyDirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtLobbyPS2DirtySock;
struct UnkStruct_D_004C5968;
struct UnkStruct_func_0033A2E0;

struct UnkStruct_D_004C5968 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_func_0033A2E0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CGtLobbyPS2DirtySock {
public:
    void ConnectToServer(char* p0, int p1);

    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    unsigned char pad_4[0x100];
    int field_104;
    unsigned char pad_108[0x8];
    unsigned char field_110;
    unsigned char field_111;
    unsigned char field_112;
    unsigned char pad_113[0x1];
    int field_114;
    unsigned char pad_118[0x8];
    unsigned char field_120;
};

extern UnkStruct_D_004C5968 D_004C5968;
extern UnkStruct_func_0033A2E0 func_0033A2E0;

extern "C" char * strcpy(char *, const char *);
extern "C" void LobbyApiConnect(int, char*, int, void *, CGtLobbyPS2DirtySock *, int);

// 0x0033A250
void CGtLobbyPS2DirtySock::ConnectToServer(char* p0, int p1)
{
    field_110 = 1;
    field_111 = 0;
    field_112 = 0;
    field_120 = 0;
    field_114 = 0;
    strcpy((char *)((char *)this + 0x4), (const char *)&D_004C5968);
    LobbyApiConnect(field_104, p0, p1, &func_0033A2E0, this, 5000);
    vfunc_14();
}
