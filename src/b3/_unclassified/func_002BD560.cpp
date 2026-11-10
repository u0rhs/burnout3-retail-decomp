// Hand-written; the lifter refused it (CB3TrailSystem::Update helper: render loop, swap loop with p1 then t then p2).

struct UnkStruct_TrailParams { unsigned char pad_0[0x50]; };
struct UnkStruct_BD_Sw { int field_0; int field_4; unsigned char pad_8[0xC]; };
class CB3TrailSystem {
public:
    static UnkStruct_TrailParams mgaDefaultParams[5];
};
extern "C" void BeginRender__16CB3TrailRendererFv();
extern "C" void EndRender__16CB3TrailRendererFv();
extern "C" void Render__16CB3TrailRendererFPP15CB3TrailEmitteriP14CB3TrailParams12EB3TrailType(void *, int, void *, int);
extern "C" void func_002F34C0(void *, void *, int);
// 0x002BD560
extern "C" void func_002BD560(char *self)
{
    int i;
    BeginRender__16CB3TrailRendererFv();
    for (i = 0; i < 5; i++) {
        int n = *(int *)(self + i * 0x208 + 0x13E0C);
        if (n > 0) {
            Render__16CB3TrailRendererFPP15CB3TrailEmitteriP14CB3TrailParams12EB3TrailType(self + i * 0x208 + 0x13C0C, n, &CB3TrailSystem::mgaDefaultParams[i], i);
        }
    }
    unsigned char *sw = (unsigned char *)self;
    for (int j = 0; j < 0x80; j++) {
        int *p1 = (int *)(sw + j * 0x14 + 0x1300C);
        int t = *p1;
        int *p2 = (int *)(sw + j * 0x14 + 0x13008);
        *p1 = *p2;
        *p2 = t;
    }
    int cur = *(int *)(self + 0x14634);
    int other = 1 - cur;
    func_002F34C0(self + other * 0x9800, self + cur * 0x9800, 0x9800);
    *(int *)(self + 0x14634) = other;
    EndRender__16CB3TrailRendererFv();
}
