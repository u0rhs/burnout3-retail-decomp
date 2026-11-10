// NONMATCHING: ezNetCtlRecreateIfstat -- retail 174 / ours 174 instructions, 4 in changed runs
// 174/174 instrs, layout exact; only 4 branch-delay-slot fills differ (retail hoists the target block's first insn into the delay slot: move a0,s3 after strlen bnez; addiu a0,s1,0x10C at beq 3; li v1,-0x12E at strcmp beqz; li v1,-0x1F3 at strcmp bnez). Cause unknown (switch / != 0 restructures tried)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

extern "C" {
struct UnkStruct_ezStat { unsigned char pad_0[0x28]; int field_28; int field_2C; };
struct UnkStruct_ezOut { int field_0; int field_4; unsigned char pad_8[0x1F4]; };
struct UnkStruct_ppp { char *field_0; int field_4; int field_8; };
extern UnkStruct_ppp pppStatusList[];
extern char D_004C6AB8[];
extern char D_004C6AC0[];
extern char D_004C6AD0[];
extern char D_004C6AD8[];
extern char D_004C6AE8[];
extern char D_004C6AF8[];
extern char D_004C6B08[];
extern char D_004C6B18[];
extern char D_004C6B20[];
extern char D_004C6B30[];
void *memset(void *, int, unsigned int);
unsigned int strlen(const char *);
char *strchr(const char *, int);
char *strncpy(char *, const char *, unsigned int);
int strncmp(const char *, const char *, unsigned int);
int strcmp(const char *, const char *);
// 0x00344F90
void ezNetCtlRecreateIfstat(char *s, UnkStruct_ezStat *st, UnkStruct_ezOut *out)
{
    char *p;
    memset(out, 0, 0x1FC);
    if (strlen(s) != 0) {
        p = strchr(s, 0x20);
        if (p != 0) p = p + 1;
        if (st->field_28 == 3) {
            strncpy((char *)out + 0x10C, s, 0x50);
            strncpy((char *)out + 0xC, s + 0x50, 0x20);
            strncpy((char *)out + 0x15C, s + 0x50, 0x20);
            strncpy((char *)out + 0x17C, s + 0x80, 0x80);
        } else if (st->field_28 == 4) {
            strncpy((char *)out + 8, s + 0x80, 0x80);
        }
        if (strncmp(s, D_004C6AB8, 5) == 0) {
            if (strcmp(p, D_004C6AD0) == 0) {
                st->field_2C = -0x194;
            } else if (strcmp(p, D_004C6AD8) == 0) {
                st->field_2C = -0x191;
            } else if (strcmp(p, D_004C6AE8) == 0) {
                st->field_2C = -0x191;
            } else if (strcmp(p, D_004C6AF8) == 0) {
                st->field_2C = -0x191;
            } else if (strcmp(p, D_004C6B08) == 0) {
                st->field_2C = -0x192;
            } else {
                st->field_2C = -0x1F3;
            }
            out->field_0 = 0x12D;
        } else if (strcmp(s, D_004C6AC0) == 0) {
            st->field_2C = -0x12E;
        } else {
            UnkStruct_ppp *e = pppStatusList;
            while (e->field_0 != 0) {
                if (strcmp(p, e->field_0) == 0) {
                    if (strncmp(s, D_004C6B18, 5) == 0) {
                        int v = e->field_4;
                        out->field_4 = v;
                        out->field_0 = v;
                        break;
                    } else if (strncmp(s, D_004C6B20, 10) == 0) {
                        st->field_2C = e->field_8;
                        break;
                    } else if (strncmp(s, D_004C6B30, 7) == 0) {
                        st->field_2C = e->field_8;
                        break;
                    }
                    return;
                }
                e = e + 1;
            }
        }
    }
}
}
