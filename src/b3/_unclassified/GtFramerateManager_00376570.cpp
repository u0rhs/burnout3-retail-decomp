// CGtFramerateManager::UpdatePostRenderWait(int,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtFramerateManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (Hand-written (decomp1, 2026-11-06): E map CGtFramerateManager::UpdatePostRenderWait(int,int); listing restored by hand (spimdisasm refused the R5900 3-operand multu); N140 pads + 16-aligned now for the frame, product temp before the -= for the schedule, volatile read for the +0x30 reload).

// CGtFramerateManager::UpdatePostRenderWait(int,int) in the E map (research/retail_names.csv 0x376570, high); the asm label
// stays until a rename pass. Hand-written (decomp1 2026-11-06) after the listing was restored (spimdisasm refused the R5900
// 3-operand multu). Layout from the proven siblings Prepare / Construct__19CGtFramerateManagerFff (GtFramerateManager.cpp):
// [L] field_20 / field_18 are tick counts (Construct: ms * 294.912 MHz / 1000), field_8 the last GetTime, field_10 an
// accumulated time; meanings [G]. Shape notes: two N140 pads + `now` 16-aligned give retail's 0x80 frame and slots
// (now 0x60, v 0x70, t 0x78); the volatile read in Min reproduces retail's reload of +0x30 (0x3766A0) [G: a volatile member
// reloads every access and does not match].
#include "b3/GtMath.h"
struct UnkStruct_00376570_t { long field_0; };
struct UnkStruct_00376570 {
    int field_0;
    unsigned char pad_4[0x4];
    long field_8;
    long field_10;
    long field_18;
    long field_20;                 // [L] frame period, ticks
    int field_28;
    int field_2C;
    int field_30;
    unsigned char field_34;
};
struct UnkStruct_00376570_pad { int x[4]; UnkStruct_00376570_pad() {} ~UnkStruct_00376570_pad() {} };  // [G] N140 frame pad
extern "C" void GetTime__19CGtHiResSystemTimerFv(UnkStruct_00376570_t *out);
// 0x00376570
extern "C" int func_00376570(UnkStruct_00376570 *self, int a, int b)
{
    UnkStruct_00376570_t t;
    UnkStruct_00376570_t v;
    UnkStruct_00376570_t now __attribute__((aligned(16)));
    UnkStruct_00376570_pad p1, p2;
    GetTime__19CGtHiResSystemTimerFv(&now);
    t = now;
    if (self->field_34) {
        v.field_0 = -1;
    } else {
        self->field_2C += self->field_28;
        if (self->field_2C <= 0) {
            self->field_8 = t.field_0;
            self->field_28 = a;
            return a;
        }
        self->field_10 += t.field_0 - self->field_8;
        v.field_0 = self->field_10 - self->field_20 * self->field_2C;
    }
    self->field_8 = t.field_0;
    int r = a;
    if (self->field_18 < v.field_0) {
        r = a + (int)((self->field_20 - 1 + (v.field_0 - self->field_18)) / self->field_20);
    }
    if (b < r) {
        r = b;
        if (self->field_0 != 2 && !self->field_34) {
            long d = self->field_20 * (b - a);
            self->field_10 -= v.field_0;
            self->field_10 += d;
        }
    }
    if (!self->field_34) {
        self->field_28 = r;
    }
    if (self->field_0 == 0) {
        r = a;
    }
    if (self->field_30 > 0 && r == a) {
        self->field_30 = GtMath::Min(*(volatile int *)&self->field_30, b - a);
        r += self->field_30;
        self->field_10 += self->field_20 * self->field_30;
    }
    self->field_30 = 0;
    return r;
}
