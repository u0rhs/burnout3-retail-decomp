// CB3InputManager::AreLockedPlayersConnected() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3InputManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3InputManager;
struct UnkStruct_0022D0A0_e2;

struct UnkStruct_0022D0A0_e2 {
    unsigned char pad_0[0x12C];
};

class CB3InputManager {
public:
    int AreLockedPlayersConnected();

    UnkStruct_0022D0A0_e2 field_0[1];  // [G] element count unknown
    unsigned char pad_12C[0xE75];
    signed char field_FA1[1];  // [G] element count unknown
    unsigned char pad_FA2[0x1];
    unsigned char field_FA3[1];  // [G] element count unknown
};

extern "C" int PadIsValid__20CB3ControllerMappingFv(void *);  // CB3ControllerMapping::PadIsValid()
extern "C" int func_0012EF20(void *);

// 0x0022D0A0
int CB3InputManager::AreLockedPlayersConnected()
{
    for (signed char i = 0; (i < 2); i++) {
        if (field_FA3[i] != 0) {
            signed char t0 = field_FA1[i];
            int r0 = PadIsValid__20CB3ControllerMappingFv(((char *)&field_0[t0] + 0xD48));
            if (r0 != 0) {
                continue;
            }
            int r1 = func_0012EF20(((char *)&field_0[t0] + 0xD48));
            if (r1 != 0) {
                continue;
            }
            return 0;
        }
    }
    return 1;
}
