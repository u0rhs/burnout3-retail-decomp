// CGtSoundBankManager::FindWave(const unsigned long&,bool) const -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundBankManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (bank list walk; int returns (result returned as-is); bank at link+8).

class CGtSoundBank { public: int FindWave(const unsigned long &, bool) const; int IsGlobal(); };
struct UnkStruct_Link { UnkStruct_Link *next; int pad; CGtSoundBank bank; };
class CGtSoundBankManager {
public:
    int FindWave(const unsigned long &p0, bool p1) const;
    unsigned char pad_0[0x38];
    UnkStruct_Link *field_38;
};
// 0x00383F60
int CGtSoundBankManager::FindWave(const unsigned long &p0, bool p1) const
{
    UnkStruct_Link *l = field_38;
    while (l != 0) {
        CGtSoundBank *b = &l->bank;
        if (b->IsGlobal()) {
            int r = b->FindWave(p0, p1);
            if (r) return r;
        }
        l = l->next;
    }
    return 0;
}
