// CGtNetworkPlayerManager::GetPlayerByID(int) const -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtNetworkPlayerManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (player array, callee param and return typed void* instead of int).

// lifter variant 0
// CGtNetworkPlayerManager::GetPlayerByID(int) const -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtNetworkPlayerManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtNetworkPlayerManager;

class CGtNetworkPlayerManager {
public:
    void * GetPlayerByID(int p0) const;

    unsigned char pad_0[0x8];
    void * field_8[1];  // [G] element count unknown
    unsigned char pad_C[0x1C];
    int field_28;
    unsigned char pad_2C[0x4C];
    int field_78;
};

extern "C" int func_0022FBB0(void *);

// 0x002366E0
void * CGtNetworkPlayerManager::GetPlayerByID(int p0) const
{
    if (p0 == field_78) {
        return 0;
    }
    for (int i = 0; (i < field_28); i++) {
        void * t0 = field_8[i];
        if (t0 == 0) {
            continue;
        }
        int r0 = func_0022FBB0(t0);
        if (p0 != r0) {
            continue;
        }
        return field_8[i];
    }
    return 0;
}
