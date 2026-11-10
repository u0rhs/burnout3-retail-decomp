// func_0022FC60 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (sibling 0x18-byte record layout (func_0022FE10); element pointers to the last record; cached count local).

// func_0022FC60 -- tiny-function batch (tools/tiny_batch.py, lifted).
struct UnkStruct_0022FC60;
struct UnkStruct_0022FC60_e0;

struct UnkStruct_0022FC60_e0 {
    int field_0;
    void * field_4;
    void * field_8;
    int field_C;
    int field_10;
    int field_14;
};

struct UnkStruct_0022FC60 {
    unsigned char pad_0[0x2C];
    UnkStruct_0022FC60_e0 field_2C[24];
    UnkStruct_0022FC60_e0 field_26C[24];
    int field_4AC;
};

extern "C" void func_0022DA20(void *);

// 0x0022FC60
extern "C" void func_0022FC60(UnkStruct_0022FC60 * self, int p0)
{
    int n = self->field_4AC;
    for (int i = 0; i < n; i++) {
        if (self->field_2C[i].field_0 == p0) {
            if (self->field_26C[i].field_8 != 0) {
                func_0022DA20(self->field_26C[i].field_8);
            }
            int t2 = self->field_4AC;
            if (t2 <= 1) {
                self->field_2C[i].field_0 = -1;
                self->field_2C[i].field_4 = (void *)-1;
                self->field_2C[i].field_8 = 0;
                self->field_26C[i].field_0 = -1;
                self->field_26C[i].field_4 = (void *)-1;
                self->field_26C[i].field_8 = 0;
            } else {
                UnkStruct_0022FC60_e0 * e2 = &self->field_2C[t2 - 1];
                self->field_2C[i].field_0 = e2->field_0;
                self->field_2C[i].field_4 = e2->field_4;
                self->field_2C[i].field_8 = e2->field_8;
                self->field_2C[i].field_C = e2->field_C;
                self->field_2C[i].field_10 = e2->field_10;
                self->field_2C[i].field_14 = e2->field_14;
                UnkStruct_0022FC60_e0 * e3 = &self->field_26C[self->field_4AC - 1];
                self->field_26C[i].field_0 = e3->field_0;
                self->field_26C[i].field_4 = e3->field_4;
                self->field_26C[i].field_8 = e3->field_8;
                self->field_26C[i].field_C = e3->field_C;
                self->field_26C[i].field_10 = e3->field_10;
                self->field_26C[i].field_14 = e3->field_14;
                UnkStruct_0022FC60_e0 * e4 = &self->field_2C[self->field_4AC - 1];
                e4->field_0 = -1;
                e4->field_4 = (void *)-1;
                e4->field_8 = 0;
                UnkStruct_0022FC60_e0 * e5 = &self->field_26C[self->field_4AC - 1];
                e5->field_0 = -1;
                e5->field_4 = (void *)-1;
                e5->field_8 = 0;
            }
            self->field_4AC--;
            return;
        }
    }
}
