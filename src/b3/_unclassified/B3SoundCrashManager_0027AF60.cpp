// CB3SoundCrashManager::UpdateDeadMansHorn() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundCrashManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (sibling UpdateFire's volume shape (k/g/t12/t7/t8 locals, equal-arm ternary store, g*t8 test) fixed FP colouring).

// CB3SoundCrashManager::UpdateDeadMansHorn()
typedef unsigned int u_long128 __attribute__((mode(TI)));

class CGtSoundVoiceParams {
public:
    void Construct();
};

class CGtSoundVirtualVoice {
public:
    void Update(const CGtSoundVoiceParams*);
    void Stop();
};

class CGtSoundWave {
public:
    float CalcFrequency() const;
};

class CGtSoundVoiceManager {
public:
    CGtSoundVirtualVoice * TriggerVoice(const CGtSoundVoiceParams*);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0064D3A0 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0027AF60_v3 {
    float field_0;
    float field_4;
    float field_8;
};

union UnkStruct_0027AF60_q {
    u_long128 field_0;
    float field_f[4];
};

struct UnkStruct_0027AF60_obj {
    unsigned char pad_0[0xB0];
    u_long128 field_B0;
};

struct UnkStruct_0027AF60_car {
    unsigned char pad_0[0x30];
    u_long128 field_30;
    unsigned char pad_40[0x18AA];
    unsigned char field_18EA;
    unsigned char pad_18EB[0xB45];
    UnkStruct_0027AF60_obj * field_2430;
};

struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x27D0];
};

struct UnkStruct_D_00522680 {
    float field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3SoundCrashManager {
public:
    void UpdateDeadMansHorn();

    unsigned char pad_0[0x520];
    int field_520;
    int field_524;
    unsigned char pad_528[0x2C0];
    UnkStruct_0027AF60_v3 field_7E8;
    UnkStruct_0027AF60_v3 field_7F4;
    CGtSoundWave * field_800;
    float field_804;
    unsigned char pad_808[0x4];
    float field_80C;
    unsigned char pad_810[0x1C];
    unsigned char field_82C;
    unsigned char field_82D;
    unsigned char pad_82E[0x1E];
    CGtSoundWave * field_84C;
    unsigned char pad_850[0x18];
    CGtSoundVirtualVoice * field_868;
    unsigned char pad_86C[0x67];
    signed char field_8D3;
    unsigned char pad_8D4[0x2];
    unsigned char field_8D6;
    unsigned char pad_8D7[0x3];
    unsigned char field_8DA;
    unsigned char pad_8DB[0x4];
    unsigned char field_8DF;
};

extern UnkStruct_D_0064D3A0 D_0064D3A0;
extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_D_00522680 D_00522680;
extern float _grDeadMansHornGain;
extern unsigned int _gnMeanCrashesBetweenDeadMansHorn;
extern CGtSoundVoiceManager D_01E7569C;

// 0x0027AF60
void CB3SoundCrashManager::UpdateDeadMansHorn()
{
    if (field_8DA != 0) return;
    int count = 0;
    for (int i = 0; i < D_0064D3A0.field_0; i++) {
        UnkStruct_0027AF60_car * car = (UnkStruct_0027AF60_car *)((char *)&D_00522660 + i * 0x27D0 + 0x12AD50);
        float pos[3];
        UnkStruct_0027AF60_q t;
        unsigned char crashing = car->field_18EA;
        t.field_0 = car->field_30;
        pos[0] = t.field_f[0];
        pos[1] = t.field_f[1];
        pos[2] = t.field_f[2];
        if (crashing != 0) count++;
        CGtSoundVirtualVoice * v = field_868;
        if (v == 0 && crashing != 0) {
            field_520 = (field_520 << 16) + (field_520 >> 16);
            field_520 += field_524;
            field_524 += field_520;
            if ((unsigned int)field_520 % _gnMeanCrashesBetweenDeadMansHorn == 0) {
                CGtSoundWave * w = field_84C;
                float gain = _grDeadMansHornGain;
                if (field_8DF == 0) {
                    ((CGtSoundVoiceParams *)&field_7E8)->Construct();
                    field_7E8 = *(UnkStruct_0027AF60_v3 *)pos;
                    field_804 = gain;
                    field_82D = 1;
                    field_800 = w;
                    field_80C = w->CalcFrequency();
                    field_82C = 3;
                    field_868 = D_01E7569C.TriggerVoice((CGtSoundVoiceParams *)&field_7E8);
                }
                field_8D3 = i;
                field_8D6 = 1;
            } else {
                field_8DA = 1;
            }
        } else if (v != 0 && crashing != 0 && field_8D3 == i) {
            UnkStruct_0027AF60_q t2;
            t2.field_0 = car->field_2430->field_B0;
            field_7F4.field_0 = t2.field_f[0];
            field_7F4.field_4 = t2.field_f[1];
            field_7F4.field_8 = t2.field_f[2];
            float k = 1.0f;
            float g = _grDeadMansHornGain;
            float *t12 = &D_00522680.field_0;
            float t7 = (*t12 - *t12) / k;
            float t8 = 1.0f - t7;
            // [G] both arms equal: the sibling UpdateFire's proven shape; it fixes retail's mul.s operand order.
            field_804 = (0 == t7) ? ((1.0f - t7) * g) : ((k - t7) * g);
            if (g * t8 <= 0.0f) {
                field_868->Stop();
                field_868 = 0;
            } else {
                field_7E8 = *(UnkStruct_0027AF60_v3 *)pos;
                field_868->Update((CGtSoundVoiceParams *)&field_7E8);
            }
        }
    }
    if (count == 0 && field_868 != 0) {
        field_868->Stop();
        field_868 = 0;
    }
}
