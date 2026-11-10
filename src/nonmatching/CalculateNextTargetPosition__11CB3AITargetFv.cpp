// NONMATCHING: CalculateNextTargetPosition__11CB3AITargetFv -- retail 663 / ours 663 instructions, 29 in changed runs
// draftAA ab7a: 663/663, 29 changed. Left: s0-s3 permutation in the else branch (retail seg s0, lane s1, lbSuccess+loop1 n s2, l s3; ours lbSuccess/n s0, l s1, seg s2, lane s3). Fixed: int next/lnEnd (double andi), l-before-n decl in loops (loop 2 regs), lane arg via accessor inline (retail does not CSE the top lane load into the call arg). Tried: decl orders, int lbSuccess, else-assign, function-top decls, shared loop vars, loop-as-inline -- no change
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the retail asm; every branch, call argument and store accounted for (Ghidra 0014BB80 cross-checked)

// CalculateNextTargetPosition__11CB3AITargetFv -- CB3AITarget::CalculateNextTargetPosition() @ 0x0014BB80
// [C] name: config/symbol_addrs_b3names.txt; [L] Revenge counterpart CB4AITarget::CalculateNextTargetPosition
// (research stabs). Hand-written from the retail asm; field names are placeholders, types [G] (widths).
#include "b3/GtMathPs2.h"
using GtMathPs2::CGtV3d;

enum EAITargetTurn { UnkEnum_0014BB80_t };
enum EAITargetCornerState { UnkEnum_0014BB80_s };

struct UnkStruct_0014BB80_seg {   // [G] 10-byte lane segment
    unsigned char pad_0[0x4];
    unsigned char field_4;        // neighbour lane index (one side)
    unsigned char field_5;        // neighbour lane index (other side)
    unsigned short field_6;
    unsigned short field_8;
};
struct UnkStruct_0014BB80_laneinfo {
    unsigned char pad_0[0x8];
    UnkStruct_0014BB80_seg * field_8;
    unsigned short field_C;       // segment count
};
class CB3AILane {
public:
    unsigned short IncrementSegmentIndexClamped(unsigned short, short) const;
    int SegmentAIsInfrontOfSegmentB(unsigned short, unsigned short) const;
    static bool LaneIsDriveable(unsigned char, unsigned short, unsigned short);

    unsigned char pad_0[0x4];
    UnkStruct_0014BB80_laneinfo * field_4;
};
struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x2C];
    CB3AILane field_2C[1];        // [G] count unknown
};
struct UnkStruct_D_0064D35C { int field_0; unsigned char pad_4[0xC]; };
extern UnkStruct_D_00522660 D_00522660;
extern UnkStruct_D_0064D35C D_0064D35C;
extern "C" float GetLeftFrac__9CB3AILaneCFUsQ29GtMathPs26CGtV3df(const CB3AILane *, unsigned short, const CGtV3d *, float);

class CB3AITarget {
public:
    void CalculateNextTargetPosition();
    void FillInTargetPosition();
    void ResetCornerStatus();
    void CalculateNearEdgePosition(unsigned short, unsigned short, int, CGtV3d *, unsigned char *, unsigned short *);
    void CalculateEdgePosition(unsigned short, unsigned short, int, CGtV3d *, unsigned char *, unsigned short *);
    int LaneIsUndesirable(const CB3AILane *, unsigned short, unsigned short) const;
    bool FindNextCorner(const CB3AILane *, unsigned short, unsigned short *, unsigned short *, unsigned short *, float *, float *, float *, EAITargetTurn *, EAITargetCornerState *, bool *, bool *);

    unsigned char pad_0[0x1D4];
    CB3AILane * field_1D4;
    unsigned short field_1D8;
    unsigned char pad_1DA[0x2];
    float field_1DC;
    unsigned char pad_1E0[0x13];
    bool field_1F3;
    EAITargetTurn field_1F4;
    int field_1F8;
    EAITargetCornerState field_1FC;
    CGtV3d field_200;
    unsigned short field_210;
    unsigned char field_212;
    bool field_213;
    unsigned short field_214;
    unsigned short field_216;
    unsigned short field_218;
    unsigned char pad_21A[0x6];
    CGtV3d field_220;
    CGtV3d field_230;
    CGtV3d field_240;
    unsigned char pad_250[0x10];
    unsigned char field_260;
    unsigned char field_261;
    unsigned char field_262;
    unsigned char pad_263;
    unsigned short field_264;
    unsigned short field_266;
    unsigned short field_268;
    unsigned char pad_26A[0x2];
    int field_26C;
    int field_270;
    int field_274;
    unsigned char pad_278[0x18];
    unsigned char field_290;
    unsigned char pad_291[0x7];
    float field_298;
    float field_29C;
    float field_2A0;
    unsigned char pad_2A4[0x2];
    unsigned short field_2A6;
};

static inline void func_0014BB80_inl1(CB3AITarget *self)
{
    self->FillInTargetPosition();
    self->field_1DC = GetLeftFrac__9CB3AILaneCFUsQ29GtMathPs26CGtV3df(self->field_1D4, self->field_210, &self->field_200, 0.0f);
}

static inline void func_0014BB80_inl2(CB3AITarget *self)
{
    if (self->field_1F4 == 2) {
        self->CalculateNearEdgePosition(self->field_214, self->field_1D8, 2, &self->field_220, &self->field_260, &self->field_264);
        self->CalculateNearEdgePosition(self->field_218, self->field_216, 2, &self->field_240, &self->field_262, &self->field_268);
        self->CalculateEdgePosition(self->field_216, self->field_214, 1, &self->field_230, &self->field_261, &self->field_266);
        self->field_26C = 2;
        self->field_270 = 1;
        self->field_274 = 2;
    } else {
        self->CalculateNearEdgePosition(self->field_214, self->field_1D8, 1, &self->field_220, &self->field_260, &self->field_264);
        self->CalculateNearEdgePosition(self->field_218, self->field_216, 1, &self->field_240, &self->field_262, &self->field_268);
        self->CalculateEdgePosition(self->field_216, self->field_214, 2, &self->field_230, &self->field_261, &self->field_266);
        self->field_26C = 1;
        self->field_270 = 2;
        self->field_274 = 1;
    }
}

static inline void func_0014BB80_inl3(CB3AITarget *self)
{
    self->field_260 = 0xFF;
    self->field_264 = 0xFFFF;
    self->field_261 = 0xFF;
    self->field_266 = 0xFFFF;
    self->field_262 = 0xFF;
    self->field_268 = 0xFFFF;
}

static inline const CB3AILane *func_0014BB80_inl5(const CB3AITarget *self) { return self->field_1D4; }

static inline bool func_0014BB80_inl4(CB3AITarget *self)
{
    bool found;
    if (self->field_210 == 0xFFFF) {
        found = self->FindNextCorner(func_0014BB80_inl5(self), self->field_1D8, &self->field_214, &self->field_216, &self->field_218,
                                     &self->field_298, &self->field_29C, &self->field_2A0, &self->field_1F4, &self->field_1FC,
                                     &self->field_213, &self->field_1F3);
    } else {
        found = self->FindNextCorner(func_0014BB80_inl5(self), self->field_210, &self->field_214, &self->field_216, &self->field_218,
                                     &self->field_298, &self->field_29C, &self->field_2A0, &self->field_1F4, &self->field_1FC,
                                     &self->field_213, &self->field_1F3);
    }
    return found;
}

// 0x0014BB80
void CB3AITarget::CalculateNextTargetPosition()
{
    if ((unsigned int)field_1FC < 2) {
        switch (field_1F8) {
        case 0:
            return;
        case 1:
            func_0014BB80_inl1(this);
            break;
        case 2: {
            bool b0, b1;
            unsigned short s0, s1, s2;
            float f0, f1, f2;
            EAITargetTurn turn;
            EAITargetCornerState state;
            bool found;
            int next = field_1D4->IncrementSegmentIndexClamped(field_218, 12);
            if (D_0064D35C.field_0 > 0) {
                found = FindNextCorner(field_1D4, field_216, &s0, &s1, &s2, &f0, &f1, &f2, &turn, &state, &b0, &b1);
            } else {
                found = FindNextCorner(field_1D4, field_2A6, &s0, &s1, &s2, &f0, &f1, &f2, &turn, &state, &b0, &b1);
            }
            if (found && turn != 0 && field_1D4->SegmentAIsInfrontOfSegmentB(next, s0)) {
                field_1FC = (EAITargetCornerState)0;
                if (field_1D4->SegmentAIsInfrontOfSegmentB(s0, field_1D8)) {
                    field_1F8 = 0;
                    field_210 = s0;
                    field_212 = 0;
                } else if (field_1D4->SegmentAIsInfrontOfSegmentB(s1, field_1D8)) {
                    field_1F8 = 1;
                    field_210 = s1;
                } else {
                    field_1F8 = 2;
                    field_210 = s2;
                }
                field_214 = s0;
                field_216 = s1;
                field_218 = s2;
                field_298 = f0;
                field_29C = f1;
                field_2A0 = f2;
                field_1F4 = turn;
                field_1FC = state;
                field_213 = b0;
                field_1F3 = b1;
                func_0014BB80_inl3(this);
                func_0014BB80_inl2(this);
                func_0014BB80_inl1(this);
            } else {
                func_0014BB80_inl1(this);
            }
            break;
        }
        }
    } else {
        CB3AILane *lane = field_1D4;
        unsigned short seg = field_1D8;
        bool lbSuccess = true;
        if (!func_0014BB80_inl4(this)) {
            lane = field_1D4;
            lbSuccess = false;
            seg = field_1D8;
        }
        if (!lbSuccess) {
            do {
                UnkStruct_0014BB80_seg *p = &field_1D4->field_4->field_8[field_1D8];
                unsigned char l = p->field_4;
                unsigned short n = p->field_6;
                int lnEnd = n + 8;
                int lnDelta = (unsigned short)lnEnd - n;
                int flags;
                if (lnDelta < 0) lnDelta += D_00522660.field_2C[l].field_4->field_C;
                if (!CB3AILane::LaneIsDriveable(l, n, lnDelta)) {
                    flags = 4;
                } else {
                    flags = LaneIsUndesirable(&D_00522660.field_2C[l], n, lnEnd);
                }
                if (flags & 4) {
                    lbSuccess = false;
                    break;
                }
                field_1D4 = &D_00522660.field_2C[l];
                field_1D8 = n;
                field_290 = 0;
                ResetCornerStatus();
                lbSuccess = true;
            } while (!func_0014BB80_inl4(this));
        }
        if (!lbSuccess) {
            field_1D4 = lane;
            field_1D8 = seg;
            do {
                UnkStruct_0014BB80_seg *p = &field_1D4->field_4->field_8[field_1D8];
                unsigned char l = p->field_5;
                unsigned short n = p->field_8;
                int lnEnd = n + 8;
                int lnDelta = (unsigned short)lnEnd - n;
                int flags;
                if (lnDelta < 0) lnDelta += D_00522660.field_2C[l].field_4->field_C;
                if (!CB3AILane::LaneIsDriveable(l, n, lnDelta)) {
                    flags = 4;
                } else {
                    flags = LaneIsUndesirable(&D_00522660.field_2C[l], n, lnEnd);
                }
                if (flags & 4) {
                    lbSuccess = false;
                    break;
                }
                field_1D4 = &D_00522660.field_2C[l];
                field_1D8 = n;
                field_290 = 0;
                ResetCornerStatus();
                lbSuccess = true;
            } while (!func_0014BB80_inl4(this));
        }
        if (!lbSuccess) {
            field_1F4 = (EAITargetTurn)0;
            field_214 = field_1D8;
            field_218 = field_1D4->field_4->field_C - 1;
            field_216 = (field_214 + field_218) / 2;
            field_298 = field_29C = 5000;
            field_2A0 = 0.1f;
            field_1F4 = (EAITargetTurn)0;
            field_1FC = (EAITargetCornerState)1;
            field_213 = 0;
        }
        func_0014BB80_inl3(this);
        if (field_1F4 != 0) {
            func_0014BB80_inl2(this);
        }
        if (field_1D4->SegmentAIsInfrontOfSegmentB(field_1D8, field_216)) {
            field_1F8 = 2;
            field_210 = field_218;
            func_0014BB80_inl1(this);
        } else if (field_1D4->SegmentAIsInfrontOfSegmentB(field_1D8, field_214)) {
            field_1F8 = 1;
            field_210 = field_216;
            func_0014BB80_inl1(this);
        } else {
            field_1F8 = 0;
            field_210 = field_214;
            field_212 = 0;
            func_0014BB80_inl1(this);
        }
    }
}
