// Hand-written; the lifter refused it (a117: lgDev enumerate/open loop; for(;;) with break + goto bad/inc [G]; decl order i,j,n,(ep,e)).

struct UnkStruct_00442720_e { unsigned char pad_0[8]; int field_8; unsigned char pad_C[0x10]; };
struct UnkStruct_00442720 {
    int field_0[2];
    unsigned char field_8[0x30];
    int field_38[2];
    int field_40;
};
extern "C" void *memset(void *, int, unsigned long);
extern "C" int lgDevEnumerate(int, void *);
extern "C" int lgDevOpen(int, void *);
extern "C" void lgDevClose(int);

// 0x00442720
extern "C" int func_00442720(UnkStruct_00442720 * self)
{
    int i = 0;
    int j = 0;
    int n = 0;
    void * ep; UnkStruct_00442720_e * e;
    self->field_40 = 0;
    do {
        if (self->field_38[i] != -1) {
            lgDevClose(self->field_38[i]);
            self->field_38[i] = -1;
        }
        memset((char *)self + i * 0x18 + 8, 0, 0x18);
        self->field_0[i] = 0;
        i++;
    } while (i < 2);
    for (;;) {
        if (!(2 > n)) break;
        e = (UnkStruct_00442720_e *)((char *)self + n * 0x18);
        ep = &e->field_8;
        if (lgDevEnumerate(j, ep) & 0x80000000) break;
        if ((unsigned)(e->field_8 - 0x11) >= 2) goto bad;
        if (lgDevOpen(j, &self->field_38[n]) & 0x80000000) goto bad;
        n++;
    inc:
        j++;
        continue;
    bad:
        memset(ep, 0, 0x18);
        self->field_38[n] = -1;
        goto inc;
    }
    return 1;
}
