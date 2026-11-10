// Hand-written; the lifter refused it (a163 tiny).

struct UnkStruct_a163_q { int field_0; int field_4; unsigned char field_8; };
class CB3AIDriver { public: static int _CalcDifficultyIndexQSortCallback(const void *, const void *); };
// 0x00144E20
int CB3AIDriver::_CalcDifficultyIndexQSortCallback(const void *a, const void *b) {
 const UnkStruct_a163_q *p = (const UnkStruct_a163_q *)a; const UnkStruct_a163_q *q = (const UnkStruct_a163_q *)b;
 if (p->field_8 == q->field_8) { if (p->field_4 == q->field_4) return p->field_0 - q->field_0; return p->field_4 - q->field_4; }
 return p->field_8 != 0 ? -1 : 1; }
