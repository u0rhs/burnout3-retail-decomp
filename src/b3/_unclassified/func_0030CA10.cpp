// Hand-written; the lifter refused it (random car pick; split result/count vars; per-loop j/c decl order).

#include "b3/_unclassified/GtRandom.h"
struct UnkStruct_D_0051BF9C { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_00518680 { CGtRandom r; unsigned char pad[0x100]; };
extern UnkStruct_D_0051BF9C D_0051BF9C;
extern UnkStruct_D_00518680 D_00518680;
struct UnkStruct_0030CA10_self { unsigned char pad_0[0x80]; unsigned long field_80[3]; unsigned char pad_98[0x80]; unsigned long *field_118[4]; };
struct UnkStruct_0030CA10_ent { unsigned long a; unsigned long b; unsigned char pad[0x88]; };
extern "C" void func_0021ADF0(unsigned long id, char *out);
extern "C" unsigned long GtIDCompress__FPCc(const char *s);
extern "C" int func_00127520(const char *, const char *, int);
extern "C" int GetRaceVehicleSeries__23CB3HardCodedVehicleListFi(int);
extern "C" unsigned long GetRaceVehicleGtID__23CB3HardCodedVehicleListFi(int);
extern "C" unsigned char IsCarUnlocked__10CB3ProfileFUl(void *, unsigned long);

// 0x0030CA10
extern "C" unsigned long func_0030CA10(UnkStruct_0030CA10_self *self, UnkStruct_0030CA10_ent *list, int n, int pl)
{
    unsigned long id1 = *self->field_118[pl];
    unsigned long s1 = 0;
    int cnt;
    int prof = D_0051BF9C.field_0;
    unsigned long a;
    unsigned long b;
    char key[16];
    char cur[16];
    unsigned long pick[20];
    struct { char a[4]; char b[4]; char pad[0x18]; } nmb;
    unsigned long cand[68];
    unsigned long cand2[68];
    if (list) {
        a = list[n].a;
        b = list[n].b;
        if (a == 0) { a = id1; b = 0; }
    } else {
        a = id1;
        b = 0;
    }
    if (b) {
        func_0021ADF0(a, nmb.a);
        func_0021ADF0(b, nmb.b);
        s1 = GtIDCompress__FPCc(nmb.a);
    }
    if (b == 0) {
        func_0021ADF0(a, key);
        cnt = 0;
        int i;
        for (i = 0; i < 0x43; i++) {
            unsigned long id = GetRaceVehicleGtID__23CB3HardCodedVehicleListFi(i);
            if (IsCarUnlocked__10CB3ProfileFUl((void *)(prof), id)) {
                func_0021ADF0(id, cur);
                if (func_00127520(cur, key, 4) == 0) {
                    int j;
                    int c = 3;
                    for (j = 0; j < n; j++) if (self->field_80[j] == id) c--;
                    if (c > 0) {
                        pick[cnt++] = id;
                        if (cnt >= 0x14) break;
                    }
                }
            }
        }
        if (cnt == 0) {
            for (i = 0; i < 0x43; i++) {
                unsigned long id = GetRaceVehicleGtID__23CB3HardCodedVehicleListFi(i);
                func_0021ADF0(id, cur);
                if (func_00127520(cur, key, 4) == 0) {
                    int c = 3;
                    for (int j = 0; j < n; j++) if (self->field_80[j] == id) c--;
                    if (c > 0) {
                        pick[cnt++] = id;
                        if (cnt >= 0x14) break;
                    }
                }
            }
        }
        s1 = pick[D_00518680.r.Random() % cnt];
    }
    if (s1 == 0) {
        int k = 0;
        for (int i = 0; i < 0x43; i++) {
            int sr = GetRaceVehicleSeries__23CB3HardCodedVehicleListFi(i);
            if (sr != 5 && sr != 6 && IsCarUnlocked__10CB3ProfileFUl((void *)(prof), GetRaceVehicleGtID__23CB3HardCodedVehicleListFi(i)))
                cand[k++] = GetRaceVehicleGtID__23CB3HardCodedVehicleListFi(i);
        }
        if (k > 0) s1 = cand[D_00518680.r.Random() % k];
    }
    if (s1 == 0) {
        int k = 0;
        for (int i = 0; i < 0x43; i++) {
            int sr = GetRaceVehicleSeries__23CB3HardCodedVehicleListFi(i);
            if (sr != 5 && sr != 6)
                cand2[k++] = GetRaceVehicleGtID__23CB3HardCodedVehicleListFi(i);
        }
        if (k > 0) s1 = cand2[D_00518680.r.Random() % k];
    }
    return s1;
}
