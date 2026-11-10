// Hand-written; the lifter refused it ([L] DNAT AddExplosionTrail; goto found; second field_20 read via const float pun).

typedef unsigned int u_long128 __attribute__((mode(TI)));
struct UnkStruct_00399E20_q { u_long128 field_0; };
struct UnkStruct_00399E20_row {
    u_long128 field_0;
    u_long128 field_10;
    float field_20;
    unsigned char field_24;
    unsigned char pad_25[0xB];
};
extern float D_004E0C14;
// 0x00399E20
extern "C" void AddExplosionTrail__19CB3ExplosionManagerFQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3d(UnkStruct_00399E20_row *self, const UnkStruct_00399E20_q *p1, const UnkStruct_00399E20_q *p2)
{
    UnkStruct_00399E20_q b = *p1;
    UnkStruct_00399E20_q a = *p2;
    float best = D_004E0C14;
    int i = 0;
    UnkStruct_00399E20_row *slot = 0;
    UnkStruct_00399E20_row *r = self;
    for (; i < 5; i++) {
        if (r->field_20 <= 0.0f) {
            slot = r;
            goto found;
        }
        if (*(const float *)&r->field_20 < best) {
            best = *(const float *)&r->field_20;
            slot = r;
        }
        r++;
    }
found:
    slot->field_0 = b.field_0;
    slot->field_10 = a.field_0;
    slot->field_20 = 1.0f;
    slot->field_24 = 0;
}
