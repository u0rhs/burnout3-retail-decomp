// CB3MyBurnoutRewardsState::Action(EGtStateAction,void*,void*,void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3MyBurnoutRewardsState.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (nested switch in source order with default first; phantom args dropped (Prepare, func_003F2620/0700, GetStateFromID__6CGtFSMFUl); swap block reads D_01EA2980 after the D_01EA2974 store).

// CB3MyBurnoutRewardsState::Action(EGtStateAction,void*,void*,void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3MyBurnoutRewardsState.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

enum EGtStateAction {};
enum EB3RewardImageType {};

class CB3MyBurnoutRewardsState;
struct UnkStruct_003EC240_5;
struct UnkStruct_003EC240_7;
struct UnkStruct_003EC240_8;
struct UnkStruct_D_01E95C74;
struct UnkStruct_D_01E95CA8;
struct UnkStruct_D_01E95CB8;
struct UnkStruct_D_01E95CD0;
struct UnkStruct_D_01EA2970;
struct UnkStruct_D_01EA2974;
struct UnkStruct_D_01EA2980;
struct UnkStruct_D_01EA2984;

struct UnkStruct_D_01E95C74 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA2974 {
    void * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA2970 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18(UnkStruct_003EC240_7 *, int);
    virtual void vfunc_1C(void *, int);
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA2980 {
    UnkStruct_003EC240_5 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003EC240_5 {
    unsigned char pad_0[0x20];
    float field_20;
};

struct UnkStruct_D_01EA2984 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003EC240_7 {
    unsigned char pad_0[0x8];
    float field_8;
};

struct UnkStruct_003EC240_8 {
    unsigned char pad_0[0x1C];
    int field_1C;
};

struct UnkStruct_D_01E95CD0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E95CA8 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E95CB8 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3MyBurnoutRewardsState {
public:
    void Action(EGtStateAction p0, void* p1, void* p2, void* p3);

    unsigned char pad_0[0x10];
    int field_10;
};

extern UnkStruct_D_01E95C74 D_01E95C74;
extern UnkStruct_D_01EA2974 D_01EA2974;
extern UnkStruct_D_01EA2970 D_01EA2970;
extern UnkStruct_D_01EA2980 D_01EA2980;
extern UnkStruct_D_01EA2984 D_01EA2984;
extern UnkStruct_D_01E95CD0 D_01E95CD0;
extern UnkStruct_D_01E95CA8 D_01E95CA8;
extern UnkStruct_D_01E95CB8 D_01E95CB8;

extern "C" void Prepare__32CB3MyBurnoutRewardsHeadlinesPageF18EB3RewardImageType(void *, EB3RewardImageType);  // CB3MyBurnoutRewardsHeadlinesPage::Prepare(EB3RewardImageType)
extern "C" int func_003F2620(void *);
extern "C" int func_003F0700(void *);
extern "C" UnkStruct_003EC240_7 * GetStateFromID__6CGtFSMFUl(void *, unsigned long);

void CB3MyBurnoutRewardsState::Action(EGtStateAction p0, void* p1, void* p2, void* p3)
{
    switch (p0) {
    default:
        break;
    case 0:
        switch (D_01E95C74.field_0) {
        case 0:
            func_003F2620(&D_01E95CA8);
            break;
        case 1:
            func_003F0700(&D_01E95CB8);
            break;
        case 2:
            Prepare__32CB3MyBurnoutRewardsHeadlinesPageF18EB3RewardImageType(&D_01E95CD0, (EB3RewardImageType)2);
            break;
        case 3:
            Prepare__32CB3MyBurnoutRewardsHeadlinesPageF18EB3RewardImageType(&D_01E95CD0, (EB3RewardImageType)1);
            break;
        case 4:
            Prepare__32CB3MyBurnoutRewardsHeadlinesPageF18EB3RewardImageType(&D_01E95CD0, (EB3RewardImageType)0);
            break;
        }
        field_10 = 1;
        break;
    case 3:
        UnkStruct_003EC240_7 * r5 = GetStateFromID__6CGtFSMFUl(&D_01EA2970, 0x94413FD6EF6E02D9);
        if (D_01EA2974.field_0 == r5) {
            break;
        }
        ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_18(r5, 0);
        void * t1 = D_01EA2974.field_0;
        D_01EA2974.field_0 = (void *)r5;
        UnkStruct_003EC240_5 * t2 = D_01EA2980.field_0;
        if (t2 != 0) {
            D_01EA2984.field_0 = t2->field_20;
            if (r5 != 0) {
                r5->field_8 = t2->field_20;
            }
        }
        ((UnkStruct_D_01EA2970 *)&D_01EA2970)->vfunc_1C(t1, 0);
        break;
    }
}
