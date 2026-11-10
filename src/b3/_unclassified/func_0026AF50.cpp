// Hand-written; the lifter refused it (ghvu9: IntersectFrustum microprogram inline (loads+vcallms one stmt in noreorder region), FlushInstances' mesh-cache copy loop, case 3 before 2, (unsigned long)(unsigned char)k, literal 0UL zero half, int i at top).

// func_0026AF50 -- hand-written from the Ghidra draft (ghvu9). A CB3TrackRenderer helper (a0 = the renderer D_01E32A10 at
// both callers in RenderBeforeVehicles__16CB3StreamedTrack): unless p2 == 1, frustum-test the instance box with the
// IntersectFrustum microprogram (vcallms 0xA18, as IntersectFrustum__14GtIntersection and FlushInstances), then append the
// cached mesh quads and the instance quads to the mesh cache's packet. Field names are placeholders, types [G].

typedef unsigned int u_long128 __attribute__((mode(TI)));

struct UnkStruct_0026AF50_mc {
    int field_0;
    u_long128 * field_4;
    unsigned char pad_8[0x8];
    u_long128 field_10[1];
};

struct UnkStruct_0026AF50_box {
    unsigned char pad_0[0xC];
    unsigned int field_C;
    unsigned char pad_10[0xC];
    unsigned int field_1C;
};

struct UnkStruct_0026AF50_fr {
    u_long128 field_0[6];
};

struct UnkStruct_0026AF50_r {
    u_long128 field_0;
    u_long128 field_10;
    u_long128 field_20;
    unsigned char pad_30[0x68];
    signed char field_98;
    signed char field_99;
    unsigned char pad_9A;
    unsigned char field_9B;
};

extern UnkStruct_0026AF50_mc * _gpMeshCache;
extern UnkStruct_0026AF50_fr D_01E327D0[];

// [L] the GtIntersection::IntersectFrustum microprogram call (IntersectFrustum__14GtIntersection 0x274BC0 without its code
// upload): box rows into $vf1/$vf6-$vf8, frustum planes into $vf9-$vf14, vcallms 0xA18, result in $vi1. The loads and the
// vcallms in one statement (else b119 drops the outputless loads) inside a `.set noreorder` region (N223: else the lb'd frustum
// index is re-extended before the multiply) [G]
static inline int func_0026AF50_inl1(const UnkStruct_0026AF50_fr * f, const UnkStruct_0026AF50_box * b)
{
    int r;
    asm(".set noreorder");
    asm("lqc2 $vf1, 0x30(%0)\n\tlqc2 $vf6, 0x20(%0)\n\tlqc2 $vf7, 0x0(%0)\n\tlqc2 $vf8, 0x10(%0)\n\t"
        "lqc2 $vf9, 0x20(%1)\n\tlqc2 $vf10, 0x30(%1)\n\tlqc2 $vf11, 0x40(%1)\n\tlqc2 $vf12, 0x50(%1)\n\t"
        "lqc2 $vf13, 0x0(%1)\n\tlqc2 $vf14, 0x10(%1)\n\tvcallms 0xA18" : : "r"(b), "r"(f));
    asm(".set reorder");
    asm("cfc2.i %0, $vi1" : "=r"(r));
    return r & 0xFFFF;
}

// 0x0026AF50
extern "C" int func_0026AF50(UnkStruct_0026AF50_r * self, const UnkStruct_0026AF50_box * e, int fl, int k)
{
    int i;
    int n = _gpMeshCache->field_0;
    if (fl != 1) {
        int ix = self->field_99;
        int r = func_0026AF50_inl1(&D_01E327D0[ix], e);
        if (r == 0) {
            return 0;
        }
        int v;   // [G] a copy variable: retail keeps `move t2,a2; move a2,t2` on the else path
        if (r == 2) {
            v = 1;
        } else {
            v = fl;
        }
        fl = v;
    }
    self->field_9B = 1;
    u_long128 * p = _gpMeshCache->field_4;
    asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"(((unsigned long)e->field_C << 32) | 0x50000000), "r"(0UL));   // a literal zero half: retail's fresh `daddu t3,zero,zero` (N218)
    *p++ = self->field_0;
    u_long128 * src = _gpMeshCache->field_10;
    i = 0;
    while (i < _gpMeshCache->field_0 - 7) {
        u_long128 a7, a6, a5, a4, a3, a2, a1, a0;
        a0 = src[i];
        a1 = src[i + 1];
        a2 = src[i + 2];
        a3 = src[i + 3];
        a4 = src[i + 4];
        a5 = src[i + 5];
        a6 = src[i + 6];
        a7 = src[i + 7];
        i += 8;
        *p++ = a0;
        *p++ = a1;
        *p++ = a2;
        *p++ = a3;
        *p++ = a4;
        *p++ = a5;
        *p++ = a6;
        *p++ = a7;
    }
    while (i < _gpMeshCache->field_0) {
        *p++ = src[i];
        i++;
    }
    _gpMeshCache->field_0 = 0;
    int c = n | (fl & ~self->field_98);
    self->field_98 = fl;
    if (c > 0) {
        unsigned int m;
        switch (fl) {
        case 3:
            m = 10;
            break;
        case 2:
            m = 2;
            break;
        default:
            m = 0;
            break;
        }
        *p++ = self->field_10;
        asm("pcpyld %0, %2, %1" : "=r"(*p++) : "r"((unsigned long)m), "r"(((long)c << 32) | (unsigned long)(unsigned char)k));
    }
    u_long128 q;
    if (e->field_1C != 0) {
        asm("pcpyld %0, %2, %1" : "=r"(q) : "r"(((unsigned long)e->field_1C << 32) | 0x50000000), "r"(0x17000000UL));
    } else {
        q = self->field_20;
    }
    *p++ = q;
    _gpMeshCache->field_4 = p;
    return 1;
}
