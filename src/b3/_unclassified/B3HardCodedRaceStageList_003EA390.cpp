// CB3HardCodedRaceStageList::GetNumStagesInChallenge(int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3HardCodedRaceStageList.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (early return, no int/unsigned casts on 64-bit index).

// CB3HardCodedRaceStageList::GetNumStagesInChallenge(int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3HardCodedRaceStageList.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3HardCodedRaceStageList;

class CB3HardCodedRaceStageList {
public:
    static int GetNumStagesInChallenge(int p0);
};

extern unsigned long kaB3HardCodedRaceChallengeList[];  // [G] element count unknown
extern int kanGPChallengeStageNumber[];  // [G] element count unknown

// 0x003EA390
int CB3HardCodedRaceStageList::GetNumStagesInChallenge(int p0)
{
    unsigned long t0 = kaB3HardCodedRaceChallengeList[p0];
    if (t0 < 7) {
        return kanGPChallengeStageNumber[t0];
    }
    return 1;
}
