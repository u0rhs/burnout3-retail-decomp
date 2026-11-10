// NONMATCHING: Render__14CB3OnlineStageFv -- retail 80 / ours 75 instructions, 23 in changed runs
// gaps1c: hand-drafted from the asm
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// gaps1c (2026-11-02): hand-drafted from the retail asm (0x1354E0..0x13561C). Name [C]: the mangled symbol in retail's
// tables (research/retail_names.csv: B3OnlineStage.cpp, high). One viewport, the world in crash-mode render
// (func_002768F0), then the HUD and the 2D overlay unless D_01E90430 / D_00665E53 say otherwise; the extra
// func_00134DE0 overlay only when the stage's +0x18EA flag (D_0064D3B0) is clear and D_00665E53 is too.
// TRACK: clean
// EQUIV: [L] written from the asm: every branch and call accounted for

class CB3OnlineStage {
public:
    void Render();
};

extern unsigned char D_00665EC0[];            // [C] the CB3GraphicsManager
extern unsigned char D_00666090[];
extern unsigned char D_0064D3B0[];
extern unsigned char D_00522660[];            // [C] the CB3World
extern unsigned char D_0066A3D0[];            // [C] the CB3HUDManager
extern int D_01E90430;
extern unsigned char D_00665E53;

extern "C" void UpdateViewport__22CB3GraphicsManagerBaseF20EB3ViewportSelection(void *, int);
extern "C" void * func_0019E9E0(void *, int);
extern "C" void func_0030A9D0(void *, void *, void *);
extern "C" void func_002768F0(void *);
extern "C" void OpenViewport__18CB3GraphicsManagerF20EB3ViewportSelection(void *, int);
extern "C" void Render__13CB3HUDManagerFv(void *);
extern "C" void Begin__12Gt2dRendererFv();
extern "C" void func_00217E70(int);
extern "C" void func_00134DF0(void *);
extern "C" void func_00134DE0();
extern "C" void End__12Gt2dRendererFv();
extern "C" void CloseViewport__22CB3GraphicsManagerBaseFv(void *);

// 0x001354E0
void CB3OnlineStage::Render()
{
    UpdateViewport__22CB3GraphicsManagerBaseF20EB3ViewportSelection(D_00665EC0, 1);
    func_0030A9D0(D_00666090, func_0019E9E0(D_00665EC0, 1), D_0064D3B0);
    func_002768F0(D_00522660);
    OpenViewport__18CB3GraphicsManagerF20EB3ViewportSelection(D_00665EC0, 0);
    if (D_0064D3B0[0x18EA] != 0) {
        if (D_01E90430 == 0 && D_00665E53 == 0) {
            Render__13CB3HUDManagerFv(D_0066A3D0);
        }
    } else if (D_01E90430 == 0) {
        if (D_00665E53 != 0) {
            Begin__12Gt2dRendererFv();
            func_00217E70(0);
            func_00134DF0(D_0064D3B0);
            End__12Gt2dRendererFv();
        } else {
            Render__13CB3HUDManagerFv(D_0066A3D0);
            Begin__12Gt2dRendererFv();
            func_00217E70(0);
            func_00134DF0(D_0064D3B0);
            func_00134DE0();
            End__12Gt2dRendererFv();
        }
    }
    CloseViewport__22CB3GraphicsManagerBaseFv(D_00665EC0);
}
