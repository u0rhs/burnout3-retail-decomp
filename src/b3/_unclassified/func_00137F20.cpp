// func_00137F20 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (for loop; switch on func_003E9AD0's result assigns k = 1..4 per case (MWCC reuses the compare register, so the case blocks merge), default: continue; then field_15A[k] = 1 (field_15B..15E as one array)).

class CB3HardCodedRaceStageList;
struct UnkStruct_D_0051BFA0;

class CB3HardCodedRaceStageList {
public:
    static unsigned long GetStageGtID(int, int);  // w64: 64-bit id [C retail 0x3EA0D8 ld v0]; was `int` (same bytes, host truncated)
};

struct UnkStruct_D_0051BFA0 {
    unsigned char pad_0[0x57];
    unsigned char field_57[1];  // [G] element count unknown
    unsigned char pad_58[0x102];
    unsigned char field_15A[5];  // [G] indexed by func_003E9AD0's 1..4 result
};

extern UnkStruct_D_0051BFA0 D_0051BFA0;

extern "C" int func_003E9AD0(unsigned long);  // w64: compares a0 with 64-bit ids [C retail 0x3E9AD8]; was `int`

// 0x00137F20
extern "C" void func_00137F20(void *a0 /* passed by every caller, not read here */)
{
    for (int i = 0; i < 73; i++) {
        if (D_0051BFA0.field_57[i] != 0) {
            int r = func_003E9AD0(CB3HardCodedRaceStageList::GetStageGtID(i, 0));
            int k;
            switch (r) {
            case 1:
                k = 1;
                break;
            case 2:
                k = 2;
                break;
            case 3:
                k = 3;
                break;
            case 4:
                k = 4;
                break;
            default:
                continue;
            }
            D_0051BFA0.field_15A[k] = 1;
        }
    }
}
