// CB3TrafficValve::Update(int,unsigned short,float,bool,bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficValve.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (psweep: scoped #pragma opt_arithtransformation off [G] (N182)).

// [G] N182: scoped optimiser pragma found by the pragma sweep (psweep_all.py)
#pragma push
#pragma opt_arithtransformation off
enum ETrafficVehicleCategories {};
class CB3TrafficLane;

class CB3TrafficSystem;
class CB3TrafficValve;
struct UnkStruct_00267EC0_1;
struct UnkStruct_00267EC0_4;
struct UnkStruct_00267EC0_8;
struct UnkStruct_00267EC0_e10;
struct UnkStruct_00267EC0_e2;
struct UnkStruct_00267EC0_e8;
struct UnkStruct_D_00522660;
struct UnkStruct_D_00665EA0;

class CB3TrafficSystem {
public:
    void Generate(ETrafficVehicleCategories, unsigned long, ETrafficVehicleCategories, unsigned long, CB3TrafficLane*, float, float, float, unsigned char, unsigned char, unsigned char);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00267EC0_1 {
    int * field_0;
    unsigned char pad_4[0x4];
    int field_8;
};

struct UnkStruct_D_00665EA0 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00267EC0_4 {
    UnkStruct_00267EC0_e2 * field_0;
    float field_4;
    unsigned char field_8;
};

struct UnkStruct_00267EC0_e2 {
    unsigned long field_0;
    unsigned long field_8;
    unsigned char pad_10[0x4];
    float field_14;
    unsigned char field_18;
    unsigned char field_19;
    unsigned char field_1A;
    unsigned char field_1B;
    unsigned char pad_1C[0x4];
};

struct UnkStruct_00267EC0_8 {
    float field_0;
};

struct UnkStruct_00267EC0_e8 {
    unsigned long field_0;
    unsigned long field_8;
    unsigned char pad_10[0x4];
    float field_14;
    unsigned char field_18;
    unsigned char field_19;
    unsigned char field_1A;
    unsigned char field_1B;
    unsigned char pad_1C[0x4];
};

struct UnkStruct_00267EC0_e10 {
    unsigned char pad_0[0x4C];
};

struct UnkStruct_D_00522660 {
    UnkStruct_00267EC0_e10 field_0[1];  // [G] element count unknown
};

class CB3TrafficValve {
public:
    void Update(int p0, unsigned short p1, float p2, bool p3, bool p4);
    void UpdateGeneration(int, int, unsigned short, float);

    UnkStruct_00267EC0_8 * field_0[1];  // [G] element count unknown
    unsigned char pad_4[0xC];
    float * field_10[1];  // [G] element count unknown
    unsigned char pad_14[0x1C];
    UnkStruct_00267EC0_4 * field_30[1];  // [G] element count unknown
    unsigned char pad_34[0xC];
    UnkStruct_00267EC0_1 * field_40;
    unsigned char pad_44[0xCC];
    unsigned char field_110[1];  // [G] element count unknown
    unsigned char pad_111[0x3];
    unsigned char field_114;
};

extern UnkStruct_D_00665EA0 D_00665EA0;
extern UnkStruct_D_00522660 D_00522660;
extern CB3TrafficSystem D_00527440;

extern "C" float GetParamFromDist__14CB3TrafficLaneFf(void *, float);  // CB3TrafficLane::GetParamFromDist(float)

// Inlined helpers (placeholder names [G]).
static inline CB3TrafficLane * func_00267EC0_lane(int idx)
{
    if (idx == 255) {
        return 0;
    }
    return (CB3TrafficLane *)((char *)&D_00522660.field_0[idx] + 0x22C);
}

static inline void func_00267EC0_gen(CB3TrafficValve * v, int i, float dist)
{
    UnkStruct_00267EC0_e2 * rec;
    int cat2;
    UnkStruct_00267EC0_4 * e = v->field_30[i];
    if (e != 0) {
        unsigned char & n = v->field_110[i];
        if (n < e->field_8) {
            rec = &e->field_0[n];
            if (!(dist < rec->field_14)) {
                if (rec->field_18 == 4) {
                    cat2 = 11;
                } else {
                    cat2 = 0;
                }
                float speed = v->field_0[i]->field_0;
                float param = GetParamFromDist__14CB3TrafficLaneFf(func_00267EC0_lane(v->field_40->field_0[i]), e->field_4);
                D_00527440.Generate((ETrafficVehicleCategories)rec->field_18, rec->field_0, (ETrafficVehicleCategories)cat2, rec->field_8, func_00267EC0_lane(v->field_40->field_0[i]), param, speed, v->field_10[i][rec->field_18], rec->field_19, rec->field_1A, rec->field_1B);
                n++;
            }
        }
    }
}

// 0x00267EC0
void CB3TrafficValve::Update(int p0, unsigned short p1, float p2, bool p3, bool p4)
{
    if (p4) {
        for (int i = 0; i < field_40->field_8; i++) {
            if (D_00665EA0.field_0 != 0) {
                func_00267EC0_gen(this, i, 45.0f);
            } else {
                func_00267EC0_gen(this, i, p2);
            }
        }
    } else if (field_114 != 0 || !p3) {
        for (int i = 0; i < field_40->field_8; i++) {
            UpdateGeneration(i, p0, p1, p2);
        }
    }
}



#pragma pop
