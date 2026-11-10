// CB3NetworkManager::GetAdapterErrorString(int) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3NetworkManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (switch cases in block address order).

enum EGtBuddyErrorCodes { E0 };
class CB3NetworkManager {
public:
    int GetBuddyErrorString(EGtBuddyErrorCodes e);
    int GetAdapterErrorString(int e);
};
// 0x0026D1E0
int CB3NetworkManager::GetAdapterErrorString(int e)
{
    switch (e) {
    case 4: return 0x67;
    case 5: return 0x6A;
    case 3: return 0x68;
    case 2: return 0x69;
    case 6: return 0x6A;
    case 8: return 0x6B;
    case 9: return 0x6C;
    case 10: return 0xB6;
    case 7: return 0x6D;
    default: return 0x452;
    }
}
