// CB3StaticTrack::RenderAllBackdrops(EBackdropRenderRange,bool,bool) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3StaticTrackPS2.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (a183: s1 loop as inline test + body-after goto form (continue to s2++), plain source).

struct UnkStruct_D_01E32AA9 {
    signed char field_0;
    unsigned char pad_1[0xF];
};
struct UnkStruct_D_01E32AB0 {
    unsigned long field_0;
    unsigned char pad_8[0x8];
};
struct UnkStruct_D_01E32AB8 {
    unsigned long field_0;
    unsigned char pad_8[0x8];
};
struct UnkStruct_D_01E32AC0 {
    unsigned long field_0;
    unsigned char pad_8[0x8];
};
struct UnkStruct_D_01E32AC8 {
    unsigned long field_0;
    unsigned char pad_8[0x8];
};
struct UnkStruct_D_01E32A10 {
    unsigned char pad_0[0x10];
};
extern UnkStruct_D_01E32AA9 D_01E32AA9;
extern UnkStruct_D_01E32AB0 D_01E32AB0;
extern UnkStruct_D_01E32AB8 D_01E32AB8;
extern UnkStruct_D_01E32AC0 D_01E32AC0;
extern UnkStruct_D_01E32AC8 D_01E32AC8;
extern UnkStruct_D_01E32A10 D_01E32A10;
extern "C" void ReallySetupCameraData__16CB3TrackRendererFv(void *);  // CB3TrackRenderer::ReallySetupCameraData()
extern "C" void EndMaterial__16CB3TrackRendererFv(void *);  // CB3TrackRenderer::EndMaterial()
extern "C" void PrepareRenderStatesForRenderingTrack__16CB3TrackRendererFv(void *);
extern "C" void RestoreRenderStatesAfterRenderingTrack__16CB3TrackRendererFv(void *);
extern "C" int func_0026AF50(void *, void *, int, int);


struct UnkStruct_0021D2E0_q {
    unsigned char pad_0[0x40];
    short field_40;
    unsigned char pad_42[2];
    unsigned char *field_44;
    short *field_48;
    unsigned char pad_4C[4];
};
struct UnkStruct_0021D2E0_row {
    short field_0;
    unsigned char pad_2[2];
    UnkStruct_0021D2E0_q *field_4;
};
struct UnkStruct_0021D2E0_unit {
    unsigned char pad_0[0x28];
};
struct UnkStruct_0021D2E0_t {
    unsigned char pad_0[8];
    UnkStruct_0021D2E0_unit *field_8;
    unsigned char pad_C[8];
    signed char field_14;
    signed char field_15;
    unsigned char pad_16[6];
    short field_1C;
    unsigned char pad_1E[6];
    UnkStruct_0021D2E0_row *field_24;
};
struct UnkStruct_D_00667054 {
    int field_0;
    unsigned char pad_4[0xC];
};
extern UnkStruct_D_00667054 D_00667054;
enum EBackdropRenderRange {};
extern "C" void func_0026AE30(void *, void *);

// [G] inlined camera-data refresh keyed by an index (cf. func_0021D550_inl1): cache check then ReallySetupCameraData
static inline void func_0021D2E0_inl1(int x)
{
    if (x == D_01E32AA9.field_0 && D_01E32AB0.field_0 == D_01E32AB8.field_0 && D_01E32AC0.field_0 == D_01E32AC8.field_0) return;
    D_01E32AA9.field_0 = x;
    D_01E32AB8.field_0 = D_01E32AB0.field_0;
    D_01E32AC8.field_0 = D_01E32AC0.field_0;
    if (D_01E32AA9.field_0 > -1) {
        ReallySetupCameraData__16CB3TrackRendererFv(&D_01E32A10);
    }
}

class CB3StaticTrack {
public:
    void RenderAllBackdrops(EBackdropRenderRange p0, bool p1, bool p2);

    unsigned char pad_0[4];
    UnkStruct_0021D2E0_t *field_4;
};

// 0x0021D2E0
void CB3StaticTrack::RenderAllBackdrops(EBackdropRenderRange p0, bool p1, bool p2)
{
    int s7 = 0;
    int fp = D_00667054.field_0;
    if (!p1) {
        s7 = 1;
    }
    if (!p2) {
        fp = 1;
    }
    int s4;
    int s3;
    switch ((int)p0) {
    case 0:
        s3 = field_4->field_14;
        s4 = 0;
        break;
    case 1:
        s4 = field_4->field_14;
        s3 = field_4->field_15;
        break;
    default:
    case 2:
        s4 = field_4->field_15;
        s3 = field_4->field_1C;
        break;
    }
    PrepareRenderStatesForRenderingTrack__16CB3TrackRendererFv(&D_01E32A10);
    for (;;) {
        if (!(s3 > s4)) {
            break;
        }
        UnkStruct_0021D2E0_row *row = &field_4->field_24[s4];
        int s2 = 0;
        for (;;) {
            if (!(row->field_0 > s2)) {
                break;
            }
            UnkStruct_0021D2E0_q *q = &row->field_4[s2];
            int s1 = 0;
        t1:
            if (s1 < q->field_40) goto body1;
            s2++;
            continue;
        body1:
            func_0026AE30(&D_01E32A10, &field_4->field_8[q->field_48[s1]]);
            {
                int s0 = s7;
                for (;;) {
                    if (!(fp > s0)) {
                        break;
                    }
                    func_0021D2E0_inl1(s0);
                    func_0026AF50(&D_01E32A10, q->field_44 + (s1 << 6), 3, s0 != 0);
                    s0++;
                }
            }
            EndMaterial__16CB3TrackRendererFv(&D_01E32A10);
            s1++;
            goto t1;
        }
        s4++;
    }
    RestoreRenderStatesAfterRenderingTrack__16CB3TrackRendererFv(&D_01E32A10);
}
