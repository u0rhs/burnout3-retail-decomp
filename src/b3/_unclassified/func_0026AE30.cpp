// Hand-written; the lifter refused it (SetCode inline (N203) + const p0 (field_24 load hoists above the byte stores)).

struct UnkStruct_0026AE30_p { unsigned char pad_0[0x24]; unsigned short field_24; };
struct UnkStruct_0026AE30 {
    unsigned char pad_0[0x94];
    const UnkStruct_0026AE30_p *field_94;
    unsigned char field_98;
    unsigned char pad_99[2];
    unsigned char field_9B;
    unsigned char field_9C;
    unsigned char pad_9D[3];
    unsigned long field_A0;
    unsigned long pad_A8;
    unsigned long field_B0;
};
struct UnkStruct_mesh { unsigned char pad_0[4]; int field_4; int field_8; };
extern UnkStruct_mesh *_gpMeshCache;
extern char vu_game_004787D0[];
extern "C" int sceDmaGetChan(int);
extern "C" int sceDmaSync(int, int, int);
class CGtVu0CodeManager {
public:
    static void *gmpCurrentVu0Code;
    static bool UploadVu0Code(void *code);
    static void WaitForUploadToFinish();
    static void *GetCurrentVu0CodePointer() { return gmpCurrentVu0Code; }
};
// [L] CGtVu0CodeManager::UploadVu0Code / WaitForUploadToFinish: names from the E B3O0PCH map (0x2294A0, 0x2293C0),
// signatures from Revenge types.h; bodies [L] from retail's inlined copies (gifq2 probes build/vt/gifq2/u*.cpp)
inline bool CGtVu0CodeManager::UploadVu0Code(void *code)
{
    if (gmpCurrentVu0Code == code) {
        return false;
    } else {
        gmpCurrentVu0Code = code;
        if (code) {
            *(volatile unsigned int *)0x10008020 = 0;
            *(volatile unsigned int *)0x10008030 = (unsigned int)code;
            *(volatile unsigned int *)0x10008000 = 0x145;
            return true;
        } else {
            return false;
        }
    }
}
inline void CGtVu0CodeManager::WaitForUploadToFinish()
{
    while (sceDmaSync(sceDmaGetChan(0), 1, 0) != 0) {}
}
// setc: p0 is const (its field_24 load hoists above the byte stores, BRIEF wave 3 const rule).
// 0x0026AE30
extern "C" void func_0026AE30(UnkStruct_0026AE30 *self, const UnkStruct_0026AE30_p *p0)
{
    if (CGtVu0CodeManager::GetCurrentVu0CodePointer() != (void *)vu_game_004787D0) {
        if (CGtVu0CodeManager::UploadVu0Code((void *)vu_game_004787D0)) CGtVu0CodeManager::WaitForUploadToFinish();
    }
    self->field_9B = 0;
    self->field_9C = 0;
    self->field_94 = p0;
    if ((p0->field_24 & 0x18) != 0) {
        self->field_A0 = (unsigned long)0xFF000000 << 32;
    } else {
        self->field_A0 = 0;
    }
    if ((p0->field_24 & 0x400) != 0) {
        self->field_B0 = (unsigned long)1 << 32;
    } else {
        self->field_B0 = 0;
    }
    self->field_98 = 0;
    UnkStruct_mesh *m = _gpMeshCache;
    m->field_8 = (int)m + 0x150;
    m->field_4 = m->field_8;
}
