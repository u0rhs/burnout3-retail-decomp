// CB3VehicleList::GetCarCount(EB3MenuCarClasses) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3DataLists.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (loop index declared before the counter (register order)).

// CB3VehicleList::GetCarCount(EB3MenuCarClasses) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3DataLists.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

enum EB3MenuCarClasses {};

class CB3VehicleList;

class CB3VehicleList {
public:
    int GetCarCount(EB3MenuCarClasses p0);
    static int GetClassFromID(unsigned long);

    unsigned char pad_0[0x4];
    int field_4;
    unsigned char pad_8[0x400];
    unsigned long field_408[1];  // [G] element count unknown
};

// 0x00251B90
int CB3VehicleList::GetCarCount(EB3MenuCarClasses p0)
{
    int i;
    int m0 = 0;
    for (i = 0; (i < field_4); i++) {
        if (CB3VehicleList::GetClassFromID(field_408[i]) == p0) {
            m0++;
        }
    }
    return m0;
}
