// NONMATCHING: func_001CEE10 -- retail 294 / ours 294 instructions, 90 in changed runs
// a230: 'saved = BUF' declared after the self+0x210 test gives retail's 294 length; remaining diff is the s0/s1 swap (self vs saved) and t1/t2 swap; tried self copy, bb init, early BUF copy
// Archived near-miss (not built, not counted): the logic is believed right, codegen still differs.
// TRACK: near
// EQUIV: unreviewed (tagged mechanically 2026-10-30, tools/tag_nonmatching_track.py)


typedef unsigned int u_long128 __attribute__((mode(TI)));
struct UnkV { u_long128 mData; UnkV() {} UnkV(const UnkV& o) : mData(o.mData) {} UnkV& operator=(const UnkV& o) { mData = o.mData; return *this; } };
struct UnkStruct_001CEE10_el { u_long128 a[3]; UnkV v; };
struct UnkStruct_001CEE10_fl { unsigned short w; };
struct UnkStruct_001CEE10_buf { int field_0; UnkStruct_001CEE10_el *field_4; UnkStruct_001CEE10_fl *field_8; };
struct UnkStruct_001CEE10_blk { unsigned char pad_0[0xC]; signed char field_C; };
struct UnkStruct_001CEE10_ptr { unsigned char pad_0[0x40]; UnkStruct_001CEE10_blk *field_40; };
extern "C" void CacheWorldTriangles__16CB3CollidingBodyFv(void *);
extern "C" void CollideWithWorld__16CB3CollidingBodyFv(void *);
extern "C" void CollideWheels__17CB3VehiclePhysicsFv(void *);
extern "C" void func_001C8290(void *, int);
struct UnkStruct_0055E948 { int pad; };
extern UnkStruct_0055E948 D_0055E948;
extern "C" void HandleCrashingVehicleWorldCollision__22CB3CrashActionDirectorFP17CB3VehiclePhysics(void *, void *);
 struct UnkStruct_001CEE10_r1 { unsigned char pad_0[0x11D0]; UnkStruct_001CEE10_el el; };
struct UnkStruct_001CEE10_r2 { unsigned char pad_0[0x1590]; UnkStruct_001CEE10_el el; };
struct UnkStruct_001CEE10_r3 { unsigned char pad_0[0x2010]; UnkStruct_001CEE10_el el; };
#define BUF (*(UnkStruct_001CEE10_buf **)(self + 0x200))

// 0x001CEE10
extern "C" void func_001CEE10(char *self)
{
    UnkStruct_001CEE10_buf *bb;
    if (*(unsigned char *)(self + 0x210) == 0) return;
    UnkStruct_001CEE10_buf *saved = BUF;
    unsigned char fl = *(unsigned char *)(self + 0x1353);
    if ((fl & 1) == 1 || (fl & 4) == 4) return;
    *(int *)(self + 0x200) = 0x70002000;
    bb = BUF;
    bb->field_0 = 0;
    bb->field_4 = (UnkStruct_001CEE10_el *)((char *)bb + 0x10);
    bb->field_8 = (UnkStruct_001CEE10_fl *)((char *)bb + 0x1810);
    CacheWorldTriangles__16CB3CollidingBodyFv(self);
    int n = BUF->field_0;
    if (*(unsigned char *)(self + 0x1350)) {
        if (n < 0x5C) {
            for (int i = 0; i < 4; i++) {
                bb = BUF;
                bb->field_4[bb->field_0] = ((UnkStruct_001CEE10_r1 *)(self + i * 0x40))->el;
                bb = BUF; bb->field_8[bb->field_0].w = 0;
                bb = BUF; UnkStruct_001CEE10_fl *f = &bb->field_8[bb->field_0]; f->w &= 0xFF00; f->w |= 0x26;
                bb = BUF;
                bb->field_0++;
            }
        } else *(unsigned char *)(self + 0x1350) = 0;
    }
    if (*(unsigned char *)(self + 0x1351)) {
        if (n < 0x5A) {
            int i = 0;
            goto loop0_t;
        loop0:
            bb = BUF;
            bb->field_4[bb->field_0] = ((UnkStruct_001CEE10_r1 *)(self + i * 0x40))->el;
            bb = BUF; bb->field_8[bb->field_0].w = 0;
            bb = BUF; UnkStruct_001CEE10_fl *f = &bb->field_8[bb->field_0]; f->w &= 0xFF00; f->w |= 0x26;
            bb = BUF;
            bb->field_0++;
            i++;
        loop0_t:
            if (i < 6) goto loop0;
        } else *(unsigned char *)(self + 0x1350) = 0;
    }
    if (*(signed char *)(self + 0x215) == 1) {
        int i;
        if (*(int *)(self + 0x3510) > 0) {
            i = 0;
            goto test3;
        body3:

            bb = BUF;
            if (bb->field_0 >= 0x60) goto done3;
            bb = BUF;
            bb->field_4[bb->field_0] = ((UnkStruct_001CEE10_r2 *)(self + i * 0x40))->el;
            bb = BUF; bb->field_8[bb->field_0].w = 0;
            bb = BUF; UnkStruct_001CEE10_fl *f = &bb->field_8[bb->field_0]; f->w &= 0xFF00; f->w |= 0x21;
            bb = BUF;
            bb->field_0++;
            i++;
        test3:
            if (i < *(int *)(self + 0x3510)) goto body3;
        }
    done3:;
        if (*(int *)(self + 0x3518) > 0) {
            i = 0;
            goto test4;
        body4:

            bb = BUF;
            if (bb->field_0 >= 0x60) goto done4;
            bb = BUF;
            bb->field_4[bb->field_0] = ((UnkStruct_001CEE10_r3 *)(self + i * 0x40))->el;
            bb = BUF; bb->field_8[bb->field_0].w = 0;
            bb = BUF; UnkStruct_001CEE10_fl *f = &bb->field_8[bb->field_0]; f->w &= 0xFF00; f->w |= 0x21;
            bb = BUF;
            bb->field_0++;
            i++;
        test4:
            if (i < *(int *)(self + 0x3518)) goto body4;
        }
    done4:;
    }
    CollideWithWorld__16CB3CollidingBodyFv(self);
    for (int i = 0; i < (*(UnkStruct_001CEE10_ptr **)(self + 0xCC0))->field_40->field_C; i++) {
        if ((*(signed char **)(self + 0xCC4))[i + 0x4B2] == 2) func_001C8290(self, i);
    }
    if (*(signed char *)(self + 0x1169)) CollideWheels__17CB3VehiclePhysicsFv(self);
    BUF = saved;
    if (*(unsigned char *)(self + 0x212))
    HandleCrashingVehicleWorldCollision__22CB3CrashActionDirectorFP17CB3VehiclePhysics(&D_0055E948, self);
}
