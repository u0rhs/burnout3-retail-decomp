// Hand-written; the lifter refused it (mwperm: commute, temp, hoist, pull, bound, type, split, if, move, inc, inline, empty-then, const, uint, merge, param, for-; minimised by mwperm, no pragma needed).

struct UnkStruct_CC910_car { unsigned char pad_0[0x18EA]; unsigned char field_18EA; unsigned char pad_18EB[0x15]; };
struct UnkStruct_CC910_g { unsigned char pad_0[0x12AD28]; UnkStruct_CC910_car * field_12AD28[1]; };
struct UnkStruct_CC910_m { unsigned char pad_0[0x3AC]; int field_3AC; };
struct UnkStruct_CC910_mp { UnkStruct_CC910_m * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_CC910_row { unsigned char pad_0[0x228]; float field_228[1]; };
struct UnkStruct_CC910 {
    unsigned char pad_0[0x4AF];
    unsigned char field_4AF;
    unsigned char pad_4B0[0x44];
    unsigned char field_4F4[6];
    unsigned char field_4FA;
};
struct UnkStruct_CC910_s { unsigned char pad_0[0x10]; };
extern UnkStruct_CC910_s D_004EE040;
extern UnkStruct_CC910_g D_00522660;
extern UnkStruct_CC910_mp D_00648704;
extern "C" int func_00131E40(void *);

// 0x003CC910
extern "C" int func_003CC910(UnkStruct_CC910 * self, int idx)
{
    int j;
    unsigned int v0 = idx;
    UnkStruct_CC910_row * row;
    int v;
    if (!(func_00131E40(&D_004EE040))) {
        return 0;
    }
    if (self->field_4F4[idx] != 0) {
        return 0;
    }
    unsigned char t1 = self->field_4FA;
    if (t1 != 0) {
        v = D_00648704.field_0->field_3AC - self->field_4AF;
        int i = 0;
        // [G] goto: N24 entry-jump loop (retail: b test; body; test: slti/bnez body)
        goto test;
    body:
        if (D_00522660.field_12AD28[i]->field_18EA != 0) {
            v++;
        }
        i++;
    test:
        if (i <= 1) goto body;
    } else {
        int limit;
        limit = D_00648704.field_0->field_3AC;
        unsigned char cnt = 0;
        j = 0;
        row = (UnkStruct_CC910_row *)(((char *)self + 0x108 * v0));
        int n = self->field_4AF;
        for (; j < n; j++) {
            if (row->field_228[j] > 0.0f) {
                cnt++;
            }
        }
        if (cnt > 0) {
            cnt--;
        }
        v = limit - cnt;
    }
    if (v < 0) {
        v = 0;
    }
    return v;
}
