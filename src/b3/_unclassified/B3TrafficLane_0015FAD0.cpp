// CB3TrafficLane::FindNextValve(int,int*,int*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficLane.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (N183: int i declared before bestVal (multiply-assigned locals: last declared -> lower reg); was 8 off).


class CB3TrafficLane;
struct UnkStruct_0015FBA0_k;
struct UnkStruct_0015FBA0_v;
struct UnkStruct_D_00522660;

struct UnkStruct_0015FBA0_k {
    unsigned char pad_0[0x4];
    int * field_4;
};

struct UnkStruct_0015FBA0_v {
    unsigned char pad_0[0x40];
    UnkStruct_0015FBA0_k * field_40;
    unsigned char pad_44[0x118 - 0x44];
};

struct UnkStruct_D_00522660 {
    UnkStruct_0015FBA0_v field_0[1];  // [G] element count unknown
};

class CB3TrafficLane {
public:
    UnkStruct_0015FBA0_v * FindNextValve(int p0, int * p1, int * p2);

    unsigned char pad_0[0x6];
    unsigned char field_6[0x18];
    unsigned char field_1E[0x2A];
    unsigned char field_48;
};

extern UnkStruct_D_00522660 D_00522660;

// 0x0015FAD0
UnkStruct_0015FBA0_v * CB3TrafficLane::FindNextValve(int p0, int * p1, int * p2)
{
    int i;
    int bestObj = -1;
    *p1 = -1;
    int bestVal = 0x3E80;
    for (i = 0; i < field_48; i++) {
        unsigned char idx = field_1E[i];
        unsigned char obj = field_6[i];
        UnkStruct_0015FBA0_v * valve = (UnkStruct_0015FBA0_v *)((char *)&D_00522660.field_0[obj] + 0x4DE4);
        int val = valve->field_40->field_4[idx];
        if (p0 < val && val < bestVal) {
            *p1 = idx;
            bestObj = obj;
            bestVal = val;
        }
    }
    *p2 = bestVal;
    if (bestObj < 0) {
        return 0;
    }
    return (UnkStruct_0015FBA0_v *)((char *)&D_00522660.field_0[bestObj] + 0x4DE4);
}
