// CGtNetworkPlayerManager::GetPlayerIndexByID(int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> GtNetworkPlayerManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (p0==field_78 arm is an inlined free-slot search (placeholder inline func_00235300_inl1, own return -1 epilogue); field_8 is void*[]).

// lifter variant 0
// CGtNetworkPlayerManager::GetPlayerIndexByID(int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> GtNetworkPlayerManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtNetworkPlayerManager;

class CGtNetworkPlayerManager {
public:
    int GetPlayerIndexByID(int p0);
    inline int func_00235300_inl1();  // [G] inlined free-slot search, name unknown

    unsigned char pad_0[0x8];
    void * field_8[1];  // [G] element count unknown
    unsigned char pad_C[0x1C];
    int field_28;
    unsigned char pad_2C[0x4C];
    int field_78;
};

extern "C" int func_0022FBB0(void *);

inline int CGtNetworkPlayerManager::func_00235300_inl1()
{
    for (int i = 0; i < field_28; i++) {
        if (field_8[i] == 0) {
            return i;
        }
    }
    return -1;
}

// 0x00235300
int CGtNetworkPlayerManager::GetPlayerIndexByID(int p0)
{
    if (p0 == field_78) {
        return func_00235300_inl1();
    }
    for (int i = 0; i < field_28; i++) {
        if (field_8[i] != 0 && p0 == func_0022FBB0(field_8[i])) {
            return i;
        }
    }
    return -1;
}
