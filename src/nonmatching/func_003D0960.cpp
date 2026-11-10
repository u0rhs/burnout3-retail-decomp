// NONMATCHING: func_003D0960 -- retail 128 / ours 128 instructions, 49 in changed runs
// a85: HackConvertString; control flow and instruction count exact (128/128), 49 changed = register allocation only: retail keeps ch in s5, compare/tmp in s4, out in s1, prev in s0 (daddiu 0x34), first in t8; ours puts ch in s4, tmp in s1, out in t9. 'slt at' vs materialised s4 compare also differs. Tried int tmp, decl orders, operand order.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

// [L] DNAT: CB3StylisedText2dObject::HackConvertString(unsigned short*,int,const unsigned short*,bool) (research/proto/new_names.csv, medium)
extern "C" void CopyN__10CGtUnicodeFPUsiPCUs(unsigned short *, int, const unsigned short *);

// 0x003D0960
extern "C" void func_003D0960(unsigned short * dst, int max, const unsigned short * src, bool flag)
{
    const unsigned short * end = src;
    while (*end != 0) {
        if (*end == 0x5C) {
            CopyN__10CGtUnicodeFPUsiPCUs(dst, max, src);
            return;
        }
        end++;
    }
    const unsigned short * brk = src;
    if (flag) {
        brk = end;
        while (src < brk) {
            brk--;
            if (*brk == 0x20) {
                brk++;
                break;
            }
        }
    }
    unsigned short code;
    int tmp;
    unsigned long prev = 0x34;
    unsigned short * out = dst;
    bool first = true;
    int limit = max - 1;
    do {
        unsigned short ch = *src;
        bool isSpace = ch == 0x20;
        if (!isSpace) {
            if (first || (ch >= 0x30 && ch < 0x3A) || ch == 0x21 || ch == 0x3F) {
                tmp = src < brk ? 0x32 : 0x34;
                code = tmp;
                first = false;
            } else {
                tmp = src < brk ? 0x31 : 0x33;
                code = tmp;
            }
            if (code != (unsigned short)prev) {
                if (!(out - dst < limit)) goto done;
                out[0] = 0x5C;
                prev = code;
                out[1] = code;
                out += 2;
            }
        }
        if (isSpace || *src == 0x2D) {
            first = true;
        }
        if (!(out - dst < limit)) goto done;
        *out = *src;
        src++;
        out++;
    } while (src < end);
done:
    *out = 0;
}
