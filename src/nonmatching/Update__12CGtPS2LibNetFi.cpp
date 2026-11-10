// NONMATCHING: Update__12CGtPS2LibNetFi -- retail 125 / ours 120 instructions, 165 in changed runs
// a250: logic complete (state machine, jtbl cases 5->48=6/4C=0, 6->48=7/14=2/40=1, inline bool range check, 32x vcall slot 0x10). Remaining: this/p0 s-register swap (retail this=s1,p0=s0), retail's dead lw 0x48 up front, field_6CC/6C8 reloaded not CSE'd, first-branch 4F store layout. Register allocation + scheduling.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)


struct UnkStruct_0022F020 {
    void **vtbl;
    unsigned char pad_4[0x4];
    int field_8;
    int field_C;
    unsigned char pad_10[0x4];
    int field_14;
    int field_18;
    unsigned char pad_1C[0x24];
    unsigned char field_40;
    unsigned char pad_41[0x7];
    int field_48;
    unsigned char field_4C;
    unsigned char pad_4D[0x2];
    unsigned char field_4F;
    unsigned char pad_50[0x66C];
    int field_6BC;
    unsigned int field_6C0;
    unsigned int field_6C4;
    int field_6C8;
    int field_6CC;
    int field_6D0;
};
extern "C" int func_0022D2E0(UnkStruct_0022F020 *, int);
static inline int func_0022F020_g6cc(UnkStruct_0022F020 *s) { return s->field_6CC; }
static inline int func_0022F020_g6c8(UnkStruct_0022F020 *s) { return s->field_6C8; }
static inline bool func_0022F020_inl1(UnkStruct_0022F020 *self)
{
    if (self->field_6CC == func_0022F020_g6c8(self) - 1) return true;
    if (func_0022F020_g6cc(self) == 31 && func_0022F020_g6c8(self) == 0) return true;
    int s = self->field_6BC + self->field_6D0;
    unsigned int a0 = self->field_6C0;
    unsigned int v1 = self->field_6C4;
    int d;
    if (v1 < a0) d = a0 - v1; else d = s - v1;
    if (d < self->field_C) return true;
    return false;
}
class CGtPS2LibNet {
public:
    int Update(int p0);
};
// [C] returns func_0022D2E0's result: nothing writes v0 between `jal func_0022D2E0` at 0x22F1E8 and `jr $ra` at 0x22F20C.
// Callers switch on it: CB3NetworkManager::Prepare at 0x271550 (`beq $v0, $a1`), CB3OnlineConnectingPage::UpdateISP at
// 0x347040 (`beq $v0, $v1`).
int CGtPS2LibNet::Update(int p0)
{
    UnkStruct_0022F020 *self = (UnkStruct_0022F020 *)this;
    int a, b, c;
    if (self->field_14 == 3) {
        if (self->field_4F != 0) {
            switch (self->field_48) {
            case 2: case 3:
                break;
            case 5:
                self->field_14 = 1;
                self->field_48 = 3;
                self->field_4C = 0;
                self->field_18 = 0;
                self->field_4F = 0;
                break;
            case 6: case 7:
                break;
            default:
                break;
            }
        }
        self->field_4F = 1;
    } else if (self->field_14 != 2) {
        if (self->field_4C != 0) {
            switch (self->field_48) {
            case 0: case 1: case 2: case 3: case 4: case 7:
                break;
            case 5:
                self->field_48 = 6;
                self->field_4C = 0;
                break;
            case 6:
                self->field_48 = 7;
                self->field_14 = 2;
                self->field_40 = 1;
                break;
            }
        }
    }
    bool ok = func_0022F020_inl1(self);
    if (ok) {
        for (int i = 0; i < 32; i++) {
            ((void (*)(void *, int *, int *, int *))self->vtbl[4])(self, &a, &b, &c);
        }
    }
    return func_0022D2E0(self, p0);
}
