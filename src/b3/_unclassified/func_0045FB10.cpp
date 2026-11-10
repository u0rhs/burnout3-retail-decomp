// func_0045FB10 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (one count n shared by both cases, no default; loop counter declared before n).

// from build/vt\try_func_0045FB10_best.cpp
// func_0045FB10 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CB3HardCodedCrashStageList;
class CB3HardCodedTrackList;
class CB3TrackList;
struct UnkStruct_0045FB10;
struct UnkStruct_D_004EE040;
struct UnkStruct_D_005196A4;

class CB3TrackList {
public:
    int GetTrackRegion(unsigned long);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

class CB3HardCodedTrackList {
public:
    static int FindTrack(unsigned long);
    static int GetTrackString(int, bool);
};

class CB3HardCodedCrashStageList {
public:
    static unsigned long GetCrashStageGtID(int);
};

struct UnkStruct_D_005196A4 {
    int field_0;
    unsigned char pad_4[0xC];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_004EE040 {
    unsigned char pad_0[0x2BA68];
    unsigned long field_2BA68[1];  // [G] element count unknown
};

struct UnkStruct_0045FB10 {
    unsigned char pad_0[0xC];
    int field_C;
    int field_10;
    unsigned char pad_14[0xC];
    unsigned long field_20[1];  // [G] element count unknown
    unsigned char pad_28[0x118];
    int field_140[1];  // [G] element count unknown
    unsigned char pad_144[0x8C];
    unsigned long field_1D0[1];  // [G] element count unknown
    unsigned char pad_1D8[0x318];
    int field_4F0[1];  // [G] element count unknown
};

extern UnkStruct_D_005196A4 D_005196A4;
extern UnkStruct_D_004EE040 D_004EE040;
extern CB3TrackList D_005196A0;

extern "C" int IsCorrectRegion__26CB3HardCodedCrashStageListF14EB3TrackRegioni(int, int);
extern "C" int func_003E9490(int, int);

// 0x0045FB10
extern "C" int func_0045FB10(UnkStruct_0045FB10 * self)
{
    int i;
    int n = 0;
    switch (self->field_C) {
    case 0:
        for (i = 0; (i < D_005196A4.field_0); i++) {
            unsigned long t1 = D_004EE040.field_2BA68[i];
            if (self->field_10 == D_005196A0.GetTrackRegion(t1)) {
                self->field_20[n] = t1;
                self->field_140[n] = CB3HardCodedTrackList::GetTrackString(CB3HardCodedTrackList::FindTrack(t1), 1);
                n++;
            }
        }
        break;
    case 1:
    case 2:
        for (int i1 = 0; (i1 < 100); i1++) {
            if (IsCorrectRegion__26CB3HardCodedCrashStageListF14EB3TrackRegioni(self->field_10, i1) != 0) {
                self->field_1D0[n] = CB3HardCodedCrashStageList::GetCrashStageGtID(i1);
                self->field_4F0[n] = func_003E9490(i1, 1);
                n++;
            }
        }
        break;
    }
    return n;
}
