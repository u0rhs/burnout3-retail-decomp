// NONMATCHING: func_0030C560 -- retail 300 / ours 299 instructions, 105 in changed runs
// a146: logic complete (299 vs 300 instrs), control flow/switch order (0,1,3,4,6)/loops right; remaining: s-register naming (retail idx=s0,r=s1,self=s2,tp=s3,e=s4; ours self=s4,idx=s3,tp=s2,e=s0 - 24 declaration permutations + param copies did not move it) and found-loop 'b; li a0,1' delay slot. Returns &D_0051AD00 (race-setup record).
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

struct UnkStruct_C560_sub { long field_0; long field_8; unsigned char pad_10[0x84]; signed char field_94; unsigned char pad_95[3]; };
struct UnkStruct_C560_ent { UnkStruct_C560_sub subs[6]; long field_390; long field_398; unsigned char pad_3A0[0x40]; };
struct UnkStruct_C560_gl { unsigned char pad_0[0x260]; int field_260; unsigned char pad_264[0x14]; UnkStruct_C560_ent field_278[1]; };
struct UnkStruct_D_0051A86C_C560 { UnkStruct_C560_gl *field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_C560_trk { long field_0; long field_8; unsigned char pad_10[4]; int field_14; };
struct UnkStruct_C560_118 { unsigned char pad_0[0x30]; int field_30; };
struct UnkStruct_C560_self {
    unsigned char pad_0[0x14];
    int field_14;
    unsigned char pad_18[0x68];
    long field_80[8];
    int field_C0[8];
    unsigned char pad_E0[8];
    long field_E8;
    unsigned char pad_F0[0x28];
    UnkStruct_C560_118 *field_118;
    unsigned char pad_11C[0x10];
    UnkStruct_C560_trk *field_12C[4];
};
struct UnkStruct_D_0051AD00_C560 {
    long field_0;
    long field_8;
    unsigned char pad_10[8];
    long field_18[8];
    unsigned char pad_58[0x10];
    long field_68;
    int field_70;
    unsigned char pad_74[4];
    int field_78[8];
    unsigned char pad_98[8];
    int field_A0;
    int field_A4;
    unsigned char pad_A8[4];
    char field_AC[0x100];
    unsigned char field_1AC;
    unsigned char pad_1AD[7];
    void *field_1B4;
    void *field_1B8;
    unsigned char pad_1BC[4];
};
struct UnkStruct_D_00518680_C560 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_00518684_C560 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_0051B938_C560 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_005196A0_C560 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_0051A86C_C560 D_0051A86C;
extern UnkStruct_D_0051AD00_C560 D_0051AD00;
extern UnkStruct_D_00518680_C560 D_00518680;
extern UnkStruct_D_00518684_C560 D_00518684;
extern UnkStruct_D_0051B938_C560 D_0051B938;
extern UnkStruct_D_005196A0_C560 D_005196A0;
struct UnkStruct_C560_b { unsigned char pad_0[0x10]; };
extern UnkStruct_C560_b D_0051B928;
extern UnkStruct_C560_b D_0051B258;
extern UnkStruct_C560_b D_0051B2F0;
extern UnkStruct_C560_b D_0051B340;
extern UnkStruct_C560_b D_0051B2A4;
extern UnkStruct_C560_b D_0051B3B4;
extern char D_004C4AB8[];
extern char *kacGameDataFileName;
extern "C" {
void *memset(void *, int, unsigned int);
unsigned int strlen(const char *);
int sprintf(char *, const char *, ...);
long func_0030CA10(UnkStruct_C560_self *, UnkStruct_C560_ent *, int, int);
int GetTrackIndexFromID__12CB3TrackListFUl(void *, unsigned long);
void CreateTrackPathFromIndex__12CB3TrackListFiPci(void *, int, char *, int);
}

extern "C" UnkStruct_D_0051AD00_C560 *func_0030C560(UnkStruct_C560_self *self, int idx)
{
    UnkStruct_C560_trk **tp;
    UnkStruct_D_0051AD00_C560 *r;
    UnkStruct_C560_ent *e;
    int i;
    r = &D_0051AD00;
    memset(r, 0, 0x1B0);
    D_0051B938.field_0 = idx;
    r->field_1B8 = &D_0051B928;
    tp = &self->field_12C[idx];
    UnkStruct_C560_trk *trk = *tp;
    UnkStruct_C560_gl *gl = D_0051A86C.field_0;
    int n = gl->field_260;
    e = gl->field_278;
    i = 0;
    goto test;
body:
    if (e->field_398 == trk->field_8) {
        if (e->field_390 == trk->field_0) goto found;
    }
    e++;
    i++;
test:
    if (i < n) goto body;
    e = 0;
found:
    r->field_1AC = 1;
    switch ((*tp)->field_14) {
    case 0:
        r->field_1B4 = &D_0051B258;
        if (self->field_118->field_30 == 8) r->field_A4 = 1;
        else r->field_A4 = 5;
        break;
    case 1:
        r->field_A4 = 5;
        r->field_1B4 = &D_0051B2F0;
        break;
    case 3:
        r->field_A4 = 3;
        r->field_1B4 = &D_0051B340;
        break;
    case 4:
        r->field_A4 = 0;
        r->field_1B4 = &D_0051B2A4;
        break;
    case 6:
        r->field_A4 = 0;
        r->field_1B4 = &D_0051B3B4;
        break;
    default:
        break;
    }
    for (i = 0; i < r->field_A4; i++) {
        if (e->subs[i + 1].field_0 == 0) e->subs[i + 1].field_0 = e->subs[0].field_0;
    }
    self->field_14 = 1;
    r->field_A0 = self->field_14;
    self->field_E8 = (*tp)->field_0;
    r->field_0 = (*tp)->field_0;
    if ((*tp)->field_14 == 6) r->field_8 = func_0030CA10(self, e, 0, 0);
    else r->field_8 = self->field_80[0];
    r->field_70 = self->field_C0[0];
    if (idx == 0) {
        for (idx = 0; idx < r->field_A4; idx++) {
            self->field_80[idx + self->field_14] = func_0030CA10(self, e, idx + self->field_14, 0);
            self->field_C0[idx + self->field_14] = e->subs[idx + self->field_14].field_94;
            if (self->field_C0[idx + self->field_14] < 0) {
                int x = D_00518680.field_0;
                int y = D_00518684.field_0;
                x = (x << 16) + (x >> 16) + y;
                D_00518680.field_0 = x;
                D_00518684.field_0 = y + x;
                int a1 = (unsigned int)x % 3;
                int t1 = idx + self->field_14;
                int best = a1;
                int bestc = 8;
                for (int a0 = 0; a0 < 3; a0++) {
                    int cnt = 0;
                    for (int t2 = 0; t2 < t1; t2++) {
                        if (self->field_80[t2] == self->field_80[t1] && self->field_C0[t2] == a1) cnt++;
                    }
                    if (cnt < bestc) {
                        bestc = cnt;
                        best = a1;
                    }
                    a1++;
                    if (a1 >= 3) a1 = 0;
                }
                self->field_C0[t1] = best;
            }
        }
    }
    for (int k = 0; k < r->field_A4; k++) {
        r->field_18[k] = self->field_80[k + self->field_14];
        r->field_78[k] = self->field_C0[k + self->field_14];
    }
    CreateTrackPathFromIndex__12CB3TrackListFiPci(&D_005196A0, GetTrackIndexFromID__12CB3TrackListFUl(&D_005196A0, (*tp)->field_0), r->field_AC, 0x100);
    sprintf(r->field_AC + strlen(r->field_AC), D_004C4AB8, kacGameDataFileName);
    r->field_68 = (*tp)->field_8;
    return r;
}

