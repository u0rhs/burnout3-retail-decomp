// CB3SoundESMLow::Prepare(unsigned long,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundESM.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3SoundESMGraphInputs;
class CB3SoundESMLow;
class CGtSoundVoiceManager;
struct UnkStruct_00287890_1;

class CGtSoundVoiceManager {
public:
    int AllocVirtualVoice();

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3SoundESMGraphInputs {
public:
    void Construct();
};

struct UnkStruct_00287890_1 {
    unsigned char pad_0[0x40];
    unsigned char field_40;
};

class CB3SoundESMLow {
public:
    // Prepare(unsigned long, int) per the E map: defined below as Prepare__14CB3SoundESMLowFUli(self, int, unsigned long, int)

    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    CB3SoundESMGraphInputs field_4;
    unsigned char pad_5[0x27];
    UnkStruct_00287890_1 * field_2C;
    int field_30;
    unsigned char pad_34[0x2C];
    int field_60[1];  // [G] element count unknown
};

extern CGtSoundVoiceManager D_01E7569C;

extern "C" int func_00288960(CB3SoundESMLow *, int, unsigned long, int);

// 0x00287890
// pass1 [C]: retail passes three arguments, not the E-map name's (unsigned long, int): CB3SoundAICar::Prepare
// calls this slot with a1 = 0, a2 = its id, a3 = its index (0x28BDD0's vcall; CB3SoundPlayerCar passes a byte field in
// a1), and the base func_00288960 reads a2 (stored 64-bit) and a3 (an index into D_0064D388), never a1. Defined through
// the link name so the parameter list can say so; a1's meaning is unknown (no reader).
extern "C" int Prepare__14CB3SoundESMLowFUli(CB3SoundESMLow *self, int p0, unsigned long p1, int p2)
{
    int r0 = func_00288960(self, p0, p1, p2);
    if (r0 != 0) {
        if (self->field_30 != 5) {
            for (int i = 0; ((unsigned int)i < (unsigned int)self->field_2C->field_40); i++) {
                int r1 = D_01E7569C.AllocVirtualVoice();
                self->field_60[i] = r1;
            }
            self->field_30 = 5;
        }
        self->vfunc_18();
        self->field_4.Construct();
        return 1;
    }
    return 0;
}
