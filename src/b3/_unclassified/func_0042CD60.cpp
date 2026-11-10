// func_0042CD60 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (four inlined bool arrow-state helpers (if-return true / shared return false), CGtV4d on/off colours, if/else colour assignment).

// func_0042CD60 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

#include "b3/GtMathPs2.h"

using GtMathPs2::CGtV4d;

struct UnkStruct_0042CD60_3 {
    unsigned char pad_0[0x10];
    CGtV4d field_10;
};

struct UnkStruct_0042CD60 {
    unsigned char pad_0[0x220];
    UnkStruct_0042CD60_3 * field_220;
    UnkStruct_0042CD60_3 * field_224;
    UnkStruct_0042CD60_3 * field_228;
    UnkStruct_0042CD60_3 * field_22C;
    int field_230;
    unsigned char pad_234[0x4];
    int field_238;
    unsigned char pad_23C[0x8];
    int field_244;
    int field_248;
    unsigned char pad_24C[0xC];
    int field_258;
    int field_25C;
    int field_260;
    unsigned char field_264;
    unsigned char field_265;
};

// [G] inlined helpers (no names known): whether each of the four arrows is enabled
static inline bool func_0042CD60_inl1(UnkStruct_0042CD60 * self)
{
    if (self->field_238 != 0) {
        return false;
    }
    if (self->field_244 <= 0) {
        return false;
    }
    return true;
}

static inline bool func_0042CD60_inl2(UnkStruct_0042CD60 * self)
{
    if (self->field_238 != 0) {
        return false;
    }
    if (self->field_244 < self->field_248 - 1) {
        return true;
    }
    return false;
}

static inline bool func_0042CD60_inl3(UnkStruct_0042CD60 * self)
{
    if (self->field_25C != 9) {
        return false;
    }
    if (self->field_238 != 0) {
        return false;
    }
    if (self->field_258 <= 0) {
        return false;
    }
    return true;
}

static inline bool func_0042CD60_inl4(UnkStruct_0042CD60 * self)
{
    if (self->field_25C != 9) {
        return false;
    }
    if (self->field_238 != 0) {
        return false;
    }
    if (!self->field_265) {
        if (self->field_258 < 4) {
            return true;
        }
    } else if (!self->field_264) {
        if (self->field_258 < 5) {
            return true;
        }
    } else if (self->field_258 < 6) {
        return true;
    }
    return false;
}
// 0x0042CD60
extern "C" void func_0042CD60(UnkStruct_0042CD60 * self)
{
    CGtV4d on(1.0f, 1.0f, 1.0f, 1.0f);
    CGtV4d off(1.0f, 1.0f, 1.0f, 0.3f);
    if (self->field_230 == 1) {
        return;
    }
    if (self->field_260 == -1) {
        if (func_0042CD60_inl1(self)) {
            self->field_220->field_10 = on;
        } else {
            self->field_220->field_10 = off;
        }
        if (func_0042CD60_inl2(self)) {
            self->field_224->field_10 = on;
        } else {
            self->field_224->field_10 = off;
        }
    }
    if (self->field_25C != 9) {
        return;
    }
    if (func_0042CD60_inl3(self)) {
        self->field_228->field_10 = on;
    } else {
        self->field_228->field_10 = off;
    }
    if (func_0042CD60_inl4(self)) {
        self->field_22C->field_10 = on;
    } else {
        self->field_22C->field_10 = off;
    }
}
