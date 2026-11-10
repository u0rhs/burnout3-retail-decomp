// CB3HardCodedRaceStageList::GetStageGtID(int,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3HardCodedRaceStageList.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (64-bit unsigned long compare t0 < 7 (no 32-bit cast); index with t0 directly).

// lifter variant 0
// CB3HardCodedRaceStageList::GetStageGtID(int,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3HardCodedRaceStageList.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3HardCodedRaceStageList;

class CB3HardCodedRaceStageList {
public:
    static unsigned long GetStageGtID(int p0, int p1);
};

extern unsigned long kaB3HardCodedRaceChallengeList[];  // [G] element count unknown
extern unsigned long * kapGPChallengeStageArrays[];  // [G] element count unknown

// 0x003EA090
unsigned long CB3HardCodedRaceStageList::GetStageGtID(int p0, int p1)
{
    unsigned long t0 = kaB3HardCodedRaceChallengeList[p0];
    if (t0 < 7) {
        t0 = kapGPChallengeStageArrays[t0][p1];
    }
    return t0;
}
