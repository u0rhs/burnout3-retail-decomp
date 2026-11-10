#include "b3/gamesource/Menu/DebugMenu/Components/B3VListComponent.h"

// [L] true size/type unknown (data region is 0xC bytes per the disassembled dlabel, but only the
// first 4 are ever read as a plain int by any caller found so far); padded well past CodeWarrior's
// small-data threshold so this extern reference compiles to the same 2-instruction absolute
// lui/addiu form retail uses, not a single gp-relative instruction (N51).
struct UnkStruct_D_01E90424 {
    int value;
    unsigned char pad[0x100];
};
extern UnkStruct_D_01E90424 D_01E90424;

// 0x0032B290 (Target #23)
void CB3VListComponent::Update(float)
{
    if (D_01E90424.value == 5)
        return;
}
