// CB3EffectsManager::RenderTrafficImmediateEffects(CB3TrafficVehicle*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3EffectsManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (a244: extern C link-name with const param (N206 sd-ra-after-load)).

// CB3EffectsManager::RenderTrafficImmediateEffects(CB3TrafficVehicle*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3EffectsManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3TrafficVehicle;

class CB3EffectsManager;
struct CB3TrafficVehicle;

struct CB3TrafficVehicle {
    unsigned char pad_0[0x58];
    unsigned char field_58;
};

class CB3EffectsManager {
public:
// 0x002621A0
    void RenderTrafficImmediateEffects(CB3TrafficVehicle* p0);
};

extern "C" void RenderLightCoronas__17CB3EffectsManagerFRC25CB3VehicleEssentialParamsb(void *, const void *, bool);  // CB3EffectsManager::RenderLightCoronas(const CB3VehicleEssentialParams&,bool)

struct UnkStruct_002621A0_pad {
    unsigned char field_0[0x4];
    UnkStruct_002621A0_pad() {}
    ~UnkStruct_002621A0_pad() {}
};

// [G] extern "C" link-name with a const parameter: retail loads field_58 before `sd ra` (const loads, N206); the member form with the mangled non-const signature cannot express that.
extern "C" void RenderTrafficImmediateEffects__17CB3EffectsManagerFP17CB3TrafficVehicle(CB3EffectsManager *self, const CB3TrafficVehicle *p0)
{
    UnkStruct_002621A0_pad pad;
    if (p0->field_58 != 0) {
        RenderLightCoronas__17CB3EffectsManagerFRC25CB3VehicleEssentialParamsb(self, (void*)p0, 0);
    }
}
