// Hand-written; the lifter refused it (a145: two inlined chunk-fetch arms (func_00236310 / func_00236460); gotos so arm A's n<=0 falls into arm B and A's completion jumps to the common end; pA,pB,sA,sB declared at top; ushort a1/a2 locals for modular diff).

struct UnkStruct_C09A0_out {
    unsigned char field_0;
    unsigned char pad_1[2];
    unsigned char field_3;
    unsigned char pad_4[8];
    unsigned short field_C;
    unsigned char pad_E[2];
    unsigned char field_10[4];
    unsigned short field_14;
};
struct UnkStruct_C09A0_mgr { unsigned char pad_0[8]; void * field_8[8]; int field_28; };
struct UnkStruct_C09A0 {
    unsigned char pad_0[0xC];
    unsigned char field_C[4][0x200];
    int field_80C[4];
    int field_81C;
    unsigned char pad_820[8];
    unsigned char field_828;
    unsigned char pad_829[0x8168 - 0x829];
    unsigned short field_8168;
    unsigned char pad_816A[0x81D8 - 0x816A];
    UnkStruct_C09A0_mgr * field_81D8;
};
extern "C" int GetPlayerByID__23CGtNetworkPlayerManagerCFi(void *, int);
extern "C" int GetMyPlayerID__23CGtNetworkPlayerManagerCFv(void *);
extern "C" int func_0022FBB0(void *);
extern "C" void * func_00236310(void *, int);
extern "C" void * func_00236460(void *, int);
extern "C" UnkStruct_C09A0_out * func_0022F910(void *, int);
extern "C" void func_0022D850(void *);
extern "C" void * memcpy(void *, const void *, unsigned int);

static inline unsigned short func_C09A0_dist(unsigned short a, unsigned short b)
{
    if (a < 0x5555 && b > 0xAAAA) return a + (0xFFFF - b);
    return a - b;
}

// 0x002C09A0
extern "C" void func_002C09A0(UnkStruct_C09A0 * self, unsigned short seq)
{
    unsigned short d;
    int pA[4];
    int pB[4];
    int sA[4];
    int sB[4];
    unsigned short a1 = seq;
    unsigned short a2 = self->field_8168;
    if (a1 < 0x5555 && a2 > 0xAAAA) d = a1 + (0xFFFF - a2);
    else d = a1 - a2;
    // [G] gotos: arm A falls into arm B when no player is counted; retail ends A with a jump to the common end
    if (self->field_828 == 0) goto armB;
    {
        int j;
        int n = 0;
        int cnt = self->field_81D8->field_28;
        for (j = 0; j < cnt; j++) {
            if (self->field_81D8->field_8[j] != 0) n++;
        }
        if (n > 0) {
            void * h = func_00236310(self->field_81D8, GetMyPlayerID__23CGtNetworkPlayerManagerCFv(self->field_81D8));
            if (h == 0) return;
            UnkStruct_C09A0_out * o = func_0022F910((void *)GetPlayerByID__23CGtNetworkPlayerManagerCFi(self->field_81D8, func_0022FBB0(h)), 2);
            int i;
            for (i = 0; i < 4; i++) pA[i] = (int)((char *)o + 0x20 + i * 0x42);
            int s4 = self->field_81C;
            if ((o->field_0 & 1) != 1) {
                for (i = 0; i < 4; i++) {
                    sA[i] = self->field_80C[s4];
                    if (sA[i] > 0x42) sA[i] = 0x42;
                    memcpy((void *)pA[i], self->field_C[s4], sA[i]);
                    s4 = (s4 + 1) % 4;
                }
                for (i = 0; i < 4; i++) o->field_10[i] = sA[i];
                o->field_14 = (unsigned short)d - 3;
                if ((o->field_0 & 2) == 2) func_0022D850(o);
                o->field_3 = 2;
                o->field_C = seq;
                o->field_0 = o->field_0 | 1;
            }
            self->field_828 = 0;
            goto done;
        }
    }
armB:
    {
        int j;
        int n = 0;
        int cnt = self->field_81D8->field_28;
        for (j = 0; j < cnt; j++) {
            if (self->field_81D8->field_8[j] != 0) n++;
        }
        if (n > 0) {
            void * h = func_00236460(self->field_81D8, GetMyPlayerID__23CGtNetworkPlayerManagerCFv(self->field_81D8));
            if (h == 0) return;
            UnkStruct_C09A0_out * o = func_0022F910((void *)GetPlayerByID__23CGtNetworkPlayerManagerCFi(self->field_81D8, func_0022FBB0(h)), 2);
            int i;
            for (i = 0; i < 4; i++) pB[i] = (int)((char *)o + 0x20 + i * 0x42);
            int s4 = self->field_81C;
            if ((o->field_0 & 1) != 1) {
                for (i = 0; i < 4; i++) {
                    sB[i] = self->field_80C[s4];
                    if (sB[i] > 0x42) sB[i] = 0x42;
                    memcpy((void *)pB[i], self->field_C[s4], sB[i]);
                    s4 = (s4 + 1) % 4;
                }
                for (i = 0; i < 4; i++) o->field_10[i] = sB[i];
                o->field_14 = (unsigned short)d - 3;
                if ((o->field_0 & 2) == 2) func_0022D850(o);
                o->field_3 = 2;
                o->field_C = seq;
                o->field_0 = o->field_0 | 1;
            }
            self->field_828 = 1;
        }
    }
done:
    return;
}
