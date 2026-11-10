// CB3SoundESMHigh::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundESM.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (field_28 typed CGtSoundBank* and tested/passed directly (int field + cast tail-duplicated the stores)).

// CB3SoundESMHigh::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundESM.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtSoundRealVoice;
class CGtSoundVirtualVoice;
class CGtSoundBank;

class CB3SoundESMHigh;
class CGtSoundBankManager;
class CGtSoundVoiceManager;
struct UnkStruct_00287E20_1;
struct UnkStruct_00287E20_e0;

class CGtSoundVoiceManager {
public:
    void FreeRealVoice(CGtSoundRealVoice*);
    void FreeVirtualVoice(CGtSoundVirtualVoice*);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CGtSoundBankManager {
public:
    void UnloadBank(CGtSoundBank*);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00287E20_1 {
    unsigned char pad_0[0x3C];
    UnkStruct_00287E20_e0 * field_3C;
    unsigned char field_40;
};

struct UnkStruct_00287E20_e0 {
    unsigned char pad_0[0xD];
    unsigned char field_D;
    unsigned char pad_E[0x2];
};

class CB3SoundESMHigh {
public:
    void Release();

    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    unsigned char pad_4[0x24];
    CGtSoundBank * field_28;  // [G] pointer type: an int field cast at the call tail-duplicates the following stores
    UnkStruct_00287E20_1 * field_2C;
    int field_30;
    unsigned char pad_34[0x2C];
    int field_60[1];  // [G] element count unknown
    unsigned char pad_64[0x2C];
    int field_90;
};

extern CGtSoundVoiceManager D_01E7569C;
extern CGtSoundBankManager D_01E75648;

// 0x00287E20
void CB3SoundESMHigh::Release()
{
    vfunc_18();
    int m0 = 0;
    while ((unsigned int)m0 < (unsigned int)field_2C->field_40) {
        switch ((field_2C->field_3C[m0].field_D & 15)) {
        case 0:
            int t0 = field_60[m0];
            if (t0 != 0) {
                D_01E7569C.FreeRealVoice((CGtSoundRealVoice*)t0);
                field_60[m0] = 0;
            }
            break;
        case 1:
            break;
        case 2:
            int t1 = field_90;
            if (t1 != 0) {
                D_01E7569C.FreeVirtualVoice((CGtSoundVirtualVoice*)t1);
                field_90 = 0;
            }
            break;
        default:
            break;
        }
        m0 = (m0 + 1);
    }
    if (field_28 != 0) {
        D_01E75648.UnloadBank(field_28);
        field_28 = 0;
    }
    field_2C = 0;
    field_30 = 0;
}
