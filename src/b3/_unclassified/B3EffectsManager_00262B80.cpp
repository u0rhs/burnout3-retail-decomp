// CB3EffectsManager::Destruct() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3EffectsManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CB3DebrisRenderer;
class CB3EffectsManager;
class CB3ParticleRenderer;
class CB3SparkRenderer;
class CB3TrailSystem;
struct UnkStruct_00262B80_e0;
struct UnkStruct_00262B80_e1;
struct UnkStruct_00262B80_e2;
struct UnkStruct_00262B80_e3;
struct UnkStruct_00262B80_e4;
struct UnkStruct_D_01EA4BB0;

class CB3TrailSystem {
public:
    void Destruct();
};

class CB3DebrisRenderer {
public:
    static void Destruct();
};

class CB3ParticleRenderer {
public:
    static void Destruct();
};

class CB3SparkRenderer {
public:
    static void Destruct();
};

struct UnkStruct_D_01EA4BB0 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00262B80_e0 {
    unsigned char pad_0[0x34];
};

struct UnkStruct_00262B80_e1 {
    unsigned char pad_0[0x30];
};

struct UnkStruct_00262B80_e2 {
    unsigned char pad_0[0x150];
};

struct UnkStruct_00262B80_e3 {
    unsigned char pad_0[0x40];
};

struct UnkStruct_00262B80_e4 {
    unsigned char pad_0[0xA8];
};

class CB3EffectsManager {
public:
    void Destruct();

    UnkStruct_00262B80_e0 field_0[1];  // [G] element count unknown
    unsigned char pad_34[0x25CC];
    CB3TrailSystem field_2600;
};

extern UnkStruct_D_01EA4BB0 D_01EA4BB0;

extern "C" void Destruct__21CB3CoronaDynamicArrayFv(void *);  // CB3CoronaDynamicArray::Destruct()
extern "C" void Destruct__14CB3DebrisArrayFv(void *);  // CB3DebrisArray::Destruct()
extern "C" void Destruct__16CB3ParticleArrayFv(void *);  // CB3ParticleArray::Destruct()
extern "C" void Destruct__15CB3PopcornArrayFv(void *);  // CB3PopcornArray::Destruct()
extern "C" void Destruct__13CB3SparkArrayFv(void *);  // CB3SparkArray::Destruct()
extern "C" void func_0039AD70(void *);
extern "C" void func_00375E80(void *);

// 0x00262B80
void CB3EffectsManager::Destruct()
{
    func_0039AD70(&D_01EA4BB0);
    for (int i = 0; (i < 3); i++) {
        Destruct__21CB3CoronaDynamicArrayFv(((char *)&field_0[i] + 0xC));
    }
    for (int i1 = 0; (i1 < 4); i1++) {
        Destruct__14CB3DebrisArrayFv(((char *)((char *)this + ((i1 * 3) << 4)) + 0xB0));
    }
    for (int i2 = 0; (i2 < 24); i2++) {
        Destruct__16CB3ParticleArrayFv(((char *)((char *)this + ((i2 * 21) << 4)) + 0x170));
    }
    for (int i3 = 0; (i3 < 4); i3++) {
        Destruct__15CB3PopcornArrayFv(((char *)((char *)this + (i3 << 6)) + 0x20F0));
    }
    for (int i4 = 0; (i4 < 6); i4++) {
        Destruct__13CB3SparkArrayFv(((char *)((char *)this + ((i4 * 21) << 3)) + 0x21F0));
    }
    field_2600.Destruct();
    func_00375E80(((char *)this + 0x16C80));
    CB3DebrisRenderer::Destruct();
    CB3ParticleRenderer::Destruct();
    CB3SparkRenderer::Destruct();
}
