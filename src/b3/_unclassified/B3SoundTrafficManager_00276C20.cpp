// CB3SoundTrafficManager::CrashingTraffic(CB3VehiclePhysics*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundTrafficManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a70: 16-entry CB3SoundCrashedTraffic array (0x5C stride), constant -1 in its own local declared before first, if(i>=16){SetOwner path}else{SetActive}).

// CB3SoundTrafficManager::CrashingTraffic(CB3VehiclePhysics*)
class CB3VehiclePhysics;

class CB3SoundCrashedTraffic {
public:
    void SetActive();
    void SetOwner(CB3VehiclePhysics * p0);

    CB3VehiclePhysics * field_0;
    unsigned char pad_4[0x58];
};

class CB3SoundTrafficManager {
public:
    void CrashingTraffic(CB3VehiclePhysics * p0);

    unsigned char pad_0[0x13F0];
    CB3SoundCrashedTraffic field_13F0[16];
};

// 0x00276C20
void CB3SoundTrafficManager::CrashingTraffic(CB3VehiclePhysics * p0)
{
    int i;
    int none = -1;
    int first = -1;
    for (i = 0; i < 16; i++) {
        CB3VehiclePhysics * owner = field_13F0[i].field_0;
        if (owner == p0) {
            break;
        }
        if (first == none && owner == 0) {
            first = i;
        }
    }
    if (i >= 16) {
        if (first != -1 && first < 16) {
            field_13F0[first].SetOwner(p0);
        }
    } else {
        field_13F0[i].SetActive();
    }
}
