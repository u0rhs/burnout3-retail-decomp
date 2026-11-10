// Hand-written; the lifter refused it (a125: vfunc_C via casts (no devirtualisation); (int)ceil(...) calls the runtime's dptoli, named by the E map (N174); maOffsetTable char[] extern +K).

#include "b3/GtMath.h"
struct UnkStruct_D_vt { virtual void vfunc_8(); virtual void vfunc_C(); unsigned char pad_4[0xC]; };
struct UnkStruct_D_byte { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_frame { unsigned char pad_0[0x38]; int field_38; };
struct UnkStruct_D_ptr { UnkStruct_frame * field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_float { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_v { float field_0; float field_4; };
class CB3OnScreenKeyboardComponent {public: void Show(bool, bool); unsigned char pad_0[0x10]; };
struct UnkStruct_00316640 {
    unsigned char pad_0[0xFC];
    float field_FC;
    unsigned char pad_100[0x1278];
    int field_1378;
    unsigned char pad_137C[0x30];
    signed char field_13AC;
};
extern UnkStruct_D_vt D_01E89544;
extern UnkStruct_D_byte D_01E8954E;
extern UnkStruct_D_vt D_01E8D450;
extern UnkStruct_D_byte D_01E8D45A;
extern UnkStruct_D_ptr D_01E8D45C;
extern UnkStruct_D_vt D_01E8EAF8;
extern UnkStruct_D_byte D_01E8EB02;
extern UnkStruct_D_vt D_01E8D490;
extern UnkStruct_D_byte D_01E8D49A;
extern UnkStruct_D_vt D_01E898E8;
extern UnkStruct_D_byte D_01E898F2;
extern CB3OnScreenKeyboardComponent D_01E899C0;
extern UnkStruct_D_float D_01E33A8C;
extern char D_004C5008[];
extern char maOffsetTable__14CB3MenuFlowFSM[];
extern "C" float func_0041E8E0(void *);
extern "C" double ceil(double);
extern "C" int snprintf(char *, unsigned int, const char *, ...);
extern "C" void ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(char *, int, int);
extern "C" void PrepareSplitBackground__17CB3TableComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPC20CGt2dObjectTableDatab(void *, const void *, const void *, const void *, const void *, bool);
extern "C" void GetImageAndTextSize__17CB3TableComponentFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv(void *, void *, void *);
extern "C" void RecalculateSize__17CB3TableComponentFv(void *);
extern "C" void Prepare__21CB3ScrollBarComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfPC29CB3MenuComponentSelectionData(void *, const void *, const void *, void *, float);
// 0x00316640
extern "C" void func_00316640(UnkStruct_00316640 * self)
{
    UnkStruct_v size;
    char buf[4];
    self->field_13AC = 1;
    if (D_01E8954E.field_0 != 0) {
        ((UnkStruct_D_vt *)&D_01E89544)->vfunc_C();
    }
    if (D_01E8D45A.field_0 != 0) {
        ((UnkStruct_D_vt *)&D_01E8D450)->vfunc_C();
    }
    if (D_01E8EB02.field_0 != 0) {
        ((UnkStruct_D_vt *)&D_01E8EAF8)->vfunc_C();
    }
    if (D_01E8D49A.field_0 != 0) {
        ((UnkStruct_D_vt *)&D_01E8D490)->vfunc_C();
    }
    if (D_01E898F2.field_0 != 0) {
        ((UnkStruct_D_vt *)&D_01E898E8)->vfunc_C();
    }
    D_01E899C0.Show(0, 1);
    PrepareSplitBackground__17CB3TableComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPC20CGt2dObjectTableDatab(&D_01E8D450, maOffsetTable__14CB3MenuFlowFSM + 0x418, maOffsetTable__14CB3MenuFlowFSM + 0x420, maOffsetTable__14CB3MenuFlowFSM + 0x428, (char *)self + 0x60, 1);
    snprintf(buf, 3, D_004C5008, (int)ceil(func_0041E8E0(&D_01E33A8C)));
    ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(buf, self->field_1378, 3);
    GetImageAndTextSize__17CB3TableComponentFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv(&size, (void *)(D_01E8D45C.field_0->field_38), (char *)self + 0xE90);
    self->field_FC = GtMath::Max(size.field_0, 21.0f);
    RecalculateSize__17CB3TableComponentFv(&D_01E8D450);
    Prepare__21CB3ScrollBarComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfPC29CB3MenuComponentSelectionData(&D_01E8EAF8, maOffsetTable__14CB3MenuFlowFSM + 0x430, maOffsetTable__14CB3MenuFlowFSM + 0x438, (char *)self + 0x1280, *(float *)(maOffsetTable__14CB3MenuFlowFSM + 0x440));
}
