// CGtLogitechHeadset::SetHeadsetCodec(int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtLogitechHeadset.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (sibling status-update chain (&&/else-if) written twice; lgCodecClose takes one arg; field_24 stored then re-read).

// CGtLogitechHeadset::SetHeadsetCodec(int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtLogitechHeadset.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtLogitechHeadset;
struct UnkStruct_002C2420_1;

struct UnkStruct_002C2420_1 {
    int field_0;
};

class CGtLogitechHeadset {
public:
    int SetHeadsetCodec(int p0);

    unsigned char pad_0[0x10];
    int field_10;
    unsigned char pad_14[0x10];
    UnkStruct_002C2420_1 * field_24;
    unsigned char pad_28[0x154];
    int field_17C;
    int field_180;
};

extern "C" void lgCodecClose(int);
extern "C" int lgCodecEnumerate(int);
extern "C" void lgCodecOpen(int, void *);

// 0x002C2420
int CGtLogitechHeadset::SetHeadsetCodec(int p0)
{
    if (field_180 != 0) {
        lgCodecClose(field_180);
        field_180 = 0;
    }
    field_24 = (UnkStruct_002C2420_1 *)lgCodecEnumerate(p0);
    if (field_24 == 0) {
        // same status update as CGtLogitechHeadset::Construct (inlined; name unknown)
        if (field_17C != -1 && field_180 != 0) {
            field_10 = 2;
        } else if (field_17C == -1) {
            field_10 = 0;
        } else if (field_180 == 0) {
            field_10 = 1;
        }
        return 0;
    }
    lgCodecOpen(field_24->field_0, &field_180);
    // same status update as CGtLogitechHeadset::Construct (inlined; name unknown)
    if (field_17C != -1 && field_180 != 0) {
        field_10 = 2;
    } else if (field_17C == -1) {
        field_10 = 0;
    } else if (field_180 == 0) {
        field_10 = 1;
    }
    return 1;
}
