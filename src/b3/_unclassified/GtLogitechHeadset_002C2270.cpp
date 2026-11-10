// CGtLogitechHeadset::OpenHeadset(int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtLogitechHeadset.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (sibling status-update if/else-if; 3-arg lgAudOpen/1-arg lgAudClose; local = {u8, S field_2, S field_8} with struct copy + field_8.field_4 = 50; init order).

// lifter variant 0
// CGtLogitechHeadset::OpenHeadset(int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtLogitechHeadset.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtLogitechHeadset;
struct UnkStruct_002C2270_1;

// [G] 6-byte audio format block; local.field_8 is a struct copy of local.field_2 (memberwise lbu/lbu/lhu, d re-set)
struct UnkStruct_002C2270_2 {
    unsigned char field_0;
    unsigned char field_1;
    unsigned short field_2;
    short field_4;
};

struct UnkStruct_002C2270_1 {
    unsigned char field_0;
    unsigned char pad_1[0x1];
    UnkStruct_002C2270_2 field_2;
    UnkStruct_002C2270_2 field_8;
    unsigned char pad_E[0x2];
};

class CGtLogitechHeadset {
public:
    bool OpenHeadset(int p0);

    unsigned char pad_0[0x10];
    int field_10;
    unsigned char pad_14[0x168];
    int field_17C;
    int field_180;
};

extern "C" void lgAudClose(int);  // one arg, as in the matched siblings
extern "C" int lgAudEnumerate(int, void *);
extern "C" int lgAudOpen(int, UnkStruct_002C2270_1 *, int *);  // [L] a3 is not read by lgAudOpen (lgcodec.s prologue)
extern "C" void lgAudSetRecordingVolume(int, int, int);
extern "C" void lgAudSetPlaybackVolume(int, int, int);
extern "C" void lgAudStartRecording(int);
extern "C" void lgAudStartPlayback(int);

// 0x002C2270
bool CGtLogitechHeadset::OpenHeadset(int p0)
{
    UnkStruct_002C2270_1 local;
    if (field_17C != -1) {
        lgAudClose(field_17C);
        field_17C = -1;
        // same status update as CGtLogitechHeadset::Construct (inlined; name unknown)
        if (field_17C != -1 && field_180 != 0) {
            field_10 = 2;
        } else if (field_17C == -1) {
            field_10 = 0;
        } else if (field_180 == 0) {
            field_10 = 1;
        }
    }
    int r = lgAudEnumerate(p0, (char *)this + 0x28);
    if (r == 0) {
        local.field_0 = 3;
        local.field_2.field_0 = 1;
        local.field_2.field_1 = 16;
        local.field_2.field_2 = 8000;
        local.field_2.field_4 = 50;
        local.field_8 = local.field_2;
        local.field_8.field_4 = 50;
        r = lgAudOpen(p0, &local, &field_17C);
        if (r == 0) {
            lgAudSetRecordingVolume(field_17C, 0, 80);
            lgAudSetPlaybackVolume(field_17C, 0, 80);
            lgAudStartRecording(field_17C);
            lgAudStartPlayback(field_17C);
            // same status update as CGtLogitechHeadset::Construct (inlined; name unknown)
            if (field_17C != -1 && field_180 != 0) {
                field_10 = 2;
            } else if (field_17C == -1) {
                field_10 = 0;
            } else if (field_180 == 0) {
                field_10 = 1;
            }
        }
    }
    return r == 0;
}
