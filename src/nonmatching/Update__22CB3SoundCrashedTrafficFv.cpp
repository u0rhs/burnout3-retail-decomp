// NONMATCHING: Update__22CB3SoundCrashedTrafficFv -- retail 251 / ours 251 instructions, 20 in changed runs
// near26: 20 off, register-only (was 31): bool t = true in the wrecked loop (daddiu), volume stored then clamped in place through the field pointer (UpdateBassVoices shape) fixes the cvt/div schedule and length. Left: first-part temp colouring -- retail many=a1, count=t1, i=a2, wrecked=t0; ours many=a2, i=a1, count=t0, wrecked=t1 (declaration order, wrecked placement, inline vs in-body loop all inert)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)


typedef unsigned int u_long128 __attribute__((mode(TI)));

#include "b3/GtMath.h"
#include "b3/_unclassified/GtRandom.h"

class CGtSoundVoiceParams;

class CB3SoundCrashedTraffic;
class CGtSoundVirtualVoice;
struct UnkStruct_00290510_2;
struct UnkStruct_00290510_8;
struct UnkStruct_00290510_9;
struct UnkStruct_00290510_e0;
struct UnkStruct_00290510_e1;
struct UnkStruct_D_004E0BA8;
struct UnkStruct_D_004E0E00;
struct UnkStruct_D_004E12D0;
struct UnkStruct_D_00522660;
struct UnkStruct_D_0064D3A0;
struct UnkStruct_D_01E78E58;

class CGtSoundVirtualVoice {
public:
    void Stop();
    void Update(const CGtSoundVoiceParams*);
};

struct UnkStruct_00290510_e0 {
    unsigned char pad_0[0x93];
    unsigned char field_93;
    unsigned char pad_94[0x2C];
};

struct UnkStruct_00290510_2 {
    unsigned char pad_0[0xB0];
    u_long128 field_B0;
    unsigned char pad_C0[0x144];
    UnkStruct_00290510_9 * field_204;
    unsigned char pad_208[0x638];
    UnkStruct_00290510_e0 field_840[1];  // [G] element count unknown
};



struct UnkStruct_D_0064D3A0 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00290510_e1 {
    unsigned char pad_0[0x1CBA];
    unsigned char field_1CBA;
    unsigned char pad_1CBB[0xB15];
};

struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x12A980];
    UnkStruct_00290510_e1 field_12A980[1];  // [G] element count unknown
};

struct UnkStruct_00290510_v {
    float field_0;
    float field_4;
    float field_8;
    float field_C;
};

struct UnkStruct_00290510_8 {
    float field_0;
    float field_4;
    float field_8;
    float field_C;
    float field_10;
    float field_14;
    unsigned char pad_18[0x4];
    float field_1C;
    unsigned char pad_20[0x30];
};

struct UnkStruct_00290510_9 {
    unsigned char pad_0[0x30];
    u_long128 field_30;
};


struct UnkStruct_D_01E78E58 {
    CGtRandom field_0;
    unsigned char pad_8[0x8];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3SoundCrashedTraffic {
public:
    void Update();
    void StartBassVoices();
    void UpdateSkidVoices();
    void StartSkidVoices();

    UnkStruct_00290510_2 * field_0;
    int field_4;
    unsigned char pad_8[0x10];
    CGtSoundVirtualVoice * field_18;
    int field_1C;
    float field_20;
    unsigned char pad_24[0x4];
    int field_28;
    int field_2C;
    unsigned char pad_30[0x8];
    int field_38;
    unsigned char pad_3C[0x10];
    CGtSoundVirtualVoice * field_4C;
    CGtSoundVirtualVoice * field_50;
    int field_54;
    int field_58;
};

extern UnkStruct_D_0064D3A0 D_0064D3A0;
extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_D_01E78E58 D_01E78E58;

extern "C" void Construct__19CGtSoundVoiceParamsFv(void *);  // CGtSoundVoiceParams::Construct()

// [G] inlined helpers, placeholder names; [L] they are CB3SoundCrashedTraffic::ReleaseSkidVoices() and
// ReleaseBassVoices() (E-build B3O0PCH map names, out of line there, absent from retail).
static inline void func_00290510_inl1(CB3SoundCrashedTraffic * self)
{
    if (self->field_18 != 0) {
        self->field_18->Stop();
        self->field_18 = 0;
        self->field_1C = 0;
    }
}

static inline void func_00290510_inl2(CB3SoundCrashedTraffic * self)
{
    if (self->field_4C != 0) {
        self->field_4C->Stop();
        self->field_4C = 0;
        self->field_54 = 0;
    }
    if (self->field_50 != 0) {
        self->field_50->Stop();
        self->field_50 = 0;
        self->field_58 = 0;
    }
    self->field_38 = 0;
}

static inline int func_00290510_inl3(UnkStruct_00290510_2 * car)
{
    int c = 0;
    for (int i = 0; i < 4; i++) {
        if (car->field_840[i].field_93 != 0) {
            c++;
        }
    }
    return c;
}

// 0x00290510
void CB3SoundCrashedTraffic::Update()
{
    unsigned char wrecked = 0;
    if (field_4 == 0) {
        func_00290510_inl1(this);
        field_4 = 0;
        func_00290510_inl2(this);
    } else {
    field_4--;
    bool many = false;
    int n = func_00290510_inl3(field_0);
    if (n > 2) {
        many = true;
    }
    if (many) {
        field_20 += 0.05f;
    } else {
        field_20 -= 0.2f;
    }
    field_20 = GtMath::Min(GtMath::Max(field_20, 0.0f), 1.0f);
    for (int j = 0; j < D_0064D3A0.field_0; j++) {
        bool t = true;
        if (!wrecked) {
            if (D_00522660.field_12A980[j].field_1CBA == 0) {
                t = 0;
            }
        }
        wrecked = t;
    }
    if (n == 0 && wrecked) {
        field_38++;
        if (field_4C == 0) {
            StartBassVoices();
        } else {
            UnkStruct_00290510_8 params;
            Construct__19CGtSoundVoiceParamsFv(&params);
            UnkStruct_00290510_v pos;
            *(u_long128 *)&pos = field_0->field_204->field_30;
            params.field_0 = pos.field_0;
            params.field_4 = pos.field_4;
            params.field_8 = pos.field_8;
            if (field_38 < 1) {
                func_00290510_inl2(this);
            } else {
                float * vol = &params.field_1C;
                *vol = (float)field_38 / 60.0f;
                *vol = GtMath::Min(GtMath::Max(*vol, 0.0f), 0.85f);
                UnkStruct_00290510_v vel;
                *(u_long128 *)&vel = field_0->field_B0;
                float * v = &params.field_C;
                v[0] = vel.field_0;
                v[1] = vel.field_4;
                v[2] = vel.field_8;
                field_4C->Update((const CGtSoundVoiceParams *)&params);
                field_50->Update((const CGtSoundVoiceParams *)&params);
            }
        }
    } else {
        field_38 = 0;
        func_00290510_inl2(this);
    }
    if (field_18 != 0) {
        UpdateSkidVoices();
    } else {
        StartSkidVoices();
    }
    if (field_28 != 0) {
        field_28--;
        if (field_28 == 0) {
            CGtRandom * const g = &D_01E78E58.field_0;
            field_2C = g->Random() % 30 + 30;
        }
    }
    if (field_2C != 0) {
        field_2C--;
        if (field_2C == 0) {
            CGtRandom * const g = &D_01E78E58.field_0;
            field_28 = g->Random() % 30 + 30;
        }
    }
    }
}
