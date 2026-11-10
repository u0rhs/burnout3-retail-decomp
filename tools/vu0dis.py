"""Decode PS2 EE COP2 (VU0 macro mode) instructions to text. decode(word) -> str or None."""
BC = "xyzw"
S1 = {0x1C: "vmulq", 0x1D: "vmaxi", 0x1E: "vmuli", 0x1F: "vminii", 0x20: "vaddq", 0x21: "vmaddq", 0x22: "vaddi", 0x23: "vmaddi",
      0x24: "vsubq", 0x25: "vmsubq", 0x26: "vsubi", 0x27: "vmsubi", 0x28: "vadd", 0x29: "vmadd", 0x2A: "vmul", 0x2B: "vmax",
      0x2C: "vsub", 0x2D: "vmsub", 0x2E: "vopmsub", 0x2F: "vmini", 0x30: "viadd", 0x31: "visub", 0x32: "viaddi", 0x34: "viand",
      0x35: "vior", 0x38: "vcallms", 0x39: "vcallmsr"}
S1BC = {0: "vadd", 1: "vsub", 2: "vmadd", 3: "vmsub", 4: "vmax", 5: "vmini", 6: "vmul"}
S2 = {0x10: "vitof0", 0x11: "vitof4", 0x12: "vitof12", 0x13: "vitof15", 0x14: "vftoi0", 0x15: "vftoi4", 0x16: "vftoi12", 0x17: "vftoi15",
      0x1C: "vmulaq", 0x1D: "vabs", 0x1E: "vmulai", 0x1F: "vclipw", 0x20: "vaddaq", 0x21: "vmaddaq", 0x22: "vaddai", 0x23: "vmaddai",
      0x24: "vsubaq", 0x25: "vmsubaq", 0x26: "vsubai", 0x27: "vmsubai", 0x28: "vadda", 0x29: "vmadda", 0x2A: "vmula", 0x2C: "vsuba",
      0x2D: "vmsuba", 0x2E: "vopmula", 0x2F: "vnop", 0x30: "vmove", 0x31: "vmr32", 0x34: "vlqi", 0x35: "vsqi", 0x36: "vlqd", 0x37: "vsqd",
      0x38: "vdiv", 0x39: "vsqrt", 0x3A: "vrsqrt", 0x3B: "vwaitq", 0x3C: "vmtir", 0x3D: "vmfir", 0x3E: "vilwr", 0x3F: "viswr",
      0x40: "vrnext", 0x41: "vrget", 0x42: "vrinit", 0x43: "vrxor"}
S2BC = {0: "vadda", 1: "vsuba", 2: "vmadda", 3: "vmsuba", 6: "vmula"}
def decode(w):
    if w >> 26 != 0x12: return None
    dest = "".join(c for i, c in enumerate("xyzw") if (w >> (24 - i)) & 1)
    ft, fs, fd = (w >> 16) & 31, (w >> 11) & 31, (w >> 6) & 31
    if not (w >> 25) & 1:
        sub = (w >> 21) & 31; rt = (w >> 16) & 31
        names = {1: "qmfc2", 2: "cfc2", 5: "qmtc2", 6: "ctc2"}
        if sub in names: return f"{names[sub]} r{rt}, vf{fs}" if sub in (1, 5) else f"{names[sub]} r{rt}, vi{fs}"
        if sub == 8: return "bc2"
        return None
    f = w & 0x3F
    if f < 0x3C:
        if f < 0x1C: return f"{S1BC.get(f >> 2, '?')}{BC[f & 3]}.{dest} vf{fd}, vf{fs}, vf{ft}{BC[f & 3]}"
        n = S1.get(f, f"vop1_{f:x}")
        if n in ("viadd", "visub", "viand", "vior"): return f"{n} vi{fd}, vi{fs}, vi{ft}"
        if n in ("vcallms", "vcallmsr"): return n
        return f"{n}.{dest} vf{fd}, vf{fs}, vf{ft}"
    f2 = ((w >> 6) & 0x1F) << 2 | (w & 3)
    if f2 < 0x10 or 0x18 <= f2 <= 0x1B:
        k = f2 >> 2 if f2 < 0x10 else 6
        return f"{S2BC.get(k, '?')}{BC[f2 & 3]}.{dest} ACC, vf{fs}, vf{ft}{BC[f2 & 3]}"
    n = S2.get(f2, f"vop2_{f2:x}")
    if n in ("vdiv", "vsqrt", "vrsqrt"):
        fsf, ftf = BC[(w >> 21) & 3], BC[(w >> 23) & 3]
        return f"{n} Q, vf{fs}{fsf}, vf{ft}{ftf}" if n != "vsqrt" else f"{n} Q, vf{ft}{ftf}"
    if n in ("vnop", "vwaitq"): return n
    if n.startswith(("vmula", "vadda", "vsuba", "vmadda", "vmsuba", "vopmula")): return f"{n}.{dest} ACC, vf{fs}, vf{ft}"
    return f"{n}.{dest} vf{ft}, vf{fs}"
