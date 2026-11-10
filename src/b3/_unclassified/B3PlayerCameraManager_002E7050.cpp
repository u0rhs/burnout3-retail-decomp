// CB3PlayerCameraManager::GetTrackTime() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3PlayerCameraManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3PlayerCameraManager;
class CB3Score;
struct UnkStruct_002E7050_3;
struct UnkStruct_002E7050_4;
struct UnkStruct_002E7050_e0;
struct UnkStruct_D_0055EFEC;

class CB3Score {
public:
    float GetTotalRaceDistFromAILaneStart();
};

struct UnkStruct_002E7050_e0 {
    UnkStruct_002E7050_3 * field_0;
    unsigned char pad_4[0x2C];
};

struct UnkStruct_D_0055EFEC {
    UnkStruct_002E7050_e0 field_0[1];  // [G] element count unknown
};

struct UnkStruct_002E7050_3 {
    unsigned char pad_0[0x13F4];
    UnkStruct_002E7050_4 * field_13F4;
};

struct UnkStruct_002E7050_4 {
    unsigned char pad_0[0x10C0];
    CB3Score field_10C0;
};

class CB3PlayerCameraManager {
public:
    float GetTrackTime();

    unsigned char pad_0[0xB94];
    int field_B94;
};

extern UnkStruct_D_0055EFEC D_0055EFEC;

// 0x002E7050
float CB3PlayerCameraManager::GetTrackTime()
{
    float r0 = D_0055EFEC.field_0[field_B94].field_0->field_13F4->field_10C0.GetTotalRaceDistFromAILaneStart();
    return (r0 / 100.0f);
}
