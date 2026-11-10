// CGtPS2LibNet -- consolidated from the lifted units' declarations (tools/hdr_consolidate.py).
// Field names are placeholders and every type is [G] (instruction widths), as in the units; offsets
// are the units' own. Header location is mechanical (include/b3/classes/), not Criterion's.
#ifndef B3_CLASSES_CGTPS2LIBNET_H
#define B3_CLASSES_CGTPS2LIBNET_H

class CGtPS2LibNet;

class CGtPS2LibNet {
public:
    void ResumeSocket(int p0);
    void SuspendSocket();
    int UpInterface(int p0);

    unsigned char pad_0[0x14];
    int field_14;
    unsigned char pad_18[0x30];
    int field_48;
    unsigned char field_4C;
    unsigned char pad_4D[0x3F];
    int field_8C;
    int field_90;
    unsigned char pad_94[0x10];
    int field_A4;
    int field_A8;
    int field_AC;
    unsigned char pad_B0[0x654];
    int field_704;
    unsigned char pad_708[0x4];
    int field_70C;
};

#endif
