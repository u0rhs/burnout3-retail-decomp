// Hand-written; the lifter refused it (a70: derived CB3GraphicsManager with nested EClutID enum, u_long128 returns stored to members, bool temp for base Prepare()).

// Prepare__18CB3GraphicsManagerFv [L] DNAT: CB3GraphicsManager::Prepare() (research/proto/new_names.csv, high)
typedef unsigned int u_long128 __attribute__((mode(TI)));

class CGtTexture;

struct UnkStruct_skyZbuf_1 {
    unsigned long field_0;
};

class CB3GraphicsManagerBase {
public:
    bool Prepare();
};

class CB3GraphicsManager : public CB3GraphicsManagerBase {
public:
    enum EClutID { UnkEClutID_0 };
    u_long128 Copy8BitTextureAsPSMT8H(CGtTexture *, unsigned int, EClutID, unsigned int);
    u_long128 CopyTextureAs32Bit(CGtTexture *, unsigned int, unsigned int);
    u_long128 Copy4BitTextureAsPSMT4H(CGtTexture *, unsigned int, EClutID, bool, unsigned int);

    unsigned char pad_0[0x40];
    CGtTexture * field_40;
    CGtTexture * field_44;
    CGtTexture * field_48;
    CGtTexture * field_4C;
    unsigned char pad_50[0x380];
    u_long128 field_3D0;
    u_long128 field_3E0;
    u_long128 field_3F0;
    u_long128 field_400;
    unsigned int field_410;
};

extern UnkStruct_skyZbuf_1 skyZbuf_1;

// 0x00228070
extern "C" int Prepare__18CB3GraphicsManagerFv(CB3GraphicsManager * self)
{
    bool ok = self->Prepare();
    if (!ok) {
        return 0;
    }
    if (self->field_4C != 0) {
        self->field_3D0 = self->Copy8BitTextureAsPSMT8H(self->field_4C, (int)(skyZbuf_1.field_0 & 0x1FF) << 5, (CB3GraphicsManager::EClutID)4, 0);
    }
    if (self->field_40 != 0) {
        self->field_3E0 = self->CopyTextureAs32Bit(self->field_40, self->field_410 + 0x11C, 0);
    }
    if (self->field_44 != 0) {
        self->field_3F0 = self->Copy4BitTextureAsPSMT4H(self->field_44, self->field_410, (CB3GraphicsManager::EClutID)2, false, 3);
    }
    if (self->field_48 != 0) {
        self->field_400 = self->Copy4BitTextureAsPSMT4H(self->field_48, self->field_410 + 0xC0, (CB3GraphicsManager::EClutID)2, true, 3);
    }
    return 1;
}
