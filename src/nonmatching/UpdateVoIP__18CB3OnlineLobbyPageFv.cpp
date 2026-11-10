// NONMATCHING: UpdateVoIP__18CB3OnlineLobbyPageFv -- retail 229 / ours 231 instructions, 22 in changed runs
// a147: logic complete, 229 vs 231 instrs, 22 in changed runs. Remaining: (1) retail lays the 'pl = GetPlayerByID(..); if (pl == 0 && func_0041E930() != GetMyPlayerID()) skip' second condition INLINE after 'bnez v0,body' ; ours moves that cond2 block out of line to the function end (beqz v0,far ... bne; b body) for if/||/goto/bool/inline-helper forms alike; (2) the break-to-common 'changed = true' of cases 4/2 keeps 'b A14; nop' in retail, ours fills the delay slot with daddiu s0,1.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// Hand-written (a147).
struct UnkStruct_D_byte { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_float { float field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_int { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E32AE0 { unsigned char pad_0[8]; int field_8[1]; unsigned char pad_C[4]; };
struct UnkStruct_D_01E33A8C { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_player {
    unsigned char pad_0[0x4B0];
    unsigned char field_4B0;
    unsigned char pad_4B1[0x37];
    unsigned char field_4E8;
    unsigned char pad_4E9[0xD];
    unsigned char field_4F6[0xFA];
    unsigned char pad_5F0[0x654];
};
struct UnkStruct_row { void * field_0; void * field_4; void * field_8; unsigned char pad_C[0x3C]; };
class CB3OnlineLobbyPage {
public:
    void UpdateVoIP();
    unsigned char pad_0[0x188];
    UnkStruct_row field_188[6];
    unsigned char pad_338[0xB58];
    unsigned char field_E90[0x4E8];
    void * field_1378;
    unsigned char pad_137C[0x14];
    int field_1390;
    unsigned char pad_1394[8];
    float field_139C;
};
struct UnkStruct_Rec { unsigned char pad_0[0x12C]; };
struct UnkStruct_D_004F50C0 { UnkStruct_Rec field_0[1]; };
extern UnkStruct_D_004F50C0 D_004F50C0;
extern signed char D_004F6061[];
extern UnkStruct_D_01E33A8C D_01E33A8C;
extern UnkStruct_D_int D_01E32B08;
extern UnkStruct_D_01E32AE0 D_01E32AE0;
extern UnkStruct_D_float D_004F50A0;
extern char D_004C5008[];
extern "C" int func_0041E930(void *);
extern "C" int func_0041E900(void *);
extern "C" void func_0041E9C0(void *);
extern "C" void func_0041E9A0(void *);
extern "C" float func_0041E8D0(void *);
extern "C" UnkStruct_player * func_002366D0(void *, int);
extern "C" int GetMyPlayerID__23CGtNetworkPlayerManagerCFv(void *);
extern "C" void * GetPlayerByID__23CGtNetworkPlayerManagerCFi(void *, int);
extern "C" int GetPlayerIndexByID__23CGtNetworkPlayerManagerFi(void *, int);
extern "C" int Retrieve__27CB3NetworkHasHeadsetMessageFPUc(void *, unsigned char *);
extern "C" void Prepare__27CB3NetworkHasHeadsetMessageFUc(void *, unsigned char);
extern "C" int snprintf(char *, unsigned int, const char *, ...);
extern "C" void ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(char *, void *, int);
extern "C" double ceil(double);
extern "C" void RenderImageAndText__17CB3TableComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv(void *, void *, unsigned short *, void *, const void *);
extern "C" void GetImageAndTextSize__17CB3TableComponentFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv(void *, void *, void *);

static inline int func_00316840_inl1()
{
    int i;
    int n = 0;
    for (i = 0; i < D_01E32B08.field_0; i++) {
        if (D_01E32AE0.field_8[i] != 0) {
            n++;
        }
    }
    return n;
}

// 0x00316840
void CB3OnlineLobbyPage::UpdateVoIP()
{
    unsigned char uc;
    char buf[3];
    bool changed = false;
    char * ctrl = (char *)&D_004F50C0 + D_004F6061[0] * 0x12C + 0xD48;
    if (D_01E33A8C.field_0 != 0) {
        if (*(short *)(ctrl + 0x76) != 0) *(short *)(ctrl + 0x76) = 0;
    }
    if (func_00316840_inl1() > 0 && func_0041E930(&D_01E33A8C) < 0 && *(short *)(ctrl + 0x76) != 0) {
        func_0041E9C0(&D_01E33A8C);
    } else {
        if (func_0041E930(&D_01E33A8C) == GetMyPlayerID__23CGtNetworkPlayerManagerCFv(&D_01E32AE0) && *(short *)(ctrl + 0x76) == 0) {
            func_0041E9A0(&D_01E33A8C);
        } else if (func_0041E930(&D_01E33A8C) >= 0) {
            if (GetPlayerByID__23CGtNetworkPlayerManagerCFi(&D_01E32AE0, func_0041E930(&D_01E33A8C)) != 0
                || func_0041E930(&D_01E33A8C) == GetMyPlayerID__23CGtNetworkPlayerManagerCFv(&D_01E32AE0)) {
                int t = (int)ceil(func_0041E8D0(&D_01E33A8C));
                int idx = GetPlayerIndexByID__23CGtNetworkPlayerManagerFi(&D_01E32AE0, func_0041E930(&D_01E33A8C));
                snprintf(buf, 3, D_004C5008, t);
                if (!(idx < field_1390)) {
                    idx -= field_1390;
                    if (idx < 6) {
                        ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(buf, field_1378, 3);
                        field_188[idx].field_0 = (void *)RenderImageAndText__17CB3TableComponentFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
                        field_188[idx].field_4 = (void *)GetImageAndTextSize__17CB3TableComponentFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
                        field_188[idx].field_8 = field_E90;
                    }
                }
            }
        }
    }
    int n = D_01E32B08.field_0;
    int i;
    for (i = 0; i < n; i++) {
        UnkStruct_player * p = func_002366D0(&D_01E32AE0, i);
        if (p == 0) continue;
        if (Retrieve__27CB3NetworkHasHeadsetMessageFPUc((char *)p + 0xC58, &uc) != 0) p->field_4E8 = uc;
        if (p->field_4B0 == 0) continue;
        if (D_004F50A0.field_0 - field_139C < 1.0f) continue;
        switch (func_0041E900(&D_01E33A8C)) {
        case 0:
        case 1:
        case 3:
            Prepare__27CB3NetworkHasHeadsetMessageFUc((char *)p + 0xC44, 0);
            changed = true;
            continue;
        case 4:
            Prepare__27CB3NetworkHasHeadsetMessageFUc((char *)p + 0xC44, 4);
            break;
        case 2:
            Prepare__27CB3NetworkHasHeadsetMessageFUc((char *)p + 0xC44, 1);
            break;
        case 5:
            Prepare__27CB3NetworkHasHeadsetMessageFUc((char *)p + 0xC44, 2);
            break;
        default:
            break;
        }
        changed = true;
    }
    if (changed) field_139C = D_004F50A0.field_0;
}
