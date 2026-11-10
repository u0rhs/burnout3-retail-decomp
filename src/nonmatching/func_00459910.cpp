// NONMATCHING: func_00459910 -- retail 459 / ours 384 instructions, 363 in changed runs
// fix2 (2026-11-01): taskB: 0xD8 is 464.0f (was 465); 0xC60 is a (1,1,1,1) vector, not D_01E90240; D_01E90240 copies are 16-byte quads; cell init straight-line | Before: logic transcription only (425/459 instrs, byte-offset stores, not typed): 11x4 table-cell setup + three object-array init loops (0x320/0x690 stride 0x50, 0x9E0 stride 0x40); retail builds them from inlined CGt2dObject-style ctors with local CGtV2d/V4d temps and float regs hoisted across the loop; needs typed ctors to match
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)



// func_00459910 -- placeholder (a184, hand-matched logic). Page layout/table setup (11 rows x 4 cells).
typedef unsigned long u_long128 __attribute__((mode(TI)));
struct UnkStruct_D_16 { u_long128 q; };   // taskB: a 16-byte quad (retail lq/sq), not a byte array (ours copied it bytewise)
struct UnkStruct_F16 { float f; unsigned char pad_4[0xC]; };
struct UnkStruct_I16 { int i; unsigned char pad_4[0xC]; };
struct UnkStruct_B16 { unsigned char b; unsigned char pad_1[0xF]; };
struct UnkStruct_00459910_v2 { float x; float y; };
struct UnkStruct_00459910_o {            // 0x50-byte text/obj slot [G]
    unsigned char field_0[0x10];         // lq copy of D_01E90240
    UnkStruct_00459910_v2 field_10;
    UnkStruct_00459910_v2 field_18;      // 0x330 / 0x6A0
    float field_20;
    int field_24;
    int field_28;
    int field_2C;
    unsigned char pad_30[0x20];
};
struct UnkStruct_00459910_p {            // 0x40-byte slot [G]
    unsigned char field_0[0x10];
    UnkStruct_00459910_v2 field_10;      // 0x9F0
    UnkStruct_00459910_v2 field_18;      // 0x9F8
    float field_20;
    float field_24;
    float field_28;
    float field_2C;
    int field_30;
    unsigned char pad_34[0xC];
};
struct UnkStruct_00459910_cell {
    void * field_0;
    void * field_4;
    void * field_8;
};
struct UnkStruct_00459910_col {
    float x;
    float y;
    unsigned char b;
    unsigned char pad_9[3];
};
struct UnkStruct_00459910 {
    unsigned char pad_0[0x18];
    float field_18;
    float field_1C;
    int field_20;
    int field_24;
    void * field_28;
    void * field_2C;
    void * field_30;
    int field_34;
    unsigned char pad_38[0x320 - 0x38];
    UnkStruct_00459910_o field_320[10];
};
extern UnkStruct_D_16 D_01E90240;
extern UnkStruct_I16 D_00665ED8, D_01EA4674, D_01EA46F8;
extern UnkStruct_F16 D_01EA4790, D_01EA4794, D_01EA4798, D_01EA479C, D_01EA47D0, D_01EA47D4, D_01EA47D8, D_01EA47DC;
extern UnkStruct_B16 D_01E3D4B0;
extern UnkStruct_D_16 D_01E3D4B4, D_01E3D390, D_0051BA44;
extern "C" int func_00271A00(void *, int);
extern "C" int func_0026C790(void *);
extern "C" int func_0026C8B0(void *, int);
extern "C" void IsWannaBeHisBuddy__22CGtBuddiesPS2DirtySockFPcPb(void *, void *, bool *);
extern "C" int func_0035F190(void *, void *, int *);
extern "C" void RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv();
extern "C" void GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv();
extern "C" void RenderImage__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv();
extern "C" void GetImageSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv();

// 0x00459910
extern "C" void func_00459910(UnkStruct_00459910 * self)
{
    char * b = (char *)self;
    float loc_120 = -1.0f;
    float loc_124 = -1.0f;
    int i;
    int s1;
    self->field_20 = 0xB;
    self->field_24 = 4;
    self->field_28 = b + 0x38;
    self->field_2C = b + 0xBC;
    self->field_30 = b + 0xEC;
    self->field_34 = *(int *)(b + 0xD44);
    self->field_18 = -1.0f;
    self->field_1C = -1.0f;
    *(float *)(b + 0xBC) = 7.0f;  *(float *)(b + 0xC0) = 24.0f; *(char *)(b + 0xC4) = 0;
    *(float *)(b + 0xC8) = 10.0f; *(float *)(b + 0xCC) = 21.0f; *(char *)(b + 0xD0) = 0;
    *(float *)(b + 0xD4) = 10.0f; *(float *)(b + 0xD8) = 464.0f;  /* taskB: 464 [C] retail 0x45994C lui 0x43E8 */ *(char *)(b + 0xDC) = 0;
    *(int *)(b + 0xE0) = 0; *(int *)(b + 0xE4) = 0; *(char *)(b + 0xE8) = 0;
    *(int *)(b + 0x38) = 0; *(float *)(b + 0x3C) = 24.0f; *(char *)(b + 0x40) = 0;
    // taskB: retail writes these 10 cells straight-line (0x4599E4..0x459A58), not in a loop
    *(float *)(b + 0x44) = 1.0f; *(float *)(b + 0x48) = 24.0f; *(char *)(b + 0x4C) = 0;
    *(float *)(b + 0x50) = 1.0f; *(float *)(b + 0x54) = 24.0f; *(char *)(b + 0x58) = 0;
    *(float *)(b + 0x5C) = 1.0f; *(float *)(b + 0x60) = 24.0f; *(char *)(b + 0x64) = 0;
    *(float *)(b + 0x68) = 1.0f; *(float *)(b + 0x6C) = 24.0f; *(char *)(b + 0x70) = 0;
    *(float *)(b + 0x74) = 1.0f; *(float *)(b + 0x78) = 24.0f; *(char *)(b + 0x7C) = 0;
    *(float *)(b + 0x80) = 1.0f; *(float *)(b + 0x84) = 24.0f; *(char *)(b + 0x88) = 0;
    *(float *)(b + 0x8C) = 1.0f; *(float *)(b + 0x90) = 24.0f; *(char *)(b + 0x94) = 0;
    *(float *)(b + 0x98) = 1.0f; *(float *)(b + 0x9C) = 24.0f; *(char *)(b + 0xA0) = 0;
    *(float *)(b + 0xA4) = 1.0f; *(float *)(b + 0xA8) = 24.0f; *(char *)(b + 0xAC) = 0;
    *(float *)(b + 0xB0) = 1.0f; *(float *)(b + 0xB4) = 24.0f; *(char *)(b + 0xB8) = 0;
    for (s1 = 0; s1 < 4; s1++) {
        if (s1 == 2) {
            *(UnkStruct_D_16 *)(b + 0x640) = D_01E90240;
            *(int *)(b + 0x650) = 0;
            *(int *)(b + 0x654) = 0;
            *(float *)(b + 0x660) = 24.0f;
            *(int *)(b + 0x664) = D_00665ED8.i;
            *(int *)(b + 0x66C) = 0;
            *(int *)(b + 0x668) = func_00271A00(&D_0051BA44, 0x3A9);
            *(int *)(b + 0x650) = 0;
            *(int *)(b + 0x654) = 0;
        } else if (s1 == 3) {
            *(UnkStruct_D_16 *)(b + 0x9B0) = D_01E90240;
            *(int *)(b + 0x9C0) = 0;
            *(int *)(b + 0x9C4) = 0;
            *(float *)(b + 0x9D0) = 24.0f;
            *(int *)(b + 0x9D4) = D_00665ED8.i;
            *(int *)(b + 0x9DC) = 0;
            *(int *)(b + 0x9D8) = func_00271A00(&D_0051BA44, 0xC04);
            *(float *)(b + 0x9C0) = 1.0f;
            *(int *)(b + 0x9C4) = 0;
        }
    }
    float v00 = 0.0f, v10 = 1.0f, v20 = 0.0f;
    for (i = 0; i < 10; i++) {
        UnkStruct_00459910_o * o1 = &self->field_320[i];
        char * o2 = b + 0x690 + i * 0x50;
        char * o3 = b + 0x9E0 + i * 0x40;
        *(UnkStruct_D_16 *)o1 = D_01E90240;
        *(float *)(o1->field_0 + 0x20) = 24.0f;
        *(int *)(o1->field_0 + 0x24) = D_00665ED8.i;
        *(int *)(o1->field_0 + 0x2C) = 0;
        *(int *)(o1->field_0 + 0x28) = *(int *)(b + 0xCF4 + i * 4);
        *(float *)(o1->field_0 + 0x10) = v00;
        *(float *)(o1->field_0 + 0x14) = v20;
        *(UnkStruct_D_16 *)o2 = D_01E90240;
        *(float *)(o2 + 0x20) = 24.0f;
        *(int *)(o2 + 0x24) = D_00665ED8.i;
        *(int *)(o2 + 0x2C) = 0;
        *(int *)(o2 + 0x28) = *(int *)(b + 0xD1C + i * 4);
        *(float *)(o2 + 0x10) = v10;
        *(float *)(o2 + 0x14) = v00;
        *(float *)(o3 + 0x10) = 20.0f;
        *(float *)(o3 + 0x14) = 22.0f;
        *(UnkStruct_D_16 *)o3 = D_01E90240;
        *(int *)(o3 + 0x30) = D_01EA4674.i;
        *(float *)(o3 + 0x20) = D_01EA4790.f;
        *(float *)(o3 + 0x24) = D_01EA4794.f;
        *(float *)(o3 + 0x28) = D_01EA4798.f;
        *(float *)(o3 + 0x2C) = D_01EA479C.f;
        *(float *)(o3 + 0x18) = 0.5f;
        *(float *)(o3 + 0x1C) = 0.5f;
    }
    *(float *)(b + 0xC70) = 21.0f;
    *(float *)(b + 0xC74) = 14.0f;
    // taskB: a local (1,1,1,1) vector, not D_01E90240 [C] retail 0x459C08-0x459C58 (four 0x3F800000 words, lq, sq)
    *(float *)(b + 0xC60) = 1.0f; *(float *)(b + 0xC64) = 1.0f; *(float *)(b + 0xC68) = 1.0f; *(float *)(b + 0xC6C) = 1.0f;
    *(int *)(b + 0xC90) = D_01EA46F8.i;
    *(float *)(b + 0xC80) = D_01EA47D0.f;
    *(float *)(b + 0xC84) = D_01EA47D4.f;
    *(float *)(b + 0xC88) = D_01EA47D8.f;
    *(float *)(b + 0xC8C) = D_01EA47DC.f;
    *(float *)(b + 0xC78) = 0.0f;
    *(float *)(b + 0xC7C) = 0.5f;
    int s3, s4;
    for (s4 = 0; s4 < 11; s4++) {
        char * s0 = b + s4 * 0x30;
        for (s3 = 0; s3 < 4; s3++) {
            UnkStruct_00459910_cell * c = (UnkStruct_00459910_cell *)(s0 + 0xEC + s3 * 12);
            if (s4 == 0) {
                if (s3 == 2) {
                    c->field_0 = (void *)RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
                    c->field_4 = (void *)GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
                    c->field_8 = b + 0x620;
                } else if (s3 == 0) {
                    c->field_0 = 0; c->field_4 = 0;
                } else if (s3 == 1) {
                    c->field_0 = 0; c->field_4 = 0;
                } else if (s3 == 3) {
                    c->field_0 = 0; c->field_4 = 0; c->field_8 = b + 0x990;
                }
            } else if (s3 == 0) {
                bool found = false;
                if (D_01E3D4B0.b != 0) {
                    int fp = s4 - 1;
                    if (fp < func_0026C790(&D_01E3D4B4)) {
                        IsWannaBeHisBuddy__22CGtBuddiesPS2DirtySockFPcPb(&D_01E3D390, (void *)(func_0026C8B0(&D_01E3D4B4, fp & 0xFF)), &found);
                    }
                }
                if (!found) {
                    c->field_0 = 0; c->field_4 = 0;
                } else {
                    c->field_0 = (void *)RenderImage__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
                    c->field_4 = (void *)GetImageSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
                }
                c->field_8 = b + (s4 - 1) * 0x40 + 0x9E0;
            } else if (s3 == 1) {
                int f2 = 0;
                if (D_01E3D4B0.b != 0) {
                    int fp = s4 - 1;
                    if (fp < func_0026C790(&D_01E3D4B4)) {
                        func_0035F190(&D_01E3D390, (void *)(func_0026C8B0(&D_01E3D4B4, fp & 0xFF)), &f2);
                    }
                }
                if (f2 == 0) {
                    c->field_0 = 0; c->field_4 = 0;
                } else {
                    c->field_0 = (void *)RenderImage__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
                    c->field_4 = (void *)GetImageSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
                }
                c->field_8 = b + 0xC60;
            } else if (s3 == 2) {
                c->field_0 = (void *)RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
                c->field_4 = (void *)GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
                c->field_8 = b + (s4 - 1) * 0x50 + 0x300;
            } else if (s3 == 3) {
                c->field_0 = 0; c->field_4 = 0;
                c->field_8 = b + (s4 - 1) * 0x50 + 0x670;
            }
        }
    }
}
