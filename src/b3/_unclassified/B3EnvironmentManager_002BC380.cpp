// CB3EnvironmentManager::RenderSky() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3EnvironmentManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a73: static sky callees via extern C (no this); if(t>=0.75) sub else add).

class CB3EnvironmentManager;
struct UnkStruct_D_004EE040 { unsigned char pad_0[0x10]; };
extern UnkStruct_D_004EE040 D_004EE040;
extern "C" void SetupCamera__18CB3SkyDomeRendererFff(float, float);
extern "C" void BeginRender__18CB3SkyDomeRendererFv(void);
extern "C" void RenderComponent__18CB3SkyDomeRendererFQ222CB3SkyDomeRendererBase13ESkyComponent(int);
extern "C" void EndRender__18CB3SkyDomeRendererFv(void);

class CB3EnvironmentManager {
public:
    void RenderSky();
    unsigned char pad_0[0x130];
    int field_130;
    float field_134;
    unsigned char pad_138[0x14];
    unsigned char field_14C;
};

// 0x002BC380
void CB3EnvironmentManager::RenderSky()
{
    if (field_14C != 0) {
        float t0 = field_134;
        unsigned long t1 = *(unsigned long *)((char *)&D_004EE040 + field_130 * 0xBB0 + 0x29980);
        if ((t1 & 0x10) || (t1 & 0x8)) {
            if (t0 >= 0.75f) {
                t0 = t0 - 0.75f;
            } else {
                t0 = t0 + 0.25f;
            }
        }
        SetupCamera__18CB3SkyDomeRendererFff(t0, 0.0f);
        BeginRender__18CB3SkyDomeRendererFv();
        RenderComponent__18CB3SkyDomeRendererFQ222CB3SkyDomeRendererBase13ESkyComponent(0);
        RenderComponent__18CB3SkyDomeRendererFQ222CB3SkyDomeRendererBase13ESkyComponent(1);
        EndRender__18CB3SkyDomeRendererFv();
    }
}
