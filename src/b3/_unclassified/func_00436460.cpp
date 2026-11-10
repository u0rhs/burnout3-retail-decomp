// func_00436460 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (BCD decode with the low nibble in an unsigned char temp (as func_00436350)).

// lifter variant 0
// func_00436460 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_00436460;
struct UnkStruct_00436460_0;

struct UnkStruct_00436460_0 {
    unsigned char pad_0[0x1];
    unsigned char field_1;
    unsigned char field_2;
    unsigned char field_3;
    unsigned char pad_4[0x1];
    unsigned char field_5;
    unsigned char field_6;
    unsigned char field_7;
};

struct UnkStruct_00436460 {
    short field_0;
    short field_2;
    short field_4;
    short field_6;
    short field_8;
    short field_A;
};

extern "C" void sceCdReadClock(UnkStruct_00436460_0 *);
extern "C" void sceScfGetLocalTimefromRTC(UnkStruct_00436460_0 *);

// 0x00436460
extern "C" void func_00436460(UnkStruct_00436460 * self)
{
    UnkStruct_00436460_0 local;  // [G] the frame's one local (size: up to the frame top)
    sceCdReadClock(&local);
    sceScfGetLocalTimefromRTC(&local);
    { unsigned char lo = local.field_7 & 0xF; self->field_0 = lo + ((local.field_7 & 0xF0) >> 4) * 10 + 2000; }
    { unsigned char lo = local.field_6 & 0xF; self->field_2 = lo + ((local.field_6 & 0xF0) >> 4) * 10; }
    { unsigned char lo = local.field_5 & 0xF; self->field_4 = lo + ((local.field_5 & 0xF0) >> 4) * 10; }
    { unsigned char lo = local.field_3 & 0xF; self->field_6 = lo + ((local.field_3 & 0xF0) >> 4) * 10; }
    { unsigned char lo = local.field_2 & 0xF; self->field_8 = lo + ((local.field_2 & 0xF0) >> 4) * 10; }
    { unsigned char lo = local.field_1 & 0xF; self->field_A = lo + ((local.field_1 & 0xF0) >> 4) * 10; }
}
