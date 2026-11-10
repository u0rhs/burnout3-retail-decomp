// Hand-written; the lifter refused it (a156: online page Update; nested-if block form (plain exits = skipped ifs to function end, breaks = b done), bool r assigned per path with shared 'no' label, D_0012C494 = const 0x12C494 (lui 0x13 / lo 0xC494 bytes equal retail)).

// Hand-written (a156): online-menu page Update (state field_176: 0 wait, 1 play queue, 2 lead-out), sibling of func_004231B0 / func_004239F0.
#include "b3/classes/UnkStruct_D_01E89788.h"
#include "b3/classes/UnkStruct_D_00516E40.h"
#include "b3/classes/UnkStruct_D_005179F0.h"

enum EB3MenuFlowFSMEvents {};
struct UnkStruct_SB { signed char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_UB { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_WI { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_Pad16 { unsigned char pad_0[0x10]; };
struct UnkStruct_Row { unsigned char pad_0[0x12C]; };
struct UnkStruct_Blk { unsigned char pad_0[0x44]; short field_44; };
struct UnkStruct_D_01E8EED8 {
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];
};
struct UnkStruct_00423F30 {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    int field_4[29];
    int field_78[29];
    int field_EC[29];
    int field_160;
    int field_164;
    unsigned char pad_168[0xC];
    unsigned char field_174;
    unsigned char field_175;
    unsigned char field_176;
    unsigned char field_177;
    unsigned char field_178;
};
extern UnkStruct_Row D_004F50C0[];
extern UnkStruct_SB D_004F6061;
extern UnkStruct_D_01E8EED8 D_01E8EED8;
extern UnkStruct_D_01E89788 D_01E89788;
extern UnkStruct_WI D_0064EB08;
extern UnkStruct_WI D_006512D8;
extern UnkStruct_WI D_01D9D208;
extern UnkStruct_Pad16 D_01D9D200;
extern UnkStruct_UB D_01E65499;
extern UnkStruct_UB D_0064D33B;
extern UnkStruct_Pad16 D_00522660;
extern UnkStruct_Pad16 D_01E90240;
extern UnkStruct_D_00516E40 D_00516E40;
extern UnkStruct_D_005179F0 D_005179F0;
extern "C" void func_0043CCD0(void *);
extern "C" void func_0043CC00(void *);
extern "C" void func_0043CCE0(void *, int, int, int);
extern "C" int func_0043DC30(void *);
extern "C" bool func_0043CBD0(void *);
extern "C" void func_0031BD60(void *, int, bool);
extern "C" int func_00255C50(void *);
extern "C" void func_00255EA0(void *);
extern "C" int func_002E70E0();
extern "C" void func_004239F0(UnkStruct_00423F30 *);
extern "C" void StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(void *, EB3MenuFlowFSMEvents, int);

// 0x00423F30
extern "C" void func_00423F30(UnkStruct_00423F30 * self)
{
    UnkStruct_Blk * s0 = (UnkStruct_Blk *)((char *)&D_004F50C0[D_004F6061.field_0] + 0xD48);
    int a0;
    bool r;
    if (self->field_176 == 1 && s0->field_44 != 0) {
        int n = self->field_174 - 2;
        if (self->field_175 < n) {
            self->field_175 = n;
            func_0043CCD0(&D_01E8EED8);
            func_0043CC00(&D_01E8EED8);
            int v0 = D_0064EB08.field_0;
            self->field_160 = 0;
            func_0031BD60(&D_01E89788, v0, 0);
            if (self->field_178 != 0) {
                int v1 = D_006512D8.field_0;
                self->field_164 = 0;
                func_0031BD60(&D_01E89788, v1, 1);
            }
        }
    }
    switch (self->field_176) {
    case 0:
        if (s0->field_44 != 0) {
            self->field_177 = 1;
        }
        if (self->field_177 == 0) {
            if (func_002E70E0() == 0) {
                self->vfunc_10();
                break;
            }
        }
        if (D_01D9D208.field_0 == 0) {
            func_00255EA0(&D_01D9D200);
            break;
        }
        if (func_00255C50(&D_01D9D200) != 0) {
            if (D_01E65499.field_0 == 0) {
                int s = 1;
                self->field_176 = 1;
                self->field_177 = 0;
                if (D_0064D33B.field_0 != 0) {
                    a0 = s;
                    s = 0;
                } else {
                    a0 = 0;
                }
                int w0 = *(int *)((char *)&D_00522660 + a0 * 0x27D0 + 0x12C494);
                self->field_160 = 0;
                func_0031BD60(&D_01E89788, w0, 0);
                if (self->field_178 != 0) {
                    int w1 = *(int *)((char *)&D_00522660 + s * 0x27D0 + 0x12C494);
                    self->field_164 = 0;
                    func_0031BD60(&D_01E89788, w1, 1);
                }
                func_0043DC30(&D_01E8EED8);
                func_004239F0(self);
                ((UnkStruct_D_00516E40 *)&D_00516E40)->vfunc_14(0x19, 0);
                ((UnkStruct_D_005179F0 *)&D_005179F0)->vfunc_14(0x19, 0);
            } else {
                self->field_176 = 2;
            }
        }
        break;
    case 1: {
        bool r;
        if (self->field_174 == 0) {
            r = true;
        } else if (func_0043CBD0(&D_01E8EED8)) {
            if (self->field_175 < self->field_174) {
                func_0043CCE0(&D_01E8EED8, self->field_4[self->field_175], self->field_78[self->field_175], self->field_EC[self->field_175]);
                self->field_175 = self->field_175 + 1;
                goto no;
            } else {
                func_0043CCD0(&D_01E8EED8);
                ((UnkStruct_D_01E8EED8 *)&D_01E8EED8)->vfunc_C();
                r = true;
            }
        } else {
        no:
            r = false;
        }
        if (r) {
            self->field_176 = 2;
        }
        break;
    }
    case 2:
        if (self->field_177 == 0) {
            StartLeadOut__18CB3MenuPageManagerF20EB3MenuFlowFSMEvents(&D_01E90240, (EB3MenuFlowFSMEvents)0x40, 0);
            func_0043CCD0(&D_01E8EED8);
            self->field_177 = 1;
        }
        break;
    }
}
