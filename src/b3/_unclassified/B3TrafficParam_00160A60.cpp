// CB3TrafficParam::GetParamInfoFromSplitter(CB3TrafficLane*,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficParam.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a70: found-block inside loop ending in break (not return), GetLaneChanges__18CB3TrafficSplitterFPbPUc25ETrafficVehicleCategoriesP15CB3TrafficParam extern C (DNAT GetLaneChanges), entry stride-8 splitter array at D_00522660+0x171AC).

// CB3TrafficParam::GetParamInfoFromSplitter(CB3TrafficLane*, int)
// [L] DNAT: GetLaneChanges__18CB3TrafficSplitterFPbPUc25ETrafficVehicleCategoriesP15CB3TrafficParam = CB3TrafficSplitter::GetLaneChanges(bool*,unsigned char*,ETrafficVehicleCategories,CB3TrafficParam*) (research/proto/new_names.csv, high)
enum ETrafficVehicleCategories {};
class CB3TrafficParam;

struct CB3TrafficLane {
    unsigned char pad_0[0x36];
    unsigned char field_36[1];  // [G] element count unknown
    unsigned char pad_37[0x12];
    unsigned char field_49;
};

struct UnkStruct_Splitter_x {
    unsigned char pad_0[0x4];
    int field_4;
};

class CB3TrafficSplitter {
public:
    unsigned char pad_0[0x4];
    UnkStruct_Splitter_x * field_4;
};

struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x171AC];
    CB3TrafficSplitter field_171AC[1];  // [G] element count unknown
};
extern UnkStruct_D_00522660 D_00522660;
extern "C" bool GetLaneChanges__18CB3TrafficSplitterFPbPUc25ETrafficVehicleCategoriesP15CB3TrafficParam(CB3TrafficSplitter *, bool *, unsigned char *, ETrafficVehicleCategories, CB3TrafficParam *);

class CB3TrafficParam {
public:
    void GetParamInfoFromSplitter(CB3TrafficLane * p0, int p1);

    unsigned char pad_0[0x30];
    float field_30;
    unsigned char pad_34[0x14];
    unsigned char field_48;
    unsigned char pad_49[0x2];
    unsigned char field_4B;
    bool field_4C;
    unsigned char field_4D;
};

// 0x00160A60
void CB3TrafficParam::GetParamInfoFromSplitter(CB3TrafficLane * p0, int p1)
{
    if (field_4B & 4) {
        return;
    }
    for (int i = 0; i < p0->field_49; i++) {
        CB3TrafficSplitter * s = &D_00522660.field_171AC[p0->field_36[i]];
        if (s->field_4->field_4 == p1 + ((int)field_30 + 4)) {
            bool r = GetLaneChanges__18CB3TrafficSplitterFPbPUc25ETrafficVehicleCategoriesP15CB3TrafficParam(s, &field_4C, &field_48, (ETrafficVehicleCategories)field_4D, this);
            if (r) {
                field_4B |= 4;
            } else {
                field_4B &= 0xFB;
            }
            break;
        }
    }
}
