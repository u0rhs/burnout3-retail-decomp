// NONMATCHING: Prepare__15CGtVideoDecoderFP15CGtLinearMallociiPCcfUi -- retail 294 / ours 294 instructions, 18 in changed runs
// near28: 18 off (was 38). default: break + case 2 ending in break with one trailing 'return 1' gives retail's shared li 1 / b; ld ra stub; field_4B store moved just before viBufReset (sb in its jal delay slot); loop loads ordered t1/t0/a2. Left: loop temp registers (retail field_120=a2, field_50=t1, pC=a3) and the feed inline's p0/0x20000000/minSize registers (retail v0/a1/a2)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)


// Prepare__15CGtVideoDecoderFP15CGtLinearMallociiPCcfUi -- [L] DNAT: CGtVideoDecoder::Prepare(CGtLinearMalloc*,int,int,const char*,float,unsigned int) (research/proto/new_names.csv, high)
struct UnkStruct_00325030_file {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual int vfunc_10(long, unsigned int); // a2 = minSize [C unit_00325030.s 0x3251C4 lui a2 live at jalr 0x325204]
    virtual void vfunc_14();
    virtual void vfunc_18(int, int);
    virtual void vfunc_1C();
    virtual void vfunc_20();
    virtual int vfunc_24();
};
struct UnkStruct_00325030_buf {
    void * field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
};
struct UnkStruct_00325030 {
    UnkStruct_00325030_buf field_0[2];
    int field_30;
    int field_34;
    int field_38;
    float field_3C;
    float field_40;
    float field_44;
    unsigned char field_48;
    unsigned char field_49;
    unsigned char field_4A;
    unsigned char field_4B;
    unsigned char field_4C;
    unsigned char field_4D;
    unsigned char field_4E;
    unsigned char pad_4F[0x1];
    int field_50;
    int field_54;
    int field_58;
    int field_5C;
    void * field_60;
    void * field_64;
    void * field_68;
    int field_6C;
    int field_70;
    unsigned char pad_74[0x4];
    unsigned char field_78[0x48];
    unsigned char field_C0[0x60];
    int field_120;
    int field_124;
};

extern "C" void viBufEndPut(void *, int);
extern "C" int viBufCount(void *);
extern "C" void viBufBeginPut(void *, unsigned int *, unsigned int *, unsigned int *, unsigned int *);
extern "C" int viBufReset(void *);
extern "C" void sceMpegGetPicture(void *, void *, int);
extern "C" int sceMpegIsEnd(void *);
extern "C" void sceMpegReset(void *);
extern "C" void sceMpegCreate(void *, void *, int);
extern "C" void sceMpegAddCallback(void *, int, void *, void *);
extern "C" int viBufCreate(void *, void *, void *, int, int, int);
extern "C" void * GetFileSystemFromFileName__13CGTFileSystemFPCc(const char *);
extern "C" int Open__13CGTFileSystemFPCcUi(void *, const char *, unsigned int);
extern "C" void func_002F9CF0(void *, int);
extern "C" void * Malloc__15CGtLinearMallocFUi(void *, int);
extern "C" int NodataCallback__15CGtVideoDecoderFP7sceMpegP13sceMpegCbDataPv(void *, void *, void *);
extern "C" void StopDMA__15CGtVideoDecoderFP7sceMpegP13sceMpegCbDataPv(void *, void *, void *);
extern "C" void RestartDMA__15CGtVideoDecoderFP7sceMpegP13sceMpegCbDataPv(void *, void *, void *);

static inline void func_00325030_feed(UnkStruct_00325030 * self, int minSize)
{
    if (((UnkStruct_00325030_file *)self->field_6C)->vfunc_24() == 1 && self->field_4C != 1) {
        unsigned int p0;
        unsigned int p1;
        unsigned int p2;
        unsigned int p3;
        viBufBeginPut(self->field_C0, &p0, &p1, &p2, &p3);
        p0 = (p0 & 0x0FFFFFFF) | 0x20000000;
        p2 = (p2 & 0x0FFFFFFF) | 0x20000000;
        if ((int)p1 >= minSize) {
            if (((UnkStruct_00325030_file *)self->field_6C)->vfunc_10((long)(int)p0, minSize) <= 0) {
                self->field_4C = 1;
                if (self->field_4B != 0) {
                    ((UnkStruct_00325030_file *)self->field_6C)->vfunc_18(0, 0);
                }
            }
            self->field_70 = minSize;
        }
    }
}


// 0x003254F0
extern "C" int Prepare__15CGtVideoDecoderFP15CGtLinearMallociiPCcfUi(UnkStruct_00325030 * self, void * alloc, int w, int h, const char * name, float rate, unsigned int flags)
{
    switch (self->field_124) {
    default:
        break;
    case 1:
    case 24: {
        void * fs = GetFileSystemFromFileName__13CGTFileSystemFPCc(name);
        self->field_6C = Open__13CGTFileSystemFPCcUi(fs, name, 0x11);
        if (self->field_6C == 0) {
            return 0;
        }
        void * saved = *(void **)((char *)alloc + 0x14);
        func_002F9CF0(alloc, 0x80);
        self->field_40 = rate;
        self->field_44 = rate;
        self->field_50 = w / 16;
        self->field_54 = h / 16;
        self->field_58 = self->field_50 * self->field_54;
        int sz = (w * h * 9) / 2 + 0x2800;
        self->field_64 = Malloc__15CGtLinearMallocFUi(alloc, sz);
        self->field_60 = Malloc__15CGtLinearMallocFUi(alloc, 0x100000);
        self->field_68 = Malloc__15CGtLinearMallocFUi(alloc, 0x110);
        for (int i = 0; i < 2; i++) {
            UnkStruct_00325030_buf * e = &self->field_0[i];
            int t1 = self->field_50;
            int t0 = self->field_54;
            int a2 = self->field_120;
            int * pC = &e->field_C;
            int * p10 = &e->field_10;
            int * p4 = &e->field_4;
            *pC = t1;
            *p10 = t0;
            *p4 = t1 / 4;
            int * p8 = &e->field_8;
            *p8 = t0 / 4;
            e->field_14 = a2;
            if (t1 % 4 != 0) {
                *p4 = *p4 + 1;
            }
            if (t0 % 4 != 0) {
                *p8 = *p8 + 1;
            }
            e->field_0 = Malloc__15CGtLinearMallocFUi(alloc, (*pC * *p10) << 10);
        }
        func_002F9CF0(alloc, (int)saved);
        sceMpegCreate(self->field_78, self->field_64, sz);
        sceMpegAddCallback(self->field_78, 1, (void *)NodataCallback__15CGtVideoDecoderFP7sceMpegP13sceMpegCbDataPv, self);
        sceMpegAddCallback(self->field_78, 2, (void *)StopDMA__15CGtVideoDecoderFP7sceMpegP13sceMpegCbDataPv, self);
        sceMpegAddCallback(self->field_78, 3, (void *)RestartDMA__15CGtVideoDecoderFP7sceMpegP13sceMpegCbDataPv, self);
        viBufCreate(self->field_C0, self->field_60, self->field_68, 0x10, 0, 0);
        self->field_30 = 0;
        self->field_34 = 1;
        self->field_49 = 0;
        self->field_48 = 1;
        self->field_4A = 0;
        self->field_4C = 0;
        self->field_4D = 0;
        self->field_4E = 0;
        self->field_70 = 0;
        self->field_38 = -1;
        self->field_3C = 0;
        self->field_5C = flags;
        self->field_4B = (flags & 1) != 0;
        viBufReset(self->field_C0);
        sceMpegReset(self->field_78);
        if (self->field_70 == 0) {
            func_00325030_feed(self, 0x80000);
        }
        self->field_124 = 2;
    }
    case 2:
        if (self->field_70 > 0) {
            if (((UnkStruct_00325030_file *)self->field_6C)->vfunc_24() == 1) {
                viBufEndPut(self->field_C0, self->field_70);
                self->field_70 = 0;
            }
        }
        if (viBufCount(self->field_C0) < 0x10001) {
            return 0;
        }
        self->field_124 = 0x17;
        break;
    }
    return 1;
}


