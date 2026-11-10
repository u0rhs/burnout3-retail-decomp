// GetLaneChanges__18CB3TrafficSplitterFPbPUc25ETrafficVehicleCategoriesP15CB3TrafficParam -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (a88: GetLaneChanges, nested arm1-last with early returns in the other arms).

// Hand-written (a88: CB3TrafficSplitter::GetLaneChanges, DNAT high).
// [L] DNAT: CB3TrafficSplitter::GetLaneChanges(bool*,unsigned char*,ETrafficVehicleCategories,CB3TrafficParam*) (research/proto/new_names.csv, high)
#include "b3/_unclassified/GtRandom.h"

struct UnkStruct_D_0055D788 { CGtRandom r; unsigned char pad[0x8]; };
struct UnkStruct_0026BD50_p { unsigned char pad_0[0x24]; float field_24; };
struct UnkStruct_0026BD50_t {
    unsigned char pad_0[0x14];
    int field_14[1];
    unsigned char pad_18[0x14];
    int field_2C[1];
};
struct UnkStruct_0026BD50 { int * field_0; };
extern UnkStruct_D_0055D788 D_0055D788;

// 0x0026BD50
extern "C" bool GetLaneChanges__18CB3TrafficSplitterFPbPUc25ETrafficVehicleCategoriesP15CB3TrafficParam(UnkStruct_0026BD50 * self, bool * p0, unsigned char * p1, int p2, UnkStruct_0026BD50_p * p3)
{
    const float k = 2.3283064e-10f;
    float r = k * (float)D_0055D788.r.Random();
    int * e = (int *)((char *)(p2 * 4) + (int)self->field_0);
    float a = 0.0f;
    float q = (float)e[-1] / 100.0f;
    a += q;
    if (!(r < a)) {
        float b2 = (float)e[5] / 100.0f;
        float b = a + b2;
        if (r < b) {
            p3->field_24 = p3->field_24 * b2;
            *p1 = 1;
            *p0 = true;
            return true;
        }
        float c = (float)e[11] / 100.0f;
        p3->field_24 = p3->field_24 * c;
        *p1 = 1;
        *p0 = false;
        return true;
    }
    p3->field_24 = p3->field_24 * q;
    *p1 = 0;
    return false;
}
