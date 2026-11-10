// func_00160B40 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (near21: lit4 0.15f literal + sibling GetParamInfoFromValve RNG block + goto-form return label with scoped opt_repositioncode off [G]).

struct UnkStruct_00160B40;
struct UnkStruct_D_0055D788;
struct UnkStruct_D_0055D78C;
struct UnkStruct_D_0055D7F7;
struct UnkStruct_D_0055D7F8;

struct UnkStruct_D_0055D7F7 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0055D7F8 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0055D788 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0055D78C {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00160B40 {
    float field_0;
    unsigned char pad_4[0x34];
    int field_38;
};

extern UnkStruct_D_0055D7F7 D_0055D7F7;
extern UnkStruct_D_0055D7F8 D_0055D7F8;
extern UnkStruct_D_0055D788 D_0055D788;
extern UnkStruct_D_0055D78C D_0055D78C;

// N182: opt_repositioncode off [G] scoped to this function: with the goto-form return label it keeps
// retail's `b exit` relay block that the body jumps back to (L268).
#pragma push
#pragma opt_repositioncode off
// 0x00160B40
// Out-of-line copy of the random-step block inlined in CB3TrafficParam::GetParamInfoFromValve
// (B3TrafficParam_00160C30.cpp) [L]; 0.15f is .lit4 D_004E10BC.
extern "C" void func_00160B40(UnkStruct_00160B40 * self)
{
    if (self->field_38 != 0) {
    ret:
        return;
    }
    if (D_0055D7F7.field_0 == 0 && D_0055D7F8.field_0 == 0) {
        int a = D_0055D788.field_0;
        int b = D_0055D78C.field_0;
        unsigned int r = (a << 16) + (a >> 16);
        r += b;
        D_0055D788.field_0 = r;
        D_0055D78C.field_0 = b + r;
        self->field_0 += 2.0f * (2.3283064e-10f * (float)r - 0.5f) * (0.15f * self->field_0);
        goto ret;
    }
}
#pragma pop
