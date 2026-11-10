// CGtLogitechHeadset::GetHeadsetCodecDesc(int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtLogitechHeadset.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a79: 16-byte struct returned by hidden pointer; copy from lgCodecEnumerate entry+4 if non-null).

struct UnkStruct_Desc { int field_0; int field_4; int field_8; int field_C; };
struct UnkStruct_Codec { int field_0; UnkStruct_Desc field_4; };
extern "C" UnkStruct_Codec * lgCodecEnumerate(int);
class CGtLogitechHeadset {
public:
    UnkStruct_Desc GetHeadsetCodecDesc(int);
};
// 0x002C2540
UnkStruct_Desc CGtLogitechHeadset::GetHeadsetCodecDesc(int idx)
{
    UnkStruct_Desc d;
    UnkStruct_Codec * c = lgCodecEnumerate(idx);
    if (c != 0) {
        d = c->field_4;
    }
    return d;
}
