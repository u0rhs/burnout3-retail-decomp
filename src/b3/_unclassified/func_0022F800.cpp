// Hand-written; the lifter refused it (a244 exact; linker 16-byte padding between per-function sections (a146_cmp now pads)).


struct UnkStruct_0022F800_o { unsigned char pad_0[0x14]; int field_14; unsigned char pad_18[0x30]; int field_48; };
struct UnkStruct_0022F800 { UnkStruct_0022F800_o * field_0; };
extern "C" void func_0022E110(UnkStruct_0022F800_o *);
extern "C" void SleepThreadTillVBlank__12CGtThreadMgrFv();
// 0x0022F800
extern "C" void func_0022F800(UnkStruct_0022F800 * self)
{
    UnkStruct_0022F800_o * s = self->field_0;
    while (1) {
        switch (s->field_48) {
        case 2: case 3: case 5: case 6:
            if (s->field_14 == 3) continue;
            func_0022E110(s);
            continue;
        default:
            break;
        case 4:
            break;
        }
        SleepThreadTillVBlank__12CGtThreadMgrFv();
    }
}
struct UnkStruct_0022F890 { UnkStruct_0022F800_o * field_0; };
extern "C" void func_0022E200(UnkStruct_0022F800_o *, UnkStruct_0022F890 *);
// 0x0022F890
extern "C" void func_0022F890(UnkStruct_0022F890 * self)
{
    func_0022E200(self->field_0, self);
}
