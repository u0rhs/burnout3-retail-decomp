// Hand-written; the lifter refused it (int byte local reassigned as (unsigned char)m & mask keeps the lbu before the %4 branch; int s = seg copy, (unsigned)s >> 2 index).

extern unsigned char gauTrafficSegmentLock8[];
class CB3TrafficSystem {
public:
    bool IsSegmentLocked(int, unsigned short);
    unsigned char pad_0[0x363B9];
    unsigned char field_363B9;
};
// 0x00163240
bool CB3TrafficSystem::IsSegmentLocked(int a, unsigned short seg)
{
    if (field_363B9 == 0) return false;
    int s = seg;
    bool lo = a == 0;
    int m = gauTrafficSegmentLock8[(unsigned short)((unsigned)s >> 2)];
    unsigned char bit = lo + (s % 4) * 2;
    unsigned char mask = 1 << bit;
    m = (unsigned char)m & mask;
    return m != 0;
}
