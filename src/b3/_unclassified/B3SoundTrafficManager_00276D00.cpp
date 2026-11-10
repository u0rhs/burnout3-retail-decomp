// CB3SoundTrafficManager::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundTrafficManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3SoundTrafficManager;
struct UnkStruct_00276D00_e0;
struct UnkStruct_00276D00_e1;

struct UnkStruct_00276D00_e0 {
    unsigned char pad_0[0x130];
};

struct UnkStruct_00276D00_e1 {
    unsigned char pad_0[0x5C];
};

class CB3SoundTrafficManager {
public:
    void Release();

    UnkStruct_00276D00_e0 field_0[1];  // [G] element count unknown
};

extern "C" void Release__22CB3SoundTrafficVehicleFv(void *);  // CB3SoundTrafficVehicle::Release()
extern "C" void Release__22CB3SoundCrashedTrafficFv(void *);  // CB3SoundCrashedTraffic::Release()

// 0x00276D00
void CB3SoundTrafficManager::Release()
{
    for (int i = 0; (i < 16); i++) {
        Release__22CB3SoundTrafficVehicleFv(((char *)&field_0[i] + 0xF0));
        Release__22CB3SoundCrashedTrafficFv(((char *)((char *)this + ((i * 23) << 2)) + 0x13F0));
    }
}
