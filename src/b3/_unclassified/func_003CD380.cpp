// func_003CD380 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (const& store helper re-reads the 0.1f literal after bc1f; scoped opt_rebuildconditionals off [G]).

struct UnkStruct_003CD380_pl { unsigned char pad_0[0x19AC]; signed char field_19AC; };
struct UnkStruct_003CD380_b { unsigned char pad_0[0x13F4]; UnkStruct_003CD380_pl *field_13F4; };
struct UnkStruct_003CD380_a { unsigned char pad_0[0x218]; signed char field_218; };
struct UnkStruct_003CD380_e { unsigned char pad_0[0x18]; float field_18[1]; unsigned char pad_1C[0xEC]; };
struct UnkStruct_003CD380 {
    unsigned char pad_0[0x18];
    UnkStruct_003CD380_a *field_18[1];
    unsigned char pad_1C[0x210 - 0x1C];
    UnkStruct_003CD380_e field_210[1];
    unsigned char pad_318[0x4AF - 0x318];
    unsigned char field_4AF;
    unsigned char field_4B0[1];
};
// [L] DNAT: CB3CrashScore::HandleVehicleImpact (research/proto/new_names.csv)
// [G] store helper taking the value by const reference: retail reloads the 0.1f literal for the
// store after the bc1f (a const& bound to the literal is re-read, not CSE'd with the compare).
static inline void func_003CD380_inl1(float &x, const float &v) { x = v; }
// N182: `#pragma opt_rebuildconditionals off` ([G] scoped to this function; found by mwperm).
#pragma push
#pragma opt_rebuildconditionals off
// 0x003CD380
extern "C" void func_003CD380(UnkStruct_003CD380 *self, UnkStruct_003CD380_a *p0, UnkStruct_003CD380_b *p1)
{
    int n;
    UnkStruct_003CD380 * v1 = self;
    UnkStruct_003CD380_b * v0;
    signed char t1;
    v0 = p1;
    int pl;
    int idx;
    n = self->field_4AF;
    idx = 0;
    goto loop0_t;
loop0:
    if (self->field_18[idx] == p0) {
        goto found;
    }
    idx += 1;
loop0_t:
    if (!(idx < n)) {
    } else {
        goto loop0;
    }
    idx = -1;
found:
    if (idx != -1) {
        if (0 != v0) {
            t1 = p1->field_13F4->field_19AC;
            pl = t1;
        tail:
            self->field_4B0[idx] = 1;
            if (!(v1->field_210[pl].field_18[idx] < 0.1f)) return;
            func_003CD380_inl1(v1->field_210[pl].field_18[idx], 0.1f);
            goto ret;
        }
        pl = p0->field_218;
        goto tail;
    }
ret:
    return;
}
#pragma pop
