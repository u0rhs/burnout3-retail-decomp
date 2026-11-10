// NONMATCHING: ExtractActiveBody__17CB3PhysicsManagerFi -- retail 130 / ours 130 instructions, 19 in changed runs
// near19: natural form -- entries are one array UnkStruct_e field_E5F0[3][0x990] (0xE5F0+3*0x4C80 = 0x1CB70) with member-wise copies; MWCC itself hoists the per-field large-offset bases. Left 19: base registers (retail E5F8->s2, ours E5FE->s1; shared i*8 in t6 vs t0) and t1/t2 swap in the last loop
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CB3PhysicsManager::ExtractActiveBody(int)
struct UnkStruct_001B7C00_e {
    float field_0;
    short field_4;
    unsigned char field_6;
    unsigned char pad_7;
};

class CB3PhysicsManager {
public:
    void ExtractActiveBody(int p0);
    unsigned char pad_0[0xE5F0];
    UnkStruct_001B7C00_e field_E5F0[3][0x990];
    int field_1CB70;
    int field_1CB74;
};

// 0x001B7C00
void CB3PhysicsManager::ExtractActiveBody(int p0)
{
    int i;
    for (int g = 0; g < 3; g++) {
        i = 0;
        while (field_E5F0[g][i].field_4 != p0) i++;
        while (field_E5F0[g][i + 1].field_4 != p0) {
            field_E5F0[g][i].field_0 = field_E5F0[g][i + 1].field_0;
            field_E5F0[g][i].field_4 = field_E5F0[g][i + 1].field_4;
            field_E5F0[g][i].field_6 = field_E5F0[g][i + 1].field_6;
            i++;
        }
        for (; i < field_1CB74 - 2; i++) {
            field_E5F0[g][i].field_0 = field_E5F0[g][i + 2].field_0;
            field_E5F0[g][i].field_4 = field_E5F0[g][i + 2].field_4;
            field_E5F0[g][i].field_6 = field_E5F0[g][i + 2].field_6;
        }
    }
    field_1CB74 -= 2;
    for (int g = 0; g < 3; g++) {
        for (int j = 0; j < field_1CB74; j++) {
            if (field_E5F0[g][j].field_4 == field_1CB70) field_E5F0[g][j].field_4 = p0;
        }
    }
}
