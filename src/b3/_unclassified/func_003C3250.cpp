// Hand-written; the lifter refused it (s318: archive + AcquireBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki's real 3rd argument (the slot index, a2)).

struct UnkStruct_theMemMgr { unsigned char pad_0[0x10]; };
struct UnkStruct_003C3250 { unsigned char pad_0[0x10]; void *field_10[54]; int field_E8; };
extern UnkStruct_theMemMgr theMemMgr;
extern "C" void *AcquireBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(void *, int, int);
// 0x003C3250
extern "C" void *func_003C3250(UnkStruct_003C3250 *self)
{
    int i;
    void **s;
    for (i = 0; i < self->field_E8; i++) {
        s = &self->field_10[i];
        if (*s == 0) {
            *s = AcquireBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(&theMemMgr, 6, i);
            if (*s == 0) return 0;
            *(int *)((unsigned int)*s | 0x20000000) = 0;
            return *s;
        }
    }
    return 0;
}
