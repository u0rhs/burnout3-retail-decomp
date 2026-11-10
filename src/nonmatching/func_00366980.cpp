// NONMATCHING: func_00366980 -- retail 429 / ours 432 instructions, 16 in changed runs
// fix2 (2026-11-01): GetPresence takes EGtBuddyPresence* (retail symbol ...FPcP16EGtBuddyPresence; int* mangled to a missing symbol) | Before: 16 instrs differ: tail block layout (E78/E7A set blocks), vf2/vf3 scalar hoist, xor operand order; 432 vs 429
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)


#include "b3/GtMathPs2.h"
using namespace GtMathPs2;
typedef unsigned int u_long128 __attribute__((mode(TI)));
class CGt2dObjectTable {
public:
    CGtV2d GetRowPos(int);
    CGtV2d GetRowSize(int);
    void RecalculateSize();
};
class CB3Panel2dObject {
public:
    void Prepare(const CGtV2d &, const CGtV2d &, const CGtV2d &, unsigned int, float);
};
struct UnkStruct_00366980_e50 { u_long128 field_0; unsigned char pad_10[0x18]; unsigned short * field_28; unsigned char pad_2C[0x24]; };
struct UnkStruct_00366980_e30 { int field_0; unsigned char pad_4[0x20]; int field_24; unsigned char pad_28[0x8]; };
struct UnkStruct_00366980 {
    unsigned char pad_0[0x8];
    short field_8;
    unsigned char pad_A[0x2];
    int field_C;
    unsigned char pad_10[0xDC];
    UnkStruct_00366980_e30 field_EC[10];
    unsigned char pad_2CC[0x760 - 0x2CC];
    UnkStruct_00366980_e50 field_760[9];
    UnkStruct_00366980_e50 field_A30[9];
    unsigned char pad_D00[0xE20 - 0xD00];
    unsigned short * field_E20[9];
    unsigned short * field_E44[9];
    unsigned char pad_E68[0x4];
    CGt2dObjectTable * field_E6C;
    unsigned char pad_E70[0x8];
    unsigned short field_E78;
    unsigned short field_E7A;
    CB3Panel2dObject * field_E7C;
    int field_E80;
};
struct UnkStruct_D_01E90240 { u_long128 field_0; u_long128 field_10; u_long128 field_20; };
struct UnkStruct_D_Pad16 { unsigned char pad_0[0x10]; };
struct UnkStruct_krB3BuddyTableSize { float field_0; unsigned char pad_4[0xC]; };
enum EGtBuddyPresence { };   // [C] name: the mangled GetPresence symbol; values unknown
class CGtBuddiesPS2DirtySock {
public:
    int GetNumBuddies();
    void GetBuddyName(int, char *);
    void GetPresence(char *, EGtBuddyPresence *);   // [C] retail symbol GetPresence__22CGtBuddiesPS2DirtySockFPcP16EGtBuddyPresence
    int GetPresenceText(char *, char *);
    void IsBuddyIgnored(char *, bool *);
    unsigned char pad_0[0x10];
};
extern UnkStruct_D_01E90240 D_01E90240;
extern UnkStruct_D_Pad16 D_01E7A800, D_0051BA44, D_01E903E0;
extern CGtBuddiesPS2DirtySock D_01E3D390;
extern UnkStruct_krB3BuddyTableSize krB3BuddyTableSize;
extern float D_004E0A38;
extern "C" void CopyN__10CGtUnicodeFPUsiPCUs(void *, int, void *);
extern "C" void ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(void *, void *, int);
extern "C" unsigned short * func_00271A00(void *, int);
extern "C" void func_00284D30(void *);
extern "C" void func_00284DA0(void *);
extern "C" int Compare__15CGtUnicodeUtilsFPUsPUs(unsigned short *, unsigned short *);
extern "C" void DestructObject__10CGt2dSceneFiP11CGt2dObject(void *, int, void *);

static inline void func_00366980_inl(UnkStruct_00366980 * self)
{
    CGtV2d pos;
    pos = self->field_E6C->GetRowPos(self->field_E78 + 1);
    pos.SetX(7.0f);
    CGtV2d size;
    size = self->field_E6C->GetRowSize(self->field_E78 + 1);
    size.SetX(krB3BuddyTableSize.field_0 - 4.0f);
    self->field_E7C->Prepare(pos, CGtV2d(0.0f, 0.0f), size, 32, 0.0f);
}
// 0x00366980
extern "C" void func_00366980(UnkStruct_00366980 * self, int flag)
{
    EGtBuddyPresence presence;
    bool ignored;
    unsigned char text[0x68];
    unsigned char buf[0x10];
    unsigned char name[0x20];
    int sel = self->field_E78;
    UnkStruct_D_01E90240 * const mgr = &D_01E90240;
    CopyN__10CGtUnicodeFPUsiPCUs(name, 16, self->field_E44[sel]);
    for (int i = 0; i < 9; i++) {
        *self->field_E44[i] = 0;
        *self->field_E20[i] = 0;
        self->field_760[i].field_28 = self->field_E20[i];
        self->field_EC[i].field_24 = 0;
        self->field_EC[i + 1].field_0 = 0;
    }
    int online;
    int n = D_01E3D390.GetNumBuddies();
    online = 0;
    for (int i = 0; i < n; i++) {
        D_01E3D390.GetBuddyName(i, (char *)buf);
        D_01E3D390.GetPresence((char *)buf, &presence);
        if ((int)presence == 0) {
            online++;
        }
    }
    if (self->field_C >= 0) {
        if (online < self->field_C) {
            func_00284DA0(&D_01E7A800);
        }
        if (self->field_C < online) {
            func_00284D30(&D_01E7A800);
        }
    }
    self->field_C = online;
    float scale = D_004E0A38;
    for (int i = self->field_E80; i < n && i < self->field_E80 + 9; i++) {
        D_01E3D390.GetBuddyName(i, (char *)buf);
        D_01E3D390.GetPresence((char *)buf, &presence);
        bool noText = D_01E3D390.GetPresenceText((char *)buf, (char *)text) == 0;
        D_01E3D390.IsBuddyIgnored((char *)buf, &ignored);
        self->field_EC[i + 1 - self->field_E80].field_0 = 0;
        if (!ignored) {
            switch ((int)presence) {
            case 0:
                self->field_760[i - self->field_E80].field_28 = func_00271A00(&D_0051BA44, 4);
                break;
            case 1: case 2: case 3: case 4: case 5:
                if (noText) {
                    ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(text, self->field_E20[i - self->field_E80], 100);
                    self->field_760[i - self->field_E80].field_28 = self->field_E20[i - self->field_E80];
                } else {
                    self->field_760[i - self->field_E80].field_28 = func_00271A00(&D_0051BA44, 5);
                }
            }
        } else {
            self->field_760[i - self->field_E80].field_28 = func_00271A00(&D_0051BA44, 8);
        }
        ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(buf, self->field_E44[i - self->field_E80], 16);
        bool isSel = self->field_E78 == (unsigned int)(i - self->field_E80);
        if (ignored) {
            self->field_A30[i - self->field_E80].field_0 = mgr->field_20;
            self->field_760[i - self->field_E80].field_0 = mgr->field_20;
            if (isSel) {
                (CGtV4d &)self->field_A30[i - self->field_E80].field_0 = (CGtV4d &)self->field_A30[i - self->field_E80].field_0 * scale;
                (CGtV4d &)self->field_760[i - self->field_E80].field_0 = (CGtV4d &)self->field_760[i - self->field_E80].field_0 * scale;
            }
        } else if (isSel) {
            self->field_760[i - self->field_E80].field_0 = mgr->field_10;
            self->field_A30[i - self->field_E80].field_0 = mgr->field_10;
        } else {
            self->field_760[i - self->field_E80].field_0 = mgr->field_0;
            self->field_A30[i - self->field_E80].field_0 = mgr->field_0;
        }
        if (flag == 0) {
            if (Compare__15CGtUnicodeUtilsFPUsPUs(self->field_E44[i - self->field_E80], (unsigned short *)name) != 0) {
                continue;
            }
            sel = i - self->field_E80;
        }
    }
    if (self->field_E7C == 0) {
        if (n > 0) {
            self->field_E78 = 0;
            self->field_E7A = n;
        }
    }
    if (self->field_E7C != 0 && D_01E3D390.GetNumBuddies() == 0) {
        DestructObject__10CGt2dSceneFiP11CGt2dObject(&D_01E903E0, self->field_8 + 1, self->field_E7C);
        self->field_E7C = 0;
    }
    if (sel < n) {
        if (n < 9) {
            self->field_E78 = sel;
            self->field_E7A = n;
        } else {
            self->field_E78 = sel;
            self->field_E7A = 9;
        }
        if (self->field_E7C != 0) {
            func_00366980_inl(self);
        }
    } else if (n > 0) {
        if (n < 9) {
            self->field_E78 = n - 1;
            self->field_E7A = n;
        } else {
            self->field_E78 = 8;
            self->field_E7A = 9;
        }
        if (self->field_E7C != 0) {
            func_00366980_inl(self);
        }
    }
    self->field_E6C->RecalculateSize();
}
