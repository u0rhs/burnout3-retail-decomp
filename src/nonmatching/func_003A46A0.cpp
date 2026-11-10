// NONMATCHING: func_003A46A0 -- retail 245 / ours 240 instructions, 98 in changed runs
// sdra: const pointee on a read-only param [G] (const loads are not ordered after stores, sdra rule 1)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// NONMATCHING: func_003A46A0 -- retail 245 / ours 240 instructions, 99 in changed runs
// Structure recovered (texture pick, ConstructObject/Prepare image + text, two ConstructChild frames and an anchor pivot per item: frame pos = obj pos + size*anchor, obj frame = it, obj pos = -size*anchor). Far from retail registers: retail keeps &D_01E90240/&D_01E903E0 in s7/s6 and spills x, values, p0*5; the texture choice is a branch in retail but movz in ours; the entry-jump loop; and the pivots go through 8-byte CGtV2d ld/sd temp copies (0x138/0x130 per pivot) that look like by-value CGtV2d setters (GtMathPs2/Gt2d inline API gap, N149-like). Archived early.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// func_003A46A0 -- hand-written from the retail structure (lifted draft failed to compile: a parameter
// used as an int * was declared int, "illegal implicit conversion from 'int' to 'int *'").
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

#include "b3/GtMathPs2.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFrame.h"

using GtMathPs2::CGtV2d;
using GtMathPs2::CGtV4d;

struct UnkStruct_D_004C9E58 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01EA4070 {
    unsigned char pad_0[0x640];
    CGtTexture * field_640[1];  // [G] element count unknown
};

struct UnkStruct_D_00665ED8 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E90240 {
    unsigned char pad_0[0x30];
    unsigned char field_30[0xE0];
    CGtV4d field_110;
};

struct UnkStruct_003A46A0_e0 {
    unsigned char pad_0[0x4];
    CGt2dObject * field_4;
    CGt2dObject * field_8;
};

struct UnkStruct_003A46A0 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x5A];
    int field_64;
    unsigned char pad_68[0x14];
    UnkStruct_003A46A0_e0 field_7C[5];  // [G] element count unknown
    unsigned char pad_B8[0x18];
    CGt2dFrame * field_D0;
    CGt2dFrame * field_D4;
    CGt2dFrame * field_D8[5];
    CGt2dFrame * field_EC[5];
};

extern int D_0051BF9C;
extern UnkStruct_D_004C9E58 D_004C9E58;
extern UnkStruct_D_004C9E58 D_004C9E68;
extern unsigned char D_004E2EDC;
extern UnkStruct_D_01EA4070 D_01EA4070;
extern UnkStruct_D_00665ED8 D_00665ED8;
extern char D_01ECD9F0[];
extern char D_01E903E0[];
extern const CGtV2d D_004C9E90;
extern UnkStruct_D_01E90240 D_01E90240;

extern "C" CGt2dObject * ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, CGt2dFrame *);  // CGt2dScene::ConstructObject(int,CGt2dFrame*)
extern "C" void Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(void *, const CGtV2d &, const CGtV2d &, const CGtV2d &, CGtV4d, CGtTexture *, const CGtV2d &, const CGtV2d &, unsigned int);  // CGt2dObjectImage::Prepare(...), plus retail's stack argument (N68)
extern "C" CGt2dFrame * ConstructChild__10CGt2dFrameFv(CGt2dFrame *);  // CGt2dFrame::ConstructChild()
extern "C" int func_0013A630(void *, int);
extern "C" int func_0042ECF0(void *, int, int, unsigned char);
extern "C" void func_001D6C40(CGt2dObject *, const CGtV2d &, const CGtV2d &, void *, void *, void *, float);

// 0x003A46A0
extern "C" void func_003A46A0(UnkStruct_003A46A0 * self, int p0, int count, const int * values)
{
    CGt2dFrame * frame = self->field_D4;
    if (frame == 0) {
        frame = self->field_D0;
    }
    UnkStruct_D_01E90240 * const mgr = &D_01E90240;
    char * const scene = D_01E903E0;
    int x = D_0051BF9C;
    float px = D_004C9E58.field_0;
    float tx = D_004C9E68.field_0;
    int base = p0 * 5;
    int i = 0;
    goto test;
body: {
        CGtV2d off;
        int n = base + i;
        int tex;
        if (func_0013A630((void *)(x), n) != 0) {
            tex = 17;
        } else {
            tex = 10;
        }
        if (self->field_D4 != 0 && (signed char)func_0042ECF0(D_01ECD9F0, self->field_64, n - 1, D_004E2EDC) == n) {
            tex = 10;
        }
        self->field_7C[i].field_4 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, self->field_8 + 1, frame);
        float y = (float)i * 32.0f;
        Prepare__16CGt2dObjectImageFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dQ29GtMathPs26CGtV4dP10CGtTextureRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(self->field_7C[i].field_4, CGtV2d(px, 3.0f + (127.5f + y)), CGtV2d(0.0f, 0.0f), D_004C9E90, mgr->field_110, D_01EA4070.field_640[tex], CGtV2d(0.0f, 0.0f), CGtV2d(1.0f, 1.0f), 0);
        self->field_7C[i].field_8 = ConstructObject__10CGt2dSceneFiP10CGt2dFrame(scene, self->field_8 + 1, frame);
        func_001D6C40(self->field_7C[i].field_8, CGtV2d(tx, 127.5f + y), CGtV2d(0.0f, 0.0f), mgr->field_30, (void *)(D_00665ED8.field_0), (void *)(values[i]), 20.0f);
        if (self->field_D4 != 0) {
            self->field_D8[i] = ConstructChild__10CGt2dFrameFv(self->field_D4);
            self->field_EC[i] = ConstructChild__10CGt2dFrameFv(self->field_D4);
            off = self->field_7C[i].field_4->mObjectSpace.mSize * CGtV2d(0.5f, 0.5f);
            self->field_D8[i]->field_0.field_0 = self->field_7C[i].field_4->mObjectSpace.mTopLeftPos + off;
            self->field_7C[i].field_4->mpFrame = self->field_D8[i];
            self->field_7C[i].field_4->mObjectSpace.mTopLeftPos = -off;
            off = self->field_7C[i].field_8->mObjectSpace.mSize * CGtV2d(0.0f, 0.5f);
            self->field_EC[i]->field_0.field_0 = self->field_7C[i].field_8->mObjectSpace.mTopLeftPos + off;
            self->field_7C[i].field_8->mpFrame = self->field_EC[i];
            self->field_7C[i].field_8->mObjectSpace.mTopLeftPos = -off;
        }
    }
    i++;
test:
    if (i < count) goto body;
}
