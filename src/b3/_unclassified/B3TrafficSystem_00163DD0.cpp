// CB3TrafficSystem::AddToDeadTrafficParamList(CB3TrafficParam*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3TrafficSystem.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (bitset clear: arr[(unsigned short)(uc / 32)] &= ~(1 << (uc % 32)) replaces the lifter's expanded signed-mod sequence).

// CB3TrafficSystem::AddToDeadTrafficParamList(CB3TrafficParam*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3TrafficSystem.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3TrafficParam;

class CB3TrafficSystem;
struct CB3TrafficParam;
struct UnkStruct_00163DD0_1;

struct UnkStruct_00163DD0_1 {
    unsigned char pad_0[0x49];
    unsigned char field_49;
};

struct CB3TrafficParam {
    unsigned char pad_0[0x44];
    unsigned char field_44;
    unsigned char pad_45[0x4];
    unsigned char field_49;
    unsigned char pad_4A[0x1];
    unsigned char field_4B;
};

class CB3TrafficSystem {
public:
    void AddToDeadTrafficParamList(CB3TrafficParam* p0);

    unsigned char pad_0[0x36300];
    int field_36300[1];  // [G] element count unknown
    unsigned char pad_36304[0x68];
    UnkStruct_00163DD0_1 * field_3636C;
};

extern "C" void func_00162BE0(CB3TrafficParam *, CB3TrafficParam *);

// 0x00163DD0
void CB3TrafficSystem::AddToDeadTrafficParamList(CB3TrafficParam* p0)
{
    func_00162BE0(p0, p0);
    p0->field_44 = field_3636C->field_49;
    field_3636C = (UnkStruct_00163DD0_1 *)p0;
    unsigned char t0 = p0->field_49;
    field_36300[(unsigned short)(t0 / 32)] &= ~(1 << (t0 % 32));
    p0->field_4B = (p0->field_4B & 247);
}
