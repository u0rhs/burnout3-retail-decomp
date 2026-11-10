// CB3OnlineLobbyState::HandleSelectCarEvents(EB3MenuFlowFSMEvents) -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> B3OnlineLobbyState.cpp.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (dperm (decomp-permuter, background run): D_01E997C0.field_0 = ((D_01E997C0.field_0 & 0xFFFFFF) | 1) | (D_01E90170.field_0 << 24);; D_01E997C0.field_0 = ((D_01E997C0.field_0 & 0xFFFFFF) | 1) | (D_01E90170.field_0 << 24);).

enum EB3MenuFlowFSMEvents {};
struct UnkStruct_D_01E3CD44 {
    virtual void vfunc_8();
    virtual void vfunc_C();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1C();
    virtual void vfunc_20();
    virtual void vfunc_24();
    virtual void vfunc_28();
    virtual void vfunc_2C();
    virtual void vfunc_30();
    virtual void vfunc_34();
    virtual void vfunc_38();
    virtual void vfunc_3C();
    virtual void vfunc_40();
    virtual void vfunc_44();
    virtual void vfunc_48();
    virtual void vfunc_4C();
    virtual void vfunc_50();
    virtual void vfunc_54();
    virtual void vfunc_58();
    virtual void vfunc_5C();
    virtual void vfunc_60();
    virtual void vfunc_64();
    virtual void vfunc_68();
    virtual void vfunc_6C();
    virtual void vfunc_70();
    virtual void vfunc_74();
    virtual void vfunc_78();
    virtual void vfunc_7C();
    virtual void vfunc_80();
    virtual void vfunc_84();
    virtual void vfunc_88();
    virtual void vfunc_8C();
    virtual void vfunc_90();
    virtual void vfunc_94();
    virtual void vfunc_98();
    virtual void vfunc_9C();
    virtual void vfunc_A0();
    virtual void vfunc_A4();
    virtual void vfunc_A8();
    virtual void vfunc_AC();
    virtual void vfunc_B0();
    virtual void vfunc_B4();
    virtual void vfunc_B8(void *);
    virtual void vfunc_BC(void *);
    unsigned char pad_4[0xC];
};
struct UnkStruct_D_01E90130 { int field_0; int field_4; unsigned char pad_8[0x8]; };
struct UnkStruct_D_01E94EF8 { unsigned long field_0; unsigned char pad_8[0x8]; };
struct UnkStruct_D_01E94F18 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E90170 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E997AC { unsigned char pad_0[0x10]; };
struct UnkStruct_D_01E997B8 { int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E997C0 { unsigned int field_0; unsigned char pad_4[0xC]; };
struct UnkStruct_D_01E99838 { unsigned char field_0; unsigned char pad_1[0xF]; };
struct UnkStruct_x { char *field_0; unsigned char pad_4[0x3C]; };
class CB3OnlineLobbyPage { public: void Prepare(char *); unsigned char pad_0[0x10]; };
class CB3OnlineLobbyState {
public:
    void HandleSelectCarEvents(EB3MenuFlowFSMEvents p0);
    unsigned char pad_0[0x10];
    unsigned char field_10;
};
extern UnkStruct_D_01E3CD44 D_01E3CD44;
extern UnkStruct_D_01E90130 D_01E90130;
extern UnkStruct_D_01E94EF8 D_01E94EF8;
extern UnkStruct_D_01E94F18 D_01E94F18;
extern UnkStruct_D_01E90170 D_01E90170;
extern UnkStruct_D_01E997AC D_01E997AC;
extern UnkStruct_D_01E997B8 D_01E997B8;
extern UnkStruct_D_01E997B8 D_01E997BC;
extern UnkStruct_D_01E997C0 D_01E997C0;
extern UnkStruct_D_01E99838 D_01E99838;
extern CB3OnlineLobbyPage D_01E98490;






// 0x0030F490
void CB3OnlineLobbyState::HandleSelectCarEvents(EB3MenuFlowFSMEvents p0)
{
  UnkStruct_x local;
  switch (p0)
  {
    case 1:

    case 2:

    case 0:
      field_10 = 1;
      *((unsigned long *) (&D_01E90130)) = D_01E94EF8.field_0;
      D_01E90170.field_0 = D_01E94F18.field_0;
      ((UnkStruct_D_01E3CD44 *) (&D_01E3CD44))->vfunc_B8(&D_01E997AC);
      D_01E997B8.field_0 = D_01E90130.field_0;
      D_01E997BC.field_0 = D_01E90130.field_4;
      D_01E997C0.field_0 = ((D_01E997C0.field_0 & 0xFFFFFF) | 1) | (D_01E90170.field_0 << 24);
      D_01E99838.field_0 = 1;
      ((UnkStruct_D_01E3CD44 *) (&D_01E3CD44))->vfunc_BC(&local);
      D_01E98490.Prepare(local.field_0);
      break;

    case 3:
      ((UnkStruct_D_01E3CD44 *) (&D_01E3CD44))->vfunc_B8(&D_01E997AC);
      D_01E997C0.field_0 |= 1;
      D_01E99838.field_0 = 1;
      ((UnkStruct_D_01E3CD44 *) (&D_01E3CD44))->vfunc_BC(&local);
      D_01E98490.Prepare(local.field_0);
      field_10 = 1;
      break;

    default:
      break;

  }

}
