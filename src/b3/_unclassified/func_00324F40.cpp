// Hand-written; the lifter refused it (a70: element loop, poll vfunc_24()==2 then ==1 -> vfunc_C, shared field_6C=0 after the if; embedded objects as char arrays).

// Release__15CGtVideoDecoderFv [L] DNAT: CGtVideoDecoder::Release() (research/proto/new_names.csv, high)
struct UnkStruct_c0;  // ring buffer at CGtVideoDecoder+0xc0 (Sony sample ViBuf [G])
struct sceMpeg;
extern "C" int viBufDelete(UnkStruct_c0 *);
extern "C" void sceMpegDelete(sceMpeg *);

class UnkStruct_00324F40_obj {
public:
    virtual int vfunc_8();
    virtual int vfunc_C();
    virtual int vfunc_10();
    virtual int vfunc_14();
    virtual int vfunc_18();
    virtual int vfunc_1C();
    virtual int vfunc_20();
    virtual int vfunc_24();
};

struct UnkStruct_00324F40_e {
    int field_0;
    int field_4;
    int field_8;
    unsigned char pad_C[0xC];
};

struct UnkStruct_00324F40 {
    UnkStruct_00324F40_e field_0[2];
    unsigned char pad_30[0x30];
    int field_60;
    int field_64;
    int field_68;
    UnkStruct_00324F40_obj * field_6C;
    unsigned char pad_70[0x8];
    char field_78[0x48];
    char field_C0[0x64];
    int field_124;
};

// 0x00324F40
extern "C" void Release__15CGtVideoDecoderFv(UnkStruct_00324F40 * self)
{
    for (int i = 0; i < 2; i++) {
        self->field_0[i].field_0 = 0;
        self->field_0[i].field_4 = -1;
        self->field_0[i].field_8 = -1;
    }
    viBufDelete((UnkStruct_c0 *)self->field_C0);
    sceMpegDelete((sceMpeg *)self->field_78);
    self->field_60 = 0;
    self->field_64 = 0;
    self->field_68 = 0;
    if (self->field_6C != 0) {
        while (self->field_6C->vfunc_24() == 2) {
        }
        if (self->field_6C->vfunc_24() == 1) {
            self->field_6C->vfunc_C();
        }
        self->field_6C = 0;
    }
    self->field_124 = 0x18;
}
