// CB3TrafficSystem::VehicleIsValid(unsigned char) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3TrafficSystem.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (bitset test: (arr[p0 / 32] & (1 << (p0 % 32))) != 0 with unsigned char p0 (no unsigned short cast here)).

// from build/vt\try_VehicleIsValid__16CB3TrafficSystemFUc_best.cpp
// CB3TrafficSystem::VehicleIsValid(unsigned char) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3TrafficSystem.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3TrafficSystem;

class CB3TrafficSystem {
public:
    bool VehicleIsValid(unsigned char p0);

    unsigned char pad_0[0x362E0];
    int field_362E0[1];  // [G] element count unknown
};

// 0x001631F0
bool CB3TrafficSystem::VehicleIsValid(unsigned char p0)
{
    return (field_362E0[p0 / 32] & (1 << (p0 % 32))) != 0;
}
