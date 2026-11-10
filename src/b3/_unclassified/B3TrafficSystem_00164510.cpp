// CB3TrafficSystem::CheckForNewHull(int,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficSystem.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (regrot: e defined before n (single-use locals colour by definition order, later def -> lower reg); byte address (p1 + (int)this)[0x363A7] for retail's addu p1,this order).


class CB3TrafficSystem;
struct UnkStruct_00164510_e;
struct UnkStruct_00164510_h;

struct UnkStruct_00164510_e {
    unsigned char pad_0[0x4];
    int field_4;
    int field_8;
    unsigned char pad_C[0xC];
};

struct UnkStruct_00164510_h {
    unsigned char pad_0[0xA4];
    UnkStruct_00164510_e * field_A4;
    int field_A8;
};

class CB3TrafficSystem {
public:
    bool CheckForNewHull(int p0, int p1);

    UnkStruct_00164510_h * field_0;
    unsigned char pad_4[0x363A3];
    unsigned char field_363A7[1];  // [G] element count unknown
};

// 0x00164510
bool CB3TrafficSystem::CheckForNewHull(int p0, int p1)
{
    unsigned char * pc = &((unsigned char *)(p1 + (int)this))[0x363A7];
    UnkStruct_00164510_h * h = field_0;
    unsigned char idx = *pc;
    UnkStruct_00164510_e * arr = h->field_A4;
    UnkStruct_00164510_e * e = &arr[idx];
    int n = h->field_A8;
    int last = n - 1;
    if (idx == last && p0 == 0) {
        *pc = 0;
        return true;
    }
    if (idx == 0 && p0 == arr[n - 1].field_8) {
        *pc = last;
        return true;
    }
    if (p0 > e->field_8) {
        ((unsigned char *)(p1 + (int)this))[0x363A7] = ((unsigned char *)(p1 + (int)this))[0x363A7] + 1;
        return true;
    }
    if (p0 < e->field_4) {
        ((unsigned char *)(p1 + (int)this))[0x363A7] = ((unsigned char *)(p1 + (int)this))[0x363A7] - 1;
        return true;
    }
    return false;
}
