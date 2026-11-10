// func_0045BC50 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (switch selects (value pointer, lo=0, count) per case, then one inlined left/right wrap-around stepper; locals declared v, n, lo).

// func_0045BC50 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.

class CB3InputManager;
struct UnkStruct_0045BC50;
struct UnkStruct_D_01E7A800;
struct UnkStruct_D_01E8961C;

class CB3InputManager {
public:
    int GetMenuLeft(signed char);
    int GetMenuRight(signed char);

    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E7A800 {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_D_01E8961C {
    unsigned char pad_0[0x10];  // [G] size: absolute addressing needs > 8 bytes (N50)
};

struct UnkStruct_0045BC50 {
    unsigned char pad_0[0x4];
    int field_4;
    int field_8;
    int field_C;
    unsigned short field_10;
};

extern CB3InputManager D_004F50C0;
extern UnkStruct_D_01E7A800 D_01E7A800;
extern UnkStruct_D_01E8961C D_01E8961C;

extern "C" void FEVerticalMove__18CB3HUDSoundManagerFv(void *, int);  // CB3HUDSoundManager::FEVerticalMove(), passed 1 more argument(s) [G]
extern "C" void SetOptionText__26CB3VOptionsSelectComponentFiUi(void *, unsigned short, int);

// [G] inlined helper (name unknown): steps *v left/right through [lo, n) with wrap-around
static inline void func_0045BC50_inl(UnkStruct_0045BC50 * self, int * v, int lo, int n)
{
    int old = *v;
    if (D_004F50C0.GetMenuLeft(0) != 0) {
        FEVerticalMove__18CB3HUDSoundManagerFv(&D_01E7A800, 1);
        (*v)--;
        if (*v < lo) {
            *v = n - 1;
        }
    } else if (D_004F50C0.GetMenuRight(0) != 0) {
        FEVerticalMove__18CB3HUDSoundManagerFv(&D_01E7A800, 1);
        (*v)++;
        if (*v >= n) {
            *v = lo;
        }
    }
    if (*v != old) {
        SetOptionText__26CB3VOptionsSelectComponentFiUi(&D_01E8961C, self->field_10, *v);
    }
}

// 0x0045BC50
extern "C" void func_0045BC50(UnkStruct_0045BC50 * self)
{
    int * v;
    int n;
    int lo;
    switch (self->field_10) {
    case 1:
        v = &self->field_8;
        lo = 0;
        n = 4;
        break;
    case 0:
        v = &self->field_C;
        lo = 0;
        n = 6;
        break;
    case 2:
        v = &self->field_4;
        lo = 0;
        n = 11;
        break;
    default:
        return;
    }
    func_0045BC50_inl(self, v, lo, n);
}
