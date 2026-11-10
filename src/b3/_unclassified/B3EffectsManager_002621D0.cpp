// CB3EffectsManager::ActuallyRenderRaceCarImmediateEffects(CB3RaceCar*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3EffectsManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (func_00257230 takes p0 (a1 live); field_18F0 is bool (no sltu)).

// CB3EffectsManager::ActuallyRenderRaceCarImmediateEffects(CB3RaceCar*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3EffectsManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3RaceCar;

class CB3EffectsManager;
struct CB3RaceCar;

struct CB3RaceCar {
    unsigned char pad_0[0x58];
    unsigned char field_58;
    unsigned char pad_59[0x1891];
    unsigned char field_18EA;
    unsigned char pad_18EB[0x5];
    bool field_18F0;
};

class CB3EffectsManager {
public:
    void ActuallyRenderRaceCarImmediateEffects(CB3RaceCar* p0);
};

extern "C" void RenderLightCoronas__17CB3EffectsManagerFRC25CB3VehicleEssentialParamsb(void *, const void *, bool);  // CB3EffectsManager::RenderLightCoronas(const CB3VehicleEssentialParams&,bool)
extern "C" void func_00257230(CB3EffectsManager *, CB3RaceCar *);

struct UnkStruct_002621D0_pad {
    unsigned char field_0[0x4];
    UnkStruct_002621D0_pad() {}
    ~UnkStruct_002621D0_pad() {}
};

// 0x002621D0
void CB3EffectsManager::ActuallyRenderRaceCarImmediateEffects(CB3RaceCar* p0)
{
    UnkStruct_002621D0_pad pad;  // [G] an unused local object: retail's frame keeps 0x10 unused bytes at its top (a scoped object with a constructor/destructor reserves its slot, known.md N140)
    if (p0->field_58 != 0) {
        RenderLightCoronas__17CB3EffectsManagerFRC25CB3VehicleEssentialParamsb(this, p0, p0->field_18F0);
    }
    if (p0->field_18EA == 0) {
        func_00257230(this, p0);
    }
}
