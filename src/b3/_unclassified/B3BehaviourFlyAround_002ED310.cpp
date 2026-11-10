// CB3BehaviourFlyAround::Construct(int,EB3FlyAroundType) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3BehaviourFlyAround.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (hand-written; D_00522660+i*0x27D0+0x12C6FC byte load shows as lui %hi(__moddi3+0x4C) (splat symbolised constant), via byte-offset cast).

extern "C" char * strcpy(char *, const char *);
extern "C" void Construct__18CB3CameraBehaviourFv(void *);  // CB3CameraBehaviour::Construct()
enum EB3FlyAroundType { EB3FlyAroundType_Unk0 };
struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x12C6FC];
    signed char field_12C6FC;
    unsigned char pad_12C6FD[0x27D0 - 1];
};
extern UnkStruct_D_00522660 D_00522660;
extern char D_004C3D18[];
extern char D_004C3D28[];
class CB3BehaviourFlyAround {
public:
    void Construct(int, EB3FlyAroundType);
    unsigned char pad_0[0x60];
    int field_60;
    int field_64;
    int field_68;
    unsigned char pad_6C[0x4];
    int field_70;
    unsigned char pad_74[0x4];
    char field_78[0x10];
    unsigned char field_88;
    unsigned char field_89;
};

// 0x002ED310
void CB3BehaviourFlyAround::Construct(int p0, EB3FlyAroundType p1)
{
    Construct__18CB3CameraBehaviourFv(this);
    field_64 = p0;
    field_68 = *((signed char *)&D_00522660 + field_64 * 0x27D0 + 0x12C6FC);
    field_70 = p1;
    if (field_64 == 0) {
        strcpy(field_78, D_004C3D18);
        field_60 = 0;
    } else {
        strcpy(field_78, D_004C3D28);
        field_60 = 0;
    }
    field_88 = 0;
    field_89 = 0;
}
