// func_00353A30 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (near1 v242: exact with a labelled FAKEMATCH empty .set noreorder barrier (N188-style, approved by lead 2026-11-01; natural forms 2 off, N292)).

#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
namespace GtMathPs2 {
// [L] N185: stand-ins. A vsub on compiler-chosen registers (result over the second operand) and retail's usual
// squared length with the 1.0 parked in a GPR (a210_pre.h forms).
static inline CGtV3d func_00353A30_sub(CGtV3d a, CGtV3d b) { asm("vsub.xyz %0, %1, %0" : "+j"(b.mData) : "j"(a.mData)); return b; }
static inline XAxisType func_00353A30_sqlen(CGtV3d a)
{
    u_long128 o, one, m, d, w;
    asm("vaddw.x %0, $vf0, $vf0w" : "=j"(o));
    asm("qmfc2.i %0, %1" : "=r"(one) : "j"(o));
    asm("vmul.xyz %0, %1, %1" "\n\t" "vadday.x $ACC, %0, %0y" : "=j"(m) : "j"(*(const u_long128*)&a.mData));
    asm("qmtc2.i %2, %1" "\n\t" "vmaddz.x %1, %1, %3z" "\n\t" "qmfc2.i %0, %1" : "=r"(d), "=&j"(w) : "r"(one), "j"(m));
    // FAKEMATCH [G] N188-style barrier (approved 2026-11-01, N292): an empty .set noreorder region keeps b119 from moving the
    // caller's lwc1 of the threshold into the vmaddz latency gap (retail: qmfc2.ni, then lwc1, then mtc1).
    asm(".set noreorder");
    asm(".set reorder");
    return XAxisType(d);
}
}
class CGtSphereTreeSphere;
struct UnkStruct_00353A30_4 { unsigned char pad_0[0x30]; CGtV3d field_30; };
struct UnkStruct_00353A30_2 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual int vfunc_1C();
    unsigned char pad_4[0x200];
    UnkStruct_00353A30_4 * field_204;
    unsigned char pad_208[0x6];
    unsigned char field_20E;
};
// [G] the 0x70-byte record at self + 0x2E0 + i*0x70 (the sphere-tree sphere and its per-body data)
struct UnkStruct_00353A30_r {
    CGtV3dPlus field_0;
    CGtV3d * field_10;
    unsigned char pad_14[0x1C];
    float field_30;
    unsigned char pad_34[0xC];
    UnkStruct_00353A30_2 * field_40;
    unsigned char pad_44[4];
    float field_48;
    unsigned char pad_4C[8];
    float field_54;
    unsigned char pad_58[8];
    float field_60;
    unsigned char pad_64[4];
    unsigned char field_68;
    unsigned char field_69;
    unsigned char pad_6A[6];
};
struct UnkStruct_00353A30_e1 { unsigned char pad_0[0x70]; };
struct UnkStruct_00353A30_e0 {
    unsigned char pad_0[0x10];
    UnkStruct_00353A30_2 * field_10;
    unsigned char pad_14[0x25];
    unsigned char field_39;
    unsigned char pad_3A[0x36];
};
struct UnkStruct_00353A30_7 { UnkStruct_00353A30_7 * field_0; };
struct UnkStruct_00353A30 {
    UnkStruct_00353A30_7 * field_0;
    unsigned char pad_4[0x6C];
    unsigned char pad_70[0x2A0];
    UnkStruct_00353A30_e0 field_310[1];  // [G] element count unknown
    unsigned char pad_380[0xC88];
    int field_1008[10];
    int field_1030;
    unsigned char pad_1034[0x14];
    unsigned char field_1048;
    unsigned char field_1049;
};
extern "C" void UpdateCollidingPairs__16CB3CrashAnalyserFv(void *);
extern "C" void RemoveSphere__13CGtSphereTreeFP19CGtSphereTreeSphere(void *, void *);
extern "C" void AddToIntegrateList__13CGtSphereTreeFP19CGtSphereTreeSphere(void *, void *);
extern "C" void Update__13CGtSphereTreeFv(void *);
extern "C" void func_00354460(UnkStruct_00353A30 *);
extern "C" float func_003548C0(UnkStruct_00353A30 *, void *);
extern "C" float func_003541D0(UnkStruct_00353A30 *, void *);

// 0x00353A30
extern "C" void func_00353A30(UnkStruct_00353A30 * self, float dt)
{
    if (self->field_1049 == 0) {
        return;
    }
    self->field_1048 = 0;
    UpdateCollidingPairs__16CB3CrashAnalyserFv(self);
    func_00354460(self);
    for (int i = 0; i < self->field_1030; i++) {
        UnkStruct_00353A30_r * s = (UnkStruct_00353A30_r *)((char *)self + i * 0x70 + 0x2E0);
        UnkStruct_00353A30_2 * b = self->field_310[i].field_10;
        if (self->field_310[i].field_39 == 0) {
            if (b->vfunc_1C() != 0) {
                RemoveSphere__13CGtSphereTreeFP19CGtSphereTreeSphere(self, s);
                s->field_69 = 1;
                s->field_60 = 0.0f;
                s->field_54 = -1.0f;
                s->field_68 = 0;
            } else {
                s->field_60 = func_003548C0(self, s);
                if (b->field_20E == 0) {
                    CGtV3d pos = b->field_204->field_30;
                    s->field_0.SetGtV3d(pos);
                    if (s->field_10 != 0) {
                        if (!(func_00353A30_sqlen(func_00353A30_sub(pos, *s->field_10)) < s->field_30)) {
                            AddToIntegrateList__13CGtSphereTreeFP19CGtSphereTreeSphere(self, s);
                        }
                    }
                }
                s->field_48 = s->field_48 + dt;
            }
        }
    }
    Update__13CGtSphereTreeFv(self);
    for (int j = 0; j < 10; j++) {
        self->field_1008[j] = 0;
    }
    UnkStruct_00353A30_7 * m = self->field_0;
    while (m != (UnkStruct_00353A30_7 *)self) {
        func_003541D0(self, (char *)m - 0x14);
        m = m->field_0;
    }
}
