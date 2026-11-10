// CB3PhysicsManager::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3PhysicsManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (Release: six vfunc_C loops over byte-offset element pools).

class UnkStruct_001B8D20_o {
public:
    virtual void vfunc_8();
    virtual void vfunc_C();
};
class CB3PhysicsManager {
public:
    void Release();
    unsigned char pad_0[0xE6200];
    int field_E6200;
    int field_E6204;
    int field_E6208;
};

// 0x001B8D20
void CB3PhysicsManager::Release()
{
    int i;
    for (i = 0; i < field_E6200; i++) {
        ((UnkStruct_001B8D20_o *)((char *)this + i * 0x4590 + 0x1CB80))->vfunc_C();
    }
    for (i = 0; i < field_E6204; i++) {
        ((UnkStruct_001B8D20_o *)((char *)this + i * 0x1580 + 0x256A0))->vfunc_C();
    }
    for (i = 0; i < field_E6208; i++) {
        ((UnkStruct_001B8D20_o *)((char *)this + i * 0x1560 + 0x2C220))->vfunc_C();
    }
    for (i = 0; i < 64; i++) {
        ((UnkStruct_001B8D20_o *)((char *)this + i * 0x2430 + 0x32D00))->vfunc_C();
    }
    for (i = 0; i < 32; i++) {
        ((UnkStruct_001B8D20_o *)((char *)this + i * 0x780 + 0xC3900))->vfunc_C();
    }
    for (i = 0; i < 64; i++) {
        ((UnkStruct_001B8D20_o *)((char *)this + i * 0x4E0 + 0xD2900))->vfunc_C();
    }
}
