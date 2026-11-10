// CB3NetworkMessage::Prepare(int,bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3NetworkMessage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (callee func_0022D850 takes only this (lifter over-passed a1/a2 still live in regs)).

// from build/vt\try_Prepare__17CB3NetworkMessageFib_best.cpp
// CB3NetworkMessage::Prepare(int,bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3NetworkMessage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3NetworkMessage;
struct UnkStruct_D_004E2A14;

struct UnkStruct_D_004E2A14 {
    unsigned short field_0;
};

class CB3NetworkMessage {
public:
    void Prepare(int p0, bool p1);

    unsigned char field_0;
    unsigned char pad_1[0x1];
    unsigned char field_2;
    unsigned char field_3;
    unsigned char pad_4[0x8];
    short field_C;
};

extern UnkStruct_D_004E2A14 D_004E2A14;

extern "C" void func_0022D850(CB3NetworkMessage *);

// 0x001A84A0
void CB3NetworkMessage::Prepare(int p0, bool p1)
{
    unsigned short v0 = D_004E2A14.field_0;
    if (D_004E2A14.field_0 == 65535) {
        v0 = 0;
    }
    if ((field_0 & 2) == 2) {
        func_0022D850(this);
        field_3 = p0;
    } else {
        field_3 = p0;
    }
    field_C = v0;
    if (p1) {
        field_2 = 1;
    }
    field_0 = (field_0 | 1);
}
