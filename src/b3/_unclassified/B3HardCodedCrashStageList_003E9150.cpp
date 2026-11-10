// CB3HardCodedCrashStageList::IsChallengeOnThisCircuit(EB3TrackRegion,int,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3HardCodedCrashStageList.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (static method; two char[16] stack buffers (id, name); switch in source order 0,1,2; GtIDCompress (GtIDCompress__FPCc) result in an unsigned long local).

enum EB3TrackRegion {};

class CB3HardCodedCrashStageList {
public:
    static bool IsChallengeOnThisCircuit(EB3TrackRegion p0, int p1, int p2);
};

extern unsigned long kaB3HardCodedCrashStageList[];  // [G] element count unknown
extern unsigned long kaB3HardCodedCrashCircuitList[];  // [G] element count unknown

extern "C" void func_0021ADF0(unsigned long, char *);
extern "C" unsigned long GtIDCompress__FPCc(const char *);

// 0x003E9150
bool CB3HardCodedCrashStageList::IsChallengeOnThisCircuit(EB3TrackRegion p0, int p1, int p2)
{
    int v3;
    int v2;
    switch (p0) {
    case 0:
        v3 = 0;
        v2 = 6;
        break;
    case 1:
        v3 = 3;
        v2 = 8;
        break;
    case 2:
        v3 = 7;
        v2 = 4;
        break;
    }
    char id[16];
    char name[16];
    func_0021ADF0(kaB3HardCodedCrashStageList[p1], id);
    name[0] = id[6];
    name[1] = id[7];
    name[2] = '_';
    name[3] = id[8];
    name[4] = id[9];
    name[5] = 0;
    unsigned long r = GtIDCompress__FPCc(name);
    return r == kaB3HardCodedCrashCircuitList[v3 + (p2 - v2)];
}
