// Hand-written; the lifter refused it (extern C, || guard to table[0]).

extern unsigned long D_004CCF80[];
extern "C" unsigned long GetRaceVehicleGtID__23CB3HardCodedVehicleListFi(int p0)
{
    if (p0 == -1 || p0 >= 0x43) return D_004CCF80[0];
    return D_004CCF80[p0];
}
