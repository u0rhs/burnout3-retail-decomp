// Hand-written; the lifter refused it (fresh4: from scratch (func_0030CA10 shape); class-check inline with one shared return false; per-loop i2/id2/c2 variables, top declarations in sweep-found order).

// func_0030B6E0 -- hand-written from scratch (the lifter refused it). Unnamed, so a placeholder with C linkage.
// Layout and types are [G] (instruction widths). [L] random pick of an existing vehicle of class p1 (class 5: two
// fixed GtIDs) used at most 3 times among self's entries; unlocked ones first; shape of the proven sibling
// func_0030CA10 (and its caller func_0030B9D0's archive: returns unsigned long, (self, int)).

#include "b3/_unclassified/GtRandom.h"
struct UnkStruct_D_0051BF9C { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_00518680 { CGtRandom r; unsigned char pad[0x100]; };
struct UnkStruct_D_005186A0 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_0051BF9C D_0051BF9C;
extern UnkStruct_D_00518680 D_00518680;
extern UnkStruct_D_005186A0 D_005186A0;
struct UnkStruct_0030B6E0_self {
    unsigned char pad_0[0x18];
    int field_18;
    unsigned char pad_1C[0x14];
    int field_30;
    unsigned char pad_34[0x4C];
    unsigned long field_80[8];
};
extern "C" unsigned long GetRaceVehicleGtID__23CB3HardCodedVehicleListFi(int);
extern "C" bool DoesVehicleExist__14CB3VehicleListFUl(void *, unsigned long);
extern "C" int GetClassFromID__14CB3VehicleListFUl(unsigned long);
extern "C" unsigned char IsCarUnlocked__10CB3ProfileFUl(void *, unsigned long);

// [G] inlined helper (name unknown): is vehicle id of class cls (class 5 = two fixed GtIDs).
static inline bool func_0030B6E0_inl1(unsigned long id, int cls)
{
    if (cls == 5) {
        if (id == 0x790798FBA1192600 || id == 0x790798FBA11A2000) {
            return true;
        }
    } else if (GetClassFromID__14CB3VehicleListFUl(id) == cls) {
        return true;
    }
    return false;
}

// 0x0030B6E0
extern "C" unsigned long func_0030B6E0(UnkStruct_0030B6E0_self *self, int cls)
{
    unsigned long id;
    int i;
    int cnt;
    int i2;
    unsigned long id2;
    int c;
    int c2;
    int j;
    int prof = D_0051BF9C.field_0;
    unsigned long pick[20];
    cnt = 0;
    for (i = 0; i < 0x43; i++) {
        id = GetRaceVehicleGtID__23CB3HardCodedVehicleListFi(i);
        c = 3;
        if (DoesVehicleExist__14CB3VehicleListFUl(&D_005186A0, id) && func_0030B6E0_inl1(id, cls) &&
            IsCarUnlocked__10CB3ProfileFUl((void *)(prof), id)) {
            for (j = 0; j < self->field_18 + self->field_30; j++) if (self->field_80[j] == id) c--;
            if (c > 0) {
                pick[cnt++] = id;
                if (cnt >= 0x14) break;
            }
        }
    }
    if (cnt == 0) {
        for (i2 = 0; i2 < 0x43; i2++) {
            id2 = GetRaceVehicleGtID__23CB3HardCodedVehicleListFi(i2);
            c2 = 3;
            if (DoesVehicleExist__14CB3VehicleListFUl(&D_005186A0, id2) && func_0030B6E0_inl1(id2, cls)) {
                for (j = 0; j < self->field_18 + self->field_30; j++) if (self->field_80[j] == id2) c2--;
                if (c2 > 0) {
                    pick[cnt++] = id2;
                    if (cnt >= 0x14) break;
                }
            }
        }
    }
    return pick[D_00518680.r.Random() % cnt];
}
