// func_004699B0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (CRC32 table init: inner loop is for(unsigned char j=8;j>0;j--) with j declared before m0; (int)((unsigned long)(m0>>1)^0xEDB88320UL)).

// func_004699B0 -- CRC32 table init. [G] (0xEDB88320 reflected polynomial)
struct UnkStruct_D_004B13C0 {
    unsigned int * field_0;
    unsigned char pad_4[0xC];
};
struct UnkStruct_D_004B13D0 {
    int field_0;
    unsigned char pad_4[0xC];
};
struct UnkStruct_D_004B13CC {
    int field_0;
    unsigned char pad_4[0xC];
};
struct UnkStruct_D_004B13C4 {
    int field_0;
    unsigned char pad_4[0xC];
};
struct UnkStruct_D_004B13C8 {
    int field_0;
    unsigned char pad_4[0xC];
};
extern UnkStruct_D_004B13C0 D_004B13C0;
extern UnkStruct_D_004B13D0 D_004B13D0;
extern UnkStruct_D_004B13CC D_004B13CC;
extern UnkStruct_D_004B13C4 D_004B13C4;
extern UnkStruct_D_004B13C8 D_004B13C8;

extern "C" unsigned int * func_00360AE0(int, int, int);

// 0x004699B0
extern "C" int func_004699B0(int n0)
{
    if (D_004B13C0.field_0 != 0)
        return 5;
    unsigned int *r0 = func_00360AE0(n0, 1024, 4);
    D_004B13C0.field_0 = r0;
    if (r0 == 0)
        return 1;
    D_004B13D0.field_0 = n0;
    for (unsigned int i = 0; i < 256; i++) {
        unsigned char j;
        int m0 = i;
        for (j = 8; j > 0; j--) {
            if ((m0 & 1) != 0) {
                m0 = (int)((unsigned long)((unsigned int)m0 >> 1) ^ 0xEDB88320UL);
            } else {
                m0 = (unsigned int)m0 >> 1;
            }
        }
        r0[i] = m0;
    }
    D_004B13CC.field_0 = -1;
    D_004B13C4.field_0 = 4;
    D_004B13C8.field_0 = 0;
    return 0;
}
