// Hand-written; the lifter refused it (a90: hand-written; clamp with locals f,d and d > f; pmaxw/pminw/pextlw helpers).

struct UnkStruct_0013B260 {
    unsigned char pad_0[0x154];
    int field_154[1];
    unsigned char pad_158[0x18];
    int field_170[1];
    unsigned char pad_174[0x8C];
    int field_200;
    unsigned char pad_204[0x140];
    unsigned int field_344[15];
};
extern unsigned int D_0051C624[];
extern unsigned int D_0051C628[];
extern unsigned int D_0051C62C[];
extern unsigned int D_0051C630[];
extern unsigned int D_0051C634[];
extern unsigned int D_0051C638[];
extern unsigned int D_0051C63C[];
extern unsigned int D_0051C640[];
extern unsigned int D_0051C644[];
extern unsigned int D_0051C648[];
extern unsigned int D_0051C64C[];
extern unsigned int D_0051C650[];
extern unsigned int D_0051C654[];
extern unsigned int D_0051C658[];
extern unsigned int D_0051C65C[];
extern "C" int func_003EB060(unsigned long);
extern "C" int GetRaceVehicleSeries__23CB3HardCodedVehicleListFi(int);
class CB3HardCodedTrackList {
public:
    static int FindTrack(unsigned long);
};
static inline int func_0013B260_max(int a, int b)
{
    int r;
    asm("pmaxw %0, %1, %2" : "=r"(r) : "r"(a), "r"(b));
    return r;
}
static inline int func_0013B260_min(int a, int b)
{
    int r;
    asm("pminw %0, %1, %2" : "=r"(r) : "r"(a), "r"(b));
    return r;
}
static inline unsigned int func_0013B260_zx(int a)
{
    unsigned int r;
    asm("pextlw %0, $0, %1" : "=r"(r) : "r"(a));
    return r;
}

// 0x0013B260
extern "C" void func_0013B260(UnkStruct_0013B260 * self, int p1, unsigned long p2, unsigned long p3, int p4)
{
    int r0 = func_003EB060(p2);
    if (r0 != -1) {
        int r1 = GetRaceVehicleSeries__23CB3HardCodedVehicleListFi(r0);
        self->field_154[r1] += p1;
    }
    int r2 = CB3HardCodedTrackList::FindTrack(p3);
    if (r2 != -1) {
        self->field_170[r2] += p1;
    }
    {
        unsigned int f = self->field_344[0];
        unsigned int d = D_0051C624[0];
        if (d > f) {
            self->field_344[0] = d;
        }
    }
    {
        unsigned int f = self->field_344[1];
        unsigned int d = D_0051C628[0];
        if (d > f) {
            self->field_344[1] = d;
        }
    }
    {
        unsigned int f = self->field_344[2];
        unsigned int d = D_0051C62C[0];
        if (d > f) {
            self->field_344[2] = d;
        }
    }
    {
        unsigned int f = self->field_344[3];
        unsigned int d = D_0051C630[0];
        if (d > f) {
            self->field_344[3] = d;
        }
    }
    {
        unsigned int f = self->field_344[4];
        unsigned int d = D_0051C634[0];
        if (d > f) {
            self->field_344[4] = d;
        }
    }
    {
        unsigned int f = self->field_344[5];
        unsigned int d = D_0051C638[0];
        if (d > f) {
            self->field_344[5] = d;
        }
    }
    {
        unsigned int f = self->field_344[6];
        unsigned int d = D_0051C63C[0];
        if (d > f) {
            self->field_344[6] = d;
        }
    }
    {
        unsigned int f = self->field_344[7];
        unsigned int d = D_0051C640[0];
        if (d > f) {
            self->field_344[7] = d;
        }
    }
    {
        unsigned int f = self->field_344[8];
        unsigned int d = D_0051C644[0];
        if (d > f) {
            self->field_344[8] = d;
        }
    }
    {
        unsigned int f = self->field_344[9];
        unsigned int d = D_0051C648[0];
        if (d > f) {
            self->field_344[9] = d;
        }
    }
    {
        unsigned int f = self->field_344[10];
        unsigned int d = D_0051C64C[0];
        if (d > f) {
            self->field_344[10] = d;
        }
    }
    {
        unsigned int f = self->field_344[11];
        unsigned int d = D_0051C650[0];
        if (d > f) {
            self->field_344[11] = d;
        }
    }
    {
        unsigned int f = self->field_344[12];
        unsigned int d = D_0051C654[0];
        if (d > f) {
            self->field_344[12] = d;
        }
    }
    {
        unsigned int f = self->field_344[13];
        unsigned int d = D_0051C658[0];
        if (d > f) {
            self->field_344[13] = d;
        }
    }
    {
        unsigned int f = self->field_344[14];
        unsigned int d = D_0051C65C[0];
        if (d > f) {
            self->field_344[14] = d;
        }
    }
    if (p4 != 0) {
        self->field_200 += p1;
        self->field_200 = func_0013B260_zx(func_0013B260_min(func_0013B260_max(self->field_200, 0), 0x773593FF));
    }
}
