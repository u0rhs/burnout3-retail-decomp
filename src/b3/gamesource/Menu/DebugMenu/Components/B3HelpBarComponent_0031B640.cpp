#include "b3/gamesource/Menu/DebugMenu/Components/B3HelpBarComponent.h"

// 0x0031B640 (Target #39). Copies x positions and edges of the four sub-objects into field_5C-0x68, with a
// 20-unit margin on the two computed edges, then sets field_6C.
void func_0031B640(CB3HelpBarComponent *self)
{
    self->field_5C = self->field_18[0]->mObjectSpace.mTopLeftPos.marValues[0];
    self->field_60 = self->field_18[1]->mObjectSpace.mTopLeftPos.marValues[0];
    self->field_64 = self->field_20->mObjectSpace.mTopLeftPos.marValues[0] -
                     self->field_18[0]->mObjectSpace.mSize.marValues[0] - 20.0f;
    self->field_68 = 20.0f + (self->field_14->mObjectSpace.mTopLeftPos.marValues[0] +
                              self->field_14->mObjectSpace.mSize.marValues[0]);
    self->field_6C = 1;
}
