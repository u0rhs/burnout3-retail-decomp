// NONMATCHING: DoFiller__16CB3TrafficSystemFP22CB3TrafficFillerStructP18CB3StartFinishLineii -- retail 283 / ours 280 instructions, 130 in changed runs
// L267: first hand-written draft (lifter refused), logic from the asm; mnemonic-only diff 59. Left: f5==1||f5==2 compiles to a sltiu range test (retail two beq), gau lui hoisted to the function top (retail per fill-loop preheader), fill-loop body order (retail computes the bit before the index; ours nor vs not/andi), inlined IsSegmentLocked p4==0 hoisted out of the vehicle loop (retail in-loop, cf. UpdateHulls), s-register numbering
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CB3TrafficSystem::DoFiller(CB3TrafficFillerStruct*,CB3StartFinishLine*,int,int) -- hand-written (lifter refused).
// [C] name: the mangled symbol in retail's tables; file: research/retail_names.csv -> B3TrafficSystem.cpp.
// Field names are placeholders and every type is [G].

class CB3StartFinishLine;
class CB3TrafficValve;
class CB3TrafficLane;

struct CB3TrafficFillerStruct {
    short field_0;
    short field_2;
    unsigned char field_4;
    unsigned char field_5;
};

struct UnkStruct_001640A0_vd {
    unsigned char pad_0[0x4];
    int * field_4;
};

class CB3TrafficValve {
public:
    void FillLaneSection(int, int, int, int, CB3StartFinishLine *, int, bool);
    unsigned char pad_0[0x40];
    UnkStruct_001640A0_vd * field_40;
};

class CB3TrafficLane {
public:
    CB3TrafficValve * FindPreviousValve(int, int *, int *);
    CB3TrafficValve * FindNextValve(int, int *, int *);
    unsigned char pad_0[0x4];
    unsigned short field_4;
    unsigned char pad_6[0x46];
};

struct UnkStruct_001640A0_e {
    unsigned char pad_0[0x30];
    float field_30;
    unsigned char pad_34[0x16];
    unsigned char field_4A;
    unsigned char pad_4B[0x5];
};

struct UnkStruct_001640A0_veh {
    unsigned char pad_0[0x10C];
    int field_10C;
    unsigned char pad_110[0x63];
    signed char field_173;
    unsigned char field_174;
    unsigned char pad_175[0xB];
};

struct UnkStruct_D_00522660 {
    CB3TrafficLane field_0[1];  // [G] element count unknown; lanes start at +0x22C
};

extern UnkStruct_D_00522660 D_00522660;
extern unsigned char gauTrafficSegmentLock8[];
extern "C" void func_00173D30(UnkStruct_001640A0_veh *);  // [L] low: CB3TrafficVehicle::Remove()

class CB3TrafficSystem {
public:
    bool IsSegmentLocked(int, unsigned short);
    void DoFiller(CB3TrafficFillerStruct *, CB3StartFinishLine *, int, int);

    unsigned char pad_0[0x127D0];
    UnkStruct_001640A0_veh field_127D0[1];  // [G] element count unknown
    unsigned char pad_12950[0x17B80];
    UnkStruct_001640A0_e field_2A4D0[1];  // [G] element count unknown
    unsigned char pad_2A520[0xBE7C];
    unsigned char * field_3639C;
    unsigned char pad_363A0[0x19];
    unsigned char field_363B9;
    unsigned char pad_363BA[0x2];
    unsigned char field_363BC;
};

// [L] body of CB3TrafficSystem::IsSegmentLocked(int,unsigned short) (0x00163240), inlined here
static inline bool func_001640A0_inl1(CB3TrafficSystem *self, int a, unsigned short seg)
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

// 0x001640A0
void CB3TrafficSystem::DoFiller(CB3TrafficFillerStruct *e, CB3StartFinishLine *sfl, int p3, int p4)
{
    int pj, pi, nj, ni;
    int end = e->field_2;
    int start = e->field_0;
    CB3TrafficLane *lane = (CB3TrafficLane *)((char *)&D_00522660.field_0[e->field_4] + 0x22C);
    if (end < start) {
        int t = end;
        end = start;
        start = t;
    }
    unsigned short segA = lane->field_4 + start;
    unsigned short segB = lane->field_4 + end;
    if ((e->field_5 == 0 && field_363BC != 0) || ((e->field_5 == 1 || e->field_5 == 2) && field_363BC == 0)) {
        for (unsigned short s = segA; s <= segB; s++) {
            int i = s;
            gauTrafficSegmentLock8[(unsigned short)((unsigned)i >> 2)] |= (unsigned char)(1 << (unsigned char)(p4 + (i % 4) * 2));
        }
        CB3TrafficValve *prev = lane->FindPreviousValve(start, &pi, &pj);
        CB3TrafficValve *next = lane->FindNextValve(start, &ni, &nj);
        while (!(end < prev->field_40->field_4[pi])) {
            int stop;
            if (next == 0) {
                stop = end;
            } else {
                stop = next->field_40->field_4[ni];
                if (end < stop) stop = end;
            }
            prev->FillLaneSection(pi, start, stop, p4, sfl, p3, true);
            if (!(stop < end)) return;
            pi = ni;
            start = stop;
            prev = next;
            next = lane->FindNextValve(next->field_40->field_4[ni], &ni, &nj);
        }
        return;
    }
    for (unsigned short s = segA; s <= segB; s++) {
        int i = s;
        gauTrafficSegmentLock8[(unsigned short)((unsigned)i >> 2)] &= (unsigned char)~(unsigned char)(1 << (unsigned char)(p4 + (i % 4) * 2));
    }
    while (!(end < start)) {
        unsigned char k = field_3639C[lane->field_4 + start];
        if (k == 0xFF) return;
        UnkStruct_001640A0_e *el = &field_2A4D0[k];
        if (!(el->field_30 <= (float)end)) return;
        UnkStruct_001640A0_veh *veh = &field_127D0[el->field_4A];
        if ((veh->field_174 & 4) && veh->field_173 != 8) return;
        if (veh->field_10C != 0) return;
        start = (int)el->field_30;
        if (func_001640A0_inl1(this, p4, lane->field_4 + (unsigned short)start)) {
            start++;
        } else {
            func_00173D30(veh);
        }
    }
}

