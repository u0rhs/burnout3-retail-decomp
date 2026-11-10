// NONMATCHING: func_00376A60 -- retail 319 / ours 319 instructions, 2 in changed runs
// a150: LOGIC+LAYOUT EXACT (319/319 instrs, all calls/jumps right). 5 instrs differ: scheduling of the per-row base-pointer setup (retail: rowC sq spill, 'sll v0,s3,5', then 'addu s7' for rowB; ours puts addu s7 + sq earlier). Tried 24 permutations of the rowA..D declarations, lobby/col/buf positions, const/non-const: stays 5. Shape: entry-jump row loop (goto test), else-if chain per column (not a switch), if(n<=0){empty;return false}else{main}, n is int, row structs with pad then arrays. | mwperm: 5 -> 2 (+'col = 0;') | near5: 24 rowA..D declaration permutations and moving rowB/rowD/rowC among buf/col/lobby lines: best stays 2.
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)

typedef unsigned int u_long128 __attribute__((mode(TI)));
struct UnkStruct_00376A60_s { unsigned short field_0; unsigned short field_2; };
struct UnkStruct_00376A60_fn { void * field_0; void * field_4; int field_8; };
struct UnkStruct_00376A60_rA { unsigned char pad_0[0xD38]; UnkStruct_00376A60_fn cols[5]; };
struct UnkStruct_00376A60_rB { unsigned char pad_0[0xB10]; unsigned short * txt[5]; };
struct UnkStruct_00376A60_rD { unsigned char pad_0[0xBA0]; unsigned long id; int field_8; };
struct UnkStruct_00376A60 {
    unsigned char pad_0[0xEDC];
    UnkStruct_00376A60_s field_EDC;
    unsigned char pad_EE0[0x24];
    signed char field_F04;
    unsigned char field_F05;
};
class CGtLobbyPS2DirtySock {
public:
    int GetRankingData(int, int, char*, int);
    int GetNumberRankRecords();
    unsigned char pad_0[0x10];
};
struct UnkStruct_D_01E3CD44 {
    virtual void vfunc_8(); virtual void vfunc_C(); virtual void vfunc_10(); virtual void vfunc_14();
    virtual void vfunc_18(); virtual void vfunc_1C(); virtual void vfunc_20(); virtual void vfunc_24();
    virtual void vfunc_28(); virtual void vfunc_2C(); virtual void vfunc_30(); virtual void vfunc_34();
    virtual void vfunc_38(); virtual void vfunc_3C(); virtual void vfunc_40(); virtual void vfunc_44();
    virtual void vfunc_48(); virtual void vfunc_4C(); virtual void vfunc_50(); virtual void vfunc_54();
    virtual void vfunc_58();
    unsigned char pad_4[0xC];
};
struct UnkStruct_D_01E898E8 {
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];
};
struct UnkStruct_D_01E8D490 {
    virtual void vfunc_8();
    virtual void vfunc_C();
    unsigned char pad_4[0xC];
};
struct UnkStruct_D_01E90240 { u_long128 field_0; u_long128 field_10; u_long128 field_20; };
struct UnkStruct_D_Pad16 { unsigned char pad_0[0x10]; };
struct UnkStruct_D_Byte16 { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_D_Ptr16 { void * field_0; unsigned char pad_4[0xC]; };
extern CGtLobbyPS2DirtySock D_01E3CD44;
extern UnkStruct_D_01E898E8 D_01E898E8;
extern UnkStruct_D_01E8D490 D_01E8D490;
extern UnkStruct_D_01E90240 D_01E90240;
extern UnkStruct_D_Pad16 D_01E8D450, D_004C9028;
extern UnkStruct_D_Byte16 D_01E898F2, D_01E8D49A;
extern UnkStruct_D_Ptr16 D_01E8D45C;
extern "C" int atoi(const char *);
extern "C" int strcmp(const char *, const char *);
extern "C" void ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(const char *, unsigned short *, int);
extern "C" unsigned long GetRaceVehicleGtID__23CB3HardCodedVehicleListFi(int);
extern "C" void RecalculateSize__17CB3TableComponentFv(void *);
extern "C" void func_00376880(void *, int, unsigned short *, int);
extern "C" void func_0032D080(void *, int, int, int, int);
extern "C" void Prepare__23CB3TableSelectComponentFiP16CGt2dObjectTablePC29CB3MenuComponentSelectionData(void *, int, void *, void *);
extern "C" void RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv(const void *, const void *, unsigned short*, const void *, const void*);
extern "C" void GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv(void *, const void *, const void*);
extern "C" void func_0033F620(const void *, const void *, unsigned short*, const void *, const void*);
extern "C" float GetCarIconSize__17CB3TableComponentFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv(void *, const void *, const void*);
static inline int a150_min(int a, int b) { int r; asm("pminw %0, %1, %2" : "=r"(r) : "r"(a), "r"(b)); return r; }
static inline unsigned int a150_zx(int a) { unsigned int r; asm("pextlw %0, $0, %1" : "=r"(r) : "r"(a)); return r; }

extern "C" bool func_00376A60(UnkStruct_00376A60 * self, int rank)
{
    UnkStruct_D_01E90240 * const mgr = &D_01E90240;
    if (D_01E3CD44.GetNumberRankRecords() <= 0) {
        self->field_F05 = 5;
        ((UnkStruct_D_01E3CD44 *)&D_01E3CD44)->vfunc_58();
        if (D_01E898F2.field_0 != 0) {
            ((UnkStruct_D_01E898E8 *)&D_01E898E8)->vfunc_C();
        }
        func_0032D080(&D_01E898E8, 2, 0x4EF, 0, 0);
        return false;
    } else {
        int n = (int)a150_zx(a150_min(5, D_01E3CD44.GetNumberRankRecords()));
        int row = 2;
        goto test;
    body:
        {
            UnkStruct_00376A60_rB * const rowB = (UnkStruct_00376A60_rB *)((char *)self + row * 20);
            char * const rowC = (char *)self + row * 400;
            UnkStruct_00376A60_rA * const rowA = (UnkStruct_00376A60_rA *)((char *)self + row * 60);
            UnkStruct_00376A60_rD * const rowD = (UnkStruct_00376A60_rD *)((char *)self + row * 32);
            char buf[0x20];
            int col = 0;
            CGtLobbyPS2DirtySock * const lobby = &D_01E3CD44;
            col = 0;
            do {
                if (col == 0) {
                    lobby->GetRankingData(rank, 0, buf, 0x20);
                    if (strcmp(buf, (const char *)&D_004C9028) == 0) {
                        for (int c = 0; c < 5; c++) *(u_long128 *)(rowC + c * 80 + 0x40) = mgr->field_20;
                    } else {
                        for (int c = 0; c < 5; c++) *(u_long128 *)(rowC + c * 80 + 0x40) = mgr->field_0;
                    }
                    ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(buf, rowB->txt[col], 0x20);
                    rowA->cols[col].field_0 = (void *)&RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
                    rowA->cols[col].field_4 = (void *)&GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
                } else if (col == 1) {
                    func_00376880(self, rank, rowB->txt[col], self->field_F04);
                    rowA->cols[col].field_0 = (void *)&RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
                    rowA->cols[col].field_4 = (void *)&GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
                } else if (col == 2) {
                    lobby->GetRankingData(rank, -3, buf, 0x20);
                    ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(buf, rowB->txt[col], 0x20);
                    rowA->cols[col].field_0 = (void *)&RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
                    rowA->cols[col].field_4 = (void *)&GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
                } else if (col == 3) {
                    if (self->field_F04 == 3) {
                        lobby->GetRankingData(rank, 5, buf, 0x20);
                    } else if (self->field_F04 == 8) {
                        lobby->GetRankingData(rank, 6, buf, 0x20);
                    } else {
                        lobby->GetRankingData(rank, 4, buf, 0x20);
                    }
                    ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(buf, rowB->txt[col], 0x20);
                    rowA->cols[col].field_0 = (void *)&RenderText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
                    rowA->cols[col].field_4 = (void *)&GetTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
                } else if (col == 4) {
                    rowD->field_8 = 0;
                    void ** p1 = &rowA->cols[col].field_0;
                    *p1 = 0;
                    void ** p2 = &rowA->cols[col].field_4;
                    *p2 = 0;
                    if (lobby->GetRankingData(rank, 3, buf, 0x20) == 2) {
                        int v = atoi(buf);
                        if (v >= 0 && v < 0x43) {
                            rowD->id = GetRaceVehicleGtID__23CB3HardCodedVehicleListFi(v);
                            *p1 = (void *)&func_0033F620;
                            *p2 = (void *)&GetCarIconSize__17CB3TableComponentFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
                        }
                    }
                }
                col++;
            } while (col < 5);
            row++;
            rank++;
        }
    test:
        if (row < n + 2) goto body;
        RecalculateSize__17CB3TableComponentFv(&D_01E8D450);
        if (self->field_EDC.field_0 >= n) {
            self->field_EDC.field_0 = self->field_EDC.field_0 - 1;
            self->field_EDC.field_2 = n;
        } else {
            unsigned short m = self->field_EDC.field_0;
            self->field_EDC.field_0 = m;
            self->field_EDC.field_2 = n;
        }
        if (D_01E8D49A.field_0 != 0) {
            ((UnkStruct_D_01E8D490 *)&D_01E8D490)->vfunc_C();
        }
        Prepare__23CB3TableSelectComponentFiP16CGt2dObjectTablePC29CB3MenuComponentSelectionData(&D_01E8D490, 2, D_01E8D45C.field_0, &self->field_EDC);
        return true;
    }
}


