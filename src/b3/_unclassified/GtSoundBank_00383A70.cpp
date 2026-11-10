// CGtSoundBank::FindWave(const unsigned long&,bool) const -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundBank.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (near18: mid -= b - 1; as its own statement before the inlined random step, then mid += (a + x) % a).


struct UnkStruct_00383A70_w { unsigned long field_0; unsigned long field_8; };
struct UnkStruct_00383A70_rnd { int field_0; int field_4; };
extern "C" UnkStruct_00383A70_rnd _mRandom__13CGtSoundUtils;
extern "C" unsigned long func_0021AD60(unsigned long, int, int);
extern "C" void func_0021AB40(unsigned long, char *);
struct UnkStruct_00383A70_pad {
    int f;
    UnkStruct_00383A70_pad() {}
    ~UnkStruct_00383A70_pad() {}
};
class CGtSoundUtils {
public:
    static int AsciiVariantToInt(char, unsigned char &);
};
class CGtSoundBank {
public:
    UnkStruct_00383A70_w * FindWave(const unsigned long & id, bool variant) const;
    UnkStruct_00383A70_w field_0[1];
    unsigned char pad_10[0x399];
    signed char field_3A9;
};
// 0x00383A70
UnkStruct_00383A70_w * CGtSoundBank::FindWave(const unsigned long & id, bool variant) const
{
    unsigned long key = func_0021AD60(id, 0, 9);
    if (id == 0) {
        return 0;
    }
    if (field_3A9 == 0) {
        return 0;
    }
    int hi = field_3A9 - 1;
    int mid;
    int lo = 0;
    while (lo <= hi) {
        mid = (hi + lo) >> 1;
        unsigned long k = func_0021AD60(field_0[mid].field_0, 0, 9);
        if (key < k) {
            hi = mid - 1;
        } else if (k < key) {
            lo = mid + 1;
        } else {
            if (variant) {
                // [C] 13 bytes: func_0021AB40 writes out[0..12] (GtID.cpp: out[12] = 0); char[12] overran by one natively.
                // Retail: buf at sp+0x88 (0x383B60), buf[11]/buf[10] read at sp+0x93/0x92, next locals sp+0x9E/0x9F; 13..15
                // keep the object byte-identical (tiny_compile + obj_same), char[0x10] moves it to sp+0x80.
                char buf[13];
                unsigned char a;
                unsigned char b;
                UnkStruct_00383A70_pad pad;
                func_0021AB40(field_0[mid].field_0, buf);
                if (CGtSoundUtils::AsciiVariantToInt(buf[11], a) && CGtSoundUtils::AsciiVariantToInt(buf[10], b)) {
                    mid -= b - 1;
                    int x = _mRandom__13CGtSoundUtils.field_0;
                    x = (x << 16) + (x >> 16);
                    x += _mRandom__13CGtSoundUtils.field_4;
                    _mRandom__13CGtSoundUtils.field_4 += x;
                    _mRandom__13CGtSoundUtils.field_0 = x;
                    mid += (unsigned)(a + x) % a;
                }
            }
            return (UnkStruct_00383A70_w *)&field_0[mid];
        }
    }
    return 0;
}
