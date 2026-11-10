// Hand-written; the lifter refused it (a135: lgDev enumeration shape reused from func_00442720 (do-while close/memset, for(;;) with goto bad/inc), then vtable slot 8 release loop).

struct UnkStruct_00442580_e { unsigned char pad_0[8]; int field_8; unsigned char pad_C[0x10]; };
struct UnkStruct_Obj {
    virtual void vfunc_8();
};
struct UnkStruct_00442580 {
    UnkStruct_Obj *field_0[2];
    unsigned char field_8[0x30];
    int field_38[2];
};
extern "C" void *memset(void *, int, unsigned long);
extern "C" void lgDevEnumHint(int *);
extern "C" int lgDevEnumerate(int, void *);
extern "C" int lgDevOpen(int, void *);
extern "C" void lgDevClose(int);

// 0x00442580
extern "C" void func_00442580(UnkStruct_00442580 * self)
{
    int i;
    int j = 0;
    int n = 0;
    void * ep; UnkStruct_00442580_e * e;
    int hint;
    lgDevEnumHint(&hint);
    if (hint == 1) {
        i = 0;
        do {
            if (self->field_38[i] != -1) {
                lgDevClose(self->field_38[i]);
                self->field_38[i] = -1;
            }
            memset((char *)self + i * 0x18 + 8, 0, 0x18);
            i++;
        } while (i < 2);
        for (;;) {
            if (!(2 > n)) break;
            e = (UnkStruct_00442580_e *)((char *)self + n * 0x18);
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
    }
    for (i = 0; i < 2; i++) {
        if (self->field_0[i] != 0) {
            self->field_0[i]->vfunc_8();
        }
    }
}
