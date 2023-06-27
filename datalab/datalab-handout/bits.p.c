#line 145 "bits.c"
int bitXor(int x, int y) {


  return ~(~(x &( ~y)) & ~(y &( ~x)));
#line 31 "<command-line>"
#include "/usr/include/stdc-predef.h"
#line 149 "bits.c"
}
#line 156
int tmin(void) {
  return 1 << 31;
}
#line 167
int isTmax(int x) {
#line 172
  return !(x + 1 + x + 1) &( !!(x + 1));
}
#line 182
int allOddBits(int x) {

  int mask=(  0xAA) |( 0xAA << 8) |( 0xAA << 16) |( 0xAA << 24);
  return !((x & mask) ^( mask));
}
#line 194
int negate(int x) {
  return ~x + 1;
}
#line 207
int isAsciiDigit(int x) {

  int highEqual=  !((x >> 4) ^( 0x3));
  int lowOneBit=  x>>1 & 0x1;
  int lowTwoBit=  x>>2 & 0x1;
  int lowThreeBit=  x>>3 & 0x1;
  return highEqual &( !lowThreeBit |( !lowTwoBit & !lowOneBit));
}
#line 222
int conditional(int x, int y, int z) {


  int allBitsX=  ~(!!x) + 1;
  return (allBitsX & y) |( ~allBitsX & z);
}
#line 235
int isLessOrEqual(int x, int y) {
  int xSign=(  x >> 31) & 1;
  int ySign=(  y >> 31) & 1;
  int signEquals=  !(xSign ^ ySign);
  int signLess=(  xSign) & !(ySign);
  int signToZeroMask=  ~(1 << 31);
  x = x & signToZeroMask;
  y = y & signToZeroMask;

  return signLess |( signEquals & !((y +( ~x + 1)) >> 31));
}
#line 255
int logicalNeg(int x) {
#line 259
  return ~((x >> 31) |(( ~x + 1) >> 31)) & 0x1;
}
#line 273
int howManyBits(int x) {
#line 278
  int bit16;int bit8;int bit4;int bit2;int bit1;

  int sign=  x >> 31;


  x ^= sign;


  bit16 =( !!(x >> 16)) << 4;
  x >>= bit16;

  bit8 =( !!(x >> 8)) << 3;
  x >>= bit8;

  bit4 =( !!(x >> 4)) << 2;
  x >>= bit4;

  bit2 =( !!(x >> 2)) << 1;
  x >>= bit2;

  bit1 =( !!(x >> 1)) << 0;
  x >>= bit1;

  return bit16 + bit8 + bit4 + bit2 + bit1 + x + 1;
}
#line 315
unsigned floatScale2(unsigned uf) {
#line 327
  unsigned signMask=  0x80000000;unsigned expMask=0x7f800000;unsigned fracMask=0x007fffff;
  unsigned sign=  uf & signMask;unsigned exp=uf&expMask;unsigned frac=uf&fracMask;

  if (exp == expMask) {
    return uf;
  }

  if (exp == 0) {
    frac <<= 1;


  } else {

    exp += 0x800000;
    if (exp == expMask) {
        frac = 0;
    }

  }
  return sign | exp | frac;
}
#line 360
int floatFloat2Int(unsigned uf)
{
  unsigned sign=(  uf >> 31) & 0x1;
  unsigned exp=(  uf >> 23) & 0xFF;
  unsigned frac=  uf & 0x7FFFFF;
  int E=  exp - 127;
  if (E < 0) return 0;
  if (exp == 0xFF || E >= 31) return 0x80000000u;
  else {
    frac = frac |( 1 << 23);
    if (E <= 23) frac >>=( 23 - E);
    else frac <<=( E - 23);
  }

  if (sign) return -frac;
  else return frac;
}
#line 390
unsigned floatPower2(int x) {
  if (x > 127) return 0xFF << 23;
  else if (x < -149) return 0;
  else if (x >= -126) return (x + 127) << 23;
  else return 1 <<( x + 126 + 23);
}
