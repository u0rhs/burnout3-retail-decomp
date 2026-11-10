// CB3AIDriver::CalcCatchupSpeed(float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AIDriver.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (near18: if/else on func_001419B0 with shared return r, then-block for ==3, r = speed; r += 45.0f, lit4 17.88159943f literal).

// CB3AIDriver::CalcCatchupSpeed(float) -- hand-written (lifter refused).
struct UnkStruct_00143FA0_p { unsigned char pad_0[0x1558]; int field_1558; float field_155C; };
struct CB3Score { short field_0; };
struct UnkStruct_00143FA0_car {
    unsigned char pad_0[0x10C0];
    CB3Score field_10C0;
    unsigned char pad_10C2[0x852];
    int field_1914;
    unsigned char pad_1918[0xB18];
    UnkStruct_00143FA0_p *field_2430;
    unsigned char pad_2434[0xC];
    int field_2440;
};
struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x12AD28];
    UnkStruct_00143FA0_car *field_12AD28[6];
};
struct UnkStruct_D_0064D37C { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_004E0EC4 { float field_0; };
struct UnkStruct_D_01E754EC { float field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_D_0064D37C D_0064D37C;
extern UnkStruct_D_01E754EC D_01E754EC;
extern "C" float GetTotalRaceAmount__8CB3ScoreFv(CB3Score *);
extern "C" int GetNumCarsDoingCatchup__16CB3AIControlDataFv();
extern "C" int func_001419B0(void *);
class CB3AIDriver {
public:
    float CalcCatchupSpeed(float);
    unsigned char pad_0[0x7A0];
    UnkStruct_00143FA0_car *field_7A0;
    unsigned char pad_7A4[0x238];
    float field_9DC;
    unsigned char pad_9E0[8];
    float field_9E8;
    unsigned char pad_9EC[0x18];
    float field_A04;
    unsigned char pad_A08[0x29];
    unsigned char field_A31;
};
// 0x00143FA0
float CB3AIDriver::CalcCatchupSpeed(float speed)
{
    field_9DC = 0.0f;
    bool ahead = GetTotalRaceAmount__8CB3ScoreFv(&field_7A0->field_10C0) >= field_9E8;
    if (ahead != false && field_A31 == 0) {
        field_A04 = 0.0f;
        field_A31 = 1;
        return speed;
    }
    UnkStruct_00143FA0_car *car = field_7A0;
    bool flag = false;
    switch (car->field_2440) {
    case 0:
        if (car->field_2430->field_1558 == 3) {
            int n = GetNumCarsDoingCatchup__16CB3AIControlDataFv();
            int mine = field_7A0->field_10C0.field_0;
            int lo = mine - n;
            int cnt = D_0064D37C.field_0;
            for (int i = 0; i < cnt; i++) {
                UnkStruct_00143FA0_car *o = D_00522660.field_12AD28[i];
                if (o->field_10C0.field_0 < lo) continue;
                if (!(o->field_10C0.field_0 < mine)) continue;
                if (o->field_1914 != 0) continue;
                flag = true;
                break;
            }
        }
        break;
    case 1:
        if (car->field_2430->field_1558 == 3) {
            flag = true;
        }
        break;
    }
    if (!flag) {
        return speed;
    }
    float r;
    if (func_001419B0(field_7A0) != 0) {
        r = speed;
        r += 45.0f;
        UnkStruct_00143FA0_p *p = field_7A0->field_2430;
        if (p->field_1558 == 3) {
            field_9DC = 17.88159943f + 17.88159943f * p->field_155C;
        }
    } else {
        r = 45.0f + D_01E754EC.field_0;
    }
    return r;
}
