// func_00136E10 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (int temp for the guarded signed-char table read (no sign-extend)).

// from build/vt\try_func_00136E10_best.cpp
// func_00136E10 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CB3HardCodedCrashStageList;
struct UnkStruct_00136E10;
struct UnkStruct_00136E10_1;
struct UnkStruct_00136E10_2;
struct UnkStruct_D_01E901C8;

class CB3HardCodedCrashStageList {
public:
    static int FindCrashStage(unsigned long);
};

struct UnkStruct_D_01E901C8 {
    UnkStruct_00136E10_1 * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00136E10_1 {
    unsigned char pad_0[0x34];
    UnkStruct_00136E10_2 * field_34;
};

struct UnkStruct_00136E10_2 {
    unsigned char pad_0[0x8];
    unsigned long field_8;
};

struct UnkStruct_00136E10 {
    unsigned char pad_0[0x380];
    int field_380;
    unsigned char field_384;
    unsigned char field_385;
    signed char field_386[1];  // [G] element count unknown
    unsigned char pad_387[0x48];
    signed char field_3CF[1];  // [G] element count unknown
    unsigned char pad_3D0[0xC4];
    unsigned char field_494;
    unsigned char field_495;
    unsigned char field_496;
    unsigned char field_497;
    unsigned char pad_498[0x2];
    unsigned char field_49A;
};

extern UnkStruct_D_01E901C8 D_01E901C8;

extern "C" int FindChallengeIndex__25CB3HardCodedRaceStageListFUl(unsigned long);

// 0x00136E10
extern "C" void func_00136E10(UnkStruct_00136E10 * self, int p0)
{
    UnkStruct_00136E10_1 * t0 = D_01E901C8.field_0;
    UnkStruct_00136E10_2 * t1 = t0->field_34;
    unsigned long t2 = t1->field_8;
    int r0 = FindChallengeIndex__25CB3HardCodedRaceStageListFUl(t2);
    if (r0 != -1) {
        self->field_49A = 1;
        self->field_496 = p0;
        self->field_494 = r0;
        if (p0 != 0) {
            int v4;
            if (r0 == -1) {
                v4 = 3;
            } else {
                v4 = self->field_386[r0];
            }
            if (v4 < p0) {
                if (r0 != -1) {
                    self->field_380 = r0;
                    self->field_384 = p0;
                    self->field_385 = 1;
                } else {
                }
            } else {
            }
        } else {
        }
    } else {
        int r1 = CB3HardCodedCrashStageList::FindCrashStage(t2);
        if (r1 != -1) {
            self->field_49A = 0;
            self->field_497 = p0;
            self->field_495 = r1;
            if (p0 != 0) {
                int v0;
                if (r1 == -1) {
                    v0 = 3;
                } else {
                    v0 = self->field_3CF[r1];
                }
                if (v0 < p0) {
                    if (r1 != -1) {
                        self->field_380 = r1;
                        self->field_384 = p0;
                        self->field_385 = 0;
                    } else {
                    }
                } else {
                }
            } else {
            }
        } else {
        }
    }
}
