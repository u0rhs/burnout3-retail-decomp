// CB3SoundRaceCar::Register(unsigned long) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundRaceCar.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (mwperm: 'body1:' -> 'body1:'; 'test1:' -> 'test1:'; 'inc1: i = i + 1;' -> 'inc1: i += 1;'; 'found:' -> 'found:').

struct UnkStruct_Reg_E {
    float field_0;
    float field_4;
    float field_8;
    float field_C;
    float field_10;
    float field_14;
    float field_18;
    float field_1C;
    float field_20;
    float field_24;
    float field_28;
    unsigned char field_2C;
    unsigned char field_2D;
    unsigned char pad_2E[2];
    unsigned long field_30;
    unsigned char pad_38[0];
};
struct UnkStruct_Reg_T { UnkStruct_Reg_E arr[6]; unsigned char pad[8]; };
struct UnkStruct_Reg_N { int field_0; };
struct UnkStruct_Reg_S {
    unsigned char pad_0[0x68];
    UnkStruct_Reg_E *field_68;
    unsigned char pad_6C[0x52];
    unsigned char field_BE;
    unsigned char field_BF;
};
extern UnkStruct_Reg_T D_01E7C9E0;
extern UnkStruct_Reg_N _guNumDifferentCars;
extern "C" void Register__15CB3SoundRaceCarFUl(UnkStruct_Reg_S *self, unsigned long id)
{
    unsigned char i = 0;
    unsigned char j;
    UnkStruct_Reg_E *e;
    UnkStruct_Reg_E *e2;
    // [G] goto loops (N24): retail keeps the shared i++ block after the second loop
    goto test1;
body1:
    e = &D_01E7C9E0.arr[i];
    if (id != e->field_30) goto inc1;
    if (e->field_2D != self->field_BE) goto inc1;
    if (e->field_2C == 0) goto inc1;
    self->field_68 = e;
    self->field_BF = 0;
    return;
test1:
    if (i < 6) goto body1;
    if (self->field_68 != 0) return;
    j = 0;
    while (j < 6) {
        e2 = &D_01E7C9E0.arr[j];
        if (e2->field_2C == 0) goto found;
        j++;
    }
    return;
inc1:
    i += 1;
    goto test1;
found:
    self->field_68 = e2;
    UnkStruct_Reg_E *n = self->field_68;
    n->field_0 = 0.0f;
    n->field_4 = -100.0f;
    n->field_8 = 100.0f;
    n->field_C = -100.0f;
    n->field_10 = -1000.0f;
    n->field_14 = 2000.0f;
    n->field_18 = 7500.0f;
    n->field_1C = 0.0f;
    n->field_20 = 0.0f;
    n->field_28 = 0.5f;
    n->field_24 = 1.0f;
    n->field_2D = 0;
    n->field_2C = 0;
    n->field_30 = 0;
    self->field_68->field_30 = id;
    self->field_68->field_2C = 1;
    self->field_68->field_2D = self->field_BE;
    _guNumDifferentCars.field_0 = _guNumDifferentCars.field_0 + 1;
    self->field_BF = 1;
}
