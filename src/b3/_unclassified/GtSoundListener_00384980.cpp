// CGtSoundListener::Prepare(unsigned int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundListener.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (bool return, F3 zero local).

struct F3 { float x, y, z; };
struct UnkStruct_Lis {
    unsigned char pad_0[0x54];
    F3 f54;
    unsigned char pad_60[0x24];
    unsigned int flags;
};
class CGtSoundListener {
public:
    bool Prepare(unsigned int p0);
    unsigned char pad_0[0x4];
    int field_4;
    UnkStruct_Lis *field_8;
};
// 0x00384980
bool CGtSoundListener::Prepare(unsigned int p0)
{
    F3 z = {0.0f, 0.0f, 0.0f};
    field_8->f54 = z;
    field_8->flags |= 2;
    field_4 = 0;
    return true;
}
