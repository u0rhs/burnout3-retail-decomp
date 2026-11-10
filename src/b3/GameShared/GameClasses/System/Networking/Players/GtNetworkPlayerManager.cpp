// GtNetworkPlayerManager.cpp -- translation unit regrouped by tools/tu_merge.py from 24 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 5 function(s) named in research/retail_names.csv -> GtNetworkPlayerManager.cpp, 2 by a medium-confidence name confirmed by a neighbour, 17 placed between two of them by address contiguity (N2).
// Area: src/b3/GameShared/GameClasses/System/Networking/Players, [L] Revenge (SLUS_212.42) GameShared/GameClasses/System/Networking/Players/GtNetworkPlayerManager.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CGtNetworkPlayerManager.h"

struct UnkStruct_002352B0;
struct UnkStruct_002366D0;
struct UnkStruct_00236940;
struct UnkStruct_00236940_2;
struct UnkStruct_00236BC0;
struct UnkStruct_00236C00;
struct UnkStruct_002351F0;
struct UnkStruct_002351F0_2;
struct UnkStruct_00235D90;
struct UnkStruct_00235D90_e0;
struct UnkStruct_00236B30;

struct UnkStruct_002351E0 {
    unsigned char pad_0[0x80];
    int field_80;
};
struct UnkStruct_002352B0 {
    unsigned char pad_0[0x5];
    unsigned char field_5;
    unsigned char pad_6[0x2];
    int field_8[1];  // [G] element count unknown
    unsigned char pad_C[0x1C];
    int field_28;
    unsigned char pad_2C[0x24];
    int field_50[1];  // [G] element count unknown
    unsigned char pad_54[0x1C];
    int field_70;
};
struct UnkStruct_002366D0 {
    unsigned char pad_0[0x8];
    int field_8[1];  // [G] element count unknown
};
struct UnkStruct_00236940_2 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
};
struct UnkStruct_00236940 {
    unsigned char pad_0[0x8];
    UnkStruct_00236940_2 * field_8[1];  // [G] element count unknown
    unsigned char pad_C[0x1C];
    int field_28;
    void * field_2C[1];  // [G] element count unknown
    unsigned char pad_30[0x1C];
    int field_4C;
    unsigned char pad_50[0x28];
    int field_78;
    unsigned char pad_7C[0x4];
    int field_80;
};
struct UnkStruct_00236BC0 {
    int field_0;
    unsigned char pad_4[0x84];
    int field_88;
};
struct UnkStruct_00236C00 {
    int field_0;
    unsigned char pad_4[0x78];
    int field_7C;
    unsigned char pad_80[0x14];
    int field_94;
};
struct UnkStruct_002351F0_2 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
};
struct UnkStruct_002351F0 {
    unsigned char pad_0[0x5];
    unsigned char field_5;
    unsigned char pad_6[0x26];
    void * field_2C[1];  // [G] element count unknown
    unsigned char pad_30[0x1C];
    int field_4C;
    UnkStruct_002351F0_2 * field_50[1];  // [G] element count unknown
    unsigned char pad_54[0x1C];
    int field_70;
};
struct UnkStruct_00235D90_e0 {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    unsigned char field_10;
    unsigned char pad_11[0x3];
};
struct UnkStruct_00235D90 {
    unsigned char pad_0[0x84];
    int field_84;
    unsigned char pad_88[0x10];
    int field_98;
    unsigned char pad_9C[0x4];
    UnkStruct_00235D90_e0 field_A0[1];  // [G] element count unknown
    unsigned char pad_B4[0x26C];
    int field_320;
};
struct UnkStruct_00236B30 {
    int field_0;
    unsigned char field_4;
    unsigned char pad_5[0x3];
    void * field_8[1];  // [G] element count unknown
    unsigned char pad_C[0x1C];
    int field_28;
    unsigned char pad_2C[0x5C];
    int field_88;
};
struct UnkStruct_00235960_vt {
    virtual void vfunc_8();
    virtual void vfunc_C(void *, int, int, int);
};
struct UnkStruct_00235960_slot {
    unsigned char field_0;
    unsigned char field_1;
    unsigned char field_2;
    signed char field_3;
    int field_4;
    int field_8;
    unsigned short field_C;
    unsigned char pad_E[2];
};
struct UnkStruct_00235960_msg {
    unsigned char pad_0[2];
    unsigned char field_2;
    signed char field_3;
    int field_4;
    int field_8;
    unsigned short field_C;
};
struct UnkStruct_00235960 {
    unsigned char pad_0[0x7C];
    UnkStruct_00235960_vt *field_7C;
    unsigned char pad_80[0x440 - 0x80];
    UnkStruct_00235960_slot field_440[10];
};
struct UnkStruct_00235A80_vt {
    virtual void vfunc_8();
    virtual void vfunc_C(void *, int, int, int);
};
struct UnkStruct_00235A80_slot {
    unsigned char field_0;
    unsigned char field_1;
    unsigned char field_2;
    signed char field_3;
    int field_4;
    int field_8;
    unsigned short field_C;
    unsigned char pad_E[2];
};
struct UnkStruct_00235A80_msg {
    unsigned char pad_0[2];
    unsigned char field_2;
    signed char field_3;
    int field_4;
    int field_8;
    unsigned short field_C;
};
struct UnkStruct_00235A80 {
    unsigned char pad_0[0x7C];
    UnkStruct_00235A80_vt *field_7C;
    unsigned char pad_80[0x3A0 - 0x80];
    UnkStruct_00235A80_slot field_440[10];
};
struct UnkStruct_002365A0 {
    unsigned char pad_0[8];
    void *field_8[1];
    unsigned char pad_C[0x1C];
    int field_28;
    unsigned char pad_2C[0x4C];
    int field_78;
};
struct UnkStruct_00235DF0_slot {
    int field_0;
    int field_4;
    int field_8;
    signed char *field_C;
    unsigned char field_10;
    unsigned char pad_11[3];
};
struct UnkStruct_00235DF0_row {
    unsigned char pad_0[0xA0];
    UnkStruct_00235DF0_slot field_A0;
};
struct UnkStruct_00235DF0 {
    unsigned char pad_0[0xA0];
    UnkStruct_00235DF0_slot field_A0[32];
    int field_320;
};
struct UnkStruct_00236310 {
    unsigned char pad_0[8];
    void *field_8[1];
    unsigned char pad_C[0x1C];
    int field_28;
    unsigned char pad_2C[0x4C];
    int field_78;
};
struct UnkStruct_00236460 {
    unsigned char pad_0[8];
    void *field_8[1];
    unsigned char pad_C[0x1C];
    int field_28;
    unsigned char pad_2C[0x4C];
    int field_78;
};
struct UnkStruct_002353D0_item {
    unsigned char field_0;
    unsigned char pad_1;
    unsigned char field_2;
    signed char field_3;
    int field_4;
    int field_8;
    unsigned short field_C;
};
struct UnkStruct_002353D0_ent {
    unsigned char pad_0[0xC];
    UnkStruct_002353D0_item * field_C;
    unsigned char field_10;
    unsigned char pad_11[0x3];
};
struct UnkStruct_002353D0 {
    unsigned char pad_0[0xA0];
    UnkStruct_002353D0_ent field_A0[32];
};
struct UnkStruct_00235590_item {
    unsigned char field_0;
    unsigned char pad_1;
    unsigned char field_2;
    signed char field_3;
    int field_4;
    int field_8;
    unsigned short field_C;
};
struct UnkStruct_00235590_ent {
    unsigned char pad_0[0xC];
    UnkStruct_00235590_item * field_C;
    unsigned char field_10;
    unsigned char pad_11[0x3];
};
struct UnkStruct_00235590 {
    unsigned char pad_0[0x94];
    void (*field_94)(int, int, int);
    unsigned char pad_98[0x8];
    UnkStruct_00235590_ent field_A0[32];
};
struct UnkStruct_00235BB0_pl {
    unsigned char pad_0[0x14];
    char field_14[16];
    int field_24;
    int field_28;
    unsigned char pad_2C[0x484];
    unsigned char field_4B0;
};
struct UnkStruct_00235BB0 {
    unsigned char pad_0[8];
    UnkStruct_00235BB0_pl *field_8[1];
    unsigned char pad_C[0x1C];
    int field_28;
    unsigned char pad_2C[0x4C];
    int field_78;
    unsigned char pad_7C[0xC];
    int field_88;
    unsigned char pad_8C[0x454];
    unsigned char field_4E0[0x10];
};

extern char D_004BA008[];

extern "C" int func_0022FBB0(void *);
extern "C" void func_00230F60(void *, int);
extern "C" void func_00235F80(UnkStruct_00236BC0 *);
extern "C" int func_002349A0(void *);
extern "C" int func_0022D3B0();
extern "C" void func_002300D0(void *);
extern "C" void func_0022D890(void *, int);
extern "C" void func_0022D970(void *, int);
extern "C" void *memcpy(void *, const void *, unsigned int);
extern "C" void ResetFinaliseNATDataVariables__17CGtNATDataManagerFv(void*);
extern "C" void func_0022D850(void *);
extern "C" int snprintf(char *, unsigned int, const char *, ...);
extern "C" int func_002311D0(void *, int, float, float, int, int, int *, int *);

// CGtNetworkPlayerManager::GetHostPlayerID() -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> GtNetworkPlayerManager.cpp.
// 0x002351D0
int CGtNetworkPlayerManager::GetHostPlayerID()
{
    return field_80;
}

// func_002351E0 -- tiny-function batch (tools/tiny_batch.py).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x002351E0
extern "C" void func_002351E0(UnkStruct_002351E0 *self, int p0)
{
    self->field_80 = p0;
}

// func_002351F0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x002351F0
extern "C" void func_002351F0(UnkStruct_002351F0 * self)
{
    for (int i = 0; (i < self->field_70); i++) {
        UnkStruct_002351F0_2 * t0 = self->field_50[i];
        if (t0 != 0) {
            int r0 = func_0022FBB0(t0);
            func_00230F60(((char *)self + 0x4E0), r0);
            self->field_50[i]->vfunc_C();
            self->field_2C[self->field_4C] = (void *)self->field_50[i];
            self->field_4C = (self->field_4C + 1);
        }
    }
    self->field_70 = 0;
    self->field_5 = 1;
}

// func_002352B0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x002352B0
extern "C" void func_002352B0(UnkStruct_002352B0 * self)
{
    self->field_70 = 0;
    for (int i = 0; (i < self->field_28); i++) {
        self->field_50[i] = self->field_8[i];
        self->field_70 = (self->field_70 + 1);
        self->field_8[i] = 0;
    }
    self->field_28 = 0;
    self->field_5 = 0;
}

// Hand-written; the lifter refused it (dperm (decomp-permuter via build/vt/dperm/to_c.py): has test inlined into the if, q local dropped (e->field_C re-read per compare)).
// 0x002353D0
extern "C" int func_002353D0(UnkStruct_002353D0 *self, UnkStruct_002353D0_item *key)
{
  int has;
  if (((key->field_2 & 4) != 0) != 0)
  {
    UnkStruct_002353D0_ent *found = 0;
    int i = 0;
    UnkStruct_002353D0_ent *e;
    UnkStruct_002353D0_item *q;
    int t;
    goto test;
    body:
    e = &self->field_A0[i];

    if (e->field_10 != 0)
    {
      goto next;
    }
    t = e->field_C->field_0 & 2;
    if (t == 2)
    {
      goto l500;
    }
    l448:
    if (t == 2)
    {
      goto l46c;
    }

    if ((key->field_0 & 2) == 2)
    {
      func_0022D850(key);
    }
    l46c:
    ;

    l470:
    if (e->field_C->field_C != key->field_C)
    {
      goto next;
    }

    if (e->field_C->field_3 != key->field_3)
    {
      goto next;
    }
    if (e->field_C->field_4 != key->field_4)
    {
      goto next;
    }
    if (e->field_C->field_8 != key->field_8)
    {
      goto next;
    }
    found = e;
    goto after;
    test:
    if (i < 32)
    {
      goto body;
    }

    after:
    if (found != 0)
    {
      self->field_A0[i].field_10 = 1;
    }

    if ((key->field_0 & 2) == 2)
    {
      goto end850;
    }
    ret1:
    return 1;

    l500:
    if ((key->field_0 & 2) == 2)
    {
      goto l448;
    }

    func_0022D890(key, 0x10);
    q = e->field_C;
    goto l470;
    next:
    i++;

    goto test;
    end850:
    func_0022D850(key);

    goto ret1;
  }
  if ((key->field_0 & 2) == 2)
  {
    func_0022D850(key);
  }
  return 0;
}

// func_00235590 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00235590
extern "C" int func_00235590(UnkStruct_00235590 *self, UnkStruct_00235590_item *key)
{
  if (((key->field_2 & 2) != 0) != 0)
  {
    UnkStruct_00235590_ent *found = 0;
    int i = 0;
    UnkStruct_00235590_ent *e;
    UnkStruct_00235590_item *q;
    int t;
    goto test;
    body:
    e = &self->field_A0[i];
    if (e->field_10 != 0)
    {
      goto next;
    }
    t = e->field_C->field_0 & 2;
    if (t == 2)
    {
      goto l500;
    }
    l448:
    if (t == 2)
    {
      goto l46c;
    }
    if ((key->field_0 & 2) == 2)
    {
      func_0022D850(key);
    }
    l46c:
    ;
    l470:
    if (e->field_C->field_C != key->field_C)
    {
      goto next;
    }
    if (e->field_C->field_3 != key->field_3)
    {
      goto next;
    }
    if (e->field_C->field_4 != key->field_4)
    {
      goto next;
    }
    if (e->field_C->field_8 != key->field_8)
    {
      goto next;
    }
    found = e;
    goto after;
    test:
    if (i < 32)
    {
      goto body;
    }
    after:
    if (found != 0)
    {
      if (self->field_94 != 0) { self->field_94(key->field_4, found->field_C->field_3, found->field_C->field_C); }
      self->field_A0[i].field_10 = 1;
    }
    if ((key->field_0 & 2) == 2)
    {
      goto end850;
    }
    ret1:
    return 1;
    l500:
    if ((key->field_0 & 2) == 2)
    {
      goto l448;
    }
    func_0022D890(key, 0x10);
    q = e->field_C;
    goto l470;
    next:
    i++;
    goto test;
    end850:
    func_0022D850(key);
    goto ret1;
  }
  if ((key->field_0 & 2) == 2)
  {
    func_0022D850(key);
  }
  return 0;
}

// Hand-written; the lifter refused it (slot-find + msg copy; int on=(f&1)!=0; if(on!=0) gives sltu).
// 0x00235960
extern "C" void func_00235960(UnkStruct_00235960 *self, UnkStruct_00235960_msg *m, int p2, int p3)
{
    int on = (m->field_2 & 1) != 0;
    if (on != 0) {
        UnkStruct_00235960_slot *s = 0;
        for (int i = 0; i < 10; i++) {
            if ((self->field_440[i].field_0 & 1) != 1) {
                s = &self->field_440[i];
                break;
            }
        }
        if (s != 0) {
            int v8 = m->field_8;
            int v4 = m->field_4;
            signed char v3 = m->field_3;
            s->field_C = m->field_C;
            s->field_4 = v4;
            s->field_8 = v8;
            s->field_2 = 4;
            s->field_3 = v3;
            s->field_1 = 0;
            s->field_0 = 0;
            s->field_0 = s->field_0 | 1;
            func_0022D890(s, 16);
            func_0022D970(s, 16);
            self->field_7C->vfunc_C(s, 16, p2, p3);
        }
    }
}

// Hand-written; the lifter refused it (twin of 00235960: offset 0x3A0, type 2).
// 0x00235A80
extern "C" void func_00235A80(UnkStruct_00235A80 *self, UnkStruct_00235A80_msg *m, int p2, int p3)
{
    int on = (m->field_2 & 1) != 0;
    if (on != 0) {
        UnkStruct_00235A80_slot *s = 0;
        for (int i = 0; i < 10; i++) {
            if ((self->field_440[i].field_0 & 1) != 1) {
                s = &self->field_440[i];
                break;
            }
        }
        if (s != 0) {
            int v8 = m->field_8;
            int v4 = m->field_4;
            signed char v3 = m->field_3;
            s->field_C = m->field_C;
            s->field_4 = v4;
            s->field_8 = v8;
            s->field_2 = 2;
            s->field_3 = v3;
            s->field_1 = 0;
            s->field_0 = 0;
            s->field_0 = s->field_0 | 1;
            func_0022D890(s, 16);
            func_0022D970(s, 16);
            self->field_7C->vfunc_C(s, 16, p2, p3);
        }
    }
}

// Hand-written; the lifter refused it (tiny extern C).
// 0x00235BA0
extern "C" void func_00235BA0(char *self) { ResetFinaliseNATDataVariables__17CGtNATDataManagerFv(self + 0x4E0); }

// func_00235BB0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00235BB0
extern "C" int func_00235BB0(UnkStruct_00235BB0 *self, int id, float p0, float p1)
{
    UnkStruct_00235BB0_pl *pl;
    int b;
    UnkStruct_00235BB0_pl **pp;
    char buf[16];
    int a;
    int i;
    if (id == self->field_78) {
        pl = 0;
    } else {
        i;
        for (i = 0; i < self->field_28; i++) {
            pp = &self->field_8[i];
            bool t0 = *pp != 0;
            if (!(t0 && id == func_0022FBB0(*pp))) {
            } else {
                pl = *pp;
                goto found;
            }
        }
        pl = 0;
    }
found:
    id = func_002311D0(self->field_4E0, self->field_78, p0, p1, id, self->field_88, &a, &b);
    if (id == 0) {
        if (a != -1) {
            snprintf(buf, 16, D_004BA008, (unsigned char)((a & 0xFF000000) >> 24), (a & 0xFF0000) >> 16, (a & 0xFF00) >> 8, a & 0xFF);
            if (pl->field_24 != a) {
                pl->field_24 = a;
                snprintf(pl->field_14, 16, D_004BA008, (unsigned char)((pl->field_24 & 0xFF000000) >> 24), (pl->field_24 & 0xFF0000) >> 16, (pl->field_24 & 0xFF00) >> 8, pl->field_24 & 0xFF);
            }
        }
        if (b != -1) {
            pl->field_28 = b;
        }
        return id;
    }
    if (id == 1) {
        pl->field_4B0 = 1;
    }
    if (b != -1) {
        pl->field_28 = b;
    }
    return id;
}

// func_00235D90 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00235D90
extern "C" void func_00235D90(UnkStruct_00235D90 * self)
{
    self->field_320 = 0;
    for (int i = 0; (i < 32); i++) {
        int v = self->field_98 + self->field_84 * i;
        self->field_A0[i].field_0 = -1;
        self->field_A0[i].field_4 = 0;
        self->field_A0[i].field_8 = -1;
        self->field_A0[i].field_C = v;
        self->field_A0[i].field_10 = 1;
    }
}

// Hand-written; the lifter refused it (a119: row-base byte-offset form, bool d tested plainly, trailing return).
// 0x00235DF0
extern "C" void func_00235DF0(UnkStruct_00235DF0 *self, int id, signed char *data, int len)
{
    UnkStruct_00235DF0_slot *s = 0;
    int n;
    for (n = 0; n < 0x20; n++) {
        UnkStruct_00235DF0_row *e = (UnkStruct_00235DF0_row *)((char *)self + self->field_320 * 20);
        if (e->field_A0.field_10 != 0 && (*(unsigned char *)e->field_A0.field_C & 1) != 1) {
            s = &e->field_A0;
            break;
        }
        self->field_320 = self->field_320 + 1;
        if (self->field_320 >= 0x20) {
            self->field_320 = 0;
        }
    }
    if (s != 0) {
        int i;
        for (i = 0; i < 0x20; i++) {
            UnkStruct_00235DF0_row *e = (UnkStruct_00235DF0_row *)((char *)self + i * 20);
            if (e->field_A0.field_10 == 0 && e->field_A0.field_0 == id && e->field_A0.field_C[3] == data[3]) {
                int j;
                bool d = false;
                for (j = 0; j < len; j++) {
                    if (data[j] != e->field_A0.field_C[j]) {
                        d = true;
                        break;
                    }
                }
                if (!d) {
                    return;
                }
            }
        }
        memcpy(s->field_C, data, len);
        s->field_0 = id;
        s->field_4 = len;
        s->field_8 = -1;
        s->field_10 = 0;
        return;
    }
}

// Hand-written; the lifter refused it (a183: shared return join via goto out/none/inc stubs after entry-jump loop, plain).
// 0x00236310
extern "C" void *func_00236310(UnkStruct_00236310 *self, int p0)
{
    int i;
    int lo = self->field_78;
    int next;
    if (p0 < lo) {
        next = lo;
    } else {
        next = 0x7FFFFFFF;
    }
    for (i = 0; i < self->field_28; i++) {
        if (self->field_8[i] != 0) {
            int id = func_0022FBB0(self->field_8[i]);
            if (id != p0) {
                if (id > p0 && id < next) {
                    next = id;
                }
                if (id < lo) {
                    lo = id;
                }
            }
        }
    }
    if (next == 0x7FFFFFFF) {
        next = lo;
    }
    {
        int j;
        void *r;
        if (next == self->field_78) goto none;
        j = 0;
        goto test;
    body:
        if (self->field_8[j] == 0) goto inc;
        if (next != func_0022FBB0(self->field_8[j])) goto inc;
        r = self->field_8[j];
        goto out;
    test:
        if (j < self->field_28) goto body;
        r = 0;
    out:
        return r;
    none:
        r = 0;
        goto out;
    inc:
        j++;
        goto test;
    }
}

// Hand-written; the lifter refused it (a183: twin of 236310, goto out/none/inc tail, plain).
// 0x00236460
extern "C" void *func_00236460(UnkStruct_00236460 *self, int p0)
{
    int i;
    int lo = self->field_78;
    int next;
    if (lo < p0) {
        next = lo;
    } else {
        next = -1;
    }
    for (i = 0; i < self->field_28; i++) {
        if (self->field_8[i] != 0) {
            int id = func_0022FBB0(self->field_8[i]);
            if (id != p0) {
                if (id < p0 && next < id) {
                    next = id;
                }
                if (lo < id) {
                    lo = id;
                }
            }
        }
    }
    if (next == -1) {
        next = lo;
    }
    {
        int j;
        void *r;
        if (next == self->field_78) goto none;
        j = 0;
        goto test;
    body:
        if (self->field_8[j] == 0) goto inc;
        if (next != func_0022FBB0(self->field_8[j])) goto inc;
        r = self->field_8[j];
        goto out;
    test:
        if (j < self->field_28) goto body;
        r = 0;
    out:
        return r;
    none:
        r = 0;
        goto out;
    inc:
        j++;
        goto test;
    }
}

// Hand-written; the lifter refused it (bool; decl order count, hi, lo).
// 0x002365A0
extern "C" bool func_002365A0(UnkStruct_002365A0 *self, int p0, int p1)
{
    int count = 0;
    int hi;
    int lo;
    if (p1 < p0) {
        hi = p0;
        lo = p1;
    } else {
        hi = p1;
        lo = p0;
    }
    if (self->field_78 < hi && lo < self->field_78) {
        count++;
    }
    for (int i = 0; i < self->field_28; i++) {
        if (self->field_8[i] != 0) {
            int id = func_0022FBB0(self->field_8[i]);
            if (id != p0 && id != p1 && id < hi && lo < id) {
                count++;
            }
        }
    }
    int half = self->field_28 / 2;
    if (count < half) {
        return p1 < p0;
    }
    return p0 < p1;
}

// func_002366D0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x002366D0
extern "C" int func_002366D0(UnkStruct_002366D0 * self, int p0)
{
    return self->field_8[p0];
}

// CGtNetworkPlayerManager::SetMyPlayerID(int) -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtNetworkPlayerManager.cpp.
// 0x00236780
void CGtNetworkPlayerManager::SetMyPlayerID(int p0)
{
    field_78 = p0;
}

// CGtNetworkPlayerManager::GetMyPlayerID() const -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtNetworkPlayerManager.cpp.
// 0x00236790
int CGtNetworkPlayerManager::GetMyPlayerID() const
{
    return field_78;
}

// CGtNetworkPlayerManager::SetMyPlayerIndex(int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtNetworkPlayerManager.cpp.
// 0x002367A0
void CGtNetworkPlayerManager::SetMyPlayerIndex(int p0)
{
    field_28 = (field_28 + 1);
}

// CGtNetworkPlayerManager::GetMyPlayerIndex() const -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtNetworkPlayerManager.cpp.
// 0x002367B0
int CGtNetworkPlayerManager::GetMyPlayerIndex() const
{
    int t0 = field_28;
    for (int i = 0; (i < t0); i++) {
        if (field_8[i] == 0) {
            return i;
        }
    }
    return -1;
}

// ClearAllPlayers__23CGtNetworkPlayerManagerFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00236940
extern "C" void ClearAllPlayers__23CGtNetworkPlayerManagerFv(UnkStruct_00236940 * self)
{
    for (int i = 0; (i < self->field_28); i++) {
        UnkStruct_00236940_2 * t0 = self->field_8[i];
        if (t0 != 0) {
            int r0 = func_0022FBB0(t0);
            func_00230F60(((char *)self + 0x4E0), r0);
            self->field_8[i]->vfunc_C();
            self->field_2C[self->field_4C] = (void *)self->field_8[i];
            self->field_4C = (self->field_4C + 1);
            self->field_8[i] = 0;
        }
    }
    self->field_28 = 0;
    self->field_78 = -1;
    self->field_80 = -1;
}

// func_00236B30 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00236B30
extern "C" void func_00236B30(UnkStruct_00236B30 * self, int p0)
{
    if (self->field_0 == 23) {
        self->field_88 = p0;
        if (self->field_4 != 0 && func_0022D3B0() != 0) {
            for (int i = 0; (i < self->field_28); i++) {
                if (self->field_8[i] != 0) {
                    func_002300D0(self->field_8[i]);
                }
            }
        }
    }
}

// func_00236BC0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00236BC0
extern "C" void func_00236BC0(UnkStruct_00236BC0 * self, int p0)
{
    self->field_88 = p0;
    int t0 = self->field_0;
    if (t0 == 23) {
        func_00235F80(self);
    }
}

// func_00236C00 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00236C00
extern "C" int func_00236C00(UnkStruct_00236C00 * self)
{
    self->field_7C = 0;
    self->field_94 = 0;
    int r0 = func_002349A0(((char *)self + 0x4E0));
    if (r0 == 0) {
        return 0;
    }
    self->field_0 = 24;
    return 1;
}
