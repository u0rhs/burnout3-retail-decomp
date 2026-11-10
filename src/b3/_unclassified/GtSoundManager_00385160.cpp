// CGtSoundManager::Construct(CGtSoundManagerConstructParams*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (char-array members stop CSE of this+0x48; three if(G==-1)G=0).

struct CGtSoundManagerConstructParams {
    int field_0; int field_4; int field_8; int field_C; int field_10; int field_14;
};
extern "C" void Construct__23CGtSoundListenerManagerFP13RwaSPU2Output(void *, void *);
extern "C" void Construct__20CGtSoundVoiceManagerFP13RwaSPU2OutputP24CGtSoundRealVoiceDSPSendiP23CGtSoundListenerManager(void *, void *);
extern "C" void Construct__19CGtSoundBankManagerFP13RwaSPU2OutputiP24CGtSoundWaveObjectBuffer(void *, void *, int, void *);
extern "C" void Construct__21CGtSoundStreamManagerFP13RwaSPU2Outputii(void *, void *, int, int);
extern "C" void func_00387240(void *);
extern int D_004E1E54;
extern int D_004E1E58;
extern int D_004E1E5C;
class CGtSoundManager {
public:
    void Construct(CGtSoundManagerConstructParams *p0);
    unsigned char pad_0[0x8];
    unsigned char field_8[0x40];
    unsigned char field_48[0x14];
    unsigned char field_5C[0x1E44];
    unsigned char field_1EA0[0x34];
    unsigned char field_1ED4[4];
    int field_1ED8;
    int field_1EDC;
    unsigned char pad_1EE0[1];
    unsigned char field_1EE1;
};
// 0x00385160
void CGtSoundManager::Construct(CGtSoundManagerConstructParams *p0)
{
    Construct__23CGtSoundListenerManagerFP13RwaSPU2Output(field_48, (void *)(field_1ED8));
    p0->field_10 = field_1ED8;
    p0->field_14 = (int)(field_48);
    Construct__20CGtSoundVoiceManagerFP13RwaSPU2OutputP24CGtSoundRealVoiceDSPSendiP23CGtSoundListenerManager(field_5C, &p0->field_10);
    Construct__19CGtSoundBankManagerFP13RwaSPU2OutputiP24CGtSoundWaveObjectBuffer(field_8, (void *)(field_1ED8), p0->field_0, (void *)(p0->field_4));
    Construct__21CGtSoundStreamManagerFP13RwaSPU2Outputii(field_1EA0, (void *)(field_1ED8), p0->field_8, p0->field_C);
    func_00387240(field_1ED4);
    field_1EDC = 1;
    field_1EE1 = 0;
    if (D_004E1E54 == -1) D_004E1E54 = 0;
    if (D_004E1E58 == -1) D_004E1E58 = 0;
    if (D_004E1E5C == -1) D_004E1E5C = 0;
}
