// NONMATCHING: Update__15CGtVideoDecoderFv -- retail 302 / ours 302 instructions, 16 in changed runs
// near19: viBufBeginPut typed as the SDK sample's (u_char **ptr0, int *len0, u_char **ptr1, int *len1), UncAddr-style pointer casts and vfunc_10(unsigned char *) put p0 on v1 as retail (18 -> 16). Left: p2/minSize/p1 rotate a1/a2/a0 vs ours a2/a0/a1 in both feed blocks; 48 decl/statement perms did not help
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// a82: 302/302 instrs, 18 changed, all register allocation in the two inlined 'feed' blocks (retail p0->v1/limit->a2, ours swapped; same under wibo and wine); layout, branch forms, switch, if(4A!=0){closing}else{main} all match
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// Update__15CGtVideoDecoderFv -- [L] DNAT: CGtVideoDecoder::Update() (research/proto/new_names.csv, high)
struct UnkStruct_00325030_file {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual int vfunc_10(unsigned char *, unsigned int); // a2 = minSize [C unit_00325030.s 0x3251C4 lui a2 live at jalr 0x325204]
    virtual void vfunc_14();
    virtual void vfunc_18(int, int);
    virtual void vfunc_1C();
    virtual void vfunc_20();
    virtual int vfunc_24();
};
struct UnkStruct_00325030_buf {
    void * field_0;
    unsigned char pad_4[0x14];
};
struct UnkStruct_00325030 {
    unsigned char pad_0[0x30];
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
    unsigned char pad_50[0x8];
    int field_58;
    int field_5C;
    unsigned char pad_60[0xC];
    UnkStruct_00325030_file * field_6C;
    int field_70;
    unsigned char pad_74[0x4];
    unsigned char field_78[0x48];
    unsigned char field_C0[0x60];
};

extern "C" void viBufEndPut(void *, int);
extern "C" int viBufCount(void *);
extern "C" void viBufBeginPut(void *, unsigned char **, int *, unsigned char **, int *);
extern "C" int viBufReset(void *);
extern "C" void sceMpegGetPicture(void *, void *, int);
extern "C" int sceMpegIsEnd(void *);
extern "C" void sceMpegReset(void *);

static inline void func_00325030_feed(UnkStruct_00325030 * self, int minSize)
{
    if (self->field_6C->vfunc_24() == 1 && self->field_4C != 1) {
        unsigned char * p0;
        int p1;
        unsigned char * p2;
        int p3;
        viBufBeginPut(self->field_C0, &p0, &p1, &p2, &p3);
        p0 = (unsigned char *)(((unsigned int)p0 & 0x0FFFFFFF) | 0x20000000);
        p2 = (unsigned char *)(((unsigned int)p2 & 0x0FFFFFFF) | 0x20000000);
        if (p1 >= minSize) {
            if (self->field_6C->vfunc_10(p0, minSize) <= 0) {
                self->field_4C = 1;
                if (self->field_4B != 0) {
                    self->field_6C->vfunc_18(0, 0);
                }
            }
            self->field_70 = minSize;
        }
    }
}

// 0x00325030
extern "C" void Update__15CGtVideoDecoderFv(UnkStruct_00325030 * self)
{
    if (self->field_48 == 0) {
        return;
    }
    if (self->field_4E != 0 && self->field_4A == 0) {
        return;
    }
    if (self->field_4A != 0) {
        switch (self->field_6C->vfunc_24()) {
        case 1:
            self->field_6C->vfunc_C();
            break;
        case 0:
            self->field_6C = 0;
            self->field_48 = 0;
            self->field_49 = 1;
            self->field_4B = 0;
            self->field_4A = 0;
            break;
        }
    } else {
        int s0 = (int)(self->field_3C / self->field_40);
        if (self->field_70 > 0) {
            if (self->field_6C->vfunc_24() == 1) {
                viBufEndPut(self->field_C0, self->field_70);
                self->field_70 = 0;
            }
        }
        if (self->field_70 == 0) {
            func_00325030_feed(self, 0x10000);
        }
        if (self->field_38 < s0) {
            if (!(viBufCount(self->field_C0) < 0x10001 && self->field_4C != 1)) {
                s0 = s0 - self->field_38;
                if (s0 > 2) {
                    s0 = 2;
                }
                while (s0 != 0) {
                    sceMpegGetPicture(self->field_78, ((UnkStruct_00325030_buf *)self + self->field_30)->field_0, self->field_58);
                    self->field_38++;
                    s0--;
                    if (sceMpegIsEnd(self->field_78) != 0) {
                        break;
                    }
                }
                self->field_30++;
                if (self->field_30 == 2) {
                    self->field_30 = 0;
                }
                self->field_34++;
                if (self->field_34 == 2) {
                    self->field_34 = 0;
                }
                if (sceMpegIsEnd(self->field_78) != 0 || self->field_4D != 0) {
                    viBufReset(self->field_C0);
                    sceMpegReset(self->field_78);
                    if (self->field_4B == 0) {
                        self->field_4A = 1;
                    } else {
                        self->field_4D = 0;
                        self->field_38 = -1;
                        self->field_3C = 0;
                        if (self->field_4C != 0) {
                            self->field_4C = 0;
                        } else {
                            while (self->field_6C->vfunc_24() != 1) {
                            }
                            self->field_6C->vfunc_18(0, 0);
                        }
                        if (self->field_70 == 0) {
                            func_00325030_feed(self, 0x80000);
                        }
                    }
                }
            }
        }
        if ((self->field_5C & 2) == 0) {
            self->field_3C += self->field_44;
        }
    }
}
