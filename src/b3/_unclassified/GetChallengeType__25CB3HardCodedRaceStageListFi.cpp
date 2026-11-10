// Hand-written; the lifter refused it (ka*/kap* tables declared const (Hungarian k = constant): const loads let sd ra sink into the beqz delay slot (sdra rule 1)).

// GetChallengeType__25CB3HardCodedRaceStageListFi -- [L] DNAT: CB3HardCodedRaceStageList::GetChallengeType(int) (research/proto/new_names.csv, high)
struct UnkStruct_003E9980_i {
    unsigned char pad_0[1];
    signed char field_1;
    unsigned char pad_2[0xE];
};
extern const unsigned long kaB3HardCodedRaceChallengeList[];  // [G] element count unknown
extern const unsigned long * const kapGPChallengeStageArrays[];  // [G] element count unknown
extern "C" void func_0021ADF0(unsigned long, void *);

// 0x003E9980
extern "C" int GetChallengeType__25CB3HardCodedRaceStageListFi(int p0)
{
    UnkStruct_003E9980_i info;
    unsigned long t0 = kaB3HardCodedRaceChallengeList[p0];
    unsigned long id = t0 < 7 ? kapGPChallengeStageArrays[(int)t0][0] : t0;
    func_0021ADF0(id, &info);
    int r = 0;
    switch (info.field_1) {
    case 'A': r = 1; break;
    case 'B': r = 6; break;
    case 'C': r = 7; break;
    case 'D': r = 8; break;
    case 'E': r = 9; break;
    case 'F': r = 10; break;
    case 'G': r = 11; break;
    default:
        if (info.field_1 >= '0' && info.field_1 < ':') r = 2;
        break;
    }
    return r;
}
