// CB3OnlineLobbyPage::UpdateConfirmLeave() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3OnlineLobbyPage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (early returns -> if (r1 == 4) {...} else if (r1 == 5) {...}; the two 0041E8A0/0041E8B0 tests merged into one || condition).

// CB3OnlineLobbyPage::UpdateConfirmLeave() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3OnlineLobbyPage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3HUDSoundManager;
class CB3OnlineLobbyPage;
struct UnkStruct_00314720_3;
struct UnkStruct_D_01E32AE0;
struct UnkStruct_D_01E33A8C;
struct UnkStruct_D_01E3CD44;
struct UnkStruct_D_01E898E8;

class CB3HUDSoundManager {
public:
    void FESelect();
    void FEBack();

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E898E8 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E3CD44 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual void vfunc_20();
    virtual void vfunc_24();
    virtual void vfunc_28();
    virtual void vfunc_2C();
    virtual void vfunc_30();
    virtual void vfunc_34();
    virtual void vfunc_38();
    virtual void vfunc_3C();
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00314720_3 {
    unsigned char pad_0[0xC];
    int field_C;
};

struct UnkStruct_D_01E32AE0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E33A8C {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3OnlineLobbyPage {
public:
    void UpdateConfirmLeave();

    unsigned char pad_0[0x13AC];
    unsigned char field_13AC;
};

extern UnkStruct_D_01E898E8 D_01E898E8;
extern UnkStruct_D_01E3CD44 D_01E3CD44;
extern UnkStruct_D_01E32AE0 D_01E32AE0;
extern CB3HUDSoundManager D_01E7A800;
extern UnkStruct_D_01E33A8C D_01E33A8C;

extern "C" int AmIHost__17CB3NetworkManagerFv(void *);  // CB3NetworkManager::AmIHost()
extern "C" int func_0032B2C0(void *, int, int);
extern "C" void func_0032D080(void *, int, int, int, int);
extern "C" int func_0041E8A0(void *);
extern "C" void func_0041E9A0(void *);
extern "C" int func_0041E8B0(void *);
extern "C" void func_00316640(CB3OnlineLobbyPage *);

// 0x00314720
void CB3OnlineLobbyPage::UpdateConfirmLeave()
{
    int r0 = AmIHost__17CB3NetworkManagerFv(&D_01E32AE0);
    int r1 = func_0032B2C0(&D_01E898E8, 0, ((r0 != 0) ^ 1));
    if (r1 == 4) {
        ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
        func_0032D080(&D_01E898E8, 0, 951, 15, 0);
        field_13AC = 10;
        ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_3C();
        D_01E7A800.FESelect();
        if (func_0041E8A0(&D_01E33A8C) || func_0041E8B0(&D_01E33A8C)) {
            func_0041E9A0(&D_01E33A8C);
        }
    } else if (r1 == 5) {
        ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
        func_00316640(this);
        D_01E7A800.FEBack();
    }
}
