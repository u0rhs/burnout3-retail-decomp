// func_003C1E00 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (D_01EA5470 as an 8-entry 0x38-byte record table; const record parameter (loads hoist above the stores); per-field copy into the first free entry, then field_0 = 1; break).

// func_003C1E00 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

// 0x38-byte record [G]: the table entries (D_01EA5470[8]) and the argument share this layout (member-wise copy)
struct UnkStruct_003C1E00_rec {
    unsigned char field_0;
    unsigned char field_1;
    unsigned char field_2;
    unsigned char field_3;
    int field_4;
    float field_8;
    float field_C;
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    int field_24;
    unsigned char field_28;
    unsigned char field_29;
    unsigned char pad_2A[0x2];
    int field_2C;
    int field_30;
    int field_34;
};

extern UnkStruct_003C1E00_rec D_01EA5470[8];  // [G] count: the loop bound

// 0x003C1E00
extern "C" void func_003C1E00(int n0, const UnkStruct_003C1E00_rec * p0)
{
    for (int i = 0; i < 8; i++) {
        if (D_01EA5470[i].field_0 == 0) {
            D_01EA5470[i].field_0 = p0->field_0;
            D_01EA5470[i].field_1 = p0->field_1;
            D_01EA5470[i].field_2 = p0->field_2;
            D_01EA5470[i].field_3 = p0->field_3;
            D_01EA5470[i].field_4 = p0->field_4;
            D_01EA5470[i].field_8 = p0->field_8;
            D_01EA5470[i].field_C = p0->field_C;
            D_01EA5470[i].field_10 = p0->field_10;
            D_01EA5470[i].field_14 = p0->field_14;
            D_01EA5470[i].field_18 = p0->field_18;
            D_01EA5470[i].field_1C = p0->field_1C;
            D_01EA5470[i].field_20 = p0->field_20;
            D_01EA5470[i].field_24 = p0->field_24;
            D_01EA5470[i].field_28 = p0->field_28;
            D_01EA5470[i].field_29 = p0->field_29;
            D_01EA5470[i].field_2C = p0->field_2C;
            D_01EA5470[i].field_30 = p0->field_30;
            D_01EA5470[i].field_34 = p0->field_34;
            D_01EA5470[i].field_0 = 1;
            break;
        }
    }
}
