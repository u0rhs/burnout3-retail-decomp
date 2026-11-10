// Hand-written; the lifter refused it (a86: GenerateRandomTrackInRegion (single event) = func_00433370 shape minus marathon/p2p tests).

// Hand-written; the lifter refused it (a86: GenerateRandomTrackInRegion, sibling of func_00433370 without the marathon/point-to-point tests; two N24 goto loops, match exits via goto done).

// [L] DNAT: CB3SingleEventGameOptionsPage::GenerateRandomTrackInRegion(EB3TrackRegion) (research/proto/new_names.csv, medium)
#include "b3/_unclassified/GtRandom.h"

class CB3Profile {
public:
    unsigned char IsTrackUnlocked(unsigned long);
    unsigned char pad_0[0x1];
};
class CB3TrackList {
public:
    int GetTrackRegion(unsigned long);
    unsigned char pad_0[0x4];
    int field_4;
    unsigned char pad_8[0x400];
    unsigned long field_408[1];
};
struct UnkStruct_D_0051BF9C {
    CB3Profile * field_0;
    unsigned char pad_4[0xC];
};
struct UnkStruct_D_00518680 {
    CGtRandom r;
    unsigned char pad[0x100];
};
struct UnkStruct_D_004EE040 { unsigned char pad_0[0x10]; };
struct UnkStruct_00432280 { unsigned char pad_0[0x4]; };
extern UnkStruct_D_0051BF9C D_0051BF9C;
extern UnkStruct_D_00518680 D_00518680;
extern CB3TrackList D_005196A0;
extern UnkStruct_D_004EE040 D_004EE040;

// 0x00432280
extern "C" unsigned long func_00432280(UnkStruct_00432280 * self, int region)
{
    unsigned long id;
    int i = 0;
    int count = 0;
    CB3Profile * profile = D_0051BF9C.field_0;
    goto test1;
body1:
    id = *(unsigned long *)((char *)&D_004EE040 + i * 8 + 0x2BA68);
    if (D_005196A0.GetTrackRegion(id) == region) {
        if (profile->IsTrackUnlocked(id)) {
            count++;
        }
    }
    i++;
test1:
    if (i < D_005196A0.field_4) goto body1;
    count = D_00518680.r.Random() % count;
    int k = 0;
    i = 0;
    goto test2;
body2:
    id = *(unsigned long *)((char *)&D_004EE040 + i * 8 + 0x2BA68);
    if (D_005196A0.GetTrackRegion(id) == region) {
        if (profile->IsTrackUnlocked(id)) {
            if (count == k) {
                goto done;
            }
            k++;
        }
    }
    i++;
test2:
    if (i < D_005196A0.field_4) goto body2;
done:
    return id;
}
