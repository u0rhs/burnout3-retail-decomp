// CB3SoundTrafficManager::GetNextHornVariant(bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3SoundTrafficManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (name buffer split into 3 locals (outc, cnt declared first, name[14]) stops &F CSE; unsigned %).

struct UnkStruct_00276B00 { unsigned char pad_0[0xD1]; unsigned char field_D1; unsigned char field_D2; };
extern "C" void func_0021AB40(unsigned long, char *);
extern "C" int AsciiVariantToInt__13CGtSoundUtilsFcRUc(char, unsigned char &);
extern "C" int IntToAsciiVariant__13CGtSoundUtilsFUcRc(unsigned char, char &);
extern "C" unsigned long GtIDCompress__FPCc(void *);
extern "C" unsigned long GetNextHornVariant__22CB3SoundTrafficManagerFb(UnkStruct_00276B00 *self, bool p0)
{
    char outc;
    unsigned char cnt;
    char name[14];
    func_0021AB40(p0 ? 0xBEADD71AAF0A9F27UL : 0xBEC06656E82A9F25UL, name);
    AsciiVariantToInt__13CGtSoundUtilsFcRUc(name[0xB], cnt);
    if (p0) {
        self->field_D1 = self->field_D1 + 1;
        self->field_D1 = (unsigned int)self->field_D1 % (unsigned int)cnt;
        IntToAsciiVariant__13CGtSoundUtilsFUcRc(self->field_D1 + 1, outc);
    } else {
        self->field_D2 = self->field_D2 + 1;
        self->field_D2 = (unsigned int)self->field_D2 % (unsigned int)cnt;
        IntToAsciiVariant__13CGtSoundUtilsFUcRc(self->field_D2 + 1, outc);
    }
    name[0xA] = outc;
    return GtIDCompress__FPCc(name);
}
