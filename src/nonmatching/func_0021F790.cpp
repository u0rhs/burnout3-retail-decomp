// NONMATCHING: func_0021F790 -- retail 261 / ours 262 instructions, 6 in changed runs
// draftX: rewritten from the RenderObject draft (old archive compiled to 0 instrs: permuter junk + wrong parameter order); 261/262, 6 changed: prologue only -- retail loads the stack bool (lbu) early with no andi and colours it t0; an early int copy gives the load and no andi but colours it t5 (13 changed)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] decoded op by op; same packet body as RenderObject plus the deformation-matrix copy loop; only prologue order/one andi differ

// func_0021F790 -- draftX (rewritten from the RenderObject draft, func_0021FBB0). [L] CB3VehicleRenderer::
// RenderDeformedObject(EB3VehicleRenderType, const CGtMatrix3x4&, CB3VehicleObject*, float, ushort, ushort,
// const CGtMatrix3x4*, int, bool) (research/nahelam_check.csv): t2 = deformation matrices, t3 = count, bool on the stack [C].
// Structure from the retail asm (0x21FBB0, 245 instrs) [C]: the VU microprogram setup (vcallms 0x7D8), the GIF tag
// for the 13-quad header, then one DMA packet per mesh whose mask bit is set (vcallms 0xB50, _rwDMAOpenVIFPkt).
// Same packet body as the sibling RenderDeformedObject (func_0021F790) minus the deformation matrices.
// Hard-coded $vf registers / vcallms are Criterion's own asm blocks (retail register numbers are fixed) [L].
// Field names are placeholders; types from instruction widths [G].
typedef unsigned int u_long128 __attribute__((mode(TI)));

union UnkStruct_0021FBB0_q { u_long128 q; int w[4]; };
struct UnkStruct_0021FBB0_mesh {        // [G] CB3VehicleMesh (0x10 bytes; RenderVehicle archive)
    unsigned int field_0;
    int field_4;
    unsigned short field_8;
    unsigned char field_A;
    unsigned char field_B;
    unsigned char field_C;
    unsigned char field_D;
    unsigned char pad_E[2];
};
class CB3VehicleObject {
public:
    signed char field_0;                 // [L] mesh count
    signed char field_1;
    unsigned char pad_2[2];
    UnkStruct_0021FBB0_mesh *field_4;
    float field_8;
};
struct UnkStruct_0021FBB0_d {
    u_long128 field_0[3];
    unsigned char pad_30[4];
    float field_34;
    int field_38;
    int field_3C;
    u_long128 field_40[0x2D];
    u_long128 field_310[3];
    float field_340[3];
    float field_34C;
    u_long128 field_350;
    u_long128 field_360;
    u_long128 field_370;
    u_long128 field_380;
    UnkStruct_0021FBB0_q field_390;
    UnkStruct_0021FBB0_q field_3A0;
    unsigned long field_3B0;
    unsigned long pad_3B8;
    u_long128 field_3C0;
    u_long128 field_3D0;
    u_long128 field_3E0;
    u_long128 field_3F0;
};
struct UnkStruct_0021FBB0_b0 { u_long128 field_0[5]; };
class CB3VehicleRenderer {
public:
    unsigned char pad_0[0x20];
    u_long128 field_20[9];
    UnkStruct_0021FBB0_b0 field_B0;
    UnkStruct_0021FBB0_d *field_100;
};
struct UnkStruct_0021FBB0_fog { u_long128 *field_0; };
extern UnkStruct_0021FBB0_fog farFogPlane;   // [G] retail label; used as the open VIF packet write pointer
extern "C" void _rwDMAOpenVIFPkt(int, int);

// 0x0021F790
extern "C" void func_0021F790(CB3VehicleRenderer *self, int leType, const u_long128 *mat, CB3VehicleObject *obj,
                              float f, unsigned short mask, unsigned short p5, const u_long128 *src, int n, bool p8)
{
    self->field_100->field_34C = obj->field_8;
    UnkStruct_0021FBB0_d *d = self->field_100;
    asm(".set noreorder");
    asm("ctc2.i %1, $vi3\n\tlqc2 $vf1, 0x0(%5)\n\tlqc2 $vf2, 0x10(%5)\n\tlqc2 $vf3, 0x20(%5)\n\tlqc2 $vf4, 0x30(%5)\n\tlqc2 $vf5, 0x0(%3)\n\tlqc2 $vf6, 0x10(%3)\n\tlqc2 $vf7, 0x20(%3)\n\tlqc2 $vf8, 0x50(%0)\n\tlqc2 $vf9, 0x60(%0)\n\tlqc2 $vf10, 0x70(%0)\n\tlqc2 $vf11, 0x80(%0)\n\tlqc2 $vf12, 0x10(%2)\n\tlqc2 $vf13, 0x30(%2)\n\tlqc2 $vf14, 0x0(%4)"
        : : "r"(d->field_40), "r"(p8), "r"(&self->field_B0), "r"(d->field_310), "r"(d->field_340), "r"(mat));
    asm("vcallms 0x7D8");
    asm(".set reorder");
    d->field_3C = 13;
    u_long128 *q = &self->field_100->field_40[self->field_100->field_3C];
    int i;
    for (i = 0; i < n; i++) {
        u_long128 a0 = src[0];
        u_long128 a1 = src[1];
        u_long128 a2 = src[2];
        u_long128 a3 = src[3];
        q[0] = a0;
        q[1] = a1;
        q[2] = a2;
        q[3] = a3;
        src += 4;
        q += 4;
    }
    self->field_100->field_390.w[2] = n;
    self->field_100->field_3C += n * 4;
    int k = self->field_100->field_3C;
    asm("pcpyld %0, %2, %1" : "=r"(self->field_100->field_40[0])
        : "r"((long)(int)((k - 1) | 0x10000000)),
          "r"(((unsigned long)(unsigned int)(((k - 1) << 16) | 0x6C0003C2) << 32) | 0x01000404));
    self->field_100->field_34 = f;
    self->field_100->field_38 = p5;
    self->field_100->field_390.w[0] = leType;
    asm(".set noreorder");
    asm("ctc2.i $0, $vi4\n\tsqc2 $vf5, 0x10(%0)\n\tsqc2 $vf6, 0x20(%0)\n\tsqc2 $vf7, 0x30(%0)\n\tsqc2 $vf8, 0x40(%0)\n\tsqc2 $vf1, 0x50(%0)\n\tsqc2 $vf2, 0x60(%0)\n\tsqc2 $vf3, 0x70(%0)\n\tsqc2 $vf4, 0x80(%0)\n\tsqc2 $vf14, 0x90(%0)\n\tsqc2 $vf9, 0xA0(%0)\n\tsqc2 $vf10, 0xB0(%0)\n\tsqc2 $vf11, 0xC0(%0)"
        : : "r"(self->field_100->field_40));
    asm(".set reorder");
    for (i = 0; i < obj->field_0; i++) {
        const UnkStruct_0021FBB0_mesh *base = obj->field_4;
        const UnkStruct_0021FBB0_mesh *e = (const UnkStruct_0021FBB0_mesh *)((unsigned int)(i << 4) + (unsigned int)base);
        int f8 = e->field_8;
        if ((mask & f8) == 0)
            continue;
        int b = e->field_B;
        UnkStruct_0021FBB0_d *dd = self->field_100;
        asm(".set noreorder");
        asm("ctc2.i %0, $vi5\n\tctc2.i %1, $vi4\n\tctc2.i %2, $vi6\n\tctc2.i %3, $vi9\n\tlqc2 $vf1, 0x0(%4)\n\tlqc2 $vf2, 0x10(%4)\n\tlqc2 $vf3, 0x20(%4)\n\tlqc2 $vf4, 0x30(%4)"
            : : "r"(b), "r"(f8), "r"(e->field_D), "r"(e->field_A), "r"(dd->field_0));
        asm("vcallms 0xB50");
        asm(".set reorder");
        _rwDMAOpenVIFPkt(0, dd->field_3C + 0xC);
        u_long128 *p = farFogPlane.field_0;
        asm("pcpyld %0, $0, %1" : "=r"(*p++) : "r"(((unsigned long)e->field_0 << 32) | 0x50000000));
        *(p++) = self->field_100->field_3C0;
        int m = self->field_100->field_3C;
        if (m != 0) {
            int j = 0;
            const u_long128 *s = self->field_100->field_40;
            while (j < m - 3) {
                u_long128 a0 = s[0];
                u_long128 a1 = s[1];
                u_long128 a2 = s[2];
                u_long128 a3 = s[3];
                j += 4;
                s += 4;
                *(p++) = a0;
                *(p++) = a1;
                *(p++) = a2;
                *(p++) = a3;
            }
            while (j < m) {
                *(p++) = *(s++);
                j++;
            }
            self->field_100->field_3C = 0;
        }
        *(p++) = self->field_100->field_3D0;
        *(p++) = self->field_100->field_3E0;
        *(p++) = self->field_20[b];
        int c7;
        unsigned long c8;
        asm(".set noreorder");
        asm("cfc2.i %0, $vi7\n\tcfc2.ni %1, $vi8\n\tsqc2 $vf6, 0x0(%2)\n\tsqc2 $vf7, 0x10(%2)\n\tsqc2 $vf8, 0x20(%2)\n\tsqc2 $vf9, 0x30(%2)"
            : "=r"(c7), "=r"(c8) : "r"(&self->field_100->field_350));
        asm(".set reorder");
        self->field_100->field_390.w[1] = c7;
        self->field_100->field_3B0 = c8;
        *(p++) = self->field_100->field_380;
        asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(self->field_100->field_3B0), "r"(0x43UL));
        *(p++) = self->field_100->field_350;
        *(p++) = self->field_100->field_360;
        *(p++) = self->field_100->field_370;
        *(p++) = self->field_100->field_390.q;
        int f4 = e->field_4;
        u_long128 last;
        if (f4 != 0) {
            self->field_100->field_3A0.w[1] = f4;
            last = self->field_100->field_3A0.q;
        } else {
            last = self->field_100->field_3F0;
        }
        *(p++) = last;
        farFogPlane.field_0 = p;
    }
}
