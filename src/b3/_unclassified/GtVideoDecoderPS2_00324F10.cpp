// CGtVideoDecoder::GetImage() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtVideoDecoderPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

struct UnkStruct_00324F10_e0;

struct UnkStruct_00324F10_e0 {
    unsigned char pad_0[0x18];
};

class CGtVideoDecoder {
public:
    void * GetImage();

    UnkStruct_00324F10_e0 field_0[1];  // [G] element count unknown
    unsigned char pad_18[0x1C];
    int field_34;
};

// 0x00324F10
void * CGtVideoDecoder::GetImage()
{
    return &field_0[field_34];
}
