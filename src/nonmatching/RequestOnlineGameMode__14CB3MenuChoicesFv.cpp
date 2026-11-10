// NONMATCHING: RequestOnlineGameMode__14CB3MenuChoicesFv -- retail 169 / ours 169 instructions, 2 in changed runs
// a124: 169/169 instrs, 2 in changed runs (one load moved 3 slots): in switch case 4 retail loads D_01E901F0 after 'ld a0,0xE8' and before 'sd a0,0(s0)', ours loads it one slot earlier. All 720 statement orders of case 4 and temp variants tried; const D_01E901F0 needed for cases 3/2 hoist. Also carries a 54-virtual vptr placeholder class (vfunc_8..vfunc_D4) for r->field_1B4->vfunc_D4()
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

struct UnkStruct_0030BB70_g { unsigned char pad_0[0x10]; };
class CB3TrackList {
public:
    int GetTrackIndexFromID(unsigned long);
    void CreateTrackPathFromIndex(int, char*, int);

    unsigned char pad_0[0x10];
};

struct UnkStruct_0030BB70_obj {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual void vfunc_20();
    virtual void vfunc_24();
    virtual void vfunc_28();
    virtual void vfunc_2C();
    virtual void vfunc_30();
    virtual void vfunc_34();
    virtual void vfunc_38();
    virtual void vfunc_3C();
    virtual void vfunc_40();
    virtual void vfunc_44();
    virtual void vfunc_48();
    virtual void vfunc_4C();
    virtual void vfunc_50();
    virtual void vfunc_54();
    virtual void vfunc_58();
    virtual void vfunc_5C();
    virtual void vfunc_60();
    virtual void vfunc_64();
    virtual void vfunc_68();
    virtual void vfunc_6C();
    virtual void vfunc_70();
    virtual void vfunc_74();
    virtual void vfunc_78();
    virtual void vfunc_7C();
    virtual void vfunc_80();
    virtual void vfunc_84();
    virtual void vfunc_88();
    virtual void vfunc_8C();
    virtual void vfunc_90();
    virtual void vfunc_94();
    virtual void vfunc_98();
    virtual void vfunc_9C();
    virtual void vfunc_A0();
    virtual void vfunc_A4();
    virtual void vfunc_A8();
    virtual void vfunc_AC();
    virtual void vfunc_B0();
    virtual void vfunc_B4();
    virtual void vfunc_B8();
    virtual void vfunc_BC();
    virtual void vfunc_C0();
    virtual void vfunc_C4();
    virtual void vfunc_C8();
    virtual void vfunc_CC();
    virtual void vfunc_D0();
    virtual void vfunc_D4();
};

struct UnkStruct_0030BB70_req {
    unsigned long field_0;
    unsigned long field_8;
    unsigned long field_10;
    unsigned long field_18[10];
    unsigned long field_68;
    int field_70;
    int field_74;
    int field_78[10];
    int field_A0;
    int field_A4;
    int field_A8;
    char field_AC[0x100];
    unsigned char field_1AC;
    unsigned char pad_1AD[0x7];
    UnkStruct_0030BB70_obj * field_1B4;
    void * field_1B8;
};

struct UnkStruct_D_0051AEC0 {
    unsigned char pad_0[0x1B8];
    void * field_1B8;
};

struct UnkStruct_kacGameDataFileName {
    int field_0;
};


class CB3MenuChoices {
public:
    UnkStruct_0030BB70_req * RequestOnlineGameMode();

    unsigned char pad_0[0x10];
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    unsigned char pad_20[0x4];
    int field_24;
    unsigned char pad_28[0x58];
    unsigned long field_80[8];
    int field_C0[10];
    unsigned long field_E8;
    unsigned char pad_F0[0x81];
    signed char field_171;
    unsigned char pad_172[5];
    unsigned char field_177;
};

extern UnkStruct_kacGameDataFileName kacGameDataFileName;
extern CB3TrackList D_005196A0;
extern "C" void * memset(void *, int, unsigned int);
extern "C" char * strcat(char *, const char *);
extern "C" unsigned long GtIDCompress__FPCc(const char *);
extern const unsigned long D_01E901F0;
extern UnkStruct_0030BB70_g D_0051B088, D_0051B920, D_0051B62C, D_0051B690, D_0051B7FC, D_0051B788, D_0051B714;
extern char D_0049BAC0[];
UnkStruct_0030BB70_req * CB3MenuChoices::RequestOnlineGameMode()
{
    UnkStruct_0030BB70_req * const r = (UnkStruct_0030BB70_req *)&D_0051B088;
    int i;
    memset(r, 0, 432);
    r->field_1B8 = &D_0051B920;
    field_14 = 1;
    r->field_A0 = field_14;
    r->field_A4 = 0;
    r->field_8 = field_80[0];
    r->field_70 = field_C0[0];
    if (field_10 != 4) {
        for (i = 1; i < field_1C; i++) {
            r->field_18[i + 4] = field_80[i];
            r->field_78[i + 4] = field_C0[i];
        }
    }
    if (field_171 != 0) {
        r->field_1AC = 1;
    } else {
        r->field_1AC = 0;
    }
    switch (field_10) {
    case 0:
        r->field_1B4 = (UnkStruct_0030BB70_obj *)&D_0051B62C;
        r->field_A8 = field_1C - 1;
        r->field_0 = field_E8;
        r->field_68 = GtIDCompress__FPCc(D_0049BAC0);
        break;
    case 1:
        r->field_1B4 = (UnkStruct_0030BB70_obj *)&D_0051B690;
        r->field_A8 = field_1C - 1;
        r->field_0 = field_E8;
        r->field_68 = GtIDCompress__FPCc(D_0049BAC0);
        break;
    case 4:
        r->field_1B4 = (UnkStruct_0030BB70_obj *)&D_0051B7FC;
        field_24 = field_1C;
        r->field_A8 = 0;
        r->field_0 = field_E8;
        r->field_1AC = 1;
        r->field_68 = D_01E901F0;
        break;
    case 3:
        r->field_1B4 = (UnkStruct_0030BB70_obj *)&D_0051B788;
        r->field_A8 = field_1C - 1;
        r->field_0 = field_E8;
        r->field_1AC = 1;
        r->field_68 = D_01E901F0;
        break;
    case 2:
        r->field_1B4 = (UnkStruct_0030BB70_obj *)&D_0051B714;
        r->field_A8 = field_1C - 1;
        r->field_0 = field_E8;
        r->field_1AC = 1;
        r->field_68 = D_01E901F0;
        break;
    default:
        break;
    }
    if (field_177 != 0) {
        field_177 = 0;
        r->field_1B4->vfunc_D4();
    }
    D_005196A0.CreateTrackPathFromIndex(D_005196A0.GetTrackIndexFromID(r->field_0), r->field_AC, 256);
    strcat(r->field_AC, (const char *)kacGameDataFileName.field_0);
    return r;
}
