// Hand-written; the lifter refused it (seed _mRandom from RTC clock via func_00436350; unfolded *15*4 etc chain).

struct UnkStruct_00387240_clk { unsigned short field_0, field_2, field_4, field_6, field_8, field_A; };
struct UnkStruct_00387240_rnd { int field_0; int field_4; };
extern "C" void func_00436350(UnkStruct_00387240_clk *);
extern "C" UnkStruct_00387240_rnd _mRandom__13CGtSoundUtils;
// 0x00387240
extern "C" void func_00387240(void *a0 /* passed by every caller, not read here */)
{
    UnkStruct_00387240_clk t;
    func_00436350(&t);
    int v = t.field_A + t.field_8 * 15 * 4 + t.field_6 * 15 * 15 * 16 + t.field_4 * 15 * 15 * 15 * 64;
    _mRandom__13CGtSoundUtils.field_4 = v;
    _mRandom__13CGtSoundUtils.field_0 = ~v;
}
