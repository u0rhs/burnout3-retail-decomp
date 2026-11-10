// CB3PhysicsManager::AddRaceCar(CB3RaceCar*,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3PhysicsManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (AddRaceCar: reverse switch for ph select, idx via signed char pun, 64B copy as 4 members).

typedef unsigned long u_long128 __attribute__((mode(TI)));
struct UnkStruct_001B89D0_m {
    u_long128 q0;
    u_long128 q1;
    u_long128 q2;
    u_long128 q3;
};
class UnkStruct_001B89D0_ph {
public:
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual void vfunc_20(void *);
    unsigned char pad_4[0x200];
    int field_204;
};
class CB3RaceCar {
public:
    unsigned char pad_0[0x1788];
    UnkStruct_001B89D0_m ** field_1788;
    unsigned char pad_178C[0x188];
    int field_1914;
    unsigned char pad_1918[0x94];
    signed char field_19AC;
};
struct UnkStruct_001B89D0_b {
    unsigned char field_0;
    unsigned char field_1;
    unsigned char field_2;
    unsigned char pad_3;
    int field_4;
    int field_8;
    UnkStruct_001B89D0_ph * field_C;
};
extern "C" void func_001AB610(void *, void *);
extern "C" void ResetOnTrack__17CB3RaceCarPhysicsFbP17CB3RaceCarPhysics(void *, bool, void *);
extern "C" void GetIntervals__17CB3PhysicsManagerFP13CB3ActiveBody(void *, void *);

class CB3PhysicsManager {
public:
    void AddRaceCar(CB3RaceCar * p0, int p1);
    unsigned char pad_0[0x70];
    UnkStruct_001B89D0_b field_70[1];
};

// 0x001B89D0
void CB3PhysicsManager::AddRaceCar(CB3RaceCar * p0, int p1)
{
    UnkStruct_001B89D0_ph * s1;
    switch (p0->field_1914) {
    case 0:
        s1 = (UnkStruct_001B89D0_ph *)((char *)this + p1 * 0x4590 + 0x1CB80);
        break;
    case 1:
        s1 = (UnkStruct_001B89D0_ph *)((char *)this + p1 * 0x1580 + 0x256A0);
        break;
    case 2:
        s1 = (UnkStruct_001B89D0_ph *)((char *)this + p1 * 0x1560 + 0x2C220);
        break;
    }
    s1->vfunc_20(p0);
    unsigned char * pidx = (unsigned char *)&p0->field_19AC;
    int idx = *(signed char *)pidx;
    int t = p0->field_1914;
    UnkStruct_001B89D0_b * b = (UnkStruct_001B89D0_b *)((char *)this + idx * 0x30 + 0x70);
    switch (t) {
    case 0:
        b->field_0 = 2;
        break;
    case 1:
        b->field_0 = 0;
        break;
    case 2:
        b->field_0 = 1;
        break;
    }
    b->field_C = s1;
    UnkStruct_001B89D0_m * src = *p0->field_1788;
    UnkStruct_001B89D0_m m;
    m.q0 = src->q0;
    m.q1 = src->q1;
    m.q2 = src->q2;
    m.q3 = src->q3;
    func_001AB610(b->field_C, &m);
    ResetOnTrack__17CB3RaceCarPhysicsFbP17CB3RaceCarPhysics(s1, false, 0);
    b->field_4 = b->field_C->field_204;
    b->field_8 = (int)b->field_C + 0x1D0;
    b->field_1 = 0;
    b->field_2 = p1;
    GetIntervals__17CB3PhysicsManagerFP13CB3ActiveBody(this, b);
}
