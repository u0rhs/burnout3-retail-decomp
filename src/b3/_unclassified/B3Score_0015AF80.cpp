// CB3Score::CheckIfNeedRevenge(const CB3Score*) const -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3Score.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (bool r=true; &&).

struct UnkStruct_015A_a164_A { unsigned char pad_0[0x19AC]; signed char idx; };
struct UnkStruct_015A_a164_B { unsigned char pad_0[0xC8]; UnkStruct_015A_a164_A *p; unsigned char pad_1[0x5B9-0xCC]; unsigned char tbl[1]; };
extern "C" bool CheckIfNeedRevenge__8CB3ScoreCFPC8CB3Score(const UnkStruct_015A_a164_B *self, const UnkStruct_015A_a164_B *o)
{
    bool r = true;
    if (self->tbl[o->p->idx] == 0 && o->tbl[self->p->idx] == 0) r = false;
    return r;
}
