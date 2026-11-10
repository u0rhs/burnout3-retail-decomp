// func_003BAA60 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (outer test as a one-case switch (beq body; b exit)).

// func_003BAA60 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

enum EB3ScoreFinishState {};

class CB3RaceCar;
struct UnkStruct_003BAA60;
struct UnkStruct_003BAA60_1;
struct UnkStruct_D_00522660;
struct UnkStruct_D_0064D37C;

class CB3RaceCar {
public:
    void SetFinished(EB3ScoreFinishState);

    unsigned char pad_0[0x10C8];
    int field_10C8;
};

struct UnkStruct_003BAA60_1 {
    unsigned char pad_0[0x30];
    int field_30;
};

struct UnkStruct_D_0064D37C {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x12AD28];
    CB3RaceCar * field_12AD28[1];  // [G] element count unknown
};

struct UnkStruct_003BAA60 {
    unsigned char pad_0[0x8];
    UnkStruct_003BAA60_1 * field_8;
};

extern UnkStruct_D_0064D37C D_0064D37C;
extern UnkStruct_D_00522660 D_00522660;

extern "C" void func_003BA8F0(UnkStruct_003BAA60 *);

// 0x003BAA60
// [L] a one-case switch: retail branches beq-to-body then b-to-exit, which no if/else form produced.
extern "C" void func_003BAA60(UnkStruct_003BAA60 * self)
{
    switch (self->field_8->field_30) {
    case 2:
        for (int m0 = 0; m0 < D_0064D37C.field_0; m0++) {
            CB3RaceCar * t0 = D_00522660.field_12AD28[m0];
            if (t0->field_10C8 == 0) {
                t0->SetFinished((EB3ScoreFinishState)2);
            }
        }
        func_003BA8F0(self);
        break;
    }
}
