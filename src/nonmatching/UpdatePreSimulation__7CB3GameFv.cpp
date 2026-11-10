// NONMATCHING: UpdatePreSimulation__7CB3GameFv -- retail 136 / ours 122 instructions, 23 in changed runs
// gaps1: hand-drafted from the asm
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// gaps1 (2026-11-02): hand-drafted from the retail asm (0x132090..0x1322AC). Name [C]: the mangled symbol in retail's
// tables (research/retail_names.csv: B3Game.cpp, medium); called first in func_00132600's state 5 (the in-game frame).
// The pause machine: field_2DA54 = the active pause (-1 none), field_2DA58 = a pause request, field_2DA5C = an
// unpause request ([G] meanings from the calls: Stop/Pause/SetPause(1) vs Unpause/SetPause(0)/Start).
// TRACK: clean
// EQUIV: [L] written from the asm: every branch, store and call accounted for

class CB3Game {
public:
    void UpdatePreSimulation();

    unsigned char pad_0[0x7080];
    unsigned char field_7080[0x10];   // [C] the CB3InputManager (SetPause__15CB3InputManagerFb a0)
    unsigned char pad_7090[0x2DA54 - 0x7090];
    int field_2DA54;
    int field_2DA58;
    int field_2DA5C;
    unsigned char pad_2DA60[0x5];
    unsigned char field_2DA65;        // [C] the requested half-rate state
    unsigned char field_2DA66;        // [C] the half-rate flag func_00132600 reads (UpdatePostRenderWait(2, 8))
};

extern unsigned char D_004EB1E0;      // [C] the CB3DebugManager object's first byte, read as a flag
extern unsigned char D_0051BAD4;
extern unsigned char D_00665E50;
extern unsigned char D_00665E51;
extern unsigned char D_00522660[];    // [C] the world's CGtTimer (Start__8CGtTimerFv / Stop__8CGtTimerFv a0)
extern unsigned char D_01E75640[];    // [C] the CB3SoundManager (Pause__15CB3SoundManagerFv a0)

extern "C" void Start__8CGtTimerFv(void *);
extern "C" void Stop__8CGtTimerFv(void *);
extern "C" void Pause__15CB3SoundManagerFv(void *);
extern "C" void Unpause__15CB3SoundManagerFv(void *);
extern "C" void SetPause__15CB3InputManagerFb(void *, bool);
extern "C" void func_001F4290(int);

// 0x00132090
void CB3Game::UpdatePreSimulation()
{
    if (field_2DA54 < 0) {
        if (!(D_00665E51 != 0 || D_00665E50 != 0)) {
            if (D_0051BAD4 != 0 && D_004EB1E0 != 0) {
                Start__8CGtTimerFv(D_00522660);
            } else {
                Stop__8CGtTimerFv(D_00522660);
            }
        }
    }
    if (D_004EB1E0 == 0) {
        return;
    }
    if (field_2DA66 != field_2DA65) {
        field_2DA66 = field_2DA65;
        if (field_2DA66 != 0) {
            func_001F4290(2);
        } else {
            func_001F4290(1);
        }
    }
    if (field_2DA58 != -1) {
        field_2DA54 = field_2DA58;
        Stop__8CGtTimerFv(D_00522660);
        Pause__15CB3SoundManagerFv(D_01E75640);
        SetPause__15CB3InputManagerFb(field_7080, true);
        field_2DA58 = -1;
        field_2DA5C = -1;
    }
    if (field_2DA54 == -1 || field_2DA5C == -1) {
        return;
    }
    if (field_2DA54 == field_2DA5C) {
        field_2DA54 = -1;
        Unpause__15CB3SoundManagerFv(D_01E75640);
        SetPause__15CB3InputManagerFb(field_7080, false);
        Start__8CGtTimerFv(D_00522660);
    }
    field_2DA58 = -1;
    field_2DA5C = -1;
}
