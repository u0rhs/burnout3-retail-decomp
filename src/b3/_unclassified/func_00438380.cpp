// Hand-written; the lifter refused it (mwperm: 'unsigned short field_44;' -> 'short field_44;'; '((UnkStruct_D_01E898E8_v *)&D_01E898E8)->vfunc_C(); self->fi' -> '((UnkStruct_D_01E898E8_v *)&D_01E898E8)->vfunc_C(); self->field_50 = 0;'; '((UnkStruct_D_01E898E8_v *)&D_01E898E8)->vfunc_C(); if (self' -> '((UnkStruct_D_01E898E8_v *)&D_01E898E8)->vfunc_C(); if (self->field_54 == 1) { f').

enum EB3MenuFlowFSMEvents {};
class CB3InputManager {
public:
    int GetMenuConfirm(signed char);
    unsigned char pad_0[0x10];
};
struct UnkStruct_P16 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E898E8_v {
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];
};
struct UnkStruct_D_01E90424 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_00438380 {
    unsigned char pad_0[0x44];
    short field_44;
    unsigned char pad_46[6];
    int field_4C;
    int field_50;
    int field_54;
};
extern UnkStruct_D_01E90424 D_01E90424;
extern UnkStruct_P16 D_01E898E8;
extern CB3InputManager D_004F50C0;
extern UnkStruct_P16 D_01E90240;
extern UnkStruct_P16 D_01E3CD44;
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);
extern "C" void func_0032D080(void *, int, int, int, int);
extern "C" void func_003361C0(void *, void *, unsigned short);
extern "C" int func_0032B2C0(void *, int, int);
extern "C" void func_004381B0(UnkStruct_00438380 *);

// 0x00438380
extern "C" void func_00438380(UnkStruct_00438380 * self)
{
    if (D_01E90424.field_0 != 5) return;
    switch (self->field_50) {
    case 0:
        func_004381B0(self);
        break;
    case 2:
        if (D_004F50C0.GetMenuConfirm(0) == 0) return;
        if (self->field_54 == 1) {
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)37, 0);
        } else {
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)1, 0);
        }
        break;
    case 1:
        {
            int r = func_0032B2C0(&D_01E898E8, 0, 1);
            if (r == 4) goto four;
            if (r != 5) goto done;
            ((UnkStruct_D_01E898E8_v *)&D_01E898E8)->vfunc_C();
            self->field_50 = 0;
            break;
        four:
            ((UnkStruct_D_01E898E8_v *)&D_01E898E8)->vfunc_C();
            if (self->field_54 == 1) {
                func_003361C0(&D_01E3CD44, (void *)(self->field_4C), 6);
            } else {
                func_003361C0(&D_01E3CD44, (void *)(self->field_4C), self->field_44);
            }
            func_0032D080(&D_01E898E8, 2, 972, 15, 0);
            self->field_50 = 2;
        }
        break;
    }
done:
    return;
}
