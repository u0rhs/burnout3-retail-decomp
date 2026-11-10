// func_0038B160 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (element pointer into D_00522660.field_12AD50[i] (as sibling func_0038C070), nested if with early float return).

struct UnkStruct_D_0064D3A0 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0038B160_e0 {
    unsigned char pad_0[0x10C8];
    int field_10C8;
    unsigned char pad_10CC[0x1704];
};

struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x12AD50];
    UnkStruct_0038B160_e0 field_12AD50[1];  // [G] element count unknown
};

struct UnkStruct_D_004EE040 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern UnkStruct_D_0064D3A0 D_0064D3A0;
extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_D_004EE040 D_004EE040;

enum EB3ScoreFinishState {};
extern "C" void SetFinished__10CB3RaceCarF19EB3ScoreFinishState(void *, EB3ScoreFinishState);  // CB3RaceCar::SetFinished(EB3ScoreFinishState)
extern "C" int func_00131CE0(void *);
extern "C" float func_00199750(void *);

// 0x0038B160
extern "C" void func_0038B160()
{
    if (func_00131CE0(&D_004EE040) == 0) {
        if (!(func_00199750(&D_00522660) < 300.0f)) {
            return;
        }
        for (int i = 0; i < D_0064D3A0.field_0; i++) {
            UnkStruct_0038B160_e0 * e = &D_00522660.field_12AD50[i];
            if (e->field_10C8 == 0) {
                SetFinished__10CB3RaceCarF19EB3ScoreFinishState(e, (EB3ScoreFinishState)1);
            }
        }
    }
}
