// NONMATCHING: Generate__16CB3TrafficSystemF25ETrafficVehicleCategoriesUl25ETrafficVehicleCategoriesUlP14CB3TrafficLanefffUcUcUc -- retail 1018 / ours 1022 instructions, 152 in changed runs
// retail 1018 / ours 1022: logic complete; left: frame 0x250 vs 0x1F0 (retail has more 16-byte temps), ZAxisType->float does 2 stack copies via the header's operator float (retail 1), vehicle-alloc bit index srl/andi order, RNG scheduling
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm (every block of the 1018-instruction listing walked: free-list pops, dead-list pushes, trailer loop, second vehicle, RNG %3 switch); calls/stores in retail order

// CB3TrafficSystem::Generate -- hand-written (draft2) from the retail asm + Ghidra draft; never attempted before.
// [C] name: the mangled symbol. Classes declared here with only what this function touches; field names are
// placeholders and every type is [G] (instruction widths). The helpers below are inlined in retail (no calls);
// AddToDeadTrafficParamList's body is the proven B3TrafficSystem_00163DD0.cpp one.
#include "b3/GtMathPs2.h"
#include "b3/GtMathPs2Quat.h"
using namespace GtMathPs2;

enum ETrafficVehicleCategories {};
enum ETrafficParamState {};
class CB3TrafficLane;

struct UnkStruct_00164A50_obj {
    unsigned char pad_0[0xE80];
    CGtV3d field_E80;
    CGtV3d field_E90;
};

class CB3TrafficParam {
public:
    void ResetMemberVariables();
    int Insert(CB3TrafficLane *, float, float, ETrafficParamState);
    void CalculateTargetParamMatrix();

    float field_0;
    unsigned char pad_4[0x4];
    float field_8;
    float field_C;
    unsigned char pad_10[0x14];
    float field_24;
    unsigned char pad_28[0x4];
    float field_2C;
    unsigned char pad_30[0x14];
    unsigned char field_44;     // next free param index (0xFF = none)
    unsigned char pad_45[0x4];
    unsigned char field_49;     // own index
    unsigned char field_4A;
    unsigned char field_4B;
    unsigned char pad_4C[0x1];
    unsigned char field_4D;
    unsigned char pad_4E[0x2];
};

class CB3TrafficVehicle {
public:
    int Create(ETrafficVehicleCategories, unsigned char);

    unsigned char pad_0[0x70];
    CGtMatrix3x4 field_70;
    UnkStruct_00164A50_obj * field_B0;
    unsigned char pad_B4[0x10];
    float field_C4;
    unsigned char pad_C8[0x1];
    unsigned char field_C9;
    unsigned char pad_CA[0x3E];
    CB3TrafficVehicle * field_108;   // free-list next
    CB3TrafficVehicle * field_10C;
    CB3TrafficVehicle * field_110;
    CB3TrafficParam * field_114;
    unsigned char pad_118[0x8];
    float field_120;
    unsigned char pad_124[0x4];
    float field_128;
    unsigned char pad_12C[0x8];
    float field_134;
    float field_138;
    unsigned char pad_13C[0x35];
    unsigned char field_171;
    unsigned char pad_172[0x2];
    unsigned char field_174;
    unsigned char pad_175[0x1];
    unsigned char field_176;
    unsigned char field_177;   // own index
    unsigned char pad_178[0x2];
    unsigned char field_17A;
};

struct UnkStruct_00164A50_mat {
    CGtMatrix3x4 field_0;
    unsigned char pad_40[0x10];
};

class CB3TrafficSystem {
public:
    CB3TrafficVehicle * Generate(ETrafficVehicleCategories, unsigned long, ETrafficVehicleCategories, unsigned long,
                                 CB3TrafficLane *, float, float, float, unsigned char, unsigned char, unsigned char);

    unsigned char pad_0[0x2F430];
    UnkStruct_00164A50_mat field_2F430[1];   // [G] element count unknown
    unsigned char pad_2F480[0x4F10];
    unsigned long field_34390[1];  // [G] element count unknown
    unsigned char pad_34398[0x58];
    int field_343F0[1];  // [G] element count unknown
    unsigned char pad_343F4[0x5C];
    signed char field_34450;
    unsigned char pad_34451[0x1E8F];
    unsigned int field_362E0[8];
    unsigned int field_36300[8];
    unsigned char pad_36320[0x28];
    int field_36348;
    int field_3634C;
    unsigned char pad_36350[0x14];
    CB3TrafficVehicle * field_36364;
    CB3TrafficVehicle * field_36368;
    CB3TrafficParam * field_3636C;
    unsigned char pad_36370[0x3B];
    unsigned char field_363AB;
    unsigned char field_363AC;
    unsigned char pad_363AD[0x7];
    unsigned char field_363B4[3];
    unsigned char pad_363B7[0x7];
    unsigned char field_363BE;
};

struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x2F2B0];
    CB3TrafficParam field_2F2B0[1];   // [G] the traffic system's param pool, addressed through the outer object
};
struct UnkStruct_Pad16 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_Pad16 D_0055EF70;
extern "C" void func_00163E90(CB3TrafficSystem *, CB3TrafficVehicle *, int);  // [L] E: AddToDeadTrafficList(CB3TrafficVehicle*,bool)
extern "C" void func_00162BE0(CB3TrafficParam *);
extern "C" void AddTrafficVehicle__17CB3PhysicsManagerFP17CB3TrafficVehicle(void *, CB3TrafficVehicle *);

// vehicle free-list pop
static inline CB3TrafficVehicle * func_00164A50_inl1(CB3TrafficSystem * s)
{
    CB3TrafficVehicle * v = s->field_36364;
    if (v == 0) return 0;
    s->field_36364 = v->field_108;
    v->field_108 = 0;
    s->field_362E0[(unsigned short)(v->field_177 / 32)] |= 1 << (v->field_177 % 32);
    s->field_363AC++;
    v->field_174 |= 1;
    if (s->field_36364 == 0) s->field_36368 = 0;
    return v;
}

// param free-list pop
static inline CB3TrafficParam * func_00164A50_inl2(CB3TrafficSystem * s)
{
    CB3TrafficParam * p = s->field_3636C;
    if (p == 0) return 0;
    s->field_3636C = (p->field_44 == 0xFF) ? 0 : &D_00522660.field_2F2B0[p->field_44];
    p->ResetMemberVariables();
    s->field_36300[(unsigned short)(p->field_49 / 32)] |= 1 << (p->field_49 % 32);
    p->field_4B |= 8;
    return p;
}

// CB3TrafficSystem::AddToDeadTrafficParamList body (proven out of line at 0x163DD0)
static inline void func_00164A50_inl3(CB3TrafficSystem * s, CB3TrafficParam * p0)
{
    func_00162BE0(p0);
    p0->field_44 = s->field_3636C->field_49;
    s->field_3636C = p0;
    unsigned char t0 = p0->field_49;
    s->field_36300[(unsigned short)(t0 / 32)] &= ~(1 << (t0 % 32));
    p0->field_4B = (p0->field_4B & 247);
}

// random step
static inline unsigned int func_00164A50_inl4(CB3TrafficSystem * s)
{
    s->field_36348 = (s->field_36348 << 16) + (s->field_36348 >> 16);
    s->field_36348 += s->field_3634C;
    s->field_3634C += s->field_36348;
    return s->field_36348;
}

static inline float func_00164A50_inl5(CB3TrafficSystem * s, int range, int div)
{
    return (float)((int)(func_00164A50_inl4(s) % range) - range / 2) / (float)div;
}

CB3TrafficVehicle * CB3TrafficSystem::Generate(ETrafficVehicleCategories cat, unsigned long id, ETrafficVehicleCategories cat2,
                                               unsigned long id2, CB3TrafficLane * lane, float f0, float f1, float f2,
                                               unsigned char c0, unsigned char c1, unsigned char c2)
{
    if (field_363BE != 0) return 0;
    if (cat == 0) return 0;
    CB3TrafficVehicle * head = field_36364;
    if (head == 0 || head->field_108 == 0) return 0;
    if (cat == 7) {
        if (field_363AC + 3 > field_363AB) return 0;
    } else {
        if (field_363AC + 2 > field_363AB) return 0;
    }
    CB3TrafficVehicle * v = func_00164A50_inl1(this);
    CB3TrafficParam * p = func_00164A50_inl2(this);
    if (p == 0) {
        if (v != 0) func_00163E90(this, v, 0);
        return 0;
    }
    if (v == 0) {
        if (p != 0) func_00164A50_inl3(this, p);
        return 0;
    }
    for (int i = 0; i < field_34450; i++) {
        if (id == field_34390[i]) {
            v->field_B0 = (UnkStruct_00164A50_obj *)field_343F0[i];
            v->field_176 = i;
            break;
        }
    }
    if (!v->Create(cat, c2)) {
        func_00163E90(this, v, 0);
        func_00164A50_inl3(this, p);
        return 0;
    }
    float r = func_00164A50_inl5(this, 1000, 10000);
    p->field_0 = f1;
    if (!p->Insert(lane, f0, r + 0.5f, (ETrafficParamState)1)) {
        func_00163E90(this, v, 0);
        func_00164A50_inl3(this, p);
        return 0;
    }
    v->field_114 = p;
    v->field_C4 = p->field_2C;
    p->field_4A = v->field_177;
    p->field_4D = cat;
    p->field_24 = f2;
    if (v->field_B0 != 0) {
        p->field_8 = v->field_B0->field_E80.Z();
        p->field_C = v->field_B0->field_E90.Z();
    }
    func_00164A50_inl4(this);
    v->field_128 = (int)(unsigned char)field_36348;
    v->field_17A |= 1;
    v->field_114->CalculateTargetParamMatrix();
    v->field_70 = field_2F430[v->field_114->field_49].field_0;
    v->field_70.mPos += v->field_70.mUp * v->field_120;
    if ((v->field_174 & 4) == 0 || cat == 8) {
        AddTrafficVehicle__17CB3PhysicsManagerFP17CB3TrafficVehicle(&D_0055EF70, v);
    }
    v->field_171 = 0;
    v->field_C9 = c0;
    if ((unsigned int)(cat - 7) < 3) {
        int n;
        if (cat == 7) {
            n = 2;
        } else {
            n = 1;
        }
        CB3TrafficVehicle * prev = v;
        for (int i = 0; i < n; i++) {
            CB3TrafficVehicle * t = func_00164A50_inl1(this);
            if (t == 0) {
                func_00163E90(this, v, 0);
                func_00164A50_inl3(this, p);
                return 0;
            }
            t->field_B0 = prev->field_B0;
            t->field_176 = prev->field_176;
            if (!t->Create(cat, c2)) {
                func_00163E90(this, v, 0);
                func_00163E90(this, t, 0);
                func_00164A50_inl3(this, p);
                return 0;
            }
            prev->field_110 = t;
            t->field_10C = prev;
            t->field_C4 = prev->field_C4;
            t->field_C9 = c0;
            if (t->field_B0 != 0) {
                p->field_C = t->field_B0->field_E90.Z() + prev->field_134 + t->field_138;
            }
            func_00164A50_inl4(this);
            t->field_128 = (int)(unsigned char)field_36348;
            t->field_17A |= 1;
            t->field_70 = prev->field_70;
            if ((unsigned int)(cat - 8) < 2) {
                t->field_138 = t->field_134;
            }
            if (cat == 8) {
                AddTrafficVehicle__17CB3PhysicsManagerFP17CB3TrafficVehicle(&D_0055EF70, t);
            }
            prev = t;
        }
    }
    if (cat2 == 0) return v;
    CB3TrafficVehicle * t = func_00164A50_inl1(this);
    if (t == 0) {
        func_00163E90(this, v, 1);
        func_00164A50_inl3(this, p);
        return 0;
    }
    for (int i = 0; i < field_34450; i++) {
        if (id2 == field_34390[i]) {
            t->field_B0 = (UnkStruct_00164A50_obj *)field_343F0[i];
            t->field_176 = i;
            break;
        }
    }
    if (!t->Create(cat2, c2)) {
        func_00163E90(this, t, 0);
        func_00163E90(this, v, 1);
        func_00164A50_inl3(this, p);
        return 0;
    }
    v->field_110 = t;
    t->field_10C = v;
    t->field_C4 = v->field_C4;
    if (t->field_B0 != 0) {
        p->field_C = t->field_B0->field_E90.Z() + v->field_134 + t->field_138;
    }
    func_00164A50_inl4(this);
    t->field_128 = (int)(unsigned char)field_36348;
    t->field_17A |= 1;
    t->field_70 = v->field_70;
    AddTrafficVehicle__17CB3PhysicsManagerFP17CB3TrafficVehicle(&D_0055EF70, t);
    unsigned char lt;
    switch ((unsigned char)(func_00164A50_inl4(this) % 3)) {
    case 0:
        lt = field_363B4[0];
        break;
    case 1:
        lt = field_363B4[1];
        break;
    case 2:
    default:
        lt = field_363B4[2];
        break;
    }
    t->field_171 = lt;
    t->field_C9 = c1;
    return v;
}
