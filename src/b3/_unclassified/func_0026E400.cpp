// func_0026E400 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CB3ReplayFileHeader;

struct UnkStruct_0026E400;
struct UnkStruct_0026E400_2;
struct UnkStruct_D_0051B85C;

struct UnkStruct_D_0051B85C {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0026E400_2 {
    unsigned char pad_0[0x4F8];
    unsigned char field_4F8;
};

struct UnkStruct_0026E400 {
    unsigned char pad_0[0x4];
    int field_4;
};

extern UnkStruct_D_0051B85C D_0051B85C;

extern "C" UnkStruct_0026E400_2 * GetPlayerByID__23CGtNetworkPlayerManagerCFi(void *, int);  // CGtNetworkPlayerManager::GetPlayerByID(int) const
extern "C" void Retrieve__29CB3NetworkReplayHeaderMessageFP19CB3ReplayFileHeader(void *, void *);  // CB3NetworkReplayHeaderMessage::Retrieve(CB3ReplayFileHeader*)

// 0x0026E400
extern "C" void func_0026E400(UnkStruct_0026E400 * self, int p0, int p1)
{
    UnkStruct_0026E400_2 * r0 = GetPlayerByID__23CGtNetworkPlayerManagerCFi((void *)p1, self->field_4);
    if (r0 != 0) {
        int t0 = D_0051B85C.field_0;
        if (t0 != 0) {
            Retrieve__29CB3NetworkReplayHeaderMessageFP19CB3ReplayFileHeader(self, (CB3ReplayFileHeader*)t0);
            r0->field_4F8 = 1;
        }
    }
}
