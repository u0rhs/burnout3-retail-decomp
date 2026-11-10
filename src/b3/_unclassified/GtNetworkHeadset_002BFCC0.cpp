// CGtNetworkHeadset::ReceiveStatusMessageOtherPlayerTalking(int,int,EHeadsetTalkControlStatus,unsigned short) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtNetworkHeadset.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (explicit empty cases for table, no default; != && cond with reset in else).

enum EHeadsetTalkControlStatus {};
class CGtNetworkHeadset {
public:
    void SetStatusToSend(EHeadsetTalkControlStatus status, int p1);
    void ChangeControlStateToOtherPlayerTalking(int p0, unsigned short p1);
    void ReceiveStatusMessageOtherPlayerTalking(int p0, int p1, EHeadsetTalkControlStatus status, unsigned short p3);
    void ReceiveStatusMessageOtherPlayerRequestingTalk(int p0, int p1, EHeadsetTalkControlStatus status, unsigned short p3);
    unsigned char pad_0[0x8];
    int field_8;
    unsigned char pad_C[0x818];
    int field_824;
    unsigned char pad_828[0x78F8];
    int field_8120;
    unsigned char pad_8124[0x3C];
    int field_8160_pad;
    int field_8164;
    unsigned char pad_8168[0x1C];
    int field_8184;
    int field_8188;
    unsigned char pad_818C[0x48];
    int field_81D4;
    unsigned char pad_81D8[0x8C];
};
// 0x002BFCC0
void CGtNetworkHeadset::ReceiveStatusMessageOtherPlayerTalking(int p0, int p1, EHeadsetTalkControlStatus status, unsigned short p3)
{
    switch ((int)status) {
    case 0: case 2: case 3: case 5: case 6:
        break;
    case 1:
        SetStatusToSend((EHeadsetTalkControlStatus)2, p1);
        break;
    case 4:
        if (field_81D4 != p1) return;
        if (field_8164 != -1 && field_8120 != 0) {
            field_824 = p3;
        } else {
            field_81D4 = -1;
            field_8188 = -1;
            field_8120 = 0;
            field_8164 = -1;
            field_8 = 0;
            field_8184 = 0;
        }
        break;
    }
}
