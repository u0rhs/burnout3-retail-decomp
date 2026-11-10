// Hand-written; the lifter refused it (a90: hand-written; FindStageIDFromProgressionIndex__10CB3ProfileFi takes a1 byte).

enum EB3TrackRegion {};
class CB3HardCodedCrashStageList {
public:
    static int FindCrashStage(unsigned long);
};
struct UnkStruct_00135F30_1 {
    unsigned char pad_0[0x1C];
    unsigned int field_1C;
    unsigned char pad_20[4];
    unsigned char field_24[4];
};
struct UnkStruct_00135F30 {
    unsigned char pad_0[0x3CF];
    signed char field_3CF[1];
    unsigned char pad_3D0[0xC5];
    signed char field_495;
    unsigned char pad_496;
    signed char field_497;
    unsigned char pad_498;
    signed char field_499;
};
extern unsigned char D_0051C040[];
extern "C" int func_003E8E60(int);
extern "C" UnkStruct_00135F30_1 * func_003E93B0(int);
extern "C" unsigned long FindStageIDFromProgressionIndex__10CB3ProfileFi(UnkStruct_00135F30 *, int);
extern "C" int func_003E92D0(int);

// 0x00135F30
extern "C" int func_00135F30(UnkStruct_00135F30 * self, int p0, int p1)
{
    if (D_0051C040[p0] == 0) {
        return 0;
    }
    if (self->field_3CF[p0] > 0) {
        return 0;
    }
    if (p1 == func_003E8E60(p0)) {
        return 1;
    }
    if (self->field_497 <= 0) {
        return 0;
    }
    int i;
    UnkStruct_00135F30_1 * r = func_003E93B0(p0);
    unsigned int f = r->field_1C;
    if (f & 4) {
        if (self->field_497 != 3 || self->field_499 == 3) {
            return 0;
        }
    } else {
        if (self->field_497 <= 0 || self->field_499 > 0) {
            return 0;
        }
    }
    if (f & 1) {
        if (p0 - 1 != self->field_495) {
            return 0;
        }
    }
    if (f & 8) {
        for (i = 0; i < 4; i++) {
            int e = r->field_24[i];
            if (e != 0xFF) {
                unsigned long id = FindStageIDFromProgressionIndex__10CB3ProfileFi(self, e);
                if (id != 0) {
                    int st = CB3HardCodedCrashStageList::FindCrashStage(id);
                    if (st != -1) {
                        if (st == self->field_495) {
                            return 1;
                        }
                    }
                }
            }
        }
    }
    if (r->field_1C & 0x20) {
        int a = func_003E92D0(self->field_495);
        int b = func_003E92D0(p0);
        if (a == b) {
            return 1;
        }
    }
    return 0;
}
