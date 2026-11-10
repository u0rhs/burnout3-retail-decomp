#include "b3/gamesource/Menu/DebugMenu/Components/B3PromptsComponent.h"

// 0x0031E140
// CB3PromptsComponent::SetCurrentPrompts(unsigned int, unsigned int) [C name], defined by its link name: `a` is 64-bit
// (w64, see B3PromptsComponent.h).
extern "C" void SetCurrentPrompts__19CB3PromptsComponentFUiUi(CB3PromptsComponent *self, unsigned long a, unsigned int b)
{
    // field_A: set by Prepare, cleared by Release (CB3MenuComponentBase). Release() is the virtual call (slot 1).
    if (self->field_A)
        self->Release();
    func_0031ECD0(self, a, b);
}
