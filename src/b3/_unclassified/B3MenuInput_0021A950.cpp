// CB3MenuInput::Prepare() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3MenuInput.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (loop 23, return true).

struct UnkStruct_021A_a164_E { short s0; short s2; float f4; int f8; };
struct UnkStruct_021A_a164 { int f0; int f4; UnkStruct_021A_a164_E e[23]; };
extern "C" bool Prepare__12CB3MenuInputFv(UnkStruct_021A_a164 *s)
{
    s->f0 = 0;
    s->f4 = 0;
    for (int i = 0; i < 23; i++) {
        s->e[i].s0 = 0;
        s->e[i].s2 = 0;
        s->e[i].f4 = 1.0f;
        s->e[i].f8 = 0;
    }
    return true;
}
