// Hand-written; the lifter refused it (hand-written CB3OnlineGameCreateOptionsPage::OnKeyboardDone [L]; first try).

// func_003986C0 -- hand-written from the retail structure (lifter refused).
// [L] DNAT: CB3OnlineGameCreateOptionsPage::OnKeyboardDone() (research/proto/new_names.csv, medium)
#include "b3/classes/CB3OnScreenKeyboardComponent.h"

struct UnkStruct_003986C0 {
    unsigned char pad_0[0x40];
    unsigned short field_40;
    unsigned char pad_42[0x56];
    unsigned short * field_98;
    unsigned short * field_9C;
    unsigned char pad_A0[0xC];
    char field_AC[0x20];
    char field_CC[0x11];
    unsigned char pad_DD[0x3];
    int field_E0;
};
struct UnkStruct_D_01E898E8 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E8961C { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E8CA94 {
    unsigned short * field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern CB3OnScreenKeyboardComponent D_01E899C0;
extern UnkStruct_D_01E898E8 D_01E898E8;
extern UnkStruct_D_01E8961C D_01E8961C;
extern UnkStruct_D_01E8CA94 D_01E8CA94;

extern "C" int Length__10CGtUnicodeFPCUs(unsigned short *);
extern "C" void ConvertUTF16toUTF8Fast__10CGtUnicodeFPCUsPUci(unsigned short *, void *, int);
extern "C" void CopyN__10CGtUnicodeFPUsiPCUs(unsigned short *, int, unsigned short *);
extern "C" char * strncpy(char *, const char *, unsigned int);
extern "C" void func_0032D080(void *, int, int, int, int);
extern "C" void SetOptionText__26CB3VOptionsSelectComponentFiUi(void *, unsigned short, int);

// 0x003986C0
extern "C" void func_003986C0(UnkStruct_003986C0 * self)
{
    char buf30[0x20];
    D_01E899C0.UnRegisterKeyboardCallbacks();
    D_01E899C0.Show(false, false);
    int len = Length__10CGtUnicodeFPCUs(D_01E8CA94.field_0);
    if (self->field_40 == 0) {
        ConvertUTF16toUTF8Fast__10CGtUnicodeFPCUsPUci(D_01E8CA94.field_0, buf30, 0x20);
        if (len == 0) {
            self->field_E0 = 0;
        } else {
            CopyN__10CGtUnicodeFPUsiPCUs(self->field_98, 0x20, D_01E8CA94.field_0);
            strncpy(self->field_AC, buf30, 0x20);
            self->field_E0 = 0;
        }
    } else if (self->field_40 == 1) {
        ConvertUTF16toUTF8Fast__10CGtUnicodeFPCUsPUci(D_01E8CA94.field_0, buf30, 0x11);
        if ((len < 4 || len > 17) && len != 0) {
            func_0032D080(&D_01E898E8, 2, 0x3DA, 0, 0);
            self->field_E0 = 5;
        } else if (len == 0) {
            self->field_CC[0] = 0;
            *self->field_9C = 0;
            self->field_E0 = 0;
        } else {
            CopyN__10CGtUnicodeFPUsiPCUs(self->field_9C, 0x11, D_01E8CA94.field_0);
            strncpy(self->field_CC, buf30, 0x11);
            self->field_E0 = 0;
        }
    }
    SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, self->field_40, 0);
}
