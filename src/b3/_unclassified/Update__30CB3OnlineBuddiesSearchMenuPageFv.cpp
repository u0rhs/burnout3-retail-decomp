// Hand-written; the lifter refused it (state switch jtbl; case 4 source-before-3).

enum EB3MenuFlowFSMEvents {};
struct UnkStruct_D_0x10 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E898E8 { virtual void vfunc_8(); virtual void vfunc_C(); unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E90424 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_30CB3OnlineBuddiesSearchMenuPage { unsigned char pad_0[0x28]; int field_28; };
extern UnkStruct_D_01E90424 D_01E90424;
extern UnkStruct_D_01E898E8 D_01E898E8;
extern UnkStruct_D_0x10 D_01E899C0, D_01E7A800, D_01E90240, D_01E3D390;
extern char D_01EA2F5E[];
extern "C" void func_00372B20(bool, void *);
extern "C" void func_00372E00(UnkStruct_30CB3OnlineBuddiesSearchMenuPage *);
extern "C" void Update__25CB3OnlineReadMailMenuPageFv(UnkStruct_30CB3OnlineBuddiesSearchMenuPage *);
extern "C" int func_0032B2C0(void *, int, int);
extern "C" void func_0032D080(void *, int, int, int, int);
extern "C" int func_0035FBC0(void *, char *);
extern "C" int BanBuddy__22CGtBuddiesPS2DirtySockFPcPFbPv_vPv(void *, char *, void (*)(bool, void *), void *);
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);
extern "C" void Show__28CB3OnScreenKeyboardComponentFbb(void *, bool, bool);
extern "C" void FESelect__18CB3HUDSoundManagerFv(void *);
extern "C" void Update__30CB3OnlineBuddiesSearchMenuPageFv(UnkStruct_30CB3OnlineBuddiesSearchMenuPage * self)
{
    if (D_01E90424.field_0 != 5) return;
    switch (self->field_28) {
    case 0:
        func_00372E00(self);
        break;
    case 1:
        Update__25CB3OnlineReadMailMenuPageFv(self);
        break;
    case 2:
        switch (func_0032B2C0(&D_01E898E8, 0, 1)) {
        case 0:
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)1, 0);
            break;
        }
        break;
    case 4:
        switch (func_0032B2C0(&D_01E898E8, 0, 1)) {
        case 4: {
            int r = BanBuddy__22CGtBuddiesPS2DirtySockFPcPFbPv_vPv(&D_01E3D390, D_01EA2F5E, func_00372B20, self);
            ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
            if (r == 0) {
                func_0035FBC0(&D_01E3D390, D_01EA2F5E);
                func_0032D080(&D_01E898E8, 0, 0x37, 0xF, 0);
            } else {
                func_0032D080(&D_01E898E8, 2, 0x39, 0, 0);
            }
            self->field_28 = 2;
            break;
        }
        case 5:
            self->field_28 = 0;
            ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
            break;
        }
        break;
    case 3:
        switch (func_0032B2C0(&D_01E898E8, 0, 1)) {
        case 0:
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)1, 0);
            break;
        case 1:
            self->field_28 = 0;
            ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
            break;
        }
        break;
    case 5:
        if (func_0032B2C0(&D_01E898E8, 0, 1) != 0) break;
        self->field_28 = 0;
        Show__28CB3OnScreenKeyboardComponentFbb(&D_01E899C0, false, false);
        ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
        FESelect__18CB3HUDSoundManagerFv(&D_01E7A800);
        break;
    }
}
