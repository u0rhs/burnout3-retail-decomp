// 0x0030D3B0 (Target #25). Identity unknown: an earlier [L] reading named this
// CB3MenuPageManager::Construct(), retracted in docs/known.md N62. Its only caller (d5/frontend_flow.s)
// passes this = &D_01E900B0, while the page manager instance is D_01E90240 (0x190 bytes later, proven by
// CB3MenuComponentBase::Construct's AddComponent call), and nothing here reaches that far. Kept under its
// placeholder name with C linkage, so the symbol is literally Prepare__14CB3MenuChoicesFv and no alias is needed.
// File placement stays [L]: it sits among CB3MenuPageManager's methods (N2 contiguity).
//
// Initializes 0x0-0x177 of the object at D_01E900B0 (layout below, placeholder struct, never defined):
// ints at 0x0-0x10, 0x18-0x38; four parallel 8-slot arrays at 0x3C (int), 0x5C (int), 0x80 (u64),
// 0xC0 (int); 0xE0/0xE4 int, 0xE8 u64; two parallel 5-slot arrays at 0xF0 (u64) and 0x118/0x12C (int);
// 0x140 u64; 0x148-0x154 ints (0x154 = 2); 0x164/0x168/0x16C = 1.0f; bytes 0x170 = 0xA, 0x171 = 1,
// 0x172-0x174/0x176/0x177 = 0.
//
// Hand-inlined, same reasoning as N37/N38/N43/N44: a plain field-by-field translation gets every
// value and store width right (confirmed: identical size, identical offsets/values, several source
// variations tried for the scratch-register choices) but CodeWarrior's register allocator picks a
// consistently different set of scratch registers (e.g. retail's single-use literals land in
// $a1/$v0 where a naive translation puts them in $a2/$v1, and the loop counters land in $a2 instead
// of $a3) for reasons that didn't respond to any source-level restructuring tried (explicit named
// locals, a single shared loop counter vs. two block-scoped ones, reordering declarations). Since
// the VALUES were never in question, the whole function is hand-inlined here to pin the exact
// register choices, including its own "jr $ra" with a real instruction in the delay slot rather
// than a compiler-synthesized "nop".
struct UnkStruct_D_01E900B0;

extern "C" void Prepare__14CB3MenuChoicesFv(UnkStruct_D_01E900B0 *self)
{
    asm volatile(
        ".set   noreorder"          "\n\t"
        "sw     $zero, 0x0(%0)"     "\n\t"
        "addiu  $a1, $zero, 0x5"    "\n\t"
        "sw     $zero, 0x4(%0)"     "\n\t"
        "addiu  $v1, $zero, 0x1"    "\n\t"
        "sw     $zero, 0x8(%0)"     "\n\t"
        "addiu  $v0, $zero, 0x4"    "\n\t"
        "sw     $zero, 0xC(%0)"     "\n\t"
        "daddu  $a2, $zero, $zero"  "\n\t"
        "sw     $zero, 0x10(%0)"    "\n\t"
        "sw     $a1, 0x18(%0)"      "\n\t"
        "sw     $zero, 0x1C(%0)"    "\n\t"
        "sw     $v1, 0x20(%0)"      "\n\t"
        "sw     $v0, 0x24(%0)"      "\n\t"
        "sw     $v1, 0x28(%0)"      "\n\t"
        "sw     $zero, 0x2C(%0)"    "\n\t"
        "sw     $zero, 0x30(%0)"    "\n\t"
        "sw     $zero, 0x34(%0)"    "\n\t"
        "sb     $zero, 0x176(%0)"   "\n\t"
        "sw     $zero, 0x38(%0)"    "\n\t"
    "1:"                            "\n\t"
        "sll    $v1, $a2, 2"        "\n\t"
        "sll    $v0, $a2, 3"        "\n\t"
        "addu   $a1, %0, $v1"       "\n\t"
        "addiu  $a2, $a2, 0x1"      "\n\t"
        "sw     $zero, 0x3C($a1)"   "\n\t"
        "addu   $v1, %0, $v0"       "\n\t"
        "sw     $zero, 0x5C($a1)"   "\n\t"
        "slti   $v0, $a2, 0x8"      "\n\t"
        "sd     $zero, 0x80($v1)"   "\n\t"
        "bnez   $v0, 1b"            "\n\t"
        "sw     $zero, 0xC0($a1)"   "\n\t"
        "sw     $zero, 0xE0(%0)"    "\n\t"
        "daddu  $a2, $zero, $zero"  "\n\t"
        "sw     $zero, 0xE4(%0)"    "\n\t"
        "sd     $zero, 0xE8(%0)"    "\n\t"
        "sw     $zero, 0x14C(%0)"   "\n\t"
    "2:"                            "\n\t"
        "sll    $v1, $a2, 2"        "\n\t"
        "sll    $v0, $a2, 3"        "\n\t"
        "addu   $a1, %0, $v1"       "\n\t"
        "addiu  $a2, $a2, 0x1"      "\n\t"
        "addu   $v1, %0, $v0"       "\n\t"
        "sw     $zero, 0x118($a1)"  "\n\t"
        "sw     $zero, 0x12C($a1)" "\n\t"
        "slti   $v0, $a2, 0x5"      "\n\t"
        "bnez   $v0, 2b"            "\n\t"
        "sd     $zero, 0xF0($v1)"   "\n\t"
        "sd     $zero, 0x140(%0)"   "\n\t"
        "addiu  $v1, $zero, 0x2"    "\n\t"
        "sw     $zero, 0x148(%0)"   "\n\t"
        "addiu  $a1, $zero, 0xA"    "\n\t"
        "sw     $zero, 0x150(%0)"   "\n\t"
        "addiu  $v0, $zero, 0x1"    "\n\t"
        "sw     $v1, 0x154(%0)"     "\n\t"
        "sb     $a1, 0x170(%0)"     "\n\t"
        "lui    $v1, 0x3F80"        "\n\t"
        "sb     $zero, 0x172(%0)"   "\n\t"
        "sb     $v0, 0x171(%0)"     "\n\t"
        "sb     $zero, 0x173(%0)"   "\n\t"
        "sb     $zero, 0x174(%0)"   "\n\t"
        "sb     $zero, 0x177(%0)"   "\n\t"
        "sw     $v1, 0x164(%0)"     "\n\t"
        "sw     $v1, 0x168(%0)"     "\n\t"
        "jr     $ra"                "\n\t"
        "sw     $v1, 0x16C(%0)"     "\n\t"
        ".set   reorder"
        :
        : "r"(self)
        : "v0", "v1", "a1", "a2"
    );
}
