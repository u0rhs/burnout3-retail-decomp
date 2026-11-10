// CB3HUDManager::PrepareCrashComponents() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3HUDManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a93: jump-table switch, first case returns).

enum EHUDAlign {};
struct UnkStruct_Crash_obj { unsigned char pad_0[0x30]; };
extern UnkStruct_Crash_obj _gCrashHeading;
extern UnkStruct_Crash_obj _gCrashComboComponent;
extern UnkStruct_Crash_obj _gImpactTime;
extern UnkStruct_Crash_obj _gCrashStyleComponentP1;
extern UnkStruct_Crash_obj D_0066C0A0;
extern "C" int func_003D2EA0(void *, int, int, int);
extern "C" int Prepare__16CB3HUDCrashComboFi9EHUDAligni(void *, int, EHUDAlign, int);
extern "C" int Prepare__16CB3HUDImpactTimeFi9EHUDAligni(void *, int, EHUDAlign, int);
extern "C" int Prepare__16CB3HUDCrashStyleFi9EHUDAligni(void *, int, EHUDAlign, int);

class CB3HUDManager {
public:
    void PrepareCrashComponents();

    unsigned char pad_0[0x174];
    unsigned int field_174;
};

// 0x001A09A0
void CB3HUDManager::PrepareCrashComponents()
{
    switch (field_174) {
    case 1:
    case 4:
    case 5:
    case 6:
    case 7:
        func_003D2EA0(&_gCrashHeading, 0, 0, 6);
        Prepare__16CB3HUDCrashComboFi9EHUDAligni(&_gCrashComboComponent, 0, (EHUDAlign)8, 2);
        Prepare__16CB3HUDImpactTimeFi9EHUDAligni(&_gImpactTime, 0, (EHUDAlign)7, 2);
        return;
    case 3:
    case 9:
        func_003D2EA0(&_gCrashHeading, 0, 0, 6);
        Prepare__16CB3HUDCrashComboFi9EHUDAligni(&_gCrashComboComponent, 0, (EHUDAlign)8, 2);
        break;
    case 10:
    case 11:
    case 12:
        Prepare__16CB3HUDImpactTimeFi9EHUDAligni(&_gImpactTime, 0, (EHUDAlign)7, 2);
        Prepare__16CB3HUDCrashStyleFi9EHUDAligni(&_gCrashStyleComponentP1, 0, (EHUDAlign)3, 2);
        break;
    case 13:
    case 15:
        Prepare__16CB3HUDCrashStyleFi9EHUDAligni(&_gCrashStyleComponentP1, 0, (EHUDAlign)3, 2);
        break;
    case 14:
        Prepare__16CB3HUDCrashStyleFi9EHUDAligni(&_gCrashStyleComponentP1, 0, (EHUDAlign)3, 2);
        Prepare__16CB3HUDCrashStyleFi9EHUDAligni(&D_0066C0A0, 1, (EHUDAlign)3, 2);
        break;
    case 0:
    case 2:
    case 8:
        break;
    }
}
