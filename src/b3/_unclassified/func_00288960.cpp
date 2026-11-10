// Hand-written; the lifter refused it (fresh4: from scratch; 4-param (a1 unused), switch fallthrough, random-interp inline, padded globals, extern format strings).

// func_00288960 -- hand-written from scratch (the lifter refused it). Unnamed, so a placeholder with C linkage.
// [C] parameters: retail reads a2 (sd, 64-bit id) and a3 (index) and never a1; the proven callers (Prepare of
// CB3SoundESMLow/High) declare (self, unsigned long, int) and pass their own a1-a3 through untouched.
// Layout and types are [G] (instruction widths). [L] sound bank load state machine (LoadBank, "%swd").

#include "b3/_unclassified/GtRandom.h"

class CGtSoundBankManager {
public:
    int LoadBank(const char *, bool, bool, int);
    unsigned char pad_0[0x10];
};
class CB3VehicleList {
public:
    int GetVehicleIndexFromID(unsigned long);
    void CreateVehiclePathFromIndex(int, char *, int);
    unsigned char pad_0[0x10];
};
struct UnkStruct_00288960_c { unsigned char pad_0[0x16DC]; int field_16DC; int field_16E0; };
struct UnkStruct_00288960_e { unsigned char pad_0[0x40]; UnkStruct_00288960_c *field_40; };
struct UnkStruct_00288960 {
    unsigned char pad_0[0x20];
    unsigned long field_20;
    int field_28;
    int field_2C;
    int field_30;
    unsigned char pad_34[4];
    int field_38;
    int field_3C;
    int field_40;
    int field_44;
    float field_48;
    float field_4C;
    float field_50;
    unsigned char field_54;
    unsigned char pad_55;
    unsigned char field_56;
    unsigned char pad_57[2];
    unsigned char field_59;
};
extern UnkStruct_00288960_e *D_0064D388[];
extern CB3VehicleList D_005186A0;
extern CGtSoundBankManager D_01E75648;
extern const char *D_004E1B04;
extern const char *D_004E1B08;
extern float D_004E1B48;
extern float D_004E1B4C;
extern float D_004E1B50;
extern "C" CGtRandom _mRandom__13CGtSoundUtils;
extern char D_004BF498[];  // "%s%s"
extern char D_004BF4A0[];  // "%swd"
extern "C" int sprintf(char *, const char *, ...);

static inline float func_00288960_inl1(float lo, float hi)
{
    const float k = 2.3283064e-10f;
    float t = k * (float)_mRandom__13CGtSoundUtils.Random();
    float d = hi - lo;
    return lo + t * d;
}
extern "C" bool func_00288960(UnkStruct_00288960 *self, int unused, unsigned long id, int idx);

// 0x00288960
bool func_00288960(UnkStruct_00288960 *self, int unused, unsigned long id, int idx)
{
    char path[0x100];
    char name[0x100];
    char dir[0x80];
    switch (self->field_30) {
    case 0:
        if (self->field_56 != 0)
            self->field_2C = D_0064D388[idx]->field_40->field_16DC;
        else
            self->field_2C = D_0064D388[idx]->field_40->field_16E0;
        self->field_30 = 2;
    case 2: {
        unsigned char alt = self->field_56;
        D_005186A0.CreateVehiclePathFromIndex(D_005186A0.GetVehicleIndexFromID(id), dir, 0x80);
        sprintf(path, D_004BF498, dir, alt ? D_004E1B08 : D_004E1B04);
        sprintf(name, D_004BF4A0, path);
        self->field_28 = D_01E75648.LoadBank(name, true, false, 0x800);
        if (self->field_28 == 0)
            break;
        self->field_30 = 3;
    }
    case 3:
        self->field_30 = 4;
    case 4:
    case 5:
        self->field_3C = 0;
        self->field_40 = 0;
        self->field_44 = 0;
        self->field_38 = 0;
        self->field_50 = D_004E1B48;
        self->field_48 = 0.001f + func_00288960_inl1(D_004E1B4C, D_004E1B50);
        self->field_4C = 0.001f + func_00288960_inl1(D_004E1B4C, D_004E1B50);
        self->field_54 = 0;
        self->field_59 = 0;
        break;
    default:
        break;
    }
    self->field_20 = id;
    return self->field_30 == 4 || self->field_30 == 5;
}
