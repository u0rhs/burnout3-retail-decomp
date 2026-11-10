// func_0038BB70 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (a66: CB3OfflineLapEliminatorLogic::OnRaceCarStartNewLap [L] DNAT low; fix = declaration: car element typed pointer (UnkStruct_a1 *) from the byte-offset cast, 0x1998/0x11E4 fields, t3 = 5 - D local before tests).

// lifter variant 0
// func_0038BB70 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

enum EB3ScoreFinishState {};
class CB3RaceCarPhysics;
class CB3CollidingPair;
class CB3CrashStartInfo;
enum EScoreBonusEvent {};

class CB3CrashActionDirector;
class CB3Score;
struct UnkStruct_0038BB70;
struct UnkStruct_0038BB70_4;
struct UnkStruct_0038BB70_5;
struct UnkStruct_0038BB70_a1;
struct UnkStruct_0038BB70_e0;
struct UnkStruct_0038BB70_e1;
struct UnkStruct_0038BB70_e2;
struct UnkStruct_D_00522660;
struct UnkStruct_D_0055D7FE;
struct UnkStruct_D_0055EFEC;
struct UnkStruct_D_0064D384;
struct UnkStruct_D_0064D3A0;

class CB3Score {
public:
    void SetNumLives(int);
};

class CB3CrashActionDirector {
public:
    void StartRaceCarCrashing(CB3RaceCarPhysics*, int, CB3CollidingPair*, CB3CrashStartInfo*);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0038BB70_a1 {
    unsigned char pad_0[0x10C0];
    CB3Score field_10C0;
    unsigned char pad_10C1[0x1];
    short field_10C2;
    unsigned char pad_10C4[0x120];
    unsigned char field_11E4[0x706];
    unsigned char field_18EA;
    unsigned char pad_18EB[0x29];
    int field_1914;
    unsigned char pad_1918[0x80];
    unsigned char field_1998;
    unsigned char pad_1999[0x13];
    signed char field_19AC;
};

struct UnkStruct_0038BB70_e0 {
    UnkStruct_0038BB70_4 * field_0;
    unsigned char pad_4[0x2C];
};

struct UnkStruct_D_0055EFEC {
    UnkStruct_0038BB70_e0 field_0[1];  // [G] element count unknown
};

struct UnkStruct_0038BB70_4 {
    unsigned char pad_0[0xCC4];
    UnkStruct_0038BB70_5 * field_CC4;
};

struct UnkStruct_0038BB70_5 {
    unsigned char pad_0[0x1015];
    unsigned char field_1015;
};

struct UnkStruct_D_0055D7FE {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0064D3A0 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0038BB70_e1 {
    unsigned char pad_0[0x1D68];
    unsigned char field_1D68;
    unsigned char pad_1D69[0xA67];
};

struct UnkStruct_0038BB70_e2 {
    unsigned char pad_0[0x27D0];
};

struct UnkStruct_D_00522660 {
    UnkStruct_0038BB70_e2 field_0[1];  // [G] element count unknown
    unsigned char pad_27D0[0x1281B0];
    UnkStruct_0038BB70_e1 field_12A980[1];  // [G] element count unknown
};

struct UnkStruct_D_0064D384 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0038BB70 {
    unsigned char pad_0[0x4C];
    int field_4C;
};

extern UnkStruct_D_0055EFEC D_0055EFEC;
extern UnkStruct_D_0055D7FE D_0055D7FE;
extern UnkStruct_D_0064D3A0 D_0064D3A0;
extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_D_0064D384 D_0064D384;
extern CB3CrashActionDirector D_0055E948;

extern "C" void SetFinished__10CB3RaceCarF19EB3ScoreFinishState(void *, EB3ScoreFinishState);  // CB3RaceCar::SetFinished(EB3ScoreFinishState)
extern "C" int OnEvent__13CB3ScoreBonusF16EScoreBonusEventiib(void *, EScoreBonusEvent, int, int, bool);  // CB3ScoreBonus::OnEvent(EScoreBonusEvent,int,int,bool)
extern "C" void func_001CC520(UnkStruct_0038BB70_4 *, int, int, float);

// 0x0038BB70
extern "C" void func_0038BB70(UnkStruct_0038BB70 * self, UnkStruct_0038BB70_a1 * p0)
{
    int t0 = self->field_4C;
    self->field_4C = (t0 + 1);
    p0->field_10C2 = (t0 + 1);
    SetFinished__10CB3RaceCarF19EB3ScoreFinishState(p0, (EB3ScoreFinishState)2);
    p0->field_10C0.SetNumLives(0);
    signed char t1 = p0->field_19AC;
    UnkStruct_0038BB70_4 * t2 = D_0055EFEC.field_0[t1].field_0;
    if (p0->field_18EA == 0) {
        D_0055E948.StartRaceCarCrashing((CB3RaceCarPhysics*)t2, t1, 0, 0);
        func_001CC520(t2, 10, 0, 0.4f);
        t2->field_CC4->field_1015 = (t2->field_CC4->field_1015 | 24);
    }
    if (p0->field_1914 == 0) {
        D_0055D7FE.field_0 = 1;
    }
    for (int i = 0; (i < D_0064D3A0.field_0); i++) {
        UnkStruct_0038BB70_a1 * car = (UnkStruct_0038BB70_a1 *)((char *)&D_00522660.field_0[i] + 0x12AD50);
        if (car != 0) {
            if (car->field_1998 != 0) {
                if (car != p0) {
                    int t3 = 5 - D_0064D384.field_0;
                    if (t3 >= 0) {
                        if (t3 < 4) {
                            OnEvent__13CB3ScoreBonusF16EScoreBonusEventiib(car->field_11E4, (EScoreBonusEvent)(t3 + 137), 0, -1, 0);
                        }
                    }
                }
            }
        }
    }
}
