// Hand-written; the lifter refused it (per-entry voice-kind switch: 0 real voice muted dry x2, 2 virtual voice, 1 none; Doppler setup with .lit4 0.9f/0.1f).

// CB3SoundESMHigh::Prepare(unsigned long,int) -- hand-written (the lifter refused it).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundESM.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3SoundDoppler;
class CB3SoundESMGraphInputs;
class CB3SoundESMHigh;
class CGtSoundRealVoice;
class CGtSoundVoiceManager;
struct UnkStruct_002882D0_1;
struct UnkStruct_002882D0_e0;

class CGtSoundRealVoice {
public:
    void MuteDryVoice(int, bool);
};

class CGtSoundVoiceManager {
public:
    int AllocVirtualVoice();

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3SoundDoppler {
public:
    void SetMaxVolBoost(float);
    void SetMaxVolLinear(float);
    void SetMaxVolToPower(float);
};

class CB3SoundESMGraphInputs {
public:
    void Construct();
};

struct UnkStruct_002882D0_e0 {
    unsigned char pad_0[0xD];
    unsigned char field_D;  // [G] low nibble: the entry's voice kind (0: real voice, 1: none, 2: virtual voice)
    unsigned char pad_E[0x2];
};

struct UnkStruct_002882D0_1 {
    unsigned char pad_0[0x3C];
    UnkStruct_002882D0_e0 * field_3C;
    unsigned char field_40;
};

class CB3SoundESMHigh {
public:
    // Prepare(unsigned long, int) per the E map: defined below as Prepare__15CB3SoundESMHighFUli(self, int, unsigned long, int)

    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    CB3SoundESMGraphInputs field_4;
    unsigned char pad_5[0x27];
    UnkStruct_002882D0_1 * field_2C;
    int field_30;
    unsigned char pad_34[0x2C];
    CGtSoundRealVoice * field_60[1];  // [G] element count unknown
    unsigned char pad_64[0x2C];
    int field_90;
    CB3SoundDoppler field_94;
};

extern CGtSoundVoiceManager D_01E7569C;

extern "C" int func_00288960(CB3SoundESMHigh *, int, unsigned long, int);
extern "C" CGtSoundRealVoice * AllocRealVoice__20CGtSoundVoiceManagerFv(CGtSoundVoiceManager *);
extern "C" int func_002F4F10(CB3SoundDoppler *);

// 0x002882D0
// pass1 [C]: retail passes three arguments, not the E-map name's (unsigned long, int): CB3SoundAICar::Prepare
// calls this slot with a1 = 0, a2 = its id, a3 = its index (0x28BDD0's vcall; CB3SoundPlayerCar passes a byte field in
// a1), and the base func_00288960 reads a2 (stored 64-bit) and a3 (an index into D_0064D388), never a1. Defined through
// the link name so the parameter list can say so; a1's meaning is unknown (no reader).
extern "C" int Prepare__15CB3SoundESMHighFUli(CB3SoundESMHigh *self, int p0, unsigned long p1, int p2)
{
    if (func_00288960(self, p0, p1, p2) != 0) {
        if (self->field_30 != 5) {
            for (unsigned int i = 0; i < self->field_2C->field_40; i++) {
                switch (self->field_2C->field_3C[i].field_D & 0xF) {
                case 0:
                    self->field_60[i] = AllocRealVoice__20CGtSoundVoiceManagerFv(&D_01E7569C);
                    self->field_60[i]->MuteDryVoice(0, true);
                    self->field_60[i]->MuteDryVoice(1, true);
                    break;
                case 2:
                    self->field_90 = D_01E7569C.AllocVirtualVoice();
                    self->field_60[i] = 0;
                case 1:
                    self->field_60[i] = 0;
                    break;
                }
            }
            self->field_30 = 5;
        }
        self->vfunc_18();
        func_002F4F10(&self->field_94);
        self->field_94.SetMaxVolLinear(0.9f);
        self->field_94.SetMaxVolToPower(0.0f);
        self->field_94.SetMaxVolBoost(0.1f);
        self->field_4.Construct();
        return 1;
    }
    return 0;
}
