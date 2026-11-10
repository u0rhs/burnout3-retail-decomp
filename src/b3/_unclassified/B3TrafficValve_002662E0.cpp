// CB3TrafficValve::RolloutCrashTraffic(int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficValve.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (e declared at top (s0/s3 order); count stored from l->field_9 (a0 reuse)).

struct UnkStruct_D_00522660_e { unsigned char pad_0[0x4C]; };
struct UnkStruct_D_00522660 { UnkStruct_D_00522660_e field_0[1]; };
struct UnkStruct_002662E0_ent { unsigned long field_0; unsigned long field_8; float field_10; unsigned char pad_14[4]; unsigned char field_18; unsigned char field_19; unsigned char field_1A; unsigned char field_1B; };
struct UnkStruct_002662E0_list { UnkStruct_002662E0_ent *field_0; unsigned char pad_4[5]; unsigned char field_9; };
struct UnkStruct_002662E0_fl { float field_0; };
struct UnkStruct_002662E0_idx { int *field_0; };
struct UnkStruct_00527440 { unsigned char pad_0[0x10]; };
class CB3TrafficValve {
public:
    void RolloutCrashTraffic(int);
    UnkStruct_002662E0_fl * field_0[1];
    unsigned char pad_4[0xC];
    float * field_10[1];
    unsigned char pad_14[0x1C];
    UnkStruct_002662E0_list * field_30[1];
    unsigned char pad_34[0xC];
    UnkStruct_002662E0_idx * field_40;
    unsigned char pad_44[0xCC];
    unsigned char field_110[1];
};
extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_00527440 D_00527440;
extern "C" float GetParamFromDist__14CB3TrafficLaneFf(void *, float);
extern "C" void Generate__16CB3TrafficSystemF25ETrafficVehicleCategoriesUl25ETrafficVehicleCategoriesUlP14CB3TrafficLanefffUcUcUc(void *, int, unsigned long, int, unsigned long, void *, float, float, float, unsigned char, unsigned char, unsigned char);
// 0x002662E0
void CB3TrafficValve::RolloutCrashTraffic(int p0)
{
    UnkStruct_002662E0_ent *e;
    UnkStruct_002662E0_list *l = field_30[p0];
    if (l == 0) return;
    int id = field_40->field_0[p0];
    void *lane;
    if (id == 255) lane = 0;
    else lane = (char *)&D_00522660.field_0[id] + 0x22C;
    int i = 0;
    float f20 = field_0[p0]->field_0;
    for (; i < l->field_9; i++) {
        e = &l->field_0[i];
        int c = e->field_18 == 4 ? 11 : 0;
        float t = GetParamFromDist__14CB3TrafficLaneFf(lane, e->field_10);
        Generate__16CB3TrafficSystemF25ETrafficVehicleCategoriesUl25ETrafficVehicleCategoriesUlP14CB3TrafficLanefffUcUcUc(&D_00527440, e->field_18, e->field_0, c, e->field_8, lane, t, f20, field_10[p0][e->field_18], e->field_19, e->field_1A, e->field_1B);
    }
    field_110[p0] = l->field_9;
}
