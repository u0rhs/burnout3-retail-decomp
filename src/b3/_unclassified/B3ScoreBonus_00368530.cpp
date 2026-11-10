// CB3ScoreBonus::OnCrashEscape(int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3ScoreBonus.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (first try; array members, jtbl OK).

extern "C" int OnEvent__13CB3ScoreBonusF16EScoreBonusEventiib(void *, int, int, int, bool);
extern "C" void AddScore__8CB3ScoreFii(void *, int, int, int);
struct UnkStruct_00368530_s {
    unsigned char pad_0[0x1530];
    int field_1530[6];
    float field_1548[6];
    float field_1560[6];
};
struct UnkStruct_00368530 {
    unsigned char pad_0[0x148];
    UnkStruct_00368530_s *field_148;
};
extern "C" void OnCrashEscape__13CB3ScoreBonusFi(UnkStruct_00368530 *self, int idx)
{
    int ev = 0x27;
    int pts = 0x19;
    float d = self->field_148->field_1560[idx];
    if (d <= 15.0f) {
        if (d <= 5.0f) {
            ev = 0x29;
            pts = 0x64;
        } else {
            ev = 0x28;
            pts = 0x32;
        }
    }
    if (self->field_148->field_1548[idx] != -1.0f) {
        switch (self->field_148->field_1530[idx]) {
        case 1: ev = 0x2B; break;
        case 2: ev = 0x2C; break;
        case 3: ev = 0x2D; break;
        case 4: ev = 0x2E; break;
        case 5: ev = 0x2F; break;
        case 7: ev = 0x30; break;
        case 8: ev = 0x31; break;
        case 9: ev = 0x32; break;
        case 11: ev = 0x33; break;
        case 12: ev = 0x2A; break;
        }
    }
    AddScore__8CB3ScoreFii((char *)self->field_148 + 0x10C0, pts, 1, 1);
    OnEvent__13CB3ScoreBonusF16EScoreBonusEventiib(self, ev, pts, 1, 0);
}
