// CB3SoundTurboModel::Prepare(const char*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundTurboModel.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (field_0 is a CGtSoundBank* (LoadBank result), tested with !field_0 (== 0 flips the layout); FindWave as a member call on a >8-byte D_004C0920).

class CB3SoundTurboModel;
class CGtSoundBank;
class CGtSoundBankManager;
class CGtSoundVirtualVoice;

class CGtSoundVirtualVoice {
public:
    void Stop();

    unsigned char pad_0[0xC];
    int field_C;
};

class CGtSoundBank {
public:
    int FindWave(const unsigned long&, bool) const;
};

class CGtSoundBankManager {
public:
    CGtSoundBank * LoadBank(const char*, bool, bool, int);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3SoundTurboModel {
public:
    int Prepare(const char* p0);

    CGtSoundBank * field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    CGtSoundVirtualVoice * field_14;
};

extern CGtSoundBankManager D_01E75648;
extern unsigned long D_004C0920[2];  // [G] 64-bit wave id(s) (FindWave takes const unsigned long&); size > 8 (absolute addressing, N50)

// 0x0028FE70
int CB3SoundTurboModel::Prepare(const char* p0)
{
    if (!field_0 && p0) {
        field_0 = D_01E75648.LoadBank(p0, 1, 0, 6144);
        if (!field_0) {
            return 0;
        }
        field_4 = field_0->FindWave(D_004C0920[0], 0);
    }
    field_8 = 0;
    field_C = 0;
    if (field_14 != 0 && field_10 == field_14->field_C) {
        field_14->Stop();
        field_14 = 0;
    }
    return 1;
}
