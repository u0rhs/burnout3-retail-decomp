// CB3Profile::WillPlayerCarUnlock(int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3Profile.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a137: switch on unlock value, case-3 range loop with lo/hi).

// Hand-written (a137): no lifter draft. [G] struct overlays for CB3Profile/gCalculatedData/D_0051BFA0 offsets used here; case 3 uses lo/hi range per series s0 (loop var is lo).
struct UnkStruct_D_0051BFA0_u { unsigned char field_0[0x43]; unsigned char field_43[20]; unsigned char field_57[73]; unsigned char pad_a0[0x132 - 0xA0]; unsigned char field_132[10]; };
struct UnkStruct_gCalcData_wp {
    unsigned char pad_0[0x20]; int field_20; unsigned char pad_24[0x8]; int field_2C;
    unsigned char pad_30[0xC]; int field_3C; unsigned char pad_40[0x50]; int field_90;
    unsigned char pad_94[0x10]; int field_A4; unsigned char pad_A8[0x24]; int field_CC; unsigned char pad_D0[0x24]; int field_F4;
};
class CB3Profile {
public:
    unsigned char pad_0[0x40];
    unsigned int field_40;
    unsigned int field_44;
    unsigned char pad_48[0x1B8];
    int field_200;
    unsigned char pad_204[0x182];
    signed char field_386[73];
    signed char field_3CF[100];
    unsigned char field_433[20];
    unsigned char field_447[10];
};
extern UnkStruct_D_0051BFA0_u D_0051BFA0;
extern UnkStruct_gCalcData_wp gCalculatedData;
extern "C" int func_003EAF00(int);
extern "C" int func_003EAFC0(int);
extern "C" bool WillPlayerCarUnlock__10CB3ProfileFi(CB3Profile *self, int a1)
{
    int s0 = func_003EAF00(a1);
    bool s1 = false;
    int i;
    switch (func_003EAFC0(a1)) {
    case 0:
        s1 = true;
        break;
    case 1:
        if (D_0051BFA0.field_57[s0] != 0) s1 = true;
        break;
    case 2:
        if (self->field_386[s0] == 3) {
            if (D_0051BFA0.field_57[s0] != 0) s1 = true;
        }
        break;
    case 3: {
        int lo, hi;
        switch (s0) {
        case 0: lo = 0; hi = 10; break;
        case 1: lo = 11; hi = 23; break;
        case 2: lo = 24; hi = 37; break;
        case 3: lo = 38; hi = 54; break;
        case 4: lo = 55; hi = 72; break;
        default: lo = 0; hi = 10; break;
        }
        s1 = true;
        for (; lo <= hi; lo++) {
            if (self->field_386[lo] != 3) { s1 = false; break; }
        }
        break;
    }
    case 4:
        if (!(self->field_40 < (unsigned)s0)) s1 = true;
        break;
    case 5:
        if (!(gCalculatedData.field_20 + self->field_200 < (unsigned)s0)) s1 = true;
        break;
    case 6:
        if (!(gCalculatedData.field_F4 + (gCalculatedData.field_A4 + gCalculatedData.field_CC) < s0)) s1 = true;
        break;
    case 7:
        s1 = true;
        for (i = 0; i < 73; i++) {
            if (self->field_386[i] != 3) { s1 = false; break; }
        }
        break;
    case 8:
        s1 = true;
        for (i = 0; i < 100; i++) {
            if (self->field_3CF[i] != 3) { s1 = false; break; }
        }
        break;
    case 9:
        if (gCalculatedData.field_90 >= 173) s1 = true;
        break;
    case 10:
        if (!(self->field_44 < (unsigned)s0)) s1 = true;
        break;
    case 11:
        s1 = true;
        for (i = 0; i < 20; i++) {
            if (self->field_433[i] == 0) { s1 = false; break; }
        }
        break;
    case 12:
        if (gCalculatedData.field_2C < 20) {
            for (i = 0; i < 20; i++) {
                if (D_0051BFA0.field_43[i] == 0) break;
            }
        } else {
            s1 = true;
        }
        break;
    case 13:
        if (gCalculatedData.field_3C < 10) {
            for (i = 0; i < 10; i++) {
                if (D_0051BFA0.field_132[i] == 0) break;
            }
        } else {
            s1 = true;
        }
        break;
    case 14:
        s1 = true;
        for (i = 0; i < 10; i++) {
            if (self->field_447[i] == 0) { s1 = false; break; }
        }
        break;
    }
    return s1;
}
