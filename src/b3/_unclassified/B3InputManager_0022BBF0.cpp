// CB3InputManager::GenericPrepare() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3InputManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3InputManager;
struct UnkStruct_0022BBF0_e0;

struct UnkStruct_0022BBF0_e0 {
    unsigned char pad_0[0x12C];
};

class CB3InputManager {
public:
    int GenericPrepare();

    UnkStruct_0022BBF0_e0 field_0[1];  // [G] element count unknown
};

extern "C" void Prepare__20CB3ControllerMappingFv(void *);  // CB3ControllerMapping::Prepare()

// 0x0022BBF0
int CB3InputManager::GenericPrepare()
{
    int m0 = 0;
    do {
        Prepare__20CB3ControllerMappingFv(((char *)&field_0[((signed char)m0)] + 0xD48));
        m0 = ((signed char)(m0 + 1));
    } while (m0 < 2);
    return 1;
}
