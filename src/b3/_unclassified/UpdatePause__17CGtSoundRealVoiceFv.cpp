// Hand-written; the lifter refused it (negating bool inline as early returns (if (inl1) return false; return true;) + inl2 returns inl1n(..) != false).

// UpdatePause__17CGtSoundRealVoiceFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished (near19): the negating helper written with early returns keeps retail's fall-through join of the
// materialised bool in case 1, and inl2's case 0/1/3 returns `inl1n(..) != false` (retail's extra sltu).

struct UnkStruct_00385260;
struct UnkStruct_00385260_1;
struct UnkStruct_00385260_2;
struct UnkStruct_00385260_3;
struct UnkStruct_00385260_4;
struct UnkStruct_00385260_5;
struct UnkStruct_00385260_6;
struct UnkStruct_00385260_7;
struct UnkStruct_00385260_8;

struct UnkStruct_00385260_1 {
    unsigned char pad_0[0x30];
    UnkStruct_00385260_2 * field_30;
    unsigned char pad_34[0x28];
    unsigned short field_5C;
    unsigned char pad_5E[0x42];
    float field_A0;
};

struct UnkStruct_00385260_2 {
    int field_0;
    unsigned char pad_4[0x10];
    int field_14;
    int field_18;
};

struct UnkStruct_00385260_3 {
    int field_0;
};

struct UnkStruct_00385260_4 {
    int field_0;
};

struct UnkStruct_00385260_5 {
    int field_0;
};

struct UnkStruct_00385260_6 {
    int field_0;
};

struct UnkStruct_00385260_7 {
    unsigned char pad_0[0x18];
    int field_18;
};

struct UnkStruct_00385260_8 {
    int field_0;
};

struct UnkStruct_00385260 {
    unsigned char pad_0[0x8];
    int field_8;
    unsigned char pad_C[0x8];
    UnkStruct_00385260_1 * field_14;
    unsigned char field_18;
    unsigned char field_19;
    unsigned char pad_1A[0x1];
    unsigned char field_1B;
};


// [G] inlined bool helper (name unknown): state 3 or 1
static inline bool func_00385260_inl1(UnkStruct_00385260_2 * p)
{
    return p->field_0 == 3 || p->field_0 == 1;
}

// [G] inlined bool helper (name unknown): the negation of func_00385260_inl1
static inline bool func_00385260_inl1n(UnkStruct_00385260_2 * p)
{
    if (func_00385260_inl1(p)) return false;
    return true;
}

// [G] inlined bool helper (name unknown)
static inline bool func_00385260_inl2(UnkStruct_00385260 * self)
{
    switch (self->field_18) {
    case 0:
    case 1:
    case 3:
        return func_00385260_inl1n(self->field_14->field_30) != false;
    case 2:
        if (self->field_1B & 8) {
            return true;
        } else {
            return false;
        }
    default:
        return false;
    }
    return false;
}

// 0x00385260
extern "C" void UpdatePause__17CGtSoundRealVoiceFv(UnkStruct_00385260 * self)
{
    switch (self->field_18) {
    case 0:
        return;
    case 1: {
        int n = self->field_19;
        if (n < 5) {
            if (func_00385260_inl1n(self->field_14->field_30) != false) {
                float s = self->field_14->field_A0;
                float t = (float)(unsigned int)n;
                t = 1.0f - t / 5.0f;
                self->field_14->field_5C |= 2;
                self->field_14->field_A0 = s * t;
                self->field_19++;
            } else {
                self->field_19 = 0;
                self->field_14->field_30->field_0 = 1;
                self->field_18 = 2;
                self->field_1B &= ~8;
            }
        } else {
            self->field_1B |= 8;
            self->field_8 = self->field_14->field_30->field_14;
            self->field_14->field_30->field_0 = 1;
            self->field_19 = 0;
            self->field_18 = 2;
        }
        break;
    }
    case 2:
        return;
    case 3:
        if ((self->field_1B & 8) == 0) {
            self->field_18 = 0;
        } else {
            if (self->field_19 == 0) {
                self->field_14->field_30->field_0 = 2;
                self->field_14->field_5C |= 0x80;
                self->field_14->field_30->field_18 = self->field_8;
            }
            int n = self->field_19;
            if (n < 5 && func_00385260_inl2(self)) {
                float s = self->field_14->field_A0;
                float t = (float)(unsigned int)n;
                t /= 5.0f;
                self->field_14->field_5C |= 2;
                self->field_14->field_A0 = s * t;
                self->field_19++;
            } else {
                self->field_18 = 0;
                self->field_19 = 0;
            }
        }
        break;
    }
}
