// func_001A9D70 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_001A9D70;
struct UnkStruct_001A9D70_e0;

struct UnkStruct_001A9D70_e0 {
    unsigned char pad_0[0x16];
};

struct UnkStruct_001A9D70 {
    UnkStruct_001A9D70_e0 field_0[1];  // [G] element count unknown
    unsigned char pad_16[0x15];
    unsigned char field_2B;
};

namespace GtMathPs2 { class CGtMatrix3x4; class CGtV3d; }

// [C] retail forwards its own a1..t0 to func_001AA3F0 untouched (no writes before the jal at 0x1A9DA4), and the callee
// reads all five (src/nonmatching/func_001AA3F0.cpp, draftAN fork C); types [L] from the E-build's
// CB3NetworkRaceUpdateMessage::AddCrashingTraffic(unsigned char, const CGtMatrix3x4*, const CGtV3d*, const CGtV3d*).
// The full list compiles byte-identically (tidy1, N290); the earlier self-only call hid the arguments from the port.
extern "C" void func_001AA3F0(void *, unsigned char, const GtMathPs2::CGtMatrix3x4 *, const GtMathPs2::CGtV3d *,
                              const GtMathPs2::CGtV3d *);

// 0x001A9D70
extern "C" void func_001A9D70(UnkStruct_001A9D70 * self, unsigned char id, const GtMathPs2::CGtMatrix3x4 * m,
                              const GtMathPs2::CGtV3d * vel, const GtMathPs2::CGtV3d * ang)
{
    unsigned char t0 = self->field_2B;
    if (t0 >= 24) return;
    func_001AA3F0(((char *)&self->field_0[t0] + 0x30), id, m, vel, ang);
    self->field_2B = (self->field_2B + 1);
}
