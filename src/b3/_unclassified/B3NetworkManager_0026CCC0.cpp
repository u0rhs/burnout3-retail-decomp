// CB3NetworkManager::GetBuddyErrorString(EGtBuddyErrorCodes) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3NetworkManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (every case own return in index order).

enum EGtBuddyErrorCodes { E0 };
class CB3NetworkManager {
public:
    int GetBuddyErrorString(EGtBuddyErrorCodes e);
    int GetAdapterErrorString(int e);
};
// 0x0026CCC0
int CB3NetworkManager::GetBuddyErrorString(EGtBuddyErrorCodes e)
{
    switch (e) {
    case 0: return 0x6D;
    case 1: return 0x6D;
    case 2: return 0x452;
    case 3: return 0x456;
    case 4: return 0x48F;
    case 5: return 0x6D;
    case 6: return 0x479;
    case 7: return 0x453;
    case 8: return 0x6D;
    case 9: return 0x6D;
    case 10: return 0x6D;
    case 11: return 0x6D;
    case 12: return 0x45B;
    case 13: return 0x480;
    case 14: return 0x4AC;
    case 15: return 0x6D;
    case 16: return 0x6D;
    case 17: return 0x6D;
    default: return 0x6D;
    }
}
