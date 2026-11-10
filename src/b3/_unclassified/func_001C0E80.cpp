// func_001C0E80 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (gaps1c: written from the asm, exact).

// gaps1c (2026-11-02): hand-written from the retail asm (0x1C0E80..0x1C0EF4). Unnamed; file B3RaceCarPhysics.cpp per research/retail_names.csv (high).
// Releases the car's resource +0x13F8: when it is one of D_01D9C350's six slots (+0xAE0), func_00254090 frees it and
// the slot is cleared; +0x13F8 = 0 either way.

struct UnkStruct_001C0E80_tab { unsigned char pad_0[0xAE0]; void * field_AE0[6]; };
struct UnkStruct_001C0E80 { unsigned char pad_0[0x13F8]; void * field_13F8; };

extern UnkStruct_001C0E80_tab D_01D9C350;

extern "C" void func_00254090(void *);

// 0x001C0E80
extern "C" void func_001C0E80(UnkStruct_001C0E80 * self)
{
    void * r = self->field_13F8;
    for (int i = 0; i < 6; i++) {
        if (D_01D9C350.field_AE0[i] == r) {
            func_00254090(D_01D9C350.field_AE0[i]);
            D_01D9C350.field_AE0[i] = 0;
            break;
        }
    }
    self->field_13F8 = 0;
}
