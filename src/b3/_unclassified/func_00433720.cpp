// Hand-written; the lifter refused it (a157: [L] DNAT UpdateScroll; goto layout (small/rest after switch), if(s5==0){} wrapper with goto done fall-off, (x<2)^1 arg).

// [L] DNAT: CB3MultiplayerGameOptionsPage::UpdateScroll() (research/proto/new_names.csv)
#include "b3/_unclassified/GtRandom.h"

class CB3Profile {
public:
    unsigned char IsTrackUnlocked(unsigned long);
    unsigned char pad_0[0x1];
};
class CB3TrackList {
public:
    int GetTrackRegion(unsigned long);
    bool IsTrackMarathon(unsigned long);
    bool IsTrackPointToPoint(unsigned long);
    unsigned char pad_0[0x4];
    int field_4;
    unsigned char pad_8[0x400];
    unsigned long field_408[1];
};
class CB3InputManager {
public:
    int GetMenuLeft(signed char);
    int GetMenuRight(signed char);
    unsigned char pad_0[0x10];
};
struct UnkStruct_D_0051BF9C {
    CB3Profile * field_0;
    unsigned char pad_4[0xC];
};
struct UnkStruct_D_004EE040 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E8961C { unsigned char pad_0[0x10]; };
struct UnkStruct_D_005196A4 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_00433720 {
    unsigned char pad_0[0x20];
    int field_20;
    unsigned short field_24;
    unsigned char pad_26[0xA2];
    unsigned short field_C8;
    unsigned short field_CA;
    int field_CC[8];
    int field_EC;
    unsigned long field_F0[1];
    unsigned char pad_F8[0x98];
    int field_190[1];
    unsigned char pad_194[0x4C];
    int field_1E0;
    unsigned char pad_1E4[0x4CC];
    int field_6B0;
    int field_6B4;
    int field_6B8;
    int field_6BC;
    int field_6C0;
};
extern UnkStruct_D_0051BF9C D_0051BF9C;
extern UnkStruct_D_005196A4 D_005196A4;
extern UnkStruct_D_004EE040 D_004EE040;
extern UnkStruct_D_01E8961C D_01E8961C;
extern CB3InputManager D_004F50C0;
extern CB3TrackList D_005196A0;
extern int D_004D1A20[];
extern int D_004D1A30[];
extern int D_004D1A38[];
extern "C" void SetOptionText__26CB3VOptionsSelectComponentFiUi(void *, int, int);
extern "C" void func_003BC360(void *, int, int);
extern "C" unsigned long func_00433370(UnkStruct_00433720 *, int);
extern "C" unsigned long func_00433560(UnkStruct_00433720 *);
extern "C" int FindTrack__21CB3HardCodedTrackListFUl(unsigned long);
extern "C" int GetTrackString__21CB3HardCodedTrackListFib(int, bool);

// 0x00433720
extern "C" void func_00433720(UnkStruct_00433720 * self)
{
    int s5;
    int *s4;
    int s3;
    int s2;
    int s1;
    int i;
    CB3Profile * profile;
    int region;
    unsigned long id;
    int mode = self->field_20;
    switch (mode) {
    default:
        s5 = D_004D1A20[self->field_24];
        break;
    case 1:
        s5 = D_004D1A30[self->field_24];
        break;
    case 2:
    case 3:
        s5 = D_004D1A38[self->field_24];
        break;
    }
    switch (s5) {
    default:
        s2 = self->field_EC;
        s4 = &self->field_6B4;
        s3 = 0;
        break;
    case 1:
        s2 = self->field_1E0;
        s4 = &self->field_6B8;
        s3 = 0;
        break;
    case 3:
        s3 = self->field_C8;
        s4 = &self->field_6C0;
        s2 = self->field_CA + 1;
        break;
    case 2:
        s2 = self->field_6B0;
        s4 = &self->field_6BC;
        s3 = 0;
        break;
    }
    s1 = *s4;
    if (D_004F50C0.GetMenuLeft(0) != 0) {
        *s4 = *s4 - 1;
        if (*s4 < s3) *s4 = s2 - 1;
    } else if (D_004F50C0.GetMenuRight(0) != 0) {
        *s4 = *s4 + 1;
        if (*s4 >= s2) *s4 = s3;
    }
    if (*s4 == s1) return;
    SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, self->field_24, *s4);
    if (s5 == 0) {
    if (self->field_6B4 == 0) goto small;
    profile = D_0051BF9C.field_0;
    region = self->field_CC[self->field_6B4];
    self->field_F0[0] = func_00433370(self, region);
    self->field_1E0 = 1;
    i = 0;
    goto test;
body:
    id = *(unsigned long *)((char *)&D_004EE040 + i * 8 + 0x2BA68);
    if (!D_005196A0.IsTrackMarathon(id)) goto rest;
next:
    i++;
test:
    if (i < D_005196A4.field_0) goto body;
join:
    self->field_6B8 = 0;
    switch (self->field_20) {
    case 0:
    case 1:
        func_003BC360(&D_01E8961C, 1, (self->field_1E0 < 2) ^ 1);
        SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 1, self->field_6B8);
        break;
    }
    goto done;
small:
    self->field_F0[0] = func_00433560(self);
    self->field_1E0 = 1;
    goto join;
rest:
    if (D_005196A0.IsTrackPointToPoint(id)) goto next;
    if (!profile->IsTrackUnlocked(id)) goto next;
    if (region != D_005196A0.GetTrackRegion(id)) goto next;
    self->field_F0[self->field_1E0] = id;
    self->field_190[self->field_1E0] = GetTrackString__21CB3HardCodedTrackListFib(FindTrack__21CB3HardCodedTrackListFUl(id), false);
    self->field_1E0 = self->field_1E0 + 1;
    goto next;
    }
done:
    ;
}
