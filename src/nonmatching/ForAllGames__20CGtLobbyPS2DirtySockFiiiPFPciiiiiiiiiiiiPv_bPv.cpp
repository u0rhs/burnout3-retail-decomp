// NONMATCHING: ForAllGames__20CGtLobbyPS2DirtySockFiiiPFPciiiiiiiiiiiiPv_bPv -- retail 137 / ours 137 instructions, 20 in changed runs
// s313: sreg L-lever (locals declared at function top, assigned in place) 24 -> 20; s-register rotation only (8 saved values: this/i/cb/g; retail g shares p1's s3). Parameter-advance / end-local loop forms no better.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

typedef int (*GameCB)(char *, int, int, int, int, int, int, int, int, int, int, int, int, int, void *);
struct UnkStruct_Row { char name[0x64]; };
struct UnkStruct_Game {
    int field_0;
    char field_4[0x44];
    int field_48;
    unsigned char pad_4C[0x40];
    char field_8C[0x88];
    unsigned int field_114;
    unsigned char pad_118[0x4];
    int field_11C;
    unsigned char pad_120[0x9C];
    int field_1BC;
    unsigned char pad_1C0[4];
    UnkStruct_Row field_1C4[1];
};
class CGtLobbyPS2DirtySock {
public:
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
    virtual int vfunc_AC();
    int ForAllGames(int p0, int p1, int p2, bool (*p3)(char *, int, int, int, int, int, int, int, int, int, int, int, int, void *), void *p4);
    int ForAllGamesFound(bool (*p0)(char *, int, int, int, int, int, int, int, int, int, int, int, int, void *), void *p1);
    unsigned char pad_4[0x4A0];
    char field_4A4[0x40];
    unsigned char pad_4E4[0x80];
    int field_564;
    int field_568;
};
extern "C" int strcasecmp(const char *, const char *);
extern "C" int DispListCount(int);
extern "C" void DispListOrder(int);
extern "C" UnkStruct_Game *DispListIndex(int, int);
extern "C" char *strcpy(char *, const char *);
extern "C" int strlen(const char *);
extern "C" int atoi(const char *);
extern "C" void *memset(void *, int, unsigned);
extern "C" void func_00128BE8(char *, void *);
struct UnkStruct_D_004C5990 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_004C5990 D_004C5990;

// 0x00339830
int CGtLobbyPS2DirtySock::ForAllGames(int p0, int p1, int p2, bool (*p3)(char *, int, int, int, int, int, int, int, int, int, int, int, int, void *), void *p4)
{
    int fl;
    char *s;
    bool found;
    UnkStruct_Game *g;
    DispListOrder(field_564);
    for (int i = p0; i < p0 + p1; i++) {
        g = DispListIndex(field_564, i);
        if (g == 0)
            continue;
        found = false;
        for (int k = 0; k < g->field_1BC && !found; k++) {
            if (strcasecmp(g->field_1C4[k].name, field_4A4) == 0)
                found = true;
        }
        if (found)
            continue;
        int vals[9];
        char buf[0x90];
        memset(vals, 0, 0x24);
        s = g->field_8C;
        for (int j = 0; j < 9; j++) {
            strcpy(buf, s);
            func_00128BE8(buf, &D_004C5990);
            vals[j] = atoi(buf);
            s += strlen(buf) + 1;
        }
        fl = 0;
        if (g->field_114 & 0x80000) fl |= 1;
        if (g->field_114 & 0x10000) fl |= 2;
        if (g->field_114 & 0x1000) fl |= 4;
        if (((GameCB)p3)(g->field_4, g->field_0, vals[0], vals[1], vals[2], g->field_1BC, g->field_11C, g->field_48, vals[3], vals[4], vals[5], vals[6], vals[7], fl, p4) == 0)
            return 2;
    }
    vfunc_14();
}

