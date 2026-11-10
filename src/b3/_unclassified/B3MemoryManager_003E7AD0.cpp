// CB3MemoryManager::ReleaseBlock(EB3MemoryBlock,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3MemoryManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a133: ReleaseBlock switch (jtbl) W()/WI() byte-offset stores; WI as ((int*)(self+off))[p1*4] gives idx-first addu).

struct UnkStruct_ReleaseBlock { unsigned char pad_0[0x984]; int field_984; };
#define W(off) (*(int *)((char *)self + (off)))
#define WI(off) (((int *)((char *)self + (off)))[p1 * 4])
// [L] DNAT: CB3MemoryManager::ReleaseBlock(EB3MemoryBlock, int) (research/proto/new_names.csv)
extern "C" void ReleaseBlock__16CB3MemoryManagerF14EB3MemoryBlocki(UnkStruct_ReleaseBlock *self, int block, int p1)
{
    switch (block) {
    case 0:
        W(0x54) = 2;
        break;
    case 1:
        if (self->field_984 == 0) WI(0x8E4) = 2;
        else if (self->field_984 == 2) WI(0x424) = 2;
        else WI(0x104) = 2;
        break;
    case 2:
        if (self->field_984 == 2) WI(0x824) = 2; else WI(0x364) = 2;
        break;
    case 3:
        if (self->field_984 == 0) W(0x914) = 2;
        else if (self->field_984 == 2) W(0x484) = 2;
        else W(0x164) = 2;
        break;
    case 5:
        if (self->field_984 == 0) W(0x934) = 2;
        else if (self->field_984 == 2) W(0x494) = 2;
        else W(0x174) = 2;
        break;
    case 6:
        if (self->field_984 == 2) WI(0x4A4) = 2; else WI(0x184) = 2;
        break;
    case 7:
        if (self->field_984 == 2) WI(0x5D4) = 2; else WI(0x224) = 2;
        break;
    case 8:
        W(0x64) = 2;
        break;
    case 9:
        if (self->field_984 == 2) W(0x804) = 2; else W(0x344) = 2;
        break;
    case 10:
        W(0x14) = 2;
        break;
    case 11:
        W(0x24) = 2;
        break;
    case 13:
        if (self->field_984 == 2) W(0x814) = 2; else W(0x354) = 2;
        break;
    case 12:
        W(0x34) = 2;
        break;
    case 14:
        W(0x4) = 2;
        break;
    case 15:
        W(0x44) = 2;
        break;
    case 16:
        W(0x944) = 2;
        break;
    case 17:
        W(0x964) = 2;
        break;
    case 20:
        W(0x954) = 2;
        break;
    case 18:
        W(0x974) = 2;
        break;
    case 19:
        W(0x904) = 2;
        break;
    case 21:
        WI(0x74) = 2;
        break;
    case 22:
        W(0xF4) = 2;
        break;
    case 4:
        break;
    }
}
