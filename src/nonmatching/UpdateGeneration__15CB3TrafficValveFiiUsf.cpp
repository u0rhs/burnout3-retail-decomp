// NONMATCHING: UpdateGeneration__15CB3TrafficValveFiiUsf -- retail 431 / ours 436 instructions, 283 in changed runs
// lit4fix: .lit4 externs rewritten as literals; was: a160: 436/431 instrs, 283 in changed runs; logic complete (jitter loop matches retail through the RNG; ring buffer/lane/Generate/vehicle-setup blocks follow m2c). Open: div.s hoisted above the unsigned->float branch (retail keeps the field_10[i][k] reload+div after it); retail keeps s4=i*20 (offset)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/_unclassified/GtRandom.h"

enum ETrafficVehicleCategories {};
class CB3TrafficLane;
class CB3TrafficVehicle;
class CB3TrafficValve;

struct UnkStruct_00267800_spd { float field_0; };
struct UnkStruct_00267800_arr { unsigned char pad_0[0x10]; int field_10; };
struct UnkStruct_00267800_ctl {
    int * field_0;
    int * field_4;
    int field_8;
    unsigned char field_C;
    unsigned char field_D;
};
struct UnkStruct_00267800_ring {
    unsigned char * field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
};
struct UnkStruct_00267800_rb {
    unsigned char pad_0[0x44];
    unsigned char * field_44;
    int field_48;
    int field_4C;
    int field_50;
    int field_54;
};
struct UnkStruct_00267800_ent { unsigned long field_0; unsigned char field_8[8]; };
struct UnkStruct_00267800_seg { unsigned char pad_0[0x4]; unsigned short field_4; unsigned char pad_6[0xA]; UnkStruct_00267800_arr * field_10; };
struct UnkStruct_00267800_lane { UnkStruct_00267800_arr * field_0; unsigned short field_4; };
struct UnkStruct_00267800_veh2 { unsigned char pad_0[0x38]; UnkStruct_00267800_arr * field_38; unsigned char pad_3C[0xB]; unsigned char field_47; };
struct UnkStruct_00267800_veh { unsigned char pad_0[0x114]; UnkStruct_00267800_veh2 * field_114; unsigned char pad_118[0x5C]; unsigned char field_174; };
struct UnkStruct_00267800_tbl { unsigned long field_0[5]; };
struct UnkStruct_D_0055D788 { CGtRandom r; unsigned char pad[0x8]; };
struct UnkStruct_00267800_m { unsigned char pad_0[0x4C]; };
struct UnkStruct_D_00522660 { UnkStruct_00267800_m field_0[1]; };

class CB3TrafficSystem {
public:
    bool IsSegmentLocked(int, unsigned short);
    UnkStruct_00267800_veh * Generate(ETrafficVehicleCategories, unsigned long, ETrafficVehicleCategories, unsigned long, CB3TrafficLane*, float, float, float, unsigned char, unsigned char, unsigned char);
    UnkStruct_00267800_tbl * field_0;
    unsigned char pad_4[0xC];
};

class CB3TrafficValve {
public:
    UnkStruct_00267800_ent * GetRandomVehicleID(ETrafficVehicleCategories);
    void UpdateGeneration(int, int, unsigned short, float);

    UnkStruct_00267800_spd * field_0[4];
    float * field_10[4];
    UnkStruct_00267800_arr * field_20[4];
    unsigned char pad_30[0x10];
    UnkStruct_00267800_ctl * field_40;
    UnkStruct_00267800_ring field_44[4];
    unsigned char pad_94[0x8];
    float field_9C[28];
    unsigned char field_10C[4];
    unsigned char field_110[4];
    unsigned char field_114;
};

extern UnkStruct_D_0055D788 D_0055D788;
extern UnkStruct_D_00522660 D_00522660;
extern CB3TrafficSystem D_00527440;

static inline UnkStruct_00267800_lane * func_00267800_lane(int idx)
{
    if (idx == 255) {
        return 0;
    }
    return (UnkStruct_00267800_lane *)((char *)&D_00522660.field_0[idx] + 0x22C);
}

void CB3TrafficValve::UpdateGeneration(int i, int p1, unsigned short p2, float t)
{
    unsigned long spC0 = 0;
    unsigned char spB0 = 0;
    unsigned char lo;
    unsigned char hi;
    if (field_40->field_C & 2) {
        lo = 6;
        hi = 7;
    } else {
        lo = 0;
        hi = 6;
    }
    float zero = 0.0f;
    for (unsigned char k = lo; k < hi; k++) {
        if (!(field_10[i][k] <= zero)) {
            float * ent = (float *)((char *)this + i * 28 + k * 4 + 0x9C);
            if (*ent < t) {
                UnkStruct_00267800_rb * rg = (UnkStruct_00267800_rb *)((char *)this + i * 20);
                if (rg->field_48 < 2) {
                    int w = rg->field_54;
                    rg->field_54 = w + 1;
                    rg->field_44[w] = k;
                    rg->field_48 = rg->field_48 + 1;
                    if (!(rg->field_54 < rg->field_4C)) {
                        rg->field_54 = 0;
                    }
                    unsigned int r = D_0055D788.r.Random();
                    float q = ((float)r * 2.3283064e-10f - 0.5f) * 2.0f;
                    float inv = 60.0f / field_10[i][k];
                    *ent = zero + (t + inv) + q * (0.3f * inv);
                }
            }
        }
    }
    unsigned int s2 = (unsigned short)(p2 + field_40->field_4[i]);
    UnkStruct_00267800_lane * lane = func_00267800_lane(field_40->field_0[i]);
    bool ok;
    unsigned short a3 = s2;
    if (a3 < lane->field_0->field_10) {
        if (a3 == 0 && field_114 != 0) {
            ok = true;
        } else {
            ok = !D_00527440.IsSegmentLocked(p1, (unsigned short)(a3 + lane->field_4));
        }
    } else {
        ok = false;
    }
    UnkStruct_00267800_rb * rg;
    if (ok && (rg = (UnkStruct_00267800_rb *)((char *)this + i * 20), rg->field_48 > 0)) {
        rg->field_48 = rg->field_48 - 1;
        unsigned char * src = rg->field_44 + rg->field_50;
        int nr = rg->field_50 + 1;
        if (!(nr < rg->field_4C)) {
            nr = 0;
        }
        rg->field_50 = nr;
        unsigned char c1 = *src;
        unsigned long s5;
        unsigned char fp = 0;
        unsigned char s6;
        if (field_40->field_C & 2) {
            unsigned char fl = field_40->field_D;
            UnkStruct_00267800_tbl * tb = D_00527440.field_0;
            if (fl & 1) {
                s5 = tb->field_0[0];
            } else if (fl & 2) {
                s5 = tb->field_0[1];
            } else if (fl & 4) {
                s5 = tb->field_0[2];
            } else if (fl & 8) {
                s5 = tb->field_0[3];
            } else if (fl & 0x10) {
                s5 = tb->field_0[4];
            } else {
                s5 = 0;
            }
            if (fl & 1) {
                c1 = 6;
            } else if (fl & 2) {
                c1 = 7;
            } else if (fl & 4) {
                c1 = 8;
            } else if (fl & 8) {
                c1 = 9;
            } else if (fl & 0x10) {
                c1 = 10;
            } else {
                c1 = 0;
            }
        } else {
            UnkStruct_00267800_ent * e = GetRandomVehicleID((ETrafficVehicleCategories)c1);
            s5 = e->field_0;
            unsigned int rr = D_0055D788.r.Random();
            int sum = 0;
            unsigned char kk = 0;
            while (kk < 8) {
                sum += e->field_8[kk];
                if (!(sum < (int)(rr % 100))) {
                    break;
                }
                kk = kk + 1;
            }
            fp = kk;
        }
        if (c1 != 4) {
            s6 = 0;
        } else {
            s6 = 11;
            UnkStruct_00267800_ent * e2 = GetRandomVehicleID((ETrafficVehicleCategories)11);
            spC0 = e2->field_0;
            unsigned int rr = D_0055D788.r.Random();
            int sum = 0;
            unsigned char kk = 0;
            while (kk < 8) {
                sum += e2->field_8[kk];
                if (!(sum < (int)(rr % 100))) {
                    break;
                }
                kk = kk + 1;
            }
            spB0 = kk;
        }
        float fs = (float)s2;
        UnkStruct_00267800_veh * v = D_00527440.Generate((ETrafficVehicleCategories)c1, s5, (ETrafficVehicleCategories)s6, spC0, (CB3TrafficLane *)func_00267800_lane(field_40->field_0[i]), fs, field_0[i]->field_0, field_10[i][c1], fp, spB0, 0);
        if (v != 0 && !(v->field_174 & 4)) {
            UnkStruct_00267800_veh2 * o = v->field_114;
            if (field_20[i]->field_10 > 0) {
                o->field_47 = field_10C[i];
                field_10C[i] = field_10C[i] + 1;
                field_10C[i] = field_10C[i] % field_20[i]->field_10;
                if (field_20[i] == 0) {
                    o->field_47 = 0xFF;
                }
                v->field_114->field_38 = field_20[i];
            } else {
                o->field_47 = 0xFF;
                v->field_114->field_38 = 0;
            }
        }
    }
}
