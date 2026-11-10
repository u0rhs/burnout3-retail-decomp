// CGtInputManagerPS2Pad2::GetConnectedDeviceID(EGtPS2InputPort) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtInputManagerPS2Pad2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (materialized && as int v = p >= 0; if (v) v = p < 2; tested as (unsigned char)v == 0 (gives the slt/xori, beqz on v, andi 255)).

// CGtInputManagerPS2Pad2::GetConnectedDeviceID(EGtPS2InputPort) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtInputManagerPS2Pad2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

enum EGtPS2InputPort {};

class CGtInputManagerPS2Pad2;

class CGtInputManagerPS2Pad2 {
public:
    int GetConnectedDeviceID(EGtPS2InputPort p0);

    unsigned char pad_0[0x210];
    int field_210[1];  // [G] element count unknown
};

int CGtInputManagerPS2Pad2::GetConnectedDeviceID(EGtPS2InputPort p0)
{
    int v0 = p0 >= 0;
    if (v0) {
        v0 = p0 < 2;
    }
    if ((unsigned char)v0 == 0) return 0;
    return field_210[p0];
}
