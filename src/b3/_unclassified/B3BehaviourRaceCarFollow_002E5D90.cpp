// CB3BehaviourRaceCarFollow::Construct(int,bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3BehaviourRaceCarFollow.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3BehaviourRaceCarFollow;
class CB3CameraAttribsCar;
struct UnkStruct_002E5D90_3;

class CB3CameraAttribsCar {
public:
    static int Prepare(unsigned long);
};

struct UnkStruct_002E5D90_3 {
    unsigned char pad_0[0x1960];
    unsigned long field_1960;
};

class CB3BehaviourRaceCarFollow {
public:
    void Construct(int p0, bool p1);

    unsigned char pad_0[0x8];
    int field_8;
    unsigned char pad_C[0x4];
    unsigned long field_10;
    unsigned char pad_18[0x8];
    int field_20;
    unsigned char pad_24[0x1];
    unsigned char field_25;
    bool field_26;
};

extern UnkStruct_002E5D90_3 * D_0064D388[];  // [G] element count unknown

extern "C" void Construct__18CB3CameraBehaviourFv(void *);  // CB3CameraBehaviour::Construct()

// 0x002E5D90
void CB3BehaviourRaceCarFollow::Construct(int p0, bool p1)
{
    Construct__18CB3CameraBehaviourFv(this);
    field_20 = p0;
    field_10 = D_0064D388[field_20]->field_1960;
    int r1 = CB3CameraAttribsCar::Prepare(field_10);
    field_8 = (r1 + 96);
    field_25 = 0;
    field_26 = p1;
}
