// B3RewardImageComponent.cpp -- translation unit regrouped by tools/tu_merge.py from 3 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 1 function(s) named in research/retail_names.csv -> B3RewardImageComponent.cpp, 2 placed between two of them by address contiguity (N2).
// Area not evidenced (no Revenge file), so _unclassified/ (docs/conventions.md).
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CB3MyBurnoutRewardsHeadlinesPage.h"
#include "b3/classes/CB3RewardImageComponent.h"
#include "b3/classes/EB3RewardImageType.h"
#include "b3/classes/UnkStruct_D_0051BA44.h"

extern UnkStruct_D_0051BA44 D_0051BA44;
extern "C" int GetTrophySpecialCondition__22CB3HardCodedTrophyListFi(int);
extern "C" unsigned short * func_00271A00(void *, int);
extern "C" int func_003F5E90(int);
extern "C" int func_003F5F50(int);
extern "C" int func_003F5FB0(int);
extern "C" void Construct__20CB3MenuComponentBaseFi(void *, int);  // CB3MenuComponentBase::Construct(int)

// Update__23CB3RewardImageComponentFf -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x003F6090
extern "C" void Update__23CB3RewardImageComponentFf()
{
}

// func_003F64D0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x003F64D0
// [C] cases 0-3 return func_00271A00's result: nothing writes v0 between each `jal func_00271A00` (0x3F6518 / 0x3F6538 /
// 0x3F6558 / 0x3F6578) and `jr $ra` at 0x3F6584. CB3MyBurnoutRewardsHeadlinesPage::Prepare passes it on as a string
// pointer (0x3F0C68 `daddu $a1, $v0, $zero`). Any other p0 leaves v0 unset (0x3F6500 `b .L003F6584`), so that path
// has no return value here either (falls off the end, as retail's code does).
extern "C" unsigned short * func_003F64D0(void *n0_, int p0, int p1)
{
    int n0 = (int)n0_;
    switch (p0) {
    case 0:
        int r6 = GetTrophySpecialCondition__22CB3HardCodedTrophyListFi(p1);
        return func_00271A00(&D_0051BA44, r6);
    case 1:
        int r4 = func_003F5E90(p1);
        return func_00271A00(&D_0051BA44, r4);
    case 2:
        int r2 = func_003F5F50(p1);
        return func_00271A00(&D_0051BA44, r2);
    case 3:
        int r0 = func_003F5FB0(p1);
        return func_00271A00(&D_0051BA44, r0);
    }
}

// CB3RewardImageComponent::Construct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3RewardImageComponent.cpp.
// 0x003F6590
void CB3RewardImageComponent::Construct()
{
    Construct__20CB3MenuComponentBaseFi(this, 2);
    field_C = 0;
    field_10 = 0;
    field_18 = 0;
}
