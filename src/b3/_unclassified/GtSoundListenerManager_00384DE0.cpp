// CGtSoundListenerManager::Construct(RwaSPU2Output*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundListenerManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (lit4 extern D_004E1170 -> float literal 0.01f (literal loads schedule freely, extern loads don't); for(unsigned i) loop; |= 16).

// from build/vt\try_Construct__23CGtSoundListenerManagerFP13_best.cpp
// CGtSoundListenerManager::Construct(RwaSPU2Output*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundListenerManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class RwaSPU2Output;

class CGtSoundListenerManager;
struct RwaSPU2Output;
struct UnkStruct_00384DE0_4;
struct UnkStruct_D_004E1170;

struct UnkStruct_D_004E1170 {
    float field_0;
};

struct RwaSPU2Output {
    unsigned char pad_0[0x1418];
    int field_1418;
};

struct UnkStruct_00384DE0_4 {
    unsigned char pad_0[0x7C];
    float field_7C;
    unsigned char pad_80[0x8];
    int field_88;
};

class CGtSoundListenerManager {
public:
    void Construct(RwaSPU2Output* p0);

    int field_0[1];  // [G] element count unknown
    unsigned char pad_4[0x8];
    RwaSPU2Output * field_C;
    UnkStruct_00384DE0_4 * field_10;
};

extern UnkStruct_D_004E1170 D_004E1170;

extern "C" int RwaListenerCreate(int, int, int);
extern "C" void RwaListenerManagerSetMode(int);

void CGtSoundListenerManager::Construct(RwaSPU2Output* p0)
{
    field_10 = (UnkStruct_00384DE0_4 *)RwaListenerCreate(4, 0, 0);
    for (unsigned int i = 0; i < 2; i++) {
        field_0[i] = 0;
    }
    p0->field_1418 = (int)field_10;
    field_10->field_7C = 0.01f;
    field_10->field_88 |= 16;
    RwaListenerManagerSetMode(3);
    field_C = p0;
}
