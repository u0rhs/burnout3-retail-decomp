// func_00393600 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/classes/CB3RaceCar.h"
#include "b3/classes/CB3SoundManager.h"
#include "b3/classes/CGtTimer.h"
#include "b3/classes/EB3ScoreFinishState.h"

struct UnkStruct_00393600;

struct UnkStruct_00393600 {
    unsigned char pad_0[0x44];
    float field_44;
    unsigned char pad_48[0xA];
    unsigned char field_52;
};

extern CB3RaceCar * D_0064D388[];  // [G] element count unknown
extern CGtTimer D_00522660;
extern CB3SoundManager D_01E75640;

// 0x00393600
extern "C" int func_00393600(UnkStruct_00393600 * self, int p0)
{
    CB3RaceCar * t0 = D_0064D388[p0];
    int t1 = t0->field_16C8;
    if (t1 != 1) {
        if (t1 != 2) {
            t0->SetFinished((EB3ScoreFinishState)6);
        }
    }
    D_00522660.SetSlowMo(1);
    D_01E75640.SetMasterPitchScalar(1.0f);
    self->field_44 = -1.0f;
    self->field_52 = 0;
    return 0;
}
