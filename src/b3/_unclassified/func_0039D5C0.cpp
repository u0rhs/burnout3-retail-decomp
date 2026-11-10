// Hand-written; the lifter refused it (a152: SetupTrackOptions [L]; x==0||x==1 (not <2) keeps else out of line; getter inline taking idx param).

// [L] DNAT: CB3OnlineGameOptionsPage::SetupTrackOptions(unsigned long) (research/proto/new_names.csv)
class CB3Profile {
public:
    unsigned char IsTrackUnlocked(unsigned long);
    unsigned char pad_0[0x1];
};
class CB3TrackList {
public:
    int GetTrackRegion(unsigned long);
    unsigned char IsTrackPointToPoint(unsigned long);
    unsigned char pad_0[0x4];
    int field_4;
    unsigned char pad_8[0x400];
};
struct UnkStruct_D_0051BF9C {
    CB3Profile * field_0;
    unsigned char pad_4[0xC];
};
struct UnkStruct_D_004EE040 { unsigned char pad_0[0x10]; };
struct UnkStruct_P { unsigned char pad_0[0x10]; };
struct UnkStruct_0039D5C0 {
    unsigned char pad_0[0x14];
    unsigned char field_14;
    unsigned char pad_15[3];
    unsigned char * field_18;
    unsigned char pad_1C[0x14];
    void * field_30;
    int field_34;
    void * field_38;
    unsigned char field_3C;
    unsigned char field_3D;
    unsigned char field_3E;
    unsigned char pad_3F[0x1];
    int field_40;
    unsigned char pad_44[0xB8];
    int field_FC[4];
    unsigned char pad_10C[0x14];
    unsigned long field_120[20];
    void * field_1C0[20];
    int field_210;
    unsigned char pad_214[0x4];
    unsigned long field_218[1];
    unsigned char pad_220[0x4C0];
    int field_6E0;
    unsigned int field_6E4;
    int field_6E8;
    int field_6EC;
    int field_6F0;
};
extern UnkStruct_D_0051BF9C D_0051BF9C;
extern CB3TrackList D_005196A0;
extern UnkStruct_D_004EE040 D_004EE040;
extern UnkStruct_P D_01E8961C, D_0051BA44;
extern "C" void SetOptionText__26CB3VOptionsSelectComponentFiUi(void *, int, int);
extern "C" void func_003BC360(void *, int, int);
extern "C" void *func_00271A00(void *, int);
extern "C" void *FindTrack__21CB3HardCodedTrackListFUl(unsigned long);
extern "C" void *GetTrackString__21CB3HardCodedTrackListFib(int, bool);

static inline int func_0039D5C0_inl1(UnkStruct_0039D5C0 * self, int i)
{
    unsigned char *p = self->field_18;
    if (p == 0 || i < 0 || i > self->field_14) return 0;
    return *(unsigned char *)((char *)p + i);
}

// 0x0039D5C0
extern "C" void func_0039D5C0(UnkStruct_0039D5C0 * self, unsigned long region)
{
    unsigned long id;
    int s3;
    int i;
    CB3Profile * profile = D_0051BF9C.field_0;
    if (self->field_6E4 == 0 || self->field_6E4 == 1) {
        for (i = 0; i < 4; i++) {
            s3 = self->field_FC[i];
            if (s3 == D_005196A0.GetTrackRegion(region)) {
                SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 1, i);
                self->field_6E8 = i;
                break;
            }
        }
        s3 = self->field_FC[self->field_6E8];
        self->field_210 = 1;
        for (i = 0; i < D_005196A0.field_4; i++) {
            id = *(unsigned long *)((char *)&D_004EE040 + i * 8 + 0x2BA68);
            if (profile->IsTrackUnlocked(id)) {
                if (s3 == D_005196A0.GetTrackRegion(id)) {
                    self->field_120[self->field_210] = id;
                    self->field_1C0[self->field_210] = GetTrackString__21CB3HardCodedTrackListFib((int)(FindTrack__21CB3HardCodedTrackListFUl(id)), false);
                    self->field_210 = self->field_210 + 1;
                }
            }
        }
        int b = func_0039D5C0_inl1(self, self->field_6E4);
        unsigned char c = self->field_210;
        self->field_30 = func_00271A00(&D_0051BA44, 719);
        self->field_38 = &self->field_1C0[0];
        self->field_3C = c;
        self->field_3D = 4;
        self->field_3E = b;
        self->field_40 = 0;
        self->field_34 = 0;
        func_003BC360(&D_01E8961C, 2, 1);
        int n = self->field_210;
        for (i = 1; i < n; i++) {
            if (self->field_120[i] == region) {
                SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 2, i);
                self->field_6EC = i;
                break;
            }
        }
        if (D_005196A0.IsTrackPointToPoint(region)) {
            SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 3, 1);
            func_003BC360(&D_01E8961C, 3, func_0039D5C0_inl1(self, self->field_6E4));
        } else {
            SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 3, self->field_6F0);
            func_003BC360(&D_01E8961C, 3, 1);
        }
    } else {
        int n = self->field_6E0;
        for (i = 1; i < n; i++) {
            if (self->field_218[i] == region) {
                SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, 1, i);
                self->field_6EC = i;
                break;
            }
        }
    }
}
