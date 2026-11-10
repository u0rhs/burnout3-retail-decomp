// CB3AILane::UpdateDrivableSegmentIndex(unsigned short*,signed char) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3AILane.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-finished from the lifted source (dperm (decomp-permuter, background run): unsigned short new_var;; CB3AILane *lane = func_00146F20_inl1(this, s, (EAISegmentLinkType) 0);; new_var = s;; CB3AILane *lane = func_00146F20_inl1(this, new_var, (EAISegmentLinkType) 0);; lane = func_00146F20_inl1(this, s, (EAISegmentLinkType) 1);; lane = func_00146F20_inl1(this, new_var, (EAISegme).

enum EAISegmentLinkType {};
struct UnkStruct_00146DB0_e {
    unsigned char pad_0[3];
    unsigned char field_3;
    unsigned char field_4[2];
    unsigned short field_6[2];
};
struct CB3AILaneStruct {
    unsigned char pad_0[8];
    UnkStruct_00146DB0_e *field_8;
    unsigned short field_C;
    unsigned char field_E;
};
class CB3AILane {
public:
    CB3AILane *FindConnectedDrivableLane(unsigned short *, EAISegmentLinkType);
    CB3AILane *UpdateDrivableSegmentIndex(unsigned short *, signed char);
    bool LaneIsDriveable(unsigned short seg, unsigned short n);
    unsigned char pad_0[4];
    CB3AILaneStruct *field_4;
};
struct UnkStruct_D_00522660 {
    unsigned char pad_0[0x2C];
    CB3AILane field_2C[1];
};
extern UnkStruct_D_00522660 D_00522660;




static inline bool func_00148D60_inl1(const CB3AILane *l, unsigned short seg, unsigned short n)
{
    const CB3AILaneStruct *r = l->field_4;
    while (n--) {
        if ((r->field_8[seg].field_3 & 7) == 5) {
            return false;
        }
        seg++;
        if (seg >= r->field_C) {
            if (r->field_E == 0) {
                break;
            }
            seg = 0;
        }
    }
    return true;
}

inline bool CB3AILane::LaneIsDriveable(unsigned short seg, unsigned short n)
{
    return func_00148D60_inl1(this, seg, n);
}
static inline CB3AILane *func_00146DB0_inl1(CB3AILane *l, unsigned short &s, EAISegmentLinkType type)
{
    unsigned char link = l->field_4->field_8[s].field_4[type];
    if (link == 255) {
        return 0;
    }
    s = l->field_4->field_8[s].field_6[type];
    return &D_00522660.field_2C[link];
}
static inline CB3AILane *func_00146F20_inl1(CB3AILane *l, unsigned short &s, EAISegmentLinkType type)
{
    unsigned short cur = s;
    CB3AILane *lane = func_00146DB0_inl1(l, cur, type);
    if (lane != 0) {
        if (lane->LaneIsDriveable(cur, 1)) {
            s = cur;
            return lane;
        }
    }
    return 0;
}





// 0x00146F20
CB3AILane *CB3AILane::UpdateDrivableSegmentIndex(unsigned short *seg, signed char d)
{
  unsigned short s = *seg;
  unsigned short v0;
  int n = s + d;
  if ((n >= 0) && (n < field_4->field_C))
  {
    *seg = n;
    return this;
  }
  if (field_4->field_E != 0)
  {
    *seg = (n + field_4->field_C) % field_4->field_C;
    return this;
  }
  v0 = s;
  CB3AILane *lane = func_00146F20_inl1(this, v0, (EAISegmentLinkType) 0);
  if (lane == 0)
  {
    lane = func_00146F20_inl1(this, v0, (EAISegmentLinkType) 1);
    if (lane == 0)
    {
      return 0;
    }
  }
  return lane;
}
