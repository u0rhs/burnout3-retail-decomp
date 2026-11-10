// NONMATCHING: Update__17CB3PhysicsManagerFf -- retail 582 / ours 589 instructions, 273 in changed runs
// draftM: 582/589, 273 changed. Left: the sweep's inner if-chain (z/z/AllowCollision/y) is moved out of line in ours, inline in retail (no change from &&/nested/continue/goto/else/inline-wrapped/operand-order forms); x key via stack slot (retail lq+sw, frame 0x3E0 vs 0x420); pair-inline argument registers; Impact f12 load placement
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the asm: every loop, branch, call and store accounted for (interval update, x sort, z/y sweep with 0x100-pair cap, pool updates, Impact)

// CB3PhysicsManager::Update(float) -- hand-written (draftM) from the retail asm and the Ghidra draft.
// [C] name: the mangled symbol in retail's tables; Revenge's CB4PhysicsManager::Update is 0x28C bytes, so not used.
// Shape [C asm]: interval update, an x sort (qsort, func_001B9820) and a sweep over the sorted interval ends that
// tests z and y overlap and queues colliding pairs (at most 0x100), then the per-pool updates. Field names are
// placeholders and every type is [G] (instruction widths); pool element sizes from CB3PhysicsManager::Release [C].
#include "b3/GtMathPs2.h"
#include "b3/GtMath.h"
using namespace GtMathPs2;

class CB3VehicleDeform;
struct UnkStruct_001B8F00_deform {        // [G] the object at vehicle->field_CC4
    unsigned char pad_0[0x300];
    unsigned char field_300[0x44];        // CB3VehicleDeform [L] (Impact's this)
    unsigned char field_344;
};
struct UnkStruct_001B8F00_p {             // [G] vehicle->field_13F4
    unsigned char pad_0[0x1914];
    int field_1914;
    unsigned char pad_1918[0x48];
    unsigned long field_1960;
};
struct UnkStruct_001B8F00_veh {           // [L] CB3VehiclePhysics (Impact's first argument)
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    unsigned char pad_4[0x15C];
    CGtV3d field_160;
    CGtV3d field_170;
    unsigned char pad_180[0x14];
    float field_194;
    int field_198;
    unsigned char pad_19C[0x72];
    unsigned char field_20E;
    unsigned char pad_20F;
    unsigned char field_210;
    unsigned char field_211;
    unsigned char field_212;
    unsigned char pad_213[0xCC0 - 0x213];
    void *field_CC0;
    UnkStruct_001B8F00_deform *field_CC4;
    unsigned char pad_CC8[0x13F4 - 0xCC8];
    UnkStruct_001B8F00_p *field_13F4;
};
class CB3ActiveBody {
public:
    signed char field_0;                  // body type [G]
    unsigned char field_1;
    unsigned char pad_2[0xA];
    UnkStruct_001B8F00_veh *field_C;
    CGtV3d field_10;                      // interval min [G]
    CGtV3d field_20;                      // interval max [G]
};
struct UnkStruct_001B8F00_end {           // one sorted interval end (func_001B9820 compares field_0)
    float field_0;
    short field_4;                        // body index
    unsigned char field_6;                // 1 = min end [G]
    unsigned char pad_7;
};
class CB3CollidingPair {
public:
    unsigned char pad_0[0x24];
    CB3ActiveBody *field_24;
    CB3ActiveBody *field_28;
    unsigned char pad_2C[0x4];
};
struct UnkStruct_001B8F00_car { virtual void vfunc_8(float); unsigned char pad_4[0x134F]; unsigned char field_1353; unsigned char pad_1354[0x4590 - 0x1354]; };
struct UnkStruct_001B8F00_ai { virtual void vfunc_8(float); unsigned char pad_4[0x134F]; unsigned char field_1353; unsigned char pad_1354[0x1580 - 0x1354]; };
struct UnkStruct_001B8F00_net { virtual void vfunc_8(float); unsigned char pad_4[0x134F]; unsigned char field_1353; unsigned char pad_1354[0x1560 - 0x1354]; };
struct UnkStruct_001B8F00_tr { unsigned char pad_0[0x2430]; };
struct UnkStruct_001B8F00_prop { virtual void vfunc_8(float); unsigned char pad_4[0x77C]; };
struct UnkStruct_001B8F00_part { virtual void vfunc_8(float); unsigned char pad_4[0x4DC]; };
struct UnkStruct_001B8F00_any { virtual void vfunc_8(float); unsigned char pad_4[0x134F]; unsigned char field_1353; };

class CB3PhysicsManager {
public:
    void Update(float);
    void GetIntervals(CB3ActiveBody *);
    int AllowCollision(CB3ActiveBody &, CB3ActiveBody &);
    void CollideAndRespondPair(CB3CollidingPair *);
    void UpdateNearMissArray();

    unsigned char pad_0[0x70];
    CB3ActiveBody field_70[1224];
    UnkStruct_001B8F00_end field_E5F0[2448];
    unsigned char pad_13270[0x1CB70 - 0x13270];
    int field_1CB70;                      // body count
    int field_1CB74;                      // interval-end count
    unsigned char pad_1CB78[0x8];
    UnkStruct_001B8F00_car field_1CB80[2];
    UnkStruct_001B8F00_ai field_256A0[5];
    UnkStruct_001B8F00_net field_2C220[5];
    UnkStruct_001B8F00_tr field_32D00[64];
    UnkStruct_001B8F00_prop field_C3900[32];
    UnkStruct_001B8F00_part field_D2900[64];
    UnkStruct_001B8F00_any *field_E6100[64];
    int field_E6200;
    int field_E6204;
    int field_E6208;
    int field_E620C;
    CB3CollidingPair field_E6210[256];
    int field_E9210;                      // pair count
    unsigned char pad_E9214[0x4];
    unsigned long field_E9218;            // active body-part mask
    unsigned long field_E9220;            // active prop mask
};

struct UnkStruct_001B8F00_cad { unsigned char pad_0[0x10]; };
struct UnkStruct_001B8F00_int { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_001B8F00_cad D_0055E948;
extern UnkStruct_001B8F00_int D_0064D37C;
extern "C" void qsort(void *, unsigned int, unsigned int, int (*)(const void *, const void *));
extern "C" int func_001B9820(const void *, const void *);
extern "C" void Update__22CB3CrashActionDirectorFf(void *, float);
extern "C" void Impact__16CB3VehicleDeformFP17CB3VehiclePhysicsP25CB3VehicleEssentialParamsP16CB3VehicleParams25ETrafficVehicleCategories17EB3ActiveBodyType13EB3ImpactTypeQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3df(
    void *, void *, void *, void *, unsigned long, int, int, int, const CGtV3d &, const CGtV3d &, int, float);

// [G] x lane read through a register copy (retail lq + sw: the 128-bit temporary is forwarded away, N129)
static inline int func_001B8F00_inl1(const CGtV3d &v)
{
    u_long128 t = v.mData;
    return *(int *)&t;
}
static inline bool func_001B8F00_inl2(const CB3ActiveBody *b)
{
    return b->field_0 == 4 || b->field_0 == 6 || b->field_0 == 7;
}
static inline bool func_001B8F00_inl3(const CB3ActiveBody *b)
{
    bool r = true;
    if ((unsigned int)b->field_0 >= 3 && !func_001B8F00_inl2(b)) r = false;
    return r;
}

static inline void func_001B8F00_inl4(CB3PhysicsManager *m, short ia, short ib)
{
    if (m->field_70[ia].field_10.Y() < m->field_70[ib].field_20.Y() && m->field_E9210 < 0x100) {
        int hi = GtMath::Max(ia, ib);
        int lo = GtMath::Min(ia, ib);
        m->field_E6210[m->field_E9210].field_28 = &m->field_70[hi];
        m->field_E6210[m->field_E9210].field_24 = &m->field_70[lo];
        m->field_E9210++;
    }
}

// 0x001B8F00
void CB3PhysicsManager::Update(float dt)
{
    int i;
    int n = 0;
    short active[256];
    CB3ActiveBody *b = field_70;
    for (i = 0; i < field_1CB70; i++, b++) {
        if (b->field_0 != 5) GetIntervals(b);
    }
    for (i = 0; i < field_1CB74; i++) {
        UnkStruct_001B8F00_end *e = &field_E5F0[i];
        CB3ActiveBody *a = &field_70[e->field_4];
        if (e->field_6) {
            *(int *)&e->field_0 = func_001B8F00_inl1(a->field_10);
        } else {
            *(int *)&e->field_0 = func_001B8F00_inl1(a->field_20);
        }
    }
    qsort(field_E5F0, field_1CB74, 8, func_001B9820);
    field_E9210 = 0;
    for (i = 0; i < field_1CB74; i++) {
        UnkStruct_001B8F00_end *e = &field_E5F0[i];
        if (e->field_6) {
            for (int j = 0; j < n; j++) {
                int ia = e->field_4;
                int ib = active[j];
                if (field_70[ia].field_20.Z() > field_70[ib].field_10.Z() && field_70[ia].field_10.Z() < field_70[ib].field_20.Z() &&
                    AllowCollision(field_70[ia], field_70[ib]) && field_70[ia].field_20.Y() > field_70[ib].field_10.Y()) {
                    func_001B8F00_inl4(this, ia, ib);
                }
            }
            active[n++] = e->field_4;
        } else {
            int j;
            for (j = 0; j < n; j++) {
                if (e->field_4 == active[j]) break;
            }
            for (; j < n - 1; j++) active[j] = active[j + 1];
            n = n - 1;
        }
    }
    for (i = 0; i < field_1CB70; i++) {
        CB3ActiveBody *a = &field_70[i];
        if (func_001B8F00_inl3(a)) {
            if ((field_70[i].field_C->field_20E == 0 || a->field_0 == 7) && field_70[i].field_1 == 0) field_70[i].field_C->vfunc_18();
            field_70[i].field_C->field_211 = 0;
        }
    }
    for (i = 0; i < field_E9210; i++) CollideAndRespondPair(&field_E6210[i]);
    for (i = 0; i < field_E6200; i++) field_1CB80[i].field_1353 = 0;
    for (i = 0; i < field_E6204; i++) field_256A0[i].field_1353 = 0;
    for (i = 0; i < field_E6208; i++) field_2C220[i].field_1353 = 0;
    for (i = 0; i < field_E620C; i++) field_E6100[i]->field_1353 = 0;
    UpdateNearMissArray();
    Update__22CB3CrashActionDirectorFf(&D_0055E948, dt);
    for (i = 0; i < field_E6200; i++) field_1CB80[i].vfunc_8(dt);
    for (i = 0; i < field_E6204; i++) field_256A0[i].vfunc_8(dt);
    for (i = 0; i < field_E6208; i++) field_2C220[i].vfunc_8(dt);
    for (i = 0; i < field_E620C; i++) field_E6100[i]->vfunc_8(dt);
    {
        unsigned long bit = 1;
        UnkStruct_001B8F00_prop *p = field_C3900;
        for (i = 0; i < 32; i++, bit <<= 1, p++) {
            if (field_E9220 & bit) p->vfunc_8(dt);
        }
    }
    {
        unsigned long bit = 1;
        UnkStruct_001B8F00_part *p = field_D2900;
        for (i = 0; i < 64; i++, bit <<= 1, p++) {
            if (field_E9218 & bit) p->vfunc_8(dt);
        }
    }
    for (i = 0; i < D_0064D37C.field_0; i++) {
        UnkStruct_001B8F00_veh *v = field_70[i].field_C;
        if (v->field_212 && v->field_198 == 1 && v->field_210) {
            int t;
            switch (v->field_13F4->field_1914) {
            case 0: t = 2; break;
            case 2: t = 1; break;
            case 1:
            case 3: t = 0; break;
            default: t = 0; break;
            }
            Impact__16CB3VehicleDeformFP17CB3VehiclePhysicsP25CB3VehicleEssentialParamsP16CB3VehicleParams25ETrafficVehicleCategories17EB3ActiveBodyType13EB3ImpactTypeQ29GtMathPs26CGtV3dQ29GtMathPs26CGtV3df(
                v->field_CC4->field_300, v, v->field_CC0, v->field_CC4, v->field_13F4->field_1960, 12, t, 1,
                v->field_160, v->field_170, 0, v->field_194);
            v->field_CC4->field_344 = 1;
        } else {
            v->field_CC4->field_344 = 0;
        }
    }
}


