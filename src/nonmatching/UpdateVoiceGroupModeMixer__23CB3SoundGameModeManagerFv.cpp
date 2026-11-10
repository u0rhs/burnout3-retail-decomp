// NONMATCHING: UpdateVoiceGroupModeMixer__23CB3SoundGameModeManagerFv -- retail 166 / ours 166 instructions, 103 in changed runs
// lit4fix: .lit4 externs rewritten as literals; was: a122: EXACT length 166; logic+instruction forms right (narrowing, 0xB4 stride, found bool, split hi/lo/off). Left: register allocation only (retail n=a3,i=t0,mask=a2, cnt=s0,g=s1 plus narrowed copy a1=g for index; ours t0/a0/s1 shuffled) - decl-order swaps did not move it
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

struct UnkStruct_00289080_g { float field_0; float field_4; unsigned char field_8; unsigned char pad_9[3]; };
struct UnkStruct_00289080_m { UnkStruct_00289080_g field_0[15]; };
struct UnkStruct_00289080_o { float field_0; float field_4; };
struct UnkStruct_D_01E7569C { unsigned char pad_0[0x10]; };
extern UnkStruct_D_01E7569C D_01E7569C;
extern "C" UnkStruct_00289080_m _gaVoiceGroupModeData[];
extern "C" void SetGroupTransition__20CGtSoundVoiceManagerFUiPC18CGtSoundVoiceGroupf(void *, unsigned int, const void *, float);
class CB3SoundGameModeManager {
public:
    void UpdateVoiceGroupModeMixer();
    unsigned int field_0;
    unsigned char pad_4[0x523C];
    UnkStruct_00289080_o field_5240[15];
};
void CB3SoundGameModeManager::UpdateVoiceGroupModeMixer()
{
    signed char list[16];
    signed char n = 0;
    signed char i = 0;
    unsigned int mask = field_0;
    do {
        if ((1 << i) & mask) {
            list[n] = i;
            n = n + 1;
        }
        i = i + 1;
    } while (i < 12);
    if (n == 0) return;
    signed char cnt = n;
    signed char g = 0;
    do {
        signed char hi = 0;
        signed char lo = 0;
        bool found = false;
        signed char j = 0;
        int off = g * 12;
        UnkStruct_00289080_g *base = (UnkStruct_00289080_g *)((char *)_gaVoiceGroupModeData + off);
        while (j < cnt) {
            UnkStruct_00289080_g *e = (UnkStruct_00289080_g *)((char *)base + list[j] * 0xB4);
            if (e->field_8 != 0) {
                UnkStruct_00289080_g *h = (UnkStruct_00289080_g *)((char *)base + list[hi] * 0xB4);
                if (e->field_4 > h->field_4) hi = j;
                found = true;
            } else {
                UnkStruct_00289080_g *l = (UnkStruct_00289080_g *)((char *)base + list[lo] * 0xB4);
                if (e->field_4 < l->field_4) lo = j;
            }
            j = j + 1;
        }
        UnkStruct_00289080_g *src;
        if (found) {
            src = (UnkStruct_00289080_g *)((char *)_gaVoiceGroupModeData + list[hi] * 0xB4 + off);
            field_5240[g].field_0 = src->field_0;
            field_5240[g].field_4 = src->field_4;
        } else {
            src = (UnkStruct_00289080_g *)((char *)_gaVoiceGroupModeData + list[lo] * 0xB4 + off);
            field_5240[g].field_0 = src->field_0;
            field_5240[g].field_4 = src->field_4;
        }
        SetGroupTransition__20CGtSoundVoiceManagerFUiPC18CGtSoundVoiceGroupf(&D_01E7569C, g, &field_5240[g], 0.1f);
        g = g + 1;
    } while (g < 15);
}
