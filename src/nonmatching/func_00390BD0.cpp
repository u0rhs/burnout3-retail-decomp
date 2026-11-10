// NONMATCHING: func_00390BD0 -- retail 103 / ours 103 instructions, 8 in changed runs
// a248: logic+layout exact (103 instrs); only s0/s2 swap (retail loop idx=s0, record=s2; ours reversed). 30 variants incl a45a-z tried; declaration order no effect
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// from build/vt\try_func_00390BD0_best.cpp
// func_00390BD0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CGtNetworkPlayerManager;
struct UnkStruct_00390BD0;
struct UnkStruct_00390BD0_4;
struct UnkStruct_D_00522660;
struct UnkStruct_D_0064EB08;
struct UnkStruct_D_00665E50;
struct UnkStruct_D_00665E51;
struct UnkStruct_D_01E32B08;

class CGtNetworkPlayerManager {
public:
    int GetMyPlayerID() const;

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_0064EB08 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E32B08 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00390BD0_4 {
    unsigned char pad_0[0x40];
    int field_40;
    unsigned char pad_44[0x8];
    unsigned char field_4C;
};

struct UnkStruct_D_00665E50 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_00665E51 {
    unsigned char field_0;
    unsigned char pad_1[0xF];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_00390BD0 {
    unsigned char pad_0[0x20];
    int field_20;
    int field_24[1];  // [G] element count unknown
    unsigned char pad_28[0x20];
    unsigned char field_48;
};

extern UnkStruct_D_0064EB08 D_0064EB08;
extern UnkStruct_D_01E32B08 D_01E32B08;
extern UnkStruct_D_00665E50 D_00665E50;
extern UnkStruct_D_00665E51 D_00665E51;
extern CGtNetworkPlayerManager D_01E32AE0;
extern UnkStruct_D_00522660 D_00522660;

extern "C" UnkStruct_00390BD0_4 * GetPlayerRecordByID__17CB3NetworkManagerFi(void *, int);  // CB3NetworkManager::GetPlayerRecordByID(int)
extern "C" void func_0026FAA0(void *, int);
extern "C" void * func_002366D0(void *, int);
extern "C" int func_0022FBB0(void *);
extern "C" void func_001D3C10(void *);
extern "C" void func_001D3C50(void *);

// 0x00390BD0
extern "C" void func_00390BD0(UnkStruct_00390BD0 * self)
{
    func_0026FAA0(&D_01E32AE0, 0);
    for (int i = 0; (i < 8); i++) {
        self->field_24[i] = -1;
    }
    self->field_48 = 0;
    int r1 = D_01E32AE0.GetMyPlayerID();
    self->field_20 = r1;
    int m0 = D_0064EB08.field_0;
    for (int i1 = 0; (D_01E32B08.field_0 > i1); i1++) {
        void * r2 = func_002366D0(&D_01E32AE0, i1);
        if (r2 != 0) {
            int r3 = func_0022FBB0(r2);
            UnkStruct_00390BD0_4 * r4 = GetPlayerRecordByID__17CB3NetworkManagerFi(&D_01E32AE0, r3);
            if (r4->field_4C != 0) {
                int t0 = r4->field_40;
                if (t0 > m0) {
                    int r5 = func_0022FBB0(r2);
                    self->field_20 = r5;
                    m0 = r4->field_40;
                } else {
                    if (t0 == m0) {
                        int r6 = func_0022FBB0(r2);
                        if (self->field_20 > r6) {
                            int r7 = func_0022FBB0(r2);
                            self->field_20 = r7;
                            m0 = r4->field_40;
                        }
                    }
                }
            }
        }
    }
    D_00665E50.field_0 = 1;
    if (D_00665E50.field_0 != 0) {
        func_001D3C10(&D_00522660);
    } else if (D_00665E51.field_0 == 0) {
        func_001D3C50(&D_00522660);
    }
}

