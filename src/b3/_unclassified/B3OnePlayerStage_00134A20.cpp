// CB3OnePlayerStage::Render() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnePlayerStage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a137: if/else swap for frame slot order, col declared last).

// Hand-written (a137): lifter refused. [G] static inline text row (func_00134A20_inl1); C-path (else) written first so its inline gets the high frame slots; col declared after the buffers; car = const ptr in s0; vtable listing starts at vfunc_8.
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dFont.h"
using namespace GtMathPs2;
struct UnkStruct_D_00665ED0 { CGt2dFont *pFont; unsigned char pad[0x100]; };
extern UnkStruct_D_00665ED0 D_00665ED0;
struct UnkStruct_D_00665EC0 { int field_0; int field_4; unsigned char pad[0x100]; };
extern UnkStruct_D_00665EC0 D_00665EC0;
struct UnkStruct_D_00522680 { float v; unsigned char pad[12]; };
extern UnkStruct_D_00522680 D_00522680;
struct UnkStruct_D_00665E53 { unsigned char v; unsigned char pad[15]; };
extern UnkStruct_D_00665E53 D_00665E53;
struct UnkStruct_D_004EB1E2 { unsigned char v; unsigned char pad[15]; };
extern UnkStruct_D_004EB1E2 D_004EB1E2;
struct UnkStruct_D_01E90430 { int v; unsigned char pad[12]; };
extern UnkStruct_D_01E90430 D_01E90430;
struct UnkStruct_D_0064D3B0 { unsigned char pad_0[0x18EA]; unsigned char field_18EA; };
extern UnkStruct_D_0064D3B0 D_0064D3B0;
struct UnkStruct_D_00666090 { unsigned char pad[0x10]; };
extern UnkStruct_D_00666090 D_00666090;
struct UnkStruct_D_00522660 { unsigned char pad[0x10]; };
extern UnkStruct_D_00522660 D_00522660;
struct UnkStruct_D_0066A3D0 { unsigned char pad[0x10]; };
extern UnkStruct_D_0066A3D0 D_0066A3D0;
extern char D_004B5D80[];
struct UnkStruct_OPS_ui { virtual void vfunc_8(); virtual void vfunc_C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24(); virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34(); virtual void vfunc_38(); virtual void vfunc_3C(); virtual void vfunc_40(); virtual void vfunc_44(); virtual void vfunc_48(); virtual void vfunc_4C(); virtual void vfunc_50(); virtual void vfunc_54(); virtual void vfunc_58(); virtual void vfunc_5C(); virtual void vfunc_60(); virtual void vfunc_64(); virtual void vfunc_68(); virtual void vfunc_6C(); virtual void vfunc_70(); virtual void vfunc_74(); virtual void vfunc_78(); virtual void vfunc_7C(); virtual void vfunc_80(); virtual void vfunc_84(); virtual void vfunc_88(); virtual void vfunc_8C(); virtual void vfunc_90(); virtual void vfunc_94(); virtual void vfunc_98(); virtual void vfunc_9C(); virtual void vfunc_A0(); virtual void vfunc_A4(); virtual void vfunc_A8(); virtual void vfunc_AC(); virtual void vfunc_B0(); virtual void vfunc_B4(); virtual void vfunc_B8(); virtual void vfunc_BC(); virtual void vfunc_C0(); virtual void vfunc_C4(); virtual void vfunc_C8(); virtual void vfunc_CC(); virtual void vfunc_D0(); virtual void vfunc_D4(); virtual void vfunc_D8(); virtual void vfunc_DC(); virtual void vfunc_E0(); virtual void vfunc_E4(); virtual int vfunc_E8(int); };
struct UnkStruct_OPS { unsigned char pad_0[0x1B4]; UnkStruct_OPS_ui *field_1B4; };
extern "C" void UpdateViewport__22CB3GraphicsManagerBaseF20EB3ViewportSelection(void *, int);
extern "C" void OpenViewport__18CB3GraphicsManagerF20EB3ViewportSelection(void *, int);
extern "C" void CloseViewport__22CB3GraphicsManagerBaseFv(void *);
extern "C" int func_0019E9E0(void *, int);
extern "C" void func_0030A9D0(void *, int, void *);
extern "C" void func_002768F0(void *);
extern "C" void Render__13CB3HUDManagerFv(void *);
extern "C" void Begin__12Gt2dRendererFv();
extern "C" void End__12Gt2dRendererFv();
extern "C" void func_00217E70(int);
extern "C" void func_00134DF0(void *);
extern "C" void ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(const char *, unsigned short *, int);
extern "C" int sprintf(char *, const char *, ...);
static inline void a137_inl()
{
    char sbuf[0x100];
    unsigned short wbuf[256];
    CGtV4d col;
    col = CGtV4d(1.0f, 1.0f, 1.0f, 1.0f);
    float sx = (float)D_00665EC0.field_0 / 640.0f;
    float sy = (float)D_00665EC0.field_4 / 480.0f;
    float sz = 30.0f * sy;
    sprintf(sbuf, D_004B5D80, (double)D_00522680.v);
    ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(sbuf, wbuf, 0x100);
    float w = D_00665ED0.pFont->GetStringWidth(wbuf);
    D_00665ED0.pFont->RenderString(wbuf, 320.0f * sx - sz * w / 2.0f, 50.0f * sy, sz, col);
}
extern "C" void Render__17CB3OnePlayerStageFv(UnkStruct_OPS *self)
{
    UnkStruct_D_0064D3B0 * const car = &D_0064D3B0;
    UpdateViewport__22CB3GraphicsManagerBaseF20EB3ViewportSelection(&D_00665EC0, 1);
    func_0030A9D0(&D_00666090, func_0019E9E0(&D_00665EC0, 1), car);
    func_002768F0(&D_00522660);
    bool flag = false;
    if (self->field_1B4 != 0) {
        if (self->field_1B4->vfunc_E8(0)) flag = true;
    }
    OpenViewport__18CB3GraphicsManagerF20EB3ViewportSelection(&D_00665EC0, 0);
    if (car->field_18EA != 0 || flag) {
        if (D_01E90430.v == 0 && D_00665E53.v == 0) {
            Begin__12Gt2dRendererFv();
            func_00217E70(0);
            if (D_004EB1E2.v != 0) a137_inl();
            End__12Gt2dRendererFv();
            Render__13CB3HUDManagerFv(&D_0066A3D0);
        }
    } else {
        if (D_01E90430.v == 0) {
            if (D_00665E53.v == 0) {
                Render__13CB3HUDManagerFv(&D_0066A3D0);
                Begin__12Gt2dRendererFv();
                func_00217E70(0);
                func_00134DF0(car);
                if (D_004EB1E2.v != 0) a137_inl();
                End__12Gt2dRendererFv();
            } else {
                Begin__12Gt2dRendererFv();
                func_00217E70(0);
                func_00134DF0(car);
                End__12Gt2dRendererFv();
            }
        }
    }
    CloseViewport__22CB3GraphicsManagerBaseFv(&D_00665EC0);
}
