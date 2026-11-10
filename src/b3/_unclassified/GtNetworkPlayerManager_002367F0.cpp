// CGtNetworkPlayerManager::RegisterPlayer(const char*,int,int,void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtNetworkPlayerManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (element pointer pp = &field_50[i] with && test and in-loop return; field_4E0 array member (address not CSE'd)).

// lifter variant 0
// CGtNetworkPlayerManager::RegisterPlayer(const char*,int,int,void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtNetworkPlayerManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtNetworkPlayerManager;
struct UnkStruct_002367F0_4;

struct UnkStruct_002367F0_4 {
    // vptr at +0x0: placeholder virtuals by slot offset (names not in any table) [G]
    virtual void vfunc_8(const char*, int, int, int, void*);
};

class CGtNetworkPlayerManager {
public:
    void RegisterPlayer(const char* p0, int p1, int p2, void* p3);

    unsigned char pad_0[0x8];
    void * field_8[1];  // [G] element count unknown
    unsigned char pad_C[0x1C];
    int field_28;
    UnkStruct_002367F0_4 * field_2C[1];  // [G] element count unknown
    unsigned char pad_30[0x1C];
    int field_4C;
    void * field_50[1];  // [G] element count unknown
    unsigned char pad_54[0x1C];
    int field_70;
    unsigned char pad_74[0x8];
    int field_7C;
    unsigned char pad_80[0x460];
    unsigned char field_4E0[1];  // [G] sub-object, size unknown
};

extern "C" int func_0022FBB0(void *);
extern "C" void func_002310B0(void *, int);
extern "C" void RegisterMessageTypes__17CGtNATDataManagerFi(void *, int);

// 0x002367F0
void CGtNetworkPlayerManager::RegisterPlayer(const char* p0, int p1, int p2, void* p3)
{
    for (int i = 0; i < field_70; i++) {
        void ** pp = &field_50[i];
        if (*pp != 0 && func_0022FBB0(*pp) == p2) {
            field_8[field_28] = *pp;
            *pp = 0;
            field_28++;
            return;
        }
    }
    field_4C--;
    UnkStruct_002367F0_4 * t2 = field_2C[field_4C];
    t2->vfunc_8(p0, p1, field_7C, p2, p3);
    field_8[field_28] = t2;
    field_28++;
    func_002310B0(field_4E0, p2);
    RegisterMessageTypes__17CGtNATDataManagerFi(field_4E0, p2);
}
