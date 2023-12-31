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
/* Copyright (C) 1991-2023 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 10.0.0.  Version 10.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2017, fifth edition, plus
   the following additions from Amendment 1 to the fifth edition:
   - 56 emoji characters
   - 285 hentaigana
   - 3 additional Zanabazar Square characters */
/*
 * bitAnd - x&y using only ~ and |
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y)
{
  return ~(~(x) | ~(y));
}
/*
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n)
{
  /* Shifta x até que o byte desejado esteja no começo e depois zera
   todos os outros bytes */
  x = x >> (n << 3);
  return x & 0xff;
}
/*
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int logicalShift(int x, int n)
{
  /* Primeiro a função faz o right shift de x n vezes, então é criada
    uma máscara para zerar os bits à esquerda dos bits procurados,
    transformando um shift aritmético em um lógico.*/
  int shifted, logical_not_n, _1, num, resp;
  shifted = x >> n;                               // shift right aritmético.
  logical_not_n = !n;                             // se n=0, 1; caso contrário, 0.
  _1 = ~1 + 1;                                    // 1 negativo.
  num = ((1 << 31) << logical_not_n) >> (n + _1); // máscara
  resp = shifted & (~num);                        // apaga os bits criados à esquerda
  return resp;
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x)
{
  /* Para entender o funcionamento do mecanismo, começo com um caso menor:
    considere um inteiro de 1 byte a7a6a5a4a3a2a1a0.

    Na primeira iteração, temos: (a7a6*a5a4*a3a2*a1a0*) + (xa7*a6a5*a4a3*a2a1*) =
    = [0(a7+a6)0(a5+a4)0(a3+a2)0(a1+a0)], sendo os bits marcados com "*" os selecionados
    pela máscara e x podendo ser 1 ou 0 por causa do shift right aritmético. Sabe-se que
    as somas das duplas de ai são no máximo 2 (10 em binário).

    Na segunda iteração, temos:
    {[0(a7+a6)][0(a5+a4)]*[0(a3+a2)][0(a1+a0)]*} + {[00][0(a7+a6)]*[0(a5+a4)][0(a3+a2)]*} =
    = [000(a7+a6+a5+a4)000(a3+a2+a1+a0)], sendo os pares de bits marcados com "*" os
    selecionados pela máscara. Sabe-se que as somas dos quartetos de ai são no máximo
    4 (100 em binário).

    Na terceira iteração, temos:
    {[000(a7+a6+a5+a4)][000(a3+a2+a1+a0)]*} + {[0000][000(a7+a6+a5+a4)]*} =
    = [0000000(a7+a6+a5+a4+a3+a2+a1+a0)], sendo os quartetos de bits marcados com "*" os
    selecionados pela máscara. Sabe-se que a soma do octeto de ai são no máximo 8
    (1000 em binário).

    Por fim, a última máscara apenas seleciona o byte menos significativo, que contém a
    soma de todos os ai e, portanto, a contagem de bits 1.

    No caso, com inteiros de 32 bits, o mecanismo é o mesmo, porém com 5 iterações. */
  int mask1 = 0x55 | (0x55 << 8) | (0x55 << 16) | (0x55 << 24); // 01010101...
  int mask2 = 0x33 | (0x33 << 8) | (0x33 << 16) | (0x33 << 24); // 00110011...
  int mask3 = 0x0F | (0x0F << 8) | (0x0F << 16) | (0x0F << 24); // 00001111...
  int mask4 = 0xFF | (0xFF << 16);                              // 0000000011111111...
  int mask5 = 0x1F;                                             // ...0000000000011111 (soma de 16 bits ocupa no máximo 5 bits).
  x = (x & mask1) + ((x >> 1) & mask1);
  x = (x & mask2) + ((x >> 2) & mask2);
  x = (x & mask3) + ((x >> 4) & mask3);
  x = (x & mask4) + ((x >> 8) & mask4);
  x = (x & mask5) + ((x >> 16) & mask5);
  return x;
}
/*
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int bang(int x)
{
  /* A ideia é que x | -x é 0 , se e somente se, x = 0 e, além disso,
  x ou -x será um número negativo (ou ambos no caso 0x80000000), com o bit mais
   significativo
  igual a 1.

  Portanto, quando shiftado para a direita 31 vezes, se x = 0, o resultado é 0, se x != 0,
  o resultado é -1. Somando 1, temos a saída desejada.*/
  int _x, resp;
  _x = ~x + 1;                 // -x
  resp = ((x | _x) >> 31) + 1; // x = 0: 1, x != 0: 0
  return resp;
}
/*
 * tmin - return minimum two's complement integer
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void)
{
  /* O número mínimo de 32 bits é 0x80000000 (100000000000...), em
    complemento de dois. O pensamento é análogo à representação de
    3 bits, na qual 100 (-4) é o menor número. */
  return 1 << 31;
}
/*
 * fitsBits - return 1 if x can be represented as an
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n)
{
  /* Se x pode ser representado em n bits os 32-n bits mais significativos
    serão iguais ao n-ésimo bit da direita para a esquerda. */
  int _n, mask, resp;
  _n = ~n + 1; // -n
  mask = (x << (32 + _n)) >> (32 + _n);
  resp = !(x ^ mask); // se x == mask: 1, x != mask: 0
  return resp;
}
/*
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n)
{
  /* A ideia é que se x for positivo, o resultado é apenas x >> n, porém
  se x for negativo tem-se um problema, pois a operação de shift para a direita
  arrendonda sempre para o menor inteiro e não para o mais próximo de 0.

  Para resolver o problema, é criada uma máscara que resulta em 0 para números positivos
  e (2^n)-1 para números negativos, essa máscara então é somada a x e por fim é feita a
  operação. Alguns exemplos para ficar claro: divpwr(-15, 2) = -3, pois (-15+3)/4 = -3;
  divpwr(-16, 3) = -2, pois (-16+7)/8 = -1,125, que arredondado para baixo é -2.*/
  int _1, mask, resp;
  _1 = ~0;                            // -1
  mask = (x >> 31) & ((1 << n) + _1); // 0 se x >= 0, (2^n)-1 se x < 0.
  resp = (x + mask) >> n;             // x >> n se x >= 0, (x + 2^n) >> n se x < 0.
  return resp;
}
/*
 * negate - return -x
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x)
{
  /* Essa lógica já foi usada em vários desafios anteriores:
    -x = ~x +1, pela representação de complemento de 2. */
  return ~x + 1;
}
/*
 * isPositive - return 1 if x > 0, return 0 otherwise
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x)
{
  /* A ideia é que se x > 0, o bit mais significativo será 0 e se x < 0,
    o bit mais significativo será 1. No entanto deve ter uma verificação se x == 0,
    pois também terá o bit mais significativo igual a 0, mas deve retornar 0.

    Para isso, basta fazer uma verificação inicial se x é 0,  fazer x >> 31 para
    preencher todos os bits com o sinal de x e fazer a operação !(shifted & 1) que
    retorna o inverso do sinal de x (1 para x > 0 e 0 para x < 0). */
  int if_0, shifted, resp;
  if_0 = !!x;                     // x == 0: 0, x != 0: 1
  shifted = x >> 31;              // x >= 0: 0x0, x < 0: 0xffffffff
  resp = (!(shifted & 1)) & if_0; // x > 0: 1, x <= 0: 0
  return resp;
}
/*
 * isLessOrEqual - if x <= y  then return 1, else return 0
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y)
{
  /* A metodologia neste desafio foi verificar o sinal de x e y pelas variáveis
  if_x_neg e if_y_neg e o valor da diferença entre x e y na variável dif. No entanto,
  o valor de dif não é confiável para variáveis com sinais diferentes por possível overflow.
  Para x <= y, dif <= 0 (se os sinais de x e y são iguais). Para detectar o sinal de dif, foi usado
  o mesmo algoritmo da função isPositive. Ao final, com a ajuda de um Mapa de Karnaugh com as
  variáveis if_x_neg, if_y_neg e is_positive, foi formulada a expressão booleana da variável
  resposta. */
  int _y, if_x_neg, if_y_neg, dif, if_0, shifted, is_positive, resp;
  _y = ~y + 1;                           // -y
  if_x_neg = (x >> 31) & 1;              // x < 0: 1, x >= 0: 0
  if_y_neg = (y >> 31) & 1;              // y < 0: 1, y >= 0: 0
  dif = x + _y;                          // x - y
  if_0 = !!dif;                          // dif == 0: 0, dif != 0: 1
  shifted = dif >> 31;                   // dif >= 0: 0x0, dif < 0: 0xfffffffff
  is_positive = (!(shifted & 1)) & if_0; // dif > 0: 1, dif <= 0: 0
  resp = ((!is_positive) & ((!if_y_neg) | if_x_neg)) | (if_x_neg & (!if_y_neg));
  return resp;
}
/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int ilog2(int x)
{
  /* A ideia é fazer uma busca binária pelo bit setado mais significativo, cuja posição será a resposta
  esperada. As somas na variável resposta servem para o resultado ficar correto após o shift de x, pois
  a posição final deve considerar essa operação. */
  int resp, found;
  resp = 0; // seta a variável resp

  found = ((!!(x >> 16)) << 31) >> 31; // 0xffffffff se há bit setado nos 2 primeiros bytes, 0 se não
  resp = resp + (found & 16);          // Aqui a resposta será somada de 16 caso o bit procurado esteja nos
  x = x >> (found & 16);               // 2 primeiros bytes e x shiftado 16x, caso contrário nada acontece

  found = ((!!(x >> 8)) << 31) >> 31; // 0xffffffff se há bit setado nos 24 primeiros bits, 0 se não
  resp = resp + (found & 8);          // Aqui a resposta será somada de 8 caso o bit procurado esteja nos
  x = x >> (found & 8);               // 24 primeiros bits e x shiftado 8x, caso contrário nada acontece

  found = ((!!(x >> 4)) << 31) >> 31; // 0xffffffff se há bit setado nos 28 primeiros bits, 0 se não
  resp = resp + (found & 4);          // Aqui a resposta será somada de 4 caso o bit procurado esteja nos
  x = x >> (found & 4);               // 28 primeiros bits e x shiftado 4x, caso contrário nada acontece

  found = ((!!(x >> 2)) << 31) >> 31; // 0xffffffff se há bit setado nos 30 primeiros bits, 0 se não
  resp = resp + (found & 2);          // Aqui a resposta será somada de 2 caso o bit procurado esteja nos
  x = x >> (found & 2);               // 30 primeiros bits e x shiftado 2x, caso contrário nada acontece

  found = ((!!(x >> 1)) << 31) >> 31; // 0xffffffff se há bit setado nos 31 primeiros bits, 0 se não
  resp = resp + (found & 1);          // Aqui a resposta será somada de 1 caso o bit procurado esteja nos
                                      // 31 primeiros bits, caso contrário nada acontece
  return resp;
}
/*
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf)
{
  /* Para fazer a operação -f, basicamente deve-se inverter o bit mais significativo,
  que guarda a informação do sinal. No entanto, a priori, deve-se detectar NaN: definido
  na representação de single precision como todos os bits do expoente iguais a 1 e a
  mantissa diferente de 0 */
  int mask_exp, mask_mant;
  unsigned int resp;
  mask_exp = 0x7f800000;                                       // 0111111110000000...
  mask_mant = 0x7fffff;                                        // 0000000001111111...
  if ((!((uf & mask_exp) ^ mask_exp)) && (!!(uf & mask_mant))) // if(NaN)
    return uf;
  else
  {
    resp = uf ^ 0x80000000;
    return resp;
  }
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
unsigned float_i2f(int x)
{
  unsigned int resp;
  int s, e, m, round;
  if ((!x)) // if(x == 0)
    return x;
  else
  {
    s = x < 0; // captura o sinal do número
    e = 158;   // 127 + 31
    m = 0;
    if (s && (x != 0x80000000))   // if(x < 0)
      x = -x;                     // a mantissa não é representada em C2
    while ((x & 0x80000000) == 0) // while(bit mais significativo = 0)
    {
      /* No fim do laço, x estará com o bit mais significativo igual a 1
        e os bits restantes serão separados em 2 grupos: 8-30 (23 bits para
        a mantissa) e 0-7 (bits que "sobraram para a direita", que serão
        importantes para arrendondar a mantissa no final)*/
      x = x << 1;
      e--; // o expoente será basicamente a posição do bit mais significativo setado
    }
    // printf("%d %d %d %d\n", x, e, m, s);
    round = x & 0xff;                               // pega os bits 0-7
    m = x >> 8;                                     // shifta os bits 8-30 para os 23 bits menos significativos
    m = m & 0x7fffff;                               // pega os bits 8-30
    if ((round > 128) || (round == 128 && (m & 1))) // arredonda para cima
    {
      m++;
      if (m > 0x7fffff) // renormalizar
      {
        m = (m & 0x7fffff) >> 1;
        e++;
      }
    }
    resp = (s << 31) | (e << 23) | m; // monta a representação final
    return resp;
  }
}
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
unsigned float_twice(unsigned uf)
{
  unsigned int mask_exp, mask_mant, sig, exp, mant, resp;
  mask_exp = 0x7f800000;                                              // 0111111110000000...
  mask_mant = 0x7fffff;                                               // 0000000001111111...
  if ((!uf) | (!(uf ^ 0x80000000)) | (!((uf & mask_exp) ^ mask_exp))) // if(uf == 0 | NaN | Inf)
    return uf;
  sig = (uf & 0x80000000);         // separa o bit de sinal
  exp = (uf & mask_exp);           // separa os bits do expoente
  mant = (uf & mask_mant);         // separa os bits da mantissa
  if (!exp)                        // if(exp == 0)
    mant = mant << 1;              // apenas multiplica a mantissa por 2 normalmente
  else                             // if(exp != 0)
    exp = ((exp >> 23) + 1) << 23; // incrementa o expoente
  resp = sig | exp | mant;         // forma o número de novo, da forma esperada
  return resp;
}
