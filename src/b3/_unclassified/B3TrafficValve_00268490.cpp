// CB3TrafficValve::Prepare(CB3TrafficValvePositionStruct*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficValve.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (extern C def; row stride 0x1C; memset(+0x94,8)).

struct UnkStruct_00268490_pos { unsigned char pad_0[8]; int field_8; unsigned char field_C; };
struct UnkStruct_00268490_row { unsigned char pad_0[0x10]; int field_10[1]; unsigned char pad_14[0x8]; };
struct UnkStruct_00268490_e48 { int field_0; unsigned char pad_4[4]; int field_8; int field_C; unsigned char pad_10[4]; };
struct UnkStruct_D_0055D7F8 { unsigned char field_0; unsigned char pad[0xF]; };
extern UnkStruct_D_0055D7F8 D_0055D7F8;
extern "C" void *memset(void *, int, unsigned long);
extern "C" void PrepareGenerationTimes__15CB3TrafficValveFfb(void *, float, bool);
struct UnkStruct_00268490_self {
    unsigned char pad_0[0x40];
    UnkStruct_00268490_pos *field_40;
    unsigned char pad_44[4];
    unsigned char field_48x[0x44];
    UnkStruct_00268490_row field_8C[4];
};
extern "C" bool Prepare__15CB3TrafficValveFP29CB3TrafficValvePositionStruct(UnkStruct_00268490_self *self, UnkStruct_00268490_pos *p0)
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 7; j++) {
            self->field_8C[i].field_10[j] = 0;
        }
    }
    self->field_40 = p0;
    unsigned char f = self->field_40->field_C;
    bool b = true;
    if ((f & 1) == 0) { if ((f & 2) == 0) b = false; }
    *((unsigned char *)self + 0x114) = b;
    memset((char *)self + 0x94, 0, 8);
    for (int i = 0; i < p0->field_8; i++) {
        UnkStruct_00268490_e48 *e = (UnkStruct_00268490_e48 *)((char *)self + 0x48 + i * 20);
        e->field_0 = 0;
        e->field_8 = 0;
        e->field_C = 0;
        *((unsigned char *)self + 0x10C + i) = 0;
    }
    if (D_0055D7F8.field_0 == 0) {
        PrepareGenerationTimes__15CB3TrafficValveFfb(self, 0.0f, false);
    }
    return true;
}
