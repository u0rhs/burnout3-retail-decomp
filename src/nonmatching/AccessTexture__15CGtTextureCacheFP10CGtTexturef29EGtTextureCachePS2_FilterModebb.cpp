// NONMATCHING: AccessTexture__15CGtTextureCacheFP10CGtTexturef29EGtTextureCachePS2_FilterModebb -- retail 257 / ours 255 instructions, 127 in changed runs
// L267: hand-written (lifter refused); control flow, TEX1 bitfield/float math (two-statement 0.0625*k then +=f, reloaded field_16 via const pun) and packet stores exact. Left: s-register colours reversed among this/p0/mode/b1/ext (retail mode s0,p0 s1,this s2,ext s3,b1 s4; ours the reverse) -- declaration order, inline helper, quad order all insensitive; switch's dead 'ori 0x120' block missing; pcpyld constant scheduling follows the registers
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// CGtTextureCache::AccessTexture(CGtTexture*,float,EGtTextureCachePS2_FilterMode,bool,bool) -- hand-written (lifter refused).
// [C] name: the mangled symbol in retail's tables; file: research/retail_names.csv -> GtTextureCachePS2.cpp (sibling AddRasterToCache).
// Field names are placeholders and every type is [G]; the texture is read with RwRaster's layout [L] (RW 3.5 sky2:
// parent +0, cpPixels +4, cType +0x20, the sky raster extension at +0x34 whose +0x58 is RASTERGETCACHEENTRY).

typedef unsigned int u_long128 __attribute__((mode(TI)));

class CGtTexture;
class RwRaster;
enum EGtTextureCachePS2_FilterMode {};

struct UnkStruct_00221A70_ext {
    unsigned char pad_0[0x8];
    unsigned int field_8;
    unsigned int field_C;
    unsigned char pad_10[0x4];
    unsigned short field_14;
    unsigned char field_16;
    unsigned char pad_17;
    unsigned int field_18;
    unsigned int field_1C;
    unsigned int field_20;
    unsigned int field_24;
    unsigned char pad_28[0x30];
    void * field_58;
};

struct UnkStruct_00221A70_ras {
    UnkStruct_00221A70_ras * field_0;
    void * field_4;
    unsigned char pad_8[0x18];
    unsigned char field_20;
    unsigned char pad_21[0x13];
    UnkStruct_00221A70_ext field_34;
};

struct UnkStruct_farFogPlane {
    u_long128 * field_0;
};

extern UnkStruct_farFogPlane farFogPlane;
extern "C" void _rwDMAOpenVIFPkt(int, int);

class CGtTextureCache {
public:
    void AccessTexture(CGtTexture *, float, EGtTextureCachePS2_FilterMode, bool, bool);
    int AddRasterToCache(RwRaster *, int);
    int field_0;
    unsigned char pad_4[0xC];
    u_long128 field_10[11];
    unsigned char pad_C0[0x10C];
    UnkStruct_00221A70_ras * field_1CC;
};

#define MK(RES, MSB, LSB) asm("pcpyld %0, %1, %2" : "=r"(RES) : "r"((unsigned long)(MSB)), "r"((unsigned long)(LSB)))

// 0x00221A70
void CGtTextureCache::AccessTexture(CGtTexture *p0, float f, EGtTextureCachePS2_FilterMode mode, bool b1, bool b2)
{
    UnkStruct_00221A70_ras *r = (UnkStruct_00221A70_ras *)p0;
    bool up = false;
    if (r == 0) {
        field_1CC = 0;
        return;
    }
    UnkStruct_00221A70_ext *ext = &r->field_34;
    if (r != field_1CC) {
        if (!(r->field_20 & 0x80) && r->field_4 != 0 && ext->field_58 == 0) {
            AddRasterToCache((RwRaster *)r, 1);
        }
        up = true;
    }
    field_1CC = r;
    int type = r->field_20 & 7;
    if (type != 2 && ext->field_58 == 0) return;
    if (!up && !(type == 2 && r->field_0 != r)) return;
    unsigned long tex1;
    if ((ext->field_16 >> 2) > 0) {
        unsigned short v = ext->field_14;
        int k = v & 0xFFF;
        if (k & 0x800) k |= -0x1000;
        float fk = 0.0625f * k;
        fk += f;
        int ik = (int)(16.0f * fk);
        if (ik < -0x800) ik = -0x800;
        else if (ik > 0x7FF) ik = 0x7FF;
        v = (v & ~0xFFF) | ((unsigned short)ik & 0xFFF);
        tex1 = ((unsigned long)(int)((v >> 12) & 3) << 19) | ((unsigned long)(int)*(const unsigned char *)&ext->field_16 | ((unsigned long)(int)(v & 0xFFF) << 32));
    } else {
        unsigned short v = ext->field_14;
        tex1 = ((unsigned long)(int)((v >> 12) & 3) << 19) | ((unsigned long)(int)*(const unsigned char *)&ext->field_16 | ((unsigned long)(int)(v & 0xFFF) << 32));
    }
    switch (mode) {
    default: tex1 |= 0x120; break;
    case 0: break;
    case 2: tex1 |= 0x160; break;
    }
    u_long128 q0, q1, q2, q3, q4, q5, q6;
    MK(q0, 0x50000006UL << 32, 0x10000006);
    MK(q1, 0xE, (0x10000000UL << 32) | 0x8005);
    MK(q2, 0x3F, 0);
    MK(q3, (int)(b1 ? 7 : 6), ((unsigned long)ext->field_C << 32) | ext->field_8);
    MK(q4, 0x14, tex1);
    MK(q5, (int)(b1 ? 0x35 : 0x34), ((unsigned long)ext->field_1C << 32) | ext->field_18);
    MK(q6, (int)(b1 ? 0x37 : 0x36), ((unsigned long)ext->field_24 << 32) | ext->field_20);
    if (b2) {
        field_0 = 0;
        field_10[field_0++] = q0;
        field_10[field_0++] = q1;
        field_10[field_0++] = q2;
        field_10[field_0++] = q3;
        field_10[field_0++] = q4;
        field_10[field_0++] = q5;
        field_10[field_0++] = q6;
    } else {
        _rwDMAOpenVIFPkt(0, 7);
        u_long128 *p = farFogPlane.field_0;
        p[0] = q0;
        p[1] = q1;
        p[2] = q2;
        p[3] = q3;
        p[4] = q4;
        p[5] = q5;
        p[6] = q6;
        farFogPlane.field_0 = p + 7;
    }
}


