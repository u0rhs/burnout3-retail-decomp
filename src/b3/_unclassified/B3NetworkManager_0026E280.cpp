// CB3NetworkManager::ReplayBodyMessageDeliveredCallback(bool,CGtNetworkMessage*,void*) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3NetworkManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a73: extern C def with static; bool diamond inline w/ || ; return after if body).

// [G] func_0026E280_inl1 is a 16-bit wraparound sequence-number "newer than" test (thirds at 0x5555/0xAAAB); placeholder inline, name unknown.
// No DNAT row for this function (research/proto/new_names.csv).
struct UnkStruct_Rbm_msg { unsigned char pad_0[0x8]; int field_8; unsigned short field_C; };
struct UnkStruct_Rbm_player { unsigned char pad_0[0x4F6]; unsigned short field_4F6; };
extern "C" UnkStruct_Rbm_player * GetPlayerByID__23CGtNetworkPlayerManagerCFi(void *, int);

static inline bool func_0026E280_inl1(int a, int b)
{
    bool v;
    if (a < 0x5555 && b > 0xAAAA) {
        v = true;
    } else if (b >= 0x5555 || a <= 0xAAAA) {
        if (b < a) v = true; else v = false;
    } else {
        v = false;
    }
    return v;
}

extern "C" void ReplayBodyMessageDeliveredCallback__17CB3NetworkManagerFbP17CGtNetworkMessagePv(bool p0, UnkStruct_Rbm_msg * p1, void * p2)
{
    UnkStruct_Rbm_player * r0 = GetPlayerByID__23CGtNetworkPlayerManagerCFi(p2, p1->field_8);
    if (r0 != 0) {
        if (r0->field_4F6 == 0xFFFF || func_0026E280_inl1(p1->field_C, r0->field_4F6)) {
            r0->field_4F6 = p1->field_C;
        }
        return;
    }
}
