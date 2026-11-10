// Hand-written; the lifter refused it (self as const pointer [G] (read-only, const-method shape): const loads reorder past stores, fixing the float register numbering (sdra rule 1)).


class CGtTexture;
namespace GtMathPs2 {
struct CGtV2d {
    float marValues[2];
    CGtV2d() {}
    CGtV2d(float x, float y) { marValues[0] = x; marValues[1] = y; }
    CGtV2d& operator=(const CGtV2d& o);
};
struct CGtV4d { float marValues[4]; };
}
using namespace GtMathPs2;
namespace Gt2dRenderer {
void RenderSpritesTex(GtMathPs2::CGtV4d, const GtMathPs2::CGtV2d&, int, const GtMathPs2::CGtV2d*, const GtMathPs2::CGtV2d*);
void SetTexture(CGtTexture*);
}
struct UnkStruct_D920 {
    CGtV2d field_0;
    CGtV2d field_8;
    CGtV4d field_10;
};
extern "C" CGtTexture *mpHUDBackgroundTexture__15CB3HUDComponent;

// 0x003CD920
extern "C" void func_003CD920(const UnkStruct_D920 *self, const CGtV2d *p)
{
    CGtV2d T[6];
    CGtV2d V[6];
    float x = p->marValues[0];
    int n = 2;
    T[0].marValues[0] = 0.0f;
    T[0].marValues[1] = 0.0f;
    if (x > 0.0f) {
        float xw = x * self->field_8.marValues[0];
        T[1].marValues[0] = xw;
        T[1].marValues[1] = self->field_8.marValues[1];
        T[2].marValues[0] = xw;
        T[2].marValues[1] = 0.0f;
        V[0] = CGtV2d(0.0f, 0.03125f);
        V[1] = CGtV2d(0.59375f, 0.9375f);
        n += 2;
    }
    V[n - 2] = CGtV2d(0.59375f, 0.03125f);
    V[n - 1] = CGtV2d(0.703125f, 0.9375f);
    if (p->marValues[1] > 0.0f) {
        float r = 1.0f - p->marValues[1];
        float rw = r * self->field_8.marValues[0];
        T[n - 1].marValues[0] = rw;
        T[n - 1].marValues[1] = self->field_8.marValues[1];
        T[n].marValues[0] = rw;
        T[n].marValues[1] = 0.0f;
        V[n] = CGtV2d(0.703125f, 0.03125f);
        V[n + 1] = CGtV2d(1.0f, 0.9375f);
        n += 2;
    }
    T[n - 1] = self->field_8;
    Gt2dRenderer::SetTexture(mpHUDBackgroundTexture__15CB3HUDComponent);
    Gt2dRenderer::RenderSpritesTex(self->field_10, self->field_0, n / 2, T, V);
}
