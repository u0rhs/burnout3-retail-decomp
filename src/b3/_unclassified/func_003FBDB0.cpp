// Hand-written; the lifter refused it (regrot: shuffle swap reads/writes field_D[k] by index (no pa pointer local) -- the element address becomes an expression temp created later, so it colours before rr).


struct UnkStruct_Rnd { int field_0; int field_4; };
extern "C" UnkStruct_Rnd _mRandom__13CGtSoundUtils;
struct UnkStruct_D_0064D370_x { unsigned long field_0; unsigned char pad_8[8]; };
extern UnkStruct_D_0064D370_x D_0064D370;
struct UnkStruct_D_004EE040 { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_004EE040 D_004EE040;
struct UnkStruct_Ent { unsigned char pad_0[0x14]; unsigned int field_14; unsigned char pad_18[0]; };
struct UnkStruct_003FBDB0 {
    unsigned char pad_0[0xC];
    unsigned char field_C;
    unsigned char field_D[0x33];
    int field_40;
    unsigned int field_44;
    unsigned char pad_48[0x24];
    unsigned int field_6C;
    unsigned char pad_70[0x44];
    char * field_B4;
    unsigned char pad_B8[0x4];
    unsigned char field_BC;
    unsigned char pad_BD[0xB];
    int field_C8_pad;
    int field_CC;
    unsigned char pad_D0[8];
    int field_D8;
};
extern "C" int func_00131E40(void *);
static inline unsigned Rnd()
{
    int a = _mRandom__13CGtSoundUtils.field_0;
    int x = (a << 16) + (a >> 16);
    x += _mRandom__13CGtSoundUtils.field_4;
    _mRandom__13CGtSoundUtils.field_4 += x;
    _mRandom__13CGtSoundUtils.field_0 = x;
    return x;
}
// 0x003FBDB0
extern "C" int func_003FBDB0(UnkStruct_003FBDB0 * self)
{
    int r = -1;
    unsigned char mode;
    if (D_0064D370.field_0 != 0) {
        if (func_00131E40(&D_004EE040)) {
            mode = 2;
        } else {
            mode = 1;
        }
    } else {
        mode = 4;
    }
    self->field_C = 0;
    switch (self->field_CC) {
    case 1:
    case 5:
        {
            unsigned j = 0;
            goto test1;
        body1:
            r = (self->field_D8 + j + 1) % self->field_6C;
            if (self->field_BC == 0) goto out1;
            if (mode & ((UnkStruct_Ent *)(self->field_B4 + r * 0x18))->field_14) goto out1;
            j++;
        test1:
            if (j < self->field_6C) goto body1;
        out1:
            if (j == self->field_6C) {
                self->field_C = 1;
                r = -1;
            }
        }
        break;
    case 4:
    case 3:
        r = self->field_D8;
        break;
    case 2:
        {
            unsigned n;
            unsigned i = 0;
            goto test2;
        body2:
            if (self->field_44 != n) {
                self->field_44 = n;
                int j = 0;
                while (j < (int)n) {
                    self->field_D[j] = j;
                    j++;
                }
                unsigned k = 0;
                while (k < n) {
                    unsigned rr = Rnd() % (n - k);
                    unsigned char * pb = &self->field_D[k + rr];
                    unsigned char t = self->field_D[k];
                    unsigned char u = *pb;
                    *pb = t;
                    self->field_D[k] = u;
                    k++;
                }
                self->field_40 = Rnd() % n;
            }
            r = self->field_D[self->field_40];
            self->field_40 = (self->field_40 + 1) % (int)self->field_44;
            if (self->field_BC == 0) goto out2;
            if (mode & ((UnkStruct_Ent *)(self->field_B4 + r * 0x18))->field_14) goto out2;
            i++;
        test2:
            if (i < (n = self->field_6C)) goto body2;
        out2:
            if (i == self->field_6C) {
                r = -1;
                self->field_C = 1;
            }
        }
        break;
    default:
        break;
    }
    return r;
}
