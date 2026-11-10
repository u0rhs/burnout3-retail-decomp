// func_0023B6E0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (switch with breaks to one return 0 and no default; case 2 reuses the index local for the chunk size, offset computed before the test).

// func_0023B6E0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CB3ReplayFileHeader;

class CB3NetworkReplayBodyMessage;
class CB3NetworkReplayHeaderMessage;
struct UnkStruct_0023B6E0;
struct UnkStruct_0023B6E0_a1;
struct UnkStruct_0023B6E0_e0;
struct UnkStruct_D_004E2A14;
struct UnkStruct_D_0055EEE8;

class CB3NetworkReplayHeaderMessage {
public:
    void Prepare(const CB3ReplayFileHeader*);
};

class CB3NetworkReplayBodyMessage {
public:
    void Prepare(const unsigned char*, int, int);
};

struct UnkStruct_0023B6E0_a1 {
    unsigned char pad_0[0x14];
    int field_14;
};

struct UnkStruct_D_004E2A14 {
    unsigned short field_0;
};

struct UnkStruct_D_0055EEE8 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0023B6E0_e0 {
    unsigned char pad_0[0x3E8];
};

struct UnkStruct_0023B6E0 {
    unsigned char pad_0[0x4F5];
    unsigned char field_4F5;
    unsigned short field_4F6;
    unsigned char pad_4F8[0x858];
    CB3NetworkReplayHeaderMessage field_D50;
    unsigned char pad_D51[0xDF];
    CB3NetworkReplayBodyMessage field_E30;
    unsigned char pad_E31[0xA9F];
    int field_18D0;
    int field_18D4;
    unsigned short field_18D8;
};

extern UnkStruct_D_004E2A14 D_004E2A14;
extern UnkStruct_D_0055EEE8 D_0055EEE8;

// 0x0023B6E0
extern "C" int func_0023B6E0(UnkStruct_0023B6E0 * self, UnkStruct_0023B6E0_a1 * p0, UnkStruct_0023B6E0_e0 * p1)
{
    int t0 = p0->field_14;
    int v0 = (t0 / 1000);
    if ((t0 % 1000) != 0) {
        v0 = ((t0 / 1000) + 1);
    }
    switch (self->field_18D0) {
    
    case 0:
        self->field_4F5 = 0;
        self->field_4F6 = 65535;
        self->field_18D4 = 0;
        self->field_D50.Prepare((const CB3ReplayFileHeader*)&D_0055EEE8);
        self->field_18D0 = 1;
        break;
    case 1:
        if (self->field_4F5 != 0) {
            self->field_18D0 = 2;
        }
        break;
    case 2: {
        unsigned short v1 = D_004E2A14.field_0;
        if (D_004E2A14.field_0 == 65535) {
            v1 = 0;
        }
        self->field_18D8 = v1;
        int n = self->field_18D4;
        int off = n * 1000;
        if (n == (v0 - 1)) {
            n = (p0->field_14 % 1000);
        } else {
            n = 1000;
        }
        self->field_E30.Prepare((const unsigned char *)p1 + off, off, n);
        self->field_18D0 = 3;
        break;
    }
    case 3:
        if (self->field_4F6 == self->field_18D8) {
            if (self->field_18D4 == (v0 - 1)) {
                self->field_18D0 = 4;
                return 1;
            }
            self->field_18D4++;
            self->field_18D0 = 2;
        }
        break;
    case 4:
        return 1;
    }
    return 0;
}
