// Hand-written; the lifter refused it (a90: sibling of 00135F30).

extern "C" int FindChallengeIndex__25CB3HardCodedRaceStageListFUl(unsigned long);
struct UnkStruct_00136110_1 {
    unsigned char pad_0[0x1C];
    unsigned int field_1C;
    unsigned char pad_20[4];
    unsigned char field_24[4];
};
struct UnkStruct_00136110 {
    unsigned char pad_0[0x386];
    signed char field_386[1];
    unsigned char pad_387[0x10D];
    signed char field_494;
    unsigned char pad_495;
    signed char field_496;
    unsigned char pad_498;
    signed char field_498;
};
extern unsigned char D_0051BFF7[];
extern "C" int func_003E96E0(int);
extern "C" UnkStruct_00136110_1 * func_003EA1D0(int);
extern "C" unsigned long FindStageIDFromProgressionIndex__10CB3ProfileFi(UnkStruct_00136110 *, int);
extern "C" void * func_003EA0E0(int);

// 0x00136110
extern "C" int func_00136110(UnkStruct_00136110 * self, int p0, int p1)
{
    if (D_0051BFF7[p0] == 0) {
        return 0;
    }
    if (self->field_386[p0] > 0) {
        return 0;
    }
    if (p1 == func_003E96E0(p0)) {
        return 1;
    }
    if (self->field_496 <= 0) {
        return 0;
    }
    int i;
    UnkStruct_00136110_1 * r = func_003EA1D0(p0);
    unsigned int f = r->field_1C;
    if (f & 4) {
        if (self->field_496 != 3 || self->field_498 == 3) {
            return 0;
        }
    } else {
        if (self->field_496 <= 0 || self->field_498 > 0) {
            return 0;
        }
    }
    if (f & 1) {
        if (p0 - 1 != self->field_494) {
            return 0;
        }
    }
    if (f & 8) {
        for (i = 0; i < 4; i++) {
            int e = r->field_24[i];
            if (e != 0xFF) {
                unsigned long id = FindStageIDFromProgressionIndex__10CB3ProfileFi(self, e);
                if (id != 0) {
                    int st = FindChallengeIndex__25CB3HardCodedRaceStageListFUl(id);
                    if (st != -1) {
                        if (st == self->field_494) {
                            return 1;
                        }
                    }
                }
            }
        }
    }
    if (r->field_1C & 0x20) {
        void * a = func_003EA0E0(self->field_494);
        void * b = func_003EA0E0(p0);
        if (a == b) {
            return 1;
        }
    }
    return 0;
}
