// Hand-written; the lifter refused it (profile stat max-update jump table; pmaxw/pextlw helpers).

struct UnkStruct_Prof {
    unsigned char pad_0[0x154];
    int field_154;
    unsigned char pad_158[0x1EC];
    int field_344;
    int field_348;
    int field_34C;
    int field_350;
    int field_354;
    int field_358;
    int field_35C;
    int field_360;
    unsigned char pad_364[0x4];
    int field_368;
    int field_36C;
    int field_370;
    int field_374;
    int field_378;
    int field_37C;
};
struct UnkStruct_D_0051BF9C { UnkStruct_Prof * field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_0051BF9C D_0051BF9C;
extern "C" int func_0013A630(void *, int);
extern "C" int func_003F5F90(int);
extern "C" int func_003F5F70(int);
extern "C" void Evaluate__10CB3ProfileFv(void *);
extern "C" void func_00139F20(void *);
static inline int a91_pmaxw(int a, int b)
{
    int r;
    asm("pmaxw %0,%1,%2" : "=r"(r) : "r"(a), "r"(b));
    return r;
}
static inline int a91_pextlw(int a)
{
    int r;
    asm("pextlw %0, $0, %1" : "=r"(r) : "r"(a));
    return r;
}
// 0x004248A0
extern "C" void func_004248A0(void * self, int p0)
{
    UnkStruct_Prof * p = D_0051BF9C.field_0;
    if (func_0013A630(p, p0) != 0) {
        return;
    }
    int idx = func_003F5F90(p0);
    int v = func_003F5F70(p0);
    switch (idx) {
    case 0:
        p->field_358 = a91_pextlw(a91_pmaxw(p->field_358, v));
        break;
    case 1:
        p->field_344 = a91_pextlw(a91_pmaxw(p->field_344, v));
        break;
    case 3:
        p->field_348 = a91_pextlw(a91_pmaxw(p->field_348, v));
        break;
    case 2:
        p->field_350 = a91_pextlw(a91_pmaxw(p->field_350, v));
        break;
    case 5:
        p->field_354 = a91_pextlw(a91_pmaxw(p->field_354, v));
        break;
    case 4:
        p->field_34C = a91_pextlw(a91_pmaxw(p->field_34C, v));
        break;
    case 6:
        p->field_368 = a91_pextlw(a91_pmaxw(p->field_368, v));
        break;
    case 7:
        p->field_36C = a91_pextlw(a91_pmaxw(p->field_36C, v));
        break;
    case 8:
        p->field_370 = a91_pextlw(a91_pmaxw(p->field_370, v));
        break;
    case 9:
        p->field_374 = a91_pextlw(a91_pmaxw(p->field_374, v));
        break;
    case 10:
        p->field_35C = a91_pextlw(a91_pmaxw(p->field_35C, v));
        break;
    case 11:
        p->field_378 = a91_pextlw(a91_pmaxw(p->field_378, v));
        break;
    case 12:
        p->field_37C = a91_pextlw(a91_pmaxw(p->field_37C, v));
        break;
    case 13:
        p->field_360 = a91_pextlw(a91_pmaxw(p->field_360, v));
        break;
    case 14:
        p->field_154 = a91_pextlw(a91_pmaxw(p->field_154, v));
        break;
    }
    Evaluate__10CB3ProfileFv(p);
    func_00139F20(p);
}
