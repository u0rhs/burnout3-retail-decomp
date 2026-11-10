// NONMATCHING: func_002300D0 -- retail 181 / ours 181 instructions, 12 in changed runs
// L266: logic, block layout, frame and second loop exact (goto-form first loop with df: label after the latch; row-base casts; inline send test indexing pm->field_A0[j]; (unsigned char) first snprintf arg; 0xFFFFFFFE clear gives li -2/and). Left 12 instrs: s-register rotation in the first loop only -- retail myId s4, i s3, row s2, &m s1; ours myId s2, i s4, row s1, &m s3 (decl order, i shared with 2nd loop, ref vs pointer all tried; 8 saved regs)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

#include "b3/classes/CGtNetworkPlayerManager.h"

struct UnkStruct_002300D0_msg {
    unsigned char field_0;
    unsigned char field_1;
    unsigned char field_2;
    unsigned char pad_3;
    int field_4;
    int field_8;
};
struct UnkStruct_002300D0_slot {
    int field_0;
    int field_4;
    int field_8;
    UnkStruct_002300D0_msg *field_C;
    unsigned char field_10;
    unsigned char pad_11[3];
};
struct UnkStruct_002300D0_pm {
    unsigned char pad_0[0x88];
    unsigned short field_88;
    unsigned char pad_8A[2];
    unsigned char field_8C;
    unsigned char pad_8D[0x13];
    UnkStruct_002300D0_slot field_A0[32];
};
struct UnkStruct_002300D0_pmrow {
    unsigned char pad_0[0xA0];
    UnkStruct_002300D0_slot field_A0;
};
struct UnkStruct_002300D0_rec {
    int field_0;
    UnkStruct_002300D0_msg *field_4;
    unsigned char pad_8[0x10];
};
struct UnkStruct_002300D0_2 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C(UnkStruct_002300D0_msg *, int, int, int);
};
struct UnkStruct_002300D0_row {
    unsigned char pad_0[0x30];
    UnkStruct_002300D0_rec field_30;
};
struct UnkStruct_002300D0 {
    unsigned char pad_0[0x4];
    UnkStruct_002300D0_2 *field_4;
    int field_8;
    UnkStruct_002300D0_pm *field_C;
    int field_10;
    unsigned char pad_14[0x10];
    int field_24;
    int field_28;
    unsigned char pad_2C[0x4];
    UnkStruct_002300D0_rec field_30[1];  // [G] element count unknown
    unsigned char pad_48[0x464];
    int field_4AC;
};

extern "C" void func_0022D890(void *, int);
extern "C" void func_0022D970(void *, int);
extern "C" void func_00235DF0(void *self, int id, signed char *data, int len);
extern "C" int snprintf(char *, unsigned int, const char *, ...);
extern char D_004BA008[];

static inline bool func_002300D0_inl1(UnkStruct_002300D0_pm *pm, int j, int id)
{
    if (pm->field_A0[j].field_10 != 0)
        return false;
    if (pm->field_A0[j].field_0 != id)
        return false;
    if (pm->field_A0[j].field_8 == -1)
        return true;
    unsigned short now = pm->field_88;
    unsigned short then = (unsigned short)pm->field_A0[j].field_8;
    unsigned short d;
    if (now < 0x5555 && then > 0xAAAA)
        d = (unsigned short)(now + (0xFFFF - then));
    else
        d = (unsigned short)(now - then);
    if (d > 10)
        return true;
    return false;
}

// 0x002300D0
extern "C" void func_002300D0(UnkStruct_002300D0 *self)
{
    int myId = ((const CGtNetworkPlayerManager *)self->field_C)->GetMyPlayerID();
    unsigned char b = self->field_C->field_8C;
    int id = self->field_8;
    int i;
    i = 0;
top:
    if (i < self->field_4AC) {
        UnkStruct_002300D0_row *r = (UnkStruct_002300D0_row *)((char *)self + i * 24);
        UnkStruct_002300D0_msg *&m = r->field_30.field_4;
        int len;
        if ((m->field_0 & 1) == 1 && (m->field_0 & 2) != 2) {
            m->field_4 = myId;
            m->field_8 = id;
            m->field_1 = b;
            int on = (m->field_2 & 1) != 0;
            len = r->field_30.field_0;
            if (on != 0)
                goto df;
            func_0022D890(m, len);
            func_0022D970(m, len);
            self->field_4->vfunc_C(m, r->field_30.field_0, self->field_24, self->field_28);
        }
    next:
        i++;
        goto top;
    df:
        func_00235DF0(self->field_C, self->field_8, (signed char *)m, len);
        m->field_0 = m->field_0 & 0xFFFFFFFE;
        goto next;
    }
    for (i = 0; i < 32; i++) {
        UnkStruct_002300D0_pm *pm = self->field_C;
        if (func_002300D0_inl1(pm, i, self->field_8)) {
            UnkStruct_002300D0_pmrow *er = (UnkStruct_002300D0_pmrow *)((char *)pm + i * 20);
            UnkStruct_002300D0_slot *e = &er->field_A0;
            int len = e->field_4;
            if ((e->field_C->field_0 & 2) != 2)
                func_0022D890(e->field_C, len);
            e->field_C->field_0 |= 1;
            func_0022D970(e->field_C, len);
            self->field_4->vfunc_C(e->field_C, e->field_4, self->field_24, self->field_28);
            char buf[16];
            int ip = self->field_24;
            snprintf(buf, 16, D_004BA008, (unsigned char)((ip & 0xFF000000) >> 24), (ip & 0xFF0000) >> 16, (ip & 0xFF00) >> 8, ip & 0xFF);
            e->field_8 = self->field_10;
        }
    }
}
