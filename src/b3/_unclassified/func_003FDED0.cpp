// func_003FDED0 -- tiny-function batch (tools/tiny_batch.py, lifted).
// Unnamed in every table, so a placeholder with C linkage (the asm label); file and Area unknown, so
// _unclassified/. Structs are declared with only the fields touched; every type is [G] (instruction
// widths); `self` is whatever a0 points to.
// Hand-finished from the lifted source (dperm (decomp-permuter, background run): while (((signed char) c) != 0); while ((c = (signed char) c) != 0)).

extern "C" void func_003FDED0 ( void *n0, unsigned short * p0 , const char * p1 );

// 0x003FDED0
void func_003FDED0(void *n0, unsigned short *p0, const char *p1)
{
  int c = *p1;
  while ((c = (signed char) c) != 0)
  {
    if ((c >= 'a') && (c <= 'z'))
    {
      *p0 = ((c + 0x20) << 8) | 0x82;
    }
    else
      if (((c >= 'A') && (c <= 'Z')) || ((c >= '0') && (c <= '9')))
    {
      *p0 = ((c + 0x1F) << 8) | 0x82;
    }
    else
      if (c == ' ')
    {
      *p0 = 0x4081;
    }
    else
    {
      *p0 = 0;
    }
    p1++;
    p0++;
    c = *p1;
  }

  *p0 = 0;
}
