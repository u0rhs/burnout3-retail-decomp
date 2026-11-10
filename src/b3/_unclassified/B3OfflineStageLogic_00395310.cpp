// CB3OfflineStageLogic::UpdateCameras() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3OfflineStageLogic.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a115: float z=0.0f local gives c.eq.s result,zero operand order; byte pun D_004EE040+0x8021 is D_004F6061).

#include "b3/classes/UnkStruct_D_0064D3A0.h"
struct UnkStruct_UC_row {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14(int, int);
};
struct UnkStruct_UC_g1 { unsigned char pad_0[0x28E00]; UnkStruct_UC_row field_28E00[1]; };
struct UnkStruct_UC_g2 { unsigned char pad_0[0x10]; };
struct UnkStruct_UC_g3 { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_UC_g4 { unsigned char pad_0[0x60000 - 0x5774]; unsigned char field_Z; };
struct UnkStruct_UC_cam { unsigned char pad_0[0xC]; unsigned char field_C; unsigned char pad_D[3]; };
struct UnkStruct_UC_self {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual void vfunc_20();
    virtual void vfunc_24();
    virtual void vfunc_28();
    virtual void vfunc_2C();
    virtual void vfunc_30();
    virtual void vfunc_34();
    virtual void vfunc_38();
    virtual void vfunc_3C();
    virtual void vfunc_40();
    virtual void vfunc_44();
    virtual void vfunc_48();
    virtual void vfunc_4C();
    virtual void vfunc_50();
    virtual void vfunc_54();
    virtual void vfunc_58();
    virtual void vfunc_5C();
    virtual void vfunc_60();
    virtual void vfunc_64();
    virtual void vfunc_68();
    virtual void vfunc_6C();
    virtual void vfunc_70();
    virtual void vfunc_74();
    virtual void vfunc_78();
    virtual void vfunc_7C();
    virtual void vfunc_80();
    virtual void vfunc_84();
    virtual void vfunc_88();
    virtual void vfunc_8C();
    virtual void vfunc_90();
    virtual void vfunc_94();
    virtual void vfunc_98();
    virtual void vfunc_9C();
    virtual void vfunc_A0();
    virtual void vfunc_A4();
    virtual void vfunc_A8();
    virtual void vfunc_AC();
    virtual void vfunc_B0();
    virtual void vfunc_B4();
    virtual void vfunc_B8();
    virtual void vfunc_BC();
    virtual void vfunc_C0();
    virtual void vfunc_C4();
    virtual void vfunc_C8();
    virtual void vfunc_CC();
    virtual void vfunc_D0();
    virtual void vfunc_D4();
    virtual void vfunc_D8();
    virtual void vfunc_DC();
    virtual void vfunc_E0();
    virtual void vfunc_E4();
    virtual void vfunc_E8();
    virtual void vfunc_EC();
    virtual void vfunc_F0();
    virtual void vfunc_F4();
    virtual void vfunc_F8();
    virtual void vfunc_FC();
    virtual void vfunc_100();
    virtual void vfunc_104();
    virtual void vfunc_108();
    virtual void vfunc_10C();
    virtual bool vfunc_110();
};
struct UnkStruct_UC_selfb { unsigned char pad_0[0x20]; UnkStruct_UC_cam field_20[1]; };
extern UnkStruct_UC_g1 D_004EE040;
extern UnkStruct_UC_g2 D_004F50C0;
extern UnkStruct_UC_g3 D_00665E53;
extern UnkStruct_D_0064D3A0 D_0064D3A0;
extern unsigned char D_00522660[];
extern "C" float func_0012F330(void *);

extern "C" void UpdateCameras__20CB3OfflineStageLogicFv(UnkStruct_UC_self * self)
{
    if (self->vfunc_110()) {
        for (int i = 0; i < D_0064D3A0.field_0; i++) {
            signed char m = *((signed char *)&D_004EE040 + (signed char)i + 0x8021);
            void * ctrl = (char *)&D_004F50C0 + m * 300 + 0xD48;
            if (D_00665E53.field_0 == 0) {
                if ((D_00522660[i * 0x4590 + 0x60000 - 0x5774] & 0x10) != 0) {
                    if (((UnkStruct_UC_selfb *)self)->field_20[i].field_C == 0) {
                        ((UnkStruct_UC_row *)((char *)&D_004EE040 + i * 0xBB0 + 0x28E00))->vfunc_14(8, 0);
                    }
                } else {
                    float z = 0.0f;
                    float r = func_0012F330(ctrl);
                    if (r != z) {
                        ((UnkStruct_UC_row *)((char *)&D_004EE040 + i * 0xBB0 + 0x28E00))->vfunc_14(7, 0);
                    }
                }
            }
        }
    }
}
