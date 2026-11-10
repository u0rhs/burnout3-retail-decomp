// CB3TrafficPhysics::Prepare() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3TrafficPhysics.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (callee + method return bool; bool r0 = call; return r0 (was int, r0&255)).

// CB3TrafficPhysics::Prepare() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3TrafficPhysics.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3TrafficPhysics;

class CB3TrafficPhysics {
public:
    bool Prepare();

    unsigned char pad_0[0x2420];
    int field_2420;
    int field_2424;
    unsigned char field_2428;
    unsigned char field_2429;
    unsigned char pad_242A[0x1];
    unsigned char field_242B;
    unsigned char field_242C;
};

extern "C" bool Prepare__17CB3VehiclePhysicsFv(void *);  // CB3VehiclePhysics::Prepare()
extern "C" void * memset(void *, int, unsigned int);

// 0x002513F0
bool CB3TrafficPhysics::Prepare()
{
    bool r0 = Prepare__17CB3VehiclePhysicsFv(this);
    memset(((char *)this + 0x1360), 0, 128);
    memset(((char *)this + 0x13E0), 0, 4160);
    field_2420 = 0;
    field_2424 = 0;
    field_2428 = 0;
    field_2429 = 0;
    field_242B = 0;
    field_242C = 1;
    return r0;
}
