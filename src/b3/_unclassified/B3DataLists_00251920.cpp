// CB3TrackList::IsTrackRightHandDrive(unsigned long) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3DataLists.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (two inlined GetTrackIndexFromID calls (sibling 0x2518E0 body, declared inline in-class): if (<0) return true; return field_208[idx]!=0 (idx -1 reads field_204)).

class CB3TrackList;

class CB3TrackList {
public:
    bool IsTrackRightHandDrive(unsigned long p0);
    int GetTrackIndexFromID(unsigned long p0)
    {
        int t0 = field_4;
        for (int i = 0; (i < t0); i++) {
            if (field_408[i] == p0) {
                return i;
            }
        }
        return -1;
    }

    unsigned char pad_0[0x4];
    int field_4;
    unsigned char pad_8[0x1FC];
    int field_204;
    int field_208[1];  // [G] element count unknown
    unsigned char pad_20C[0x1FC];
    unsigned long field_408[1];  // [G] element count unknown
};

// 0x00251920
bool CB3TrackList::IsTrackRightHandDrive(unsigned long p0)
{
    if (GetTrackIndexFromID(p0) < 0) {
        return true;
    }
    return field_208[GetTrackIndexFromID(p0)] != 0;
}
