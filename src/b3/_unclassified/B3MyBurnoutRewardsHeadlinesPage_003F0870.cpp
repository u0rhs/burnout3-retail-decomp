// CB3MyBurnoutRewardsHeadlinesPage::Update() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3MyBurnoutRewardsHeadlinesPage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (early-return chain; explicit trailing return; inside the last if; vcall through cast pointer (no devirtualisation)).

enum EB3MenuFlowFSMEvents {};
enum EB3RewardPageType {};
enum EB3RewardImageType {};

class CB3InputManager;
class CB3MyBurnoutRewardsHeadlinesPage;
struct UnkStruct_003F0870_3;
struct UnkStruct_D_01E7A800;
struct UnkStruct_D_01E89788;
struct UnkStruct_D_01E8E7A0;
struct UnkStruct_D_01E8EC30;
struct UnkStruct_D_01E90240;
struct UnkStruct_D_01E90424;

class CB3InputManager {
public:
    int GetMenuBack(signed char);
    int GetMenuUp(signed char);
    int GetMenuDown(signed char);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E90424 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8E7A0 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003F0870_3 {
    unsigned char pad_0[0xC];
    int field_C;
};

struct UnkStruct_D_01E90240 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8EC30 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E7A800 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E89788 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3MyBurnoutRewardsHeadlinesPage {
public:
    void Update();

    unsigned char pad_0[0x4];
    int field_4;
};

extern UnkStruct_D_01E90424 D_01E90424;
extern UnkStruct_D_01E8E7A0 D_01E8E7A0;
extern CB3InputManager D_004F50C0;
extern UnkStruct_D_01E90240 D_01E90240;
extern UnkStruct_D_01E8EC30 D_01E8EC30;
extern UnkStruct_D_01E7A800 D_01E7A800;
extern UnkStruct_D_01E89788 D_01E89788;

extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);  // CB3MenuPageManager::StartLeadOut(EB3MenuFlowFSMEvents), passed 1 more argument(s) [G]
extern "C" void FEVerticalMove__18CB3HUDSoundManagerFv(void *, int);  // CB3HUDSoundManager::FEVerticalMove(), passed 1 more argument(s) [G]
extern "C" bool Prepare__23CB3RewardImageComponentF17EB3RewardPageType18EB3RewardImageTypei(void *, EB3RewardPageType, EB3RewardImageType, int, int);  // CB3RewardImageComponent::Prepare(EB3RewardPageType,EB3RewardImageType,int), passed 1 more argument(s) [G]
extern "C" void SetString__19CB3HelpBarComponentFPCUsbbf(void *, const unsigned short*, bool, bool, float);  // CB3HelpBarComponent::SetString(const unsigned short*,bool,bool,float)
extern "C" int func_0042C270(void *);
extern "C" int func_0042BC70(void *);
extern "C" void func_0042C090(void *);
extern "C" int func_0042B6A0(void *, int);
extern "C" int GetLockedRewardString__23CB3RewardImageComponentF18EB3RewardImageTypei(void *, int, int);
extern "C" int func_003F64D0(void *, int, int);
extern "C" int func_0042C240(void *);
extern "C" void func_0042C020(void *);

// 0x003F0870
void CB3MyBurnoutRewardsHeadlinesPage::Update()
{
    if (D_01E90424.field_0 != 5) return;
    if (D_004F50C0.GetMenuBack(0) != 0) {
        StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)3, 0);
        return;
    }
    if (D_004F50C0.GetMenuUp(0) != 0) {
        if (func_0042C240(&D_01E8EC30) != 0) {
            FEVerticalMove__18CB3HUDSoundManagerFv(&D_01E7A800, 1);
            int n = func_0042BC70(&D_01E8EC30) - 1;
            func_0042C020(&D_01E8EC30);
            ((UnkStruct_D_01E8E7A0 *)&D_01E8E7A0)->vfunc_C();
            const unsigned short * str;
            if (func_0042B6A0(&D_01E8EC30, n) != 0) {
                Prepare__23CB3RewardImageComponentF17EB3RewardPageType18EB3RewardImageTypei(&D_01E8E7A0, (EB3RewardPageType)0, (EB3RewardImageType)field_4, n, 0);
                str = (const unsigned short *)func_003F64D0(&D_01E8E7A0, field_4, n);
            } else {
                Prepare__23CB3RewardImageComponentF17EB3RewardPageType18EB3RewardImageTypei(&D_01E8E7A0, (EB3RewardPageType)0, (EB3RewardImageType)field_4, n, 1);
                str = (const unsigned short *)GetLockedRewardString__23CB3RewardImageComponentF18EB3RewardImageTypei(&D_01E8E7A0, field_4, n);
            }
            SetString__19CB3HelpBarComponentFPCUsbbf(&D_01E89788, str, 1, 0, 80.0f);
        }
        return;
    }
    if (D_004F50C0.GetMenuDown(0) != 0) {
        if (func_0042C270(&D_01E8EC30) != 0) {
            FEVerticalMove__18CB3HUDSoundManagerFv(&D_01E7A800, 1);
            int n = func_0042BC70(&D_01E8EC30) + 1;
            func_0042C090(&D_01E8EC30);
            ((UnkStruct_D_01E8E7A0 *)&D_01E8E7A0)->vfunc_C();
            const unsigned short * str;
            if (func_0042B6A0(&D_01E8EC30, n) != 0) {
                Prepare__23CB3RewardImageComponentF17EB3RewardPageType18EB3RewardImageTypei(&D_01E8E7A0, (EB3RewardPageType)0, (EB3RewardImageType)field_4, n, 0);
                str = (const unsigned short *)func_003F64D0(&D_01E8E7A0, field_4, n);
            } else {
                Prepare__23CB3RewardImageComponentF17EB3RewardPageType18EB3RewardImageTypei(&D_01E8E7A0, (EB3RewardPageType)0, (EB3RewardImageType)field_4, n, 1);
                str = (const unsigned short *)GetLockedRewardString__23CB3RewardImageComponentF18EB3RewardImageTypei(&D_01E8E7A0, field_4, n);
            }
            SetString__19CB3HelpBarComponentFPCUsbbf(&D_01E89788, str, 1, 0, 80.0f);
        }
        return;
    }
}
