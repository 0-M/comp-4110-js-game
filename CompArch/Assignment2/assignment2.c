/*****************************************************************/
/* File convert_float_to_bits.c:  asks for a floating point      */
/* input number and prints the value out in decimal, hex and     */
/* bits spaced for readability.  The program expects that input  */
/* floats are stored in IEEE 754 format after scanning, and is   */
/* currently built to run on little endian machines (i.e. Compaq,*/
/* Intel, etc.).  To run this program on a big endian machine,   */
/* the bit structures would require top-to-bottom inversions.    */
/*****************************************************************/

#include <stdio.h>


int main(int argc, char * argv[])
{

union float_32{
        float   floating_value_in_32_bits;
        int     floating_value_as_int;
        struct  sign_exp_mantissa{
                unsigned  mantissa:23;
                unsigned  exponent:8;
                unsigned      sign:1;
        } f_bits;
	struct single_bits{
		unsigned  b0 :1;
		unsigned  b1 :1;
		unsigned  b2 :1;
		unsigned  b3 :1;
		unsigned  b4 :1;
		unsigned  b5 :1;
		unsigned  b6 :1;
		unsigned  b7 :1;
		unsigned  b8 :1;
		unsigned  b9 :1;
		unsigned  b10:1;
		unsigned  b11:1;
		unsigned  b12:1;
		unsigned  b13:1;
		unsigned  b14:1;
		unsigned  b15:1;
		unsigned  b16:1;
		unsigned  b17:1;
		unsigned  b18:1;
		unsigned  b19:1;
		unsigned  b20:1;
		unsigned  b21:1;
		unsigned  b22:1;
		unsigned  b23:1;
		unsigned  b24:1;
		unsigned  b25:1;
		unsigned  b26:1;
		unsigned  b27:1;
		unsigned  b28:1;
		unsigned  b29:1;
		unsigned  b30:1;
		unsigned  b31:1;
	}bit;
} float_32;

union float_32 num_1;
union float_32 num_2;
union float_32 result;

printf("\nPlease enter two positive floating point values each with:\n"); 
printf("     - no more than 6 significant digits\n"); 
printf("     - a value between   +   10**37 and 10**-37\n\n");
printf("Enter Float 1: ");
scanf("%g", &num_1.floating_value_in_32_bits);
printf("Enter Float 2: ");
scanf("%g", &num_2.floating_value_in_32_bits);
printf("\n");
int mant_1,mant_2,shift,exp_1,exp_2,mant_result;

mant_1 = num_1.f_bits.mantissa;
mant_2 = num_2.f_bits.mantissa;
exp_1 = num_1.f_bits.exponent;
exp_2 = num_2.f_bits.exponent;

shift = exp_1 - exp_2;

if(exp_1) {
   mant_1 |= (1 << 23);
}

if(exp_2) {
   mant_2 |= (1 << 23);
}

if (shift > 0)
{
  if(shift > 24)
	{
		shift = 24; // never shift more than container size, undefined in C
	}	
  mant_2 = mant_2 >> shift;
  result.f_bits.exponent = exp_1;
}

if (shift < 0)
{
  shift = -shift;
  if(shift > 24)
	{
		shift = 24; // never shift more than container size, undefined in C
	}	
  mant_1 = mant_1 >> shift;
  result.f_bits.exponent = exp_2;
}

if(shift == 0)
{
	result.f_bits.exponent = exp_2;
}

mant_result = mant_1 + mant_2;

if(mant_result & (1 << 24)) {
   mant_result >>= 1;
   result.f_bits.exponent++; // add one back to exponent 
   result.f_bits.mantissa = mant_result & ~(1 << 23); // remove hidden bit
}
else
{
   result.f_bits.mantissa = mant_result & ~(1 << 23);
}

char num_1_bit_string[43];
char num_2_bit_string[43];
char result_bit_string[43];
int i;

for(i=0; i<42; i++){
	num_1_bit_string[i] = ' ';
}
num_1_bit_string[42] = '\0';

num_1_bit_string[0] = num_1.bit.b31?'1':'0';

num_1_bit_string[2] = num_1.bit.b30?'1':'0';
num_1_bit_string[3] = num_1.bit.b29?'1':'0';
num_1_bit_string[4] = num_1.bit.b28?'1':'0';
num_1_bit_string[5] = num_1.bit.b27?'1':'0';

num_1_bit_string[7] = num_1.bit.b26?'1':'0';
num_1_bit_string[8] = num_1.bit.b25?'1':'0';
num_1_bit_string[9] = num_1.bit.b24?'1':'0';
num_1_bit_string[10] = num_1.bit.b23?'1':'0';

num_1_bit_string[12] = num_1.bit.b22?'1':'0';
num_1_bit_string[13] = num_1.bit.b21?'1':'0';
num_1_bit_string[14] = num_1.bit.b20?'1':'0';

num_1_bit_string[16] = num_1.bit.b19?'1':'0';
num_1_bit_string[17] = num_1.bit.b18?'1':'0';
num_1_bit_string[18] = num_1.bit.b17?'1':'0';
num_1_bit_string[19] = num_1.bit.b16?'1':'0';

num_1_bit_string[21] = num_1.bit.b15?'1':'0';
num_1_bit_string[22] = num_1.bit.b14?'1':'0';
num_1_bit_string[23] = num_1.bit.b13?'1':'0';
num_1_bit_string[24] = num_1.bit.b12?'1':'0';

num_1_bit_string[26] = num_1.bit.b11?'1':'0';
num_1_bit_string[27] = num_1.bit.b10?'1':'0';
num_1_bit_string[28] = num_1.bit.b9?'1':'0';
num_1_bit_string[29] = num_1.bit.b8?'1':'0';

num_1_bit_string[31] = num_1.bit.b7?'1':'0';
num_1_bit_string[32] = num_1.bit.b6?'1':'0';
num_1_bit_string[33] = num_1.bit.b5?'1':'0';
num_1_bit_string[34] = num_1.bit.b4?'1':'0';

num_1_bit_string[36] = num_1.bit.b3?'1':'0';
num_1_bit_string[37] = num_1.bit.b2?'1':'0';
num_1_bit_string[38] = num_1.bit.b1?'1':'0';
num_1_bit_string[39] = num_1.bit.b0?'1':'0';

printf("Original pattern of Float 1: %s\n",num_1_bit_string);

for(i=0; i<42; i++){
	num_2_bit_string[i] = ' ';
}
num_2_bit_string[42] = '\0';

num_2_bit_string[0] = num_2.bit.b31?'1':'0';

num_2_bit_string[2] = num_2.bit.b30?'1':'0';
num_2_bit_string[3] = num_2.bit.b29?'1':'0';
num_2_bit_string[4] = num_2.bit.b28?'1':'0';
num_2_bit_string[5] = num_2.bit.b27?'1':'0';

num_2_bit_string[7] = num_2.bit.b26?'1':'0';
num_2_bit_string[8] = num_2.bit.b25?'1':'0';
num_2_bit_string[9] = num_2.bit.b24?'1':'0';
num_2_bit_string[10] = num_2.bit.b23?'1':'0';

num_2_bit_string[12] = num_2.bit.b22?'1':'0';
num_2_bit_string[13] = num_2.bit.b21?'1':'0';
num_2_bit_string[14] = num_2.bit.b20?'1':'0';

num_2_bit_string[16] = num_2.bit.b19?'1':'0';
num_2_bit_string[17] = num_2.bit.b18?'1':'0';
num_2_bit_string[18] = num_2.bit.b17?'1':'0';
num_2_bit_string[19] = num_2.bit.b16?'1':'0';

num_2_bit_string[21] = num_2.bit.b15?'1':'0';
num_2_bit_string[22] = num_2.bit.b14?'1':'0';
num_2_bit_string[23] = num_2.bit.b13?'1':'0';
num_2_bit_string[24] = num_2.bit.b12?'1':'0';

num_2_bit_string[26] = num_2.bit.b11?'1':'0';
num_2_bit_string[27] = num_2.bit.b10?'1':'0';
num_2_bit_string[28] = num_2.bit.b9?'1':'0';
num_2_bit_string[29] = num_2.bit.b8?'1':'0';

num_2_bit_string[31] = num_2.bit.b7?'1':'0';
num_2_bit_string[32] = num_2.bit.b6?'1':'0';
num_2_bit_string[33] = num_2.bit.b5?'1':'0';
num_2_bit_string[34] = num_2.bit.b4?'1':'0';

num_2_bit_string[36] = num_2.bit.b3?'1':'0';
num_2_bit_string[37] = num_2.bit.b2?'1':'0';
num_2_bit_string[38] = num_2.bit.b1?'1':'0';
num_2_bit_string[39] = num_2.bit.b0?'1':'0';

printf("Original pattern of Float 2: %s\n",num_2_bit_string);
if(result.f_bits.exponent == 255)
{
   result.f_bits.mantissa = 0;
}
for(i=0; i<42; i++){
	result_bit_string[i] = ' ';
}
result_bit_string[42] = '\0';

result_bit_string[0] = result.bit.b31?'1':'0';

result_bit_string[2] = result.bit.b30?'1':'0';
result_bit_string[3] = result.bit.b29?'1':'0';
result_bit_string[4] = result.bit.b28?'1':'0';
result_bit_string[5] = result.bit.b27?'1':'0';

result_bit_string[7] = result.bit.b26?'1':'0';
result_bit_string[8] = result.bit.b25?'1':'0';
result_bit_string[9] = result.bit.b24?'1':'0';
result_bit_string[10] = result.bit.b23?'1':'0';

result_bit_string[12] = result.bit.b22?'1':'0';
result_bit_string[13] = result.bit.b21?'1':'0';
result_bit_string[14] = result.bit.b20?'1':'0';

result_bit_string[16] = result.bit.b19?'1':'0';
result_bit_string[17] = result.bit.b18?'1':'0';
result_bit_string[18] = result.bit.b17?'1':'0';
result_bit_string[19] = result.bit.b16?'1':'0';

result_bit_string[21] = result.bit.b15?'1':'0';
result_bit_string[22] = result.bit.b14?'1':'0';
result_bit_string[23] = result.bit.b13?'1':'0';
result_bit_string[24] = result.bit.b12?'1':'0';

result_bit_string[26] = result.bit.b11?'1':'0';
result_bit_string[27] = result.bit.b10?'1':'0';
result_bit_string[28] = result.bit.b9?'1':'0';
result_bit_string[29] = result.bit.b8?'1':'0';

result_bit_string[31] = result.bit.b7?'1':'0';
result_bit_string[32] = result.bit.b6?'1':'0';
result_bit_string[33] = result.bit.b5?'1':'0';
result_bit_string[34] = result.bit.b4?'1':'0';

result_bit_string[36] = result.bit.b3?'1':'0';
result_bit_string[37] = result.bit.b2?'1':'0';
result_bit_string[38] = result.bit.b1?'1':'0';
result_bit_string[39] = result.bit.b0?'1':'0';
if(result.f_bits.exponent == 255)
{
   result.f_bits.mantissa = 0;
}
printf("Bit pattern of result      : %s\n\n",result_bit_string);
printf("EMULATED FLOATING RESULT FROM PRINTF ==>>> %g\n",result.floating_value_in_32_bits);
printf("HARDWARE FLOATING RESULT FROM PRNITF ==>>> %g\n",num_1.floating_value_in_32_bits + num_2.floating_value_in_32_bits);
}

