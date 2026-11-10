// NONMATCHING: HeadsetControlMessageArrivedCallback__17CGtNetworkHeadsetFP17CGtNetworkMessageiPv -- retail 119 / ours 119 instructions, 22 in changed runs
// audit1 (2026-11-01): layout: pad_C was 4 short, field_8184/8188/81D8 read 4 low [C] retail 0x2C0118 (behaviour_audit) | Before: near24 (28->24): assignment order s3=b, s2=a, s0=field_C, s1=field_4 fixes s2/s3 (declaration order inert). Left: field_4/field_C swap s0/s1 -- retail gives m's register s0 to field_C (lhu s0,12(s0)); all 24 assignment orders, ushort/int, mm placement tried
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)


// NONMATCHING: HeadsetControlMessageArrivedCallback__17CGtNetworkHeadsetFP17CGtNetworkMessageiPv -- retail 119 / ours 119 instructions, 28 in changed runs
// a251: layout/jtbl exact (119 instrs); only s0-s3 register assignment of 4 msg locals differs (28 off); decl order/types/load order tried
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

#include "b3/classes/EHeadsetTalkControlStatus.h"
class CGtNetworkPlayerManager { public: int GetMyPlayerID() const; };
struct UnkStruct_Msg { unsigned char pad_0[4]; int field_4; unsigned char pad_8[4]; unsigned short field_C; };
class CGtNetworkMessage;
extern "C" int func_002C1F70(void *, int *, unsigned short *);
class CGtNetworkHeadset {
public:
    static void HeadsetControlMessageArrivedCallback(CGtNetworkMessage *, int, void *);
    void SetStatusToSend(EHeadsetTalkControlStatus, int);
    void ChangeControlStateToOtherPlayerTalking(int, unsigned short);
    void ReceiveStatusMessageRequestingTalk(int, int, EHeadsetTalkControlStatus, unsigned short);
    void ReceiveStatusMessageOtherPlayerRequestingTalk(int, int, EHeadsetTalkControlStatus, unsigned short);
    void ReceiveStatusMessageOtherPlayerTalking(int, int, EHeadsetTalkControlStatus, unsigned short);
    unsigned char pad_0[8];
    int field_8;
    unsigned char pad_C[0x8178];   // audit1: was 0x8174 (field_8184..field_81D8 4 low) [C] retail 0x2C0118 lw 0x81D8
    int field_8184;
    int field_8188;
    unsigned char pad_818C[0x4C];
    CGtNetworkPlayerManager *field_81D8;
};
void CGtNetworkHeadset::HeadsetControlMessageArrivedCallback(CGtNetworkMessage *m, int, void *pv)
{
    CGtNetworkHeadset *h = (CGtNetworkHeadset *)pv;
    int a;
    unsigned short b;
    unsigned short s3;
    int s2;
    int s1;
    int s0;
    if (func_002C1F70(m, &a, &b)) {
    UnkStruct_Msg *mm = (UnkStruct_Msg *)m;
    s3 = b;
    s2 = a;
    s0 = mm->field_C;
    s1 = mm->field_4;
    if (h->field_81D8->GetMyPlayerID() >= 0) {
    switch (h->field_8) {
    case 0:
        switch (s2) {
        case 6: h->ChangeControlStateToOtherPlayerTalking(s1, s3); break;
        case 1:
            h->field_8188 = s1;
            h->SetStatusToSend((EHeadsetTalkControlStatus)3, s1);
            h->field_8 = 3;
            h->field_8184 = 0;
            break;
        case 0: case 2: case 3: case 4: case 5: break;
        }
        break;
    case 1: h->ReceiveStatusMessageRequestingTalk(s0, s1, (EHeadsetTalkControlStatus)s2, s3); break;
    case 2:
        switch (s2) {
        case 1: h->SetStatusToSend((EHeadsetTalkControlStatus)2, s1); break;
        case 0: case 2: case 3: case 4: case 5: case 6: break;
        }
        break;
    case 3: h->ReceiveStatusMessageOtherPlayerRequestingTalk(s0, s1, (EHeadsetTalkControlStatus)s2, s3); break;
    case 4: h->ReceiveStatusMessageOtherPlayerTalking(s0, s1, (EHeadsetTalkControlStatus)s2, s3); break;
    }
    }}
}
