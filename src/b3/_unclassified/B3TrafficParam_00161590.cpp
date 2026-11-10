// CB3TrafficParam::Insert(CB3TrafficLane*,float,float,ETrafficParamState) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3TrafficParam.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (goto layout form, ip assigned after zx store, n loaded before null test).

// Hand-written; lifter refused (a138). [G] goto form: only way to keep retail block layout (loop/before-insert/tail order); pminw/pextlw helpers per a71.
#include "b3/GtMath.h"

struct UnkStruct_00161590_e { float field_0; unsigned char pad_4[0x4]; };
struct UnkStruct_00161590_blk {
    unsigned char pad_0[0x4];
    UnkStruct_00161590_e * field_4;
    unsigned char pad_8[0x8];
    int field_10;
};
struct UnkStruct_00161590_lane {
    UnkStruct_00161590_blk * field_0;
    unsigned short field_4;
    unsigned char pad_6[0x40];
    unsigned char field_46;
    unsigned char field_47;
    unsigned char pad_48[0x4];
};
struct UnkStruct_00161590 {
    float field_0;
    unsigned char pad_4[0x1C];
    float field_20;
    unsigned char pad_24[0x8];
    float field_2C;
    float field_30;
    float field_34;
    unsigned char pad_38[0x9];
    unsigned char field_41;
    unsigned char pad_42[0x2];
    unsigned char field_44;
    unsigned char field_45;
    unsigned char field_46;
    unsigned char pad_47[0x2];
    unsigned char field_49;
    unsigned char pad_4A[0x1];
    unsigned char field_4B;
    unsigned char pad_4C[0x4];
};
struct UnkStruct_D_00522660 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_0055D7DC { unsigned char * field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_D_0055D7DC D_0055D7DC;
extern float D_004E0E00;
extern float D_004E0A40;
extern float D_004E11F4;

static inline int func_00161590_min(int a, int b) { int r; asm("pminw %0, %1, %2" : "=r"(r) : "r"(a), "r"(b)); return r; }
static inline unsigned int func_00161590_zx(int a) { unsigned int r; asm("pextlw %0, $0, %1" : "=r"(r) : "r"(a)); return r; }

static inline UnkStruct_00161590 * GetParam(unsigned char i)
{
    if (i == 0xFF) {
        return 0;
    }
    return (UnkStruct_00161590 *)((char *)&D_00522660 + i * 80 + 0x2F2B0);
}

// 0x00161590
extern "C" int Insert__15CB3TrafficParamFP14CB3TrafficLaneff18ETrafficParamState(UnkStruct_00161590 * self, UnkStruct_00161590_lane * lane, float p0, float p1, int p2)
{
    unsigned char * buf = D_0055D7DC.field_0;
    UnkStruct_00161590 * a;
    int ip;
    bool tail = false;
    p2 = func_00161590_min(p2, 2);
    self->field_46 = func_00161590_zx(p2);
    ip = (int)p0;
    self->field_30 = p0;
    self->field_34 = GtMath::Min(GtMath::Max(p1, D_004E0E00), D_004E0A40);
    self->field_41 = lane->field_47;
    self->field_4B |= 0x10;
    if (ip > 0) {
        self->field_20 = lane->field_0->field_4[ip].field_0 - lane->field_0->field_4[ip - 1].field_0;
    } else {
        self->field_20 = lane->field_0->field_4[ip].field_0;
    }
    self->field_2C = D_004E11F4 * self->field_0;
    unsigned char id = buf[lane->field_4 + ip];
    if (id == 0xFF) {
        goto early;
    }
    a = GetParam(id);
    if (self->field_30 <= a->field_30) {
        goto before1;
    }
    for (;;) {
        if (self->field_30 <= a->field_30) {
            goto found;
        }
        unsigned char n = a->field_44;
        if (a == 0) {
            goto notfound;
        }
        if (n == 0xFF) {
            goto notfound;
        }
        a = GetParam(n);
    }
before1:
    self->field_45 = a->field_45;
    if (self->field_45 != 0xFF) {
        UnkStruct_00161590 * o = GetParam(self->field_45);
        o->field_44 = self->field_49;
    }
    self->field_44 = a->field_49;
    a->field_45 = self->field_49;
    {
        int j = ip;
        while (j >= 0 && a->field_49 == buf[lane->field_4 + j]) {
            buf[lane->field_4 + j] = self->field_49;
            j--;
        }
    }
    goto join;
notfound:
    tail = true;
found:
    if (!tail) {
        unsigned char t = a->field_45;
        if (t == 0xFF) {
            self->field_45 = 0xFF;
        } else {
            UnkStruct_00161590 * o = GetParam(t);
            self->field_45 = t;
            o->field_44 = self->field_49;
        }
        self->field_44 = a->field_49;
        a->field_45 = self->field_49;
    }
    goto join;
early:
    tail = true;
join:
    if (tail) {
        unsigned char l = lane->field_46;
        if (l != 0xFF) {
            UnkStruct_00161590 * o = GetParam(l);
            self->field_45 = l;
            o->field_44 = self->field_49;
        }
        lane->field_46 = self->field_49;
        while (ip >= 0 && buf[lane->field_4 + ip] == 0xFF) {
            buf[lane->field_4 + ip] = self->field_49;
            ip--;
        }
    }
    return 1;
}
