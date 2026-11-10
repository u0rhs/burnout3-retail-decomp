// Hand-written; the lifter refused it (a84: CB3GraphicsManager::Construct [L] DNAT; loop i=1..5 with int j=i-1 local (no offset folding), D?1:0 via movz, ==1 for xori/sltiu).

// func_00228160 -- CB3GraphicsManager::Construct() [L] DNAT (research/proto/new_names.csv, medium)
struct UnkStruct_D_004E2910 { signed char field_0; };
struct UnkStruct_00228160_dic {
    unsigned char pad_0[0x8];
    int field_8;
    unsigned char pad_C[0x4];
};
struct UnkStruct_00228160 {
    unsigned char pad_0[0xD];
    unsigned char field_D;
    unsigned char pad_E[0x3AA];
    int field_3B8;
    unsigned char pad_3BC[0x54];
    int field_410;
    int field_414;
    int field_418;
    int field_41C;
    unsigned char pad_420[0xC];
    int field_42C;
    unsigned char pad_430[0xD68];
    int field_1198;
    int field_119C;
    int field_11A0[5];
    int field_11B4[5];
    int field_11C8[5];
};
struct UnkStruct_P { unsigned char pad_0[0x10]; };
struct UnkStruct_P4 { void * field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_004E2910 D_004E2910;
extern UnkStruct_00228160_dic * D_004E1588;
extern "C" UnkStruct_00228160_dic * mgpB3LogoTexDic__22CB3GraphicsManagerBase;
extern "C" UnkStruct_00228160_dic * mgpSmallFontTexDic__22CB3GraphicsManagerBase;
extern UnkStruct_P gTextureCache, D_01D6E280, D_01D6E640, D_01D6EA00;
extern UnkStruct_P4 D_01D6EDC0, D_01D6EDC4, D_01D6EDC8;
extern "C" int func_00436570();
extern "C" void OpenRenderWare__18CB3GraphicsManagerFv(void *);
extern "C" int RpSkyTexCacheGetStartAddress();
extern "C" void RpSkyTexCacheSetStartAddress(int);
extern "C" void Destruct__15CGtTextureCacheFv(void *);
extern "C" void Construct__15CGtTextureCacheFUiii(void *, unsigned int, int, int);
extern "C" void FixUp__17CGtDictionaryBaseFv(void *);
extern "C" void * func_00131AA0(void *, int);
extern "C" void FixUp__10CGtTextureFv(void *);
extern "C" void Construct__22CB3GraphicsManagerBaseFv(void *);

// [L] DNAT: CB3GraphicsManager::Construct() (research/proto/new_names.csv, medium)
// 0x00228160
extern "C" void func_00228160(UnkStruct_00228160 * self)
{
    self->field_3B8 = D_004E2910.field_0 ? 2 : 0;
    self->field_D = func_00436570() == 1;
    self->field_42C = 0;
    for (int i = 1; i < 6; i++) { int j = i - 1;
        self->field_11A0[j] = 0;
        self->field_11B4[j] = 0;
        self->field_11C8[j] = 0;
    }
    self->field_1198 = 0;
    self->field_119C = 0;
    OpenRenderWare__18CB3GraphicsManagerFv(self);
    self->field_410 = RpSkyTexCacheGetStartAddress();
    self->field_414 = self->field_410 + 0x6000;
    self->field_418 = self->field_414 + 0x800;
    self->field_41C = self->field_418 + 0x10000;
    unsigned int addr = self->field_41C + 0x10000;
    RpSkyTexCacheSetStartAddress(addr);
    Destruct__15CGtTextureCacheFv(&gTextureCache);
    Construct__15CGtTextureCacheFUiii(&gTextureCache, addr, 30, 384);
    self->field_410 = (unsigned int)self->field_410 >> 6;
    self->field_414 = (unsigned int)self->field_414 >> 6;
    self->field_418 = (unsigned int)self->field_418 >> 6;
    self->field_41C = (unsigned int)self->field_41C >> 6;
    UnkStruct_00228160_dic * d = D_004E1588;
    FixUp__17CGtDictionaryBaseFv(d);
    for (int i = 0; i < d->field_8; i++) {
        FixUp__10CGtTextureFv(func_00131AA0(d, i));
    }
    d = mgpB3LogoTexDic__22CB3GraphicsManagerBase;
    FixUp__17CGtDictionaryBaseFv(d);
    for (int i = 0; i < d->field_8; i++) {
        FixUp__10CGtTextureFv(func_00131AA0(d, i));
    }
    d = mgpSmallFontTexDic__22CB3GraphicsManagerBase;
    if (d != 0) {
        FixUp__17CGtDictionaryBaseFv(d);
        for (int i = 0; i < d->field_8; i++) {
            FixUp__10CGtTextureFv(func_00131AA0(d, i));
        }
    }
    Construct__22CB3GraphicsManagerBaseFv(self);
    D_01D6EDC0.field_0 = &D_01D6E280;
    D_01D6EDC4.field_0 = &D_01D6E640;
    D_01D6EDC8.field_0 = &D_01D6EA00;
}
