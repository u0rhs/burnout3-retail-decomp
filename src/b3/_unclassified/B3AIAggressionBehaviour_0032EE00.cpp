// CB3AIAggressionBehaviour::UpdateAggressiveHornBlast() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AIAggressionBehaviour.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a71: early returns (return after first arm, return on field_58==0) give retail's two b-exit blocks; 0.05f lit4, rotate-right-1 of field_54).

// CB3AIAggressionBehaviour::UpdateAggressiveHornBlast()
struct UnkStruct_D_0052267C {
    float field_0;
    unsigned char pad_4[0xC];
};
extern UnkStruct_D_0052267C D_0052267C;

struct UnkStruct_HornOwner {
    unsigned char pad_0[0x18ED];
    unsigned char field_18ED;
};

class CB3AIAggressionBehaviour {
public:
    void UpdateAggressiveHornBlast();

    unsigned char pad_0[0x44];
    UnkStruct_HornOwner * field_44;
    unsigned char pad_48[0x4];
    float field_4C;
    float field_50;
    unsigned int field_54;
    unsigned char field_58;
};

// 0x0032EE00
void CB3AIAggressionBehaviour::UpdateAggressiveHornBlast()
{
    field_44->field_18ED = 0;
    field_4C = field_4C - D_0052267C.field_0;
    if (field_4C <= 0.0f) {
        if (field_58 == 0) {
            field_4C = 0.0f;
        } else {
            field_4C = 25.0f;
            field_58 = 0;
        }
        return;
    }
    if (field_58 == 0) {
        return;
    }
    field_50 = field_50 - D_0052267C.field_0;
    if (field_50 <= 0.0f) {
        field_50 = field_50 + 0.05f;
        unsigned int b = field_54 & 1;
        field_54 = field_54 >> 1;
        field_54 = field_54 | (b << 31);
    }
    if ((field_54 & 1) == 1) {
        field_44->field_18ED = 1;
    }
}
