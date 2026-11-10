// Hand-written; the lifter refused it (else-if on random&0xF; x=(a<<16)+(a>>16); x+=field_4).

struct UnkStruct_003F8580_rnd { int field_0; int field_4; };
extern "C" UnkStruct_003F8580_rnd _mRandom__13CGtSoundUtils;
extern int D_004E2918;
extern int D_004E1EC8;
extern int D_004E1ECC;
extern int D_004E1ED0;
extern int D_004E1ED8;
extern int D_004A55D0[];
extern char D_004CE958[];
struct UnkStruct_D_0064D370_x { unsigned long field_0; unsigned char pad_8[8]; };
extern UnkStruct_D_0064D370_x D_0064D370;
extern "C" int sprintf(char *, const char *, ...);
extern "C" void func_003F88E0(void *, char *);
extern "C" void func_003F8AA0(void *, unsigned long, char *, int *, int *, int, int);
// 0x003F8580
extern "C" void func_003F8580(void *p0_, char *p1, int *p2, int *p3)
{
    int p0 = (int)p0_;
    int a = _mRandom__13CGtSoundUtils.field_0;
    int x = (a << 16) + (a >> 16);
    x += _mRandom__13CGtSoundUtils.field_4;
    _mRandom__13CGtSoundUtils.field_4 += x;
    _mRandom__13CGtSoundUtils.field_0 = x;
    int r = x & 0xF;
    if (r == 0) {
        *p2 = 0;
        *p3 = 0;
        sprintf(p1, D_004CE958, D_004E1EC8, D_004A55D0[D_004E2918], D_004E1ECC, D_004E1ED8);
    } else if (r == 7) {
        *p2 = 0;
        *p3 = 0;
        sprintf(p1, D_004CE958, D_004E1EC8, D_004A55D0[D_004E2918], D_004E1ED0, D_004E1ED8);
    } else if (r == 15) {
        func_003F88E0(p0_, p1);
        *p2 = 0;
        *p3 = 0;
    } else {
        func_003F8AA0((void *)(p0), D_0064D370.field_0, p1, p2, p3, 0, 0);
    }
}
