// NONMATCHING: SetTexture__12Gt2dRendererFP10CGtTexturei -- retail 154 / ours 152 instructions, 9 in changed runs
// a96: 152/154 instrs, 9 off: logic exact (sub-struct ptr s0=&t->field_34, A arm palette/else, B arm only palette>0). Retail leaves a nop in the blez delay slot and computes arr=&t->field_90 (addiu a0,s1,0x90) after it, with a0 reused for lw field_C; ours hoists addiu into the delay slot (a1). Tried arr local placement (outer/inner/byte-cast/&field_90[pal]), >=1, swapped arms, const arr
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

typedef unsigned int u_long128 __attribute__((mode(TI)));
struct UnkStruct_34 {
    unsigned char pad_0[8];
    unsigned int field_8;
    unsigned int field_C;
};
class CGtTexture {
public:
    unsigned char pad_0[0x34];
    UnkStruct_34 field_34;
    unsigned char pad_44[0x48];
    int field_8C;
    unsigned short field_90[8];
};
struct UnkStruct_skyTextureRaster { void *field_0; };
extern UnkStruct_skyTextureRaster skyTextureRaster;
extern "C" void RpSkyTexCacheAccessSpeculate(void *);
extern "C" int RpSkyTexCacheAccessRaster(void *, int);

class Gt2dRenderer {
public:
    static void SetTexture(CGtTexture *p0, int p1);
    static void _Dispatch();
    static u_long128 *_gau128Buffer;
    static unsigned long *_gpu64Current;
    static unsigned int *_gpuNLoops;
    static int _guCurrentPrimType;
    static u_long128 _gu128ADDRDATAGIFTag;
    static CGtTexture *_gpCurrentTexture;
    static int _gnCurrentTexturePalette;
};
void Gt2dRenderer::SetTexture(CGtTexture *p0, int p1)
{
    if (p0 == _gpCurrentTexture && p1 == _gnCurrentTexturePalette) {
        return;
    }
    _gnCurrentTexturePalette = p1;
    _gpCurrentTexture = p0;
    UnkStruct_34 *sub = &p0->field_34;
    if (p0->field_8C != 0) {
        if (511 - (int)(((unsigned int)(_gpu64Current + 1) - (unsigned int)_gau128Buffer) >> 4) < 2) {
            _Dispatch();
        }
        unsigned short *arr = p0->field_90;
        unsigned long lo;
        if (_gnCurrentTexturePalette > 0) {
            unsigned int a = sub->field_C + (arr[_gnCurrentTexturePalette] << 5);
            lo = sub->field_8 | ((unsigned long)a << 32);
        } else {
            lo = sub->field_8 | ((unsigned long)sub->field_C << 32);
        }
        u_long128 q;
        asm("pcpyld %0, %1, %2" : "=r"(q) : "r"(6), "r"(lo));
        if (_guCurrentPrimType != 10) {
            if (((int)_gpu64Current & 0xF) != 0) {
                _gpu64Current = _gpu64Current + 1;
            }
            _guCurrentPrimType = 10;
            u_long128 *tag = (u_long128 *)_gpu64Current;
            *tag = _gu128ADDRDATAGIFTag;
            _gpuNLoops = (unsigned int *)tag;
            _gpu64Current = _gpu64Current + 2;
        }
        *(u_long128 *)_gpu64Current = q;
        _gpu64Current = _gpu64Current + 2;
        *_gpuNLoops += 1;
    } else {
        if (_gpuNLoops != 0) {
            _Dispatch();
        }
        if (skyTextureRaster.field_0 != p0) {
            RpSkyTexCacheAccessSpeculate(p0);
            if (RpSkyTexCacheAccessRaster(p0, 0) != 0) {
                skyTextureRaster.field_0 = p0;
            }
        }
        unsigned short *arr = p0->field_90;
        if (_gnCurrentTexturePalette > 0) {
            unsigned int a = sub->field_C + (arr[_gnCurrentTexturePalette] << 5);
            unsigned long lo = sub->field_8 | ((unsigned long)a << 32);
            u_long128 q;
            asm("pcpyld %0, %1, %2" : "=r"(q) : "r"(6), "r"(lo));
            if (_guCurrentPrimType != 10) {
                if (((int)_gpu64Current & 0xF) != 0) {
                    _gpu64Current = _gpu64Current + 1;
                }
                _guCurrentPrimType = 10;
                u_long128 *tag = (u_long128 *)_gpu64Current;
                *tag = _gu128ADDRDATAGIFTag;
                _gpuNLoops = (unsigned int *)tag;
                _gpu64Current = _gpu64Current + 2;
            }
            *(u_long128 *)_gpu64Current = q;
            _gpu64Current = _gpu64Current + 2;
            *_gpuNLoops += 1;
        }
    }
}
