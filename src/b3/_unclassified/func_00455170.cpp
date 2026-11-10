// Hand-written; the lifter refused it (switch default-first with per-arm s4=0).

// Hand-written; the lifter refused it (options page left/right input).
class CB3TrackList {
public:
    int GetTrackRegion(unsigned long);
    unsigned char pad_0[0x4];
    int field_4;
    unsigned char pad_8[0x400];
};
class CB3InputManager {
public:
    int GetMenuLeft(signed char);
    int GetMenuRight(signed char);
    unsigned char pad_0[0x10];
};
struct UnkStruct_D_004EE040 { unsigned char pad_0[0x10]; };
struct UnkStruct_P { unsigned char pad_0[0x10]; };
struct UnkStruct_00455170 {
    unsigned char pad_0[0x18];
    unsigned short field_18;
    unsigned char pad_1A[0x3E];
    int field_58[8];
    int field_78;
    unsigned char pad_7C[0x4];
    unsigned long field_80[20];
    void * field_120[20];
    int field_170;
    unsigned char pad_174[0x4CC];
    int field_640;
    int field_644;
    int field_648;
    int field_64C;
};
extern CB3TrackList D_005196A0;
extern CB3InputManager D_004F50C0;
extern UnkStruct_D_004EE040 D_004EE040;
extern UnkStruct_P D_01E8961C, D_01E7A800;
extern "C" void SetOptionText__26CB3VOptionsSelectComponentFiUi(void *, int, int);
extern "C" void func_003BC360(void *, int, int);
extern "C" void FEVerticalMove__18CB3HUDSoundManagerFv(void *, int);
extern "C" void *FindTrack__21CB3HardCodedTrackListFUl(unsigned long);
extern "C" void *GetTrackString__21CB3HardCodedTrackListFib(int, bool);

// 0x00455170
extern "C" void func_00455170(UnkStruct_00455170 * self)
{
    int *p;
    int s4;
    int s3;
    int s2 = self->field_18;
    switch (s2) {
    default:
        s3 = self->field_78;
        p = &self->field_644;
        s4 = 0;
        break;
    case 1:
        s3 = self->field_170;
        p = &self->field_648;
        s4 = 0;
        break;
    case 2:
        s3 = self->field_640;
        p = &self->field_64C;
        s4 = 0;
        break;
    }
    FEVerticalMove__18CB3HUDSoundManagerFv(&D_01E7A800, 1);
    int s1 = *p;
    if (D_004F50C0.GetMenuLeft(0) != 0) {
        *p -= 1;
        if (*p < s4) *p = s3 - 1;
    } else if (D_004F50C0.GetMenuRight(0) != 0) {
        *p += 1;
        if (*p >= s3) *p = s4;
    }
    if (*p == s1) return;
    SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, self->field_18, *p);
    if (s2 != 2 && s2 != 1) {
    int i = 0;
    int reg = self->field_58[self->field_644];
    self->field_170 = 0;
    for (i = 0; i < D_005196A0.field_4; i++) {
        unsigned long id = *(unsigned long *)((char *)&D_004EE040 + i * 8 + 0x2BA68);
        if (reg == D_005196A0.GetTrackRegion(id)) {
            self->field_80[self->field_170] = id;
            self->field_120[self->field_170] = GetTrackString__21CB3HardCodedTrackListFib((int)(FindTrack__21CB3HardCodedTrackListFUl(id)), false);
            self->field_170 = self->field_170 + 1;
        }
    }
    self->field_648 = 0;
    func_003BC360(&D_01E8961C, 1, self->field_170 > 0);
    func_003BC360(&D_01E8961C, 2, self->field_640 > 0);
    SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 1, self->field_648);
    SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 2, self->field_64C);
    }
}
