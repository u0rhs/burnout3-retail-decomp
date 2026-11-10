// NONMATCHING: Construct__15CB3ScrapeSystemFv -- retail 64 / ours 64 instructions, 34 in changed runs
// psweep: scoped #pragma opt_arithtransformation off [G] improves 35 -> 34
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/GtMathPs2.h"
// [G] N182: scoped optimiser pragma found by the pragma sweep (psweep_all.py)
#pragma push
#pragma opt_arithtransformation off
using namespace GtMathPs2;
extern volatile float D_004E114C;
extern float D_004E1150;
struct UnkStruct_D_01EA4910 {
    CGtV4d field_0;
    CGtV4d field_10;
    char field_20[0xC];
    int field_2C;
    unsigned int field_30;
    float field_34;
    float field_38;
    float field_3C;
};
extern UnkStruct_D_01EA4910 D_01EA4910;
extern char D_004C9008[];
extern "C" char *strcpy(char *, const char *);
class CB3ScrapeRenderer { public: static void Construct(); };
class CB3ScrapeSystem {
public:
    void Construct();
    unsigned char pad_0[0x8A00];
    void *field_8A00;
    unsigned char pad_8A04[4];
    int field_8A08;
    unsigned char pad_8A0C[0x108];
    int field_8B14;
};
void CB3ScrapeSystem::Construct()
{
    CGtV4d b = CGtV4d(D_004E114C, D_004E114C, D_004E114C, 0.625f);
    CGtV4d a = CGtV4d(D_004E114C, D_004E114C, D_004E114C, D_004E1150);
    D_01EA4910.field_0 = a;
    D_01EA4910.field_10 = b;
    strcpy(D_01EA4910.field_20, D_004C9008);
    D_01EA4910.field_2C = 0;
    D_01EA4910.field_30 = 0x80000044;
    D_01EA4910.field_34 = 1.75f;
    D_01EA4910.field_38 = 1.5f;
    D_01EA4910.field_3C = 15.0f;
    field_8A08 = 32;
    field_8A00 = (char *)this + 0x8A0C;
    field_8B14 = -1;
    CB3ScrapeRenderer::Construct();
}

#pragma pop
