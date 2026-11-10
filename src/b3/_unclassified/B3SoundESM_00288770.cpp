// CB3SoundESM::ModulateRpm(CB3SoundESMGraphInputs&,const CB3RaceCar*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundESM.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (near20: CGtRandom::Random() (GtRandom.h) for _mRandom + 'const float k = 2.3283064e-10f;' (DoAggressiveHornBlast idiom) hoists the 2^-32 constant; amplitude product in its own float local for madd operand order).

#include "b3/_unclassified/GtRandom.h"
struct UnkStruct_00288480_e { unsigned char pad_0[0x14A4]; void *field_14A4; unsigned char pad_14A8[0x20]; int field_14C8; };
struct UnkStruct_00288480_ent { UnkStruct_00288480_e *field_0; unsigned char pad_4[0x2C]; };
class CB3RaceCar { public: unsigned char pad_0[0x11DE]; unsigned char field_11DE; unsigned char pad_11DF[0x7CD]; signed char field_19AC; };
class CB3SoundESMGraphInputs { public: float field_0; };
struct UnkStruct_D_0052267C { float field_0; unsigned char pad_4[12]; };
extern UnkStruct_00288480_ent D_0055EFEC[];
extern UnkStruct_D_0052267C D_0052267C;
extern float krRpmModulationMinTime;
extern float krRpmModulationMaxAmp;
extern float krRpmModulationPeriod;
extern "C" CGtRandom _mRandom__13CGtSoundUtils;
extern "C" unsigned int mguFrames__8CGtTimer;
extern "C" float sinf(float);
class CB3SoundESM {
public:
    unsigned char pad_0[0x38];
    float field_38;
    unsigned char pad_3C[0x18];
    signed char field_54;
    unsigned char pad_55[4];
    unsigned char field_59;
    void ModulateRpm(CB3SoundESMGraphInputs &, const CB3RaceCar *);
};
// 0x00288770
void CB3SoundESM::ModulateRpm(CB3SoundESMGraphInputs &in, const CB3RaceCar *car)
{
    UnkStruct_00288480_e *e = D_0055EFEC[car->field_19AC].field_0;
    if (e->field_14A4 != 0 && e->field_14C8 > field_54) {
        const float k = 2.3283064e-10f;
        float mt = krRpmModulationMinTime;
        field_38 = mt - (mt / 2.0f) * (k * (float)_mRandom__13CGtSoundUtils.Random());
    }
    float t = field_38;
    if (t > 0.0f && e->field_14A4 == 0) {
        float k;
        if (t <= krRpmModulationMinTime) k = t / krRpmModulationMinTime;
        else k = 1.0f;
        float s = sinf((float)mguFrames__8CGtTimer / krRpmModulationPeriod);
        float amp = krRpmModulationMaxAmp * k;
        in.field_0 = in.field_0 + amp * s;
        field_38 = field_38 - D_0052267C.field_0;
    }
    field_54 = e->field_14C8;
    field_59 = car->field_11DE;
}
