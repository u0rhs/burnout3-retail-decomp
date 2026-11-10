// CB3SoundESMLow::Update(const CB3RaceCar*,float,float,float) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundESM.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a122: if(field_58==0){body} return; ; outs wrapper with 16-byte tail pad).

struct UnkStruct_00287710_in { int w[7]; };
struct UnkStruct_00287710_out { unsigned char pad_0[0x50]; };
struct UnkStruct_00287710_st { unsigned char pad_0[0x40]; unsigned char field_40; };
class CB3RaceCar { public: unsigned char pad_0[0x1998]; unsigned char field_1998; };
extern "C" void Construct__22CB3SoundESMGraphInputsFPC10CB3RaceCarf(UnkStruct_00287710_in *, const CB3RaceCar *, float);
extern "C" void ApplyLag__22CB3SoundESMGraphInputsFRC22CB3SoundESMGraphInputsPC19CB3SoundESMInputLag(UnkStruct_00287710_in *, const UnkStruct_00287710_in *, void *);
extern "C" void Update__17CB3SoundESMStructCFRC22CB3SoundESMGraphInputsP23CB3SoundEsmGraphOutputs(UnkStruct_00287710_st *, const UnkStruct_00287710_in *, UnkStruct_00287710_out *);
extern "C" void Apply__23CB3SoundEsmGraphOutputsCFP20CGtSoundVirtualVoicePC10CB3RaceCarf(UnkStruct_00287710_out *, void *, const CB3RaceCar *, float);
class CB3SoundESMLow;
extern "C" void ModulateRpm__11CB3SoundESMFR22CB3SoundESMGraphInputsPC10CB3RaceCar(CB3SoundESMLow *, UnkStruct_00287710_in *, const CB3RaceCar *);
extern "C" void func_00288480(CB3SoundESMLow *, UnkStruct_00287710_in *, const CB3RaceCar *);
class CB3SoundESMLow {
public:
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    UnkStruct_00287710_in field_4;
    unsigned char pad_20[0xC];
    UnkStruct_00287710_st *field_2C;
    unsigned char pad_30[0x24];
    unsigned char field_54[3];
    unsigned char field_57;
    unsigned char field_58;
    unsigned char pad_59[7];
    void *field_60[1];
    void Update(const CB3RaceCar *, float, float, float);
};
// 0x00287710
void CB3SoundESMLow::Update(const CB3RaceCar *car, float p0, float p1, float p2)
{
    struct { UnkStruct_00287710_out a[12]; int pad[4]; } outs;
    UnkStruct_00287710_in in;
    if (car->field_1998 == 0) {
        if (field_57 != 0) vfunc_18();
        return;
    }
    if (field_57 == 0) vfunc_14();
    if (field_58 == 0) {
    Construct__22CB3SoundESMGraphInputsFPC10CB3RaceCarf(&in, car, p1);
    ApplyLag__22CB3SoundESMGraphInputsFRC22CB3SoundESMGraphInputsPC19CB3SoundESMInputLag(&in, &field_4, field_2C);
    ModulateRpm__11CB3SoundESMFR22CB3SoundESMGraphInputsPC10CB3RaceCar(this, &in, car);
    func_00288480(this, &in, car);
    Update__17CB3SoundESMStructCFRC22CB3SoundESMGraphInputsP23CB3SoundEsmGraphOutputs(field_2C, &in, outs.a);
    for (unsigned int i = 0; i < field_2C->field_40; i++) {
        Apply__23CB3SoundEsmGraphOutputsCFP20CGtSoundVirtualVoicePC10CB3RaceCarf(&outs.a[i], field_60[i], car, p0);
    }
    field_4 = in;
    }
    return;
}
