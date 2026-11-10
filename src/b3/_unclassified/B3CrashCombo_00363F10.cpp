// CB3CrashCombo::UpdateCollidingPairs() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CrashCombo.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (CrashCombo UpdateCollidingPairs).

struct UnkStruct_ucp_d {
    unsigned char pad_0[0x258A];
    unsigned char field_258A;
    unsigned char pad_258B[0x115];
    void *field_26A0[64];
    int field_27A0;
    int field_27A4;
};
struct UnkStruct_ucp_c {
    unsigned char pad_0[0x13F4];
    UnkStruct_ucp_d *field_13F4;
};
struct UnkStruct_ucp_b {
    signed char field_0;
    unsigned char pad_1[0xB];
    UnkStruct_ucp_c *field_C;
};
struct UnkStruct_ucp_p {
    unsigned char pad_0[0x24];
    UnkStruct_ucp_b *field_24;
    UnkStruct_ucp_b *field_28;
    unsigned char field_2C;
    unsigned char pad_2D[3];
};
struct UnkStruct_D_00648180 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_00645180 { UnkStruct_ucp_p field_0[1]; };
extern UnkStruct_D_00648180 D_00648180;
extern UnkStruct_D_00645180 D_00645180;
class CB3CrashCombo {
public:
    void UpdateCollidingPairs();
};
static inline bool func_00363F10_inl1(signed char t)
{
    bool r = true;
    if ((unsigned int)t > 2 && t != 4) r = false;
    return r;
}
static inline void func_00363F10_inl2(UnkStruct_ucp_d *d, UnkStruct_ucp_c *other)
{
    if (d->field_258A == 0) return;
    int n = d->field_27A0;
    if (n == 0x40) return;
    for (int j = 0; j < n; j++) {
        if (d->field_26A0[j] == other) return;
    }
    d->field_26A0[n] = other;
    d->field_27A0 = d->field_27A0 + 1;
    d->field_27A4 = d->field_27A4 + 1;
}
// 0x00363F10
void CB3CrashCombo::UpdateCollidingPairs()
{
    int i;
    int n = D_00648180.field_0;
    UnkStruct_ucp_p *pairs = D_00645180.field_0;
    for (i = 0; i < n; i++) {
        UnkStruct_ucp_p *p = &pairs[i];
        if (p->field_2C != 0) {
            UnkStruct_ucp_b *a = p->field_24;
            bool b1 = func_00363F10_inl1(a->field_0);
            if (b1) {
                UnkStruct_ucp_b *b = p->field_28;
                bool b2 = func_00363F10_inl1(b->field_0);
                if (b2) {
                    UnkStruct_ucp_c *ca = a->field_C;
                    UnkStruct_ucp_c *cb = p->field_28->field_C;
                    if (*(const signed char *)&a->field_0 == 2) func_00363F10_inl2(ca->field_13F4, cb);
                    if (p->field_28->field_0 == 2) func_00363F10_inl2(cb->field_13F4, ca);
                }
            }
        }
    }
}
