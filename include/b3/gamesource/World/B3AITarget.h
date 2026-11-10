#ifndef B3_B3AITARGET_H
#define B3_B3AITARGET_H

// [L]: Revenge's CB4AIAggressionBehaviour::Construct(void) exists at the same
// relative role (research/R_jul14/map_symbols.csv) -- CB3->CB4 lineage, same
// pattern already proven for CB3TrackRenderer/CB4TrackRenderer.
class CB3AIAggressionBehaviour {
public:
    void Construct();   // 0x00331DA0 [L] mangled Construct__24CB3AIAggressionBehaviourFv
    // [C] 0x0032F350, retail tables (B3AIAggressionBehaviour.cpp, high). Returns field_48; the return type is [G]
    // (a pointer, from the name; the pointee type is unknown).
    void *GetAttackTarget() const;

private:
    unsigned char pad_0[0x48];
    void *field_48;
};

class CB3AITarget {
public:
    void Construct();   // 0x0014DD40 [C]: decompiled and objdiff-verified
    // ... other known-but-undecompiled methods (see config/symbol_addrs_b3names.txt lines 603-626):
    // ResetTarget, Prepare, Update, Release, ResetCornerStatus, UpdateCurrentSegment,
    // FillInTargetPosition, CalculateNextTargetPosition, FindNextCorner,
    // CalculateNearEdgePosition, CalculateEdgePosition, GetCurrentFwdFrac,
    // LaneIsUndesirable (x2), LanesAreSideBySide, GetDesiredDirection

private:
    unsigned char pad0[0x170];
    CB3AIAggressionBehaviour field_170;   // embedded member, offset proven by this+0x170 in asm
};

#endif
