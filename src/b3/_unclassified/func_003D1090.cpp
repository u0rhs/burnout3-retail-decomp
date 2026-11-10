// Hand-written; the lifter refused it (g pointer hoisted before 0x30 test; bool callees).

#include "b3/classes/UnkStruct_D_0051BA88.h"
#include "b3/classes/CB3HardCodedTrackList.h"
#include "b3/classes/CB3HardCodedCrashStageList.h"
struct UnkStruct_003D1090 { unsigned char pad_0[0x4EC0 + 100 * 0x17C]; };
extern UnkStruct_D_0051BA88 D_0051BA88;
extern unsigned long D_004E2EE8;
extern int D_004E2EE0;
extern unsigned long D_004E2EF0;
extern "C" void func_003D0C80(void *);
extern "C" bool func_003D1500(void *, int, int);
extern "C" bool func_003D1650(void *, int, unsigned long);
// 0x003D1090
extern "C" bool func_003D1090(UnkStruct_003D1090 *self, unsigned long p0, unsigned long p1)
{
    bool r;
    func_003D0C80(self);
    D_004E2EE0 = 3;
    if (p0 == 0) return false;
    UnkStruct_00154A30_4 *g = D_0051BA88.field_0;
    if (p0 & 0x30) {
        unsigned long h = g->field_68;
        D_004E2EF0 = h;
        int s = CB3HardCodedCrashStageList::FindCrashStage(h);
        char *e = (char *)self + s * 0x17C + 0x4EC0;
        if (p0 & 0x10) {
            D_004E2EE0 = 1;
            r = func_003D1500(e, 0, 0);
        } else {
            D_004E2EE0 = 2;
            r = func_003D1500(e, 0, 1);
        }
    } else {
        D_004E2EE0 = 0;
        unsigned long h = *(unsigned long *)g;
        D_004E2EE8 = h;
        int t = CB3HardCodedTrackList::FindTrack(h);
        char *e = (char *)self + t * 0x230;
        r = func_003D1650(e, 0, p0);
        if (p1) {
            r = func_003D1650(e, 1, p0) || r;
        }
    }
    return r;
}
