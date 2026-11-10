// NONMATCHING: func_0042CFA0 -- retail 194 / ours 194 instructions, 6 in changed runs
// psweep: scoped #pragma opt_propagation off [G] improves 12 -> 6
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// [G] N182: scoped optimiser pragma found by the pragma sweep (psweep_all.py)
#pragma push
#pragma opt_propagation off
struct UnkStruct_D_0051BF9C { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_0051BF9C D_0051BF9C;
struct UnkStruct_D_005186A0 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_005186A0 D_005186A0;
struct UnkStruct_0042CFA0_self { unsigned char pad_0[0x240]; int field_240; int field_244; unsigned char pad_248[8]; int field_250; int field_254; int field_258; int field_25C; int field_260; unsigned char field_264; unsigned char field_265; };
extern "C" unsigned long GetCarID__14CB3VehicleListF17EB3MenuCarClassesi(void *, int, int);
extern "C" unsigned char IsVehicleDriveable__14CB3VehicleListFUl(void *, unsigned long);
extern "C" int GetCarCount__14CB3VehicleListF17EB3MenuCarClasses(void *, int);
extern "C" int GetClassFromID__14CB3VehicleListFUl(unsigned long);
extern "C" int IsCarUnlocked__10CB3ProfileFUl(void *, unsigned long);
static inline bool func_0042CFA0_inl1(int prof, unsigned long id)
{
    if (IsVehicleDriveable__14CB3VehicleListFUl(&D_005186A0, id)) {
        if (IsCarUnlocked__10CB3ProfileFUl((void *)(prof), id)) return true;
    }
    return false;
}
extern "C" int func_0042D2B0(void *, int, int, int, int);

// 0x0042CFA0
extern "C" void func_0042CFA0(UnkStruct_0042CFA0_self *self, int p1, int p2, int p3, int p4, unsigned char a5, unsigned char a6, int a7)
{
    if (!a6) {
        if (p1 == 9 && (unsigned)(p3 - 5) < 2) {
            p3 = 0;
            p4 = 0;
        }
        if (p4 == 9) p4 = 0;
    } else if (!a5) {
        if (p1 == 9 && p3 == 6) {
            p3 = 0;
            p4 = 0;
        }
    }
    if (p2 == -1) goto search;
    p4 = 0;
store:
    self->field_25C = p1;
    self->field_260 = p2;
    self->field_258 = p3;
    self->field_254 = *(const int *)&self->field_258;
    self->field_244 = p4;
    self->field_240 = p4;
    self->field_264 = a5;
    self->field_265 = a6;
    self->field_250 = a7;
    func_0042D2B0(self, 0, 4, p4, 0);
    return;
search:
    {
        unsigned long id3;
        unsigned long id = GetCarID__14CB3VehicleListF17EB3MenuCarClassesi(&D_005186A0, p3, p4);
        int prof = D_0051BF9C.field_0;
        bool ok = func_0042CFA0_inl1(prof, id);
        if (!ok) {
            int i;
            for (i = 0; i < GetCarCount__14CB3VehicleListF17EB3MenuCarClasses(&D_005186A0, p3); i++) {
                unsigned long id2 = GetCarID__14CB3VehicleListF17EB3MenuCarClassesi(&D_005186A0, p3, i);
                int prof2 = D_0051BF9C.field_0;
                bool ok2 = func_0042CFA0_inl1(prof2, id2);
                if (ok2) {
                    p4 = i;
                    break;
                }
            }
            if (i == GetCarCount__14CB3VehicleListF17EB3MenuCarClasses(&D_005186A0, p3)) {
                if (p1 == 9) {
                    p3 = 0;
                    p4 = 0;
                } else {
                    p4 = 0;
                }
            }
        }
        int cls;
        unsigned long cur;
        cur = GetCarID__14CB3VehicleListF17EB3MenuCarClassesi(&D_005186A0, p3, p4);
        cls = GetClassFromID__14CB3VehicleListFUl(cur);
        p4 = 0;
        int j;
        for (j = 0; j < GetCarCount__14CB3VehicleListF17EB3MenuCarClasses(&D_005186A0, cls); j++) {
            id3 = GetCarID__14CB3VehicleListF17EB3MenuCarClassesi(&D_005186A0, cls, j);
            if (IsVehicleDriveable__14CB3VehicleListFUl(&D_005186A0, id3)) {
                if (id3 == cur) goto store;
                p4++;
            }
        }
        p4 = -1;
        goto store;
    }
}

#pragma pop
