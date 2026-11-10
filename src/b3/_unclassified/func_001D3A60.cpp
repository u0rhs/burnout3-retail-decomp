// Hand-written; the lifter refused it (a86: CGtTimer::Update; void* param + struct cast; compare operand order (x > y) for slt at; arm order for block layout).

#include "b3/classes/CGtTimer.h"

struct UnkStruct_001D3A60 {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    int field_14;
    int field_18;
    float field_1C;
    float field_20;
    int field_24;
    unsigned char field_28;
};

// 0x001D3A60
extern "C" void Update__8CGtTimerFv(void * p)
{
    UnkStruct_001D3A60 * self = (UnkStruct_001D3A60 *)p;
    if (self->field_0 != CGtTimer::mguFrames) {
        if (self->field_18 != self->field_24) {
            if (self->field_24 != 1) {
                self->field_10 = (self->field_18 - 1 + self->field_10 * self->field_24) / self->field_18;
            } else {
                if (self->field_10 > self->field_18 / 2) {
                    self->field_C = self->field_C + 1;
                }
                self->field_10 = 0;
            }
            self->field_18 = self->field_24;
            self->field_1C = CGtTimer::mgrBaseTimestepSeconds / (float)self->field_18;
        }
        self->field_0 = CGtTimer::mguFrames;
        int v = self->field_0 - self->field_14;
        int d = v - self->field_4;
        if (d > 0) {
            if (self->field_28 != 0) {
                if (self->field_18 != 1) {
                    self->field_10 = self->field_10 + d % self->field_18;
                    if (self->field_10 > self->field_18) {
                        self->field_C = self->field_C + self->field_10 / self->field_18;
                        self->field_10 = self->field_10 % self->field_18;
                    }
                    self->field_C = self->field_C + d / self->field_18;
                } else {
                    self->field_C = self->field_C + d;
                }
            } else {
                self->field_8 = self->field_8 + d;
            }
            self->field_4 = v;
        }
    }
    self->field_20 = (float)self->field_C * CGtTimer::mgrBaseTimestepSeconds
                   + (float)self->field_10 * (CGtTimer::mgrBaseTimestepSeconds / (float)self->field_18);
}
