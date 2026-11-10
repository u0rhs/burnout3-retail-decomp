// GtSoundStream.cpp -- translation unit regrouped by tools/tu_merge.py from 11 proven function(s) (tools/tiny_batch.py).
// [C]/[L] membership: 3 function(s) named in research/retail_names.csv -> GtSoundStream.cpp, 8 placed between two of them by address contiguity (N2).
// Area: src/b3/GameShared/GameClasses/Sound, [L] Revenge (SLUS_212.42) GameShared/GameClasses/Sound/GtSoundStream.cpp.
// Shared classes, structs and enums: include/b3/classes/ (tools/hdr_consolidate.py); field names are
// placeholders and every type is [G] (instruction widths). Each function's own notes precede it.

#include "b3/classes/CGtSoundStream.h"

struct UnkStruct_00385FD0;
struct UnkStruct_00385FE0;
struct UnkStruct_00386010;
struct UnkStruct_00386020;
struct UnkStruct_00386020_0;
struct UnkStruct_00386020_2;
struct UnkStruct_00386080;
struct UnkStruct_00386080_1;
struct UnkStruct_00386240;
struct UnkStruct_00386300;
struct UnkStruct_003863C0;
struct UnkStruct_00386290;
struct UnkStruct_003865A0;
struct UnkStruct_003865A0_1;
struct UnkStruct_003865A0_2;

struct UnkStruct_00385FD0 {
    unsigned char pad_0[0x1D0];
    int field_1D0;
};

struct UnkStruct_00385FE0 {
    unsigned char pad_0[0x1D0];
    int field_1D0;
};

struct UnkStruct_00386010 {
    unsigned char pad_0[0x1D0];
    int field_1D0;
};

struct UnkStruct_00386020_0 {
    UnkStruct_00386020_2 * field_0;
    int field_4;
    int field_8;
    unsigned char pad_C[0x4];
};

struct UnkStruct_00386020_2 {
    unsigned char pad_0[0x38];
    int field_38;
};

struct UnkStruct_00386020 {
    unsigned char pad_0[0x138];
    int field_138;
    int field_13C;
    unsigned char pad_140[0x8C];
    int field_1CC;
};

struct UnkStruct_00386080_1 {
    unsigned char pad_0[0x4];
    int field_4;
    float field_8;
    int field_C;
};

struct UnkStruct_00386080 {
    unsigned char pad_0[0x1CC];
    int field_1CC;
};

struct UnkStruct_00386240 {
    unsigned char pad_0[0x1CC];
    int field_1CC;
    int field_1D0;
    unsigned char pad_1D4[0x22];
    unsigned char field_1F6;
};

struct UnkStruct_00386300 {
    unsigned char pad_0[0x1A4];
    float field_1A4[1];  // [G] element count unknown
};

struct UnkStruct_003863C0 {
    unsigned char field_0;
    unsigned char pad_1[0x13F];
    int field_140;
    unsigned char pad_144[0x88];
    int field_1CC;
    int field_1D0;
    unsigned char pad_1D4[0x20];
    unsigned char field_1F4;
    unsigned char pad_1F5[0x1];
    unsigned char field_1F6;
};

struct UnkStruct_00386290 {
    unsigned char pad_0[0x1CC];
    int field_1CC;
    int field_1D0;
    unsigned char pad_1D4[0x21];
    unsigned char field_1F5;
};

struct UnkStruct_003865A0_q {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
};

struct UnkStruct_003865A0_p {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
};

struct UnkStruct_003865A0_e {
    UnkStruct_003865A0_2 * field_0;
    int field_4;
    int field_8;
};

struct UnkStruct_003865A0_f {
    UnkStruct_003865A0_p * field_0;
    int field_4;
};

struct UnkStruct_003865A0_1 {
    int field_0;
    int field_4;
    int field_8;
    int field_C;
    unsigned char pad_10[0x10];
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
    unsigned char pad_30[0x4];
    int field_34;
    unsigned char pad_38[0x4];
    int field_3C;
    int field_40;
    int field_44;
    unsigned char pad_48[0x4];
    int field_4C;
    int field_50;
    unsigned char pad_54[0x4];
    UnkStruct_003865A0_2 * field_58;
    int field_5C;
    int field_60;
    unsigned char pad_64[0x4];
    void * field_68;
    int field_6C;
};

struct UnkStruct_003865A0_2 {
    unsigned char pad_0[0x38];
    int field_38;
};

struct UnkStruct_003865A0 {
    unsigned char pad_0[0x138];
    int field_138;
    int field_13C;
    unsigned char pad_140[0x88];
    float field_1C8;
    int field_1CC;
    int field_1D0;
    unsigned char pad_1D4[0x1C];
    int field_1F0;
    unsigned char field_1F4;
    unsigned char field_1F5;
    unsigned char field_1F6;
};

extern "C" void func_002A28A0(int, void *);
extern "C" int RwaWaveFormatGetSamples(int, int);
extern "C" int _rwaStreamGetStatus(int);
extern "C" void _rwaStreamGetStreamPos(int, void *);
extern "C" void _rwaStreamSetPlayState(int, int);
extern "C" void _rwaStreamSetMedia(int, int);
extern "C" void ApplyVolumesAndPitch__14CGtSoundStreamFv(void *);  // CGtSoundStream::ApplyVolumesAndPitch()
extern "C" void _rwaStreamSetLoopSegment(int, bool);
extern "C" bool AttachMedia__14CGtSoundStreamFPCc(void *, const char*, int);  // CGtSoundStream::AttachMedia(const char*), passed 1 more argument(s) [G]
extern "C" void func_002A28C0(int, void *);
extern "C" void _rwaStreamSetStreamPos(int, void *);

// func_00385FD0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00385FD0
extern "C" bool func_00385FD0(UnkStruct_00385FD0 * self)
{
    return (self->field_1D0 == 1);
}

// func_00385FE0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00385FE0
extern "C" int func_00385FE0(UnkStruct_00385FE0 * self)
{
    int t0 = self->field_1D0;
    if ((t0 == 4) || (t0 == 0)) {
        return 1;
    }
    return 0;
}

// func_00386010 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00386010
extern "C" bool func_00386010(UnkStruct_00386010 * self)
{
    return (self->field_1D0 == 6);
}

// func_00386020 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00386020
// [C] returns RwaWaveFormatGetSamples's result: nothing writes v0 between the `jal RwaWaveFormatGetSamples` at 0x386060
// and `jr $ra` at 0x386070, and func_003FC2E0 adds it at 0x3FC410 (`addu $v1, $s1, $v0`).
extern "C" int func_00386020(UnkStruct_00386020 * self)
{
    UnkStruct_00386020_0 local;  // [G] the frame's one local (size: up to the frame top)
    local.field_8 = 0;
    local.field_4 = 0;
    func_002A28A0(self->field_1CC, &local);
    return RwaWaveFormatGetSamples((local.field_0->field_38 + 16), (self->field_138 / self->field_13C));
}

// func_00386080 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00386080
extern "C" int func_00386080(UnkStruct_00386080 * self, int p0)
{
    UnkStruct_00386080_1 local;  // [G] the frame's one local (size: up to the frame top)
    int r0 = _rwaStreamGetStatus(self->field_1CC);
    switch (r0) {
    case 5:
    case 6:
        local.field_4 = 3;
        if (p0 == 0) {
            local.field_C = 2;
            _rwaStreamGetStreamPos(self->field_1CC, &local);
            return *(int *)&local.field_8;
        }
        local.field_C = 1;
        _rwaStreamGetStreamPos(self->field_1CC, &local);
        return ((int)(1000.0f * local.field_8));
    default:
        return 0;
    }
}

// Stop__14CGtSoundStreamFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00386240
extern "C" void Stop__14CGtSoundStreamFv(UnkStruct_00386240 * self)
{
    int t0 = self->field_1D0;
    if (t0 != 5) {
        if (t0 != 4) {
            self->field_1D0 = 5;
            _rwaStreamSetPlayState(self->field_1CC, 1);
        }
    }
    self->field_1F6 = 0;
}

// Play__14CGtSoundStreamFb -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00386290
extern "C" void Play__14CGtSoundStreamFb(UnkStruct_00386290 * self, unsigned char p0)
{
    bool b = p0 != 0;
    if (self->field_1D0 != 6) {
        _rwaStreamSetLoopSegment(self->field_1CC, b);
        _rwaStreamSetPlayState(self->field_1CC, 2);
        self->field_1D0 = 6;
        ApplyVolumesAndPitch__14CGtSoundStreamFv(self);
    }
    self->field_1F5 = 0;
}

// SetVolume__14CGtSoundStreamFfi -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x00386300
extern "C" void SetVolume__14CGtSoundStreamFfi(UnkStruct_00386300 * self, int p0, float f0)
{
    if (p0 != -1) {
        self->field_1A4[p0] = f0;
    } else {
        int i = 0;
        goto loop0_test;
loop0_body:
        {
            self->field_1A4[i] = f0;
        }
        i++;
loop0_test:
        if ((unsigned int)i < (unsigned int)8) goto loop0_body;
    }
}

// CGtSoundStream::SetMediaBuffer(void*,int) -- tiny-function batch (tools/tiny_batch.py).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> GtSoundStream.cpp.
// 0x00386350
void CGtSoundStream::SetMediaBuffer(void* p0, int p1)
{
    field_134 = p0;
    field_138 = p1;
}

// Release__14CGtSoundStreamFv -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x003863C0
extern "C" int Release__14CGtSoundStreamFv(UnkStruct_003863C0 * self)
{
    self->field_140 = 0;
    _rwaStreamSetPlayState(self->field_1CC, 1);
    _rwaStreamSetMedia(self->field_1CC, 0);
    self->field_1F4 = 0;
    self->field_1D0 = 0;
    self->field_1F6 = 0;
    self->field_0 = 0;
    return 1;
}

// func_003865A0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// 0x003865A0
extern "C" int func_003865A0(UnkStruct_003865A0 * self, void *p0_, int p1, int p2, int p3, int p4)
{
    int p0 = (int)p0_;
    UnkStruct_003865A0_f f;
    UnkStruct_003865A0_e e;
    UnkStruct_003865A0_q d;
    UnkStruct_003865A0_p c;
    UnkStruct_003865A0_p b;
    UnkStruct_003865A0_q a;
    self->field_1F5 = 0;
    self->field_1F6 = 0;
    self->field_1C8 = -1.0f;
    if (self->field_1F4 == 0) {
        AttachMedia__14CGtSoundStreamFPCc(self, (const char*)p0, p4);
        return 0;
    }
    switch (_rwaStreamGetStatus(self->field_1CC)) {
    case 5:
        self->field_1D0 = 2;
        switch (_rwaStreamGetStatus(self->field_1CC)) {
        case 5:
        case 6:
            c.field_4 = 3;
            c.field_C = 1;
            _rwaStreamGetStreamPos(self->field_1CC, &c);
            break;
        }
        d.field_0 = 0;
        d.field_4 = 3;
        d.field_C = 1;
        func_002A28C0(self->field_1CC, &d);
        self->field_1F0 = d.field_10;
        return 1;
    case 3:
        self->field_1D0 = 1;
        a.field_4 = 3;
        a.field_C = 2;
        a.field_0 = p3;
        func_002A28C0(self->field_1CC, &a);
        while ((unsigned int)p2 >= (unsigned int)a.field_8) {
            e.field_8 = 0;
            e.field_4 = 0;
            func_002A28A0(self->field_1CC, &e);
            p2 -= RwaWaveFormatGetSamples(e.field_0->field_38 + 16, self->field_138 / self->field_13C);
        }
        b.field_0 = p3;
        f.field_4 = 1;
        f.field_0 = &b;
        b.field_4 = 3;
        b.field_8 = p2;
        b.field_C = 2;
        _rwaStreamSetStreamPos(self->field_1CC, &f);
        _rwaStreamSetPlayState(self->field_1CC, 3);
        break;
    case 6:
        _rwaStreamSetPlayState(self->field_1CC, 1);
        self->field_1D0 = 1;
        break;
    }
    return 0;
}
