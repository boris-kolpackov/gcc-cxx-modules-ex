/* { dg-do run { target int128 } } */
/* { dg-additional-options "-fgcse-after-reload" } */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
int a, b, c;
int
d (u16 e, u64 f)
{
  b |= e;
  __builtin_memset (&f, e, 2);
  a = (u16) - e >= 2 ? : __builtin_popcountll (f);
  return a + c;
}

int
main (void)
{
  __int128 x = d (~0, 0);
  if (x != 16)
    __builtin_abort ();
  return 0;
}
