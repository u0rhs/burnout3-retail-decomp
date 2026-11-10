// NONMATCHING: func_0044A640 -- retail 114 / ours 114 instructions, 1 in changed runs
// pass3b: c2 = b2 copy in the sel arm gives retail's two 'move a1,s7' sites but swaps b1/b2 (s7/s6) in every one of the 12 declaration orders of b1/b2/b3/c2; 2+base, b1+1, b3-1, self->field_8+2 (reload) ruled out. Retail CSEs the sel-arm base+2 into b2 without raising b2's colour priority.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// near10: 1 off (was 5). Writing the sel!=0 arm as 'a1 = base + 2;' lowers b2's colouring weight so b1=s6/b2=s7/b3=fp as retail; left: that arm then emits 'addiu a1,s1,2' where retail has 'move a1,s7'. Merged conditions (sel==0 && (j==2||j==4)) also give retail's registers but merge the two 'move a1,s7' sites (3 off). Tried c2 copy, b1+1, inline helpers, goto forms, short base, sreg run

// restored (dperm): the 5 -> 2 dperm archive was withdrawn -- it assigned b1 = 4 inside a condition (b1 is read on the next iteration), a behaviour change; this is the original form

class CGt2dObject;
class CGt2dFrame;
struct UnkStruct_D_01E903E0 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_01E903E0 D_01E903E0;
extern "C" void Release__20CB3MenuComponentBaseFv(void *);
extern "C" void DestructObject__10CGt2dSceneFiP11CGt2dObject(void *, int, void *);
extern "C" void Destruct__10CGt2dFrameFv(CGt2dFrame *);
struct UnkStruct_0044A640;
extern "C" void func_0044C960(UnkStruct_0044A640 *, int, int);
struct UnkStruct_0044A640_row {
    void *field_0;
    void *field_4;
    CGt2dFrame *field_8;
    CGt2dFrame *field_C;
    void *field_10[5];
};
struct UnkStruct_0044A640 {
    unsigned char pad_0[8];
    short field_8;
    unsigned char pad_A[0x122];
    CGt2dFrame *field_12C;
    int field_130;
    unsigned char pad_134[0xC5];
    signed char field_1F9;
    unsigned char pad_1FA;
    unsigned char field_1FB;
    unsigned char pad_1FC[8];
    unsigned char field_204;
};

// 0x0044A640
extern "C" void func_0044A640(UnkStruct_0044A640 *self)
{
    void *const scene = &D_01E903E0;
    int i;
    int j;
    int base = self->field_8;
    int b1 = base + 1;
    int b2 = base + 2;
    int b3 = base + 3;
    Release__20CB3MenuComponentBaseFv(self);
    if (self->field_204 == 0 && self->field_1FB != 0) {
        func_0044C960(self, self->field_1F9, 0);
        self->field_1FB = 0;
    }
    for (i = 0; i < 8; i++) {
        int sel = *((signed char *)self + 0x1C8 + i);
        UnkStruct_0044A640_row *r = (UnkStruct_0044A640_row *)((char *)self + i * 0x24 + 0xC);
        if (r->field_0 != 0) {
            DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, b1, r->field_0);
            r->field_0 = 0;
        }
        if (r->field_4 != 0) {
            DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, base, r->field_4);
            r->field_4 = 0;
        }
        if (r->field_C != 0) {
            Destruct__10CGt2dFrameFv(r->field_C);
            r->field_C = 0;
        }
        if (r->field_8 != 0) {
            Destruct__10CGt2dFrameFv(r->field_8);
            r->field_8 = 0;
        }
        for (j = 0; j < 5; j++) {
            void **slot = &r->field_10[j];
            if (r->field_10[j] != 0) {
                int a1;
                if (sel != 0) {
                    a1 = base + 2;
                } else if (j == 2 || j == 4) {
                    a1 = b3;
                } else {
                    a1 = b2;
                }
                DestructObject__10CGt2dSceneFiP11CGt2dObject(scene, a1, r->field_10[j]);
                *slot = 0;
            }
        }
    }
    Destruct__10CGt2dFrameFv(self->field_12C);
    self->field_12C = 0;
    self->field_130 = 0;
}
