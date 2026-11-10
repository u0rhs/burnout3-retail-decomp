// CB3ProfileManager::UpdateProfile(EChallengeMedal,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3Profile.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

enum EChallengeMedal {};

struct UnkStruct_D_0051BF9C;

struct UnkStruct_D_0051BF9C {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3ProfileManager {
public:
    void UpdateProfile(EChallengeMedal p0, int p1);
};

extern UnkStruct_D_0051BF9C D_0051BF9C;

extern "C" void func_00136E10(int, EChallengeMedal, int);

// 0x001364A0
void CB3ProfileManager::UpdateProfile(EChallengeMedal p0, int p1)
{
    func_00136E10(D_0051BF9C.field_0, p0, p1);
}
