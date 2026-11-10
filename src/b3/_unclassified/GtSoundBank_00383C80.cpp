// CGtSoundBank::LoadAsync(const char*,RwaSPU2Output*,RwaWaveDictLoader*,void*,int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundBank.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (mwperm: 'int field_3A0;' -> 'unsigned int field_3A0;'; 'int r = RwaWaveDictLoaderUpdate(loader); switch (r) { case 0' -> 'int r = RwaWaveDictLoaderUpdate(loader); switch (r) { case 0x30: case 0x50: case'; 'field_398 = loader->field_0; unsigned int n = RwaWaveDictGet' -> '').

#include "b3/classes/CGtSoundWave.h"
struct RwaSPU2Output;
struct RwaWaveDictLoader {
    int field_0;
    unsigned char pad_4[0x28];
    int field_2C;
};
extern "C" int RwaWaveDictReadAsync(const char *, int, int, int, int, int, int, RwaWaveDictLoader *);
extern "C" char * strcpy(char *, const char *);
extern "C" int RwaWaveDictLoaderUpdate(RwaWaveDictLoader *);
extern "C" int RwaWaveDictGetWaveCount(int);
extern "C" RwaSPU2Wave * RwaWaveDictFindWaveByIndex(int, int);
extern "C" void RwaWaveDictLoaderInitialise(RwaWaveDictLoader *);
class CGtSoundBank {
public:
    int LoadAsync(const char *, RwaSPU2Output *, RwaWaveDictLoader *, void *, int);
    CGtSoundWave field_0[1];
    unsigned char pad_10[0x360];
    char field_370[0x28];
    int field_398;
    int field_39C;
    unsigned int field_3A0;
    int field_3A4;
    unsigned char pad_3A8;
    signed char field_3A9;
    unsigned char pad_3AA;
    unsigned char field_3AB;
};
// 0x00383C80
int CGtSoundBank::LoadAsync(const char *name, RwaSPU2Output *out, RwaWaveDictLoader *loader, void *buf, int size)
{
    switch (field_3A4) {
    case 1:
        field_3AB = 0;
        field_3A0 = size;
        if (field_39C == 0) {
            field_39C = (int)buf;
        }
    case 2:
        RwaWaveDictReadAsync(name, field_39C, field_3A0, 0, 0, 0, 0x20000, loader);
        strcpy(field_370, name);
        {
            int st = loader->field_2C;
            if (st == 2) {
                field_3A4 = 2;
            } else if (st != 1) {
                field_3A4 = 0x10;
            }
        }
        break;
    case 0x10: {
            int r = RwaWaveDictLoaderUpdate(loader);
            switch (r) {
            case 0x30:
            case 0x50:
            case 0x70:
                return 0;
            case 0x100:
                field_3A4 = 0x100;
                break;
            }
            field_398 = loader->field_0;
            unsigned int n = RwaWaveDictGetWaveCount(field_398);
            for (unsigned int i = 0; i < n; i++) {
                field_0[i].Construct(RwaWaveDictFindWaveByIndex(field_398, i));
            }
            field_3A9 = n;
            if (field_3A9 > 0) {
                bool sorted;
                do {
                    sorted = true;
                    for (int j = 0; j < field_3A9 - 1; j++) {
                        CGtSoundWave *b = &field_0[j + 1];
                        CGtSoundWave *a = &field_0[j];
                        unsigned long x = a->field_0;
                        unsigned long y = b->field_0;
                        if (x > y) {
                            RwaSPU2Wave *t = a->field_8;
                            a->field_0 = y;
                            a->field_8 = b->field_8;
                            b->field_0 = x;
                            b->field_8 = t;
                            sorted = false;
                        }
                    }
                } while (!sorted);
            }
            RwaWaveDictLoaderInitialise(loader);
        }
    case 0x100:
        return 1;
    }
    return 0;
}
