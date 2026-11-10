// Pointer members that keep the PS2's 32-bit layout on a 64-bit host.
//
// mwccps2 (__MWERKS__, the matching build): B3_PTR(T) is T*, a 32-bit pointer; nothing changes for matching.
// Host build (resource D port layer, x64): B3_PTR(T) is B3GuestPtr<T>, a 32-bit guest address, so every class keeps its
// PS2 offsets and size. The port layer supplies the two address conversions (for resource D:
// generated::RamPointer and its inverse; matching/resource_d/).
// B3_FNPTR(Name, Ret, Args) declares a function-pointer type: a real one on the PS2, a 32-bit guest code address on the
// host (guest code is called through the port layer, never directly).
// B3_CHECK_OFFSET / B3_CHECK_SIZE state layouts recovered from retail code; both compilers check them.
// This file's own names (B3_PTR, B3GuestPtr, ...) are project conventions, not Criterion's.
#ifndef B3_PTR_H
#define B3_PTR_H

#if defined(__MWERKS__)

#define B3_PTR(T) T*
#define B3_FNPTR(Name, Ret, Args) typedef Ret (*Name) Args
#define B3_OFFSETOF(T, m) ((unsigned int)&((T*)0)->m)

#else

#include <cstddef>

void* B3GuestToHost(unsigned int guest);      // port layer; null for 0
unsigned int B3HostToGuest(const void* host); // port layer; 0 for null

template <typename T>
struct B3GuestPtr {
    unsigned int addr;
    T* get() const { return static_cast<T*>(B3GuestToHost(addr)); }
    T* operator->() const { return get(); }
    T& operator*() const { return *get(); }
    operator T*() const { return get(); }
    B3GuestPtr& operator=(T* p) { addr = B3HostToGuest(p); return *this; }
};

#define B3_PTR(T) B3GuestPtr<T>
#define B3_FNPTR(Name, Ret, Args) typedef unsigned int Name
#define B3_OFFSETOF(T, m) offsetof(T, m)

#endif

#define B3_CAT2(a, b) a##b
#define B3_CAT(a, b) B3_CAT2(a, b)
#define B3_CHECK_OFFSET(T, m, off) typedef char B3_CAT(b3_offset_check_, __LINE__)[(B3_OFFSETOF(T, m) == (off)) ? 1 : -1]
#define B3_CHECK_SIZE(T, size) typedef char B3_CAT(b3_size_check_, __LINE__)[(sizeof(T) == (size)) ? 1 : -1]

#endif
