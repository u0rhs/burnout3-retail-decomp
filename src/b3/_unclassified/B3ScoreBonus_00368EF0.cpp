// CB3ScoreBonus::OnEvent(EScoreBonusEvent,int,int,bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ScoreBonus.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (OnEvent: merged ev<200||ev>208, pmaxw/pextlw asm helpers).

struct UnkStruct_8EF0_ui { virtual void vfunc_8(); virtual void vfunc_C(); virtual void vfunc_10(); virtual void vfunc_14(); virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24(); virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34(); virtual void vfunc_38(); virtual void vfunc_3C(); virtual void vfunc_40(); virtual void vfunc_44(); virtual int vfunc_48(); };
struct UnkStruct_8EF0_g { unsigned char pad_0[0x1B4]; UnkStruct_8EF0_ui *field_1B4; };
struct UnkStruct_8EF0_g2 { UnkStruct_8EF0_g *field_0; unsigned long pad; };
struct UnkStruct_8EF0_car { unsigned char pad_0[0x10CC]; float field_10CC; unsigned char pad_10D0[0x81A]; unsigned char field_18EA; };
struct UnkStruct_8EF0 {
    unsigned char pad_0[0x10]; unsigned char field_10; unsigned char field_11; unsigned char pad_12[0x11E];
    int field_130; int field_134; float field_138; unsigned char pad_13C[0xC]; UnkStruct_8EF0_car *field_148;
};
struct UnkStruct_D_004EE040_x { unsigned char pad_0[0x10]; };
extern UnkStruct_D_004EE040_x D_004EE040;
extern UnkStruct_8EF0_g2 D_0051BA88;
extern "C" int func_00131E40(void *);
static inline int a129_max(int a, int b) { int r; asm("pmaxw %0, %1, %2" : "=r"(r) : "r"(a), "r"(b)); return r; }
static inline unsigned int a129_zx(int a) { unsigned int r; asm("pextlw %0, $0, %1" : "=r"(r) : "r"(a)); return r; }
extern "C" int OnEvent__13CB3ScoreBonusF16EScoreBonusEventiib(UnkStruct_8EF0 *self, int ev, int a2, int a3, int a4)
{
    if (func_00131E40(&D_004EE040)) {
        if (ev < 200 || ev > 208) return 0;
    } else {
        if (ev < self->field_130) {
            int r = D_0051BA88.field_0->field_1B4->vfunc_48();
            if (a3 & r) self->field_134 = a129_zx(a129_max(a2, self->field_134));
            return 0;
        }
    }
    if ((unsigned)(ev - 0x7F) < 3) {
        if (self->field_148->field_18EA == 0) return 0;
    } else {
        self->field_11 = a4;
        if (self->field_148->field_18EA != 0 && self->field_11 == 0) return 0;
    }
    int r = D_0051BA88.field_0->field_1B4->vfunc_48();
    if (!(a3 & r)) a2 = 0;
    self->field_130 = ev;
    self->field_134 = a129_zx(a129_max(a2, self->field_134));
    self->field_138 = self->field_148->field_10CC;
    self->field_10 = 1;
    return 1;
}
