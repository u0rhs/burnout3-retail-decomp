// CB3CrashScore::HandleCrashTrafficCar(CB3TrafficPhysics*,CB3TrafficVehicle*,bool,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CrashScore.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (near15: find as static inline with early returns; if (find != -1) return; then the appends).


struct UnkStruct_HCT_veh { unsigned char pad_0[0x176]; unsigned char field_176; };
struct UnkStruct_HCT_phys { int dummy; };
struct UnkStruct_HCT {
    unsigned char pad_0[0x18];
    UnkStruct_HCT_phys *field_18[1];
    unsigned char pad_1C[0x120 - 0x1C];
    int field_120[1];
    unsigned char pad_124[0x4AF - 0x124 - 0x0];
    unsigned char field_4AF;
    unsigned char field_4B0[1];
};
extern int D_0055B860[];
static inline int func_003CD430_inl1(UnkStruct_HCT *self, UnkStruct_HCT_phys *p0)
{
    for (int i = 0; i < self->field_4AF; i++) {
        if (self->field_18[i] == p0) {
            return i;
        }
    }
    return -1;
}

extern "C" void HandleCrashTrafficCar__13CB3CrashScoreFP17CB3TrafficPhysicsP17CB3TrafficVehiclebi(UnkStruct_HCT *self, UnkStruct_HCT_phys *p0, UnkStruct_HCT_veh *p1, bool p2, int p3)
{
    if (func_003CD430_inl1(self, p0) != -1) return;
    self->field_4B0[self->field_4AF] = p2;
    self->field_18[self->field_4AF] = p0;
    self->field_120[self->field_4AF] = D_0055B860[p1->field_176];
    self->field_4AF = self->field_4AF + 1;
}
