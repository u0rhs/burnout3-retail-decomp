// NONMATCHING: OnTradePaint__8CB3ScoreFP17CB3RaceCarPhysicsP17CB3RaceCarPhysicsfb -- retail 75 / ours 75 instructions, 5 in changed runs
// near16: scoped opt_repositioncode off [G] + goto-form out-of-line 2nd AddBurn + 'goto r1' shared return (12 -> 5, 75/75). Left: a (self->field_13F4) / ta (field_1914) swap a0<->a2 only; decl/def-order, char*, const-pun, sreg perm tried
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// NONMATCHING: OnTradePaint__8CB3ScoreFP17CB3RaceCarPhysicsP17CB3RaceCarPhysicsfb -- retail 75 / ours 80 instructions, 12 in changed runs
// a246: lifter draft was garbled (bool return always 1, block struct at +0x10C0 with fields C/5C0/5EC/5F0 fixed the first 50 instrs). Left: horn-blast tail layout (retail keeps redundant ta==1 test after failed ta==0 inner test; a2=1914,a0=ptr) 12 changed, 80 vs 75
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// lifter variant 0
// CB3Score::OnTradePaint(CB3RaceCarPhysics*,CB3RaceCarPhysics*,float,bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3Score.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3RaceCarPhysics;
enum EAggressiveHornBlashReason {};

class CB3Score;
struct CB3RaceCarPhysics;
struct UnkStruct_00155910_3;
struct UnkStruct_00155910_blk { unsigned char pad_0[0xC]; float field_C; unsigned char pad_10[0x5B0]; float field_5C0; unsigned char pad_5C4[0x28]; int field_5EC; float field_5F0; };
struct UnkStruct_00155910_4;

struct CB3RaceCarPhysics {
    unsigned char pad_0[0x13F4];
    UnkStruct_00155910_4 * field_13F4;
};

struct UnkStruct_00155910_3 {
    unsigned char pad_0[0x10CC];
    float field_C;
    unsigned char pad_10D0[0x5B0];
    float field_5C0;
    unsigned char pad_1684[0x28];
    int field_5EC;
    float field_5F0;
    unsigned char pad_16B4[0x260];
    int field_1914;
};

struct UnkStruct_00155910_4 {
    unsigned char pad_0[0x10CC];
    float field_C;
    unsigned char pad_10D0[0x5B0];
    float field_5C0;
    unsigned char pad_1684[0x28];
    int field_5EC;
    float field_5F0;
    unsigned char pad_16B4[0x260];
    int field_1914;
};

class CB3Score {
public:
    bool OnTradePaint(CB3RaceCarPhysics* p0, CB3RaceCarPhysics* p1, float p2, bool p3);
    int CalculateSlamType(CB3RaceCarPhysics*, CB3RaceCarPhysics*, float);
    static float gmrTradingPaintBurnValue;

    unsigned char pad_0[0x13F4];
    UnkStruct_00155910_3 * field_13F4;
};

extern "C" void AddBurn__7CB3BurnFf(void *, float);  // CB3Burn::AddBurn(float)
extern "C" float DoAggressiveHornBlast__24CB3AIAggressionBehaviourF26EAggressiveHornBlashReason(void *, EAggressiveHornBlashReason);  // CB3AIAggressionBehaviour::DoAggressiveHornBlast(EAggressiveHornBlashReason)
extern "C" void func_00368D20(void *, UnkStruct_00155910_4 *, bool);

// 0x00155910
// N182 [G]
#pragma push
#pragma opt_repositioncode off
bool CB3Score::OnTradePaint(CB3RaceCarPhysics* p0, CB3RaceCarPhysics* p1, float p2, bool p3)
{
    UnkStruct_00155910_blk * t0 = (UnkStruct_00155910_blk *)((char *)field_13F4 + 0x10C0);
    UnkStruct_00155910_blk * t1 = (UnkStruct_00155910_blk *)((char *)p0->field_13F4 + 0x10C0);
    bool same = CalculateSlamType(p0, p1, p2) == 1;
    func_00368D20((char *)t0 + 0x124, p0->field_13F4, same);
    AddBurn__7CB3BurnFf((char *)t0 + 0xCC, CB3Score::gmrTradingPaintBurnValue);
    if (!same) goto burn;
back:
    t0->field_5C0 = t0->field_C;
    t1->field_5C0 = t1->field_C;
    t1->field_5EC = (int)field_13F4;
    t1->field_5F0 = t1->field_C;
    t0->field_5EC = (int)p0->field_13F4;
    t0->field_5F0 = t0->field_C;
    if (!same) {
        UnkStruct_00155910_3 * a = field_13F4;
        int ta = a->field_1914;
        if (ta == 0) {
            UnkStruct_00155910_4 * b = p0->field_13F4;
            if (b->field_1914 == 1) {
                DoAggressiveHornBlast__24CB3AIAggressionBehaviourF26EAggressiveHornBlashReason((char *)b + 0x1B60, (EAggressiveHornBlashReason)1);
                goto r1;
            }
        }
        if (ta == 1) {
            if (p0->field_13F4->field_1914 == 0) {
                DoAggressiveHornBlast__24CB3AIAggressionBehaviourF26EAggressiveHornBlashReason((char *)a + 0x1B60, (EAggressiveHornBlashReason)1);
            }
        }
    }
r1:
    return true;
burn:
    AddBurn__7CB3BurnFf((char *)t1 + 0xCC, CB3Score::gmrTradingPaintBurnValue);
    goto back;
}

#pragma pop
