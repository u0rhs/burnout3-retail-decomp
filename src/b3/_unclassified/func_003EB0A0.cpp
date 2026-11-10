// func_003EB0A0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

extern unsigned long D_004CDB30[];  // [G] element count unknown

extern "C" int FindChallengeIndex__25CB3HardCodedRaceStageListFUl(unsigned long);

// 0x003EB0A0
extern "C" void func_003EB0A0()
{
    for (int i = 0; (i < 26); i++) {
        FindChallengeIndex__25CB3HardCodedRaceStageListFUl(D_004CDB30[i]);
    }
}
