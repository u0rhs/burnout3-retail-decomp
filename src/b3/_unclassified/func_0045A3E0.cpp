// Hand-written; the lifter refused it (sibling func_00314E50's nested shape (h38 in both guard arms, else-if chain) + goto to a trailing return for the t2 exit).

// func_0045A3E0 -- placeholder (a184 draft; s315 matched it with the proven sibling func_00314E50's nested shape:
// `int h38` read in both guard arms, confirm/back/lead-out as an else-if chain). Online page Update: ctrl input -> table action.
struct UnkStruct_D_16 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_B { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_V {
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];
};
class CB3TableComponent {
public:
    void RecalculateSize();
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];
};
struct UnkStruct_0045A3E0_ent {
    short field_0;
    short field_2;
    unsigned char field_4;
    unsigned char pad_5[3];
};
struct UnkStruct_0045A3E0 {
    unsigned char pad_0[0x4];
    char field_4;
    unsigned char pad_5[0xC9B];
    unsigned short field_CA0;
    unsigned char pad_CA2[0x6];
    UnkStruct_0045A3E0_ent field_CA8[1];
    unsigned char pad_CB0[0x28];
    unsigned int field_CD8[1];
    unsigned char pad_CDC[0x71];
    unsigned char field_D4D;
};
extern signed char D_004F6061[];
extern UnkStruct_D_16 D_004F50C0, D_01E7A800, D_01E90240, D_01E3D390, D_01E899C0, D_004D35D8, D_004D35E0, D_004D35E8;
extern UnkStruct_D_B D_01E8954E, D_01E8D45A, D_01E8D49A, D_01E898F2;
extern UnkStruct_D_V D_01E89544, D_01E8D490, D_01E898E8;
extern CB3TableComponent D_01E8D450;
extern "C" int func_00319360(void *);
extern "C" int func_00319330(void *);
extern "C" void FESelect__18CB3HUDSoundManagerFv(void *);
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, int, int);
extern "C" int BuddyInvite__22CGtBuddiesPS2DirtySockFPcPFbPv_vPv(void *, void *, void *, void *);
extern "C" void func_0032D080(void *, int, int, int, int);
extern "C" void func_004596D0(int);
extern "C" void Show__28CB3OnScreenKeyboardComponentFbb(void *, bool, bool);
extern "C" void SetAllowableCharacters__28CB3OnScreenKeyboardComponentF14EGlobalStrings(void *, int);
extern "C" void PrepareSplitBackground__17CB3TableComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPC20CGt2dObjectTableDatab(void *, const void *, const void *, const void *, const void *, bool);

static inline void func_0045A3E0_inl0(UnkStruct_0045A3E0 * self)
{
    self->field_D4D = 0;
    if (D_01E8954E.field_0 != 0) {
        ((UnkStruct_D_V *)&D_01E89544)->vfunc_C();
    }
    if (D_01E8D45A.field_0 != 0) {
        ((CB3TableComponent *)&D_01E8D450)->vfunc_C();
    }
    if (D_01E8D49A.field_0 != 0) {
        ((UnkStruct_D_V *)&D_01E8D490)->vfunc_C();
    }
    if (D_01E898F2.field_0 != 0) {
        ((UnkStruct_D_V *)&D_01E898E8)->vfunc_C();
    }
    PrepareSplitBackground__17CB3TableComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPC20CGt2dObjectTableDatab(&D_01E8D450, &D_004D35D8, &D_004D35E0, &D_004D35E8, (const void *)((char *)self + 0x18), 0);
    D_01E8D450.RecalculateSize();
}

// 0x0045A3E0
extern "C" void func_0045A3E0(UnkStruct_0045A3E0 * self)
{
    char * ctrl = (char *)&D_004F50C0 + D_004F6061[0] * 0x12C + 0xD48;
    if (self->field_4 == 0) {
        func_0045A3E0_inl0(self);
    } else {
        int h38;
        if (*(short *)(ctrl + 0x2C) != 0) {
            if (func_00319360((char *)self + 0xCA0) != 0) return;
            h38 = *(short *)(ctrl + 0x38);
        } else {
            h38 = *(short *)(ctrl + 0x38);
        }
        if (h38 != 0) {
            // [G] goto: a jump to a separate `return` block keeps retail's `bnez v0 -> ld ra` + `b back; lh` shape.
            if (func_00319330((char *)self + 0xCA0) != 0) goto out;
        }
        if (*(short *)(ctrl + 0x44) != 0 && self->field_CA8[self->field_CA0].field_4 == 0) {
            FESelect__18CB3HUDSoundManagerFv(&D_01E7A800);
            switch (self->field_CD8[self->field_CA0]) {
            case 0:
                self->field_D4D = 2;
                if (BuddyInvite__22CGtBuddiesPS2DirtySockFPcPFbPv_vPv(&D_01E3D390, &self->field_4, (void *)func_004596D0, self) == 0) {
                    func_0032D080(&D_01E898E8, 0, 0x40, 0xF, 0);
                } else {
                    func_0032D080(&D_01E898E8, 2, 0x42, 0, 0);
                }
                break;
            case 1:
                self->field_D4D = 7;
                func_0032D080(&D_01E898E8, 7, 0x32, 5, 0);
                break;
            case 2:
                self->field_D4D = 3;
                Show__28CB3OnScreenKeyboardComponentFbb(&D_01E899C0, true, true);
                SetAllowableCharacters__28CB3OnScreenKeyboardComponentF14EGlobalStrings(&D_01E899C0, 0x293);
                break;
            case 3:
                StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, 0x2C, 0);
                break;
            case 4:
                self->field_D4D = 5;
                func_0032D080(&D_01E898E8, 7, 0x36, 5, 0);
                break;
            case 5:
                StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, 0x2A, 0);
                break;
            default:
                break;
            }
        } else if (*(short *)(ctrl + 0x5C) != 0) {
            func_0045A3E0_inl0(self);
        } else if (*(short *)(ctrl + 0x8C) != 0) {
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, 0x24, 0);
        }
    }
    return;
out:
    return;
}
