// CB3TrafficVehicle::CheckForChangeLane() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficVehicle.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (near3: shared return stub as an in-place label (ret: return; after the field_46=6/7 store) with goto ret from the field_46=1 and field_140=0 paths [G goto]).



class CB3TrafficLane;
class CB3TrafficVehicle;

class CB3TrafficParam {
public:
    int FindLaneChange(CB3TrafficLane **, float *, float *, bool, bool);

    unsigned char pad_0[0x30];
    float field_30;
    unsigned char pad_34[0x11];
    unsigned char field_45;
    unsigned char field_46;
    unsigned char pad_47[0x1];
    unsigned char field_48;
    unsigned char pad_49[0x2];
    unsigned char field_4B;
    bool field_4C;
};

class CB3TrafficLane {
public:
    unsigned char pad_0[0x4];
    unsigned short field_4;
    unsigned char pad_6[0x40];
    unsigned char field_46;
};

struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x50];
};
struct UnkStruct_D_0055D7DC {
    unsigned char * field_0;
    unsigned char pad_4[0xC];
};
struct UnkStruct_D_0055D7F8 {
    unsigned char field_0;
    unsigned char pad_1[0xF];
};
extern UnkStruct_D_00522660 D_00522660[];
extern UnkStruct_D_0055D7DC D_0055D7DC;
extern UnkStruct_D_0055D7F8 D_0055D7F8;

class CB3TrafficVehicle {
public:
    void CheckForChangeLane();
    void ChangeLane(CB3TrafficLane *, float);

    unsigned char pad_0[0x114];
    CB3TrafficParam * field_114;
    CB3TrafficLane * field_118;
    float field_11C;
    unsigned char pad_120[0x20];
    float field_140;
    unsigned char pad_144[0x1C];
    float field_160;
    unsigned char pad_164[0x11];
    unsigned char field_175;
};

static inline CB3TrafficParam * func_00171BE0_inl1(unsigned char i)
{
    if (i == 0xFF) {
        return 0;
    }
    return (CB3TrafficParam *)((char *)&D_00522660[i] + 0x2F2B0);
}

// 0x00171BA0
void CB3TrafficVehicle::CheckForChangeLane()
{
    float pos;
    float b;
    float a;
    CB3TrafficLane * lane = field_118;
    if (lane != 0) {
        CB3TrafficParam * p = field_114;
        a = field_160;
        b = p->field_30;
        if (a <= b) {
            ChangeLane(lane, field_11C);
            unsigned char s = field_114->field_46;
            if ((unsigned int)(s - 6) < 2) {
                field_114->field_46 = 1;
                goto ret;
            }
        } else {
            pos = field_11C;
            unsigned short idx = (unsigned short)pos;
            unsigned char * buf = D_0055D7DC.field_0 + lane->field_4;
            unsigned char id = buf[idx];
            CB3TrafficParam * other;
            if (id != 0xFF) {
                CB3TrafficParam * o1 = func_00171BE0_inl1(id);
                unsigned char n = o1->field_45;
                if (n == 0xFF) {
                    other = 0;
                } else {
                    other = func_00171BE0_inl1(n);
                }
            } else {
                unsigned char n = lane->field_46;
                if (n == 0xFF) {
                    other = 0;
                } else {
                    other = func_00171BE0_inl1(n);
                }
            }
            if (other != 0) {
                float d = pos - other->field_30;
                if (d < 3.0f) {
                    if (a - b > d) {
                        p->field_46 = 6;
                    } else {
                        p->field_46 = 7;
                    }
                ret:
                    return;
                }
            }
        }
    } else {
        CB3TrafficParam * p = field_114;
        if (p->field_48 > 0) {
            bool flag = (p->field_4B & 4) != 0;
            int r = p->FindLaneChange(&field_118, &field_11C, &field_160, p->field_4C, flag);
            if (r && flag) {
                field_114->field_48 = 0;
                field_114->field_4B &= 0xFB;
            }
            if (field_118 != 0) {
                if (field_114->field_48 > 0) {
                    field_114->field_48 = field_114->field_48 - 1;
                }
            }
            if (D_0055D7F8.field_0 == 0) {
                if (field_114->field_4C != 0) {
                    field_175 |= 1;
                } else {
                    field_175 |= 4;
                }
                if (field_140 < 0.0f) {
                    field_140 = 0.0f;
                    goto ret;
                }
            }
        }
    }
}
