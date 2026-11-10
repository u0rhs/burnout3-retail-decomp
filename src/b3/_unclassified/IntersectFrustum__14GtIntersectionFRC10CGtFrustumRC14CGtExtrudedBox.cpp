// Hand-written; the lifter refused it (SetCode inline (N203) under scoped opt_repositioncode off + VU0 microcode asm).

// GtIntersection::IntersectFrustum(const CGtFrustum&,const CGtExtrudedBox&) -- hand-written (setc).
// [C] name: the mangled symbol in retail's tables; file: GtIntersectionPS2.cpp (E dnat map). Area not evidenced, so
// _unclassified/. The VU0 microprogram (GtIntsecVU0.dsm, E dnat) reads its inputs from fixed VF registers, so the
// loads and the vcallms/cfc2 are inline asm; the code upload is the inlined CGtVu0CodeManager::UploadVu0Code (N203).
extern "C" int sceDmaGetChan(int);
extern "C" int sceDmaSync(int, int, int);
// [C] names: E B3O0PCH map (CGtVu0CodeManager::UploadVu0Code 0x2294A0, WaitForUploadToFinish 0x2293C0,
// GetCurrentVu0CodePointer 0x229520); signatures from Revenge types.h; static data gmpCurrentVu0Code (retail tables).
class CGtVu0CodeManager {
public:
    static void *gmpCurrentVu0Code;
    static bool UploadVu0Code(void *code);
    static void WaitForUploadToFinish();
    static void *GetCurrentVu0CodePointer() { return gmpCurrentVu0Code; }
};
// [L] bodies from retail's inlined copies (gifq2 probes, N203)
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
extern char vu_game_004787D0[];
class CGtFrustum;
class CGtExtrudedBox;
class GtIntersection { public: static int IntersectFrustum(const CGtFrustum &f, const CGtExtrudedBox &b); };

// N182/N203: GtIntersection's inlined SetCode copies keep the no-reposition `bne; nop; b join` shape: [G] scoped to
// this function (opt_repositioncode off; [L] GtIntersection*.cpp compiled with it, gifq2 probe ur7).
#pragma push
#pragma opt_repositioncode off
// 0x00274AF0
int GtIntersection::IntersectFrustum(const CGtFrustum &f, const CGtExtrudedBox &b)
{
    if (CGtVu0CodeManager::GetCurrentVu0CodePointer() != (void *)vu_game_004787D0) {
        if (CGtVu0CodeManager::UploadVu0Code((void *)vu_game_004787D0)) CGtVu0CodeManager::WaitForUploadToFinish();
    }
    int r;
    asm volatile("lqc2 $vf1, 0x0(%0)\n\tlqc2 $vf2, 0x10(%0)\n\tlqc2 $vf3, 0x20(%0)\n\tlqc2 $vf4, 0x30(%0)" : : "r"(&b));
    asm volatile("lqc2 $vf9, 0x20(%0)\n\tlqc2 $vf10, 0x30(%0)\n\tlqc2 $vf11, 0x40(%0)\n\tlqc2 $vf12, 0x50(%0)\n\t"
                 "lqc2 $vf13, 0x0(%0)\n\tlqc2 $vf14, 0x10(%0)" : : "r"(&f));
    asm volatile("vcallms 0xA50");
    asm volatile("cfc2.i %0, $vi1" : "=r"(r));
    return r & 0xFFFF;   // [G] the result is a 16-bit VI register value
}
#pragma pop
