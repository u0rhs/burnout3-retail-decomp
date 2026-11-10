// CGtPS2LibNet::Connect(int,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtPS2LibNet.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (switch with no default: case 0 falls into case 1 (break), shared final return field_710; 0 > x compares (slt at,x,zero); field_714 as a 16-byte address struct member).

// CGtPS2LibNet::Connect(int,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtPS2LibNet.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtPS2LibNet;
struct UnkStruct_0022E9D0_1;

struct UnkStruct_0022E9D0_1 {
    unsigned char pad_0[0x1];
    unsigned char field_1;
    short field_2;
    int field_4;
    unsigned char pad_8[0x8];
};

class CGtPS2LibNet {
public:
    int Connect(int p0, int p1);

    unsigned char pad_0[0xB0];
    int field_B0;
    unsigned char pad_B4[0x65C];
    int field_710;
    UnkStruct_0022E9D0_1 field_714;
};

extern "C" void * memset(void *, int, unsigned int);
extern "C" int func_00237320(int);
extern "C" int func_002372F8(int);
extern "C" int sceInsockSocket(int, int, int);
extern "C" int sceInsockBind(int, UnkStruct_0022E9D0_1 *, int);

// 0x0022E9D0
int CGtPS2LibNet::Connect(int p0, int p1)
{
    UnkStruct_0022E9D0_1 local;
    switch (field_710) {
    case 0:
        memset(&local, 0, 16);
        local.field_1 = 2;
        local.field_2 = func_00237320(0);
        local.field_4 = func_002372F8(0);
        memset(&field_714, 0, 16);
        field_714.field_1 = 2;
        field_714.field_2 = func_00237320(p1 & 65535);
        field_714.field_4 = func_002372F8(p0);
        field_B0 = sceInsockSocket(2, 1, 0);
        if (0 > field_B0) {
            field_710 = 0;
            return 4;
        }
        if (0 > sceInsockBind(field_B0, &local, 16)) {
            field_710 = 0;
            return 4;
        }
        field_710 = 1;
    case 1:
        break;
    case 3:
        field_710 = 0;
        return 3;
    case 4:
        field_710 = 0;
        return 4;
    }
    return field_710;
}
