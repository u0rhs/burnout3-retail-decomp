// CB3SoundAICar::Update(const CB3RaceCar*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundAICar.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (near3 match; pad renamed to UnkStruct_0028BBC0_pad (drop_pad_dtor pattern)).



// lifter variant 0
// CB3SoundAICar::Update(const CB3RaceCar*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundAICar.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3RaceCar;

class CB3SoundAICar;
class CGtSoundVirtualVoice;
struct CB3RaceCar;
struct UnkStruct_0028BBC0_8;
struct UnkStruct_0028BBC0_e0;
struct UnkStruct_0028BBC0_e1;
struct UnkStruct_0028BBC0_e2;
struct UnkStruct_D_00522660;
struct UnkStruct_D_0055EFEC;
struct UnkStruct_D_0064D3A0;

class CGtSoundVirtualVoice {
public:
    void ForgetMe(float);
};

struct UnkStruct_D_0064D3A0 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0028BBC0_e0 {
    unsigned char pad_0[0x1CBA];
    unsigned char field_1CBA;
    unsigned char pad_1CBB[0xB15];
};

struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x12A980];
    UnkStruct_0028BBC0_e0 field_12A980[1];  // [G] element count unknown
};

struct CB3RaceCar {
    unsigned char pad_0[0x19AC];
    signed char field_19AC;
};

struct UnkStruct_0028BBC0_e1 {
    UnkStruct_0028BBC0_8 * field_0;
    unsigned char pad_4[0x2C];
};

struct UnkStruct_D_0055EFEC {
    UnkStruct_0028BBC0_e1 field_0[1];  // [G] element count unknown
};

struct UnkStruct_0028BBC0_e2 {
    unsigned char pad_0[0x93];
    unsigned char field_93;
    unsigned char pad_94[0x2C];
};

struct UnkStruct_0028BBC0_8 {
    unsigned char pad_0[0x198];
    int field_198;
    unsigned char pad_19C[0x6A4];
    UnkStruct_0028BBC0_e2 field_840[1];  // [G] element count unknown
};

struct UnkStruct_0028BBC0_pad { unsigned char field_0[0x10]; UnkStruct_0028BBC0_pad() {} ~UnkStruct_0028BBC0_pad() {} };
class CB3SoundAICar {
public:
    void Update(const CB3RaceCar* p0);
    void StartBassVoices();
    void UpdateBassVoices(const CB3RaceCar*);

    unsigned char pad_0[0x140];
    int field_140;
    unsigned char pad_144[0xC];
    CGtSoundVirtualVoice * field_150;
    CGtSoundVirtualVoice * field_154;
    int field_158;
    int field_15C;
};

extern UnkStruct_D_0064D3A0 D_0064D3A0;
extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_D_0055EFEC D_0055EFEC;

extern "C" void func_0028D830(CB3SoundAICar *, const CB3RaceCar *);

// 0x0028BBC0
void CB3SoundAICar::Update(const CB3RaceCar* p0)
{
    UnkStruct_0028BBC0_pad pad;
    bool m0 = false;
    func_0028D830(this, p0);
    int t0 = D_0064D3A0.field_0;
    for (int i = 0; (i < t0); i++) {
        bool v1 = true;
        if (!m0) {
            if (D_00522660.field_12A980[i].field_1CBA == 0) {
                v1 = false;
            }
        }
        m0 = v1;
    }
    if (!m0) {
        signed char t3 = p0->field_19AC;
        UnkStruct_0028BBC0_8 * t4 = D_0055EFEC.field_0[t3].field_0;
        int m1 = 0;
        for (int i1 = 0; (i1 < 4); i1++) {
            if (t4->field_840[i1].field_93 != 0) {
                m1 = (m1 + 1);
            }
        }
        int v8 = m1;
        if (t4->field_198 != 0) {
            v8 = 4;
        }
        if (v8 == 0) {
            field_140 = (field_140 + 1);
            if (field_140 >= 5) {
                if (field_150 == 0) {
                    StartBassVoices();
                } else {
                    UpdateBassVoices(p0);
                }
            }
        } else {
            field_140 = 0;
            CGtSoundVirtualVoice * t5 = field_150;
            if (t5 != 0) {
                t5->ForgetMe(0.5f);
                field_150 = 0;
                field_158 = 0;
            }
            CGtSoundVirtualVoice * t6 = field_154;
            if (t6 != 0) {
                t6->ForgetMe(0.5f);
                field_154 = 0;
                field_15C = 0;
            }
            field_140 = 0;
        }
    } else {
            field_140 = 0;
            CGtSoundVirtualVoice * t1 = field_150;
            if (t1 != 0) {
                t1->ForgetMe(0.5f);
                field_150 = 0;
                field_158 = 0;
            }
            CGtSoundVirtualVoice * t2 = field_154;
            if (t2 != 0) {
                t2->ForgetMe(0.5f);
                field_154 = 0;
                field_15C = 0;
            }
            field_140 = 0;
    }
}
