// NONMATCHING: func_0042B7C0 -- retail 298 / ours 298 instructions, 11 in changed runs
// a156: 298/298 instrs, 11 in changed runs -- one block left. Everything else exact: switch(field_234) 0/1/2 do-while fill loops with unsigned char *p=&e->field_12 reloaded (e->field_13=*p), class-9 / single-class / single-car (field_260 != -1) branches, GetCarID returns unsigned long (id kept, no dsll32), rows as byte-offset casts (char*)self + i*12 with pad_0[0xC] row structs (signed char field_10/11), second table at +0xFC. Left: the single-car block (field_260 != -1): retail keeps the offset s0=s2*12 in a callee-saved reg and recomputes self+s0 three times (before IsCarUnlocked as the delay-slot store, once for the 0x13/0x10/0x11 group, once after GetCarTexture for the +0xC store), ours CSEs one pointer (s1/s0) across both calls; int/unsigned/volatile-free address forms, separate pointer locals, rc struct and int-array index forms did not break the CSE.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// Hand-written (a156): builds the unlockable-item list (two 12-byte-row tables at +0xC / +0xFC), sibling of func_0042B700.
enum EB3MenuCarClasses {};

class CB3VehicleList {
public:
    unsigned long GetCarID(EB3MenuCarClasses, int);
    bool IsVehicleDriveable(unsigned long);
    int GetCarCount(EB3MenuCarClasses);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0042B7C0_row {
    int field_0;
    unsigned char field_4;
    unsigned char field_5;
    unsigned char field_6;
    unsigned char field_7;
    unsigned char pad_8[0x4];
};

struct UnkStruct_0042B7C0_ra {
    unsigned char pad_0[0xC];
    int field_C;
    signed char field_10;
    signed char field_11;
    unsigned char field_12;
    unsigned char field_13;
};
struct UnkStruct_0042B7C0_rc {
    unsigned char pad_0[0xC];
    int field_C;
};
struct UnkStruct_0042B7C0_rb {
    unsigned char pad_0[0xFC];
    int field_FC;
    signed char field_100;
    signed char field_101;
    unsigned char field_102;
    unsigned char field_103;
};

struct UnkStruct_0042B7C0 {
    unsigned char pad_0[0xC];
    int field_C_[1];
    unsigned char pad_C[0x1E0 - 4];
    unsigned char pad_1EC[0x48];
    int field_234;
    unsigned char pad_238[0x10];
    int field_248;
    int field_24C;
    unsigned char pad_250[0x4];
    int field_254;
    int field_258;
    int field_25C;
    int field_260;
    unsigned char pad_264[0x1];
    unsigned char field_265;
};

struct UnkStruct_D_0051BF9C { int field_0; unsigned char pad_4[0xC]; };

extern CB3VehicleList D_005186A0;
extern UnkStruct_D_0051BF9C D_0051BF9C;

extern "C" unsigned char func_0013A7E0(void *, int);
extern "C" unsigned char IsCheatUnlocked__10CB3ProfileFi(void *, int);
extern "C" unsigned char func_0013A820(void *, int);
extern "C" unsigned char IsCarUnlocked__10CB3ProfileFUl(void *, unsigned long);
extern "C" int GetCarTexture__22CB3ImageReward2dObjectF17EB3MenuCarClassesi(int, int);
extern "C" int GetTexture__22CB3ImageReward2dObjectF18EB3RewardImageTypei(int, int);

// 0x0042B7C0
extern "C" void func_0042B7C0(UnkStruct_0042B7C0 * self)
{
    int i;
    int s4;
    int s3 = D_0051BF9C.field_0;
    int s2;
    int s1;
    i = 0;
    do {
        UnkStruct_0042B7C0_ra * a = (UnkStruct_0042B7C0_ra *)((char *)self + i * 12);
        UnkStruct_0042B7C0_rb * b = (UnkStruct_0042B7C0_rb *)((char *)self + i * 12);
        i++;
        a->field_12 = 0;
        a->field_13 = 0;
        b->field_102 = 0;
        b->field_103 = 0;
    } while (i < 20);
    s4 = 0;
    s2 = 0;
    switch (self->field_234) {
    case 0:
        do {
            UnkStruct_0042B7C0_ra * e = (UnkStruct_0042B7C0_ra *)((char *)self + s2 * 12);
            unsigned char * p = &e->field_12;
            *p = func_0013A7E0((void *)(s3), s2);
            s2++;
            e->field_13 = *p;
        } while (s2 < 10);
        break;
    case 1:
        do {
            UnkStruct_0042B7C0_ra * e = (UnkStruct_0042B7C0_ra *)((char *)self + s2 * 12);
            unsigned char * p = &e->field_12;
            *p = IsCheatUnlocked__10CB3ProfileFi((void *)(s3), s2);
            s2++;
            e->field_13 = *p;
        } while (s2 < 10);
        break;
    case 2:
        do {
            UnkStruct_0042B7C0_ra * e = (UnkStruct_0042B7C0_ra *)((char *)self + s2 * 12);
            unsigned char * p = &e->field_12;
            *p = func_0013A820((void *)(s3), s2);
            s2++;
            e->field_13 = *p;
        } while (s2 < 20);
        break;
    }
    if (self->field_234 == 4) {
        if (self->field_25C == 9) {
            for (s1 = 0; s1 < D_005186A0.GetCarCount((EB3MenuCarClasses)self->field_254); s1++) {
                if (self->field_265 == 0 && s1 == 9) continue;
                unsigned long id = D_005186A0.GetCarID((EB3MenuCarClasses)self->field_254, s1);
                if (!D_005186A0.IsVehicleDriveable(id)) continue;
                UnkStruct_0042B7C0_ra * e = (UnkStruct_0042B7C0_ra *)((char *)self + s2 * 12);
                unsigned char * p = &e->field_12;
                *p = IsCarUnlocked__10CB3ProfileFUl((void *)(s3), id);
                e->field_13 = *p;
                e->field_10 = s1;
                e->field_11 = self->field_254;
                e->field_C = GetCarTexture__22CB3ImageReward2dObjectF17EB3MenuCarClassesi(self->field_254, s1);
                s2++;
            }
            for (s1 = 0; s1 < D_005186A0.GetCarCount((EB3MenuCarClasses)self->field_258); s1++) {
                unsigned long id = D_005186A0.GetCarID((EB3MenuCarClasses)self->field_258, s1);
                if (!D_005186A0.IsVehicleDriveable(id)) continue;
                if (self->field_265 == 0 && s1 == 9) continue;
                UnkStruct_0042B7C0_rb * e = (UnkStruct_0042B7C0_rb *)((char *)self + s4 * 12);
                unsigned char * p = &e->field_102;
                *p = IsCarUnlocked__10CB3ProfileFUl((void *)(s3), id);
                e->field_103 = *p;
                e->field_100 = s1;
                e->field_101 = self->field_258;
                e->field_FC = GetCarTexture__22CB3ImageReward2dObjectF17EB3MenuCarClassesi(self->field_258, s1);
                s4++;
            }
            self->field_248 = s2;
        } else if (self->field_260 == -1) {
            for (s1 = 0; s1 < D_005186A0.GetCarCount((EB3MenuCarClasses)self->field_25C); s1++) {
                if (self->field_265 == 0 && s1 == 9) continue;
                unsigned long id = D_005186A0.GetCarID((EB3MenuCarClasses)self->field_25C, s1);
                if (!D_005186A0.IsVehicleDriveable(id)) continue;
                UnkStruct_0042B7C0_ra * e = (UnkStruct_0042B7C0_ra *)((char *)self + s2 * 12);
                unsigned char * p = &e->field_12;
                *p = IsCarUnlocked__10CB3ProfileFUl((void *)(s3), id);
                e->field_13 = *p;
                e->field_10 = s1;
                e->field_11 = self->field_25C;
                e->field_C = GetCarTexture__22CB3ImageReward2dObjectF17EB3MenuCarClassesi(self->field_25C, s1);
                s2++;
            }
            self->field_248 = s2;
        } else {
            unsigned long id = D_005186A0.GetCarID((EB3MenuCarClasses)self->field_25C, self->field_260);
            int off = s2 * 12;
            ((UnkStruct_0042B7C0_ra *)((char *)self + off))->field_12 = 1;
            unsigned char r = IsCarUnlocked__10CB3ProfileFUl((void *)(s3), id);
            UnkStruct_0042B7C0_ra * e1 = (UnkStruct_0042B7C0_ra *)((char *)self + off);
            e1->field_13 = r;
            e1->field_10 = self->field_260;
            e1->field_11 = self->field_25C;
            int t = GetCarTexture__22CB3ImageReward2dObjectF17EB3MenuCarClassesi(self->field_25C, self->field_260);
            self->field_C_[s2 * 3] = t;
            s2++;
            self->field_248 = s2;
        }
        self->field_24C = s4;
    } else {
        self->field_248 = s2;
        self->field_24C = 0;
        for (i = 0; i < self->field_248; i++) {
            UnkStruct_0042B7C0_ra * e = (UnkStruct_0042B7C0_ra *)((char *)self + i * 12);
            e->field_10 = -1;
            e->field_11 = 9;
            e->field_C = GetTexture__22CB3ImageReward2dObjectF18EB3RewardImageTypei(self->field_234, i);
        }
    }
}
