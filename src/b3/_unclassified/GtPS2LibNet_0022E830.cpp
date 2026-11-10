// CGtPS2LibNet::ChangePort(int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtPS2LibNet.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).

class CGtPS2LibNet;
struct UnkStruct_0022E830_1;

struct UnkStruct_0022E830_1 {
    unsigned char pad_0[0x1];
    unsigned char field_1;
    short field_2;
    int field_4;
    unsigned char pad_8[0x8];
};

class CGtPS2LibNet {
public:
    void ChangePort(int p0);

    unsigned char pad_0[0x4C];
    unsigned char field_4C;
    unsigned char pad_4D[0x3F];
    int field_8C;
    int field_90;
    unsigned char pad_94[0x14];
    int field_A8;
    int field_AC;
    unsigned char pad_B0[0x654];
    int field_704;
};

extern "C" void * memset(void *, int, unsigned int);
extern "C" void SuspendThread(int);
extern "C" void sceInsockShutdown(int, int);
extern "C" int func_00237320(int);
extern "C" int sceInsockSocket(int, int, int);
extern "C" void sceInsockBind(int, UnkStruct_0022E830_1 *, int);
extern "C" void ResumeThread(int);

// 0x0022E830
void CGtPS2LibNet::ChangePort(int p0)
{
    UnkStruct_0022E830_1 local;  // [G] the frame's one local (size: up to the frame top)
    if (field_704 == p0) return;
    SuspendThread(field_8C);
    SuspendThread(field_90);
    sceInsockShutdown(field_AC, 2);
    field_AC = -1;
    field_704 = p0;
    memset(&local, 0, 16);
    local.field_1 = 2;
    int r4 = func_00237320((p0 & 65535));
    local.field_2 = r4;
    local.field_4 = field_A8;
    int r5 = sceInsockSocket(2, 2, 0);
    field_AC = r5;
    sceInsockBind(field_AC, &local, 16);
    field_4C = 1;
    ResumeThread(field_8C);
    ResumeThread(field_90);
}
