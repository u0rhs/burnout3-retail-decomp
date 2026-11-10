// CGtLobbyPS2DirtySock::LeaveGameImmediately() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> GtLobbyDirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a74: lifter draft matches as-is).

// from build/vt\try_LeaveGameImmediately__20CGtLobbyPS2Dirty_best.cpp
// CGtLobbyPS2DirtySock::LeaveGameImmediately() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> GtLobbyDirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtLobbyPS2DirtySock;
struct UnkStruct_00335DE0_1;
struct UnkStruct_00335DE0_3;
struct UnkStruct_D_004C5850;
struct UnkStruct_D_004C5858;
struct UnkStruct_D_004E2DAC;

struct UnkStruct_D_004E2DAC {
    UnkStruct_00335DE0_1 * field_0;
};

struct UnkStruct_00335DE0_1 {
    unsigned char field_0;
};

struct UnkStruct_00335DE0_3 {
    unsigned char pad_0[0x114];
    int field_114;
};

struct UnkStruct_D_004C5850 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004C5858 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CGtLobbyPS2DirtySock {
public:
    void LeaveGameImmediately();

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
    unsigned char pad_121[0x13];
    UnkStruct_00335DE0_3 * field_134;
};

extern UnkStruct_D_004E2DAC D_004E2DAC;
extern UnkStruct_D_004C5850 D_004C5850;
extern UnkStruct_D_004C5858 D_004C5858;

extern "C" void DefaultCallback__20CGtLobbyPS2DirtySockFPQ29DirtySock12LobbyApiRefTPQ29DirtySock12LobbyApiMsgTPv(void *, void *, void*);  // CGtLobbyPS2DirtySock::DefaultCallback(DirtySock::LobbyApiRefT*,DirtySock::LobbyApiMsgT*,void*), its address taken
extern "C" void TagFieldSetString(UnkStruct_00335DE0_1 *, int, void *, void *);
extern "C" void TagFieldSetNumber(UnkStruct_00335DE0_1 *, int, void *, int);
extern "C" void LobbyApiRequestCB(int, int, UnkStruct_00335DE0_1 *, void *, CGtLobbyPS2DirtySock *);

// 0x00335DE0
void CGtLobbyPS2DirtySock::LeaveGameImmediately()
{
    D_004E2DAC.field_0->field_0 = 0;
    TagFieldSetString(D_004E2DAC.field_0, 1024, &D_004C5850, ((char *)field_134 + 0x4));
    TagFieldSetNumber(D_004E2DAC.field_0, 1024, &D_004C5858, (field_134->field_114 | 4096));
    LobbyApiRequestCB(field_104, 0x67736574, D_004E2DAC.field_0, (void *)&DefaultCallback__20CGtLobbyPS2DirtySockFPQ29DirtySock12LobbyApiRefTPQ29DirtySock12LobbyApiMsgTPv, this);
    field_110 = 1;
    field_111 = 0;
    field_112 = 0;
    field_120 = 0;
    field_114 = 0;
    vfunc_14();
}
