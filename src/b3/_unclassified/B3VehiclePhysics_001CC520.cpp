// CB3VehiclePhysics::FireAirRam(unsigned int,float,bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3VehiclePhysics.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (gaps1c: written from the asm, exact).

// gaps1c (2026-11-02): hand-written from the retail asm (0x1CC520..0x1CC57C). Unnamed; file B3VehiclePhysics.cpp per research/retail_names.csv (high).
// Fires an air ram along one of the body's axes (+0x204: row 0 for flags 0x40 / 0x20, row 2 for 0x80, else row 1);
// a1, a2 (bool) and f12 go through unchanged.

struct UnkStruct_001CC520_body { unsigned char field_0[0x10]; unsigned char field_10[0x10]; unsigned char field_20[0x10]; };
struct UnkStruct_001CC520 { unsigned char pad_0[0x204]; UnkStruct_001CC520_body * field_204; };

extern "C" void FireAirRamWithDirection__17CB3VehiclePhysicsFUifQ29GtMathPs26CGtV3db(void *, unsigned int, float, void *, bool);

// 0x001CC520
extern "C" void func_001CC520(UnkStruct_001CC520 * self, unsigned int flags, bool b, float f)
{
    void * dir;
    if ((flags & 0x40) != 0 || (flags & 0x20) != 0) {
        dir = self->field_204->field_0;
    } else if ((flags & 0x80) != 0) {
        dir = self->field_204->field_20;
    } else {
        dir = self->field_204->field_10;
    }
    FireAirRamWithDirection__17CB3VehiclePhysicsFUifQ29GtMathPs26CGtV3db(self, flags, f, dir, b);
}
