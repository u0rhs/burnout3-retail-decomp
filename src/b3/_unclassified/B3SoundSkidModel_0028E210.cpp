// CB3SoundSkidModel::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundSkidModel.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a72: guarded voice loop do-while, then zero loop do-while, bank unload; extern structs >8 bytes (no gp-rel)).

class CGtSoundBank;
class CB3SoundSkidModel;

class CB3SoundSkidModel {
public:
    void Release();

    int field_0[3];
    int field_C[6];
    unsigned char pad_24[0x34];
    CGtSoundBank * field_58;
};

struct UnkStruct_D_01E75648 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E7569C { unsigned char pad_0[0x10]; };
extern UnkStruct_D_01E75648 D_01E75648;
extern UnkStruct_D_01E7569C D_01E7569C;

extern "C" int IsPlaying__20CGtSoundVirtualVoiceFv(void *);
extern "C" void Stop__20CGtSoundVirtualVoiceFv(void *);
extern "C" void FreeVirtualVoice__20CGtSoundVoiceManagerFP20CGtSoundVirtualVoice(void *, void *);
extern "C" void UnloadBank__19CGtSoundBankManagerFP12CGtSoundBank(void *, CGtSoundBank *);

// 0x0028E210
void CB3SoundSkidModel::Release()
{
    if (field_C[0] != 0) {
        unsigned int j = 0;
        do {
            int * p = &field_C[j];
            if (IsPlaying__20CGtSoundVirtualVoiceFv((void *)*p) != 0) {
                Stop__20CGtSoundVirtualVoiceFv((void *)*p);
            }
            FreeVirtualVoice__20CGtSoundVoiceManagerFP20CGtSoundVirtualVoice(&D_01E7569C, (void *)*p);
            *p = 0;
            j++;
        } while (j < 6);
    }
    unsigned int i = 0;
    do {
        field_0[i] = 0;
        i++;
    } while (i < 3);
    if (field_58 != 0) {
        UnloadBank__19CGtSoundBankManagerFP12CGtSoundBank(&D_01E75648, field_58);
        field_58 = 0;
    }
}
