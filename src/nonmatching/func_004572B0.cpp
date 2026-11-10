// NONMATCHING: func_004572B0 -- retail 537 / ours 495 instructions, 505 in changed runs
// fix3 (2026-11-01): slot size = field_30 + d (was d); +0x28 is a float timer advanced by dt (draft advanced field_8.x); field_57 slide: x < 0 slides on, else clamp to 0 and finish (arms were swapped, x never clamped; second object clamp too) | Before: audit1 (2026-11-01): func_003D0710's 6th argument (t1) is always 1 in retail, the draft passed t0 (2 on three of the six calls) [C] retail 0x4573EC/0x457468/0x4574E0 (behaviour_audit) | Before: lit4fix: .lit4 externs rewritten as literals; was: logic transcription (490/537): 2-slot slide animation update; control flow, calls and constants read from asm but the CGtV2d temporaries (ld/sd copies via stack) are plain floats and struct layout is [G]; retail adds/muls per component through V2 temps with sd copies; 6 copies of the func_003D0710 c
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: [L] fix3: reviewed end to end against retail asm (every branch, store, call and constant)



// func_004572B0 -- placeholder (a184, hand-matched logic). Two-slot slide-in/out animation update (Update(float dt)).
struct UnkStruct_V2 { float x; float y; };
struct UnkStruct_Obj {                       // CGt2dObject-like [G]
    UnkStruct_V2 field_0;
    UnkStruct_V2 field_8;
    unsigned char pad_10[0x18];
    float field_28;                         // fix3 [C] a float timer: lwc1/add.s/swc1 0x28 at 0x45777C, sw zero at 0x457A60
    unsigned char field_2C;
};
struct UnkStruct_004572B0 {
    void * field_0;
    int field_4;
    int field_8;
    unsigned char pad_C[4];
    UnkStruct_Obj * field_10[2];
    UnkStruct_Obj * field_18;               // [G] overlaps field_10[2]; slide objects
    UnkStruct_Obj * field_1C;
    UnkStruct_V2 field_20[2];
    UnkStruct_V2 field_30[2];
    int field_40[2];
    void * field_48;
    float field_4C;
    unsigned char field_50[2];
    unsigned char field_52[2];
    unsigned char field_54[2];
    unsigned char field_56;
    unsigned char field_57;
    unsigned char field_58;
};
struct UnkStruct_F16 { float f; unsigned char pad_4[0xC]; };
struct UnkStruct_I16 { int i; unsigned char pad_4[0xC]; };
extern UnkStruct_F16 D_004F50A0;
extern UnkStruct_I16 D_00665ED0, D_004D3580;
extern "C" int ConstructObject__10CGt2dSceneFiP10CGt2dFrame(void *, int, void *);
extern "C" void DestructObject__10CGt2dSceneFiP11CGt2dObject(void *, int, void *);
extern "C" void SetPos__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(void *, const UnkStruct_V2 *, const UnkStruct_V2 *);
extern "C" void func_003D0710(void *, const UnkStruct_V2 *, const UnkStruct_V2 *, const void *, int, int, int, void *, void *, int, float, float);

static inline unsigned char func_004572B0_inl0(UnkStruct_004572B0 * self, int obj, int s5, float yv, int t0)
{
    UnkStruct_V2 a2;
    UnkStruct_V2 a1;
    a2.x = 0.5f; a2.y = 0.0f;
    a1.x = yv; a1.y = 55.0f;
    func_003D0710(self->field_10[obj], &a1, &a2, &D_004D3580, t0, 1, 0, (void *)(D_00665ED0.i), (void *)(s5), 0, 42.0f, 3.4028235e+38f);
    return 1;
}

// 0x004572B0
extern "C" void func_004572B0(UnkStruct_004572B0 * self, float dt)
{
    int s3;
    int i;
    float remain = D_004F50A0.f - self->field_4C;
    float half = 0.5f * remain;
    float k = 0.4f - (remain - 0.4f);
    for (s3 = 0; s3 < 2; s3++) {
        unsigned char * flags = &self->field_50[s3];
        if (self->field_50[s3] == 0) continue;
        if (self->field_10[s3] == 0) continue;
        if (!(remain <= 0.8f)) {
            self->field_50[s3] = 0;
            self->field_10[s3]->field_8 = self->field_30[s3];
            self->field_10[s3]->field_0 = self->field_20[s3];
            continue;
        }
        int s5 = self->field_40[s3];
        if (s5 != 0) {
            if (self->field_52[s3] == 0 && !(remain <= 0.336f)) {
                if (s3 == 0) {
                    if (self->field_56 != 0) {
                        if (self->field_10[0] == 0) self->field_10[0] = (UnkStruct_Obj *)ConstructObject__10CGt2dSceneFiP10CGt2dFrame(self->field_0, self->field_4, self->field_48);
                        self->field_52[s3] = func_004572B0_inl0(self, 0, s5, 0.0f, 2);
                    } else if (s5 != 0) {
                        if (self->field_10[0] == 0) self->field_10[0] = (UnkStruct_Obj *)ConstructObject__10CGt2dSceneFiP10CGt2dFrame(self->field_0, self->field_4, self->field_48);
                        self->field_52[s3] = func_004572B0_inl0(self, 0, s5, -120.0f, 2);
                    } else {
                        self->field_52[s3] = 1;
                    }
                } else if (s5 != 0) {
                    if (self->field_10[1] == 0) self->field_10[1] = (UnkStruct_Obj *)ConstructObject__10CGt2dSceneFiP10CGt2dFrame(self->field_0, self->field_4, self->field_48);
                    self->field_52[s3] = func_004572B0_inl0(self, 1, s5, 120.0f, 2);
                }
            }
            if (self->field_54[s3] == 0 && !(remain <= 0.49600002f)) {
                if (s3 == 0) {
                    if (self->field_56 != 0) {
                        if (self->field_10[0] == 0) self->field_10[0] = (UnkStruct_Obj *)ConstructObject__10CGt2dSceneFiP10CGt2dFrame(self->field_0, self->field_4, self->field_48);
                        self->field_54[s3] = func_004572B0_inl0(self, 0, s5, 0.0f, 1);
                    } else if (s5 != 0) {
                        if (self->field_10[0] == 0) self->field_10[0] = (UnkStruct_Obj *)ConstructObject__10CGt2dSceneFiP10CGt2dFrame(self->field_0, self->field_4, self->field_48);
                        self->field_54[s3] = func_004572B0_inl0(self, 0, s5, -120.0f, 1);
                    } else {
                        self->field_54[s3] = 1;
                    }
                } else if (s5 != 0) {
                    if (self->field_10[1] == 0) self->field_10[1] = (UnkStruct_Obj *)ConstructObject__10CGt2dSceneFiP10CGt2dFrame(self->field_0, self->field_4, self->field_48);
                    self->field_54[s3] = func_004572B0_inl0(self, 1, s5, 120.0f, 1);
                }
            }
        }
        float m = (remain <= 0.4f) ? half : k * 0.5f;
        {
            UnkStruct_V2 d, p, q;
            d.x = self->field_30[s3].x * m;
            d.y = self->field_30[s3].y * m;
            // fix3 [C] retail 0x4576E8..0x45771C: the size grows by d (field_30 + d), not d alone
            self->field_10[s3]->field_8.x = self->field_30[s3].x + d.x;
            self->field_10[s3]->field_8.y = self->field_30[s3].y + d.y;
            p.x = self->field_20[s3].x + d.x * -0.5f;
            p.y = self->field_20[s3].y + d.y * -0.5f;
            self->field_10[s3]->field_0 = p;
        }
    }
    for (i = 0; i < 2; i++) {
        UnkStruct_Obj * o = (&self->field_18)[i];
        if (o != 0) o->field_28 += dt;     // fix3 [C] retail 0x45777C: +0x28 (the draft advanced field_8.x)
    }
    if (self->field_58 != 0) {
        UnkStruct_V2 p = self->field_18->field_0;
        if (!(p.y < 255.0f)) {
            p.y = 255.0f;
            self->field_18->field_0 = p;
            self->field_18->field_2C = 2;
            self->field_18->field_28 = 0.0f;
            self->field_58 = 0;
        } else {
            self->field_18->field_0.x = p.x;
            self->field_18->field_0.y = p.y + 200.0f / (1.0f / dt);
        }
    }
    if (self->field_57 != 0) {
        if (self->field_18 != 0) {
            UnkStruct_V2 pos;
            pos.x = self->field_18->field_0.x + self->field_18->field_8.x * 0.5f;
            pos.y = self->field_18->field_0.y + self->field_18->field_8.y * 0.0f;
            UnkStruct_V2 z; z.x = 0.5f; z.y = 0.0f;
            // fix3 [C] retail 0x457818: c.lt pos.x, 0 -> 0x457860 slides on; otherwise it is clamped to 0 and the swap ends
            // (the draft had the two arms swapped and kept the unclamped x)
            if (pos.x < 0.0f) {
                pos.x = pos.x + 120.0f / (0.8f / dt);
                SetPos__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(self->field_18, &pos, &z);
            } else {
                pos.x = 0.0f;
                SetPos__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(self->field_18, &pos, &z);
                self->field_57 = 0;
                if (self->field_1C != 0) {
                    DestructObject__10CGt2dSceneFiP11CGt2dObject(self->field_0, self->field_8, self->field_1C);
                    self->field_1C = 0;
                }
            }
        }
        if (self->field_1C != 0 && self->field_57 != 0) {
            UnkStruct_V2 pos;
            pos.x = self->field_1C->field_0.x + self->field_1C->field_8.x * 0.5f;
            pos.y = self->field_1C->field_0.y + self->field_1C->field_8.y * 0.0f;
            UnkStruct_V2 z; z.x = 0.5f; z.y = 0.0f;
            if (!(pos.x <= 0.0f)) {
                pos.x = pos.x - 120.0f / (0.8f / dt);
                SetPos__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(self->field_1C, &pos, &z);
                return;
            }
            pos.x = 0.0f;   // fix3 [C] retail 0x457914 swc1 f4(0), 0x190(sp)
            SetPos__11CGt2dObjectFRCQ29GtMathPs26CGtV2dRCQ29GtMathPs26CGtV2d(self->field_1C, &pos, &z);
            self->field_57 = 0;
            if (self->field_18 != 0) {
                DestructObject__10CGt2dSceneFiP11CGt2dObject(self->field_0, self->field_8, self->field_18);
                self->field_18 = 0;
            }
        }
    }
}
