// Hand-written; the lifter refused it (gaps1c: written from the asm, exact).

// gaps1c (2026-11-02): hand-written from the retail asm (0x28B700..0x28B710). The class name is the asm label's (config/symbol_addrs.txt; no retail
// table row): a constructor that only sets the vtable pointer (__vt__12CUnk0028B700) at +0 and returns this.

class CUnk0028B700 {
public:
    CUnk0028B700();
    virtual void vfunc_8();
};

// 0x0028B700
CUnk0028B700::CUnk0028B700()
{
}
