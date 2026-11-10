// CB3CrashCombo::OnCrashFinishing() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3CrashCombo.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (switch cases 1,5,4 source order; tag == car->218 operand order; RELOC diff only the ofs_00122A10 constant (a107)).

struct UnkStruct_D_00522660 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_0064517C { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_0064D37C { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_D_0064517C D_0064517C;
extern UnkStruct_D_0064D37C D_0064D37C;
struct UnkStruct_00363B10_car { unsigned char pad_0[0x218]; signed char field_218; unsigned char pad_219[0x2207]; int field_2420; };
class CB3CrashCombo {
public:
    void OnCrashFinishing();
    unsigned char pad_0[0x11A];
    unsigned char field_11A;
    unsigned char pad_11B[0x10D];
    UnkStruct_00363B10_car *field_228;
    unsigned char pad_22C[0x10C];
    int field_338;
    int field_33C;
    int field_340;
    int field_344;
    int field_348;
};
// 0x00363B10
void CB3CrashCombo::OnCrashFinishing()
{
    if (field_228 == 0 || field_11A == 0) return;
    field_338 = 0;
    field_33C = 0;
    field_340 = 0;
    field_344 = 0;
    field_348 = 0;
    int tag = field_228->field_218;
    for (int i = 0; i < D_0064517C.field_0; i++) {
        UnkStruct_00363B10_car *car = *(UnkStruct_00363B10_car **)((char *)&D_00522660 + i * 4 + 0x122A10);
        if (car != 0 && tag == car->field_218) {
            field_338++;
            switch (car->field_2420) {
            case 1:
                field_340++;
                break;
            case 5:
                field_33C++;
                break;
            case 4:
                field_344++;
                break;
            default:
                continue;
            }
        }
    }
    for (int j = 0; j < D_0064D37C.field_0; j++) {
        UnkStruct_00363B10_car *car = *(UnkStruct_00363B10_car **)((char *)&D_00522660 + j * 0x30 + 0x3C98C);
        if (car != 0 && car != field_228 && tag == car->field_218) {
            field_338++;
            field_340++;
            field_348++;
        }
    }
}
