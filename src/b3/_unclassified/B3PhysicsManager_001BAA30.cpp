// CB3ActiveBody::GetNetworkCollBodyType() const -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3PhysicsManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (switch with early returns, case 4 via int r, int g).

struct UnkStruct_D_0064ED5C { signed char field_0; unsigned char pad_1[0xF]; };
extern UnkStruct_D_0064ED5C D_0064ED5C;
struct UnkStruct_001BAA30_o { unsigned char pad_0[0x242B]; signed char field_242B; };
class CB3ActiveBody {
public:
    signed char field_0;
    unsigned char pad_1[0xB];
    UnkStruct_001BAA30_o *field_C;
    int GetNetworkCollBodyType() const;
};
// 0x001BAA30
int CB3ActiveBody::GetNetworkCollBodyType() const
{
    int g = D_0064ED5C.field_0;
    switch (field_0) {
    case 0: case 2: return 0;
    case 1: return 1;
    case 3: return 2;
    case 4: {
        int r;
        if (g == field_C->field_242B) r = 3; else r = 5;
        return r;
    }
    case 5: case 6: case 7: return 6;
    default: return 6;
    }
}
