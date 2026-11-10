// NONMATCHING: SetAlpha__13CB3RadialBlurFUlUliiiiP10CGtTextureb -- retail 184 / ours 182 instructions, 189 in changed runs
// a252: logic/loop structure decoded from retail (two sprite-strip loops, n1/n2 block counts, u/v fixed-point); remaining: reg alloc (retail keeps 3 callee-saved s0-s2, frame 0x30 vs 0x20) and quad store scheduling; 182 vs 184 instrs
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// Hand-written; the lifter refused it (a252).
typedef unsigned int u_long128 __attribute__((mode(TI)));

class CGtTexture {
public:
    unsigned char pad_0[0xC];
    int field_C;
    int field_10;
    unsigned char pad_14[0x28];
    unsigned int field_3C;
    unsigned int field_40;
};

struct UnkStruct_farFogPlane {
    u_long128 * field_0;
};

class CB3RadialBlur {
public:
    void SetAlpha(unsigned long p0, unsigned long p1, int p2, int p3, int p4, int p5, CGtTexture * p6, bool p7);

    unsigned char pad_0[8];
    float field_8;
    float field_C;
};

extern UnkStruct_farFogPlane farFogPlane;

void CB3RadialBlur::SetAlpha(unsigned long p0, unsigned long p1, int p2, int p3, int p4, int p5, CGtTexture * p6, bool p7)
{
    int n1 = (p2 + 31) / 32;
    int n2 = (p4 + 31) / 32 - p2 / 32;
    float fs = (float)p6->field_C / ((float)p4 * field_8);
    int x0 = p2 << 4;
    u_long128 * q = farFogPlane.field_0;
    u_long128 q0;
    asm("pcpyld %0, %2, %1" : "=r"(q0) : "r"(3 | ((unsigned long)0x10AB4000 << 32)), "r"(14));
    unsigned long c1 = p0 | (p1 << 16) | ((unsigned long)0xFFFFFF << 32);
    u_long128 q1;
    float ft = (float)p6->field_10 / ((float)p5 * field_C);
    int u = (int)(fs * (float)x0);
    asm("pcpyld %0, %2, %1" : "=r"(q1) : "r"(c1), "r"(76));
    q[0] = q0;
    q[1] = q1;
    u_long128 q2;
    asm("pcpyld %0, %2, %1" : "=r"(q2) : "r"(p6->field_3C | ((unsigned long)p6->field_40 << 32)), "r"(6));
    q[2] = q2;
    u_long128 q3;
    asm("pcpyld %0, %2, %1" : "=r"(q3) : "r"(5), "r"(8));
    q[3] = q3;
    u_long128 q4;
    asm("pcpyld %0, %2, %1" : "=r"(q4) : "r"((unsigned long)(unsigned int)(n1 + n2) | ((unsigned long)0x84000000 << 32)), "r"(0x53535353));
    q[4] = q4;
    q += 5;
    int vt = 0;
    if (p7) {
        vt = (int)(ft * (float)(p3 << 4));
    }
    int dv = (int)(ft * (float)((p5 - p3) << 4));
    long yb = (long)(p5 << 4) << 16;
    long ya = (long)(p3 << 4) << 16;
    long vt16 = (long)vt << 16;
    long dv16 = (long)dv << 16;
    long x = 0;
    int xe = p2 << 4;
    do {
        n1--;
        long xp = x;
        long s1 = u | vt16;
        long s0 = u | dv16;
        long t8 = x | yb;
        if (n1 == 0) {
            x = xe;
            u = 0;
        } else {
            x += 0x200;
            u = (int)(fs * (float)(x0 - (int)x));
        }
        u_long128 a;
        asm("pcpyld %0, %2, %1" : "=r"(a) : "r"(s1), "r"(xp));
        q[0] = a;
        u_long128 b;
        asm("pcpyld %0, %2, %1" : "=r"(b) : "r"((long)u), "r"(x | ya));
        q[1] = b;
        q[2] = b;
        u_long128 c;
        asm("pcpyld %0, %2, %1" : "=r"(c) : "r"(s0), "r"(t8));
        q[3] = c;
        q += 4;
    } while (n1);
    int xe2 = p4 << 4;
    do {
        n2--;
        long xp = x;
        long t5 = x | yb;
        long t2 = u | vt16;
        long t1 = u | dv16;
        if (n2 == 0) {
            x = xe2;
        } else {
            x += 0x200;
        }
        u_long128 a;
        asm("pcpyld %0, %2, %1" : "=r"(a) : "r"(t2), "r"(xp));
        q[0] = a;
        u_long128 c;
        asm("pcpyld %0, %2, %1" : "=r"(c) : "r"(t1), "r"(t5));
        u = (int)(fs * (float)((int)x - x0));
        u_long128 b;
        asm("pcpyld %0, %2, %1" : "=r"(b) : "r"((long)u), "r"(x | ya));
        q[1] = b;
        q[2] = b;
        q[3] = c;
        q += 4;
    } while (n2);
    farFogPlane.field_0 = q;
}
