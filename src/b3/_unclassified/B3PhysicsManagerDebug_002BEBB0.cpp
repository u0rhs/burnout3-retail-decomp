// CB3PhysicsManagerDebug::Update() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3PhysicsManagerDebug.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (mwperm: 'unsigned long bits = *(unsigned long *)(pm + 0xE9218);' -> 'int n = 0;'; 'int n = 0;' -> 'unsigned long bits = *(unsigned long *)(pm + 0xE9218); i = 0;').

struct UnkStruct_PMD_G { unsigned char pad_0[0x10]; };
class CB3PhysicsManagerDebug {
public:
    void Update();
};
extern UnkStruct_PMD_G D_0055EF70;
extern int _gnMaxBodyCount;
extern int _gnMaxOverlapCount;
extern int _gnMaxCrashingTrafficCount;
extern int _gnMaxDynamicPropCount;
extern int _gnMaxBodyPartCount;
// 0x002BEBB0
void CB3PhysicsManagerDebug::Update()
{
    char *pm = (char *)&D_0055EF70;
    int c = *(int *)(pm + 0x1CB70);
    if (c > _gnMaxBodyCount) _gnMaxBodyCount = c;
    c = *(int *)(pm + 0xE9210);
    if (c > _gnMaxOverlapCount) _gnMaxOverlapCount = c;
    c = *(int *)(pm + 0xE620C);
    if (c > _gnMaxCrashingTrafficCount) _gnMaxCrashingTrafficCount = c;
    {
        unsigned long bits = *(unsigned long *)(pm + 0xE9220);
        int n = 0;
        int i;
        unsigned long m = 1;
        for (i = 0; i < 32; i++) {
            if (bits & m) n++;
            m <<= 1;
        }
        if (n > _gnMaxDynamicPropCount) _gnMaxDynamicPropCount = n;
    }
    {
        int n = 0;
        int i;
        unsigned long m = 1;
        unsigned long bits = *(unsigned long *)(pm + 0xE9218);
        i = 0;
        for (i = 0; i < 64; i++) {
            if (bits & m) n++;
            m <<= 1;
        }
        if (n > _gnMaxBodyPartCount) _gnMaxBodyPartCount = n;
    }
}
