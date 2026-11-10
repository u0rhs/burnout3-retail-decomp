// Hand-written; the lifter refused it (switch on D_004CBD30[n]; [L] DNAT GetStageTypeString).

extern int D_004CBD30[];  // [G] element count unknown

// 0x003E9C00
extern "C" int func_003E9C00(int n0, int n1)
{
    switch (D_004CBD30[n0]) {
    case 0: return 0xBEF;
    case 1: return 0xBF0;
    case 2: return 0xBF1;
    case 3: return 0xBF2;
    case 4: return 0xBF3;
    case 5: return 0xC3D;
    case 6: return 0x9BE;
    case 7: return 0xB43;
    default: return 0x173;
    }
}
