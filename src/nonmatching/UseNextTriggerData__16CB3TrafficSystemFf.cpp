// NONMATCHING: UseNextTriggerData__16CB3TrafficSystemFf -- retail 436 / ours 436 instructions, 98 in changed runs
// a159: logic complete, 436/436 instrs, jtbl switch ok. Left: s1/s2 swap (retail td=s1,i=s2,self=s0; ours i=s1,td=s2) across all loops (declaration order permutations tried: idx/td/i/ scoped for), + a2/a3 + a0/a1 reg numbering in case 7 and one extra 'b' at 0x57c
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// a159: CB3TrafficSystem::UseNextTriggerData
struct UnkStruct_UNT_td {
    void * field_0;
    unsigned char * field_4_dummy;
};
struct UnkStruct_UNT_P {
    unsigned char pad_0[0x4C];
    unsigned char * field_4C;
    int field_50;
};
struct UnkStruct_UNT_valve {
    unsigned char * field_0[4];
    unsigned char * field_10[4];
    unsigned char * field_20[4];
    unsigned char * field_30[4];
    unsigned char pad_40[0xD8];
};
struct UnkStruct_UNT_light { unsigned char pad_0[4]; void * field_4; unsigned char pad_8[0x10]; };
struct UnkStruct_UNT_tdd {
    void * field_0;
    unsigned char * field_4;
    unsigned char * field_8;
    unsigned char * field_C;
    unsigned char * field_10;
    unsigned char * field_14;
    unsigned char * field_18;
    unsigned char * field_1C;
    unsigned char * field_20;
    unsigned char * field_24;
    unsigned char * field_28;
    unsigned char * field_2C;
    unsigned char * field_30;
    unsigned char * field_34;
    unsigned char * field_38;
    int field_3C;
    int field_40;
    int field_44;
    int field_48;
    float field_4C;
    unsigned short field_50;
    unsigned char field_52;
    unsigned char field_53;
    unsigned char field_54;
    unsigned char field_55;
};
struct UnkStruct_UNT_self {
    UnkStruct_UNT_P * field_0;
    UnkStruct_UNT_valve field_4[1];
    unsigned char pad_11C[0x117CC - 0x11C];
    UnkStruct_UNT_light field_117CC[1];
    unsigned char pad_117E4[0x123CC - 0x117E4];
    unsigned char * field_123CC[1][2];
    unsigned char pad_123D4[0x363A0 - 0x123D4];
    float field_363A0;
    unsigned short field_363A4;
    unsigned char field_363A6;
    unsigned char pad_363A7[0x363B1 - 0x363A7];
    unsigned char field_363B1;
    unsigned char field_363B2;
    unsigned char field_363B3;
    unsigned char pad_363B4[3];
    unsigned char field_363B7;
    unsigned char field_363B8;
    unsigned char field_363B9;
    unsigned char pad_363BA[3];
    unsigned char field_363BD;
};
struct UnkStruct_D_00665EA0_unt { unsigned char field_0; unsigned char pad_1[0xF]; };
extern UnkStruct_D_00665EA0_unt D_00665EA0;
extern float D_004E1038;
extern "C" void UseNewTimingsData__15CB3TrafficLightFf(void *, float);
extern "C" void DoFiller__16CB3TrafficSystemFP22CB3TrafficFillerStructP18CB3StartFinishLineii(void *, void *, void *, int, int);
extern "C" void PrepareGenerationTimes__15CB3TrafficValveFfb(void *, float, bool);
extern "C" void ApplyNewFormation__15CB3TrafficValveFi(void *, int);
extern "C" void RolloutCrashTraffic__15CB3TrafficValveFi(void *, int);


extern "C" void UseNextTriggerData__16CB3TrafficSystemFf(UnkStruct_UNT_self * self, float f)
{
    int i;
    unsigned char idx = self->field_363B1;
    UnkStruct_UNT_tdd * td = (UnkStruct_UNT_tdd *)(self->field_0->field_4C + idx * 0x58);
    i = 0;
    switch (self->field_363B2) {
    case 0:
        if (idx != 0) {
            if (self->field_363B9 != 0) { self->field_363B2 = 2; return; }
        }
        for (i = 0; i < td->field_55; i++) {
            UnkStruct_UNT_light * l = &self->field_117CC[td->field_34[i]];
            l->field_4 = (char *)td->field_30 + i * 16;
            UseNewTimingsData__15CB3TrafficLightFf(l, f);
        }
        if (self->field_363B9 != 0) { self->field_363B2 = 2; return; }
        self->field_363B2 = 1;
        return;
    case 1:
        if (idx == 0) {
            self->field_363B2 = *(const unsigned char *)&self->field_363B2 + 1;
        } else {
            if (self->field_363B3 < td->field_53) {
                DoFiller__16CB3TrafficSystemFP22CB3TrafficFillerStructP18CB3StartFinishLineii(self, (char *)td->field_0 + self->field_363B3 * 6, 0, 0, 0);
                self->field_363B3 = self->field_363B3 + 1;
                return;
            }
            self->field_363B3 = 0;
            self->field_363B2 = self->field_363B2 + 1;
        }
    case 2:
        for (i = 0; i < td->field_40; i++) {
            self->field_4[td->field_8[i]].field_0[td->field_C[i]] = (unsigned char *)td->field_4 + i * 4;
        }
        self->field_363B2 = self->field_363B2 + 1;
        return;
    case 3:
        for (i = 0; i < td->field_44; i++) {
            UnkStruct_UNT_valve * v = &self->field_4[td->field_14[i]];
            v->field_10[td->field_18[i]] = (unsigned char *)td->field_10 + i * 28;
            if (self->field_363B1 != 0) PrepareGenerationTimes__15CB3TrafficValveFfb(v, f, false);
        }
        self->field_363B2 = self->field_363B2 + 1;
        return;
    case 4:
        for (i = 0; i < td->field_48; i++) {
            UnkStruct_UNT_valve * v = &self->field_4[td->field_20[i]];
            v->field_20[td->field_24[i]] = (unsigned char *)td->field_1C + i * 20;
            if (self->field_363B1 != 0) ApplyNewFormation__15CB3TrafficValveFi(v, td->field_24[i]);
        }
        self->field_363B2 = self->field_363B2 + 1;
        return;
    case 5:
        for (i = 0; i < td->field_54; i++) {
            self->field_123CC[td->field_2C[i]][0] = (unsigned char *)td->field_28 + i * 72;
        }
        self->field_363B2 = self->field_363B2 + 1;
        return;
    case 6:
        if (self->field_363B8 != 0) {
            for (i = 0; i < td->field_3C; i++) {
                unsigned char * e = (unsigned char *)td->field_38 + i * 12;
                UnkStruct_UNT_valve * v = &self->field_4[e[0xA]];
                v->field_30[e[0xB]] = e;
                if (self->field_363B1 > 0) RolloutCrashTraffic__15CB3TrafficValveFi(v, e[0xB]);
            }
        }
        self->field_363B2 = self->field_363B2 + 1;
        return;
    case 7:
        self->field_363B1 = idx + 1;
        if (self->field_363B7 == 0 && self->field_363B8 == 0) {
            UnkStruct_UNT_P * p = self->field_0;
            int n = self->field_363B1;
            if (!(n < p->field_50)) goto zero;
            self->field_363A4 = *(unsigned short *)(self->field_0->field_4C + n * 0x58 + 0x50);
            self->field_363A6 = *(self->field_0->field_4C + self->field_363B1 * 0x58 + 0x52);
        } else {
            UnkStruct_UNT_P * p = self->field_0;
            int n = self->field_363B1;
            if (n < p->field_50) {
                if (self->field_363B8 != 0 && D_00665EA0.field_0 != 0) self->field_363A0 = D_004E1038;
                else self->field_363A0 = *(float *)(self->field_0->field_4C + (unsigned char)n * 0x58 + 0x4C);
            } else {
                self->field_363A0 = -1.0f;
            }
        }
    common:
        self->field_363BD = 0;
        self->field_363B2 = 0;
        return;
    }
    return;
zero:
    self->field_363A4 = 0;
    self->field_363A6 = 0;
    goto common;
}
