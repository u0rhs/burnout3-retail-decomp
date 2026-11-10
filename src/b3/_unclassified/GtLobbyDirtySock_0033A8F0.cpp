// CGtLobbyPS2DirtySock::SelectPersona(char*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtLobbyDirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtLobbyPS2DirtySock;
struct UnkStruct_0033A8F0_0;
struct UnkStruct_D_004C58E0;
struct UnkStruct_D_004C5AE0;

struct UnkStruct_0033A8F0_0 {
    unsigned char field_0;
    unsigned char pad_1[0x7F];
};

struct UnkStruct_D_004C58E0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004C5AE0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CGtLobbyPS2DirtySock {
public:
    void SelectPersona(char* p0);

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
    unsigned char pad_121[0x46F];
    unsigned char field_590;
};

extern UnkStruct_D_004C58E0 D_004C58E0;
extern UnkStruct_D_004C5AE0 D_004C5AE0;

extern "C" void PersonaLoggedInCallback__20CGtLobbyPS2DirtySockFPQ29DirtySock12LobbyApiRefTPQ29DirtySock12LobbyApiMsgTPv(void *, void *, void*);  // CGtLobbyPS2DirtySock::PersonaLoggedInCallback(DirtySock::LobbyApiRefT*,DirtySock::LobbyApiMsgT*,void*), its address taken
extern "C" void TagFieldSetString(UnkStruct_0033A8F0_0 *, int, void *, void *);
extern "C" void LobbyApiRequestCB(int, int, UnkStruct_0033A8F0_0 *, void *, CGtLobbyPS2DirtySock *);

// 0x0033A8F0
void CGtLobbyPS2DirtySock::SelectPersona(char* p0)
{
    UnkStruct_0033A8F0_0 local;  // [G] the frame's one local (size: up to the frame top)
    local.field_0 = 0;
    TagFieldSetString(&local, 128, &D_004C58E0, p0);
    if (field_590 != 0) {
        TagFieldSetString(&local, 128, &D_004C5AE0, ((char *)this + 0x591));
    }
    field_110 = 1;
    field_111 = 0;
    field_112 = 0;
    field_120 = 0;
    field_114 = 0;
    LobbyApiRequestCB(field_104, 0x70657273, &local, (void *)&PersonaLoggedInCallback__20CGtLobbyPS2DirtySockFPQ29DirtySock12LobbyApiRefTPQ29DirtySock12LobbyApiMsgTPv, this);
    vfunc_14();
}
