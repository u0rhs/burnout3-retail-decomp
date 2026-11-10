// CB3StopJunction::StopVehiclesIfTurning(EStopJunctionLaneTypes,bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3StopJunction.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (rewritten with a param-by-index inline; p0==3 / p0==2 turning-slot refresh; if (param) {...} else {...} (no early return in the first arm); the release arm as one block-form condition (p0 != 1 || field_1C) && slot != 0xFF; distance into a temp so field_46 is stored first).

enum EStopJunctionLaneTypes {};

class CB3StopJunction;

struct UnkStruct_002B56B0_2 {
    int field_0[10];  // [G] per lane type: lane index
    int field_28[10];  // [G] per lane type: point index
};

struct UnkStruct_002B56B0_p {
    unsigned char pad_0[0x10];
    float field_10;
    unsigned char pad_14[0x1C];
    float field_30;
    unsigned char pad_34[0x12];
    unsigned char field_46;
    unsigned char pad_47[0x2];
    unsigned char field_49;
    unsigned char pad_4A[0x6];
};

struct UnkStruct_002B56B0_l {
    unsigned char pad_0[0x4C];
};

// [G] D_00522660: lanes (0x4C each) at +0x22C, param records (0x50 each) at +0x2F2B0
struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x22C];
    UnkStruct_002B56B0_l field_22C[1];  // [G] element count unknown
    unsigned char pad_278[0x2F038];
    UnkStruct_002B56B0_p field_2F2B0[1];  // [G] element count unknown
};

class CB3StopJunction {
public:
    void StopVehiclesIfTurning(EStopJunctionLaneTypes p0, bool p1);
    unsigned char FindFirstTurningParam(EStopJunctionLaneTypes, bool);

    UnkStruct_002B56B0_2 * field_0;
    unsigned char pad_4[0xC];
    unsigned char field_10[5];  // [G] per lane type
    unsigned char field_15;
    unsigned char field_16;
    unsigned char field_17;
    unsigned char pad_18[0x4];
    unsigned char field_1C;
};

extern UnkStruct_D_00522660 D_00522660;

extern "C" float GetSignedForwardDistBetweenParams__14CB3TrafficLaneFff(void *, float, float);  // CB3TrafficLane::GetSignedForwardDistBetweenParams(float,float)

// [G] placeholder inline: a param record by byte index (0xFF = none)
static inline UnkStruct_002B56B0_p * func_002B56B0_inl1(unsigned char i)
{
    if (i == 0xFF) {
        return 0;
    }
    return &D_00522660.field_2F2B0[i];
}

// 0x002B56B0
void CB3StopJunction::StopVehiclesIfTurning(EStopJunctionLaneTypes p0, bool p1)
{
    UnkStruct_002B56B0_p * param = 0;
    int point = field_0->field_28[p0];
    UnkStruct_002B56B0_l * lane = &D_00522660.field_22C[field_0->field_0[p0]];
    if (p0 == 3) {
        if (field_16 == 0xFF) {
            field_16 = FindFirstTurningParam(p0, p1);
            if (field_16 == field_17) {
                field_16 = 0xFF;
            } else {
                param = func_002B56B0_inl1(field_16);
            }
        } else {
            param = func_002B56B0_inl1(field_16);
        }
    } else if (p0 == 2) {
        if (field_15 == 0xFF) {
            field_15 = FindFirstTurningParam(p0, p1);
            if (field_15 == field_17) {
                field_15 = 0xFF;
            } else {
                param = func_002B56B0_inl1(field_15);
            }
        } else {
            param = func_002B56B0_inl1(field_15);
        }
    }
    if (param != 0) {
        float d = GetSignedForwardDistBetweenParams__14CB3TrafficLaneFff(lane, (float)point, param->field_30);
        param->field_46 = 2;
        param->field_10 = d;
        field_10[p0] = param->field_49;
    } else {
        if ((p0 != 1 || field_1C != 0) && field_10[p0] != 0xFF) {
            UnkStruct_002B56B0_p * q = func_002B56B0_inl1(field_10[p0]);
            if (q->field_46 == 2) {
                q->field_46 = 1;
                q->field_10 = -1.0f;
            }
            field_10[p0] = 0xFF;
        }
    }
}
