// NONMATCHING: func_001AB090 -- retail 36 / ours 36 instructions, 15 in changed runs
// gaps1c: hand-drafted from the asm
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// gaps1c (2026-11-02): hand-drafted from the retail asm (0x1AB090..0x1AB11C). Unnamed; file B3CollidingBody.cpp per
// research/retail_names.csv (high). Appends one intersection result to the car's triangle cache (+0x200; at most
// 0x60): its three vertices then its normal, and the polygon's flag word; on overflow (or once overflowed: D_004E2704)
// sets D_004E2704 and returns 0. Called from func_001C5330, CacheWorldTriangles' per-triangle callback.
// TRACK: clean
// EQUIV: [L] written from the asm: every branch and store accounted for (all four quads loaded before any store, as retail)

typedef unsigned int u_long128 __attribute__((mode(TI)));
typedef u_long128 UnkStruct_001AB090_q;   // [C] lq / sq quads
struct UnkStruct_001AB090_tri { UnkStruct_001AB090_q field_0[4]; };            // [C] 0x40 bytes
struct UnkStruct_001AB090_cache { int field_0; UnkStruct_001AB090_tri * field_4; unsigned short * field_8; };
struct UnkStruct_001AB090_poly { unsigned char pad_0[0x4]; unsigned short field_4; };   // [C] lhu 0x4: the surface flags
struct UnkStruct_001AB090_res {                                              // [C] the polygon-intersection result
    unsigned char pad_0[0x10];
    UnkStruct_001AB090_q field_10;                                           // [G] the normal (dot with the car's +0xB0)
    UnkStruct_001AB090_q field_20;
    UnkStruct_001AB090_q field_30;
    UnkStruct_001AB090_q field_40;
    unsigned char pad_50[0x10];
    UnkStruct_001AB090_poly * field_60;
};
struct UnkStruct_001AB090 { unsigned char pad_0[0x200]; UnkStruct_001AB090_cache * field_200; };

extern unsigned char D_004E2704;              // [C] gp-relative byte: the cache overflowed this query

// 0x001AB090
extern "C" int func_001AB090(UnkStruct_001AB090 * self, UnkStruct_001AB090_res * res)
{
    if (D_004E2704 == 0 && self->field_200->field_0 < 0x60) {
        int n = self->field_200->field_0;
        UnkStruct_001AB090_q a = res->field_20;
        UnkStruct_001AB090_q b = res->field_30;
        UnkStruct_001AB090_q c = res->field_40;
        UnkStruct_001AB090_q d = res->field_10;
        UnkStruct_001AB090_tri * t = &self->field_200->field_4[n];
        t->field_0[0] = a;
        t->field_0[1] = b;
        t->field_0[2] = c;
        t->field_0[3] = d;
        self->field_200->field_8[n] = res->field_60->field_4;
        self->field_200->field_0 = n + 1;
        return 1;
    }
    D_004E2704 = 1;
    return 0;
}
