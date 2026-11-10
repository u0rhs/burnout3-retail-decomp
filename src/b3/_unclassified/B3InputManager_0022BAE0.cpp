// CB3InputManager::GetDeadInputTime(signed char) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3InputManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (local CB3ControllerMapping*[2]; min initialised before the GetAvailableControllers call; index the array directly).

// lifter variant 0
// CB3InputManager::GetDeadInputTime(signed char) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3InputManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3ControllerMapping;

class CB3ControllerMapping;
class CB3InputManager;
struct UnkStruct_0022BAE0_0;

class CB3ControllerMapping {
public:
    float GetControllerDeadTime();
};

struct UnkStruct_0022BAE0_0 {
    CB3ControllerMapping * field_0[1];  // [G] element count unknown
    unsigned char pad_4[0x4];
};

class CB3InputManager {
public:
    float GetDeadInputTime(signed char p0);
    void GetAvailableControllers(CB3ControllerMapping**, signed char);
};

float CB3InputManager::GetDeadInputTime(signed char p0)
{
    CB3ControllerMapping * local[2];
    float m0 = 100000000;
    GetAvailableControllers(local, p0);
    for (signed char i = 0; i < 2; i++) {
        if (local[i] != 0) {
            float r1 = local[i]->GetControllerDeadTime();
            if (r1 < m0) {
                m0 = r1;
            }
        }
    }
    return m0;
}
