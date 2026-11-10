// CGtSoundStream::Destruct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundStream.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtSoundStream;
struct UnkStruct_ourGlobals;

struct UnkStruct_ourGlobals {
    unsigned char pad_0[0x138];
    int field_138;
};

class CGtSoundStream {
public:
    void Destruct();

    unsigned char pad_0[0x130];
    int field_130;
    int field_134;
    unsigned char pad_138[0x94];
    int field_1CC;
    int field_1D0;
    unsigned char pad_1D4[0x20];
    unsigned char field_1F4;
};

extern UnkStruct_ourGlobals ourGlobals;

extern "C" void RwaObjDestroy(int, int, int);
extern "C" void sceSifFreeSysMemory(int);

// 0x00386360
void CGtSoundStream::Destruct()
{
    RwaObjDestroy(field_1CC, 0, 0);
    sceSifFreeSysMemory(field_134);
    field_134 = 0;
    field_1CC = 0;
    field_1F4 = 0;
    field_1D0 = 0;
    ((void (*)(int))ourGlobals.field_138)(field_130);
}
