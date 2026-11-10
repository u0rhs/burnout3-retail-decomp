// Hand-written; the lifter refused it (s318: archive + AcquireBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki's real 3rd argument (the slot index, a2)).

struct UnkStruct_theMemMgr { unsigned char pad_0[0x10]; };
struct UnkStruct_003C3150 { unsigned char pad_0[0x5C]; void *field_5C[36]; int field_EC; };
extern UnkStruct_theMemMgr theMemMgr;
extern "C" void *AcquireBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(void *, int, int);
// 0x003C3150
extern "C" void *func_003C3150(UnkStruct_003C3150 *self)
{
    int i;
    void **s;
    for (i = 0; i < self->field_EC; i++) {
        s = &self->field_5C[i];
        if (*s == 0) {
            *s = AcquireBlock__19CB3MemoryManagerPS2F14EB3MemoryBlocki(&theMemMgr, 7, i);
            if (*s == 0) return 0;
            *(int *)((unsigned int)*s | 0x20000000) = 0;
            return *s;
        }
    }
    return 0;
}
