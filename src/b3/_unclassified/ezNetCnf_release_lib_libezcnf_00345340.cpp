// ezNetCnfGetCombinationList -- tiny-function batch (tools/tiny_batch.py, lifted).
// [C] name: the mangled symbol in retail's tables (high); file: research/retail_names.csv -> ezNetCnf_release.lib libezcnf.o.
// Area not evidenced, so _unclassified/ (docs/conventions.md). Classes and structs are declared here with only
// what this function touches; field names are placeholders and every type is [G] (instruction widths).
// Hand-written; the lifter refused it (dperm (decomp-permuter, background run): int new_var;; new_var = (int) c_;; InvalidDCache(c, v + 0x7FF);; InvalidDCache(new_var, v + 0x7FF);).

extern "C" {
extern char D_004C6B58[];
extern char D_004C6BD0[];
extern char D_004C6BF0[];
extern char D_004C6BA0[];
extern char D_004C6BC0[];
extern int D_004E2DE8;
struct UnkStruct_01EA39C0 { int field_0; char pad_4[0xC]; };
extern UnkStruct_01EA39C0 D_01EA39C0;
struct UnkStruct_01EA3A00 { int field_0; char *field_4; char pad_8[8]; char field_10[0x100]; };
extern UnkStruct_01EA3A00 D_01EA3A00;
int scePrintf(char *, ...);
void InvalidDCache(int, int);
char *strncpy(char *, const char *, unsigned);
int sceSifCallRpc(void *, int, int, void *, int, void *, int, void *, void *);

#pragma push
#pragma opt_propagation off





// 0x00345340
int ezNetCnfGetCombinationList(char *a, int b_, void *c_)
{
  char *b = (char *) b_;
  int c = (int) c_;
  int v0;
  UnkStruct_01EA3A00 *p = &D_01EA3A00;
  if (D_004E2DE8 == 0)
  {
    scePrintf(D_004C6B58, D_004C6BD0);
    scePrintf(D_004C6BA0);
    return -1;
  }
  v0 = (int) c_;
  int v = c;
  if (v & 0x3F)
  {
    scePrintf(D_004C6B58, D_004C6BD0);
    scePrintf(D_004C6BF0, v, 0x40);
    return -22;
  }
  InvalidDCache(v0, v + 0x7FF);
  p->field_0 = v;
  p->field_4 = b;
  strncpy(p->field_10, a, 0xFF);
  sceSifCallRpc(&D_01EA39C0, 1, 0, p, 0x180, p, 4, 0, 0);
  scePrintf(D_004C6B58, D_004C6BD0);
  scePrintf(D_004C6BC0, p->field_0);
  return p->field_0;
}


#pragma pop
}
