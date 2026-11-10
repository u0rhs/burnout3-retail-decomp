// NONMATCHING: Update__16CB3StreamedTrackFv -- retail 297 / ours 296 instructions, 121 in changed runs
// a144: logic complete, 296/297 instrs; remaining = saved-reg assignment (retail cur=s0,self=s1,near=s2,tmp=s3; ours self=s0) and 2-3 scheduling diffs (ring-window inlines: retail near/v use direct daddiu, v in v0). Ring windows are 3 inlines (8, 8&>4, 4); GetUnit inlined x2 (0x17C/0x154 arrays) then ->field_4 deref without null check
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

class CB3StreamedTrackHighData;
class CB3StreamedTrackLODAndCollisionData;
struct UnkStruct_D_004E2D48 { int field_0; };
struct UnkStruct_D_0064CD44 { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_0064D370 { unsigned long field_0; unsigned char pad_8[0x8]; };
struct UnkStruct_D_0064CD40 { void *field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_u { unsigned char pad_0[4]; int field_4; };
struct UnkStruct_Update {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    unsigned char pad_10[8];
    unsigned char field_18;
    unsigned char field_19;
    unsigned char pad_1A[2];
    int field_1C;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
    unsigned char pad_30[0x17];
    unsigned char field_47;
    int field_48;
    int field_4C;
    unsigned char pad_50[0x104];
    UnkStruct_u *field_154[1];
    unsigned char pad_158[0x24];
    UnkStruct_u *field_17C[1];
};
extern UnkStruct_D_004E2D48 D_004E2D48;
extern UnkStruct_D_0064CD44 D_0064CD44;
extern UnkStruct_D_0064D370 D_0064D370;
extern UnkStruct_D_0064CD40 D_0064CD40;
extern unsigned char D_00522660[];
extern "C" void UpdateStreamFSM__16CB3StreamedTrackFv(void *);
extern "C" int func_00150300(void *);
extern "C" CB3StreamedTrackHighData * func_003C3250(void *);
extern "C" CB3StreamedTrackLODAndCollisionData * func_003C3150(void *);

// 0x00302160
extern "C" int Update__16CB3StreamedTrackFv(UnkStruct_Update *self)
{
    if (D_0064D370.field_0 == 0) return 1;
    UpdateStreamFSM__16CB3StreamedTrackFv(self);
    bool near = false;
    int cur = func_00150300(D_00522660 + self->field_1C * 0x27D0 + 0x12AD50);
    if (cur == -1) cur = self->field_4;
    if (cur > self->field_4) {
        if (!(cur > self->field_4 + 8)) near = true;
    } else if (self->field_4 > cur) {
        if (!(cur + self->field_C > self->field_4 + 8)) near = true;
    }
    if (near) {
        if (self->field_47 == 0) {
            if (D_004E2D48.field_0 == -1) D_004E2D48.field_0 = self->field_1C;
            if (D_004E2D48.field_0 == self->field_1C) {
                bool ok;
                if (self->field_24 == self->field_2C) {
                    int a = self->field_2C % self->field_C;
                    UnkStruct_u **p = &self->field_154[self->field_28 % self->field_8];
                    *p = (UnkStruct_u *)func_003C3250(&D_0064CD40);
                    UnkStruct_u **q = &self->field_17C[a];
                    *q = (UnkStruct_u *)func_003C3150(&D_0064CD40);
                    if (*p != 0 && *q != 0) {
                        self->field_2C++;
                        self->field_28++;
                        self->field_19 = 1;
                        D_0064CD44.field_0 = 1;
                        ok = true;
                    } else ok = false;
                } else ok = false;
                if (ok) self->field_47 = 1;
            }
        }
    } else {
        if (D_004E2D48.field_0 == self->field_1C) D_004E2D48.field_0 = -1;
    }
    if (self->field_47 != 0) {
        bool v = false;
        int a1 = self->field_4;
        if (cur > a1) {
            if (!(cur > a1 + 8) && cur - a1 > 4) v = true;
        } else if (a1 > cur) {
            int a0 = cur + self->field_C;
            if (!(a0 > a1 + 8) && a0 - a1 > 4) v = true;
        }
        if (self->field_24 == self->field_2C) {
            self->field_4++;
            self->field_0++;
            self->field_4 = self->field_4 % self->field_C;
            self->field_0 = self->field_0 % self->field_8;
            self->field_47 = 0;
            D_004E2D48.field_0 = -1;
            v = false;
        }
        if (v) return 0;
    }
    {
        int v1 = self->field_4;
        if (cur < v1) {
            if (v1 > cur) {
                if (!(cur + self->field_C > v1 + 4)) self->field_4C = cur;
            }
        } else {
            if (!(cur > v1 + 4)) self->field_4C = cur;
        }
    }
    self->field_48 = -1;
    UnkStruct_u *u;
    {
        int idx = self->field_4C;
        if (self->field_24 != self->field_2C && idx == self->field_24 % self->field_C) {
            u = 0;
        } else if (idx >= 0 && idx < self->field_C) {
            UnkStruct_u *x = self->field_17C[idx];
            if (*(int *)((unsigned int)x | 0x20000000) == 2) u = x;
            else u = 0;
        } else {
            u = 0;
        }
    }
    for (int i = self->field_0 - 4; i <= self->field_0 + 4; i++) {
        int j = i;
        if (j < 0) j = i + self->field_8;
        int a3 = j % self->field_8;
        UnkStruct_u *y;
        if (self->field_20 != self->field_28 && a3 == self->field_20 % self->field_8) {
            y = 0;
        } else if (a3 >= 0 && a3 < self->field_8) {
            UnkStruct_u *x = self->field_154[a3];
            if (*(int *)((unsigned int)x | 0x20000000) == 2) y = x;
            else y = 0;
        } else {
            y = 0;
        }
        if (y->field_4 == u->field_4) {
            self->field_48 = a3;
            return 1;
        }
    }
    return 1;
}
