// CB3SoundSkidModel::Prepare() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundSkidModel.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (do-while loops with unsigned counters; early-return bank load).

class CGtSoundBank;
class CGtSoundBankManager {
public:
    CGtSoundBank * LoadBank(const char*, bool, bool, int);
    unsigned char pad_0[0x10];
};
class CGtSoundVoiceManager {
public:
    void * AllocVirtualVoice();
    unsigned char pad_0[0x10];
};
struct UnkStruct_SK_G { unsigned char pad_0[0x48]; };
struct UnkStruct_SK_B { const char *field_0; };
extern UnkStruct_SK_G _gaSkidGraphs[];
extern UnkStruct_SK_B kpcSkidBankPath;
extern CGtSoundBankManager D_01E75648;
extern CGtSoundVoiceManager D_01E7569C;
extern "C" int FindWave__12CGtSoundBankCFRCUlb(void *, void *, bool);
class CB3SoundSkidModel {
public:
    bool Prepare();
    int field_0[3];
    int field_C[6];
    int field_24[4];
    int field_34[6];
    unsigned char pad_4C[0xC];
    CGtSoundBank *field_58;
};
// 0x0028EBE0
bool CB3SoundSkidModel::Prepare()
{
    if (field_58 == 0) {
        field_58 = D_01E75648.LoadBank(kpcSkidBankPath.field_0, true, false, 0x1800);
    }
    if (field_58 == 0) return false;
    if (field_C[0] == 0) {
        unsigned i = 0;
        do {
            field_C[i] = (int)D_01E7569C.AllocVirtualVoice();
            i++;
        } while (i < 6);
    }
    if (field_0[0] == 0) {
        unsigned i = 0;
        do {
            field_0[i] = FindWave__12CGtSoundBankCFRCUlb(field_58, &_gaSkidGraphs[i], false);
            i++;
        } while (i < 3);
    }
    unsigned i = 0;
    do {
        field_24[i] = 0;
        i++;
    } while (i < 4);
    unsigned k = 0;
    do {
        field_34[k] = 0;
        k++;
    } while (k < 6);
    return true;
}
