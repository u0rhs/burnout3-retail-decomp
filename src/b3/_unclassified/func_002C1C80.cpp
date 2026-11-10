// Hand-written; the lifter refused it (a77: two func_0022FE10 registrations, int-typed params, callback address as int).

extern "C" void func_0022FE10(void *, int, int, void *, void *, void *, void *, void *);
extern "C" void HeadsetControlMessageArrivedCallback__17CGtNetworkHeadsetFP17CGtNetworkMessageiPv(void *, int, void *);

// [L] DNAT: low row only (GetNumVariantsOnThisJunction, 0.63 similarity), not applicable: body registers two network-message callbacks via func_0022FE10 (research/proto/new_names.csv).
// 0x002C1C80
extern "C" void func_002C1C80(void *p0, void *p1, void *p2, void *p3, void *p4)
{
    func_0022FE10((void *)(p1), 3, 32, (void *)(p4), (void *)(0), (void *)((int)&HeadsetControlMessageArrivedCallback__17CGtNetworkHeadsetFP17CGtNetworkMessageiPv), (void *)(0), (void *)(p0));
    func_0022FE10((void *)(p1), 2, 304, (void *)(p2), (void *)(p3), (void *)(0), (void *)(0), (void *)(0));
}
