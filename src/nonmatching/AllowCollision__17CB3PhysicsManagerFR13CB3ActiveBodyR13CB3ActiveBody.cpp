// NONMATCHING: AllowCollision__17CB3PhysicsManagerFR13CB3ActiveBodyR13CB3ActiveBody -- retail 168 / ours 168 instructions, 20 in changed runs
// psweep: scoped #pragma opt_arithtransformation off [G] improves 32 -> 20
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// [G] N182: scoped optimiser pragma found by the pragma sweep (psweep_all.py)
#pragma push
#pragma opt_arithtransformation off
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.


// a162: 174 vs 168 instrs, 29 changed. Logic exact (derived from asm): T2 = st<=2||4||6||7 -> field_20E==1 / field_216==-1 checks, T1 = st<=2||st==4 -> field_1353&4==4 checks. KEY: the inline must take a const CB3ActiveBody* (const stops the lb CSE; fixed the dsll32/dsra32 reloads, same trick matched RenderWorld). Left: retail materialises T2(a) as a bool (t1) and joins at an out-of-line block (beqz t1,L48FC; b L4888; lw v0,12(a1) at the function end, exits as 'b L4AA8; move v0,zero' stubs); ours branches directly. T1(a) reuses T2(a)'s lb in retail but T2(b)/T1(b) reload.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// CB3PhysicsManager::AllowCollision(CB3ActiveBody&,CB3ActiveBody&) -- hand-written
struct UnkStruct_001B4810_o {
    unsigned char pad_0[0x20E];
    unsigned char field_20E;
    unsigned char pad_20F[7];
    signed char field_216;
    unsigned char pad_217[0x113C];
    unsigned char field_1353;
};
class CB3ActiveBody {
public:
    signed char field_0;
    unsigned char pad_1[0xB];
    UnkStruct_001B4810_o *field_C;
};
class CB3PhysicsManager {
public:
    bool AllowCollision(CB3ActiveBody &, CB3ActiveBody &);
};
static inline bool func_001B4810_inl1(const CB3ActiveBody *b)
{
    int s = b->field_0;
    return (unsigned int)s <= 2 || s == 4 || s == 6 || s == 7;
}
static inline bool func_001B4810_inl2(const CB3ActiveBody *b)
{
    int s = b->field_0;
    return (unsigned int)s <= 2 || s == 4;
}
// 0x001B4810
bool CB3PhysicsManager::AllowCollision(CB3ActiveBody &a, CB3ActiveBody &b)
{
    int sa = a.field_0;
    if (sa == 3 && b.field_0 == 3) {
        return false;
    }
    if (sa == 5 && b.field_0 == 5) {
        return false;
    }
    if (func_001B4810_inl1(&a) && a.field_C->field_20E == 1 && func_001B4810_inl1(&b) && b.field_C->field_20E == 1) {
        return false;
    }
    if ((func_001B4810_inl2(&a) && (a.field_C->field_1353 & 4) == 4) || (func_001B4810_inl2(&b) && (b.field_C->field_1353 & 4) == 4)) {
        return false;
    }
    if ((sa == 5 && b.field_0 == 3) || (b.field_0 == 5 && sa == 3)) {
        return false;
    }
    if ((func_001B4810_inl1(&a) && a.field_C->field_216 == -1) || (func_001B4810_inl1(&b) && b.field_C->field_216 == -1)) {
        return false;
    }
    return true;
}



#pragma pop
