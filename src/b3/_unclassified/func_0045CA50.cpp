// Hand-written; the lifter refused it (a67: e-mail validity inline, one-case switch, merged || false block).

// [L] DNAT: CB3CreateAccount1MenuPage::OnKeyboardCancel() (research/proto/new_names.csv, low)
#include "b3/classes/CB3OnScreenKeyboardComponent.h"
#include "b3/classes/UnkStruct_D_01E8961C.h"
#include "b3/classes/UnkStruct_D_01E899DC.h"

struct UnkStruct_0045CA50_rec {
    unsigned char pad_0[0x8C];
    char field_8C[0x32];
};
struct UnkStruct_0045CA50 {
    unsigned char pad_0[0xBC];
    UnkStruct_0045CA50_rec *field_BC;
    unsigned char pad_C0[0x1C];
    signed char field_DC;
};

extern "C" unsigned int strlen(const char *);
extern "C" char *strchr(const char *, int);
extern "C" void func_003BC360(void *, int, bool);
extern CB3OnScreenKeyboardComponent D_01E899C0;
extern UnkStruct_D_01E899DC D_01E899DC;
extern UnkStruct_D_01E8961C D_01E8961C;

// [G] inlined e-mail validity check (no name in any table)
static inline bool func_0045CA50_inl1(UnkStruct_0045CA50 *self)
{
    if (strlen(self->field_BC->field_8C) < 6) return false;
    if (strchr(self->field_BC->field_8C, '.') == 0 || strchr(self->field_BC->field_8C, '@') == 0) return false;
    UnkStruct_0045CA50_rec *r = self->field_BC;
    if (r->field_8C[strlen(r->field_8C) - 1] == '.' || self->field_BC->field_8C[strlen(r->field_8C) - 1] == '@') return false;
    return true;
}

// 0x0045CA50
extern "C" void func_0045CA50(UnkStruct_0045CA50 *self)
{
    switch (self->field_DC) {
    case 1:
        self->field_DC = 6;
        D_01E899C0.Show(false, false);
        D_01E899DC.field_0 = 0;
        func_003BC360(&D_01E8961C, 1, func_0045CA50_inl1(self));
        break;
    }
}
