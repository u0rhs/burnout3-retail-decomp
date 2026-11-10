// CGtByteStream::ReadMemory(void*,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtByteStream.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (inline GetSpaceFree() in the guard (as sibling WriteMemory), int-padding rounding).

// CGtByteStream::ReadMemory(void*,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtByteStream.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtByteStream;
class CGtByteStream {
public:
    int ReadMemory(void* p0, int p1);
    int GetSpaceFree() const { return field_10 - (field_8 - field_4); }

    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
};

extern "C" void * memcpy(void *, const void *, unsigned int);

// 0x003742C0
int CGtByteStream::ReadMemory(void* p0, int p1)
{
    if (GetSpaceFree() < p1) {
        field_0 = 1;
        return 0;
    }
    memcpy(p0, (const void *)field_8, p1);
    int a = field_14;
    if (a != 0) {
        int r = p1 % a;
        if (r != 0) {
            p1 += a - r;
        }
    }
    field_8 += p1;
    int t0 = field_8;
    if ((unsigned int)t0 > (unsigned int)field_C) {
        field_C = t0;
    }
    return 1;
}
