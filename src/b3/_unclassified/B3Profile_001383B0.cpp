// CB3Profile::EvaluateTrackUnlocking() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3Profile.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a90: hand-written; local gCalculatedData overlay with field_38 (header has pad_38)).

struct UnkStruct_gCalculatedData { unsigned char pad_0[0x38]; int field_38; unsigned char pad_3C[0x10]; };
class CB3HardCodedRaceStageList {
public:
    static int GetNumStagesInChallenge(int);
};
extern "C" unsigned long GetStageGtID__25CB3HardCodedRaceStageListFii(int, int);
extern "C" unsigned long GetStageTrackID__25CB3HardCodedRaceStageListFUl(unsigned long);
extern "C" int DoesChallengeUnlockTracks__25CB3HardCodedRaceStageListFi(int);
class CB3HardCodedTrackList {
public:
    static int FindTrack(unsigned long);
};
struct UnkStruct_D_0051BFA0 {
    unsigned char pad_0[0x57];
    unsigned char field_57[0x49];
    unsigned char pad_A0[0x64];
    unsigned char field_104[0x24];
};
struct UnkStruct_D_0051C0A8 { unsigned char field_0; unsigned char pad_1[0xF]; };
extern UnkStruct_D_0051BFA0 D_0051BFA0;
extern UnkStruct_D_0051C0A8 D_0051C0A8;
extern UnkStruct_gCalculatedData gCalculatedData;

class CB3Profile {
public:
    void EvaluateTrackUnlocking();
    unsigned char pad_0[0x386];
    signed char field_386[1];
};

#define G38 gCalculatedData.field_38
// 0x00137FE0
void CB3Profile::EvaluateTrackUnlocking()
{
    int i;
    int j;
    for (i = 0; i < 0x24; i++) {
        D_0051BFA0.field_104[i] = 0;
    }
    for (i = 0; i < 0x49; i++) {
        if (D_0051BFA0.field_57[i] != 0) {
            if (DoesChallengeUnlockTracks__25CB3HardCodedRaceStageListFi(i) != 0) {
                if (field_386[i] > 0) {
                    int n = CB3HardCodedRaceStageList::GetNumStagesInChallenge(i);
                    for (j = 0; j < n; j++) {
                        int t = CB3HardCodedTrackList::FindTrack(GetStageTrackID__25CB3HardCodedRaceStageListFUl(GetStageGtID__25CB3HardCodedRaceStageListFii(i, j)));
                        if (t != -1) {
                            D_0051BFA0.field_104[t] = 1;
                        }
                    }
                }
            }
        }
    }
    D_0051C0A8.field_0 = 1;
    G38 = 0;
    for (int k = 0; k < 0x24; k++) {
        if (D_0051BFA0.field_104[k] != 0) {
            G38 = G38 + 1;
        }
    }
}
