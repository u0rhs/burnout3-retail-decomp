// CB3ScoreBonus::OnAttack(EScoreBonusAttackType,CB3RaceCar*,int,EScoreBonusCategory) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3ScoreBonus.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (wirefix: D_004A4EEC is gapacMedalString+0xC).

struct UnkStruct_00367F40_sc {
    unsigned char pad_0[0x10C0];
    int field_10C0;
    unsigned char pad_10C4[0x8];
    float field_10CC;
    unsigned char pad_10D0[0x10E];
    unsigned char field_11DE;
};
struct UnkStruct_00367F40_car {
    unsigned char pad_0[0x12D4];
    UnkStruct_00367F40_sc * field_12D4;
    float field_12D8;
};
struct UnkStruct_00367F40 {
    int field_0;
    unsigned char field_4;
    unsigned char field_5;
    unsigned char pad_6[0xCE];
    UnkStruct_00367F40_car * field_D4;
    float field_D8;
    float field_DC;
    int field_E0;
    int field_E4;
    int field_E8;
    unsigned char field_EC;
    unsigned char pad_ED[0x3];
    UnkStruct_00367F40_car * field_F0;
    float field_F4;
    unsigned char pad_F8[0x50];
    UnkStruct_00367F40_sc * field_148;
};
extern "C" int OnEvent__13CB3ScoreBonusF16EScoreBonusEventiib(void *, int, int, int, bool);
extern "C" void AddScore__8CB3ScoreFii(void *, int, int, int);
extern "C" unsigned char _kaaeTouchTypeEvents[];
extern "C" unsigned char _kaaeSlamTypeEvents[];
extern "C" unsigned char _kaaeBadSlamTypeEvents[];
extern unsigned char D_004C7A87[];
extern unsigned char D_004C7A77[];
extern int D_004A4F1C[];
extern int gapacMedalString[];
static inline int a150_min(int a, int b) { int r; asm("pminw %0, %1, %2" : "=r"(r) : "r"(a), "r"(b)); return r; }
static inline unsigned int a150_zx(int a) { unsigned int r; asm("pextlw %0, $0, %1" : "=r"(r) : "r"(a)); return r; }

extern "C" void OnAttack__13CB3ScoreBonusF21EScoreBonusAttackTypeP10CB3RaceCari19EScoreBonusCategory(UnkStruct_00367F40 * self, int type, UnkStruct_00367F40_car * car, int bp, int cat)
{
    int ev2 = 0;
    int s0;
    int pts;
    float now = self->field_148->field_10CC;
    bool b = false;
    if (self->field_D4 != car) {
        if (type == 3 || type == 4) b = true;
    }
    if (self->field_E4 == 0 || b) {
        self->field_E4 = 1;
        self->field_E8 = 0;
        self->field_EC = (type == 5);
        self->field_DC = self->field_148->field_10CC;
    } else {
        if (type != 5) self->field_EC = 0;
        if (self->field_D4 != car) {
            s0 = 4;
        } else if (self->field_F0 == car && !(self->field_F4 <= self->field_D8)) {
            s0 = 3;
        } else {
            s0 = 2;
        }
        if (!(self->field_148->field_10CC <= 1.0f + self->field_DC)) {
            if (self->field_E4 == s0) {
                self->field_E8 = self->field_E8 + 1;
                self->field_DC = self->field_148->field_10CC;
            } else {
                self->field_E4 = s0;
                self->field_E8 = 1;
                self->field_DC = self->field_148->field_10CC;
            }
            int k = a150_zx(a150_min(self->field_E8, 2));
            if (self->field_EC != 0) {
                ev2 = (&D_004C7A87[self->field_E4 * 2])[k];
                pts = *(int *)((char *)D_004A4F1C + self->field_E4 * 8 + k * 4);
            } else {
                ev2 = (&D_004C7A77[self->field_E4 * 2])[k];
                pts = *(int *)((char *)&gapacMedalString[3] + self->field_E4 * 8 + k * 4);
            }
            if (ev2 != 0) {
                OnEvent__13CB3ScoreBonusF16EScoreBonusEventiib(self, ev2, (int)((unsigned)bp + (unsigned)pts), 1, 0);
                AddScore__8CB3ScoreFii(&self->field_148->field_10C0, bp + pts, 1, 1);
            }
            if (s0 == 3) {
                OnEvent__13CB3ScoreBonusF16EScoreBonusEventiib((char *)car + 0x11E4, ev2, (int)((unsigned)bp + (unsigned)pts), 1, 0);
                AddScore__8CB3ScoreFii((char *)car + 0x10C0, bp + pts, 1, 1);
            }
        }
    }
    if (ev2 == 0) {
        int e1;
        bool nonSlam = false;
        if (type == 5) {
            int kk = 0;
            if (self->field_4 != 0) kk = kk + 1;
            if (self->field_5 != 0) kk += 2;
            e1 = (&_kaaeSlamTypeEvents[self->field_0 * 4])[kk];
            ev2 = (&_kaaeBadSlamTypeEvents[self->field_0 * 4])[kk];
        } else {
            e1 = (&_kaaeTouchTypeEvents[type * 3])[cat];
            if (e1 == 0x40) {
                if (self->field_148->field_11DE != 0) {
                    e1 = 0x41;
                    ev2 = 0x43;
                } else {
                    ev2 = 0x42;
                }
            } else {
                ev2 = e1;
                nonSlam = true;
            }
        }
        if (e1 != 0) {
            OnEvent__13CB3ScoreBonusF16EScoreBonusEventiib(self, e1, bp, 1, 0);
            AddScore__8CB3ScoreFii(&self->field_148->field_10C0, bp, 1, 1);
        }
        if (ev2 != 0) {
            bp = nonSlam ? bp : 0;
            OnEvent__13CB3ScoreBonusF16EScoreBonusEventiib((char *)car + 0x11E4, ev2, bp, 1, 0);
            AddScore__8CB3ScoreFii((char *)car + 0x10C0, bp, 1, 1);
        }
    }
    self->field_E0 = type;
    self->field_D8 = now;
    self->field_D4 = car;
    car->field_12D4 = self->field_148;
    car->field_12D8 = self->field_148->field_10CC;
}
