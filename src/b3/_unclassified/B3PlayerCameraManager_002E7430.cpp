// CB3PlayerCameraManager::Destruct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3PlayerCameraManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3CameraEditor;
class CB3CrashCameraDirector;
class CB3PlayerCameraManager;

class CB3CrashCameraDirector {
public:
    void Destruct();
};

class CB3CameraEditor {
public:
    void Destruct();

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3PlayerCameraManager {
public:
    void Destruct();

    unsigned char pad_0[0x18];
    CB3CrashCameraDirector field_18;
    unsigned char pad_19[0xB77];
    int field_B90;
};

extern CB3CameraEditor D_01E86500;

extern "C" void Destruct__6CGtFSMFv(void *);  // CGtFSM::Destruct()

// 0x002E7430
void CB3PlayerCameraManager::Destruct()
{
    Destruct__6CGtFSMFv(this);
    field_18.Destruct();
    if (field_B90 == 0) {
        D_01E86500.Destruct();
    }
}
