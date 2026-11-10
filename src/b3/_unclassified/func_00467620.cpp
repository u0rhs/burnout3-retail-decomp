// Hand-written; the lifter refused it (entry-jump goto loops, i<=7, unsigned int mask).

// Hand-written; the lifter refused it (a176: slot selection by bit mask; goto-joined tail).

struct UnkStruct_00467620_i {
    unsigned short field_0;
    unsigned char pad_2[0xE];
    void (*field_10)(int);
};
struct UnkStruct_00467620_s {
    int field_0;
    int field_4;
    int field_8;
    unsigned char pad_C[0x4];
    int field_10;
    unsigned char pad_14[0x40];
    char field_54[0x18];
    int field_6C;
};
struct UnkStruct_D_004E2FCC_a { UnkStruct_00467620_i * field_0; };
struct UnkStruct_D_004E2FC8_a { UnkStruct_00467620_s * field_0; };
extern UnkStruct_D_004E2FCC_a D_004E2FCC;
extern UnkStruct_D_004E2FC8_a D_004E2FC8;
extern "C" void * memset(void *, int, unsigned int);
extern "C" char * strcpy(char *, const char *);
extern "C" void func_00462150(int);

static inline int func_00467620_inl1()
{
    return D_004E2FCC.field_0 != 0;
}

// 0x00467620
extern "C" int func_00467620(const char * name, int slot, int mode)
{
    unsigned int mask;
    int cnt;
    int i;
    if (func_00467620_inl1() == 0) return 2;
    if (name == 0) return 12;
    if (!(slot == -1 || (slot < 8 && 0 <= slot))) return 9;
    if (slot != -1) {
        if (((unsigned short)(1 << slot) & D_004E2FCC.field_0->field_0) == 0) return 11;
    }
    if (D_004E2FC8.field_0->field_0 != 0) return 13;
    memset((char *)D_004E2FC8.field_0 + 0xC, 0, 0x60);
    if (slot == -1) {
        mask = D_004E2FCC.field_0->field_0;
        cnt = 0;
        i = 0;
        goto t1;
    b1:
        if (((unsigned short)(1 << (unsigned short)i) & mask) != 0) cnt++;
        i++;
    t1:
        if (i <= 7) goto b1;
        if (cnt == 1) {
            i = 0;
            goto t2;
        b2:
            if (((unsigned short)(1 << (unsigned short)i) & mask) != 0) goto d2;
            i++;
        t2:
            if (i <= 7) goto b2;
        d2:;
            D_004E2FC8.field_0->field_10 = i;
            D_004E2FC8.field_0->field_0 = 6;
        } else {
            if (mode == 0) {
                i = 0;
                goto t3;
            b3:
                if (((unsigned short)(1 << (unsigned short)i) & mask) != 0) goto d3;
                i++;
            t3:
                if (i <= 7) goto b3;
            d3:;
                D_004E2FC8.field_0->field_10 = i;
                D_004E2FC8.field_0->field_0 = 3;
            } else if (mode == 1) {
                i = 7;
                goto t4;
            b4:
                if (((unsigned short)(1 << (unsigned short)i) & mask) != 0) goto d4;
                i--;
            t4:
                if (i >= 0) goto b4;
            d4:;
                D_004E2FC8.field_0->field_10 = i;
                D_004E2FC8.field_0->field_0 = 3;
            } else {
                return 12;
            }
        }
    } else {
        D_004E2FC8.field_0->field_10 = slot;
        D_004E2FC8.field_0->field_0 = 6;
    }
    {
        int t = D_004E2FC8.field_0->field_0;
        if (t != 11 && t != 12 && t != 13) D_004E2FC8.field_0->field_8 = 0;
    }
    strcpy(D_004E2FC8.field_0->field_54, name);
    D_004E2FC8.field_0->field_6C = mode;
    func_00462150(1);
    D_004E2FCC.field_0->field_10(D_004E2FC8.field_0->field_10);
    D_004E2FC8.field_0->field_4 = 1;
    return 0;
}
