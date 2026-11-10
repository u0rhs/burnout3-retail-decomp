// NONMATCHING: func_004D6190 -- retail 613 / ours 1070 instructions, 1391 in changed runs
// gaps1 (2026-11-02): generated from the retail asm by build/vt/gaps1/gen_sinit.py (symbolic execution of this branch-free
// static initialiser: every global load, store and call in retail's order; the stack staging of 16-byte constants folded).
// A C++ __sinit (.init section, 0x4D3E00-0x4DD81C): the constructor code of one translation unit's globals, kept as its
// asm label (retail's own symbol is a local __sinit_<file>). Declarations are byte arrays; types [G] from store widths.
// TRACK: clean
// EQUIV: [L] generated: every instruction modelled or the generator refuses; behaviour_audit quiet

struct UnkStruct_004D6190_q { unsigned int w[4]; };   // a 16-byte lq/sq copy
extern unsigned char D_004C3760[];
extern unsigned char D_004C3770[];
extern unsigned char D_004C3780[];
extern unsigned char D_004C3790[];
extern unsigned char D_004C37A0[];
extern unsigned char D_004C37B0[];
extern unsigned char D_004C37C0[];
extern unsigned char D_004C37D0[];
extern unsigned char D_004C37E0[];
extern unsigned char D_004C37F0[];
extern unsigned char D_004C3800[];
extern unsigned char D_004C39A0[];
extern unsigned char D_004C39B0[];
extern unsigned char D_004C39E0[];
extern unsigned char D_004C3B90[];
extern unsigned char D_004C3BA0[];
extern unsigned char D_004C3BB0[];

// 0x004D6190
extern "C" void func_004D6190()
{
    UnkStruct_004D6190_q t1;   // lanes 3: never written, copied as retail does
    *(float *)&t1.w[0] = 0.0f;
    *(float *)&t1.w[1] = 0.0f;
    *(float *)&t1.w[2] = -1.0f;
    UnkStruct_004D6190_q t2;   // lanes 3: never written, copied as retail does
    *(float *)&t2.w[0] = -2.0f;
    *(float *)&t2.w[1] = 1.0f;
    *(float *)&t2.w[2] = 3.0f;
    UnkStruct_004D6190_q t3;   // lanes 3: never written, copied as retail does
    *(float *)&t3.w[0] = 2.0f;
    *(float *)&t3.w[1] = 1.0f;
    *(float *)&t3.w[2] = 2.0f;
    UnkStruct_004D6190_q t4;   // lanes 3: never written, copied as retail does
    *(float *)&t4.w[0] = -2.0f;
    *(float *)&t4.w[1] = 2.0f;
    *(float *)&t4.w[2] = 2.0f;
    UnkStruct_004D6190_q t5;   // lanes 3: never written, copied as retail does
    *(float *)&t5.w[0] = -2.0f;
    *(float *)&t5.w[1] = 1.0f;
    *(float *)&t5.w[2] = 4.0f;
    UnkStruct_004D6190_q t6;   // lanes 3: never written, copied as retail does
    *(float *)&t6.w[0] = 2.0f;
    *(float *)&t6.w[1] = 1.0f;
    *(float *)&t6.w[2] = 3.0f;
    *(UnkStruct_004D6190_q *)D_004C3770 = t2;
    *(UnkStruct_004D6190_q *)D_004C3780 = t3;
    *(UnkStruct_004D6190_q *)D_004C3790 = t4;
    *(UnkStruct_004D6190_q *)D_004C37B0 = t6;
    UnkStruct_004D6190_q t7;   // lanes 3: never written, copied as retail does
    *(float *)&t7.w[0] = -2.0f;
    *(float *)&t7.w[1] = 2.0f;
    *(float *)&t7.w[2] = 3.0f;
    UnkStruct_004D6190_q t8;   // lanes 3: never written, copied as retail does
    *(float *)&t8.w[0] = 2.0f;
    *(float *)&t8.w[1] = 1.0f;
    *(float *)&t8.w[2] = 4.0f;
    UnkStruct_004D6190_q t9;   // lanes 3: never written, copied as retail does
    *(float *)&t9.w[0] = -2.0f;
    *(float *)&t9.w[1] = 1.0f;
    *(float *)&t9.w[2] = 3.0f;
    UnkStruct_004D6190_q t10;   // lanes 3: never written, copied as retail does
    *(float *)&t10.w[0] = 2.0f;
    *(float *)&t10.w[1] = 2.0f;
    *(float *)&t10.w[2] = 3.0f;
    *(UnkStruct_004D6190_q *)D_004C37A0 = t5;
    UnkStruct_004D6190_q t11;   // lanes 3: never written, copied as retail does
    *(float *)&t11.w[0] = 1.0f;
    *(float *)&t11.w[1] = 1.0f;
    *(float *)&t11.w[2] = 4.5f;
    UnkStruct_004D6190_q t12;   // lanes 3: never written, copied as retail does
    *(float *)&t12.w[0] = 1.0f;
    *(float *)&t12.w[1] = 1.5f;
    *(float *)&t12.w[2] = 2.0f;
    *(UnkStruct_004D6190_q *)D_004C3800 = t11;
    *(UnkStruct_004D6190_q *)(D_004C3800 + 0x10) = t12;
    UnkStruct_004D6190_q t13;   // lanes 3: never written, copied as retail does
    *(float *)&t13.w[0] = 2.0f;
    *(float *)&t13.w[1] = 2.0f;
    *(float *)&t13.w[2] = -0.5f;
    *(UnkStruct_004D6190_q *)(D_004C3800 + 0x20) = t13;
    UnkStruct_004D6190_q t14;   // lanes 3: never written, copied as retail does
    *(float *)&t14.w[0] = -1.0f;
    *(float *)&t14.w[1] = 1.0f;
    *(float *)&t14.w[2] = 4.5f;
    *(UnkStruct_004D6190_q *)D_004C37C0 = t7;
    UnkStruct_004D6190_q t15;   // lanes 3: never written, copied as retail does
    *(float *)&t15.w[0] = -1.0f;
    *(float *)&t15.w[1] = 1.5f;
    *(float *)&t15.w[2] = 2.0f;
    *(UnkStruct_004D6190_q *)D_004C37D0 = t8;
    *(UnkStruct_004D6190_q *)(D_004C3800 + 0x30) = t14;
    UnkStruct_004D6190_q t16;   // lanes 3: never written, copied as retail does
    *(float *)&t16.w[0] = -2.0f;
    *(float *)&t16.w[1] = 2.0f;
    *(float *)&t16.w[2] = -0.5f;
    *(UnkStruct_004D6190_q *)(D_004C3800 + 0x40) = t15;
    *(UnkStruct_004D6190_q *)(D_004C3800 + 0x50) = t16;
    *(UnkStruct_004D6190_q *)D_004C37E0 = t9;
    UnkStruct_004D6190_q t17;   // lanes 3: never written, copied as retail does
    *(float *)&t17.w[0] = 0.0f;
    *(float *)&t17.w[1] = 0.0f;
    *(float *)&t17.w[2] = 6.0f;
    *(UnkStruct_004D6190_q *)D_004C37F0 = t10;
    *(UnkStruct_004D6190_q *)(D_004C3800 + 0x60) = t17;
    UnkStruct_004D6190_q t18;   // lanes 3: never written, copied as retail does
    *(float *)&t18.w[0] = 0.0f;
    *(float *)&t18.w[1] = 0.0f;
    *(float *)&t18.w[2] = 4.0f;
    UnkStruct_004D6190_q t19;   // lanes 3: never written, copied as retail does
    *(float *)&t19.w[0] = -2.0f;
    *(float *)&t19.w[1] = 2.0f;
    *(float *)&t19.w[2] = 2.0f;
    *(UnkStruct_004D6190_q *)(D_004C3800 + 0x70) = t18;
    UnkStruct_004D6190_q t20;   // lanes 3: never written, copied as retail does
    *(float *)&t20.w[0] = 0.0f;
    *(float *)&t20.w[1] = 0.0f;
    *(float *)&t20.w[2] = 6.0f;
    *(UnkStruct_004D6190_q *)(D_004C3800 + 0x80) = t19;
    UnkStruct_004D6190_q t21;   // lanes 3: never written, copied as retail does
    *(float *)&t21.w[0] = 0.0f;
    *(float *)&t21.w[1] = 0.0f;
    *(float *)&t21.w[2] = 4.0f;
    UnkStruct_004D6190_q t22;   // lanes 3: never written, copied as retail does
    *(float *)&t22.w[0] = 2.0f;
    *(float *)&t22.w[1] = 2.0f;
    *(float *)&t22.w[2] = 2.0f;
    *(UnkStruct_004D6190_q *)(D_004C3800 + 0x90) = t20;
    UnkStruct_004D6190_q t23;   // lanes 3: never written, copied as retail does
    *(float *)&t23.w[0] = 0.0f;
    *(float *)&t23.w[1] = 0.0f;
    *(float *)&t23.w[2] = 4.0f;
    *(UnkStruct_004D6190_q *)(D_004C3800 + 0xA0) = t21;
    UnkStruct_004D6190_q t24;   // lanes 3: never written, copied as retail does
    *(float *)&t24.w[0] = 0.0f;
    *(float *)&t24.w[1] = 1.0f;
    *(float *)&t24.w[2] = 5.0f;
    UnkStruct_004D6190_q t25;   // lanes 3: never written, copied as retail does
    *(float *)&t25.w[0] = -2.0f;
    *(float *)&t25.w[1] = 2.0f;
    *(float *)&t25.w[2] = 1.0f;
    *(UnkStruct_004D6190_q *)(D_004C3800 + 0xB0) = t22;
    UnkStruct_004D6190_q t26;   // lanes 3: never written, copied as retail does
    *(float *)&t26.w[0] = 0.0f;
    *(float *)&t26.w[1] = 0.0f;
    *(float *)&t26.w[2] = 4.0f;
    *(UnkStruct_004D6190_q *)(D_004C3800 + 0xC0) = t23;
    UnkStruct_004D6190_q t27;   // lanes 3: never written, copied as retail does
    *(float *)&t27.w[0] = 0.0f;
    *(float *)&t27.w[1] = 1.0f;
    *(float *)&t27.w[2] = 5.0f;
    UnkStruct_004D6190_q t28;   // lanes 3: never written, copied as retail does
    *(float *)&t28.w[0] = 2.0f;
    *(float *)&t28.w[1] = 2.0f;
    *(float *)&t28.w[2] = 1.0f;
    *(UnkStruct_004D6190_q *)(D_004C3800 + 0xD0) = t24;
    UnkStruct_004D6190_q t29;   // lanes 3: never written, copied as retail does
    *(float *)&t29.w[0] = 3.0f;
    *(float *)&t29.w[1] = 1.0f;
    *(float *)&t29.w[2] = -2.0f;
    *(UnkStruct_004D6190_q *)(D_004C3800 + 0xE0) = t25;
    *(UnkStruct_004D6190_q *)(D_004C3800 + 0xF0) = t26;
    UnkStruct_004D6190_q t30;   // lanes 3: never written, copied as retail does
    *(float *)&t30.w[0] = 0.0f;
    *(float *)&t30.w[1] = 3.0f;
    *(float *)&t30.w[2] = -6.0f;
    UnkStruct_004D6190_q t31;   // lanes 3: never written, copied as retail does
    *(float *)&t31.w[0] = -3.0f;
    *(float *)&t31.w[1] = 1.0f;
    *(float *)&t31.w[2] = -2.0f;
    UnkStruct_004D6190_q t32;   // lanes 3: never written, copied as retail does
    *(float *)&t32.w[0] = -3.0f;
    *(float *)&t32.w[1] = 1.0f;
    *(float *)&t32.w[2] = -2.0f;
    *(UnkStruct_004D6190_q *)(D_004C3800 + 0x100) = t27;
    UnkStruct_004D6190_q t33;   // lanes 3: never written, copied as retail does
    *(float *)&t33.w[0] = 0.0f;
    *(float *)&t33.w[1] = 3.0f;
    *(float *)&t33.w[2] = -6.0f;
    *(UnkStruct_004D6190_q *)(D_004C3800 + 0x110) = t28;
    UnkStruct_004D6190_q t34;   // lanes 3: never written, copied as retail does
    *(float *)&t34.w[0] = 3.0f;
    *(float *)&t34.w[1] = 1.0f;
    *(float *)&t34.w[2] = -2.0f;
    *(UnkStruct_004D6190_q *)(D_004C3800 + 0x120) = t29;
    UnkStruct_004D6190_q t35;   // lanes 3: never written, copied as retail does
    *(float *)&t35.w[0] = 3.0f;
    *(float *)&t35.w[1] = 2.0f;
    *(float *)&t35.w[2] = 4.0f;
    *(UnkStruct_004D6190_q *)(D_004C3800 + 0x130) = t30;
    UnkStruct_004D6190_q t36;   // lanes 3: never written, copied as retail does
    *(float *)&t36.w[0] = -3.0f;
    *(float *)&t36.w[1] = 2.0f;
    *(float *)&t36.w[2] = 4.0f;
    *(UnkStruct_004D6190_q *)(D_004C3800 + 0x140) = t31;
    *(UnkStruct_004D6190_q *)(D_004C3800 + 0x150) = t32;
    UnkStruct_004D6190_q t37;   // lanes 3: never written, copied as retail does
    *(float *)&t37.w[0] = -5.0f;
    *(float *)&t37.w[1] = 2.0f;
    *(float *)&t37.w[2] = 0.0f;
    *(UnkStruct_004D6190_q *)(D_004C3800 + 0x160) = t33;
    UnkStruct_004D6190_q t38;   // lanes 3: never written, copied as retail does
    *(float *)&t38.w[0] = -3.0f;
    *(float *)&t38.w[1] = 2.0f;
    *(float *)&t38.w[2] = 4.0f;
    *(UnkStruct_004D6190_q *)D_004C39A0 = t37;
    *(UnkStruct_004D6190_q *)(D_004C3800 + 0x170) = t34;
    *(UnkStruct_004D6190_q *)D_004C39B0 = t38;
    UnkStruct_004D6190_q t39;   // lanes 3: never written, copied as retail does
    *(float *)&t39.w[0] = 3.0f;
    *(float *)&t39.w[1] = 2.0f;
    *(float *)&t39.w[2] = 4.0f;
    *(UnkStruct_004D6190_q *)(D_004C3800 + 0x180) = t35;
    *(UnkStruct_004D6190_q *)(D_004C39B0 + 0x10) = t39;
    UnkStruct_004D6190_q t40;   // lanes 3: never written, copied as retail does
    *(float *)&t40.w[0] = 5.0f;
    *(float *)&t40.w[1] = 2.0f;
    *(float *)&t40.w[2] = 0.0f;
    *(UnkStruct_004D6190_q *)(D_004C3800 + 0x190) = t36;
    UnkStruct_004D6190_q t41;   // lanes 3: never written, copied as retail does
    *(float *)&t41.w[0] = 0.0f;
    *(float *)&t41.w[1] = 0.0f;
    *(float *)&t41.w[2] = -1.0f;
    UnkStruct_004D6190_q t42;   // lanes 3: never written, copied as retail does
    *(float *)&t42.w[0] = 0.0f;
    *(float *)&t42.w[1] = 0.0f;
    *(float *)&t42.w[2] = -1.0f;
    *(UnkStruct_004D6190_q *)(D_004C39B0 + 0x20) = t40;
    UnkStruct_004D6190_q t43;   // lanes 3: never written, copied as retail does
    *(float *)&t43.w[0] = 0.0f;
    *(float *)&t43.w[1] = 0.0f;
    *(float *)&t43.w[2] = 1.0f;
    UnkStruct_004D6190_q t44;   // lanes 3: never written, copied as retail does
    *(float *)&t44.w[0] = 0.0f;
    *(float *)&t44.w[1] = 0.0f;
    *(float *)&t44.w[2] = -1.0f;
    UnkStruct_004D6190_q t45;   // lanes 3: never written, copied as retail does
    *(float *)&t45.w[0] = 0.0f;
    *(float *)&t45.w[1] = 0.0f;
    *(float *)&t45.w[2] = -1.0f;
    *(UnkStruct_004D6190_q *)D_004C39E0 = t41;
    UnkStruct_004D6190_q t46;   // lanes 3: never written, copied as retail does
    *(float *)&t46.w[0] = 0.0f;
    *(float *)&t46.w[1] = 0.0f;
    *(float *)&t46.w[2] = 1.0f;
    *(UnkStruct_004D6190_q *)(D_004C39E0 + 0x10) = t42;
    UnkStruct_004D6190_q t47;   // lanes 3: never written, copied as retail does
    *(float *)&t47.w[0] = 0.0f;
    *(float *)&t47.w[1] = 0.0f;
    *(float *)&t47.w[2] = -1.0f;
    UnkStruct_004D6190_q t48;   // lanes 3: never written, copied as retail does
    *(float *)&t48.w[0] = 0.0f;
    *(float *)&t48.w[1] = 0.0f;
    *(float *)&t48.w[2] = -1.0f;
    *(UnkStruct_004D6190_q *)(D_004C39E0 + 0x20) = t43;
    UnkStruct_004D6190_q t49;   // lanes 3: never written, copied as retail does
    *(float *)&t49.w[0] = 0.0f;
    *(float *)&t49.w[1] = 0.0f;
    *(float *)&t49.w[2] = 1.0f;
    *(UnkStruct_004D6190_q *)(D_004C39E0 + 0x30) = t44;
    UnkStruct_004D6190_q t50;   // lanes 3: never written, copied as retail does
    *(float *)&t50.w[0] = 0.0f;
    *(float *)&t50.w[1] = 0.0f;
    *(float *)&t50.w[2] = -1.0f;
    *(UnkStruct_004D6190_q *)(D_004C39E0 + 0x40) = t45;
    UnkStruct_004D6190_q t51;   // lanes 3: never written, copied as retail does
    *(float *)&t51.w[0] = 0.0f;
    *(float *)&t51.w[1] = 0.0f;
    *(float *)&t51.w[2] = -1.0f;
    *(UnkStruct_004D6190_q *)(D_004C39E0 + 0x50) = t46;
    UnkStruct_004D6190_q t52;   // lanes 3: never written, copied as retail does
    *(float *)&t52.w[0] = 0.0f;
    *(float *)&t52.w[1] = 0.0f;
    *(float *)&t52.w[2] = 1.0f;
    *(UnkStruct_004D6190_q *)(D_004C39E0 + 0x60) = t47;
    UnkStruct_004D6190_q t53;   // lanes 3: never written, copied as retail does
    *(float *)&t53.w[0] = 0.0f;
    *(float *)&t53.w[1] = 0.0f;
    *(float *)&t53.w[2] = -1.0f;
    *(UnkStruct_004D6190_q *)(D_004C39E0 + 0x70) = t48;
    UnkStruct_004D6190_q t54;   // lanes 3: never written, copied as retail does
    *(float *)&t54.w[0] = 0.0f;
    *(float *)&t54.w[1] = 0.0f;
    *(float *)&t54.w[2] = -1.0f;
    *(UnkStruct_004D6190_q *)(D_004C39E0 + 0x80) = t49;
    UnkStruct_004D6190_q t55;   // lanes 3: never written, copied as retail does
    *(float *)&t55.w[0] = 0.0f;
    *(float *)&t55.w[1] = 0.0f;
    *(float *)&t55.w[2] = 1.0f;
    *(UnkStruct_004D6190_q *)(D_004C39E0 + 0x90) = t50;
    UnkStruct_004D6190_q t56;   // lanes 3: never written, copied as retail does
    *(float *)&t56.w[0] = 0.0f;
    *(float *)&t56.w[1] = 0.0f;
    *(float *)&t56.w[2] = -1.0f;
    *(UnkStruct_004D6190_q *)(D_004C39E0 + 0xA0) = t51;
    UnkStruct_004D6190_q t57;   // lanes 3: never written, copied as retail does
    *(float *)&t57.w[0] = 0.0f;
    *(float *)&t57.w[1] = 0.0f;
    *(float *)&t57.w[2] = -1.0f;
    *(UnkStruct_004D6190_q *)D_004C3760 = t1;
    *(UnkStruct_004D6190_q *)(D_004C39E0 + 0xB0) = t52;
    UnkStruct_004D6190_q t58;   // lanes 3: never written, copied as retail does
    *(float *)&t58.w[0] = 0.0f;
    *(float *)&t58.w[1] = 0.0f;
    *(float *)&t58.w[2] = 1.0f;
    *(UnkStruct_004D6190_q *)(D_004C39E0 + 0xC0) = t53;
    UnkStruct_004D6190_q t59;   // lanes 3: never written, copied as retail does
    *(float *)&t59.w[0] = 0.0f;
    *(float *)&t59.w[1] = 0.0f;
    *(float *)&t59.w[2] = -1.0f;
    *(UnkStruct_004D6190_q *)(D_004C39E0 + 0xD0) = t54;
    UnkStruct_004D6190_q t60;   // lanes 3: never written, copied as retail does
    *(float *)&t60.w[0] = 0.0f;
    *(float *)&t60.w[1] = 0.0f;
    *(float *)&t60.w[2] = -1.0f;
    *(UnkStruct_004D6190_q *)(D_004C39E0 + 0xE0) = t55;
    UnkStruct_004D6190_q t61;   // lanes 3: never written, copied as retail does
    *(float *)&t61.w[0] = 0.0f;
    *(float *)&t61.w[1] = 0.0f;
    *(float *)&t61.w[2] = 1.0f;
    *(UnkStruct_004D6190_q *)(D_004C39E0 + 0xF0) = t56;
    UnkStruct_004D6190_q t62;   // lanes 3: never written, copied as retail does
    *(float *)&t62.w[0] = 0.0f;
    *(float *)&t62.w[1] = 0.0f;
    *(float *)&t62.w[2] = -1.0f;
    *(UnkStruct_004D6190_q *)(D_004C39E0 + 0x100) = t57;
    UnkStruct_004D6190_q t63;   // lanes 3: never written, copied as retail does
    *(float *)&t63.w[0] = 0.0f;
    *(float *)&t63.w[1] = 0.0f;
    *(float *)&t63.w[2] = -1.0f;
    *(UnkStruct_004D6190_q *)(D_004C39E0 + 0x110) = t58;
    UnkStruct_004D6190_q t64;   // lanes 3: never written, copied as retail does
    *(float *)&t64.w[0] = 0.0f;
    *(float *)&t64.w[1] = 0.0f;
    *(float *)&t64.w[2] = 1.0f;
    *(UnkStruct_004D6190_q *)(D_004C39E0 + 0x120) = t59;
    UnkStruct_004D6190_q t65;   // lanes 3: never written, copied as retail does
    *(float *)&t65.w[0] = 0.0f;
    *(float *)&t65.w[1] = 1.0f;
    *(float *)&t65.w[2] = 3.0f;
    *(UnkStruct_004D6190_q *)(D_004C39E0 + 0x130) = t60;
    UnkStruct_004D6190_q t66;   // lanes 3: never written, copied as retail does
    *(float *)&t66.w[0] = 0.0f;
    *(float *)&t66.w[1] = 0.0f;
    *(float *)&t66.w[2] = 2.0f;
    *(UnkStruct_004D6190_q *)(D_004C39E0 + 0x140) = t61;
    UnkStruct_004D6190_q t67;   // lanes 3: never written, copied as retail does
    *(float *)&t67.w[0] = 0.0f;
    *(float *)&t67.w[1] = 0.0f;
    *(float *)&t67.w[2] = 3.0f;
    *(UnkStruct_004D6190_q *)(D_004C39E0 + 0x150) = t62;
    UnkStruct_004D6190_q t68;   // lanes 3: never written, copied as retail does
    *(float *)&t68.w[0] = 0.0f;
    *(float *)&t68.w[1] = 1.0f;
    *(float *)&t68.w[2] = 3.0f;
    *(UnkStruct_004D6190_q *)(D_004C39E0 + 0x160) = t63;
    *(UnkStruct_004D6190_q *)D_004C3B90 = t68;
    UnkStruct_004D6190_q t69;   // lanes 3: never written, copied as retail does
    *(float *)&t69.w[0] = 0.0f;
    *(float *)&t69.w[1] = 0.0f;
    *(float *)&t69.w[2] = 2.0f;
    *(UnkStruct_004D6190_q *)(D_004C39E0 + 0x170) = t64;
    UnkStruct_004D6190_q t70;   // lanes 3: never written, copied as retail does
    *(float *)&t70.w[0] = 0.0f;
    *(float *)&t70.w[1] = 0.0f;
    *(float *)&t70.w[2] = 3.0f;
    *(UnkStruct_004D6190_q *)D_004C3BA0 = t69;
    *(UnkStruct_004D6190_q *)(D_004C39E0 + 0x180) = t65;
    UnkStruct_004D6190_q t71;   // lanes 3: never written, copied as retail does
    *(float *)&t71.w[0] = 0.0f;
    *(float *)&t71.w[1] = 0.0f;
    *(float *)&t71.w[2] = 1.0f;
    *(UnkStruct_004D6190_q *)D_004C3BB0 = t70;
    *(UnkStruct_004D6190_q *)(D_004C39E0 + 0x190) = t66;
    *(UnkStruct_004D6190_q *)(D_004C3BB0 + 0x10) = t71;
    UnkStruct_004D6190_q t72;   // lanes 3: never written, copied as retail does
    *(float *)&t72.w[0] = 0.0f;
    *(float *)&t72.w[1] = 0.0f;
    *(float *)&t72.w[2] = 1.0f;
    UnkStruct_004D6190_q t73;   // lanes 3: never written, copied as retail does
    *(float *)&t73.w[0] = 0.0f;
    *(float *)&t73.w[1] = 0.5f;
    *(float *)&t73.w[2] = 0.0f;
    UnkStruct_004D6190_q t74;   // lanes 3: never written, copied as retail does
    *(float *)&t74.w[0] = 0.0f;
    *(float *)&t74.w[1] = 0.0f;
    *(float *)&t74.w[2] = 1.0f;
    *(UnkStruct_004D6190_q *)(D_004C3BB0 + 0x20) = t72;
    UnkStruct_004D6190_q t75;   // lanes 3: never written, copied as retail does
    *(float *)&t75.w[0] = 0.0f;
    *(float *)&t75.w[1] = 0.0f;
    *(float *)&t75.w[2] = 1.0f;
    *(UnkStruct_004D6190_q *)(D_004C39E0 + 0x1A0) = t67;
    UnkStruct_004D6190_q t76;   // lanes 3: never written, copied as retail does
    *(float *)&t76.w[0] = 0.0f;
    *(float *)&t76.w[1] = 0.5f;
    *(float *)&t76.w[2] = 0.0f;
    *(UnkStruct_004D6190_q *)(D_004C3BB0 + 0x30) = t73;
    *(UnkStruct_004D6190_q *)(D_004C3BB0 + 0x40) = t74;
    *(UnkStruct_004D6190_q *)(D_004C3BB0 + 0x50) = t75;
    *(UnkStruct_004D6190_q *)(D_004C3BB0 + 0x60) = t76;
    UnkStruct_004D6190_q t77;   // lanes 0, 1, 2, 3: never written, copied as retail does
    UnkStruct_004D6190_q t78;   // lanes 0, 1, 2, 3: never written, copied as retail does
    UnkStruct_004D6190_q t79;   // lanes 0, 1, 2, 3: never written, copied as retail does
    UnkStruct_004D6190_q t80;   // lanes 0, 1, 2, 3: never written, copied as retail does
    UnkStruct_004D6190_q t81;   // lanes 0, 1, 2, 3: never written, copied as retail does
    UnkStruct_004D6190_q t82;   // lanes 0, 1, 2, 3: never written, copied as retail does
    UnkStruct_004D6190_q t83;   // lanes 0, 1, 2, 3: never written, copied as retail does
    UnkStruct_004D6190_q t84;   // lanes 0, 1, 2, 3: never written, copied as retail does
    UnkStruct_004D6190_q t85;   // lanes 0, 1, 2, 3: never written, copied as retail does
}
