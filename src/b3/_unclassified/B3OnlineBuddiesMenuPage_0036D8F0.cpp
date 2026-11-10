// CB3OnlineBuddiesMenuPage::UpdateRemove() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineBuddiesMenuPage.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a222: case1/2 f11D!=0 {main} else {0x25 arm} last; case0 tail 'return;' instead of goto out).

// Hand-written (a169): CB3OnlineBuddiesMenuPage::UpdateRemove -- lifter refused; written from cfgmap + asm.
struct UnkStruct_Pad16 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_vt {
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];
};
struct UnkStruct_D_Byte16 { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_Int16 { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_vt D_01E898E8, D_01E8970C;
extern UnkStruct_D_Byte16 D_01E8D67A, D_01E89716, D_01E8EB02;
extern UnkStruct_D_Int16 D_01E3D460;
extern UnkStruct_Pad16 D_01E7A800, D_01E3D390, D_01E8D670, D_01E89800, D_01E8EAF8, D_004C8158, D_004C8160;
extern "C" int func_0032B2C0(void *, int, int);
extern "C" void func_0032D080(void *, int, int, int, int);
extern "C" void FESelect__18CB3HUDSoundManagerFv(void *);
extern "C" void FEBack__18CB3HUDSoundManagerFv(void *);
extern "C" void Prepare__24CB3BuddyDisplayComponentFv(void *, int, int);
extern "C" void SetFocus__24CB3BuddyDisplayComponentFb(void *, bool);
extern "C" void SetCurrentPrompts__19CB3PromptsComponentFUiUi(void *, unsigned long, unsigned int);
extern "C" void Prepare__21CB3ScrollBarComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfPC29CB3MenuComponentSelectionData(void *, void *, void *, void *, float);
extern "C" void IsBuddyIgnored__22CGtBuddiesPS2DirtySockFPcPb(void *, char *, bool *);
extern "C" void IsTemporaryBuddy__22CGtBuddiesPS2DirtySockFPcPb(void *, char *, bool *);
extern "C" void IsPermanentBuddy__22CGtBuddiesPS2DirtySockFPcPb(void *, char *, bool *);
extern "C" int RemoveBuddy__22CGtBuddiesPS2DirtySockFPcPFbPv_vPv(void *, char *, void *, void *);
extern "C" int RemoveTempBuddy__22CGtBuddiesPS2DirtySockFPcPFbPv_vPv(void *, char *, void *, void *);
extern "C" int RemoveIgnoredBuddy__22CGtBuddiesPS2DirtySockFPcPFbPv_vPv(void *, char *, void *, void *);
extern "C" void _RemoveBuddyCallback__24CB3OnlineBuddiesMenuPageFbPv(bool, void *);
struct UnkStruct_a169 {
    unsigned char pad_0[0x5C];
    unsigned char field_5C[0x70];
    int field_CC;
    int field_D0;
    unsigned char pad_D4[0x34];
    char field_108[0x14];
    unsigned char pad_11C[1];
    unsigned char field_11D;
    unsigned char pad_11E[1];
    unsigned char field_11F;
    unsigned char pad_120[4];
    int field_124;
    int field_128;
};
static inline void a169_pageOpen(UnkStruct_a169 *self)
{
    ((UnkStruct_D_vt *)&D_01E898E8)->vfunc_C();
    self->field_CC = 2;
    if (D_01E8D67A.field_0 == 0) {
        Prepare__24CB3BuddyDisplayComponentFv(&D_01E8D670, self->field_124, self->field_128);
    }
    SetFocus__24CB3BuddyDisplayComponentFb(&D_01E8D670, true);
    if (D_01E89716.field_0 != 0) {
        ((UnkStruct_D_vt *)&D_01E8970C)->vfunc_C();
    }
    if (D_01E8EB02.field_0 == 0) {
        Prepare__21CB3ScrollBarComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dfPC29CB3MenuComponentSelectionData(&D_01E8EAF8, &D_004C8158, &D_004C8160, self->field_5C, 272.0f);
    }
    unsigned long v = 0x105 | ((unsigned long)4 << 32);
    if (D_01E3D460.field_0 == 6) {
        v |= (unsigned long)2 << 32;
    } else {
        v |= (unsigned long)1 << 32;
    }
    SetCurrentPrompts__19CB3PromptsComponentFUiUi(&D_01E89800, v, 3);
}
extern "C" void UpdateRemove__24CB3OnlineBuddiesMenuPageFv(UnkStruct_a169 *self)
{
    bool ign, temp, perm;
    int ok;
    int r = func_0032B2C0(&D_01E898E8, 0, 1);
    switch (self->field_D0) {
    case 0:
        if (r == 4) {
            FESelect__18CB3HUDSoundManagerFv(&D_01E7A800);
            self->field_11D = 0;
            self->field_11F = 0;
            IsBuddyIgnored__22CGtBuddiesPS2DirtySockFPcPb(&D_01E3D390, self->field_108, &ign);
            IsTemporaryBuddy__22CGtBuddiesPS2DirtySockFPcPb(&D_01E3D390, self->field_108, &temp);
            IsPermanentBuddy__22CGtBuddiesPS2DirtySockFPcPb(&D_01E3D390, self->field_108, &perm);
            if (ign) {
                self->field_D0 = 1;
                ok = RemoveIgnoredBuddy__22CGtBuddiesPS2DirtySockFPcPFbPv_vPv(&D_01E3D390, self->field_108, (void *)&_RemoveBuddyCallback__24CB3OnlineBuddiesMenuPageFbPv, self);
            } else if (temp) {
                self->field_D0 = 2;
                ok = RemoveTempBuddy__22CGtBuddiesPS2DirtySockFPcPFbPv_vPv(&D_01E3D390, self->field_108, (void *)&_RemoveBuddyCallback__24CB3OnlineBuddiesMenuPageFbPv, self);
            } else if (perm) {
                self->field_D0 = 3;
                ok = RemoveBuddy__22CGtBuddiesPS2DirtySockFPcPFbPv_vPv(&D_01E3D390, self->field_108, (void *)&_RemoveBuddyCallback__24CB3OnlineBuddiesMenuPageFbPv, self);
            }
            if (ok) {
                self->field_D0 = 4;
                ((UnkStruct_D_vt *)&D_01E898E8)->vfunc_C();
                func_0032D080(&D_01E898E8, 2, 0x25, 0, 0);
            } else {
                ((UnkStruct_D_vt *)&D_01E898E8)->vfunc_C();
                func_0032D080(&D_01E898E8, 0, 0x23, 0xF, 0);
            }
            return;
        }
        if (r != 5) goto out;
        FEBack__18CB3HUDSoundManagerFv(&D_01E7A800);
        a169_pageOpen(self);
        break;
    case 1:
        if (self->field_11F == 0) goto out;
        if (self->field_11D != 0) {
        self->field_11F = 0;
        IsTemporaryBuddy__22CGtBuddiesPS2DirtySockFPcPb(&D_01E3D390, self->field_108, &temp);
        IsPermanentBuddy__22CGtBuddiesPS2DirtySockFPcPb(&D_01E3D390, self->field_108, &perm);
        if (temp) {
            self->field_D0 = 2;
            ok = RemoveTempBuddy__22CGtBuddiesPS2DirtySockFPcPFbPv_vPv(&D_01E3D390, self->field_108, (void *)&_RemoveBuddyCallback__24CB3OnlineBuddiesMenuPageFbPv, self);
        } else if (!perm) {
            self->field_D0 = 4;
            ((UnkStruct_D_vt *)&D_01E898E8)->vfunc_C();
            func_0032D080(&D_01E898E8, 2, 0x24, 0, 0);
            break;
        } else {
            self->field_D0 = 3;
            ok = RemoveBuddy__22CGtBuddiesPS2DirtySockFPcPFbPv_vPv(&D_01E3D390, self->field_108, (void *)&_RemoveBuddyCallback__24CB3OnlineBuddiesMenuPageFbPv, self);
        }
        if (ok == 0) goto out;
        self->field_D0 = 4;
        ((UnkStruct_D_vt *)&D_01E898E8)->vfunc_C();
        func_0032D080(&D_01E898E8, 2, 0x25, 0, 0);
        } else {
            self->field_D0 = 4;
            ((UnkStruct_D_vt *)&D_01E898E8)->vfunc_C();
            func_0032D080(&D_01E898E8, 2, 0x25, 0, 0);
        }
        break;
    case 2:
        if (self->field_11F == 0) goto out;
        if (self->field_11D != 0) {
        self->field_11F = 0;
        IsPermanentBuddy__22CGtBuddiesPS2DirtySockFPcPb(&D_01E3D390, self->field_108, &perm);
        if (!perm) {
            self->field_D0 = 4;
            ((UnkStruct_D_vt *)&D_01E898E8)->vfunc_C();
            func_0032D080(&D_01E898E8, 2, 0x24, 0, 0);
            break;
        }
        self->field_D0 = 3;
        ok = RemoveBuddy__22CGtBuddiesPS2DirtySockFPcPFbPv_vPv(&D_01E3D390, self->field_108, (void *)&_RemoveBuddyCallback__24CB3OnlineBuddiesMenuPageFbPv, self);
        if (ok == 0) goto out;
        self->field_D0 = 4;
        ((UnkStruct_D_vt *)&D_01E898E8)->vfunc_C();
        func_0032D080(&D_01E898E8, 2, 0x25, 0, 0);
        } else {
            self->field_D0 = 4;
            ((UnkStruct_D_vt *)&D_01E898E8)->vfunc_C();
            func_0032D080(&D_01E898E8, 2, 0x25, 0, 0);
        }
        break;
    case 3:
        if (self->field_11F == 0) goto out;
        self->field_D0 = 4;
        if (self->field_11D != 0) {
            ((UnkStruct_D_vt *)&D_01E898E8)->vfunc_C();
            func_0032D080(&D_01E898E8, 2, 0x24, 0, 0);
        } else {
            ((UnkStruct_D_vt *)&D_01E898E8)->vfunc_C();
            func_0032D080(&D_01E898E8, 2, 0x25, 0, 0);
        }
        break;
    case 4:
        if (r != 0) goto out;
        a169_pageOpen(self);
        FESelect__18CB3HUDSoundManagerFv(&D_01E7A800);
        break;
    }
out:
    return;
}
