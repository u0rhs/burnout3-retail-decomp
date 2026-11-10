// CGtByteStream::WriteMemory(const void*,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtByteStream.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (inline GetSpaceFree() (real name, 0x374450) in the guard; t0=field_8; if (t0 > field_C) field_C=t0).

// CGtByteStream::WriteMemory(const void*,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtByteStream.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtByteStream;
struct UnkStruct_00374380_e0;

struct UnkStruct_00374380_e0 {
    unsigned char pad_0[0x1];
};

class CGtByteStream {
public:
    int WriteMemory(const void* p0, int p1);
    int GetSpaceFree() const { return field_10 - (field_8 - field_4); }

    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
};

extern "C" void * memcpy(void *, const void *, unsigned int);

// 0x00374380
int CGtByteStream::WriteMemory(const void* p0, int p1)
{
    if (GetSpaceFree() < p1) {
        field_0 = 1;
        return 0;
    }
    memcpy((void *)field_8, p0, p1);
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
