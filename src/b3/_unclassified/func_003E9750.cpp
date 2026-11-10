// Hand-written; the lifter refused it (a133: stage-list scan; decl order i,h,r picks s2,s1,s0; goto lowest shared tail).

struct UnkStruct_003E9750_4 { unsigned long field_0; };
struct UnkStruct_003E9750_5 {
    unsigned char field_0; unsigned char field_1; unsigned char field_2; unsigned char field_3;
    unsigned char field_4; unsigned char field_5;
    signed char field_6; signed char field_7; signed char field_8; signed char field_9;
    signed char field_A; signed char field_B; unsigned char pad_C[0x4];
};
struct UnkStruct_003E9750_blk { unsigned char pad_0[0x10]; unsigned long field_10; };
extern const unsigned long kaB3HardCodedRaceChallengeList[];
extern UnkStruct_003E9750_4 * kapGPChallengeStageArrays[];
extern "C" int func_00136400(int);
extern "C" void func_0021ADF0(unsigned long, UnkStruct_003E9750_5 *);
extern "C" unsigned long GtIDCompress__FPCc(UnkStruct_003E9750_5 *, signed char, signed char, void *, signed char, void *, void *);
extern "C" int FindTrack__21CB3HardCodedTrackListFUl(unsigned long);
extern "C" int func_003EAA60(void *);
extern "C" bool IsChallengeOnThisCircuit__25CB3HardCodedRaceStageListF14EB3TrackRegionii(int, int, int);
extern "C" int func_0013AD70(void *, int, int);
extern "C" int func_0013AD30(void *, int, int);
extern "C" UnkStruct_003E9750_blk *func_003EA1D0(int);
extern "C" int GetChallengeType__25CB3HardCodedRaceStageListFi(int);
extern "C" int func_00136110(void *, int, int);
// 0x003E9750
extern "C" int func_003E9750(int p0, int p1, void *p2_)
{
    int p2 = (int)p2_;
    int i;
    int h = func_00136400(p2);
    int r = 0;
    for (i = 0; i < 0x49; i++) {
        UnkStruct_003E9750_5 local;
        unsigned long t0 = kaB3HardCodedRaceChallengeList[i];
        unsigned long v0 = t0 < 7 ? kapGPChallengeStageArrays[(int)t0]->field_0 : t0;
        func_0021ADF0(v0, &local);
        signed char t1 = local.field_6;
        signed char t2 = local.field_7;
        signed char t3 = local.field_8;
        signed char t4 = local.field_9;
        local.field_2 = 95;
        local.field_5 = 95;
        local.field_0 = t1;
        signed char t5 = local.field_A;
        signed char t6 = local.field_B;
        local.field_1 = t2;
        local.field_3 = t3;
        local.field_4 = t4;
        local.field_8 = 0;
        local.field_6 = t5;
        local.field_7 = t6;
        unsigned long r1 = GtIDCompress__FPCc(&local, t4, t3, ((char *)&local + 0x8), t2, ((char *)&local + 0x7), ((char *)&local + 0x6));
        if (func_003EAA60((void *)(FindTrack__21CB3HardCodedTrackListFUl(r1))) != p0) continue;
        if (!IsChallengeOnThisCircuit__25CB3HardCodedRaceStageListF14EB3TrackRegionii(p0, i, p1)) continue;
        if (func_0013AD70((void *)(p2), i, 1) != 0) continue;
        if (func_0013AD30((void *)(p2), i, 1) > 0) {
            UnkStruct_003E9750_blk *b = func_003EA1D0(i);
            if (b == 0) goto lowest;
            if (b->field_10 == 0) goto lowest;
            if (func_0013AD30((void *)(p2), i, 1) == 3) goto lowest;
            r = 1;
            continue;
        } else {
            if (GetChallengeType__25CB3HardCodedRaceStageListFi(i) == 2) { r = 3; continue; }
            if (func_00136110((void *)(p2), i, h) != 0) { r = 2; continue; }
            if (r == 2) continue;
            if (r == 3) continue;
            r = 1;
            continue;
        }
    lowest:
        if (r != 0) continue;
        r = 4;
    }
    return r;
}
