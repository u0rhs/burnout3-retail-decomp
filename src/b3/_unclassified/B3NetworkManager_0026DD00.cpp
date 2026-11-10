// CB3NetworkManager::RegisterPlayerCarCrash() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3NetworkManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a79: loop over field_28 calling func_002366D0, sb 3).

struct UnkStruct_0026DD00_obj {
    unsigned char pad_0[0x28];
    int field_28;
};
struct UnkStruct_002366D0_ret {
    unsigned char pad_0[0x4EE9];
    unsigned char field_4EE9;
};
class CB3NetworkManager {
public:
    void RegisterPlayerCarCrash();
    unsigned char pad_0[0x28];
    int field_28;
};
extern "C" UnkStruct_002366D0_ret *func_002366D0(CB3NetworkManager *, int);
// 0x0026DD00
void CB3NetworkManager::RegisterPlayerCarCrash()
{
    int n = field_28;
    for (int i = 0; i < n; i++) {
        UnkStruct_002366D0_ret *p = func_002366D0(this, i);
        if (p != 0) {
            p->field_4EE9 = 3;
        }
    }
}
