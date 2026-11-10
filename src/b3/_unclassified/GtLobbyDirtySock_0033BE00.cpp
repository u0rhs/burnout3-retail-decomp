// CGtLobbyPS2DirtySock::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtLobbyDirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (void* handles; outer test written 'if (field_61C)' (not '!= 0') moves its block to the function end; nested null test for the D_004E2DAC free; '> -1' for slti).

// lifter variant 0
// CGtLobbyPS2DirtySock::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtLobbyDirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtLobbyPS2DirtySock;
struct UnkStruct_D_004E2DAC;
struct UnkStruct__gMemoryAllocator;

struct UnkStruct_D_004E2DAC {
    void * field_0;
};

struct UnkStruct__gMemoryAllocator {
    unsigned char pad_0[0x4];  // [G] size: gp-relative addressing needs <= 8 bytes
};

class CGtLobbyPS2DirtySock {
public:
    void Release();

    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual int vfunc_14();
    unsigned char pad_4[0x100];
    void * field_104;
    unsigned char pad_108[0x9];
    unsigned char field_111;
    unsigned char pad_112[0xC];
    unsigned char field_11E;
    unsigned char pad_11F[0x441];
    void * field_560;
    void * field_564;
    void * field_568;
    void * field_56C;
    unsigned char pad_570[0x9C];
    int field_60C;
    int field_610;
    int field_614;
    int field_618;
    void * field_61C;
    unsigned char pad_620[0xC];
    void * field_62C;
};

extern UnkStruct_D_004E2DAC D_004E2DAC;
extern UnkStruct__gMemoryAllocator _gMemoryAllocator;

extern "C" int func_0040C9D0(void *, int);
extern "C" void func_0040C848(void *);
extern "C" void Free__9CGtMallocFPv(void *, void *);
extern "C" void func_0040E508(void *);
extern "C" void LobbyApiListFree(void *, int, void *);
extern "C" void LobbyApiClearCallback(void *, int);
extern "C" void LobbyApiDestroy(void *);

// 0x0033BE00
void CGtLobbyPS2DirtySock::Release()
{
    if (field_61C) {
        if (vfunc_14() != 2) {
            if (func_0040C9D0(field_61C, 0x63617465) == 0 || func_0040C9D0(field_61C, 0x6C697374) == 0) {
                field_111 = 1;
            }
        }
        if (field_61C != 0) {
            func_0040C848(field_61C);
            field_61C = 0;
        }
    }
    if (D_004E2DAC.field_0 != 0) {
        if (D_004E2DAC.field_0 != 0) {
            Free__9CGtMallocFPv(&_gMemoryAllocator, D_004E2DAC.field_0);
        }
        D_004E2DAC.field_0 = 0;
    }
    if (field_62C != 0) {
        func_0040E508(field_62C);
        field_62C = 0;
    }
    if (field_560 != 0) {
        LobbyApiListFree(field_104, 0, field_560);
        field_560 = 0;
    }
    if (field_564 != 0) {
        LobbyApiListFree(field_104, 5, field_564);
        field_564 = 0;
    }
    if (field_568 != 0) {
        LobbyApiListFree(field_104, 4, field_568);
        field_568 = 0;
    }
    if (field_56C != 0) {
        LobbyApiListFree(field_104, 1, field_56C);
        field_56C = 0;
    }
    if (field_60C > -1) {
        LobbyApiClearCallback(field_104, field_60C);
        field_60C = -1;
    }
    if (field_610 > -1) {
        LobbyApiClearCallback(field_104, field_610);
        field_610 = -1;
    }
    if (field_614 > -1) {
        LobbyApiClearCallback(field_104, field_614);
        field_614 = -1;
    }
    if (field_618 > -1) {
        LobbyApiClearCallback(field_104, field_618);
        field_618 = -1;
    }
    if (field_104 != 0) {
        LobbyApiDestroy(field_104);
        field_104 = 0;
    }
    field_11E = 0;
}
