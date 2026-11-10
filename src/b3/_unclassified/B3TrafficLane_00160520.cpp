// CB3TrafficLane::DoesNeighbourExist(int,ESegmentNeighbourTypes) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficLane.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

enum ESegmentNeighbourTypes {};

class CB3TrafficLane;
struct UnkStruct_00160520_1;
struct UnkStruct_00160520_e0;

struct UnkStruct_00160520_1 {
    unsigned char pad_0[0x8];
    UnkStruct_00160520_e0 * field_8;
    unsigned char pad_C[0x4];
    int field_10;
};

struct UnkStruct_00160520_e0 {
    unsigned char pad_0[0xC];
    unsigned char field_C[1];  // [G] element count unknown
    unsigned char pad_D[0x5];
};

class CB3TrafficLane {
public:
    bool DoesNeighbourExist(int p0, ESegmentNeighbourTypes p1);

    UnkStruct_00160520_1 * field_0;
};

// 0x00160520
bool CB3TrafficLane::DoesNeighbourExist(int p0, ESegmentNeighbourTypes p1)
{
    if ((p0 >= field_0->field_10) || (p0 < 0)) {
        return 0;
    }
    return ((field_0->field_8[p0].field_C[p1] ^ 255) != 0);
}
