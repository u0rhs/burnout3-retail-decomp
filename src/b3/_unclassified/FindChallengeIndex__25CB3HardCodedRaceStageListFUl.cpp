// Hand-written; the lifter refused it (near3: 'if (found) break;' inside the t0 < 7 arm, and the direct-id arm is 'found = true; break;' (its own daddiu 1, bne to p0++)).


// FindChallengeIndex__25CB3HardCodedRaceStageListFUl -- [L] DNAT: CB3HardCodedRaceStageList::FindChallengeIndex(unsigned long) (research/proto/new_names.csv, high)
extern unsigned long kaB3HardCodedRaceChallengeList[];  // [G] element count unknown
extern int kanGPChallengeStageNumber[];  // [G] element count unknown
extern unsigned long * kapGPChallengeStageArrays[];  // [G] element count unknown

static inline bool func_003EA3E0_inl1() { return true; }

// 0x003EA3E0
extern "C" int FindChallengeIndex__25CB3HardCodedRaceStageListFUl(unsigned long n0)
{
    int p0;
    int i;
    bool found = false;
    for (p0 = 0; p0 < 73; p0++) {
        unsigned long t0 = kaB3HardCodedRaceChallengeList[p0];
        if (t0 < 7) {
            int id = (int)t0;
            for (i = 0; i < kanGPChallengeStageNumber[id]; i++) {
                if (n0 == kapGPChallengeStageArrays[id][i]) {
                    found = func_003EA3E0_inl1();
                    break;
                }
            }
            if (found) break;
        } else if (t0 == n0) {
            found = true;
            break;
        }
    }
    return found ? p0 : -1;
}
