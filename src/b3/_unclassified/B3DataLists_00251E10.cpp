// CB3TrackList::DoesTrackExist(unsigned long) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3DataLists.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (bool return; body is the inlined GetTrackIndexFromID loop (in-class inline here; the real one is out-of-line at 0x2518E0, beware redefinition on TU merge): return GetTrackIndexFromID(p0) >= 0).

class CB3TrackList {
public:
    bool DoesTrackExist(unsigned long p0);
    int GetTrackIndexFromID(unsigned long p0) {
        for (int i = 0; i < field_4; i++) {
            if (field_408[i] == p0) {
                return i;
            }
        }
        return -1;
    }

    unsigned char pad_0[0x4];
    int field_4;
    unsigned char pad_8[0x400];
    unsigned long field_408[1];
};

// 0x00251E10
bool CB3TrackList::DoesTrackExist(unsigned long p0)
{
    return GetTrackIndexFromID(p0) >= 0;
}
