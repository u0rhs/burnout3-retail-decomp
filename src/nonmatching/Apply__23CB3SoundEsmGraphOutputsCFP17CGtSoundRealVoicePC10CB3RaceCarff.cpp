// NONMATCHING: Apply__23CB3SoundEsmGraphOutputsCFP17CGtSoundRealVoicePC10CB3RaceCarff -- retail 97 / ours 97 instructions, 2 in changed runs
// pass3b: scheduling-only (sq v2 above the first v1 lane load); not re-tuned -- the VirtualVoice sibling's store-placement forms (through d, pointer local, float temp, order swap) all keep ours' early placement.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// regrot: v0/v1 swap fixed by copying v2 after the d stores; left: sq v2 (0x60) scheduled before the first v1 lane load lwc1 f6,0x70 (retail interleaves). Tried reading v1.field_0 first, v2 copy between d stores

// a124: 97/97 instrs, 6 in changed runs; all logic exact (min/max of field_8/C, lo*=1/hi, res via shared float, 1.0f/-1.0f arms). Left only the v0/v1 swap (lq temp vs &params.field_C pointer) and its store regs — same as the earlier archive of the VirtualVoice variant; sweeps of v1/v2 order, d placement failed

typedef unsigned int u_long128 __attribute__((mode(TI)));

class CGtSoundVoiceParams;

class CGtSoundRealVoice {
public:
    int IsPlaying() const;
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
    unsigned char pad_28[4];
    float field_2C;
    float field_30;
    unsigned char pad_34[0x1C];
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
    void Apply(CGtSoundRealVoice *voice, const CB3RaceCar *car, float f, float g) const;
    float field_0;
    float field_4;
    float field_8;
    float field_C;
};

void CB3SoundEsmGraphOutputs::Apply(CGtSoundRealVoice *voice, const CB3RaceCar *car, float f, float g) const
{
    if (voice->IsPlaying() == 0) {
        return;
    }
    {
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
        float hi;
        float lo;
        bool swapped;
        if (field_8 > field_C) {
            hi = field_8;
            lo = field_C;
            swapped = true;
        } else {
            hi = field_C;
            lo = field_8;
            swapped = false;
        }
        if (hi == 0.0f) {
            lo = 1.0f;
        } else {
            lo = lo * (1.0f / hi);
        }
        float res;
        if (swapped) {
            res = -1.0f + lo;
        } else {
            res = 1.0f - lo;
        }
        params.field_2C = res;
        params.field_30 = params.field_1C = field_0 * f;
        params.field_24 = field_4 * g;
        voice->Update((const CGtSoundVoiceParams *)&params);
    }
}

