// CB3SoundTrafficManager::Prepare() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundTrafficManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a76: member arrays, return true).

// [C] name CB3SoundTrafficManager::Prepare() (mangled symbol); 16 CB3SoundTrafficVehicle (0x130 each at +0xF0) and 16 CB3SoundCrashedTraffic (0x5C each at +0x13F0), cf. Release() in B3SoundTrafficManager_00276D00; layout [G]. No DNAT row.
struct UnkStruct_002772D0_veh {
    unsigned char pad_0[0x130];
};

struct UnkStruct_002772D0_crash {
    unsigned char pad_0[0x5C];
};

class CB3SoundTrafficManager {
public:
    bool Prepare();

    unsigned char pad_0[0xD0];
    unsigned char field_D0;
    unsigned char field_D1;
    unsigned char field_D2;
    unsigned char pad_D3[0xF0 - 0xD3];
    UnkStruct_002772D0_veh field_F0[16];
    UnkStruct_002772D0_crash field_13F0[16];
};

extern "C" void Prepare__22CB3SoundTrafficVehicleFv(void *);  // CB3SoundTrafficVehicle::Prepare()
extern "C" void Prepare__22CB3SoundCrashedTrafficFv(void *);  // CB3SoundCrashedTraffic::Prepare()

// 0x002772D0
bool CB3SoundTrafficManager::Prepare()
{
    for (int i = 0; i < 16; i++) {
        Prepare__22CB3SoundTrafficVehicleFv(&field_F0[i]);
        Prepare__22CB3SoundCrashedTrafficFv(&field_13F0[i]);
    }
    field_D1 = 0;
    field_D2 = 0;
    field_D0 = 0;
    return true;
}
