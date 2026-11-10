// CB3CrashCombo::CalculateCrashDescription() -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3CrashCombo.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a150: extern C self struct; goto-free else-if chain; switch cases in ascending source order; bool flag).

struct UnkStruct_00361900_car {
    unsigned char pad_0[0x1914];
    int field_1914;
};
struct UnkStruct_00361900_obj {
    unsigned char pad_0[0x215];
    signed char field_215;
    unsigned char pad_216[0x220A];
    int field_2420;
};
struct UnkStruct_00361900 {
    unsigned char pad_0[0x11B];
    unsigned char field_11B;
    unsigned char field_11C;
    unsigned char pad_11D[0x53];
    int field_170[3];
    unsigned char pad_17C[0x20];
    int field_19C[7];
    int field_1B8;
    unsigned char pad_1BC[0xC];
    float field_1C8;
    unsigned char pad_1CC[0x4];
    int field_1D0;
    float field_1D4;
    unsigned char pad_1D8[0x2C];
    float field_204[7];
    unsigned char pad_220[0x4];
    UnkStruct_00361900_car * field_224;
    unsigned char pad_228[0x8];
    UnkStruct_00361900_obj * field_230;
    unsigned char pad_234[0xFC];
    int field_330;
    unsigned char pad_334[0x8];
    int field_33C;
    int field_340;
    int field_344;
};
extern "C" void OnCrashComboResult__13CB3ScoreBonusF21ECrashComboEvaluation(void *, void *);
extern "C" void CalculateCrashDescription__13CB3CrashComboFv(UnkStruct_00361900 * self)
{
    if (self->field_224->field_1914 != 0) return;
    self->field_170[2] = self->field_170[2] / 2;
    int i;
    float maxF = 0.0f;
    int maxFi = 0;
    int maxIi = 0;
    int maxI = 0;
    for (i = 0; i < 7; i++) {
        float f = self->field_204[i];
        if (f > maxF) { maxF = f; maxFi = i; }
        int v = self->field_19C[i];
        if (maxI < v) { maxI = v; maxIi = i; }
    }
    int best = -1;
    int bestVal = 0;
    int second = -1;
    for (i = 0; i < 3; i++) {
        int v = self->field_170[i];
        if (!(v < bestVal)) { second = best; bestVal = v; best = i; }
    }
    bool flag = false;
    if (second != -1) {
        int sv = self->field_170[second];
        if (sv >= 2) {
            int bv = self->field_170[best];
            int diff = bv - sv;
            if (!(diff > bv / 3)) flag = true;
        }
    }
    int half = self->field_170[0] / 2;
    int ok = self->field_1B8 >= half;
    int ev = 0x1F;
    if (self->field_11B != 0) {
        ev = 0x1D;
    } else if (!(self->field_33C < 3)) {
        ev = 0x1C;
    } else if (!(self->field_340 < 5)) {
        ev = 0x1B;
    } else if (!(self->field_344 < 3)) {
        ev = 0x1A;
    } else if (!(self->field_1D4 <= 15.0f) && self->field_1D0 != 0) {
        switch (self->field_1D0) {
        case 1: ev = 0x19; break;
        case 2: ev = 0x15; break;
        case 3: ev = 0x18; break;
        case 4: ev = 0x17; break;
        case 5: case 6: ev = 0x16; break;
        }
    } else {
        if (maxFi != 0 && maxFi != 3 && maxFi != 4 && !(self->field_204[maxFi] <= 50.0f)) {
            switch (maxFi) {
            case 1: ev = 0x13; break;
            case 2: ev = 0x12; break;
            case 5: ev = 0x14; break;
            case 6: ev = 0x14; break;
            }
        } else if (maxIi == 2 && !(self->field_19C[maxIi] * 180 < 540)) {
            ev = 0x11;
        } else if (!(self->field_1C8 <= 3.5f)) {
            ev = 0xD;
        } else if (best != -1 && self->field_170[best] >= 2) {
            int t2 = self->field_170[best];
            if (!flag) {
                if (t2 < 3) {
                    switch (best) {
                    case 0: ev = ok ? 0xB : 9; break;
                    case 1: ev = 0xC; break;
                    case 2: ev = 8; break;
                    }
                } else {
                    switch (best) {
                    case 0: ev = ok ? 0xB : 0xA; break;
                    case 1: ev = 0xC; break;
                    case 2: ev = 7; break;
                    }
                }
            } else {
                if (best == 2) {
                    if (second == 0) ev = ok ? 0xF : 0xE; else ev = 0x10;
                } else if (second == 2) {
                    if (best == 0) ev = ok ? 0xF : 0xE; else ev = 0x10;
                }
            }
        } else if (self->field_11C == 0) {
            if (self->field_330 > 0) {
                UnkStruct_00361900_obj * o = self->field_230;
                int st = o->field_215;
                switch (st) {
                case 1: case 2: case 3: ev = 0; break;
                case 4: case 5: {
                    int k = o->field_2420;
                    switch (k) {
                    case 1: ev = 2; break;
                    case 2: ev = 3; break;
                    case 3: ev = 3; break;
                    case 4: ev = 4; break;
                    case 5: ev = 5; break;
                    case 0xB: ev = 6; break;
                    }
                    break;
                }
                }
            }
        } else {
            ev = 1;
        }
    }
    if (ev != 0x1F) {
        OnCrashComboResult__13CB3ScoreBonusF21ECrashComboEvaluation((char *)self->field_224 + 0x11E4, (void *)(ev));
    }
}
