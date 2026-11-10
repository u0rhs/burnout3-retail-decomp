// CGtSoundBankManager::Construct(RwaSPU2Output*,int,CGtSoundWaveObjectBuffer*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundBankManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (first try; GtLListPoolCreateInMemory has 7th arg; ourGlobals+0x134 fn ptr alloc).

struct GtLListTag; struct GtLLLinkTag; struct GtLListPoolTag;
class CGtFreeListPool;
struct RwaSPU2Output; struct CGtSoundWaveObjectBuffer;
extern "C" void Construct__15CGtFreeListPoolFUiUiUiPCvPvUi(CGtFreeListPool*, unsigned int, unsigned int, unsigned int, const void*, void*, unsigned int);
extern "C" void Construct__11CGtFreeListFP15CGtFreeListPool(void *, void *);
extern "C" void *AddLink__11CGtFreeListFv(void *);
extern "C" void RemoveAllLinks__11CGtFreeListFv(void *);
extern "C" void func_00383F10(void *);
extern "C" int RwaWaveDictLoaderCreate(int);
extern "C" int sceSifAllocSysMemory(int, int, int);
extern "C" void RwaWaveDictSetWaveDataUploadBuffer(int, int);
struct UnkStruct_ourGlobals {
    unsigned char pad_0[0x134];
    void *(*field_134)(int, int);
};
extern UnkStruct_ourGlobals ourGlobals;
class CGtSoundBankManager {
public:
    void Construct(RwaSPU2Output *p0, int p1, CGtSoundWaveObjectBuffer *p2);
    int field_0;
    int field_4;
    unsigned char pad_8[0x4];
    CGtSoundWaveObjectBuffer *field_C;
    unsigned char pad_10[0x4];
    int field_14;
    int field_18;
    void *field_1C;
    unsigned char field_20[0x14];
    unsigned char field_34[0x8];
    RwaSPU2Output *field_3C;
};
// 0x00384460
void CGtSoundBankManager::Construct(RwaSPU2Output *p0, int p1, CGtSoundWaveObjectBuffer *p2)
{
    field_3C = p0;
    field_C = p2;
    field_18 = p1;
    field_14 = field_18 * 0x3C0 + 0x20;
    field_1C = ourGlobals.field_134(field_14, 0);
    Construct__15CGtFreeListPoolFUiUiUiPCvPvUi((CGtFreeListPool *)field_20, field_18, 0x3B0, 0x10, 0, field_1C, field_14);
    Construct__11CGtFreeListFP15CGtFreeListPool(field_34, field_20);
    for (int i = 0; i < field_18; i++) {
        func_00383F10((char *)AddLink__11CGtFreeListFv(field_34) + 8);
    }
    RemoveAllLinks__11CGtFreeListFv(field_34);
    field_0 = RwaWaveDictLoaderCreate(0);
    field_4 = sceSifAllocSysMemory(0, 0x4000, 0);
    RwaWaveDictSetWaveDataUploadBuffer(field_4, 0x4000);
}
