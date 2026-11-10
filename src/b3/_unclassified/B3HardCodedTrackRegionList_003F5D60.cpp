// CB3HardCodedTrackRegionList::GetTrackRegionString(EB3TrackRegion,bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (medium); file: research/retail_names.csv -> B3HardCodedTrackRegionList.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (switch cases in ascending source order, ?: with int p1).

extern "C" int GetTrackRegionString__27CB3HardCodedTrackRegionListF14EB3TrackRegionb(int p0, int p1)
{
    switch (p0) {
    case 0: return p1 != 0 ? 0x190 : 0x2E1;
    case 1: return p1 != 0 ? 0x191 : 0x2E2;
    case 2: return p1 != 0 ? 0x192 : 0x2E3;
    }
    return 0;
}
