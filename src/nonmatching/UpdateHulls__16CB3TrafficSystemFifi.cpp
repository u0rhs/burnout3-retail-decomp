// NONMATCHING: UpdateHulls__16CB3TrafficSystemFifi -- retail 282 / ours 281 instructions, 74 in changed runs
// L267: IsSegmentLocked inline now exact (int m reassigned form) + scoped opt_loop_invariants off keeps p2==0 in the loop; mnemonic-only diff 23. Left: s-register rotation (retail p2 s0/this s1/cur s2/old s3; ours cur s0/p2 s1/this s2), D_00522660 lane +0x22C folded into lhu 0x230 (retail addiu 0x22C; lhu 4 -- every cast/inline form folds), movn vs movz select
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CB3TrafficSystem::UpdateHulls(int,float,int) -- hand-written from the retail asm (lifter refused).
// [C] name: the mangled symbol in retail's tables; file: research/retail_names.csv -> B3TrafficSystem.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Field names are placeholders and every type is [G].

class CB3TrafficValve;
class CB3TrafficVehicle;
struct CB3TrafficFillerStruct;
class CB3StartFinishLine;
struct UnkStruct_001645E0_vd;
struct UnkStruct_001645E0_hull;
struct UnkStruct_001645E0_h;
struct UnkStruct_001645E0_e;
struct UnkStruct_001645E0_lane;
struct UnkStruct_D_00522660;

struct CB3TrafficFillerStruct {
    short field_0;
    short field_2;
    unsigned char field_4;
    unsigned char field_5;
};

struct UnkStruct_001645E0_vd {
    unsigned char pad_0[0xC];
    unsigned char field_C;
};

class CB3TrafficValve {
public:
    void Update(int, unsigned short, float, bool, bool);
    void PrepareGenerationTimes(float, bool);
    unsigned char pad_0[0x40];
    UnkStruct_001645E0_vd * field_40;
    unsigned char pad_44[0xD4];
};

class CB3TrafficVehicle {
public:
    unsigned char pad_0[0x174];
    unsigned char field_174;
    unsigned char pad_175[0xB];
};

struct UnkStruct_001645E0_hull {
    CB3TrafficFillerStruct * field_0;
    unsigned char pad_4[0x8];
    unsigned short * field_C;
    unsigned char * field_10;
    unsigned char field_14;
    unsigned char field_15;
    unsigned char pad_16[0x2];
};

struct UnkStruct_001645E0_h {
    unsigned char pad_0[0xA4];
    UnkStruct_001645E0_hull * field_A4;
    int field_A8;
};

struct UnkStruct_001645E0_e {
    unsigned char pad_0[0x30];
    float field_30;
    unsigned char pad_34[0x16];
    unsigned char field_4A;
    unsigned char pad_4B[0x5];
};

struct UnkStruct_001645E0_lane {
    unsigned char pad_0[0x4];
    unsigned short field_4;
    unsigned char pad_6[0x46];
};

struct UnkStruct_D_00522660 {
    UnkStruct_001645E0_lane field_0[1];  // [G] element count unknown; lanes start at +0x22C
};

extern UnkStruct_D_00522660 D_00522660;
extern unsigned char gauTrafficSegmentLock8[];
extern "C" void func_00173D30(CB3TrafficVehicle *);  // [L] low: CB3TrafficVehicle::Remove()

class CB3TrafficSystem {
public:
    bool CheckForNewHull(int, int);
    void DoFiller(CB3TrafficFillerStruct *, CB3StartFinishLine *, int, int);
    void UpdateHulls(int, float, int);

    UnkStruct_001645E0_h * field_0;
    CB3TrafficValve field_4[1];  // [G] element count unknown
    unsigned char pad_11C[0x126B4];
    CB3TrafficVehicle field_127D0[1];  // [G] element count unknown
    unsigned char pad_12950[0x17B80];
    UnkStruct_001645E0_e field_2A4D0[1];  // [G] element count unknown
    unsigned char pad_2A520[0xBE7C];
    unsigned char * field_3639C;
    unsigned char pad_363A0[0x7];
    unsigned char field_363A7[2];
    unsigned char field_363A9[2];
    unsigned char pad_363AB[0xC];
    bool field_363B7;
    bool field_363B8;
    unsigned char field_363B9;
    unsigned char pad_363BA[0x2];
    unsigned char field_363BC;
};

// [L] body of CB3TrafficSystem::IsSegmentLocked(int,unsigned short) (0x00163240), inlined here
static inline bool func_001645E0_inl1(CB3TrafficSystem *self, int a, unsigned short seg)
{
    if (self->field_363B9 == 0) return false;
    int s = seg;
    bool lo = a == 0;
    int m = gauTrafficSegmentLock8[(unsigned short)((unsigned)s >> 2)];
    unsigned char bit = lo + (s % 4) * 2;
    unsigned char mask = 1 << bit;
    m = (unsigned char)m & mask;
    return m != 0;
}

static inline UnkStruct_001645E0_lane *func_001645E0_inl2(unsigned char i)
{
    return (UnkStruct_001645E0_lane *)((char *)&D_00522660.field_0[i] + 0x22C);
}

// N182: opt_loop_invariants off [G] scoped to this function -- keeps the inlined IsSegmentLocked's `p2 == 0` inside the loop as retail does
// 0x001645E0
#pragma push
#pragma opt_loop_invariants off
void CB3TrafficSystem::UpdateHulls(int p1, float f, int p2)
{
    unsigned char old = field_363A7[p2];
    if (CheckForNewHull(p1, p2)) {
        int last = field_0->field_A8 - 1;
        if (old != last && old != 0) {
            if (old < field_363A7[p2]) field_363BC = 1; else field_363BC = 0;
        } else {
            if (field_363A7[p2] < 2U) field_363BC = 1; else field_363BC = 0;
        }
        UnkStruct_001645E0_hull *hull = &field_0->field_A4[field_363A7[p2]];
        field_363A9[p2] = hull->field_14;
        for (unsigned char i = 0; i < hull->field_15; i++) {
            CB3TrafficValve *v = &field_4[hull->field_10[i]];
            if (!(v->field_40->field_C & 2)) {
                v->PrepareGenerationTimes(f, 1);
            }
        }
        return;
    }
    UnkStruct_001645E0_hull *hull = &field_0->field_A4[field_363A7[p2]];
    if (field_363A9[p2] > 0) {
        DoFiller(&hull->field_0[field_363A9[p2] - 1], 0, 0, p2);
        field_363A9[p2]--;
        return;
    }
    for (unsigned char i = 0; i < hull->field_15; i++) {
        field_4[hull->field_10[i]].Update(p2, hull->field_C[i], f, field_363B7, field_363B8);
    }
    for (int j = 0; j < hull->field_14; j++) {
        CB3TrafficFillerStruct *e = &hull->field_0[j];
        if (e->field_2 < e->field_0) continue;
        int pos = e->field_5 ? (int)e->field_0 : (int)e->field_2;
        UnkStruct_001645E0_lane *ln = (UnkStruct_001645E0_lane *)((char *)&D_00522660.field_0[e->field_4] + 0x22C);
        unsigned short base = ln->field_4;
        unsigned char k = field_3639C[base + pos];
        if (k == 0xFF) continue;
        UnkStruct_001645E0_e *el = &field_2A4D0[k];
        unsigned short seg = base + (unsigned short)el->field_30;
        if (!func_001645E0_inl1(this, p2, seg) && (int)el->field_30 < pos + 4) {
            CB3TrafficVehicle *veh = &field_127D0[el->field_4A];
            if (!(veh->field_174 & 4)) func_00173D30(veh);
        }
    }
}


#pragma pop

