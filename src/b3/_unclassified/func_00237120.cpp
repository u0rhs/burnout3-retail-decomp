// Hand-written; the lifter refused it (a71: [L] DNAT CGtThreadMgr::SleepThreadTillVBlank; volatile byte poll, byte-offset pun on the found-store keeps retail's i*4 reg + re-materialised base).

// [L] DNAT: CGtThreadMgr::SleepThreadTillVBlank() (research/proto/new_names.csv, high)
extern unsigned char _gaThreadsToWakeSignals[8];  // [G] element count: gp-relative
extern int D_01D80700[];  // [G] element count unknown

extern "C" void func_00114E60();
extern "C" void EIntr();
extern "C" int GetThreadId();
extern "C" void SleepThread();

// 0x00237120
extern "C" void SleepThreadTillVBlank__12CGtThreadMgrFv()
{
    func_00114E60();
    int i;
    for (i = 0; i < 4; i++) {
        if (D_01D80700[i] == -1) {
            _gaThreadsToWakeSignals[i] = 0;
            // [G] byte-offset pun: stops MWCC reusing the loop's element address (retail re-materialises the base)
            *(int *)((char *)D_01D80700 + i * 4) = GetThreadId();
            break;
        }
    }
    EIntr();
    volatile unsigned char * p = &_gaThreadsToWakeSignals[i];
    while (*p == 0) {
        SleepThread();
    }
    D_01D80700[i] = -1;
}
