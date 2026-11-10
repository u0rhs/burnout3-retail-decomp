// CB3HardCodedTrackList::GetTrackString(int,bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3HardCodedTrackList.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (int p1 (not bool): no andi; p0>-1; != 0 ? 4FF:4FE -> movz).

extern int D_004CC580[];
extern int D_004CC610[];
extern "C" int GetTrackString__21CB3HardCodedTrackListFib(int p0, int p1)
{
    if (p0 > -1) {
        if (p1 != 0) return D_004CC580[p0];
        return D_004CC610[p0];
    }
    return p1 != 0 ? 0x4FF : 0x4FE;
}
