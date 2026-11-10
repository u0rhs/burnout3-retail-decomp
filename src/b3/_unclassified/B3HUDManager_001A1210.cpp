// CB3HUDManager::PrepareScoreList() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3HUDManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (single-case switch on field_174 (beq/nop/b-to-exit shape)).

// CB3HUDManager::PrepareScoreList() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3HUDManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

enum EHUDAlign {};

class CB3HUDEscapeDistance;
class CB3HUDManager;
class CB3HUDScoreList;
struct UnkStruct_D_0064E510;
struct UnkStruct__gTimerComponentP1;

class CB3HUDScoreList {
public:
    void ActualPrepare();

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3HUDEscapeDistance {
public:
    void Prepare(int, EHUDAlign, int);
    void ActualPrepare();

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0064E510 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct__gTimerComponentP1 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3HUDManager {
public:
    void PrepareScoreList();

    unsigned char pad_0[0x174];
    int field_174;
};

extern UnkStruct_D_0064E510 D_0064E510;
extern CB3HUDScoreList _gScoreListComponentP1;
extern CB3HUDEscapeDistance D_0066B500;
extern UnkStruct__gTimerComponentP1 _gTimerComponentP1;

extern "C" int Prepare__11CB3HUDTimerFi9EHUDAligni(void *, int, EHUDAlign, int, int);  // CB3HUDTimer::Prepare(int,EHUDAlign,int), passed 1 more argument(s) [G]

// 0x001A1210
void CB3HUDManager::PrepareScoreList()
{
    _gScoreListComponentP1.ActualPrepare();
    switch (field_174) {
    case 9:
        if (D_0064E510.field_0 != 0) {
            D_0066B500.Prepare(0, (EHUDAlign)7, 1);
            D_0066B500.ActualPrepare();
        } else {
            Prepare__11CB3HUDTimerFi9EHUDAligni(&_gTimerComponentP1, 0, (EHUDAlign)7, 1, 0);
        }
        break;
    }
}
