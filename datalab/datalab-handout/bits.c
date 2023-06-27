/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  // (x & (~y)) | (y & (~x))
  // a | b = ~(~a & ~b)
  return ~(~(x & (~y)) & ~(y & (~x)));
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  return 1 << 31;
}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  // int tmax (0111111) = ~(1 << 31);
  // tmax + 1= tmin;
  // x + x = 0 ==> x = 0 或 x = tmin
  // (x + 1 != 0) && (x + x + 2 = 0)
  return !(x + 1 + x + 1) & (!!(x + 1));
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  // integer required beweetn 0 and 0xFF.
  int mask = (0xAA) | (0xAA << 8) | (0xAA << 16) | (0xAA << 24);
  return !((x & mask) ^ (mask));
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ~x + 1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  // 0x30 = 0011,0000 0x39 = 0011, 1001 所以就是前4bit是0011, 后4bit是0xxx或100x
  int highEqual = !((x >> 4) ^ (0x3));
  int lowOneBit = x>>1 & 0x1;
  int lowTwoBit = x>>2 & 0x1;
  int lowThreeBit = x>>3 & 0x1;
  return highEqual & (!lowThreeBit | (!lowTwoBit & !lowOneBit));
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  // x = 0, 0xffffffff + 1 = 0x0 ==> allBits & y = 0, ~allBits & z = z
  // x != 0, 0xffffffff ===> y = allBits & y = y ~allBits & z = 0
  int allBitsX = ~(!!x) + 1;
  return (allBitsX & y) | (~allBitsX & z);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  int xSign = (x >> 31) & 1;
  int ySign = (y >> 31) & 1;
  int signEquals = !(xSign ^ ySign);
  int signLess = (xSign) & !(ySign);
  int signToZeroMask = ~(1 << 31);
  x = x & signToZeroMask;
  y = y & signToZeroMask;
  // y - x > 0，即sign = 0
  return signLess | (signEquals & !((y + (~x + 1)) >> 31));
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  // 0 -> 1, 其他变0
  // 这题的本质是，让0做一个转换后，得到某个bit位置是某个值
  // 只有0,Tmin的相反数的符号位不变，只有0和0的相反数都是sign=0
  return ~((x >> 31) | ((~x + 1) >> 31)) & 0x1;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4  (-5 = -8 + 3, -8需要4bit)
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  // 正数: 开头的连续0都去掉，再在前面补一个符号位（例如0001 1010 => 01 1010)，所以就是32 - 连续0数量 + 1
  // 负数: 开头的连续1都去掉，最后一个1的位置就是符号位，仍然是1 (例如11001010 => 1001010, 10001010 => 10001010)
  // 所以就是32 - 开头连续0数量 + 1 = 第一个1的下标 + 1
  // 检查前16位是否有1，如果有的话，那bits=16 + bits(前16位), 没有的话, bits = bits(后16位)，以此类推
  int bit16, bit8, bit4, bit2, bit1;
  // 注意,如果x为负，则x >> 31为0xffffffff
  int sign = x >> 31;
  // 因为正数记录从左到右第一个1,负数记录第一个0
  // 所以可以对操作数取反，将负数转为正数，正数不变，便于更好的计算
  x ^= sign;
  // 二分查找，先判断高16位有无存在1,并将范围缩小到高16位或低16位
  // 如果高16位存在0,则bit16 == 16,否则等于0
  bit16 = (!!(x >> 16)) << 4;
  x >>= bit16;
  // 查找剩余16位中的高8位是否存在1
  bit8 = (!!(x >> 8)) << 3;
  x >>= bit8;
  // 查找剩余8位中的高4位是否存在1
  bit4 = (!!(x >> 4)) << 2;
  x >>= bit4;
  // 查找剩余4位中的高2位是否存在1
  bit2 = (!!(x >> 2)) << 1;
  x >>= bit2;
  // 查找剩余2位中的高1位是否存在1
  bit1 = (!!(x >> 1)) << 0;
  x >>= bit1;
    // 注意return中要再加上一个符号位
  return bit16 + bit8 + bit4 + bit2 + bit1 + x + 1;
}
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
// float: [s 1bit][exp 8bit][frac 23]
unsigned floatScale2(unsigned uf) {
  // Float Basic:
  // NaN or infinity => self
  // bias = 127, V = -1^s * M * 2^E
  // Normalized: M = 1 + f, E = exp - 127
  // Denormalized (exp all zero): M = f, E = 1 - 127 = -126
  // Special Number (exp all one)

  // if special Number (inifinate <frac all zero> || NaN) => self
  // normal condition: Normalized:exp + 1, Denormalized: frac << 1
  // strange condition: 1. normalized -> inifinate 2. Denormalized -> normalized

  unsigned signMask = 0x80000000, expMask = 0x7f800000, fracMask = 0x007fffff;
  unsigned sign = uf & signMask, exp = uf & expMask, frac = uf & fracMask;
  // all one, NaN or inf
  if (exp == expMask) {
    return uf;
  }
    // Denormalized
  if (exp == 0) {
    frac <<= 1; 
    // 神奇的是，这里的边界情况也正确，当frac第一位是1时,1xxx,会溢出到exp,使得exp变成1, frac变成xxx0
    // 这是规格化的,认为是1.xxx0 * 2，刚好是原来1xxx * 2
  } else { // Normalized
    // exp = (exp + 0x800000) & expMask;  // exp + 1
    exp += 0x800000;  // exp + 1
    if (exp == expMask) {
        frac = 0;
    }
    // 这里边界情况也正确，当normalized的exp为11111110时, exp + 1变成全1，此时把frac全变成0，就看作inf
  }
  return sign | exp | frac;
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf)
{
  unsigned sign = (uf >> 31) & 0x1;
  unsigned exp = (uf >> 23) & 0xFF;
  unsigned frac = uf & 0x7FFFFF;
  int E = exp - 127;
  if (E < 0)  return 0;
  if (exp == 0xFF || E >= 31)  return 0x80000000u;
  else {
    frac = frac | (1 << 23);
    if (E <= 23)  frac >>= (23 - E);
    else  frac <<= (E - 23);
  }
  
  if (sign) return -frac;
  else  return frac;
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
  if (x > 127)  return 0xFF << 23; // largest normalized < 2 * 2 ^ 127 = 2 ^ 128
  else if (x < -149)  return 0; // smallest denormalized = 2 ^ (1 - 127) + 2 ^ (-23) = 2 ^ (-149)
  else if (x >= -126)  return (x + 127) << 23; // smallest normalized = 2 ^ (-126)
  else return 1 << (x + 126 + 23);
}
