// NONMATCHING: func_003FD1F0 -- retail 408 / ours 390 instructions, 462 in changed runs
// fix2 (2026-11-01): first-row stylised text height 28.0f, not 30.0f [C] retail 0x3FD470 lui 0x41E0 / sw 0x3FD4C8 | Before: logic transcription (390/408), raw byte-offset stores, a0 unused param; 7-column x 5-row results cell builder (jump table on column, snprintf/ustrFromInt/ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi per column, 0x40-byte style obj copies from D_01EA6AB0.., cell = {render,size,obj}); needs typed row/cell/style structs and 0x50-byte template copies (known family blocker, see BRIEF)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)


// func_003FD1F0 -- CB3OnlineCrashResultsPage results-table row builder (a184, logic transcription; names: research/proto/new_names.csv lists it between AddRaceTime and PrepareTable).
struct UnkStruct_D_16 { unsigned char pad_0[0x10]; };
struct UnkStruct_Q { unsigned char b[0x10]; };
struct UnkStruct_D_90 { unsigned char b[0x90]; };
extern UnkStruct_D_16 D_01E90240;
extern unsigned char D_01EA5470[], D_01EA5700[], D_01EA5A80[], D_01EA6890[], D_01EA6B70[], D_0051BA44[];
extern UnkStruct_Q D_01EA6AB0, D_01EA6AF0, D_01EA6B00, D_01EA6B10;
extern long D_01EA6AC0, D_01EA6AC8, D_01EA6B20, D_01EA6B28;
extern float D_01EA6AD0, D_01EA6B30;
extern int D_01EA6AD4, D_01EA6AD8, D_01EA6ADC, D_01EA6AE0, D_01EA6B34, D_01EA6B38, D_01EA6B3C;
extern char D_004CEAC8[], D_004CEAD0[], D_004CEAD8[], D_004CEAE0[];
extern "C" int snprintf(char *, unsigned int, const char *, ...);
extern "C" void ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(char *, void *, int);
extern "C" void ustrFromInt(void *, int, int, int);
extern "C" void CopyN__10CGtUnicodeFPUsiPCUs(void *, int, int);
extern "C" int func_00271A00(void *, int);
extern "C" void func_003C1990(void *, void *, unsigned short *, void *, const void *);
extern "C" void GetStylisedTextSize__14CB3ResultsPageFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv(void *, void *, void *);
extern "C" void RenderItalicText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv(void *, void *, unsigned short *, void *, const void *);
extern "C" void GetItalicTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv(void *, void *, const void *);

// 0x003FD1F0
extern "C" void func_003FD1F0(void * unused, int r1, int r2)
{
    char * rec = (char *)D_01EA5470 + r1 * 0x38;
    char * strs = (char *)(r2 * 70);
    char * s1 = (char *)D_01EA5700 + r2 * 0x40;
    char * cells = (char *)D_01EA6890 + r2 * 12;
    int s6 = r2 * 80;
    char * s7 = (char *)D_01EA5A80 + s6;
    char buf[0x23 * 1];
    int s4;
    for (s4 = 0; s4 < 7; s4++) {
        char * dst = strs + (int)D_01EA6B70 + s4 * 0x15E;
        int s5 = 1;
        char * cell = cells + s4 * 60;
        if (*(unsigned char *)rec != 0) {
            switch (s4) {
            case 0:
                snprintf(buf, 0x23, D_004CEAC8, *(int *)(rec + 0x34));
                ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(buf, dst, 0x23);
                break;
            case 1:
                ustrFromInt(dst, *(int *)(rec + 0x18), 0, 0);
                break;
            case 2:
                ustrFromInt(dst, *(int *)(rec + 0x24), 0, 0);
                break;
            case 3: {
                int v = *(int *)(rec + 0x20);
                if (v < 0) {
                    snprintf(buf, 0x23, D_004CEAD8);
                } else if (v != 0) {
                    snprintf(buf, 0x23, D_004CEAE0);
                } else {
                    s5 = 0;
                }
                ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(buf, dst, 0x23);
                break;
            }
            case 4:
                if (*(int *)(rec + 0x20) != 0) {
                    ustrFromInt(dst, *(int *)(rec + 0x2C), 0, 0);
                } else {
                    s5 = 0;
                }
                break;
            case 5:
                snprintf(buf, 0x23, D_004CEAD0, *(int *)(rec + 0x1C));
                ConvertUTF8toUTF16Fast__10CGtUnicodeFPCUcPUsi(buf, dst, 0x23);
                break;
            }
            if (s5 == 0) {
                *(int *)(cell + 0) = 0;
                *(int *)(cell + 8) = 0;
                *(int *)(cell + 4) = 0;
                continue;
            }
            if (s4 == 0) {
                *(UnkStruct_Q *)s1 = D_01EA6AB0;
                *(long *)(s1 + 0x10) = D_01EA6AC0;
                *(long *)(s1 + 0x18) = D_01EA6AC8;
                *(float *)(s1 + 0x20) = D_01EA6AD0;
                *(int *)(s1 + 0x24) = D_01EA6AD4;
                *(int *)(s1 + 0x28) = D_01EA6AD8;
                *(int *)(s1 + 0x2C) = D_01EA6ADC;
                *(int *)(s1 + 0x30) = D_01EA6AE0;
                *(float *)(s1 + 0x10) = 1.0f;
                *(float *)(s1 + 0x14) = 0.5f;
                *(float *)(s1 + 0x20) = 28.0f;   // fix2: [C] retail 0x3FD470 lui 0x41E0 (28.0f), stored at 0x3FD4C8
                *(char **)(s1 + 0x28) = dst;
                *(void **)(cell + 0) = (void *)func_003C1990;
                *(void **)(cell + 8) = s1;
                *(void **)(cell + 4) = (void *)GetStylisedTextSize__14CB3ResultsPageFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
            } else {
                char * obj = s7 + s4 * 400;
                *(UnkStruct_Q *)(obj + 0x00) = D_01EA6AF0;
                *(UnkStruct_Q *)(obj + 0x10) = D_01EA6B00;
                *(UnkStruct_Q *)(obj + 0x20) = D_01EA6B10;
                *(long *)(obj + 0x30) = D_01EA6B20;
                *(long *)(obj + 0x38) = D_01EA6B28;
                *(float *)(obj + 0x40) = D_01EA6B30;
                *(int *)(obj + 0x44) = D_01EA6B34;
                *(int *)(obj + 0x48) = D_01EA6B38;
                *(int *)(obj + 0x4C) = D_01EA6B3C;
                *(char **)(obj + 0x48) = dst;
                *(void **)(cell + 0) = (void *)RenderItalicText__16CGt2dObjectTableFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2dPUsRC10CGt2dFramePCv;
                *(void **)(cell + 4) = (void *)GetItalicTextSize__16CGt2dObjectTableFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
                *(char **)(cell + 8) = obj;
                *(UnkStruct_Q *)(obj + 0x20) = *(UnkStruct_Q *)((char *)&D_01E90240 + 0x180);
                *(float *)(obj + 0x30) = 1.0f;
                *(float *)(obj + 0x34) = 0.5f;
            }
        } else if (s4 == 0) {
            char * d2 = dst;
            CopyN__10CGtUnicodeFPUsiPCUs(d2, 0x23, func_00271A00(D_0051BA44, 0x26B));
            *(UnkStruct_Q *)s1 = D_01EA6AB0;
            *(long *)(s1 + 0x10) = D_01EA6AC0;
            *(long *)(s1 + 0x18) = D_01EA6AC8;
            *(float *)(s1 + 0x20) = D_01EA6AD0;
            *(int *)(s1 + 0x24) = D_01EA6AD4;
            *(int *)(s1 + 0x28) = D_01EA6AD8;
            *(int *)(s1 + 0x2C) = D_01EA6ADC;
            *(int *)(s1 + 0x30) = D_01EA6AE0;
            *(float *)(s1 + 0x10) = 1.0f;
            *(float *)(s1 + 0x14) = 0.5f;
            *(float *)(s1 + 0x20) = 35.0f;
            *(void **)(cell + 0) = (void *)func_003C1990;
            *(void **)(cell + 8) = s1;
            *(void **)(cell + 4) = (void *)GetStylisedTextSize__14CB3ResultsPageFPQ29GtMathPs26CGtV2dRC10CGt2dFramePCv;
            *(char **)(s1 + 0x28) = d2;
        } else {
            char * obj = s7 + s4 * 400;
            *(UnkStruct_Q *)(obj + 0x00) = D_01EA6AF0;
            *(UnkStruct_Q *)(obj + 0x10) = D_01EA6B00;
            *(UnkStruct_Q *)(obj + 0x20) = D_01EA6B10;
            *(long *)(obj + 0x30) = D_01EA6B20;
            *(long *)(obj + 0x38) = D_01EA6B28;
            *(float *)(obj + 0x40) = D_01EA6B30;
            *(int *)(obj + 0x44) = D_01EA6B34;
            *(int *)(obj + 0x48) = D_01EA6B38;
            *(int *)(obj + 0x4C) = D_01EA6B3C;
            *(int *)(cell + 0) = 0;
            *(int *)(cell + 4) = 0;
            *(char **)(cell + 8) = obj;
            *(int *)(obj + 0x48) = 0;
        }
    }
}
