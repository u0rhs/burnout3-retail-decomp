// Hand-written; the lifter refused it (SJIS-ish char convert; manual count-down byte copy of 0x21 table).

struct UnkStruct_00466E80_tbl { signed char b[0x21]; };
extern UnkStruct_00466E80_tbl D_004B1390;

// 0x00466E80
extern "C" void func_00466E80(const signed char *s, unsigned short *out)
{
    unsigned char n = 0;
    UnkStruct_00466E80_tbl tbl;
    { const signed char *sp_ = D_004B1390.b; signed char *dp_ = tbl.b; int k = 0x21; do { *dp_ = *sp_; k--; sp_++; dp_++; } while (k > 0); }
    unsigned short c;
    unsigned short r;
    while ((c = (unsigned short)*s++) != 0) {
        if (c >= 0x81 && c < 0x99) {
            r = (unsigned short)((c << 8) + *s);
            s++;
        } else if (c >= 0x7B) {
            r = (unsigned short)((unsigned char)tbl.b[c - 0x5E] + 0x7FFF + 0x101);
        } else if (c >= 0x61) {
            r = (unsigned short)(c + 0x7FFF + 0x221);
        } else if (c >= 0x5B) {
            r = (unsigned short)((unsigned char)tbl.b[c - 0x44] + 0x7FFF + 0x101);
        } else if (c >= 0x41) {
            r = (unsigned short)(c + 0x7FFF + 0x220);
        } else if (c >= 0x3A) {
            r = (unsigned short)((unsigned char)tbl.b[c - 0x2A] + 0x7FFF + 0x101);
        } else if (c >= 0x30) {
            r = (unsigned short)(c + 0x7FFF + 0x220);
        } else {
            r = (unsigned short)((unsigned char)tbl.b[c - 0x20] + 0x7FFF + 0x101);
        }
        out[n++] = (unsigned short)((r >> 8) + ((r & 0xFF) << 8));
    }
}
