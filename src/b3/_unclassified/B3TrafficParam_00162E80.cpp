// CB3TrafficParam::Update(bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3TrafficParam.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (L284: hand-written (lifter refused); pos truncated before field_30 += step, bool result of GetLaneChanges in a local).

// CB3TrafficParam::Update(bool) -- hand-written from the asm (L284; the lifter refused it).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficParam.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"

using GtMathPs2::CGtV3d;

enum ETrafficVehicleCategories { ETrafficVehicleCategories_0 };   // [C] type name from the mangled callee; values unknown

class CB3TrafficParam;
class CB3TrafficLane;

struct UnkStruct_00162E80_pt {          // [G] 8-byte path points
    float field_0;
    float field_4;
};

struct UnkStruct_00162E80_blk {
    unsigned char pad_0[0x4];
    UnkStruct_00162E80_pt *field_4;
    unsigned char pad_8[0x8];
    int field_10;
};

struct UnkStruct_00162E80_lane {        // [C] 0x4C-byte lanes at D_00522660+0x22C (as func_00162BF0's GetLane)
    UnkStruct_00162E80_blk *field_0;
    unsigned char pad_4[0x32];
    unsigned char field_36[0x13];
    unsigned char field_49;
    unsigned char pad_4A[0x2];
};

struct UnkStruct_00162E80_mtx {         // [C] 0x50-byte records at D_00522660+0x34210 (as CalculateTargetParamMatrix)
    CGtV3d field_0;
    unsigned char pad_10[0x20];
    CGtV3d field_30;
    CGtV3d field_40;
};

struct UnkStruct_00162E80_cnt {
    unsigned char pad_0[0x4];
    int field_4;
};

class CB3TrafficSplitter {              // [C] 8-byte records at D_00522660+0x171AC (this of GetLaneChanges)
public:
    bool GetLaneChanges(bool *, unsigned char *, ETrafficVehicleCategories, CB3TrafficParam *);

    unsigned char pad_0[0x4];
    UnkStruct_00162E80_cnt *field_4;
};

struct UnkStruct_00162E80_valve {       // [G] 0x180-byte records at D_00522660+0x175B0
    unsigned char pad_0[0x174];
    unsigned char field_174;
    unsigned char pad_175[0xB];
};

class CB3TrafficParam {
public:
    bool Update(bool p);
    void GetParamInfoFromValve(CB3TrafficLane *, bool, bool);

    unsigned char pad_0[0x20];
    float field_20;
    unsigned char pad_24[0x4];
    float field_28;
    float field_2C;
    float field_30;
    unsigned char pad_34[0xD];
    unsigned char field_41;
    unsigned char pad_42[0x4];
    unsigned char field_46;
    unsigned char pad_47[0x1];
    unsigned char field_48;
    unsigned char field_49;
    unsigned char field_4A;
    unsigned char field_4B;
    bool field_4C;
    unsigned char field_4D;
};

struct UnkStruct_D_00522660 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_00522660 D_00522660;
struct UnkStruct_D_0052267C {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};
extern UnkStruct_D_0052267C D_0052267C;

// [L] low name CB3TrafficParam::CalculateTargetParamMatrix(float, CGtMatrix3x4*) (research/retail_names.csv).
extern "C" void func_001618C0(CB3TrafficParam *, UnkStruct_00162E80_mtx *, float);

static inline UnkStruct_00162E80_lane *GetLane(unsigned char i)
{
    if (i == 0xFF) {
        return 0;
    }
    return (UnkStruct_00162E80_lane *)((char *)&D_00522660 + i * 76 + 0x22C);
}

// 0x00162E80
bool CB3TrafficParam::Update(bool p)
{
    field_4B &= 0xFE;
    if (field_46 == 0)
        return false;
    UnkStruct_00162E80_mtx *m = (UnkStruct_00162E80_mtx *)((char *)&D_00522660 + field_49 * 0x50 + 0x34210);
    UnkStruct_00162E80_lane *lane = GetLane(field_41);
    int n = lane->field_0->field_10;
    int pos = (int)field_30;
    field_30 = field_30 + field_2C * D_0052267C.field_0 / field_20;
    if (!(field_30 <= (float)n)) {
        field_46 = 0;
        return false;
    }
    float frac = field_30 - (float)pos;
    while (n > pos && !(frac < 1.0f)) {
        field_4B |= 1;
        pos++;
        float old = field_20;
        float len = lane->field_0->field_4[pos].field_0 - lane->field_0->field_4[pos - 1].field_0;
        field_20 = len;
        if (!(len <= 0.0f))
            frac = (frac - 1.0f) * old / len;
        field_30 = frac + (float)pos;
    }
    func_001618C0(this, m, field_30);
    m->field_40 = m->field_30;
    if (field_28 != 0.0f) {
        float lim = 0.28f * lane->field_0->field_4[pos].field_4;
        float v = GtMath::Min(GtMath::Max(-field_28, -lim), lim);
        m->field_40 += m->field_0 * v;
    }
    UnkStruct_00162E80_valve *valve = (UnkStruct_00162E80_valve *)((char *)&D_00522660 + field_4A * 0x180 + 0x175B0);
    unsigned char b = field_4B;
    if ((b & 1) && !(b & 4)) {
        if (!(valve->field_174 & 4) && !(b & 4)) {
            for (int i = 0; i < lane->field_49; i++) {
                CB3TrafficSplitter *s = (CB3TrafficSplitter *)((char *)&D_00522660 + lane->field_36[i] * 8 + 0x171AC);
                if (s->field_4->field_4 == (int)field_30 + 7) {
                    bool r = s->GetLaneChanges(&field_4C, &field_48, (ETrafficVehicleCategories)field_4D, this);
                    if (r)
                        field_4B |= 4;
                    else
                        field_4B &= ~4;
                    break;
                }
            }
        }
        GetParamInfoFromValve((CB3TrafficLane *)lane, (valve->field_174 & 4) != 0, p);
    }
    return true;
}
