// CB3HUDManager::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3HUDManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (element pointer e = &field_0[i]; field_64 as void* (null-tested, passed on); list head address held in a local int* pp).

// CB3HUDManager::Release() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3HUDManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3HUDManager;
struct UnkStruct_001A0800_3;
struct UnkStruct_001A0800_e0;
struct UnkStruct_001A0800_e1;

struct UnkStruct_001A0800_e0 {
    unsigned char pad_0[0x40];
    UnkStruct_001A0800_e1 * field_40;
    unsigned char pad_44[0x20];
    void * field_64;
    int field_68;
    unsigned char pad_6C[0x4];
};

struct UnkStruct_001A0800_e1 {
    unsigned char pad_0[0xC];
    int field_C;
};

struct UnkStruct_001A0800_3 {
    unsigned char pad_0[0xC];
    int field_C;
};

class CB3HUDManager {
public:
    void Release();

    UnkStruct_001A0800_e0 field_0[1];  // [G] element count unknown
    unsigned char pad_70[0x100];
    int field_170;
    int field_174;
    int field_178;
};

extern "C" void Destruct__10CGt2dFrameFv(void *);  // CGt2dFrame::Destruct()

// 0x001A0800
void CB3HUDManager::Release()
{
    for (int i = 0; (i < field_170); i++) {
        UnkStruct_001A0800_e0 * e = &field_0[i];
        for (int i1 = 0; (i1 < 18); i1++) {
            e->field_40[i1].field_C = 0;
        }
        if (e->field_64 != 0) {
            Destruct__10CGt2dFrameFv(e->field_64);
            e->field_64 = 0;
        }
        int * pp = &e->field_68;
        UnkStruct_001A0800_3 * m0 = (UnkStruct_001A0800_3 *)*pp;
        while (m0 != 0) {
            int t1 = m0->field_C;
            m0->field_C = 0;
            m0 = (UnkStruct_001A0800_3 *)t1;
        }
        *pp = 0;
    }
    field_170 = 0;
    field_174 = 0;
    field_178 = 24;
}
