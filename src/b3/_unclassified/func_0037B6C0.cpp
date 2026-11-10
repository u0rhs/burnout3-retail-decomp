// func_0037B6C0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (comparator with const pointer params (lets sd ra fill the first delay slot); flat early returns; strcasecmp(name, name) two args).

// func_0037B6C0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

struct UnkStruct_0037B6C0;
struct UnkStruct_0037B6C0_a1;

struct UnkStruct_0037B6C0_a1 {
    unsigned char pad_0[0x34];
    int field_34;
    unsigned char pad_38[0x4];
    int field_3C;
    int field_40;
};

struct UnkStruct_0037B6C0 {
    unsigned char pad_0[0x34];
    int field_34;
    unsigned char pad_38[0x4];
    int field_3C;
    int field_40;
};

extern "C" int strcasecmp(const char *, const char *);

// 0x0037B6C0
extern "C" int func_0037B6C0(const UnkStruct_0037B6C0 * self, const UnkStruct_0037B6C0_a1 * p0)
{
    int t0 = p0->field_34;
    if (self->field_34 < t0) return -1;
    if (self->field_34 > t0) return 1;
    if (self->field_3C > p0->field_3C) return -1;
    if (self->field_3C < p0->field_3C) return 1;
    if (self->field_40 > p0->field_40) return -1;
    if (self->field_40 < p0->field_40) return 1;
    return strcasecmp((const char *)self, (const char *)p0);
}
