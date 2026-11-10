// CB3PropPhysics::Construct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3PropPhysics.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (&field_230 / &field_570 member addresses instead of this+K casts (no CSE across them)).

// lifter variant 0
// CB3PropPhysics::Construct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3PropPhysics.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3ConvexHullProp;
class CB3PropPhysics;

class CB3ConvexHullProp {
public:
    void Initialise();
};

class CB3PropPhysics {
public:
    void Construct();

    unsigned char pad_0[0x200];
    void * field_200;
    unsigned char pad_204[0x11];
    unsigned char field_215;
    unsigned char pad_216[0xA];
    int field_220;
    float field_224;
    unsigned char pad_228[0x8];
    int field_230;
    void * field_234;
    void * field_238;
    unsigned char pad_23C[0x334];
    CB3ConvexHullProp field_570;
};

extern "C" void * memset(void *, int, unsigned int);
extern "C" void func_001AD850(CB3PropPhysics *);

// 0x001BE8F0
void CB3PropPhysics::Construct()
{
    func_001AD850(this);
    field_215 = 6;
    field_220 = 0;
    field_224 = -1.0f;
    memset(&field_230, 0, 816);
    memset(((char *)this + 0x560), 0, 16);
    memset(&field_570, 0, 528);
    field_570.Initialise();
    field_230 = 0;
    field_234 = ((char *)this + 0x240);
    field_238 = ((char *)this + 0x540);
    field_230 = -1;
    field_200 = &field_230;
}
