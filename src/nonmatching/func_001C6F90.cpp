// NONMATCHING: func_001C6F90 -- retail 572 / ours 566 instructions, 246 in changed runs
// gaps1c: hand-drafted from the asm (transmission update)
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.

// gaps1c (2026-11-02): hand-drafted from the retail asm (0x1C6F90..0x1C787C) with the Ghidra aid; every branch, store and
// float operation in retail's order (products associated as retail multiplies them; `a + b * c` where retail uses
// adda.s/madd.s). The vehicle transmission's per-tick update ([L] by role: gear in +0x80, ratios at +0x4[gear], rpm at
// +0x54, shift timers +0x58/+0x88/+0x8C; retail_names.csv has no row): returns the drive torque factor. Called with
// a0 = car + 0x1448, a1/a2 flags, f12 = throttle [G], f13 = wheel speed [G] (Update__17CB3RaceCarPhysicsFf's archive,
// retail 0x1C4D94). +0x68/+0x6C is the same two-word random stir CB3Game uses at +0x2A640.
// TRACK: clean
// EQUIV: [L] written from the asm: the three shift paths (up, down, kick-down to neutral), the two rpm models (+0x54 below
// / above the limiter), the five random draws in retail's order, the unsigned-to-float conversions

struct UnkStruct_001C6F90_rc {
    unsigned char pad_0[0x10CC];
    float field_10CC;
    unsigned char pad_10D0[0x11B0 - 0x10D0];
    float field_11B0;
    unsigned char pad_11B4[0x11E1 - 0x11B4];
    unsigned char field_11E1;
};
struct UnkStruct_001C6F90_car {
    unsigned char pad_0[0xBC];
    float field_BC;                   // [C] the w lane of the quad at +0xB0 (lq + lwc1 0xC of the copy)
    unsigned char pad_C0[0x13D4 - 0xC0];
    float field_13D4;
    unsigned char pad_13D8[0x13F4 - 0x13D8];
    UnkStruct_001C6F90_rc * field_13F4;
};
struct UnkStruct_001C6F90 {
    unsigned char pad_0[0x4];
    float field_4[7];                 // [C] lwc1 0x4(gear * 4): the gear ratios, gear -1..
    float field_20;
    float field_24;
    float field_28;
    float field_2C;
    unsigned char pad_30[0x8];
    float field_38;
    float field_3C;
    float field_40;
    float field_44;
    float field_48;
    float field_4C;
    float field_50;
    float field_54;                   // [G] engine rpm
    float field_58;
    int field_5C;
    int field_60;
    unsigned char pad_64[0x4];
    int field_68;                     // [C] random stir state (sll/sra/addu)
    int field_6C;
    int field_70;
    unsigned char pad_74[0xC];
    int field_80;                     // [G] the gear (-1 reverse, 0 neutral)
    int field_84;                     // [C] upper bound of field_80 for an upshift
    float field_88;
    float field_8C;
    UnkStruct_001C6F90_car * field_90; // [C] func_001C7880 stores its a1 (the car) here
};

extern float D_0052267C;              // [C] the world timer's dt (D_00522660 + 0x1C)
extern float D_004E0978;              // [C] gp-relative constants (lwc1 %gp_rel)
extern float D_004E07A8;
extern float D_004E0A40;
extern float D_004E0B74;
extern float D_004E0BB8;
extern float D_004E0C18;
extern float D_004E0CE8;
extern float D_004E0CF0;
extern float D_004E0D6C;
extern float D_004E0D80;
extern float D_004E0D84;
extern float D_004E0D88;
extern float D_004E0D8C;
extern float D_004E0D90;
extern float D_004E16DC;
extern float D_004E16E0;

// the +0x68/+0x6C stir, then its first word as an unsigned in [0, 1) (2^-32 = 0x2F800000)
static inline float func_001C6F90_inl1(UnkStruct_001C6F90 * t)
{
    t->field_68 = (t->field_68 << 16) + (t->field_68 >> 16);
    t->field_68 = t->field_68 + t->field_6C;
    t->field_6C = t->field_6C + t->field_68;
    return 2.3283064e-10f * (float)(unsigned int)t->field_68;
}

// 0x001C6F90
extern "C" float func_001C6F90(UnkStruct_001C6F90 * t, int p0, int p1, float p, float q)
{
    if (p0 != 0 && p < D_004E0B74) {
        p = D_004E0B74;
    }
    int gear = t->field_80;
    if (gear == 1 && q < 0.0f) {
        q = q * 100.0f;
    }
    float r = t->field_20 * (q * t->field_4[gear]);
    float lo = D_004E0D80 * t->field_24;
    float hi = D_004E0D80 * t->field_2C;
    float up = D_004E0D80 * t->field_28;
    if (gear == 0) {
        r = p * (D_004E0D80 * t->field_40);
    }

    if (t->field_5C != 0) {
        t->field_58 = t->field_58 - D_0052267C;
        if (t->field_58 <= 0.0f) {
            t->field_5C = 0;
        } else {
            p = p * D_004E0C18;
        }
    } else if (t->field_70 == 0) {
        t->field_8C = t->field_8C - D_0052267C;
        t->field_88 = t->field_88 - D_0052267C;
        bool down = false;
        if (r < hi && t->field_80 >= 2 && p < 0.5f) {
            down = true;
        } else if (r < 0.75f * hi && t->field_80 >= 2) {
            down = true;
        }
        if (down) {
            if (t->field_8C <= 0.0f) {
                t->field_80 = t->field_80 - 1;
                t->field_5C = 1;
                t->field_58 = D_004E07A8;
                t->field_88 = 1.0f;
            }
        } else if (!(r <= up)) {
            int g = t->field_80;
            if (g > 0 && g < t->field_84 && t->field_60 == 0 && t->field_88 <= 0.0f) {
                float ratio = t->field_4[g];
                t->field_80 = g + 1;
                t->field_5C = 1;
                r = t->field_20 * (q * ratio);
                if (p0 != 0) {
                    t->field_58 = D_004E0C18;
                    t->field_8C = D_004E0C18;
                } else {
                    t->field_58 = D_004E07A8;
                    t->field_8C = 1.0f;
                }
            }
        }
    }

    float f40 = t->field_40;
    gear = t->field_80;
    float m = D_004E0D80 * f40;        // [G] the rev limit
    if (gear == -1) {
        m = m * D_004E0A40;
    } else if (gear != 0) {
        if (p0 != 0) {
            m = m * D_004E0D84;
        } else if (t->field_70 != 0) {
            m = m * D_004E0D88;
        }
    }

    if (!(t->field_54 < m - D_004E0CF0)) {
        // at the limiter: re-draw the limit around +0x38, rpm falls 20, throttle becomes engine braking
        if (f40 == t->field_38 && p0 == 0) {
            if (gear == 0) {
                float u = func_001C6F90_inl1(t);
                t->field_40 = t->field_38 - D_004E0C18 * (t->field_38 * u);
            } else {
                float u = func_001C6F90_inl1(t);
                t->field_40 = (t->field_38 - 50.0f * u) - 70.0f;
            }
        }
        p = (-1.0f * r) / m;
        t->field_54 = t->field_54 - 20.0f;
        if (!(p <= 0.0f)) {
            p = 0.0f;
        }
    } else {
        t->field_40 = t->field_38;
        float rise, fall;
        if (t->field_80 == 0) {
            if (t->field_38 < (float)6000) {
                rise = 22.5f;
                fall = D_004E0D8C;
            } else {
                rise = 45.0f;
                fall = 16.0f;
            }
            float u = func_001C6F90_inl1(t);
            r = r * (D_004E0CE8 + D_004E0BB8 * u);
        } else if (p0 != 0) {
            rise = 45.0f;
            fall = 8.0f;
        } else {
            rise = 15.0f;
            fall = 8.0f;
        }
        float x = t->field_54;
        if (!(r <= x + rise)) {
            t->field_54 = x + rise;
        } else if (r < x - fall) {
            t->field_54 = t->field_54 - fall;
        } else {
            t->field_54 = r;
        }
        if (t->field_54 < lo || D_004E0D6C * t->field_90->field_BC < 1.0f) {
            if (t->field_54 <= lo + D_004E16DC) {
                float u = func_001C6F90_inl1(t);
                t->field_54 = lo + D_004E16E0 * u;
            }
            if (p <= 0.0f && (t->field_80 == 1 || t->field_80 == -1 || t->field_70 != 0)) {
                t->field_80 = 0;
                t->field_5C = 1;
                t->field_58 = D_004E0D90;
            }
        }
    }

    float y = t->field_54;
    float g;
    if (y < t->field_44) {
        g = 0.5f + 0.5f * (y / t->field_44);
    } else if (!(y <= t->field_48)) {
        g = 0.75f + 0.25f * ((m - y) / (m - t->field_48));
    } else {
        g = 1.0f;
    }
    if (p1 != 0) {
        g = 2.0f;
    }
    if (t->field_80 == -1) {
        g = (m - y) / m;
    }
    if (p0 != 0) {
        UnkStruct_001C6F90_car * car = t->field_90;
        if (D_004E0D6C * car->field_BC < car->field_13D4) {
            UnkStruct_001C6F90_rc * rc = car->field_13F4;
            float d = rc->field_10CC - rc->field_11B0;
            if (rc->field_11E1 != 0) {
                g = 1.0f + t->field_4C;
            } else if (d < t->field_50) {
                g = 1.0f + t->field_4C * (1.0f - d / t->field_50);
            }
        }
    }
    float u = func_001C6F90_inl1(t);
    float k = t->field_20 * (t->field_4[t->field_80] * (g * (p * t->field_3C)));
    return k * (D_004E0978 + D_004E0C18 * u);
}
