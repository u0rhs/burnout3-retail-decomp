// func_003EA580 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (function-scope locals in a fixed declaration order (register allocation), element-pointer locals p/q, 64-bit t4<7 compare, GtIDCompress__FPCc returns unsigned long).

// lifter variant 0
// func_003EA580 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CB3HardCodedTrackList;
struct UnkStruct_003EA580_13;
struct UnkStruct_003EA580_14;
struct UnkStruct_003EA580_1;
struct UnkStruct_003EA580_2;
struct UnkStruct_003EA580_5;
struct UnkStruct_003EA580_e0;
struct UnkStruct_003EA580_e1;
struct UnkStruct_003EA580_e2;
struct UnkStruct_D_00518690;

class CB3HardCodedTrackList {
public:
    static int FindTrack(unsigned long);
};

struct UnkStruct_D_00518690 {
    UnkStruct_003EA580_1 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003EA580_1 {
    unsigned char pad_0[0x4];
    UnkStruct_003EA580_2 * field_4;
};

struct UnkStruct_003EA580_2 {
    UnkStruct_003EA580_e0 * field_0;
    int field_4;
};

struct UnkStruct_003EA580_e0 {
    unsigned char pad_0[0x10];
    UnkStruct_003EA580_e1 * field_10;
    int field_14;
};

struct UnkStruct_003EA580_e1 {
    unsigned char pad_0[0x34];
    UnkStruct_003EA580_5 * field_34;
    int field_38;
    unsigned char pad_3C[0x4];
};

struct UnkStruct_003EA580_5 {
    unsigned char pad_0[0x8];
    unsigned long field_8;
};

struct UnkStruct_003EA580_e2 {
    unsigned char pad_0[0x8];
    unsigned long field_8;
    unsigned char pad_10[0x10];
};

struct UnkStruct_003EA580_13 {
    unsigned long field_0;
};

struct UnkStruct_003EA580_14 {
    unsigned char field_0;
    unsigned char field_1;
    unsigned char field_2;
    unsigned char field_3;
    unsigned char field_4;
    unsigned char field_5;
    signed char field_6;
    signed char field_7;
    signed char field_8;
    signed char field_9;
    signed char field_A;
    signed char field_B;
    unsigned char pad_C[0x4];
};

extern UnkStruct_D_00518690 D_00518690;
extern int D_01EB5CA0[];  // [G] element count unknown
extern unsigned long kaB3HardCodedRaceChallengeList[];  // [G] element count unknown
extern UnkStruct_003EA580_13 * kapGPChallengeStageArrays[];  // [G] element count unknown

extern "C" void *FindProgressionChallenge__25CB3HardCodedRaceStageListFi(int);
extern "C" int FindChallengeIndex__25CB3HardCodedRaceStageListFUl(unsigned long);
extern "C" int FindLocalStageIndex__25CB3HardCodedRaceStageListFUli(unsigned long, int);
extern "C" void func_0021ADF0(unsigned long, UnkStruct_003EA580_14 *);
extern "C" unsigned long GtIDCompress__FPCc(UnkStruct_003EA580_14 *, signed char, signed char, void *, signed char, void *, void *);
extern "C" int func_003EAA60(void *);
extern "C" int func_003E9CB0(int, int);

// 0x003EA580
extern "C" void func_003EA580()
{
    UnkStruct_003EA580_14 local;
    int i;
    int i1;
    int i2;
    int r1;
    int i3;
    UnkStruct_003EA580_2 * t1;
    UnkStruct_003EA580_e0 * p;
    UnkStruct_003EA580_e1 * q;
    for (i = 0; (i < 73); i++) {
        FindProgressionChallenge__25CB3HardCodedRaceStageListFi(i);
    }
    t1 = D_00518690.field_0->field_4;
    for (i1 = 0; (i1 < t1->field_4); i1++) {
        p = &t1->field_0[i1];
        for (i2 = 0; (i2 < p->field_14); i2++) {
            q = &p->field_10[i2];
            r1 = FindChallengeIndex__25CB3HardCodedRaceStageListFUl(q->field_34->field_8);
            if (r1 != -1) {
                for (i3 = 0; (i3 < q->field_38); i3++) {
                    FindLocalStageIndex__25CB3HardCodedRaceStageListFUli(((UnkStruct_003EA580_e2 *)q->field_34)[i3].field_8, r1);
                }
            }
        }
    }
    for (i = 0; (i < 18); i++) {
        D_01EB5CA0[i] = 0;
    }
    for (i = 0; (i < 73); i++) {
        unsigned long t4 = kaB3HardCodedRaceChallengeList[i];
        unsigned long v0 = t4;
        if (t4 < 7) {
            v0 = kapGPChallengeStageArrays[((int)t4)]->field_0;
        }
        func_0021ADF0(v0, &local);
        signed char t5 = local.field_6;
        signed char t6 = local.field_7;
        signed char t7 = local.field_8;
        signed char t8 = local.field_9;
        local.field_2 = 95;
        local.field_5 = 95;
        local.field_0 = t5;
        signed char t9 = local.field_A;
        signed char t10 = local.field_B;
        local.field_1 = t6;
        local.field_3 = t7;
        local.field_4 = t8;
        local.field_8 = 0;
        local.field_6 = t9;
        local.field_7 = t10;
        unsigned long r4 = GtIDCompress__FPCc(&local, t8, t7, ((char *)&local + 0x8), t6, ((char *)&local + 0x7), ((char *)&local + 0x6));
        int r5 = CB3HardCodedTrackList::FindTrack(r4);
        int r6 = func_003EAA60((void *)(r5));
        int r7 = func_003E9CB0(r6, i);
        D_01EB5CA0[r7] = (D_01EB5CA0[r7] + 1);
    }
}
