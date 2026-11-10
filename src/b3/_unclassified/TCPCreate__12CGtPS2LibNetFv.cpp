// Hand-written; the lifter refused it (tiny extern C).

extern "C" int WakeupThread(int);
extern "C" int TCPCreate__12CGtPS2LibNetFv(int *self) { self[0x710/4] = 0; return WakeupThread(self[0x98/4]); }
