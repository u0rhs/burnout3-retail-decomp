// CB3StageLogic::OnWorldPrepared() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3StageLogic.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (callee func_0013C390 takes (void*, int): dropped the lifter's 2 phantom args (a2/a3 were loop constants left in regs)).

// from build/vt\try_OnWorldPrepared__13CB3StageLogicFv_best.cpp
// CB3StageLogic::OnWorldPrepared() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3StageLogic.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3StageLogic;
struct UnkStruct_D_0051BF9C;
struct UnkStruct_D_0051C610;
struct UnkStruct_D_0064D3A0;

struct UnkStruct_D_0064D3A0 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051BF9C {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0051C610 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3StageLogic {
public:
    void OnWorldPrepared();

    unsigned char pad_0[0x8];
    int field_8[1];  // [G] element count unknown
    unsigned char pad_C[0x4];
    float field_10[1];  // [G] element count unknown
    unsigned char pad_14[0x4];
    float field_18[1];  // [G] element count unknown
};

extern UnkStruct_D_0064D3A0 D_0064D3A0;
extern UnkStruct_D_0051BF9C D_0051BF9C;
extern UnkStruct_D_0051C610 D_0051C610;

extern "C" void func_0013C390(void *, int);

// 0x00395970
void CB3StageLogic::OnWorldPrepared()
{
    for (int i = 0; (i < D_0064D3A0.field_0); i++) {
        field_8[i] = 0;
        field_10[i] = 10.0f;
        field_18[i] = 4.0f;
    }
    int t0 = D_0051BF9C.field_0;
    if (t0 == 0) return;
    func_0013C390(&D_0051C610, t0);
}
