// CB3SoundDistortion::Construct(RwaSPU2Output*,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundDistPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (buffer field_1900[0x400] and client struct field_1D10 as members (no CSE); push as *((int*&)field_1D04)++; real SifRpc arg counts).

// CB3SoundDistortion::Construct(RwaSPU2Output*,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundDistPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class RwaSPU2Output;
enum EDSPType {};

class CB3SoundDSPDataBlock;
class CB3SoundDistortion;
struct UnkStruct_002FD0E0_1;
struct UnkStruct_002FD0E0_2;
struct UnkStruct_002FD0E0_3;
struct UnkStruct_002FD0E0_e0;
struct UnkStruct_func_002FC530;

class CB3SoundDSPDataBlock {
public:
    void SetType(EDSPType);
    void Reset();
};

struct UnkStruct_002FD0E0_1 {
    int field_0;
};

struct UnkStruct_002FD0E0_2 {
    void * field_0;
    int field_4;
};

struct UnkStruct_002FD0E0_3 {
    int field_0;
};

struct UnkStruct_002FD0E0_cd {
    unsigned char pad_0[0x24];
    int field_24;
};

struct UnkStruct_func_002FC530 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_002FD0E0_e0 {
    unsigned char pad_0[0x110];
};

class CB3SoundDistortion {
public:
    void Construct(RwaSPU2Output* p0, int p1);

    UnkStruct_002FD0E0_e0 field_0[1];  // [G] element count unknown
    CB3SoundDSPDataBlock field_110;
    unsigned char pad_111[0x172F];
    int field_1840;
    int field_1844;
    int field_1848;
    unsigned char field_184C;
    unsigned char pad_184D[0x2];
    unsigned char field_184F;
    unsigned char pad_1850[0xA8];
    float field_18F8;
    float field_18FC;
    unsigned char field_1900[0x400];
    UnkStruct_002FD0E0_1 * field_1D00;
    UnkStruct_002FD0E0_2 * field_1D04;
    int field_1D08;
    int field_1D0C;
    UnkStruct_002FD0E0_cd field_1D10;
};

extern UnkStruct_func_002FC530 func_002FC530;

extern "C" void Construct__20CB3SoundDSPDataBlockFv(void *);  // CB3SoundDSPDataBlock::Construct()
extern "C" void SetType__20CB3SoundDSPDataBlockF8EDSPType(void *, EDSPType);  // CB3SoundDSPDataBlock::SetType(EDSPType)
extern "C" void Reset__20CB3SoundDSPDataBlockFv(void *);  // CB3SoundDSPDataBlock::Reset()
extern "C" void sceSifInitRpc(int);
extern "C" void sceSifBindRpc(void *, int, int);
extern "C" void sceSifAddCmdHandler(int, void *, CB3SoundDistortion *);
extern "C" int sceSifCheckStatRpc(void *);
extern "C" void sceSifCallRpc(void *, int, int, void *, int, void *, int, void *, void *);

// 0x002FD0E0
void CB3SoundDistortion::Construct(RwaSPU2Output* p0, int p1)
{
    field_184C = 0;
    field_184F = 0;
    sceSifInitRpc(0);
    do {
        sceSifBindRpc(&field_1D10, 0x150276, 0);
    } while (field_1D10.field_24 == 0);
    sceSifAddCmdHandler(6, &func_002FC530, this);
    field_1D00 = (UnkStruct_002FD0E0_1 *)&field_1900[0];
    field_1D04 = (UnkStruct_002FD0E0_2 *)&field_1900[4];
    field_1D08 = 0;
    field_1D0C = 0;
    field_1D00->field_0 = 0;
    *(((int *&)field_1D04)++) = 32768;
    
    UnkStruct_002FD0E0_2 * t1 = field_1D04++;
    field_1D00->field_0 = (field_1D00->field_0 + 1);
    t1->field_0 = ((char *)this + 0x240);
    t1->field_4 = p1;
    if (field_1D00->field_0 != 0) {
        if (sceSifCheckStatRpc(&field_1D10) != 1) {
            sceSifCallRpc(&field_1D10, 0x150276, 0, field_1900, 1024, 0, 0, 0, 0);
        }
        field_1D00->field_0 = 0;
        field_1D04 = (UnkStruct_002FD0E0_2 *)&field_1900[4];
    }
    for (int i = 0; i < 2; i++) {
        Construct__20CB3SoundDSPDataBlockFv(&field_0[i]);
    }
    field_18F8 = 50.0f;
    field_18FC = 10.0f;
    SetType__20CB3SoundDSPDataBlockF8EDSPType(this, (EDSPType)0);
    field_110.SetType((EDSPType)0);
    Reset__20CB3SoundDSPDataBlockFv(this);
    field_110.Reset();
    field_1840 = 0x10000;
    field_1844 = 0x10000;
    field_1848 = 0x10000;
}
