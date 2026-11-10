// CGtSoundStream::Construct(RwaSPU2Output*,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundStream.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (int k = 56 local + scoped opt_propagation off [G] keeps li/mult (no strength reduction)).

// CGtSoundStream::Construct(RwaSPU2Output*,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundStream.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class RwaSPU2Output;

class CGtSoundStream;
struct UnkStruct_ourGlobals;

struct UnkStruct_ourGlobals {
    unsigned char pad_0[0x134];
    int field_134;
};

class CGtSoundStream {
public:
    void Construct(RwaSPU2Output* p0, int p1);

    unsigned char pad_0[0x130];
    int field_130;
    int field_134;
    int field_138;
    int field_13C;
    int field_140;
    unsigned char pad_144[0x60];
    int field_1A4[1];  // [G] element count unknown
    unsigned char pad_1A8[0x1C];
    int field_1C4;
    unsigned char pad_1C8[0x4];
    int field_1CC;
    int field_1D0;
    unsigned char pad_1D4[0x20];
    unsigned char field_1F4;
    unsigned char field_1F5;
    unsigned char field_1F6;
};

extern UnkStruct_ourGlobals ourGlobals;

extern "C" int RwaStreamCreate(RwaSPU2Output*, int, int, int, int);

// N182: `#pragma opt_propagation off` ([G] scoped to this function): keeps `k` a variable, so 56*p1
// stays retail's li/mult instead of the shift/subtract strength reduction.
#pragma push
#pragma opt_propagation off
// 0x003868C0
void CGtSoundStream::Construct(RwaSPU2Output* p0, int p1)
{
    int r0 = RwaStreamCreate(p0, 0, 0, 0, 0);
    field_1CC = r0;
    int i = 0;
    goto loop0_test;
loop0_body:
    {
        field_1A4[i] = 0;
    }
    i++;
loop0_test:
    if ((unsigned int)i < (unsigned int)8) goto loop0_body;
    int k = 56;
    int r1 = ((int (*)(int, int))ourGlobals.field_134)((k * p1), 0);
    field_130 = r1;
    field_13C = p1;
    field_1F4 = 0;
    field_1D0 = 0;
    field_1F5 = 0;
    field_1F6 = 0;
    field_134 = 0;
    field_138 = 0;
    field_140 = 0;
    field_1C4 = 0;
}

#pragma pop
