// CGtLobbyPS2DirtySock::JoinLobby(int,char*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtLobbyDirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (the lifted for(;;) rewritten as for (i = 0; i < func_0040A5D0(field_560) && field_25C == 0; i++) with the match block returning vfunc_14() inside (as sibling func_003392C0)).

class CGtLobbyPS2DirtySock;
struct UnkStruct_00338260_1;
struct UnkStruct_00338260_3;
struct UnkStruct_D_004C59E8;
struct UnkStruct_D_004E2DAC;
struct UnkStruct_func_00338C10;

struct UnkStruct_D_004E2DAC {
    UnkStruct_00338260_1 * field_0;
};

struct UnkStruct_00338260_1 {
    unsigned char field_0;
};

struct UnkStruct_00338260_3 {
    int field_0;
};

struct UnkStruct_D_004C59E8 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_func_00338C10 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CGtLobbyPS2DirtySock {
public:
    int JoinLobby(int p0, char* p1);
    static int ConvertDirtySockError(int);

    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual int vfunc_14();
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
    unsigned char pad_121[0x13B];
    void * field_25C;
    int field_260;
    unsigned char pad_264[0x2FC];
    int field_560;
};

extern UnkStruct_D_004E2DAC D_004E2DAC;
extern UnkStruct_D_004C59E8 D_004C59E8;
extern UnkStruct_func_00338C10 func_00338C10;

extern "C" void JoinLobbyCallback__20CGtLobbyPS2DirtySockFPQ29DirtySock12LobbyApiRefTPQ29DirtySock12LobbyApiMsgTPv(void *, void *, void*);  // CGtLobbyPS2DirtySock::JoinLobbyCallback(DirtySock::LobbyApiRefT*,DirtySock::LobbyApiMsgT*,void*), its address taken
extern "C" void TagFieldSetNumber(UnkStruct_00338260_1 *, int, void *, int);
extern "C" void DispListFilt(int, int, int, void *);
extern "C" void DispListOrder(int);
extern "C" int func_0040A5D0(int);
extern "C" UnkStruct_00338260_3 * DispListIndex(int, int);
extern "C" void LobbyApiRequestCB(int, int, UnkStruct_00338260_1 *, void *, CGtLobbyPS2DirtySock *);

// 0x00338260
int CGtLobbyPS2DirtySock::JoinLobby(int p0, char* p1)
{
    D_004E2DAC.field_0->field_0 = 0;
    TagFieldSetNumber(D_004E2DAC.field_0, 1024, &D_004C59E8, p0);
    DispListFilt(field_560, 0, 1, &func_00338C10);
    DispListOrder(field_560);
    field_25C = 0;
    for (int i = 0; i < func_0040A5D0(field_560) && field_25C == 0; i++) {
        UnkStruct_00338260_3 * r4 = DispListIndex(field_560, i);
        if (r4 == 0) {
            continue;
        }
        if (r4->field_0 != p0) {
            continue;
        }
        field_25C = (void *)r4;
        field_260 = r4->field_0;
        field_110 = 1;
        field_111 = 0;
        field_112 = 0;
        field_120 = 0;
        field_114 = 0;
        LobbyApiRequestCB(field_104, 0x6D6F7665, D_004E2DAC.field_0, (void *)&JoinLobbyCallback__20CGtLobbyPS2DirtySockFPQ29DirtySock12LobbyApiRefTPQ29DirtySock12LobbyApiMsgTPv, this);
        return vfunc_14();
    }
    int r7 = CGtLobbyPS2DirtySock::ConvertDirtySockError(0x75726F6D);
    field_112 = 1;
    field_110 = 0;
    field_114 = r7;
    return 1;
}
