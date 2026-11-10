// NONMATCHING: func_002C13F0 -- retail 90 / ours 90 instructions, 13 in changed runs
// 13 instrs, register-only: layout exact (goto entry loop, pm=&self->field_81D8 in body). retail total=s1,i=s3,k=s4,ok=s2,ent=s0,pm=s6; 720 declaration orders tried, best 13
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

struct UnkStruct_NH_Mgr { unsigned char pad_0[0x28]; int field_28; };
struct UnkStruct_NH_Hs {
    unsigned char pad_0[0x8188];
    int field_8188[1];
    int field_818C[8];
    int field_81AC;
    int field_81B0[8];
    int field_81D0;
    int field_81D4;
    UnkStruct_NH_Mgr *field_81D8;
};
extern "C" void *func_002366D0(UnkStruct_NH_Mgr *, int);
extern "C" int func_0022FBB0(void *);
extern "C" void func_002C13F0(UnkStruct_NH_Hs *self)
{
    int *ent;
    int i;
    bool ok;
    int k;
    UnkStruct_NH_Mgr **pm;
    int total;
    total = self->field_81D8->field_28;
    i = 0;
    goto test;
    body:
    pm = &self->field_81D8;
    ent = &self->field_81B0[i];
    ok = true;
    for (k = 0; k < total; k++) {
        void *p = func_002366D0(*pm, k);
        if (p != 0) {
            if (*ent == func_0022FBB0(p)) ok = false;
        }
    }
    if (ok) {
        for (int t = 0; t < 8; t++) {
            if (self->field_818C[t] == *ent) {
                self->field_818C[t] = self->field_8188[self->field_81AC];
                self->field_8188[self->field_81AC] = -1;
            }
        }
    }
    i++;
    test:
    if (i < self->field_81D0) goto body;
}
