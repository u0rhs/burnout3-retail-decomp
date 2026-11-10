// CB3PlayerCameraManager::PrepareBuffer() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3PlayerCameraManager.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a123: statics meLoadState/mgpCameraBuffer/mbLoaded* as class statics; switch cases return false; sibling header declares mgpCameraBuffer int).

typedef unsigned int u_long128 __attribute__((mode(TI)));
struct UnkStruct_theMemMgr { unsigned char pad_0[0x10]; };
struct UnkStruct_E7D20_buf { int field_0; };
class CB3CameraEditor { public: unsigned char pad_0[0x10]; };

class CB3PlayerCameraManager {
public:
    bool PrepareBuffer();

    static int meLoadState;
    static UnkStruct_E7D20_buf * mgpCameraBuffer;
    static bool mbLoadedIntro;
    static bool mbLoadedReplay;
};

extern UnkStruct_theMemMgr theMemMgr;
extern CB3CameraEditor D_01E86500;
extern struct { unsigned char field_0; } D_004E2D3C;
extern "C" UnkStruct_E7D20_buf * AcquireBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(void *, int, int);
extern "C" void * memset(void *, int, unsigned int);
extern "C" void RegisterVariables__16CB3CameraAttribsFv(void *);
extern "C" int LoadMungedKeyFrames__15CB3CameraEditorFPv15EB3KeyFrameType(void *, void *, void *);
extern "C" void func_00446A40(void *, void *);

// 0x002E7D20
bool CB3PlayerCameraManager::PrepareBuffer()
{
    if (mgpCameraBuffer == 0) {
        mgpCameraBuffer = AcquireBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(&theMemMgr, 0, 0);
        if (mgpCameraBuffer == 0) {
            return false;
        }
        memset((char *)mgpCameraBuffer + 0x980, 0, 0x1F40);
        memset((char *)mgpCameraBuffer + 0x330, 0, 0x640);
        *(unsigned long *)((char *)mgpCameraBuffer + 0x2970) = 0;
        *(unsigned long *)((char *)mgpCameraBuffer + 0x2B20) = 0;
        RegisterVariables__16CB3CameraAttribsFv((char *)mgpCameraBuffer + 0x2C30);
    }
    switch (meLoadState) {
    case 0: {
        int r = LoadMungedKeyFrames__15CB3CameraEditorFPv15EB3KeyFrameType(&D_01E86500, (char *)mgpCameraBuffer + 0x330, (void *)(1));
        if (r == 0) {
            mbLoadedIntro = false;
            meLoadState = 1;
        } else if (r == 2) {
            meLoadState = 1;
            mbLoadedIntro = true;
        }
        return false;
    }
    case 1: {
        int r = LoadMungedKeyFrames__15CB3CameraEditorFPv15EB3KeyFrameType(&D_01E86500, (char *)mgpCameraBuffer + 0x980, (void *)(3));
        if (r == 0) {
            mbLoadedReplay = false;
            meLoadState = 2;
        } else if (r == 2) {
            mgpCameraBuffer->field_0 = *(int *)((char *)mgpCameraBuffer + 0x984);
            for (int i = 0; i < mgpCameraBuffer->field_0; i++) {
                u_long128 tmp;
                func_00446A40(&tmp, (char *)mgpCameraBuffer + i * 32 + 0x990);
                *(u_long128 *)((char *)mgpCameraBuffer + i * 16 + 0x10) = tmp;
            }
            memset((char *)mgpCameraBuffer + 0x980, 0, 0x1F40);
            meLoadState = 2;
            mbLoadedReplay = true;
        }
        return false;
    }
    case 2:
        D_004E2D3C.field_0 = 0;
        meLoadState = 3;
        return true;
    default:
        return true;
    }
}
