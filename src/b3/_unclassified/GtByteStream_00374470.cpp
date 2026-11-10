// CGtByteStream::SetPosition(int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtByteStream.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtByteStream;
struct UnkStruct_00374470_e0;

struct UnkStruct_00374470_e0 {
    unsigned char pad_0[0x1];
};

class CGtByteStream {
public:
    void SetPosition(int p0);

    unsigned char pad_0[0x4];
    UnkStruct_00374470_e0 * field_4;
    int field_8;
    int field_C;
};

// 0x00374470
void CGtByteStream::SetPosition(int p0)
{
    field_8 = (int)&field_4[p0];
    int t0 = field_8;
    if ((unsigned int)t0 > (unsigned int)field_C) {
        field_C = t0;
    }
}
