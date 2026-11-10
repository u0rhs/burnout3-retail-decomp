// CB3CrashAnalyser::Construct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CrashAnalyser.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtSphereTreeSphere;

class CB3CrashAnalyser;
struct UnkStruct_00354ED0_e0;
struct UnkStruct_00354ED0_e1;
struct UnkStruct_karParentRadii;

struct UnkStruct_00354ED0_e0 {
    unsigned char pad_0[0x14];
    void * field_14;
    unsigned char pad_18[0x28];
};

struct UnkStruct_karParentRadii {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00354ED0_e1 {
    unsigned char pad_0[0x4];
};

class CB3CrashAnalyser {
public:
    void Construct();

    UnkStruct_00354ED0_e1 field_0[1];  // [G] element count unknown
    unsigned char pad_4[0x7C];
    UnkStruct_00354ED0_e0 field_80[1];  // [G] element count unknown
    unsigned char pad_C0[0xF70];
    int field_1030;
    int field_1034;
    unsigned char pad_1038[0x11];
    unsigned char field_1049;
};

extern UnkStruct_karParentRadii karParentRadii;

extern "C" void Init__13CGtSphereTreeFiiP19CGtSphereTreeSpheref(void *, int, int, void *, float);  // CGtSphereTree::Init(int,int,CGtSphereTreeSphere*,float)
extern "C" void SetMaxParentSize__13CGtSphereTreeFif(void *, int, float);  // CGtSphereTree::SetMaxParentSize(int,float)

// 0x00354ED0
void CB3CrashAnalyser::Construct()
{
    Init__13CGtSphereTreeFiiP19CGtSphereTreeSpheref(this, 1, 10, (CGtSphereTreeSphere*)((char *)this + 0x60), 0.5f);
    for (int i = 0; (i < 10); i++) {
        field_80[i].field_14 = ((char *)&field_0[i] + 0x1008);
    }
    SetMaxParentSize__13CGtSphereTreeFif(this, 0, karParentRadii.field_0);
    field_1049 = 0;
    field_1030 = 0;
    field_1034 = 0;
}
