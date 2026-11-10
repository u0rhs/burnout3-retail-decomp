// Hand-written; the lifter refused it (asm sync/ei as GtThreadMgr).

#include "b3/classes/UnkStruct_guFrameCount.h"

extern UnkStruct_guFrameCount guFrameCount;

// 0x0022B830
extern "C" int func_0022B830(int p0)
{
    guFrameCount.field_0 = guFrameCount.field_0 + 1;
    asm("sync");
    asm(".word 0x42000038");
    return 0;
}
