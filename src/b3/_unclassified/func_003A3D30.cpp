// Hand-written; the lifter refused it (a115: ellipsis-truncate text to width; float globals as 16-byte wrapper (else gp-relative)).

struct UnkStruct_D_00665ED0 { void * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_Cell { unsigned char pad_0[0x10E]; unsigned short field_10E[1]; };
extern UnkStruct_D_00665ED0 D_00665ED0;
struct UnkStruct_F16 { float field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_F16 D_004C9E30;
extern UnkStruct_F16 D_004C9E40;
extern unsigned short D_004C9F00[];
extern "C" unsigned short * Copy__10CGtUnicodeFPUsPCUs(unsigned short *, const unsigned short *);
extern "C" unsigned short * Append__10CGtUnicodeFPUsPCUs(unsigned short *, const unsigned short *);
extern "C" int Length__10CGtUnicodeFPCUs(const unsigned short *);
extern "C" float GetStringWidth__9CGt2dFontCFPCUs(void *, const unsigned short *);

// 0x003A3D30
extern "C" unsigned short * func_003A3D30(UnkStruct_D_Cell * self, int flag, int idx, unsigned short * text)
{
    unsigned short * buf = (unsigned short *)((char *)self + idx * 36 + flag * 18 + 0x10E);
    Copy__10CGtUnicodeFPUsPCUs(buf, text);
    float w = 20.0f * GetStringWidth__9CGt2dFontCFPCUs(D_00665ED0.field_0, buf);
    float limit;
    if (flag == 0) {
        limit = D_004C9E30.field_0;
    } else {
        limit = D_004C9E40.field_0;
    }
    if (w <= limit) {
        return text;
    }
    float ell = 20.0f * GetStringWidth__9CGt2dFontCFPCUs(D_00665ED0.field_0, D_004C9F00);
    int n = Length__10CGtUnicodeFPCUs(buf);
    w = 20.0f * GetStringWidth__9CGt2dFontCFPCUs(D_00665ED0.field_0, buf);
    while (n > 0 && w + ell > limit) {
        n--;
        buf[n] = 0;
        w = 20.0f * GetStringWidth__9CGt2dFontCFPCUs(D_00665ED0.field_0, buf);
    }
    Append__10CGtUnicodeFPUsPCUs(buf, D_004C9F00);
    return buf;
}
