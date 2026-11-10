// CB3StopJunction::Update(bool,float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3StopJunction.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (draftAB: 3-case switch, FindFirstParam's lane test as a shared bool inline, transitions end in break (retail's exit block)).

// CB3StopJunction::Update(bool, float) -- hand-written (draftAB) from retail asm + Ghidra draft.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

enum EStopJunctionLaneTypes {};

struct UnkStruct_002B5B70_2 {
    int field_0[6];
    int field_18[4];
    int field_28[10];
};

struct UnkStruct_002B5B70_p {
    unsigned char pad_0[0x10];
    float field_10;
    unsigned char pad_14[0x18];
    float field_2C;
    float field_30;
    unsigned char pad_34[0x12];
    unsigned char field_46;
    unsigned char pad_47[0x4];
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
    void StopCarsInControlZone(EStopJunctionLaneTypes);
    void StopVehiclesIfTurning(EStopJunctionLaneTypes, bool);
    bool IsClearAreaEmpty(EStopJunctionLaneTypes);
    void Update(bool, float);

    UnkStruct_002B5B70_2 * field_0;
    float field_4;
    float field_8;
    float field_C;
    unsigned char field_10[4];
    unsigned char field_14;
    unsigned char field_15;
    unsigned char field_16;
    unsigned char field_17;
    unsigned char field_18;
    unsigned char field_19;
    unsigned char field_1A;
    unsigned char field_1B;
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

// [L] the same lane test opens FindFirstParam (0x002B5B70).
static inline bool func_002B5B70_inl2(const CB3StopJunction * s, EStopJunctionLaneTypes p0)
{
    bool skip;
    if (p0 == 1 && s->field_1C == 0) {
        skip = true;
    } else {
        unsigned char * buf = D_0055D7DC.field_0;
        int li = s->field_0->field_0[p0];
        int hi = s->field_0->field_28[p0];
        int lo = s->field_0->field_18[p0];
        UnkStruct_002B5B70_l * l0 = &D_00522660.field_22C[li];
        unsigned char i0 = buf[l0->field_4 + lo];
        if (i0 == 0xFF) {
            skip = true;
        } else {
            skip = hi < (int)func_002B5B70_inl1(i0)->field_30;
        }
    }
    return skip;
}

static inline void func_002B61E0_inl1(UnkStruct_002B5B70_p * p)
{
    if (p->field_46 == 2) {
        p->field_46 = 1;
        p->field_10 = -1.0f;
    }
}

static inline bool func_002B61E0_inl2(CB3StopJunction * s, EStopJunctionLaneTypes k)
{
    UnkStruct_002B5B70_p * p = s->FindFirstParam(k);
    if (p == 0) {
        return false;
    }
    if (p->field_4B & 4) {
        return true;
    }
    return false;
}

// 0x002B61E0
void CB3StopJunction::Update(bool p0, float p1)
{
    switch (field_14) {
    case 0:
        if (field_10[0] != 0xFF) {
            func_002B61E0_inl1(func_002B5B70_inl1(field_10[0]));
            field_10[0] = 0xFF;
        }
        if (field_1C != 0 && field_10[1] != 0xFF) {
            func_002B61E0_inl1(func_002B5B70_inl1(field_10[1]));
            field_10[1] = 0xFF;
        }
        StopVehiclesIfTurning((EStopJunctionLaneTypes)2, p0);
        StopVehiclesIfTurning((EStopJunctionLaneTypes)3, p0);
        if (field_15 != 0xFF) {
            if (func_002B5B70_inl1(field_15)->field_2C < 0.1f) {
                float d;
                if (field_19 == 0) {
                    field_4 = p1;
                    d = 0.0f;
                    field_19 = 1;
                } else {
                    d = p1 - field_4;
                }
                if (d > 19.0f) {
                    field_17 = field_15;
                    field_15 = 0xFF;
                    field_19 = 0;
                    field_1B = 1;
                    field_C = p1;
                    field_14 = 1;
                    break;
                }
            }
            if (IsClearAreaEmpty((EStopJunctionLaneTypes)0)) {
                field_17 = field_15;
                field_15 = 0xFF;
                field_19 = 0;
                field_1B = 1;
                field_C = p1;
                field_14 = 1;
                break;
            }
        }
        if (field_16 != 0xFF) {
            if (func_002B5B70_inl1(field_16)->field_2C < 0.1f) {
                float d;
                if (field_1A == 0) {
                    field_8 = p1;
                    d = 0.0f;
                    field_1A = 1;
                } else {
                    d = p1 - field_8;
                }
                if (d > 12.0f || (IsClearAreaEmpty((EStopJunctionLaneTypes)0) && IsClearAreaEmpty((EStopJunctionLaneTypes)2))) {
                    field_17 = field_16;
                    field_16 = 0xFF;
                    field_1A = 0;
                    field_1B = 1;
                    field_C = p1;
                    field_14 = 2;
                }
            }
        }
        break;
    case 1: {
        StopCarsInControlZone((EStopJunctionLaneTypes)0);
        StopCarsInControlZone((EStopJunctionLaneTypes)1);
        if (field_10[2] != 0xFF) {
            func_002B61E0_inl1(func_002B5B70_inl1(field_10[2]));
            field_10[2] = 0xFF;
        }
        float dt = p1 - field_C;
        bool nb = !(func_002B5B70_inl2(this, (EStopJunctionLaneTypes)0) && func_002B5B70_inl2(this, (EStopJunctionLaneTypes)1));
        bool c = !func_002B61E0_inl2(this, (EStopJunctionLaneTypes)2) && IsClearAreaEmpty((EStopJunctionLaneTypes)2);
        if ((dt > 3.0f && nb) || c) {
            if (IsClearAreaEmpty((EStopJunctionLaneTypes)-1)) {
                field_17 = 0xFF;
                field_1B = 0;
                field_14 = 0;
            } else {
                StopCarsInControlZone((EStopJunctionLaneTypes)2);
            }
        }
        break;
    }
    case 2: {
        if (field_18 == 0xFF) {
            if (func_002B61E0_inl2(this, (EStopJunctionLaneTypes)0)) {
                field_18 = FindFirstTurningParam((EStopJunctionLaneTypes)0, p0);
            }
        }
        if (field_18 != 0xFF) {
            UnkStruct_002B5B70_p * p = func_002B5B70_inl1(field_16);
            if (p->field_4B & 4) {
                if (p0) {
                    if (p->field_4C != 0) {
                        field_18 = 0xFF;
                    } else {
                        p->field_46 = 1;
                        p->field_10 = -1.0f;
                    }
                } else {
                    if (p->field_4C != 0) {
                        field_18 = 0xFF;
                    } else {
                        p->field_46 = 1;
                        p->field_10 = -1.0f;
                    }
                }
            }
        }
        StopCarsInControlZone((EStopJunctionLaneTypes)0);
        StopCarsInControlZone((EStopJunctionLaneTypes)1);
        StopCarsInControlZone((EStopJunctionLaneTypes)2);
        if (field_10[3] != 0xFF) {
            func_002B61E0_inl1(func_002B5B70_inl1(field_10[3]));
            field_10[3] = 0xFF;
        }
        float dt = p1 - field_C;
        bool nb = !(func_002B5B70_inl2(this, (EStopJunctionLaneTypes)0) && func_002B5B70_inl2(this, (EStopJunctionLaneTypes)1));
        bool c = !func_002B61E0_inl2(this, (EStopJunctionLaneTypes)3) && IsClearAreaEmpty((EStopJunctionLaneTypes)3);
        if ((dt > 3.0f && nb) || c) {
            if (IsClearAreaEmpty((EStopJunctionLaneTypes)-1)) {
                field_18 = 0xFF;
                field_17 = 0xFF;
                field_1B = 0;
                field_14 = 0;
            } else {
                StopCarsInControlZone((EStopJunctionLaneTypes)2);
            }
        }
        break;
    }
    }
}
