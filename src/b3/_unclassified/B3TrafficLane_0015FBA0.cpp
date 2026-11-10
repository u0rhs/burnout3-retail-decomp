// CB3TrafficLane::FindPreviousValve(int,int*,int*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficLane.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (archive already exact; was hidden by the diff masking a real addiu ...,0).

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
    UnkStruct_0015FBA0_v * FindPreviousValve(int p0, int * p1, int * p2);

    unsigned char pad_0[0x6];
    unsigned char field_6[0x18];
    unsigned char field_1E[0x2A];
    unsigned char field_48;
};

extern UnkStruct_D_00522660 D_00522660;

// N182: `#pragma opt_arithtransformation off` ([G] scoped to this function; found by mwperm).
#pragma push
#pragma opt_arithtransformation off
// 0x0015FBA0
UnkStruct_0015FBA0_v * CB3TrafficLane::FindPreviousValve(int p0, int * p1, int * p2)
{
    int i;
    int bestObj;
    int v2;
    v2 = p0;
    int * v1;
    v1 = p2;
    char * t2;
    unsigned char idx;
    int * v0;
    int val;
    v0 = p1;
    int bestVal;
    bestObj = -1;
    bestVal = -1;
    char * t0;
    i = 0;
    *v0 = -1;
    goto loop0_t;
loop0:
    unsigned char t4 = field_1E[i];
    idx = t4;
    unsigned char obj = field_6[i];
    t0 = ((char *)&D_00522660.field_0[obj]) + 0x4DE4;
    UnkStruct_0015FBA0_v * valve = (UnkStruct_0015FBA0_v *)((char *)&D_00522660.field_0[obj] + 0x4DE4);
    int t3 = valve->field_40->field_4[idx];
    val = t3;
    if (!(!(val > v2) && bestVal < val)) {
    } else {
        *p1 = idx;
        bestObj = obj;
        bestVal = val;
    }
    i++;
loop0_t:
    if ((i >= field_48)) {
        *p2 = bestVal;
        if (!(bestObj < 0)) {
            char * t1 = 0x4DE4 + (char *)&D_00522660.field_0[bestObj];
            t2 = (t1);
            return (UnkStruct_0015FBA0_v *)(t2);
        } else {
            return 0;
        }
    } else {
        goto loop0;
    }
}
#pragma pop
