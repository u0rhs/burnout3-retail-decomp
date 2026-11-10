// func_0042DF40 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (mwperm: 'int only = p1; unsigned long id = p0; int m0 = 0; int i = 0;' -> 'int t3; int t2; int t5; long v0 = p0; unsigned long r1; EB3MenuCarClasses r0; un'; 'unsigned long r1 = D_005186A0.GetCarID(r0, i); if (only != 0' -> 'r1 = D_005186A0.GetCarID(r0, i); if (p1 != 0) { int t4 = D_005186A0.IsVehicleDri'; 'm0++;' -> 'unsigned int t1 = (unsigned int)m0+ (unsigned int)1; t5 = (int)(t1); m0 = (t5);').

enum EB3MenuCarClasses {};

class CB3VehicleList;

class CB3VehicleList {
public:
    static int GetClassFromID(unsigned long);
    int GetCarCount(EB3MenuCarClasses);
    unsigned long GetCarID(EB3MenuCarClasses, int);
    int IsVehicleDriveable(unsigned long);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

extern CB3VehicleList D_005186A0;

// 0x0042DF40
extern "C" int func_0042DF40(unsigned long p0, int p1)
{
    int t3;
    int t2;
    int t5;
    long v0 = p0;
    unsigned long r1;
    EB3MenuCarClasses r0;
    unsigned long id = v0;
    int i;
    unsigned int t0;
    t2 = CB3VehicleList::GetClassFromID(id);
    r0 = (EB3MenuCarClasses)t2;
    unsigned int m0 = 0;
    i = 0;
    for (; i < D_005186A0.GetCarCount(r0); i++) {
        r1 = D_005186A0.GetCarID(r0, i);
        if (p1 != 0) {
            int t4 = D_005186A0.IsVehicleDriveable(r1);
            t3 = t4;
            t0 = t3;
            if (((t0))) {
            } else {
                continue;
            }
        }
        if (r1 == id) {
            return m0;
        }
        unsigned int t1 = (unsigned int)m0+ (unsigned int)1;
        t5 = (int)(t1);
        m0 = (t5);
    }
    return -1;
}
