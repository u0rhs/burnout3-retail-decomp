// CB3TrafficVehicle::ChangeLane(CB3TrafficLane*,float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficVehicle.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (inlined RNG step on the seed globals (rotate+add, as matched siblings); lookup written as if (t3 == 255) v0 = 0; else v0 = &...; owner/fallback colour as && with else).

// lifter variant 0
// CB3TrafficVehicle::ChangeLane(CB3TrafficLane*,float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficVehicle.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3TrafficLane;
enum ETrafficParamState {};

class CB3TrafficParam;
class CB3TrafficVehicle;
struct UnkStruct_00171A00_4;
struct UnkStruct_00171A00_6;
struct UnkStruct_00171A00_e0;
struct UnkStruct_D_00522660;
struct UnkStruct_D_0055D788;
struct UnkStruct_D_0055D78C;
struct UnkStruct_D_0055D7F7;

class CB3TrafficParam {
public:
    void Remove();
    void Insert(CB3TrafficLane*, float, float, ETrafficParamState);
    void CalculateTargetParamMatrix();
    void GetParamInfoFromValve(CB3TrafficLane*, bool, bool);

    unsigned char pad_0[0x45];
    unsigned char field_45;
    unsigned char pad_46[0x5];
    unsigned char field_4B;
};

struct UnkStruct_D_0055D788 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0055D78C {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00171A00_4 {
    unsigned char pad_0[0x40];
    unsigned char field_40;
};

struct UnkStruct_D_0055D7F7 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00171A00_6 {
    unsigned char pad_0[0x177];
    unsigned char field_177;
};

struct UnkStruct_00171A00_e0 {
    unsigned char pad_0[0x50];
};

struct UnkStruct_D_00522660 {
    UnkStruct_00171A00_e0 field_0[1];  // [G] element count unknown
};

class CB3TrafficVehicle {
public:
    void ChangeLane(CB3TrafficLane* p0, float p1);

    unsigned char pad_0[0x110];
    UnkStruct_00171A00_6 * field_110;
    CB3TrafficParam * field_114;
    int field_118;
    int field_11C;
    unsigned char pad_120[0x54];
    unsigned char field_174;
    unsigned char pad_175[0x2];
    unsigned char field_177;
};

extern UnkStruct_D_0055D788 D_0055D788;
extern UnkStruct_D_0055D78C D_0055D78C;
extern UnkStruct_D_0055D7F7 D_0055D7F7;
extern UnkStruct_D_00522660 D_00522660;

// 0x00171A00
void CB3TrafficVehicle::ChangeLane(CB3TrafficLane* p0, float p1)
{
    D_0055D788.field_0 = (D_0055D788.field_0 << 16) + (D_0055D788.field_0 >> 16);
    D_0055D788.field_0 += D_0055D78C.field_0;
    D_0055D78C.field_0 += D_0055D788.field_0;
    float off = 0.5f + (float)((int)((unsigned int)D_0055D788.field_0 % 1000) - 500) / (float)5000;
    unsigned char t3 = field_114->field_45;
    if (t3 != 255) {
        UnkStruct_00171A00_4 * v0;
        if (t3 == 255) {
            v0 = 0;
        } else {
            v0 = (UnkStruct_00171A00_4 *)((char *)&D_00522660.field_0[t3] + 0x2F2B0);
        }
        if (v0->field_40 == 255) {
            if (field_110 != 0 && D_0055D7F7.field_0 == 0) {
                v0->field_40 = field_110->field_177;
            } else {
                v0->field_40 = field_177;
            }
        }
    }
    field_114->Remove();
    field_114->Insert(p0, p1, off, (ETrafficParamState)1);
    field_114->CalculateTargetParamMatrix();
    field_114->GetParamInfoFromValve(p0, (field_174 & 4) != 0, 0);
    field_118 = 0;
    field_11C = 0;
    field_114->field_4B &= ~4;
}
