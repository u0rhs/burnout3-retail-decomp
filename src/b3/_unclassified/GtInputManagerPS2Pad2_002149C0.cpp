// CGtInputManagerPS2Pad2::GetPadControls(EGtPS2InputPort) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtInputManagerPS2Pad2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (bool v = p0>=0; if (v) v = p0<2; if (v == false) return 0; return &field_218[p0]; (== false gives the andi 0xFF, !v doesn't)).

enum EGtPS2InputPort {};
struct UnkStruct_002149C0_e0 {
    unsigned char pad_0[0x20];
};
class CGtInputManagerPS2Pad2 {
public:
    UnkStruct_002149C0_e0 * GetPadControls(EGtPS2InputPort p0);

    unsigned char pad_0[0x218];
    UnkStruct_002149C0_e0 field_218[2];
};

UnkStruct_002149C0_e0 * CGtInputManagerPS2Pad2::GetPadControls(EGtPS2InputPort p0)
{
    bool v = p0 >= 0;
    if (v) {
        v = p0 < 2;
    }
    if (v == false) {
        return 0;
    }
    return &field_218[p0];
}
