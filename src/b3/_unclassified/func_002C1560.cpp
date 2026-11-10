// Hand-written; the lifter refused it (mwperm: 'for (j = 0; j < self->field_81D0; j++) { if (self->field_81B' -> 'j = 0; goto loop1_t; loop1: if (func_0022FBB0(p) != self->field_81B0[j]) { } els').

struct UnkStruct_NH_Mgr { unsigned char pad_0[0x28]; int field_28; };
struct UnkStruct_NH_Hs {
    unsigned char pad_0[0x8188];
    int field_8188[2];
    int field_8190[6];
    int field_81A8;
    int field_81AC;
    int field_81B0[8];
    int field_81D0;
    int field_81D4;
    UnkStruct_NH_Mgr *field_81D8;
};
extern "C" void *func_002366D0(UnkStruct_NH_Mgr *, int);
extern "C" int func_0022FBB0(void *);
// 0x002C1560
extern "C" void func_002C1560(UnkStruct_NH_Hs *self, int *ids, int *count)
{
    int n;
    int total;
    int i;
    int j;
    void *p;
    bool ok;
    n = 0;
    total = self->field_81D8->field_28;
    for (i = 0; i < total; i++) {
        p = func_002366D0(self->field_81D8, i);
        if (p != 0) {
            ok = true;
            j = 0;
            goto loop1_t;
        loop1:
            if (func_0022FBB0(p) != self->field_81B0[j]) {
            } else {
                ok = false;
            }
            j++;
                
        loop1_t:
            unsigned char t1 = self->field_81D0 > j;
            if (!(t1)) {
            } else {
                goto loop1;
            }
            if (ok) {
                ids[n++] = func_0022FBB0(p);
            }
        }
    }
    *count = n;
}
