// func_0015E720 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. `self` is whatever a0 points to.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths).

#include "b3/GtMathPs2.h"

#include "b3/classes/CB3SplitTimeCheckpoint.h"
#include "b3/classes/CGtTexture.h"

struct UnkStruct_0015E720;

struct UnkStruct_0015E720 {
    unsigned char pad_0[0x4];
    int field_4;
    int field_8;
    unsigned char field_C;
};

extern "C" void DrawCheckpoint__22CB3SplitTimeCheckpointFP10CGtTextureQ29GtMathPs26CGtV4d(void *, void *, GtMathPs2::CGtV4d);  // CB3SplitTimeCheckpoint::DrawCheckpoint(CGtTexture*,GtMathPs2::CGtV4d)

// 0x0015E720
extern "C" void func_0015E720(UnkStruct_0015E720 * self, int p0)
{
    GtMathPs2::CGtV4d c(0.5f, 0.5f, 0.5f, 1.0f);
    int v0 = self->field_8;
    if (self->field_C == 0) return;
    if ((p0 & 24) != 0) {
        v0 = self->field_4;
    }
    DrawCheckpoint__22CB3SplitTimeCheckpointFP10CGtTextureQ29GtMathPs26CGtV4d(self, (CGtTexture*)v0, c);
}
