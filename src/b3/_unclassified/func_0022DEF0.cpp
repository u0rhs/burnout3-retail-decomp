// func_0022DEF0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (char-array member at 0x6E4 (no CSE), shared tail, switch default/-15/{-14,-1 via goto [G]}, clear-loop store order for reloc order).

// func_0022DEF0 -- hand-written (fresh1) from the lifted draft.
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0022DEF0;
struct UnkStruct_0022DEF0_6;
struct UnkStruct_0022DEF0_e2;
struct UnkStruct_D_01D6EE00;
struct UnkStruct_D_01D7AF00;

struct UnkStruct_D_01D7AF00 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0022DEF0_6 {
    int field_0;
    int field_4;
};

struct UnkStruct_0022DEF0_e2 {
    unsigned char pad_0[0x1340];
};

struct UnkStruct_D_01D6EE00 {
    UnkStruct_0022DEF0_e2 field_0[10];  // [G] element count: the 10-entry flag arrays
};

struct UnkStruct_0022DEF0 {
    unsigned char pad_0[0x14];
    int field_14;
    int field_18;
    unsigned char pad_1C[0x30];
    unsigned char field_4C;
    unsigned char field_4D;
    unsigned char field_4E;
    unsigned char pad_4F[0x51];
    int field_A0;
    unsigned char pad_A4[0x640];
    unsigned char field_6E4[0x10];  // [G] size: a char array (an address MWCC does not CSE)
};

extern unsigned char D_01D7AE90[];  // [G] 10 used
extern unsigned char D_01D7AE80[];  // [G] 10 used
extern UnkStruct_D_01D7AF00 D_01D7AF00;
extern UnkStruct_D_01D6EE00 D_01D6EE00;

extern "C" void sceNetcnfifInit(UnkStruct_0022DEF0 *);
extern "C" int sceNetcnfifCreateMc2Thread(int);
extern "C" int ezNetCnfInit();
extern "C" void sceNetcnfifDeleteMc2Thread(int);
extern "C" void sceNetcnfifTerm();
extern "C" int ezNetCnfGetCombinationList(void *, int, void *);
extern "C" UnkStruct_0022DEF0_6 * ezNetCnfGetCombination(void *, int);
extern "C" int ezNetCnfGetProperties(void *, void *, void *);
extern "C" int ezNetCnfExit();

// 0x0022DEF0
extern "C" void func_0022DEF0(UnkStruct_0022DEF0 * self)
{
    if (self->field_4D == 0) {
        sceNetcnfifInit(self);
        self->field_A0 = sceNetcnfifCreateMc2Thread(1);
        if (ezNetCnfInit() != 0) {
            sceNetcnfifDeleteMc2Thread(self->field_A0);
            self->field_A0 = -1;
            sceNetcnfifTerm();
            self->field_14 = 3;
            self->field_18 = 4;
            self->field_4E = 0;
            return;
        }
        int r = ezNetCnfGetCombinationList(self->field_6E4, 7, &D_01D7AF00);
        if (r > 0) {
            int i;
            for (i = 0; i < 10; i++) {
                D_01D7AE80[i] = 0;
                D_01D7AE90[i] = 0;
            }
            for (i = 0; i < D_01D7AF00.field_0; i++) {
                UnkStruct_0022DEF0_6 * c = ezNetCnfGetCombination(&D_01D7AF00, i + 1);
                if (c != 0 && c->field_0 >= 0) {
                    if (ezNetCnfGetProperties(self->field_6E4, (char *)c + 0x8, &D_01D6EE00.field_0[i]) >= 0) {
                        D_01D7AE80[i] = 1;
                    }
                    if ((unsigned int)(c->field_4 - 3) <= 1) {
                        D_01D7AE90[i] = 1;
                    }
                }
            }
        } else {
            switch (r) {
            default:
                self->field_14 = 3;
                self->field_18 = 4;
                self->field_4E = 0;
                break;
            case -14:
            case -1:
                goto five;  // [G] goto: retail tests -15, -1, -14 but lays the -1/-14 block last
            case -15:
                self->field_14 = 3;
                self->field_18 = 3;
                self->field_4E = 0;
                break;
            five:
                self->field_14 = 3;
                self->field_18 = 5;
                self->field_4E = 0;
                break;
            }
        }
        ezNetCnfExit();
        sceNetcnfifDeleteMc2Thread(self->field_A0);
        self->field_A0 = -1;
        sceNetcnfifTerm();
    }
    self->field_4C = 1;
}
