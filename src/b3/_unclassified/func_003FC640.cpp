// Hand-written; the lifter refused it (tail call with a0+8).

extern "C" void func_0042B5B0(void *);
// 0x003FC640
extern "C" void func_003FC640(char * p0)
{
    func_0042B5B0(p0 + 8);
}
