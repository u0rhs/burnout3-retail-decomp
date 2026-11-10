// CB3CrashAnalyser::JoinExistingCrash() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CrashAnalyser.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (cmp1: field_19AC bound to an int-sized enum local keeps the beq lower-register-first order (N240)).

// 1 instr: beq v0,v1 vs ours v1,v0 (register numbering of 103C/19AC loads); func_0035EDB0 now takes self (argread real, sig2); tried decl-order locals, != forms, inline eq helpers


enum UnkEnum_00354D60 { UnkEnum_00354D60_0 };

struct UnkStruct_00354D60_c3 { unsigned char pad_0[0x1914]; int field_1914; unsigned char pad_1918[0x94]; signed char field_19AC; };
struct UnkStruct_00354D60_c2 { unsigned char pad_0[0x13F4]; UnkStruct_00354D60_c3 *field_13F4; };
struct UnkStruct_00354D60_car { unsigned char pad_0[0x218]; signed char field_218; unsigned char pad_219[0x11DB]; UnkStruct_00354D60_c3 *field_13F4; };
struct UnkStruct_D_00522660 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_0064517C { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_0064D37C { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_D_0064517C D_0064517C;
extern UnkStruct_D_0064D37C D_0064D37C;
extern char D_004EE040[];
extern "C" int func_0035EDB0(void *);
extern "C" int func_00131E40(void *);
class CB3CollidingBody;
class CB3CrashAnalyser {
public:
    void AddCollidingBody(CB3CollidingBody *);
    unsigned char pad_0[0x1000];
    UnkStruct_00354D60_car *field_1000;
    int field_1004;
    unsigned char pad_1008[0x28];
    int field_1030;
    int field_1034;
    int field_1038;
    int field_103C;
    int field_1040;
    int field_1044;
    unsigned char pad_1048;
    unsigned char field_1049;
};
extern "C" int JoinExistingCrash__16CB3CrashAnalyserFv(CB3CrashAnalyser *self, UnkStruct_00354D60_car *car)
{
    func_0035EDB0(self);
    self->field_1000 = car;
    self->field_103C = self->field_1000->field_218;
    self->field_1030 = 0;
    self->field_1034 = 0;
    self->field_1038 = 0;
    self->field_1044 = -1;
    self->field_1004 = -1;
    self->field_1049 = 1;
    self->field_1040 = 0;
    if (func_00131E40(D_004EE040) != 0) goto join;
    {
    UnkStruct_00354D60_c3 *c = self->field_1000->field_13F4;
    UnkEnum_00354D60 idx = (UnkEnum_00354D60)c->field_19AC;
    if (self->field_103C == idx && c->field_1914 == 0) {
    } else {
        for (int i = 0; i < D_0064517C.field_0; i++) {
            UnkStruct_00354D60_car *o = *(UnkStruct_00354D60_car **)((char *)&D_00522660 + i * 4 + 0x122A10);
            if (self->field_103C == o->field_218) self->AddCollidingBody((CB3CollidingBody *)o);
        }
    }
    }
    for (int j = 0; j < D_0064D37C.field_0; j++) {
        self->AddCollidingBody(*(CB3CollidingBody **)((char *)&D_00522660 + j * 0x30 + 0x3C98C));
    }
ret:
    return 1;
join:
    self->AddCollidingBody((CB3CollidingBody *)car);
    goto ret;
}
