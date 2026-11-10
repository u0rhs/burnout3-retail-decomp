// func_003E8C20 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

// 0x003E8C20
extern "C" int func_003E8C20(int n0)
{
    switch (n0) {
    case 0:
    case 6:
    case 14:
    case 20:
    case 26:
    case 34:
    case 40:
    case 46:
    case 54:
    case 60:
    case 66:
    case 74:
    case 80:
    case 86:
    case 94:
        return 2702;
    case 5:
    case 25:
    case 45:
    case 65:
    case 85:
        return 2704;
    case 13:
    case 33:
    case 53:
    case 73:
    case 93:
        return 2705;
    case 19:
    case 39:
    case 59:
    case 79:
    case 89:
        return 2706;
    case 99:
        return 2707;
    default:
        return 2703;
    }
}
