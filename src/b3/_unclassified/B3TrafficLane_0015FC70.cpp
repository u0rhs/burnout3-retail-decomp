// CB3TrafficLane::GetNearestParamInSameLane(CB3TrafficParam*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficLane.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (rewritten with two placeholder inlines: param-by-byte-index (0xFF test as early return 0) and lane distance at a fractional index (lane count/array held in locals; index-1 in its own local); returns the nearer of the two neighbours).

class CB3TrafficLane;
struct CB3TrafficParam;
struct UnkStruct_0015FC70_3;
struct UnkStruct_0015FC70_e0;

struct CB3TrafficParam {
    unsigned char pad_0[0x30];
    float field_30;
    unsigned char pad_34[0x10];
    unsigned char field_44;
    unsigned char field_45;
    unsigned char pad_46[0xA];
};

struct UnkStruct_0015FC70_e0 {
    float field_0;
    unsigned char pad_4[0x4];
};

struct UnkStruct_0015FC70_3 {
    unsigned char pad_0[0x4];
    UnkStruct_0015FC70_e0 * field_4;
    unsigned char pad_8[0x8];
    int field_10;
};

// [G] D_00522660 + 0x2F2B0: an array of 0x50-byte CB3TrafficParam records indexed by a byte (0xFF = none)
struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x2F2B0];
    CB3TrafficParam field_2F2B0[1];  // [G] element count unknown
};

class CB3TrafficLane {
public:
    CB3TrafficParam * GetNearestParamInSameLane(CB3TrafficParam * p0);

    UnkStruct_0015FC70_3 * field_0;
};

extern UnkStruct_D_00522660 D_00522660;

// [G] placeholder inlines: a param record by byte index, and a lane distance at a fractional point index
static inline CB3TrafficParam * func_0015FC70_inl1(unsigned char i)
{
    if (i == 0xFF) {
        return 0;
    }
    return &D_00522660.field_2F2B0[i];
}

static inline float func_0015FC70_inl2(UnkStruct_0015FC70_e0 * arr, int n, float t)
{
    int i = (int)t;
    if (n < i) {
        i = n;
    }
    int j = i - 1;
    float r;
    if (j < 0) {
        r = 0.0f;
    } else {
        r = arr[j].field_0;
    }
    if (i < n) {
        r = r + (t - (float)i) * (arr[i].field_0 - r);
    }
    return r;
}

// 0x0015FC70
CB3TrafficParam * CB3TrafficLane::GetNearestParamInSameLane(CB3TrafficParam * p0)
{
    if (p0->field_44 == 0xFF) {
        if (p0->field_45 == 0xFF) {
            return 0;
        }
        return func_0015FC70_inl1(p0->field_45);
    }
    if (p0->field_45 == 0xFF) {
        return func_0015FC70_inl1(p0->field_44);
    }
    CB3TrafficParam * a = func_0015FC70_inl1(p0->field_44);
    CB3TrafficParam * b = func_0015FC70_inl1(p0->field_45);
    UnkStruct_0015FC70_3 * d = field_0;
    int n = d->field_10;
    UnkStruct_0015FC70_e0 * arr = d->field_4;
    float da = func_0015FC70_inl2(arr, n, a->field_30) - func_0015FC70_inl2(arr, n, p0->field_30);
    float db = func_0015FC70_inl2(arr, n, p0->field_30) - func_0015FC70_inl2(arr, n, b->field_30);
    if (da < db) {
        return a;
    }
    return b;
}
