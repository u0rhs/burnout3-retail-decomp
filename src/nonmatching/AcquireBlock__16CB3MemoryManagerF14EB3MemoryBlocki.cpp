// NONMATCHING: AcquireBlock__16CB3MemoryManagerF14EB3MemoryBlocki -- retail 643 / ours 643 instructions, 167 in changed runs
// 643 instrs both; 167 changed. Logic exact (23-case jtbl; per-slot: v=slot+4; if (v>=0&&v!=lay) r=0; else if (slot==0) {slot=-1; r=slot+12}). Source is generated from Release's slot map (build/vt/hand/a177_gen50.py). Open: (1) 3-arm layout cases (1,3,5): retail has layout-0 arm inline after 'bnez a1', ours puts it out of line ('beqz a1'); (2) simple W cases: ours CSEs &W(A) into v1 (addiu v1,a0,A) in the set-block, retail uses direct lw/sw A(a0).
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// [L] DNAT: CB3MemoryManager::AcquireBlock(EB3MemoryBlock, int) (research/proto/new_names.csv)
struct UnkStruct_Acq { unsigned char pad_0[0x984]; int field_984; };
#define W(off) (*(int *)((char *)self + (off)))
#define WI(off) (((int *)((char *)self + (off)))[p1 * 4])
// 0x003E7D40
extern "C" int AcquireBlock__16CB3MemoryManagerF14EB3MemoryBlocki(UnkStruct_Acq *self, int block, int p1)
{
    switch (block) {
    case 0:
        {
            int lay = self->field_984;
            {
                int v = W(0x58);
                int r;
                if (v >= 0 && v != lay) r = 0;
                else if (W(0x54) == 0) { W(0x54) = -1; r = W(0x60); }
                else r = 0;
                return r;
            }
        }
    case 1:
        {
            int lay = self->field_984;
            switch (lay) {
            default:
                {
                    int v = WI(0x108);
                    int r;
                    if (v >= 0 && v != lay) r = 0;
                    else if (WI(0x104) == 0) { WI(0x104) = -1; r = WI(0x110); }
                    else r = 0;
                    return r;
                }
            case 2:
                {
                    int v = WI(0x428);
                    int r;
                    if (v >= 0 && v != lay) r = 0;
                    else if (WI(0x424) == 0) { WI(0x424) = -1; r = WI(0x430); }
                    else r = 0;
                    return r;
                }
            case 0:
                {
                    int v = WI(0x8E8);
                    int r;
                    if (v >= 0 && v != lay) r = 0;
                    else if (WI(0x8E4) == 0) { WI(0x8E4) = -1; r = WI(0x8F0); }
                    else r = 0;
                    return r;
                }
            }
        }
    case 2:
        {
            int lay = self->field_984;
            if (lay == 2)
            {
                int v = WI(0x828);
                int r;
                if (v >= 0 && v != lay) r = 0;
                else if (WI(0x824) == 0) { WI(0x824) = -1; r = WI(0x830); }
                else r = 0;
                return r;
            }
            else
            {
                int v = WI(0x368);
                int r;
                if (v >= 0 && v != lay) r = 0;
                else if (WI(0x364) == 0) { WI(0x364) = -1; r = WI(0x370); }
                else r = 0;
                return r;
            }
        }
    case 3:
        {
            int lay = self->field_984;
            switch (lay) {
            default:
                {
                    int v = W(0x168);
                    int r;
                    if (v >= 0 && v != lay) r = 0;
                    else if (W(0x164) == 0) { W(0x164) = -1; r = W(0x170); }
                    else r = 0;
                    return r;
                }
            case 2:
                {
                    int v = W(0x488);
                    int r;
                    if (v >= 0 && v != lay) r = 0;
                    else if (W(0x484) == 0) { W(0x484) = -1; r = W(0x490); }
                    else r = 0;
                    return r;
                }
            case 0:
                {
                    int v = W(0x918);
                    int r;
                    if (v >= 0 && v != lay) r = 0;
                    else if (W(0x914) == 0) { W(0x914) = -1; r = W(0x920); }
                    else r = 0;
                    return r;
                }
            }
        }
    case 5:
        {
            int lay = self->field_984;
            switch (lay) {
            default:
                {
                    int v = W(0x178);
                    int r;
                    if (v >= 0 && v != lay) r = 0;
                    else if (W(0x174) == 0) { W(0x174) = -1; r = W(0x180); }
                    else r = 0;
                    return r;
                }
            case 2:
                {
                    int v = W(0x498);
                    int r;
                    if (v >= 0 && v != lay) r = 0;
                    else if (W(0x494) == 0) { W(0x494) = -1; r = W(0x4A0); }
                    else r = 0;
                    return r;
                }
            case 0:
                {
                    int v = W(0x938);
                    int r;
                    if (v >= 0 && v != lay) r = 0;
                    else if (W(0x934) == 0) { W(0x934) = -1; r = W(0x940); }
                    else r = 0;
                    return r;
                }
            }
        }
    case 6:
        {
            int lay = self->field_984;
            if (lay == 2)
            {
                int v = WI(0x4A8);
                int r;
                if (v >= 0 && v != lay) r = 0;
                else if (WI(0x4A4) == 0) { WI(0x4A4) = -1; r = WI(0x4B0); }
                else r = 0;
                return r;
            }
            else
            {
                int v = WI(0x188);
                int r;
                if (v >= 0 && v != lay) r = 0;
                else if (WI(0x184) == 0) { WI(0x184) = -1; r = WI(0x190); }
                else r = 0;
                return r;
            }
        }
    case 7:
        {
            int lay = self->field_984;
            if (lay == 2)
            {
                int v = WI(0x5D8);
                int r;
                if (v >= 0 && v != lay) r = 0;
                else if (WI(0x5D4) == 0) { WI(0x5D4) = -1; r = WI(0x5E0); }
                else r = 0;
                return r;
            }
            else
            {
                int v = WI(0x228);
                int r;
                if (v >= 0 && v != lay) r = 0;
                else if (WI(0x224) == 0) { WI(0x224) = -1; r = WI(0x230); }
                else r = 0;
                return r;
            }
        }
    case 8:
        {
            int lay = self->field_984;
            {
                int v = W(0x68);
                int r;
                if (v >= 0 && v != lay) r = 0;
                else if (W(0x64) == 0) { W(0x64) = -1; r = W(0x70); }
                else r = 0;
                return r;
            }
        }
    case 9:
        {
            int lay = self->field_984;
            if (lay == 2)
            {
                int v = W(0x808);
                int r;
                if (v >= 0 && v != lay) r = 0;
                else if (W(0x804) == 0) { W(0x804) = -1; r = W(0x810); }
                else r = 0;
                return r;
            }
            else
            {
                int v = W(0x348);
                int r;
                if (v >= 0 && v != lay) r = 0;
                else if (W(0x344) == 0) { W(0x344) = -1; r = W(0x350); }
                else r = 0;
                return r;
            }
        }
    case 10:
        {
            int lay = self->field_984;
            {
                int v = W(0x18);
                int r;
                if (v >= 0 && v != lay) r = 0;
                else if (W(0x14) == 0) { W(0x14) = -1; r = W(0x20); }
                else r = 0;
                return r;
            }
        }
    case 11:
        {
            int lay = self->field_984;
            {
                int v = W(0x28);
                int r;
                if (v >= 0 && v != lay) r = 0;
                else if (W(0x24) == 0) { W(0x24) = -1; r = W(0x30); }
                else r = 0;
                return r;
            }
        }
    case 13:
        {
            int lay = self->field_984;
            if (lay == 2)
            {
                int v = W(0x818);
                int r;
                if (v >= 0 && v != lay) r = 0;
                else if (W(0x814) == 0) { W(0x814) = -1; r = W(0x820); }
                else r = 0;
                return r;
            }
            else
            {
                int v = W(0x358);
                int r;
                if (v >= 0 && v != lay) r = 0;
                else if (W(0x354) == 0) { W(0x354) = -1; r = W(0x360); }
                else r = 0;
                return r;
            }
        }
    case 12:
        {
            int lay = self->field_984;
            {
                int v = W(0x38);
                int r;
                if (v >= 0 && v != lay) r = 0;
                else if (W(0x34) == 0) { W(0x34) = -1; r = W(0x40); }
                else r = 0;
                return r;
            }
        }
    case 14:
        {
            int lay = self->field_984;
            {
                int v = W(0x8);
                int r;
                if (v >= 0 && v != lay) r = 0;
                else if (W(0x4) == 0) { W(0x4) = -1; r = W(0x10); }
                else r = 0;
                return r;
            }
        }
    case 15:
        {
            int lay = self->field_984;
            {
                int v = W(0x48);
                int r;
                if (v >= 0 && v != lay) r = 0;
                else if (W(0x44) == 0) { W(0x44) = -1; r = W(0x50); }
                else r = 0;
                return r;
            }
        }
    case 16:
        {
            int lay = self->field_984;
            {
                int v = W(0x948);
                int r;
                if (v >= 0 && v != lay) r = 0;
                else if (W(0x944) == 0) { W(0x944) = -1; r = W(0x950); }
                else r = 0;
                return r;
            }
        }
    case 17:
        {
            int lay = self->field_984;
            {
                int v = W(0x968);
                int r;
                if (v >= 0 && v != lay) r = 0;
                else if (W(0x964) == 0) { W(0x964) = -1; r = W(0x970); }
                else r = 0;
                return r;
            }
        }
    case 20:
        {
            int lay = self->field_984;
            {
                int v = W(0x958);
                int r;
                if (v >= 0 && v != lay) r = 0;
                else if (W(0x954) == 0) { W(0x954) = -1; r = W(0x960); }
                else r = 0;
                return r;
            }
        }
    case 18:
        {
            int lay = self->field_984;
            {
                int v = W(0x978);
                int r;
                if (v >= 0 && v != lay) r = 0;
                else if (W(0x974) == 0) { W(0x974) = -1; r = W(0x980); }
                else r = 0;
                return r;
            }
        }
    case 19:
        {
            int lay = self->field_984;
            {
                int v = W(0x908);
                int r;
                if (v >= 0 && v != lay) r = 0;
                else if (W(0x904) == 0) { W(0x904) = -1; r = W(0x910); }
                else r = 0;
                return r;
            }
        }
    case 21:
        {
            int lay = self->field_984;
            {
                int v = WI(0x78);
                int r;
                if (v >= 0 && v != lay) r = 0;
                else if (WI(0x74) == 0) { WI(0x74) = -1; r = WI(0x80); }
                else r = 0;
                return r;
            }
        }
    case 22:
        {
            int lay = self->field_984;
            {
                int v = W(0xF8);
                int r;
                if (v >= 0 && v != lay) r = 0;
                else if (W(0xF4) == 0) { W(0xF4) = -1; r = W(0x100); }
                else r = 0;
                return r;
            }
        }
    case 4:
        break;
    }
    return 0;
}

