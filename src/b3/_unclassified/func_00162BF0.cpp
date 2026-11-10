// Hand-written; the lifter refused it (a84: CB3TrafficParam::UpdateNodes [L] DNAT; const lane ptr picks s0/s1, block form single return, top-tested while loops, GetParam(c) before compare in chain walk, bool found).

// UpdateNodes__15CB3TrafficParamFv -- CB3TrafficParam::UpdateNodes() [L] DNAT
struct UnkStruct_00162BF0_blk { int pad_0[4]; int field_10; };
struct UnkStruct_00162BF0_lane {
    UnkStruct_00162BF0_blk * field_0;
    unsigned short field_4;
    unsigned char pad_6[0x46];
};
struct UnkStruct_00162BF0 {
    unsigned char pad_0[0x2C];
    float field_2C;
    float field_30;
    float field_34;
    unsigned char pad_38[0x9];
    unsigned char field_41;
    unsigned char pad_42[0x2];
    unsigned char field_44;
    unsigned char pad_45[0x1];
    unsigned char field_46;
    unsigned char pad_47[0x2];
    unsigned char field_49;
    unsigned char pad_4A[0x6];
};
struct UnkStruct_D_00522660 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_0055D7DC { unsigned char * field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_D_0055D7DC D_0055D7DC;
extern "C" int Remove__15CB3TrafficParamFv(void *);
extern "C" int Insert__15CB3TrafficParamFP14CB3TrafficLaneff18ETrafficParamState(void *, void *, float, float, int);
extern "C" int UpdateNodes__15CB3TrafficParamFv(UnkStruct_00162BF0 *);

static inline UnkStruct_00162BF0_lane * GetLane(unsigned char i)
{
    if (i == 0xFF) {
        return 0;
    }
    return (UnkStruct_00162BF0_lane *)((char *)&D_00522660 + i * 76 + 0x22C);
}

static inline UnkStruct_00162BF0 * GetParam(unsigned char i)
{
    if (i == 0xFF) {
        return 0;
    }
    return (UnkStruct_00162BF0 *)((char *)&D_00522660 + i * 80 + 0x2F2B0);
}

// [L] DNAT: CB3TrafficParam::UpdateNodes() (research/proto/new_names.csv, high)
// 0x00162BF0
extern "C" int UpdateNodes__15CB3TrafficParamFv(UnkStruct_00162BF0 * self)
{
    unsigned char * buf = D_0055D7DC.field_0;
    UnkStruct_00162BF0 * other;
    float x = self->field_30;
    int pos = (int)x;
    UnkStruct_00162BF0_lane * const lane = GetLane(self->field_41);
    int n = lane->field_0->field_10;
    if (pos >= n) {
        pos = n - 1;
    }
    unsigned char cur = *(buf + lane->field_4 + pos);
    unsigned char id = self->field_49;
    if (cur == id) {
        return 1;
    }
    if (cur == 0xFF) {
        while (pos >= 0 && *(buf + lane->field_4 + pos) == 0xFF) {
            *(buf + lane->field_4 + pos) = self->field_49;
            pos--;
        }
    } else {
        other = GetParam(cur);
        bool found = false;
        unsigned char c = id; while (c != 0xFF) { UnkStruct_00162BF0 * pc = GetParam(c);
            if (c == cur) {
                found = true;
            } c = pc->field_44; }
        if (found) {
            if (x <= other->field_30) {
                while (pos >= 0 && other->field_49 == *(buf + lane->field_4 + pos)) {
                    *(buf + lane->field_4 + pos) = self->field_49;
                    pos--;
                }
            } else {
                float save = other->field_2C;
                Remove__15CB3TrafficParamFv(other);
                UpdateNodes__15CB3TrafficParamFv(self);
                Insert__15CB3TrafficParamFP14CB3TrafficLaneff18ETrafficParamState(other, GetLane(other->field_41), other->field_30, other->field_34, other->field_46);
                other->field_2C = save;
            }
        } else {
            if (x < other->field_30) {
                float save = self->field_2C;
                Remove__15CB3TrafficParamFv(self);
                Insert__15CB3TrafficParamFP14CB3TrafficLaneff18ETrafficParamState(self, lane, self->field_30, self->field_34, self->field_46);
                self->field_2C = save;
            }
        }
    }
    return 1;
}
