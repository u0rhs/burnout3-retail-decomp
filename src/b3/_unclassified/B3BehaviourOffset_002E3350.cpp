// CB3BehaviourOffset::Construct(EB3BehaviourType,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3BehaviourOffset.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (phantom args dropped: CB3CameraAttribsCar::Prepare(unsigned long) is static, one 64-bit arg in a0).

// CB3BehaviourOffset::Construct(EB3BehaviourType,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3BehaviourOffset.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

enum EB3BehaviourType {};

class CB3BehaviourOffset;
struct UnkStruct_002E3350_3;

struct UnkStruct_002E3350_3 {
    unsigned char pad_0[0x1960];
    unsigned long field_1960;
};

class CB3BehaviourOffset {
public:
    void Construct(EB3BehaviourType p0, int p1);

    unsigned char pad_0[0xC];
    int field_C;
    unsigned char pad_10[0x10];
    unsigned long field_20;
    int field_28;
    int field_2C;
};

extern UnkStruct_002E3350_3 * D_0064D388[];  // [G] element count unknown

extern "C" int Prepare__19CB3CameraAttribsCarFUl(unsigned long);  // CB3CameraAttribsCar::Prepare(unsigned long) [G] static: a0 holds the 64-bit argument

// 0x002E3350
void CB3BehaviourOffset::Construct(EB3BehaviourType p0, int p1)
{
    field_28 = p1;
    field_20 = D_0064D388[field_28]->field_1960;
    field_2C = p0;
    switch (field_2C) {
    case 0:
        field_C = Prepare__19CB3CameraAttribsCarFUl(field_20) + 48;
        break;
    case 1:
        field_C = Prepare__19CB3CameraAttribsCarFUl(field_20);
        break;
    case 5:
    case 6:
    case 7:
        field_C = 0;
        break;
    default:
        field_C = 0;
        break;
    }
}
