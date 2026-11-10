// CB3StopJunction::FindFirstTurningParam(EStopJunctionLaneTypes,bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3StopJunction.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a123: do-while loop, compares break to shared return 0xFF; GetParamInfoFromSplitter extern C).

enum EStopJunctionLaneTypes {};

struct UnkStruct_002B5B70_2 {
    int field_0[6];
    int field_18[4];
    int field_28[10];
};

struct UnkStruct_002B5B70_p {
    unsigned char pad_0[0x30];
    float field_30;
    unsigned char pad_34[0x0D];
    unsigned char field_41;
    unsigned char pad_42[3];
    unsigned char field_45;
    unsigned char field_46;
    unsigned char pad_47[0x2];
    unsigned char field_49;
    unsigned char pad_4A;
    unsigned char field_4B;
    unsigned char field_4C;
    unsigned char pad_4D[3];
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

extern "C" void GetParamInfoFromSplitter__15CB3TrafficParamFP14CB3TrafficLanei(void *, void *, int);

static inline UnkStruct_002B5B70_p * func_002B5B70_inl1(unsigned char i)
{
    if (i == 0xFF) {
        return 0;
    }
    return &D_00522660.field_2F2B0[i];
}

// 0x002B5970
unsigned char CB3StopJunction::FindFirstTurningParam(EStopJunctionLaneTypes p0, bool p1)
{
    UnkStruct_002B5B70_p * p = FindFirstParam(p0);
    if (p == 0) {
        return 0xFF;
    }
    int lo = field_0->field_18[p0];
    int hi = field_0->field_28[p0];
    do {
        int f = (int)p->field_30;
        if (f > hi || f < lo) {
            break;
        }
        if (p->field_4B & 4) {
            if (p1) {
                if (p->field_4C != 0) {
                    return p->field_49;
                }
            } else {
                if (p->field_4C == 0) {
                    return p->field_49;
                }
            }
        } else if (p0 == 3) {
            int i = 0;
            for (; i < 8; i++) {
                unsigned char id = p->field_41;
                void * lane = id == 0xFF ? 0 : &D_00522660.field_22C[id];
                GetParamInfoFromSplitter__15CB3TrafficParamFP14CB3TrafficLanei(p, lane, i);
                if (p->field_4B & 4) {
                    break;
                }
            }
            if (p->field_4B & 4) {
                if (p1) {
                    if (p->field_4C != 0) {
                        return p->field_49;
                    }
                } else {
                    if (p->field_4C == 0) {
                        return p->field_49;
                    }
                }
            }
        }
        unsigned char n = p->field_45;
        if (n == 0xFF) {
            p = 0;
        } else {
            p = func_002B5B70_inl1(n);
        }
    } while (p != 0);
    return 0xFF;
}
