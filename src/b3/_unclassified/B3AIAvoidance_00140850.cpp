// CB3AIAvoidanceMap::Update(bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AIAvoidance.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (bool v = false declared before the loop, set true by either test, tested if (!v) (daddiu, no andi)).

// CB3AIAvoidanceMap::Update(bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AIAvoidance.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

#include "b3/GtMath.h"

class CB3AIAvoidanceMap;
class CB3Score;
struct UnkStruct_00140850_5;
struct UnkStruct_D_01E75600;

class CB3Score {
public:
    int WasSlammedWithinTime(float);
};

struct UnkStruct_D_01E75600 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00140850_5 {
    unsigned char pad_0[0x10C0];
    CB3Score field_10C0;
    unsigned char pad_10C1[0xB];
    float field_10CC;
    unsigned char pad_10D0[0x574];
    float field_1644;
};

class CB3AIAvoidanceMap {
public:
    void Update(bool p0);
    void CalculateCarPositionInMap(bool);
    void CheckNoGoZones();
    void CheckRaceCar();
    void CheckTraffic();
    void CheckCrashingTraffic();
    void CalculateCarCoverage();

    unsigned char pad_0[0x40];
    unsigned char field_40[1];  // [G] element count unknown
    unsigned char pad_41[0xFF];
    unsigned char field_140[1];  // [G] element count unknown
    unsigned char pad_141[0xFF];
    short field_240[1];  // [G] element count unknown
    unsigned char pad_242[0x212];
    UnkStruct_00140850_5 * field_454;
};

extern UnkStruct_D_01E75600 D_01E75600;

// 0x00140850
void CB3AIAvoidanceMap::Update(bool p0)
{
    bool v = false;
    for (int i = 0; (i < 256); i++) {
        field_140[i] = 255;
        field_240[i] = ((int)((((float)32767) * GtMath::Min(GtMath::Max(500.0f, -500.0f), 500.0f)) / 500.0f));
        field_40[i] = 0;
    }
    CalculateCarPositionInMap(p0);
    if (field_454->field_10C0.WasSlammedWithinTime(2.0f) != 0) {
        v = true;
    }
    if (field_454->field_10CC < (field_454->field_1644 + D_01E75600.field_0)) {
        v = true;
    }
    if (!v) {
        CheckNoGoZones();
        CheckRaceCar();
        if (p0) {
            CheckTraffic();
            CheckCrashingTraffic();
        }
    }
    CalculateCarCoverage();
}
