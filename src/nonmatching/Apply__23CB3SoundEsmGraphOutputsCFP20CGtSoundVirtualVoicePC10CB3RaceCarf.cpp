// NONMATCHING: Apply__23CB3SoundEsmGraphOutputsCFP20CGtSoundVirtualVoicePC10CB3RaceCarf -- retail 61 / ours 61 instructions, 2 in changed runs
// pass3b: field_1C store via ((float*)d)[4], via a params pointer local, via float* p1c, with a float temp, and stored before field_24: all keep it right after the sq's (retail delays it until f0 is reused). Scheduler priority, not source order.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// regrot: v0/v1 swap fixed by copying v2 after the d stores (d's address temp created earlier -> colours later); left: swc1 field_1C (0x9C) scheduled above the v1/v2 lane loads (retail keeps it after the 0x64 load). Tried 1C/24/0-8 store orders, byte-offset pun

// Right shape (vector copies via u_long128 locals; params.field_C a nested 3-float struct reached through a pointer local). Left: v0/v1 swapped (lq temp vs the &params.field_C pointer) and the store of field_0*f (swc1 156(sp)) one slot earlier than retail's.

// CB3SoundEsmGraphOutputs::Apply(CGtSoundVirtualVoice*, const CB3RaceCar*, float) const -- hand-written (a69; the lifter refused
// a static callee with extra arguments: Construct's a1 is a phantom leftover). Layouts [G] from instruction widths.
typedef unsigned int u_long128 __attribute__((mode(TI)));

class CGtSoundVoiceParams;

class CGtSoundVirtualVoice {
public:
    int IsPlaying();
    void Update(const CGtSoundVoiceParams *);
};

struct UnkStruct_Apply_v3 { float field_0; float field_4; float field_8; };
struct UnkStruct_Apply_params {          // CGtSoundVoiceParams, 0x50 bytes
    float field_0;
    float field_4;
    float field_8;
    UnkStruct_Apply_v3 field_C;
    unsigned char pad_18[4];
    float field_1C;
    unsigned char pad_20[4];
    float field_24;
    unsigned char pad_28[0x28];
};
struct UnkStruct_Apply_v {
    float field_0;
    float field_4;
    float field_8;
    float field_C;
};
struct UnkStruct_Apply_src {
    unsigned char pad_0[0xB0];
    u_long128 field_B0;
};
struct UnkStruct_Apply_el {              // D_0055EFEC element, stride 0x30
    UnkStruct_Apply_src *field_0;
    unsigned char pad_4[0x2C];
};
struct CB3RaceCar {
    unsigned char pad_0[0x30];
    u_long128 field_30;
    unsigned char pad_40[0x196C];
    signed char field_19AC;
};

extern UnkStruct_Apply_el D_0055EFEC[];
extern "C" void Construct__19CGtSoundVoiceParamsFv(void *);

class CB3SoundEsmGraphOutputs {
public:
    void Apply(CGtSoundVirtualVoice *voice, const CB3RaceCar *car, float f) const;

    float field_0;
    float field_4;
};

void CB3SoundEsmGraphOutputs::Apply(CGtSoundVirtualVoice *voice, const CB3RaceCar *car, float f) const
{
    if (voice->IsPlaying() != 0) {
        UnkStruct_Apply_params params;
        UnkStruct_Apply_v v1;
        UnkStruct_Apply_v v2;
        UnkStruct_Apply_src *src = D_0055EFEC[car->field_19AC].field_0;
        Construct__19CGtSoundVoiceParamsFv(&params);
        *(u_long128 *)&v1 = src->field_B0;
        UnkStruct_Apply_v3 *d = &params.field_C;
        d->field_0 = v1.field_0;
        d->field_4 = v1.field_4;
        d->field_8 = v1.field_8;
        *(u_long128 *)&v2 = car->field_30;
        params.field_0 = v2.field_0;
        params.field_4 = v2.field_4;
        params.field_8 = v2.field_8;
        params.field_24 = field_4;
        params.field_1C = field_0 * f;
        voice->Update((const CGtSoundVoiceParams *)&params);
    }
}

