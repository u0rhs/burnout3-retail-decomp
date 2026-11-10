// NONMATCHING: Construct__Q213CB3SparkArray10CSparkBankFPC19CB3SparkArrayParamsb -- retail 486 / ours 481 instructions, 98 in changed runs
// draftAB: Revenge STABS locals + E-map _SparkSetRGBAQ inline x4, GtMath::Max chain, explicit batch counts, lpSubArray/lnPackedLifetime before the header stores; left: retail treats lanSubArrayBatchCounts as address-taken (non-folded &lan[i], field_4 reloaded after its stores: a struct-pointer probe reproduces the reload, length 486) -- source form not found
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] written from the asm: every store, branch and DMA/VIF word accounted for (logic mirrors Revenge's locals)

// CB3SparkArray::CSparkBank::Construct(const CB3SparkArrayParams*, bool) -- hand-written (draftAB) from retail asm.
// [L] locals: Revenge STABS of CB4SparkArray::CSparkBank::Construct (B4SparkRendererPS2.cpp); [C] inline name
// _SparkSetRGBAQ(const RwRGBAReal*) from the E map (research/E_B3O0PCH_symbols.csv 0x278EE0). Layout [G].
#include "b3/GtMath.h"

struct RwRGBAReal {
    float red;
    float green;
    float blue;
    float alpha;
};

struct CB3SparkArrayParams {
    RwRGBAReal field_0[4];
    float field_40[4];
    unsigned char pad_50[0x10];
    int field_60;
    int field_64;
};

struct UnkStruct_00264170_e {
    unsigned char pad_0[0x90];
};

struct UnkStruct_00264170_s {
    UnkStruct_00264170_e * field_0;
    int field_4;
    int field_8;
    float field_C;
};

class CB3SparkArray {
public:
    class CSparkBank {
    public:
        void Construct(const CB3SparkArrayParams *, bool);
        UnkStruct_00264170_s field_0[4];
        int field_40;
        float field_44;
        void * field_48;
    };
};

extern float D_004E115C;
extern "C" void * Alloc__17CB3EffectsManagerFUiUi(unsigned int, unsigned int);
extern "C" void * memset(void *, int, unsigned int);
extern "C" void SyncDCache(void *, void *);

static inline unsigned long _SparkSetRGBAQ(const RwRGBAReal * lpRGBA)
{
    unsigned long lu64RGBAQ = ((unsigned long)(int)(lpRGBA->red * 64.0f + 0.5f))
        | ((unsigned long)(int)(lpRGBA->green * 64.0f + 0.5f) << 8)
        | ((unsigned long)(int)(lpRGBA->blue * 64.0f + 0.5f) << 16)
        | ((unsigned long)(int)(lpRGBA->alpha * 128.0f + 0.5f) << 24)
        | 0x3F80000000000000UL;
    return lu64RGBAQ;
}

// 0x00264170
void CB3SparkArray::CSparkBank::Construct(const CB3SparkArrayParams * lpParams, bool lbCrashBank)
{
    unsigned long lau64SubArrayColours[4];
    int lnDMADataNumQW;
    int lnAllocNumQW;
    int lnAllocSize;
    unsigned long * lpDMAPtr;
    int lnNumSparks;
    int lnNumBatches;
    int lnSubArray;
    UnkStruct_00264170_s * lpSubArray;
    int lnBatch;
    int lnBatchSize;
    float lrLifetimeScale;
    int lnPackedLifetime;
    int lnITOP;
    UnkStruct_00264170_e * lpBatchAddr;
    int lanSubArrayBatchCounts[4];
    float lrNumOverSumLifetime;

    if (lbCrashBank) {
        lnNumSparks = lpParams->field_64;
    } else {
        lnNumSparks = lpParams->field_60;
    }
    if (lnNumSparks == 0) {
        field_48 = 0;
        field_40 = 0;
        memset(this, 0, 0x40);
        return;
    }
    float lrMax = GtMath::Max(lpParams->field_40[3], GtMath::Max(lpParams->field_40[2], GtMath::Max(lpParams->field_40[0], lpParams->field_40[1])));
    lrNumOverSumLifetime = (float)lnNumSparks / (lpParams->field_40[0] + lpParams->field_40[1] + lpParams->field_40[2] + lpParams->field_40[3]);
    field_0[0].field_4 = ((int)(lpParams->field_40[0] * lrNumOverSumLifetime) + 3) & ~3;
    lrLifetimeScale = D_004E115C / lrMax;
    field_0[1].field_4 = ((int)(lpParams->field_40[1] * lrNumOverSumLifetime) + 3) & ~3;
    field_0[2].field_4 = ((int)(lpParams->field_40[2] * lrNumOverSumLifetime) + 3) & ~3;
    field_0[3].field_4 = ((int)(lpParams->field_40[3] * lrNumOverSumLifetime) + 3) & ~3;
    field_0[0].field_C = lpParams->field_40[0];
    field_0[1].field_C = lpParams->field_40[1];
    field_0[2].field_C = lpParams->field_40[2];
    field_0[3].field_C = lpParams->field_40[3];
    lau64SubArrayColours[0] = _SparkSetRGBAQ(&lpParams->field_0[0]);
    lau64SubArrayColours[1] = _SparkSetRGBAQ(&lpParams->field_0[1]);
    lau64SubArrayColours[2] = _SparkSetRGBAQ(&lpParams->field_0[2]);
    lau64SubArrayColours[3] = _SparkSetRGBAQ(&lpParams->field_0[3]);
    lanSubArrayBatchCounts[0] = (field_0[0].field_4 / 4 + 10) / 11;
    lanSubArrayBatchCounts[1] = (field_0[1].field_4 / 4 + 10) / 11;
    lanSubArrayBatchCounts[2] = (field_0[2].field_4 / 4 + 10) / 11;
    lanSubArrayBatchCounts[3] = (field_0[3].field_4 / 4 + 10) / 11;
    lnDMADataNumQW = 1;
    lnDMADataNumQW += 12;
    lnDMADataNumQW += (lanSubArrayBatchCounts[0] + lanSubArrayBatchCounts[1] + lanSubArrayBatchCounts[2] + lanSubArrayBatchCounts[3]) * 2;
    lnAllocNumQW = lnDMADataNumQW + ((field_0[0].field_4 + field_0[1].field_4 + field_0[2].field_4 + field_0[3].field_4) / 4) * 9;
    lnAllocSize = lnAllocNumQW * 16;
    field_48 = Alloc__17CB3EffectsManagerFUiUi(lnAllocSize, 0x80);
    memset(field_48, 0, lnAllocSize);
    field_0[0].field_0 = (UnkStruct_00264170_e *)((char *)field_48 + lnDMADataNumQW * 16);
    field_0[1].field_0 = field_0[0].field_0 + field_0[0].field_4 / 4;
    field_0[2].field_0 = field_0[1].field_0 + field_0[1].field_4 / 4;
    field_0[3].field_0 = field_0[2].field_0 + field_0[2].field_4 / 4;
    lpDMAPtr = (unsigned long *)field_48;
    *lpDMAPtr++ = 0x10000000;
    *lpDMAPtr++ = 0x0500000000000000UL;
    for (lnSubArray = 0; lnSubArray < 4; lnSubArray++) {
        lpSubArray = &field_0[lnSubArray];
        lnPackedLifetime = (int)(lrLifetimeScale * lpSubArray->field_C) & ~0xF;
        *lpDMAPtr++ = 0x10000002;
        *lpDMAPtr++ = 0x5000000210000000UL;
        *lpDMAPtr++ = 0x1000000000008001UL;
        *lpDMAPtr++ = 0xE;
        *lpDMAPtr++ = lau64SubArrayColours[lnSubArray];
        *lpDMAPtr++ = 1;
        lnNumBatches = lanSubArrayBatchCounts[lnSubArray];
        for (lnBatch = 0; lnBatch < lnNumBatches; lnBatch++) {
            lpBatchAddr = lpSubArray->field_0 + lnBatch * 11;
            if (lnBatch < lnNumBatches - 1) {
                lnBatchSize = 11;
            } else {
                lnBatchSize = lpSubArray->field_4 / 4 - (lnNumBatches - 1) * 11;
            }
            *lpDMAPtr++ = ((unsigned long)(unsigned int)lpBatchAddr << 32) | (long)(int)(0x30000000 | (lnBatchSize * 9));
            *lpDMAPtr++ = ((unsigned long)(unsigned int)(0x6C008000 | ((lnBatchSize * 9) << 16)) << 32) | 0x01000101;
            if (lnSubArray < 3 || lnBatch < lnNumBatches - 1) {
                *lpDMAPtr++ = 0x10000000;
            } else {
                *lpDMAPtr++ = 0x60000000;
            }
            lnITOP = lnBatchSize | lnPackedLifetime;
            if (lnSubArray == 0 && lnBatch == 0 && !lbCrashBank) {
                *lpDMAPtr++ = (unsigned long)(unsigned int)(0x04000000 | lnITOP) | 0x1500000000000000UL;
            } else {
                *lpDMAPtr++ = (unsigned long)(unsigned int)(0x04000000 | lnITOP) | 0x1700000000000000UL;
            }
        }
    }
    SyncDCache(field_48, (char *)field_48 + lnAllocSize - 1);
}

