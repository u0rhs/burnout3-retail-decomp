// CB3SoundPlayerCar::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundPlayerCar.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (re-read field_15C[i] each use instead of a cached local).

// CB3SoundPlayerCar::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundPlayerCar.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3SoundPlayerCar;
class CB3SoundTurboModel;
class CGtSoundVirtualVoice;

class CGtSoundVirtualVoice {
public:
    void Stop();
};

class CB3SoundTurboModel {
public:
    void Release();
};

class CB3SoundPlayerCar {
public:
    void Release();

    unsigned char pad_0[0x144];
    CB3SoundTurboModel field_144;
    unsigned char pad_145[0x17];
    CGtSoundVirtualVoice * field_15C[1];  // [G] element count unknown
    unsigned char pad_160[0xC];
    int field_16C[1];  // [G] element count unknown
};

extern "C" void Release__15CB3SoundRaceCarFv(void *);  // CB3SoundRaceCar::Release()

// 0x0028CA80
void CB3SoundPlayerCar::Release()
{
    for (int i = 0; (i < 4); i++) {
        field_16C[i] = 0;
        if (field_15C[i] != 0) {
            field_15C[i]->Stop();
            field_15C[i] = 0;
        }
    }
    field_144.Release();
    Release__15CB3SoundRaceCarFv(this);
}
