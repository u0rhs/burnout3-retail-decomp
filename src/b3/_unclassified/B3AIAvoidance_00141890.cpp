// CB3AIAvoidance::Update() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AIAvoidance.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (callee func_001419B0 declared bool and its call passed directly as the bool argument (no temp: a bool temp adds andi 255)).

// CB3AIAvoidance::Update() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AIAvoidance.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3AIAvoidance;

class CB3AIAvoidance {
public:
    void Update();
    void GenerateTarget();

    unsigned char pad_0[0x4A4];
    int field_4A4;
    unsigned char pad_4A8[0x7];
    unsigned char field_4AF;
};

extern "C" void Update__17CB3AIAvoidanceMapFb(void *, bool);  // CB3AIAvoidanceMap::Update(bool)
extern "C" bool func_001419B0(void *);

struct UnkStruct_00141890_pad {
    unsigned char field_0[0x4];
    UnkStruct_00141890_pad() {}
    ~UnkStruct_00141890_pad() {}
};

// 0x00141890
void CB3AIAvoidance::Update()
{
    UnkStruct_00141890_pad pad;  // [G] an unused local object: retail's frame keeps 0x10 unused bytes at its top (a scoped object with a constructor/destructor reserves its slot, known.md N140)
    field_4AF = (field_4AF + 1);
    if (field_4AF < 3) return;
    field_4AF = 0;
    Update__17CB3AIAvoidanceMapFb(this, func_001419B0((void *)(field_4A4)));
    GenerateTarget();
}
