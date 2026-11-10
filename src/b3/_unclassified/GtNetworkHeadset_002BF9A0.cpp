// CGtNetworkHeadset::ChangeControlStateToOtherPlayerTalking(int,unsigned short) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtNetworkHeadset.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtNetworkHeadset;
struct UnkStruct_002BF9A0_2;
struct UnkStruct_002BF9A0_3;
struct UnkStruct_002BF9A0_4;

struct UnkStruct_002BF9A0_2 {
    unsigned char pad_0[0x28];
    int field_28;
};

struct UnkStruct_002BF9A0_3 {
    unsigned char field_0;
};

struct UnkStruct_002BF9A0_4 {
    unsigned char field_0;
};

class CGtNetworkHeadset {
public:
    void ChangeControlStateToOtherPlayerTalking(int p0, unsigned short p1);

    unsigned char pad_0[0x8];
    int field_8;
    unsigned char pad_C[0x818];
    int field_824;
    unsigned char pad_828[0x1];
    unsigned char field_829;
    unsigned char pad_82A[0x78F2];
    int field_811C;
    int field_8120;
    unsigned char pad_8124[0x4];
    unsigned char field_8128[1];  // [G] element count unknown
    unsigned char pad_8129[0x3B];
    int field_8164;
    unsigned char pad_8168[0x10];
    float field_8178;
    unsigned char pad_817C[0x8];
    int field_8184;
    int field_8188;
    unsigned char pad_818C[0x48];
    int field_81D4;
    UnkStruct_002BF9A0_2 * field_81D8;
    unsigned char pad_81DC[0x28];
    unsigned char field_8204;
};

extern "C" void * func_002366D0(UnkStruct_002BF9A0_2 *, int);
extern "C" UnkStruct_002BF9A0_3 * func_0022F910(void *, int);
extern "C" UnkStruct_002BF9A0_4 * func_0022F8C0(void *, int);

// 0x002BF9A0
void CGtNetworkHeadset::ChangeControlStateToOtherPlayerTalking(int p0, unsigned short p1)
{
    field_81D4 = p0;
    field_8188 = -1;
    for (int i = 0; (i < 60); i++) {
        field_8128[i] = 0;
    }
    field_8164 = -1;
    field_811C = 0;
    field_8120 = 0;
    field_824 = 65535;
    field_829 = 0;
    field_8178 = ((float)(p1 & 65535));
    if (field_8204 != 0) {
        for (int i1 = 0; (i1 < field_81D8->field_28); i1++) {
            void * r0 = func_002366D0(field_81D8, i1);
            if (r0 != 0) {
                UnkStruct_002BF9A0_3 * r1 = func_0022F910(r0, 2);
                UnkStruct_002BF9A0_4 * r2 = func_0022F8C0(r0, 2);
                r1->field_0 = (r1->field_0 & -2);
                r2->field_0 = (r2->field_0 & -2);
            }
        }
    }
    field_8 = 4;
    field_8184 = 0;
}
