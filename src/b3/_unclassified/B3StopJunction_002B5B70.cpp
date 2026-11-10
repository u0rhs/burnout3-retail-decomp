// CB3StopJunction::FindFirstParam(EStopJunctionLaneTypes) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3StopJunction.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (near24: lane element-pointer local in the skip test + if (idx != 0xFF) arm first (block order)).

enum EStopJunctionLaneTypes {};

struct UnkStruct_002B5B70_2 {
    int field_0[6];
    int field_18[4];
    int field_28[10];
};

struct UnkStruct_002B5B70_p {
    unsigned char pad_0[0x30];
    float field_30;
    unsigned char pad_34[0x11];
    unsigned char field_45;
    unsigned char field_46;
    unsigned char pad_47[0x2];
    unsigned char field_49;
    unsigned char pad_4A[0x6];
};

struct UnkStruct_002B5B70_l {
    unsigned char pad_0[4];
    unsigned short field_4;
    unsigned char pad_6[0x40];
    unsigned char field_46;
    unsigned char pad_47[5];
};

struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x22C];
    UnkStruct_002B5B70_l field_22C[1];
    unsigned char pad_278[0x2F038];
    UnkStruct_002B5B70_p field_2F2B0[1];
};

struct UnkStruct_D_0055D7DC { unsigned char * field_0; unsigned char pad_4[0xC]; };

class CB3StopJunction {
public:
    UnkStruct_002B5B70_p * FindFirstParam(EStopJunctionLaneTypes);
    unsigned char FindFirstTurningParam(EStopJunctionLaneTypes, bool);

    UnkStruct_002B5B70_2 * field_0;
    unsigned char pad_4[0xC];
    unsigned char field_10[5];
    unsigned char field_15;
    unsigned char field_16;
    unsigned char field_17;
    unsigned char pad_18[0x4];
    unsigned char field_1C;
};

extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_D_0055D7DC D_0055D7DC;

static inline UnkStruct_002B5B70_p * func_002B5B70_inl1(unsigned char i)
{
    if (i == 0xFF) {
        return 0;
    }
    return &D_00522660.field_2F2B0[i];
}

// 0x002B5B70
UnkStruct_002B5B70_p * CB3StopJunction::FindFirstParam(EStopJunctionLaneTypes p0)
{
    bool skip;
    if (p0 == 1 && field_1C == 0) {
        skip = true;
    } else {
        unsigned char * buf = D_0055D7DC.field_0;
        int li = field_0->field_0[p0];
        int hi = field_0->field_28[p0];
        int lo = field_0->field_18[p0];
        UnkStruct_002B5B70_l * l0 = &D_00522660.field_22C[li];
        unsigned char i0 = buf[l0->field_4 + lo];
        if (i0 == 0xFF) {
            skip = true;
        } else {
            skip = hi < (int)func_002B5B70_inl1(i0)->field_30;
        }
    }
    if (skip) {
        return 0;
    }
    int li = field_0->field_0[p0];
    int lo = field_0->field_18[p0];
    int hi = field_0->field_28[p0];
    UnkStruct_002B5B70_l * lane = &D_00522660.field_22C[li];
    unsigned char idx = D_0055D7DC.field_0[lane->field_4 + hi];
    UnkStruct_002B5B70_p * r;
    if (idx != 0xFF) {
        unsigned char j = func_002B5B70_inl1(idx)->field_45;
        if (j == 0xFF) {
            r = 0;
        } else {
            r = func_002B5B70_inl1(j);
        }
    } else {
        unsigned char j = lane->field_46;
        if (j == 0xFF) {
            r = 0;
        } else {
            r = func_002B5B70_inl1(j);
        }
    }
    if (r == 0 || (int)r->field_30 < lo) {
        return 0;
    }
    return r;
}
