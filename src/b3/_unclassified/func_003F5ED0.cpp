// func_003F5ED0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

extern unsigned long D_004CE500[];  // [G] element count unknown

extern "C" int FindChallengeIndex__25CB3HardCodedRaceStageListFUl(unsigned long);

// 0x003F5ED0
extern "C" int func_003F5ED0(int n0)
{
    return FindChallengeIndex__25CB3HardCodedRaceStageListFUl(D_004CE500[n0]);
}
