// CGtNetworkHeadset::ReceiveStatusMessageRequestingTalk(int,int,EHeadsetTalkControlStatus,unsigned short) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtNetworkHeadset.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a123: 'int pl; bool all = true; for (pl=0;...)' fixes s4/s5; jtbl OK).

enum EHeadsetTalkControlStatus { UnkEnum_HTCS_0 };
struct UnkStruct_BFE70_pm { unsigned char pad_0[0x28]; int field_28; };

class CGtNetworkHeadset {
public:
    void ReceiveStatusMessageRequestingTalk(int, int, EHeadsetTalkControlStatus, unsigned short);
    void SetStatusToSend(EHeadsetTalkControlStatus, int);
    void ChangeControlStateToOtherPlayerTalking(int, unsigned short);

    unsigned char pad_0[8];
    int field_8;
    unsigned char pad_C[0x810];
    int field_81C;
    int field_820;
    unsigned char pad_824[4];
    unsigned char field_828;
    unsigned char pad_829[0x793F];
    unsigned char field_8168;
    unsigned char field_8169;
    unsigned char field_816A;
    unsigned char pad_816B[0xD];
    float field_8178;
    float field_817C;
    int field_8180;
    int field_8184;
    int field_8188;
    int field_818C[8];
    int field_81AC;
    unsigned char pad_81B0[0x24];
    int field_81D4;
    UnkStruct_BFE70_pm * field_81D8;
};

extern "C" void * func_002366D0(UnkStruct_BFE70_pm *, int);
extern "C" int func_0022FBB0(void *);
extern "C" int GetMyPlayerID__23CGtNetworkPlayerManagerCFv(void *);

// 0x002BFE70
void CGtNetworkHeadset::ReceiveStatusMessageRequestingTalk(int p0, int p1, EHeadsetTalkControlStatus p2, unsigned short p3)
{
    switch ((int)p2) {
    case 0: case 4: case 5:
        break;
    case 1:
        SetStatusToSend((EHeadsetTalkControlStatus)2, p1);
        break;
    case 2:
        SetStatusToSend((EHeadsetTalkControlStatus)5, -1);
        field_8 = 0;
        field_8184 = 0;
        break;
    case 3: {
        int n = field_81AC;
        int i = 0;
        for (; i < n; i++) {
            if (field_818C[i] == p1) {
                break;
            }
        }
        if (i == n && n < 8) {
            field_818C[n] = p1;
            field_81AC = field_81AC + 1;
        }
        int pl;
        bool all = true;
        for (pl = 0; pl < field_81D8->field_28; pl++) {
            void * q = func_002366D0(field_81D8, pl);
            if (q != 0) {
                int j = 0;
                for (; j < 8; j++) {
                    int v = field_818C[j];
                    if (v == func_0022FBB0(q)) {
                        break;
                    }
                }
                if (j == 8) {
                    all = false;
                    break;
                }
            }
        }
        if (all) {
            int id = GetMyPlayerID__23CGtNetworkPlayerManagerCFv(field_81D8);
            field_828 = 1;
            field_81C = 0;
            field_820 = 0;
            field_81D4 = id;
            field_8178 = field_817C;
            field_816A = 1;
            SetStatusToSend((EHeadsetTalkControlStatus)6, -1);
            field_8 = 2;
            field_8184 = 0;
        }
        break;
    }
    case 6:
        ChangeControlStateToOtherPlayerTalking(p1, p3);
        break;
    }
}
