// CGtByteStream::Create(void*,int,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtByteStream.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtByteStream;

class CGtByteStream {
public:
    void Create(void* p0, int p1, int p2);

    int field_0;
    void * field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
};

// 0x003744C0
void CGtByteStream::Create(void* p0, int p1, int p2)
{
    field_0 = 0;
    field_4 = (void *)p0;
    field_10 = p1;
    field_14 = p2;
    field_8 = (int)field_4;
    field_C = (int)field_4;
}
