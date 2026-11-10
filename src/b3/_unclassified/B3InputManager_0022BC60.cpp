// CB3InputManager::GenericConstruct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3InputManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3InputManager;
struct UnkStruct_0022BC60_e13;

struct UnkStruct_0022BC60_e13 {
    unsigned char pad_0[0x12C];
};

class CB3InputManager {
public:
    int GenericConstruct();

    UnkStruct_0022BC60_e13 field_0[1];  // [G] element count unknown
    unsigned char pad_12C[0xE74];
    unsigned char field_FA0;
    unsigned char field_FA1[1];  // [G] element count unknown
    unsigned char pad_FA2[0x1];
    unsigned char field_FA3[1];  // [G] element count unknown
    unsigned char pad_FA4[0x1];
    unsigned char field_FA5[1];  // [G] element count unknown
    unsigned char pad_FA6[0x2];
    int field_FA8[1];  // [G] element count unknown
    unsigned char pad_FAC[0x4];
    int field_FB0[1];  // [G] element count unknown
    unsigned char pad_FB4[0x4];
    int field_FB8[1];  // [G] element count unknown
    unsigned char pad_FBC[0x4];
    int field_FC0[1];  // [G] element count unknown
    unsigned char pad_FC4[0x4];
    int field_FC8[1];  // [G] element count unknown
    unsigned char pad_FCC[0x4];
    int field_FD0[1];  // [G] element count unknown
    unsigned char pad_FD4[0x4];
    int field_FD8[1];  // [G] element count unknown
    unsigned char pad_FDC[0x4];
    unsigned char field_FE0;
    unsigned char field_FE1[1];  // [G] element count unknown
    unsigned char pad_FE2[0x2];
    float field_FE4[1];  // [G] element count unknown
    unsigned char pad_FE8[0x4];
    float field_FEC[1];  // [G] element count unknown
};

extern "C" void Construct__20CB3ControllerMappingFUi(void *, unsigned int);  // CB3ControllerMapping::Construct(unsigned int)

// 0x0022BC60
int CB3InputManager::GenericConstruct()
{
    int m0 = 0;
    do {
        Construct__20CB3ControllerMappingFUi(((char *)&field_0[((signed char)m0)] + 0xD48), ((signed char)m0));
        field_FA5[((signed char)m0)] = 0;
        m0 = ((signed char)(m0 + 1));
    } while (m0 < 2);
    int m1 = 0;
    do {
        field_FA1[((signed char)m1)] = m1;
        field_FA3[((signed char)m1)] = 0;
        field_FA8[((signed char)m1)] = 0;
        field_FB0[((signed char)m1)] = 0;
        field_FB8[((signed char)m1)] = 0;
        field_FC0[((signed char)m1)] = 0;
        field_FC8[((signed char)m1)] = 0;
        field_FD0[((signed char)m1)] = 0;
        field_FD8[((signed char)m1)] = 0;
        field_FE1[((signed char)m1)] = 0;
        field_FE4[((signed char)m1)] = -1.0f;
        field_FEC[((signed char)m1)] = -1.0f;
        m1 = ((signed char)(m1 + 1));
    } while (m1 < 2);
    field_FA0 = 0;
    field_FE0 = 0;
    return 1;
}
