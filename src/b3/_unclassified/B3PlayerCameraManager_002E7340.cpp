// CB3PlayerCameraManager::IsPlayerVisible() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3PlayerCameraManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (bool return; merged bool b from nested int c = ((f&K)!=0)^1 tests, copied to vis; field_9E8 read into a local before the call).

// lifter variant 0
// CB3PlayerCameraManager::IsPlayerVisible() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3PlayerCameraManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3BehaviourInterpolate;
class CB3PlayerCameraManager;

class CB3BehaviourInterpolate {
public:
    float GetTimeElapsed();
};

class CB3PlayerCameraManager {
public:
    bool IsPlayerVisible();

    unsigned char pad_0[0x8C0];
    CB3BehaviourInterpolate field_8C0;
    unsigned char pad_8C1[0x127];
    float field_9E8;
    unsigned char pad_9EC[0x4];
    int field_9F0;
    int field_9F4;
    unsigned char pad_9F8[0x188];
    unsigned long field_B80;
};

// 0x002E7340
bool CB3PlayerCameraManager::IsPlayerVisible()
{
    unsigned long f = field_B80;
    bool b = false;
    int c = ((f & 16) != 0) ^ 1;
    if (c) {
        c = ((f & 32) != 0) ^ 1;
        if (c) b = true;
    }
    bool vis = b;
    if (vis && (f & 1024) != 0) {
        if (field_9F0 == 4 || field_9F0 == 5) {
            if (field_8C0.GetTimeElapsed() < 0.2f) {
                vis = false;
            }
        }
        if (field_9F4 == 4 || field_9F4 == 5) {
            float t = field_9E8;
            if (t - field_8C0.GetTimeElapsed() < 0.2f) {
                vis = false;
            }
        }
    }
    return vis;
}
