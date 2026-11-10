// CB3AIAvoidanceMap::CheckNoGoZones() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AIAvoidance.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (fresh7: goto-form out-of-line arms + scoped opt_repositioncode off [G]; separate locals per pass (x2/y2/lane2.., lane3/ns3/nl3 for the second pass's backward walk) fix FP/s-register colouring).

// CB3AIAvoidanceMap::CheckNoGoZones() -- hand-written (fresh7); the lifter refused it.
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AIAvoidance.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

enum EAIAvoidanceRisk {};

struct UnkStruct_0013DF60_seg {
    unsigned char pad_0[3];
    unsigned char field_3;
    unsigned char field_4[2];
    unsigned short field_6[2];
};
struct CB3AILaneStruct {
    unsigned char pad_0[8];
    UnkStruct_0013DF60_seg *field_8;
    unsigned short field_C;
    unsigned char field_E;
};
class CB3AILane {
public:
    static bool LaneIsDriveable(unsigned char id, unsigned short seg, unsigned short n);
    unsigned char pad_0[4];
    CB3AILaneStruct *field_4;
};
struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x2C];
    CB3AILane field_2C[1];
};
extern UnkStruct_D_00522660 D_00522660;

// [G] tuning values (absolute lui addressing: one object)
struct UnkStruct_D_01E75520 {
    float field_0;
    float field_4;
    float field_8;
    float field_C;
    unsigned char pad_10[0x24];
    float field_34;
    float field_38;
};
extern UnkStruct_D_01E75520 D_01E75520;

struct UnkStruct_0013DF60_car {
    unsigned char pad_0[0x18B4];
    CB3AILane *field_18B4;
    unsigned short field_18B8;
    unsigned char pad_18BA[0x2C6];
    unsigned char field_1B80;
};

class CB3AIAvoidanceMap {
public:
    void CheckNoGoZones();
    void FillInNoGoData(const CB3AILane *, unsigned short, EAIAvoidanceRisk, float, float);
    unsigned char pad_0[0x454];
    UnkStruct_0013DF60_car *field_454;
};

// N182: `#pragma opt_repositioncode off` ([G] scoped to this function): retail lays the rare arms (first-pass
// offsets, segment wrap, risk-1 calls, the risk-7 calls of the second pass) out of line after the return, in the
// goto order below.
#pragma push
#pragma opt_repositioncode off
// 0x0013DF60
void CB3AIAvoidanceMap::CheckNoGoZones()
{
    int i;
    float x;
    float y;
    CB3AILane *lane;
    CB3AILaneStruct *ld;
    UnkStruct_0013DF60_seg *e;
    unsigned short seg;
    unsigned short ns;
    unsigned char nl;
    EAIAvoidanceRisk r;
    float x2;
    float y2;
    CB3AILane *lane2;
    CB3AILaneStruct *ld2;
    unsigned short seg2;
    unsigned short ns2;
    unsigned char nl2;
    CB3AILane *lane3;
    unsigned short ns3;
    unsigned char nl3;
    for (i = 0; i < 10; i++) {
        if (i == 0)
            goto first;
        {
            float fi = (float)i;
            y = D_01E75520.field_4 + fi * D_01E75520.field_34;
            x = D_01E75520.field_0 + fi * D_01E75520.field_38;
        }
    have_xy:
        lane = field_454->field_18B4;
        seg = field_454->field_18B8 + i;
        ld = lane->field_4;
        if (!(seg < ld->field_C))
            goto wrap1;
    seg_ok:
        e = &ld->field_8[seg];
        if ((e->field_3 & 7) == 5) {
            if (e->field_4[0] == 0xFF || e->field_4[1] == 0xFF)
                goto risk1;
            r = (EAIAvoidanceRisk)2;
        call_cur:
            FillInNoGoData(lane, seg, r, x, y);
        }
        nl = lane->field_4->field_8[seg].field_4[0];
        ns = lane->field_4->field_8[seg].field_6[0];
        while (nl != 0xFF) {
            lane = &D_00522660.field_2C[nl];
            e = &lane->field_4->field_8[ns];
            if ((e->field_3 & 7) == 5) {
                if (e->field_4[0] == 0xFF || e->field_4[1] == 0xFF)
                    goto next_risk1;
                FillInNoGoData(lane, ns, (EAIAvoidanceRisk)2, x, y);
            }
        next_tail:
            nl = lane->field_4->field_8[ns].field_4[0];
            ns = lane->field_4->field_8[ns].field_6[0];
        }
        lane = field_454->field_18B4;
        seg = field_454->field_18B8 + i;
        ld = lane->field_4;
        if (seg >= ld->field_C) {
            if (ld->field_E != 0)
                seg -= ld->field_C;
        }
        nl = ld->field_8[seg].field_4[1];
        ns = ld->field_8[seg].field_6[1];
        while (nl != 0xFF) {
            lane = &D_00522660.field_2C[nl];
            e = &lane->field_4->field_8[ns];
            if ((e->field_3 & 7) == 5) {
                if (e->field_4[0] == 0xFF || e->field_4[1] == 0xFF)
                    goto prev_risk1;
                FillInNoGoData(lane, ns, (EAIAvoidanceRisk)2, x, y);
            }
        prev_tail:
            nl = lane->field_4->field_8[ns].field_4[1];
            ns = lane->field_4->field_8[ns].field_6[1];
        }
    }
pass2:
    if (field_454->field_1B80 != 0)
        return;
    for (i = 0; i < 1; i++) {
        {
            float fi = (float)i;
            lane2 = field_454->field_18B4;
            y2 = D_01E75520.field_4 + fi * D_01E75520.field_34;
            x2 = D_01E75520.field_0 + fi * D_01E75520.field_38;
        }
        seg2 = field_454->field_18B8 + i;
        ld2 = lane2->field_4;
        if (!(seg2 < ld2->field_C))
            goto wrap2;
    seg_ok2:
        if ((ld2->field_8[seg2].field_3 & 7) == 4)
            FillInNoGoData(lane2, seg2, (EAIAvoidanceRisk)7, x2, y2);
        nl2 = lane2->field_4->field_8[seg2].field_4[0];
        ns2 = lane2->field_4->field_8[seg2].field_6[0];
        while (CB3AILane::LaneIsDriveable(nl2, ns2, 1)) {
            lane2 = &D_00522660.field_2C[nl2];
            if ((lane2->field_4->field_8[ns2].field_3 & 7) == 4)
                goto next7;
        next7_tail:
            nl2 = lane2->field_4->field_8[ns2].field_4[0];
            ns2 = lane2->field_4->field_8[ns2].field_6[0];
        }
        lane3 = field_454->field_18B4;
        seg2 = field_454->field_18B8;
        nl3 = lane3->field_4->field_8[seg2].field_4[1];
        ns3 = lane3->field_4->field_8[seg2].field_6[1];
        while (CB3AILane::LaneIsDriveable(nl3, ns3, 1)) {
            lane3 = &D_00522660.field_2C[nl3];
            if ((lane3->field_4->field_8[ns3].field_3 & 7) == 4)
                goto prev7;
        prev7_tail:
            nl3 = lane3->field_4->field_8[ns3].field_4[1];
            ns3 = lane3->field_4->field_8[ns3].field_6[1];
        }
    }
    return;
first:
    y = D_01E75520.field_C;
    x = D_01E75520.field_8;
    goto have_xy;
wrap1:
    if (ld->field_E == 0)
        goto pass2;
    seg -= ld->field_C;
    goto seg_ok;
risk1:
    r = (EAIAvoidanceRisk)1;
    goto call_cur;
next_risk1:
    if (i == 0)
        FillInNoGoData(lane, ns, (EAIAvoidanceRisk)1, x, y);
    goto next_tail;
prev_risk1:
    if (i == 0)
        FillInNoGoData(lane, ns, (EAIAvoidanceRisk)1, x, y);
    goto prev_tail;
wrap2:
    if (ld2->field_E == 0)
        return;
    seg2 -= ld2->field_C;
    goto seg_ok2;
next7:
    FillInNoGoData(lane2, ns2, (EAIAvoidanceRisk)7, x2, y2);
    goto next7_tail;
prev7:
    FillInNoGoData(lane3, ns3, (EAIAvoidanceRisk)7, x2, y2);
    goto prev7_tail;
}
#pragma pop
