// CB3TrafficLight::StopCars() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficLight.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (near23: mismatch arm first (!= laneId), laneId read before the slot address).

// CB3TrafficLight::StopCars() -- hand-finished by near23 from a143's archive: lane-id mismatch arm first (if (c->field_41 != laneId) {...} else {...}),
// laneId read before the slot address (head schedule).

struct UnkStruct_StopCars_P {
    int * field_0;
    int * field_4;
    unsigned char pad_8[4];
    int * field_C;
    unsigned char pad_10[5];
    unsigned char field_15;
};
struct UnkStruct_StopCars_car {
    unsigned char pad_0[0x10];
    float field_10;
    unsigned char pad_14[0x18];
    float field_2C;
    float field_30;
    unsigned char pad_34[0xD];
    unsigned char field_41;
    unsigned char pad_42[3];
    unsigned char field_45;
    unsigned char field_46;
    unsigned char pad_47[2];
    unsigned char field_49;
    unsigned char pad_4A[6];
};
struct UnkStruct_StopCars_lane { unsigned char pad_0[4]; unsigned short field_4; unsigned char pad_6[0x46]; };
struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x22C];
    UnkStruct_StopCars_lane field_22C[1];
};
struct UnkStruct_D_00522660_b { unsigned char pad_0[0x2F2B0]; UnkStruct_StopCars_car field_2F2B0[1]; };
struct UnkStruct_D_0055D7DC { unsigned char * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_004E0A40 { float field_0; };
extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_D_0055D7DC D_0055D7DC;
extern UnkStruct_D_004E0A40 D_004E0A40;
extern "C" float GetSignedForwardDistBetweenParams__14CB3TrafficLaneFff(void *, float, float);

class CB3TrafficLight {
public:
    void StopCars();
    UnkStruct_StopCars_P * field_0;
    unsigned char pad_4[0xC];
    unsigned char field_10[1];
};

static inline UnkStruct_StopCars_car * func_00265C80_inl1(unsigned char i)
{
    if (i == 255) return 0;
    return (UnkStruct_StopCars_car *)(int)&((UnkStruct_D_00522660_b *)&D_00522660)->field_2F2B0[i];
}

// 0x00265C80
void CB3TrafficLight::StopCars()
{
    UnkStruct_StopCars_lane * lane;
    int i;
    for (i = 0; i < field_0->field_15; i++) {
        int laneId = field_0->field_C[i];
        unsigned char * slot = &field_10[i];
        lane = &D_00522660.field_22C[laneId];
        UnkStruct_StopCars_car * c;
        if (field_10[i] != 255) {
            c = func_00265C80_inl1(field_10[i]);
            if (c->field_41 != laneId) {
                if (c->field_46 == 2) {
                    c->field_46 = 1;
                    c->field_10 = -1.0f;
                }
                *slot = 255;
            } else {
                float d = GetSignedForwardDistBetweenParams__14CB3TrafficLaneFff(lane, (float)field_0->field_4[i], c->field_30);
                if (d < 0.0f) d = 0.0f;
                if (c->field_46 == 2) c->field_10 = d;
            }
        } else {
        unsigned char h = D_0055D7DC.field_0[lane->field_4 + field_0->field_4[i]];
        if (h != 255) {
            c = func_00265C80_inl1(h);
            if (c->field_45 == 255) c = 0;
            else c = func_00265C80_inl1(c->field_45);
        } else {
            if (*((unsigned char *)lane + 0x46) == 255) c = 0;
            else c = func_00265C80_inl1(*((unsigned char *)lane + 0x46));
        }
        while (c != 0) {
            float d1 = GetSignedForwardDistBetweenParams__14CB3TrafficLaneFff(lane, (float)field_0->field_4[i], c->field_30);
            float d2 = GetSignedForwardDistBetweenParams__14CB3TrafficLaneFff(lane, c->field_30, (float)field_0->field_0[i]);
            if (d1 > 0.0f && d2 > 0.0f && D_004E0A40.field_0 * d1 < c->field_2C) {
                if (c->field_46 == 1) {
                    c->field_46 = 2;
                    c->field_10 = d1;
                    *slot = c->field_49;
                } else if (d1 < c->field_10) {
                    c->field_46 = 2;
                    c->field_10 = d1;
                    *slot = c->field_49;
                }
                break;
            }
            if (c->field_45 == 255) c = 0;
            else c = func_00265C80_inl1(c->field_45);
        }
        }
    }
}
