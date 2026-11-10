// NONMATCHING: Start__15CB3SoundESMHighFv -- retail 119 / ours 119 instructions, 15 in changed runs
// 119/119, 15 changed: logic, layout, frame exact (switch case 0/2/1, bool flag set before the calls, n++ before SetType, const d = &D_01E7AA40). Left: s0/s1 swap -- retail d=s0, flag=s1; ours flag=s0, d=s1. sreg 2 rounds + flag declaration/type, w pointer/reference forms tried.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CB3SoundESMHigh::Start() -- hand-written (fresh1).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundESM.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

enum EDSPType {};

class CGtSoundBank;

class CGtSoundVoiceParams {
public:
    void Construct();

    unsigned char pad_0[0x18];
    int field_18;
    unsigned char pad_1C[0x28];
    unsigned char field_44;
    unsigned char field_45;
    unsigned char pad_46[0x2];
};

class CGtSoundRealVoice {
public:
    void Start(const CGtSoundVoiceParams*);
};

class CGtSoundVirtualVoice {
public:
    void Start(const CGtSoundVoiceParams*);
};

class CB3SoundDSPDataBlock {
public:
    void SetType(EDSPType);
    void Reset();

    unsigned char pad_0[0x110];
};

class CB3SoundDistortion {
public:
    void SetChannels(int);

    CB3SoundDSPDataBlock field_0[2];  // [G] element count: the fill loop stops at 2
};

class CGtSoundBankManager {
public:
    int FindWave(const unsigned long&, bool) const;

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00287C40_e0 {
    unsigned long field_0;  // [G] the wave id FindWave reads (passed by address)
    unsigned char pad_8[0x5];
    unsigned char field_D;
    unsigned char pad_E[0x2];
};

struct UnkStruct_00287C40_2 {
    unsigned char pad_0[0x3C];
    UnkStruct_00287C40_e0 * field_3C;
    unsigned char field_40;
};

class CGtSoundBank {
public:
    int FindWave(const unsigned long&, bool) const;
};

class CB3SoundESMHigh {
public:
    void Start();

    unsigned char pad_0[0x28];
    CGtSoundBank * field_28;
    UnkStruct_00287C40_2 * field_2C;
    unsigned char pad_30[0x27];
    unsigned char field_57;
    unsigned char pad_58[0x8];
    CGtSoundRealVoice * field_60[12];  // [G] element count unknown
    CGtSoundVirtualVoice * field_90;
};

struct UnkStruct_kWaveIdTurboTurbine {
    unsigned long field_0;
    unsigned char pad_8[0x8];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern UnkStruct_kWaveIdTurboTurbine kWaveIdTurboTurbine;
extern CGtSoundBankManager D_01E75648;
extern CB3SoundDistortion D_01E7AA40;

// 0x00287C40
void CB3SoundESMHigh::Start()
{
    CGtSoundVoiceParams params;
    params.Construct();
    params.field_45 = 1;
    params.field_44 = 4;
    unsigned int i;
    unsigned int n = 0;
    int mask = 0;
    CB3SoundDistortion * const d = &D_01E7AA40;
    for (i = 0; i < field_2C->field_40; i++) {
        bool on = true;
        UnkStruct_00287C40_e0 * e = &field_2C->field_3C[i];
        unsigned char b = e->field_D;
        switch (b & 0xF) {
        case 0:
            params.field_18 = field_28->FindWave(e->field_0, false);
            field_60[i]->Start(&params);
            break;
        case 2: {
            int &w = params.field_18;
            if ((w = field_28->FindWave(e->field_0, false)) == 0) {
                w = D_01E75648.FindWave(kWaveIdTurboTurbine.field_0, false);
            }
            on = false;
            field_90->Start(&params);
            break;
        }
        case 1: {
            CB3SoundDSPDataBlock * blk = &d->field_0[i];
            on = false;
            n++;
            blk->SetType((EDSPType)((b & 0xF0) >> 4));
            blk->Reset();
            break;
        }
        }
        mask = (mask << 1) | on;
    }
    if (n <= 1) {
        for (; n < 2; n++) d->field_0[n].SetType((EDSPType)0);
    }
    d->SetChannels(mask);
    field_57 = 1;
}

