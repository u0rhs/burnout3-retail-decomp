// CGt2dScene (E map: Gt2dScene.cpp). Header name/folder: project convention (K18/K19).
// Layout from retail code only (docs/hud2d.md Phase 2, K24): CGt2dScene::Prepare 0x1D78F0, ConstructObject 0x1D7580,
// DestructObject 0x1D7560. Burnout 2's C2dScene (maLayers 0x74, mnNumLayers 0x78) does not carry over; its member names
// are kept as hints in comments only.
#ifndef B3_GT2DSCENE_H
#define B3_GT2DSCENE_H

#include "b3/B3Ptr.h"
#include "b3/GameShared/GameClasses/Graphical/2d/Gt2dObject.h"
#include "b3/GameShared/GameClasses/Graphical/2d/GtFreeList.h"

class CGt2dFrame;

// Scene layer record, 16-byte stride in the array at CGt2dScene +0x2C (type name: placeholder). Cf. B2 C2dLayer
// (mnProperties, mObjectList, ...) [G].
struct UnkStruct_Gt2dScene_2C {
    unsigned int field_0;                      // [C] property bits (Render: blend 0x26, filter 0x8, address 0x10); cleared by Prepare
    CGtFreeList field_4;                       // [C] objects of this layer: AddLink / RemoveLink / RemoveAllLinks
    B3_PTR(CGt2dFrame) field_c;                // [C] clip frame (Render: its +0x20/+0x28 give the clip region; B2: mpClipFrame [G]); cleared by Prepare
};
B3_CHECK_SIZE(UnkStruct_Gt2dScene_2C, 0x10);

class CGt2dFrameHierarchy {                    // E map: Gt2dFrameHierarchy.cpp
public:
    void Prepare();                            // 0x1D4F90, called by CGt2dScene::Prepare on the scene itself [C]
    unsigned char field_0[0x14];               // [L] the scene's +0x0..+0x13 (pool begins at +0x18); layout not recovered
    B3_PTR(CGt2dFrame) field_14;               // [C] root frame: Prepare walks its children from here (lw 0x14(a0));
                                               // CB3HeadingComponent::Prepare calls ConstructChild() on it
};

class CGt2dScene : public CGt2dFrameHierarchy {  // base [L]: Prepare calls CGt2dFrameHierarchy::Prepare(this); B2 too
public:
    void DestructObject(int, CGt2dObject*);    // 0x1D7560
    CGt2dObject* ConstructObject(int, CGt2dFrame*);  // 0x1D7580 (returns link + 8 [C])
    void Render();                             // 0x1D75C0
    void Prepare();                            // 0x1D78F0
    void Construct(int, int, int, void*, unsigned int);  // 0x1D7960

    CGtFreeListPool field_18;                  // [C] SortFree() at the end of Prepare
    B3_PTR(UnkStruct_Gt2dScene_2C) field_2c;   // [C] layer array (B2: maLayers [G])
    int field_30;                              // [C] layer count, signed compare in Prepare (B2: mnNumLayers [G])
};
B3_CHECK_OFFSET(CGt2dScene, field_18, 0x18);
B3_CHECK_OFFSET(CGt2dScene, field_2c, 0x2C);
B3_CHECK_OFFSET(CGt2dScene, field_30, 0x30);

#endif
