// CB3TrafficParam::Remove() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficParam.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (clamp as static inline 'if (p >= n) p = n - 1; return p;' (keeps the then-arm inline, no relay b)).

// 6->1: clamp written 'pos = pos >= n ? n - 1 : pos;' (retail slt a1/bnez shape); 1 left: extra 'b' before the n-1 addiu (ours 121 vs retail 120 instrs)

// 2 instrs over: the pos<n clamp compiles to slt at/beqz + b over, retail slt a1,t1,a2/bnez/nop/addiu (n in a2); all else matches


// UpdateNodes__15CB3TrafficParamFv -- CB3TrafficParam::UpdateNodes() [L] DNAT
struct UnkStruct_00162BF0_blk { int pad_0[4]; int field_10; };
struct UnkStruct_00162BF0_lane {
    UnkStruct_00162BF0_blk * field_0;
    unsigned short field_4;
    unsigned char pad_6[0x40];
    unsigned char field_46;
    unsigned char pad_47[0x5];
};
struct UnkStruct_00162BF0 {
    unsigned char pad_0a[0x1C];
    int field_1C;
    unsigned char pad_20[0xC];
    float field_2C;
    float field_30;
    float field_34;
    unsigned char pad_38[0x9];
    unsigned char field_41;
    unsigned char pad_42[0x2];
    unsigned char field_44;
    unsigned char field_45;
    unsigned char field_46;
    unsigned char pad_47[0x2];
    unsigned char field_49;
    unsigned char pad_4A[0x6];
};
struct UnkStruct_D_00522660 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_0055D7DC { unsigned char * field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_D_0055D7DC D_0055D7DC;

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

static inline int func_00161400_inl1(int p, int n) { if (p >= n) p = n - 1; return p; }
extern "C" int Remove__15CB3TrafficParamFv(UnkStruct_00162BF0 *self)
{
    unsigned char *buf = D_0055D7DC.field_0;
    UnkStruct_00162BF0_lane *const lane = GetLane(self->field_41);
    if (self->field_45 != 0xFF) {
        UnkStruct_00162BF0 *o = GetParam(self->field_45);
        o->field_44 = self->field_44;
    }
    if (self->field_44 != 0xFF) {
        UnkStruct_00162BF0 *o = GetParam(self->field_44);
        o->field_45 = self->field_45;
    } else {
        lane->field_46 = self->field_45;
    }
    int pos = (int)self->field_30;
    int n = lane->field_0->field_10;
    pos = func_00161400_inl1(pos, n);
    for (;;) {
        if (pos < 0) {
            break;
        }
        unsigned char *p = buf + lane->field_4 + pos;
        if (self->field_49 != *p) {
            break;
        }
        if (self->field_44 == 0xFF) {
            *p = 0xFF;
        } else {
            *p = self->field_44;
        }
        pos--;
    }
    int j = lane->field_0->field_10 - 1;
    unsigned char *p = buf + lane->field_4 + j;
    if (self->field_49 == *p) {
        *p = 0xFF;
    }
    j--;
    for (; j >= 0; j--) {
        unsigned char *q = buf + lane->field_4 + j;
        if (self->field_49 == *q) {
            *q = q[1];
        }
    }
    self->field_44 = 0xFF;
    self->field_45 = 0xFF;
    self->field_1C = 0;
    return 1;
}
