// CGtByteStream::GetPosition() const -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtByteStream.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtByteStream {
public:
    int GetPosition() const;

    unsigned char pad_0[0x4];
    int field_4;
    int field_8;
};

// 0x003744B0
int CGtByteStream::GetPosition() const
{
    return (field_8 - field_4);
}
