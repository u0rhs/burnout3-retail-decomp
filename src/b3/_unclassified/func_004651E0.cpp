// func_004651E0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (a72: declaration fix only (16-byte element with 4 fields, char* field_4/field_98, element pointer e)).

struct UnkStruct_004651E0_e0 {
    int field_0;
    char * field_4;
    int field_8;
    int field_C;
};

struct UnkStruct_004651E0_1 {
    unsigned char pad_0[0x90];
    int field_90;
    int field_94;
    char * field_98;
    UnkStruct_004651E0_e0 * field_9C;
};

struct UnkStruct_D_004E2FBC {
    UnkStruct_004651E0_1 * field_0;
};

extern UnkStruct_D_004E2FBC D_004E2FBC;

extern "C" void * memcpy(void *, const void *, unsigned int);

// 0x004651E0
extern "C" char * func_004651E0(int n0, int p0, void *p1_)
{
    int p1 = (int)p1_;
    UnkStruct_004651E0_1 * t0 = D_004E2FBC.field_0;
    int t1 = t0->field_94;
    if (t1 == t0->field_90) {
        return t0->field_98;
    }
    UnkStruct_004651E0_e0 * t2 = t0->field_9C;
    UnkStruct_004651E0_e0 * e = &t2[t1];
    if (t1 == 0) {
        t2->field_4 = 0;
    }
    e->field_0 = n0;
    e->field_8 = p0;
    memcpy(&e->field_C, (const void *)p1, 4);
    D_004E2FBC.field_0->field_94 = D_004E2FBC.field_0->field_94 + 1;
    int v0 = p0 + 12;
    if (v0 == 0) {
        v0 = 1;
    }
    D_004E2FBC.field_0->field_98 = e->field_4 + v0;
    UnkStruct_004651E0_1 * t3 = D_004E2FBC.field_0;
    if (t3->field_94 != t3->field_90) {
        e[1].field_4 = t3->field_98;
    }
    return e->field_4;
}
