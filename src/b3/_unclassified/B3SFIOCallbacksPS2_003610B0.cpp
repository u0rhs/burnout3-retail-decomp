// CB3SFIOCallbacks::SFIOWriteCallback(int,const void*,unsigned int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SFIOCallbacksPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (a67: static SFIO write callback; buffer=p1,size=p2; goto err to share the error block (FAKEMATCH-ish shape [G])).

// [G] explicit goto err: the only shape found that shares retail's single error block (return-based and tail-duplicated forms leave 6-9 instrs). static callback: a1=buffer, a2=size.
class CB3SFIOCallbacks;
class CMemoryDevicePS2;
struct UnkStruct_003610B0_0;
struct UnkStruct_003610B0_e0;
struct UnkStruct_D_01EA4020;

class CMemoryDevicePS2 {
public:
    int Write(const char*, unsigned int, unsigned int);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_003610B0_0 {
    int field_0;
};

struct UnkStruct_003610B0_e0 {
    unsigned char pad_0[0x1];
};

struct UnkStruct_D_01EA4020 {
    UnkStruct_003610B0_e0 field_0[1];  // [G] element count unknown
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3SFIOCallbacks {
public:
    static void SFIOWriteCallback(int p0, const void* p1, unsigned int p2);
    static int gmnOffset;
    static int gmeError;
    static int gmeLastOperation;
    static int gmeProcess;
};

extern CMemoryDevicePS2 D_005185A0;
extern UnkStruct_D_01EA4020 D_01EA4020;

extern "C" void * memcpy(void *, const void *, unsigned int);
extern "C" int SLoginStatePreviousGet(UnkStruct_003610B0_0 *);

// 0x003610B0
void CB3SFIOCallbacks::SFIOWriteCallback(int p0, const void* p1, unsigned int p2)
{
    UnkStruct_003610B0_0 local;
    int r;
    SLoginStatePreviousGet(&local);
    if (local.field_0 == 0 && (gmnOffset == 0 || gmnOffset == 29) && p2 == 29) {
        memcpy(&D_01EA4020.field_0[gmnOffset], p1, p2);
        r = D_005185A0.Write((const char*)&D_01EA4020, 58, 0);
        if (r != 0) goto err;
        gmeLastOperation = 0;
        gmeProcess = 2;
        gmeError = 4;
        return;
    }
    r = D_005185A0.Write((const char*)p1, p2, gmnOffset);
    if (r != 0) goto err;
    gmeLastOperation = 0;
        gmeProcess = 2;
        gmeError = 4;
    return;
err:
    gmeError = 0;
        gmeLastOperation = 8;
        gmeProcess = 1;
}
