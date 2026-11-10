// CGtSoundBankManager::LoadBank(const char*,bool,bool,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundBankManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a130: goto none for out-of-line failure return; j reused as slot address; strlen returns unsigned int; bool p2 -> bool param).

struct UnkStruct_00383FF0_b {
    unsigned char pad_0[0x3A4];
    int field_3A4;
    unsigned char pad_3A8[3];
    unsigned char field_3AB;
};
struct UnkStruct_00383FF0_n {
    UnkStruct_00383FF0_n * field_0;
    unsigned char pad_4[4];
    UnkStruct_00383FF0_b field_8;
};
struct UnkStruct_00383FF0_s {
    int field_0;
    int field_4;
    unsigned char field_8;
    unsigned char pad_9[3];
};
class CGtSoundBankManager {
public:
    int LoadBank(const char *, bool, bool, int);
    int field_0;
    unsigned char pad_4[8];
    UnkStruct_00383FF0_s * field_C;
    int field_10;
    unsigned char pad_14[4];
    int field_18;
    unsigned char pad_1C[0x18];
    unsigned char field_34[4];
    UnkStruct_00383FF0_n * field_38;
    void * field_3C;
};
extern "C" unsigned int strlen(const char *);
extern "C" int strcasecmp(const char *, const char *);
extern "C" char * func_00383C00(void *);
extern "C" int GetReferenceCount__12CGtSoundBankFv(void *);
extern "C" void SetReferenceCount__12CGtSoundBankFi(void *, int);
extern "C" void func_00383EC0(void *, bool);
extern "C" int LoadAsync__12CGtSoundBankFPCcP13RwaSPU2OutputP17RwaWaveDictLoaderPvi(void *, const char *, void *, void *, void *, int);
extern "C" void * AddLink__11CGtFreeListFv(void *);
extern "C" int RwaSPU2WaveRAMGetFree();
// 0x003840C0
int CGtSoundBankManager::LoadBank(const char *name, bool p1, bool p2, int p3)
{
    unsigned int n = strlen(name);
    unsigned int i;
    char *p = (char *)name;
    for (i = 0; i < n; i++) {
        if (*p == '/') {
            *p = '\\';
        }
        p++;
    }
    UnkStruct_00383FF0_b *bank;
    UnkStruct_00383FF0_n *node;
    for (node = field_38; node != 0; node = node->field_0) {
        bank = &node->field_8;
        if (strcasecmp(func_00383C00(bank), name) == 0) {
            goto found;
        }
    }
    bank = 0;
found:
    if (bank != 0) {
        if (bank->field_3AB != 0) {
            SetReferenceCount__12CGtSoundBankFi(bank, GetReferenceCount__12CGtSoundBankFv(bank) + 1);
        } else {
            if (bank->field_3A4 != 0x100) {
                bank->field_3AB = LoadAsync__12CGtSoundBankFPCcP13RwaSPU2OutputP17RwaWaveDictLoaderPvi(bank, name, field_3C, (void *)(field_0), (void *)(0), p3);
            } else {
                bank->field_3AB = 1;
            }
            if (bank->field_3AB == 0) {
                return 0;
            }
            func_00383EC0(bank, p2);
        }
        return (int)bank;
    }
    UnkStruct_00383FF0_b *other;
    for (node = field_38; node != 0; node = node->field_0) {
        other = &node->field_8;
        if ((other->field_3A4 & 0x100) == 0) {
            goto have;
        }
    }
    other = 0;
have:
    if (other != 0) {
        LoadAsync__12CGtSoundBankFPCcP13RwaSPU2OutputP17RwaWaveDictLoaderPvi(other, 0, field_3C, (void *)(field_0), (void *)(0), 0);
        return 0;
    }
    node = (UnkStruct_00383FF0_n *)AddLink__11CGtFreeListFv(&field_34);
    if (node == 0) {
        goto none;  // [G] goto: retail keeps the failure return out of line after the call
    }
    field_10 = RwaSPU2WaveRAMGetFree();
    UnkStruct_00383FF0_b *nb = &node->field_8;
    int cnt = field_18;
    int j;
    for (j = 0; j < cnt; j++) {
        if (p3 == field_C[j].field_4 && field_C[j].field_8 == 0) {
            field_C[j].field_8 = 1;
            j = field_C[j].field_0;
            goto call;
        }
    }
    j = 0;
call:
    LoadAsync__12CGtSoundBankFPCcP13RwaSPU2OutputP17RwaWaveDictLoaderPvi(nb, name, field_3C, (void *)(field_0), (void *)(j), p3);
    return 0;
none:
    return 0;
}
