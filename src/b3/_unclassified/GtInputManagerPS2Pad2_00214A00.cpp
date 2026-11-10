// CGtInputManagerPS2Pad2::GetSocketNumber(EGtPS2InputPort) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtInputManagerPS2Pad2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (bool v0 = p0 >= 0; if (v0) v0 = p0 < 2; -- test the bool var itself, not a re-spelled !(p0<0) (that folds to bltz a1)).

// CGtInputManagerPS2Pad2::GetSocketNumber(EGtPS2InputPort) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtInputManagerPS2Pad2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

enum EGtPS2InputPort {};

class CGtInputManagerPS2Pad2;

class CGtInputManagerPS2Pad2 {
public:
    int GetSocketNumber(EGtPS2InputPort p0);

    unsigned char pad_0[0x258];
    int field_258[1];  // [G] element count unknown
};

// 0x00214A00
int CGtInputManagerPS2Pad2::GetSocketNumber(EGtPS2InputPort p0)
{
    bool v0 = p0 >= 0;
    if (v0) {
        v0 = p0 < 2;
    }
    int v1;
    if (v0 == 0) {
        v1 = 0;
    } else {
        v1 = field_258[p0];
    }
    return v1;
}
