// CGtLobbyPS2DirtySock::ForAllGamesFound(bool (*)(char*, int, int, int, int, int, int, int, int, int, int, int, int, void*),void* -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtLobbyDirtySock.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a126: callback called via 15-arg cast (13 ints), flags bits).

typedef int (*GameCB)(char *, int, int, int, int, int, int, int, int, int, int, int, int, int, void *);
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
    int ForAllGamesFound(bool (*p0)(char *, int, int, int, int, int, int, int, int, int, int, int, int, void *), void *p1);
    unsigned char pad_4[0x564];
    int field_568;
};
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

// 0x00339480
int CGtLobbyPS2DirtySock::ForAllGamesFound(bool (*p0)(char *, int, int, int, int, int, int, int, int, int, int, int, int, void *), void *p1)
{
    DispListOrder(field_568);
    for (int i = 0; i < DispListCount(field_568); i++) {
        UnkStruct_Game *g = DispListIndex(field_568, i);
        if (g == 0)
            continue;
        int fl = 0;
        if (g->field_114 & 0x80000) fl |= 1;
        if (g->field_114 & 0x10000) fl |= 2;
        if (g->field_114 & 0x1000) fl |= 4;
        int vals[9];
        char buf[0x90];
        memset(vals, 0, 0x24);
        char *s = g->field_8C;
        for (int j = 0; j < 9; j++) {
            strcpy(buf, s);
            func_00128BE8(buf, &D_004C5990);
            vals[j] = atoi(buf);
            s += strlen(buf) + 1;
        }
        if (((GameCB)p0)(g->field_4, g->field_0, vals[0], vals[1], vals[2], g->field_1BC, g->field_11C, g->field_48, vals[3], vals[4], vals[5], vals[6], vals[7], fl, p1) == 0)
            return 2;
    }
    vfunc_14();
}
