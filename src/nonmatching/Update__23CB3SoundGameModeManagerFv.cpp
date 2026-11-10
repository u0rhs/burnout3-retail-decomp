// NONMATCHING: Update__23CB3SoundGameModeManagerFv -- retail 187 / ours 186 instructions, 7 in changed runs
// near15: D_0051BA88 as 16-byte struct {ptr field_0} (lui/lw, fixes the prologue) + 'if (m != false)' restores the sltu (7 off). Left: the scan loop's not-found block (sw -1800; b top; addiu j) is laid out at the function end; retail keeps it after the found block. for/while/continue/goto/inline-with-return forms and scoped opt_repositioncode off (79 off) tried
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// a252: logic complete, 11 instrs changed. Open: loop 2 (D_0064D3A0 scan) layout -- retail keeps the else block (sw -1800; b top; addiu j) inline after the then block with a top-tested loop, ours moves it to the function end / rotates the loop; retail also materialises (x&0x200)!=0 via sltu; li v1,3 order at top. += 300 on _gnCurrentReverbLevel and 'if (x <= 10)' ramp forms fixed other hunks; N140 pad needed for frame 0x90

// Hand-written; the lifter refused it (a252).
class CB3HUDSoundManager { public: void Update(); };
class CB3SoundTrafficManager { public: void Update(bool); };
class CB3SoundRaceCarManager { public: void Update(); };
class CB3SoundCrashManager { public: void Update(); };
class CB3SoundStaticPassManager { public: void Update(); };
class CB3SoundDistortion { public: void StartDistortion(); void Update(); void StopDistortion(); };
class CB3SoundManager { public: void SetMasterVolumeScalar(float); };
struct UnkStruct_D_01E75640 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_0049C3B0 { int field_0; unsigned char pad_4[0x2C]; };
struct UnkStruct_D_0051BA88 { unsigned char pad_0[0xA0]; int field_A0; };
struct UnkStruct_Rec1160 { unsigned char pad_0[0x1160]; unsigned short field_1160; };
struct UnkStruct_D_0051BAA4 { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_0051BA94 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_00522660 { unsigned char pad_0[0x130000]; };
struct UnkStruct_D_0064D3A0 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E77518 { int field_0; unsigned char pad_4[0xC]; };

struct UnkStruct_00289BF0_pad { int x[4]; UnkStruct_00289BF0_pad() {} ~UnkStruct_00289BF0_pad() {} };

class CB3SoundGameModeManager {
public:
    void Update();
    void UpdateGameStates();
    void UpdateTakedownPitcher();

    unsigned char pad_0[0x10];
    CB3SoundRaceCarManager field_10;
    unsigned char pad_11[0xFBF];
    CB3SoundCrashManager field_FD0;
    unsigned char pad_FD1[0x93F];
    CB3SoundTrafficManager field_1910;
    unsigned char pad_1911[0x19AF];
    CB3HUDSoundManager field_32C0;
    unsigned char pad_32C1[0x7F];
    CB3SoundStaticPassManager field_3340;
    unsigned char pad_3341[0x1BF];
    CB3SoundDistortion field_3500;
    unsigned char pad_3501[0x1DCB];
    unsigned char field_52CC;
};

extern UnkStruct_D_0049C3B0 D_0049C3B0;
struct UnkStruct_D_0051BA88_p { UnkStruct_D_0051BA88 * field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_0051BA88_p D_0051BA88;
extern UnkStruct_D_0051BAA4 D_0051BAA4;
extern UnkStruct_D_0051BA94 D_0051BA94;
extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_D_0064D3A0 D_0064D3A0;
extern UnkStruct_D_01E75640 D_01E75640;
extern UnkStruct_D_01E77518 D_01E77518;
extern int _gnCurrentReverbLevel;
extern int _gnLastSetRoomLevel;
extern "C" void func_003FACC0(void *);
extern "C" void _rwaSPU2OutputSetEnvironment(int, void *);

static inline int ug_pabsw(int x)
{
    int r;
    asm("pabsw %0,%1" : "=r"(r) : "r"(x));
    return r;
}
static inline long ug_pextlw0(int x)
{
    long r;
    asm("pextlw %0,$0,%1" : "=r"(r) : "r"(x));
    return r;
}

void CB3SoundGameModeManager::Update()
{
    UnkStruct_00289BF0_pad padx;
    UnkStruct_D_0049C3B0 loc = D_0049C3B0;
    UnkStruct_D_0051BA88 * s0 = D_0051BA88.field_0;
    bool s2 = false;
    bool s1 = false;
    field_32C0.Update();
    if (D_0051BAA4.field_0 != 0 && s0 != 0) {
        s1 = true;
    }
    if (s1) {
        UpdateGameStates();
    }
    if (D_0051BA94.field_0 != -1) {
        return;
    }
    func_003FACC0((char *)this + 0x3348);
    if (s1) {
        if (!(field_52CC > 10)) {
            ((CB3SoundManager *)&D_01E75640)->SetMasterVolumeScalar((float)(unsigned int)field_52CC / 10.0f);
            field_52CC = field_52CC + 1;
        }
        int n = s0->field_A0;
        if (n > 0) {
            for (int i = 0; i < n; i++) {
                s2 = (s2 | *((unsigned char *)&D_00522660 + i * 0x27D0 + 0x12BF2E)) != 0;
            }
            UpdateGameStates();
            field_1910.Update(s2);
            field_10.Update();
            field_FD0.Update();
            field_3340.Update();
            field_3500.StartDistortion();
            field_3500.Update();
            int j = 0;
            do {
                if (!(j < D_0064D3A0.field_0)) break;
                UnkStruct_Rec1160 *rc = *(UnkStruct_Rec1160 **)((char *)&D_00522660 + j * 0x27D0 + 0x12D180);
                if (rc != 0) {
                    bool m = (rc->field_1160 & 0x200) != 0;
                    if (m != false) {
                        loc.field_0 = -450;
                        break;
                    }
                }
                loc.field_0 = -1800;
                j++;
            } while (true);
            UpdateTakedownPitcher();
        } else {
            loc.field_0 = -10000;
            field_3500.StopDistortion();
        }
        if (ug_pextlw0(ug_pabsw(loc.field_0 - _gnCurrentReverbLevel)) >= 300) {
            if (_gnCurrentReverbLevel < loc.field_0) {
                _gnCurrentReverbLevel += 300;
            } else {
                _gnCurrentReverbLevel -= 300;
            }
            loc.field_0 = _gnCurrentReverbLevel;
        }
        if (loc.field_0 != _gnLastSetRoomLevel) {
            _rwaSPU2OutputSetEnvironment(D_01E77518.field_0, &loc);
            _gnLastSetRoomLevel = loc.field_0;
        }
    }
}
