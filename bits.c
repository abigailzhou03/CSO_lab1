/* 
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
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

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

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

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
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
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
  return ~(~((~x)&y) & ~(x&(~y)));
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  return (1 << 31);
}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 2
 */
int isTmax(int x) {
  return !(~(x ^ (x + 1))) & !(!(x + 1));
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  int oddX = x & ((0xAA << 24) + (0xAA << 16) + (0xAA << 8) + 0xAA);
  int evenX = (oddX << 1) | 0x1;
  int combined = oddX | evenX;
  return !(~combined);
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return (~x + 0x1);
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
  return !((x & (~0x7)) ^ (0x30)) + !(x ^ 0x38) + !(x ^ 0x39);
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  int bool_x = !(!x);
  bool_x |= bool_x << 1;
  bool_x |= bool_x << 2;
  bool_x |= bool_x << 4;
  bool_x |= bool_x << 8;
  bool_x |= bool_x << 16;
  return (bool_x & y) | (~bool_x & z);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  int diff_sign = (!(x >> 31) ^ !(y >> 31));
  int neg_vs_pos = diff_sign & (x >> 31);
  int same_sign_less = !diff_sign & !((y + (~x + 1)) >> 31);
  return neg_vs_pos | same_sign_less;
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
  int a = x;
  a |= a >> 1;
  a |= a >> 2;
  a |= a >> 4;
  a |= a >> 8;
  a |= a >> 16;
  a = ~a;
  a = a & 0x1;
  return a;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  int is_min = !(x ^ (0x1 << 31));
  int sign = ((x >> 31) & 1);
  int bool_x = sign;
  int px, px_orig;
  int pxs = 0;
  int mask1, mask2, mask3, mask4;
  int sum, sum_minus_one, extra_bit_for_sign;

  is_min |= is_min << 1;
  is_min |= is_min << 2;
  is_min |= is_min << 4;
  is_min |= is_min << 8;
  is_min |= is_min << 16;
  bool_x |= bool_x << 1;
  bool_x |= bool_x << 2;
  bool_x |= bool_x << 4;
  bool_x |= bool_x << 8;
  bool_x |= bool_x << 16;
  px = (bool_x & (~x + 1)) | (~bool_x & x);

  px_orig = px;

  /*copy the 1s to the right*/
  px |= px >> 1;
  px |= px >> 2;
  px |= px >> 4;
  px |= px >> 8;
  px |= px >> 16;

  /* count all the 1s bits by adding them up in parallel*/
  pxs = px;
  mask1 = 0x55;
  mask1 = mask1 | (mask1 << 8);
  mask1 = mask1 | (mask1 << 16);
  pxs = (pxs & mask1) + ((pxs >> 1) & mask1);
  /* add odd bits to even bits*/

  mask2 = 0x33;
  mask2 = mask2 | (mask2 << 8);
  mask2 = mask2 | (mask2 << 16);
  pxs = (pxs & mask2) + ((pxs >> 2) & mask2);

  mask3 = 0x0f;
  mask3 = mask3 | (mask3 << 8);
  mask3 = mask3 | (mask3 << 16);
  pxs = (pxs + (pxs >> 4)) & mask3;

  mask4 = 0xff;
  mask4 = mask4 | (mask4 << 16);
  pxs = (pxs + (pxs >> 8)) & mask4;
  pxs = (pxs + (pxs >> 16)) & 0xff;

  sum = pxs;
  sum_minus_one = sum + ~0x0;
  /* add 1 for sign bits but no need to add for negative power of two*/
  extra_bit_for_sign = !(!(px_orig ^ (0x1 << sum_minus_one)));
  sum = sum + ((bool_x & extra_bit_for_sign) | (~bool_x & 0x1));
  return (is_min & 32) | (~is_min & sum);
}
//float
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
  unsigned exp;
  unsigned frac;
  if (uf == 0)
    return uf;
  exp = uf & 0x7f800000;
  if (exp == 0x7f800000)
    return uf;
  if (exp != 0x0) {
    exp = exp + 0x00800000;
    if (exp == 0x7f800000)
      uf = uf & 0xff800000;
    uf = uf & 0x807fffff;
    uf = uf | exp;
  }
  else {
    frac = uf & 0x007fffff;
    frac = frac << 1;
    uf = uf & 0xff800000;
    uf = uf | frac; 
  }
  return uf;
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
  unsigned sign = x>>31 & 1;
  unsigned exp, frag;
  unsigned absi = sign ? -x : x;
  int shift;
  if (absi == 0) {
      return 0;
  }
  shift = 0;
  while (!(absi&0x80000000)) {
      absi <<= 1;
      shift++;
  }
  absi <<= 1;
  shift++;
  exp = 159-shift; // 127 + 32 - shift
  frag = absi >> 9;
  if (shift < 9) {
      unsigned rest = 1<<(9-shift);
      unsigned rest_m = rest >> 1;
      unsigned frag_r = absi>>shift & (rest-1);
      unsigned addition;
      if (frag_r > rest_m) {
          addition = 1;
      } else if (frag_r < rest_m) {
          addition = 0;
      } else {
          addition = frag&1 ? 1 : 0;
      }
      frag += addition;
      if (frag >> 23) exp++;
      frag &= 0x7fffff;
  }
  return sign<<31 | exp<<23 | frag;
}
/* 
 * float_f2i - Return bit-level equivalent of expression (int) f
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
int float_f2i(unsigned uf) {
  int exp;
  unsigned frac;
  unsigned sign_bit;
  if (uf == 0)
    return 0;
  sign_bit = uf & 0x80000000;
  exp = uf & 0x7f800000;
  exp = exp >> 23;
  exp = exp - 127;
  if (exp > 30)
    return 0x80000000;
  if (exp < 0)
    return 0;
  frac = uf & 0x007fffff;
  frac = frac | 0x00800000;
  if (exp < 23)
    frac = frac >> (23 - exp);
  if (exp > 23)
    frac = frac << (exp - 23);
  if (sign_bit == 0x80000000)
    frac = ~frac + 0x1;
  return frac;
}
