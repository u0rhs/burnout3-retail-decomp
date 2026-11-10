// Hand-written; the lifter refused it (a67: frame hierarchy set-up, SetIdentity inl x2, mem declared uninit then assigned, poolSize+mem return).

#include "b3/GtMathPs2.h"
#include "b3/GameShared/GameClasses/Graphical/2d/GtFreeList.h"

struct UnkStruct_001D4680_f {
    float field_0;
    float field_4;
    float field_8;
    float field_C;
    GtMathPs2::CGtV4d field_10;
};
struct UnkStruct_001D4680_h {
    unsigned char pad_0[0x14];
    UnkStruct_001D4680_f *field_14;
};

// [L] CGt2dFrameHierarchy set-up called from CGt2dScene::Construct (Gt2dScene.cpp): (hierarchy, frames, memory, memory size)
// [G] the two frame initialisers are CGt2dFrame::CGt2dFrameSpace::SetIdentity inlined (0x1D5DC0 out of line elsewhere)
static inline void func_001D4680_inl1(UnkStruct_001D4680_f *f)
{
    f->field_0 = 0.0f;
    f->field_4 = 0.0f;
    f->field_8 = 1.0f;
    f->field_C = 1.0f;
    f->field_10 = GtMathPs2::CGtV4d(1.0f, 1.0f, 1.0f, 1.0f);
}

// 0x001D4680
extern "C" char *func_001D4680(UnkStruct_001D4680_h *self, int frames, UnkStruct_001D4680_f *memory, unsigned int memorySize)
{
    char *mem;
    unsigned int poolSize = _GetRequiredMemory__15CGtFreeListPoolFUiUiUi(frames, 0x50, 0x10);
    self->field_14 = memory;
    mem = (char *)self->field_14 + 0x50;
    func_001D4680_inl1(self->field_14);
    func_001D4680_inl1(self->field_14 + 1);
    Construct__11CGtFreeListFP15CGtFreeListPool((GtLListTag *)(self->field_14 + 2), (GtLListPoolTag *)self);
    ((int *)self->field_14)[0x48 / 4] = 0;
    ((UnkStruct_001D4680_h **)self->field_14)[0x4C / 4] = self;
    Construct__15CGtFreeListPoolFUiUiUiPCvPvUi((CGtFreeListPool *)self, frames, 0x50, 0x10, self->field_14, mem, poolSize);
    return (char *)(poolSize + (unsigned int)mem);
}
