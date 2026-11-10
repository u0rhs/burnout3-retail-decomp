// CB3CrashAnalyser::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CrashAnalyser.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (for loop; the call argument (element address + 0x2E0) taken into a local before the flag test).

// CB3CrashAnalyser::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CrashAnalyser.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtSphereTreeSphere;

class CB3CrashAnalyser;
struct UnkStruct_00353990_e0;
struct UnkStruct_00353990_e1;

struct UnkStruct_00353990_e0 {
    unsigned char pad_0[0x39];
    unsigned char field_39;
    unsigned char pad_3A[0x36];
};

struct UnkStruct_00353990_e1 {
    unsigned char pad_0[0x70];
};

class CB3CrashAnalyser {
public:
    void Release();

    UnkStruct_00353990_e1 field_0[1];  // [G] element count unknown
    unsigned char pad_70[0x2A0];
    UnkStruct_00353990_e0 field_310[1];  // [G] element count unknown
    unsigned char pad_380[0xCB0];
    int field_1030;
    int field_1034;
    unsigned char pad_1038[0x11];
    unsigned char field_1049;
};

extern "C" void RemoveSphere__13CGtSphereTreeFP19CGtSphereTreeSphere(void *, void *);  // CGtSphereTree::RemoveSphere(CGtSphereTreeSphere*)

void CB3CrashAnalyser::Release()
{
    for (int i = 0; i < field_1030; i++) {
        CGtSphereTreeSphere * s = (CGtSphereTreeSphere *)((char *)&field_0[i] + 0x2E0);
        if (field_310[i].field_39 == 0) {
            RemoveSphere__13CGtSphereTreeFP19CGtSphereTreeSphere(this, s);
        }
    }
    field_1049 = 0;
    field_1034 = 0;
    field_1030 = 0;
}
