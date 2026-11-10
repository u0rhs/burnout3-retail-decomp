// NONMATCHING: NodataCallback__15CGtVideoDecoderFP7sceMpegP13sceMpegCbDataPv -- retail 106 / ours 106 instructions, 11 in changed runs
// near18: bool r = viBufCount(..) < 0x10000; if (r) keeps 0x10000 in a1 for the 4C arm (16 -> 11); left: feed block GPRs (retail p0 v0 / 0x20000000 a1 / 0x10000 a2 / slt into v1; ours a1/a2/v0) -- decl/statement perms and sreg no effect
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// NONMATCHING: NodataCallback__15CGtVideoDecoderFP7sceMpegP13sceMpegCbDataPv -- retail 106 / ours 107 instructions, 16 in changed runs
// a125: layout exact; 16 instrs: retail keeps 0x10000 in a1 (lui a1 after viBufCount; slt v0,v0,a1; reused as viBufEndPut arg in field_4C arm; feed's compare uses lui a2 and sched differs), ours slt at + rematerialised lui; local/inline/const forms all fold
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

struct sceMpeg;
struct sceMpegCbData;
struct UnkStruct_file {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual int vfunc_10(long, unsigned int); // a2 = minSize [C unit_00325030.s 0x3251C4 lui a2 live at jalr 0x325204]
    virtual void vfunc_14();
    virtual void vfunc_18(int, int);
    virtual void vfunc_1C();
    virtual void vfunc_20();
    virtual int vfunc_24();
};
struct UnkStruct_003259E0 {
    unsigned char pad_0[0x4B];
    unsigned char field_4B;
    unsigned char field_4C;
    unsigned char field_4D;
    unsigned char pad_4E[0x1E];
    UnkStruct_file * field_6C;
    int field_70;
    unsigned char pad_74[0x4C];
    unsigned char field_C0[0x60];
};
extern "C" void viBufEndPut(void *, int);
extern "C" int viBufCount(void *);
extern "C" int viBufAddDMA(void *);
extern "C" void viBufBeginPut(void *, unsigned int *, unsigned int *, unsigned int *, unsigned int *);

static inline void func_003259E0_feed(UnkStruct_003259E0 * self, int minSize)
{
    if (self->field_6C->vfunc_24() == 1 && self->field_4C != 1) {
        unsigned int p0;
        unsigned int p1;
        unsigned int p2;
        unsigned int p3;
        viBufBeginPut(self->field_C0, &p0, &p1, &p2, &p3);
        p0 = (p0 & 0x0FFFFFFF) | 0x20000000;
        p2 = (p2 & 0x0FFFFFFF) | 0x20000000;
        if ((int)p1 >= minSize) {
            if (self->field_6C->vfunc_10((long)(int)p0, minSize) <= 0) {
                self->field_4C = 1;
                if (self->field_4B != 0) {
                    self->field_6C->vfunc_18(0, 0);
                }
            }
            self->field_70 = minSize;
        }
    }
}

extern "C" int NodataCallback__15CGtVideoDecoderFP7sceMpegP13sceMpegCbDataPv(sceMpeg * p0, sceMpegCbData * p1, UnkStruct_003259E0 * self)
{
    bool r = viBufCount(self->field_C0) < 0x10000;
    if (r) {
        if (self->field_4C == 0) {
            if (self->field_70 > 0) {
                if (self->field_6C->vfunc_24() == 1) {
                    viBufEndPut(self->field_C0, self->field_70);
                    self->field_70 = 0;
                }
            }
            viBufAddDMA(self->field_C0);
            if (self->field_70 == 0) {
                func_003259E0_feed(self, 0x10000);
            }
        } else {
            self->field_4D = 1;
            viBufEndPut(self->field_C0, 0x10000);
            viBufAddDMA(self->field_C0);
        }
    } else {
        viBufAddDMA(self->field_C0);
    }
    return 1;
}

