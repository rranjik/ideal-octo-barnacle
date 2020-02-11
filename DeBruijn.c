#include<stdio.h>
#include<inttypes.h>

//actual DeBruijn sequence starts with 0 but setting it to 32 
//lets simplify code a little bit more
const int DeBruijn[32] = 
{
  32, 1, 28, 2, 29, 14, 24, 3, 30, 22, 20, 15, 25, 17, 4, 8, 
  31, 27, 13, 23, 21, 19, 16, 7, 26, 12, 18, 6, 11, 5, 10, 9
};

uint8_t mismatching_trailing_bits(const uint32_t* const a, const uint32_t* const b){
	//change it to the problem of finding rightmost '1' bit
	uint32_t d = *a^(~*b);
	//change it to problem of finding lg(x) when x is a power of 2
	//d & -d preserves the rightmost '1' (making it a power of 2) alone
	return DeBruijn[((uint32_t)((d & -d) * 0x077CB531U)) >> 27];
}

int main(){
	uint32_t a = 0XDEADBEEFU;
	uint32_t b = 0XDEADBEECU;
	//do not compare if they are equal
	int res = (a^b)?(mismatching_trailing_bits(&a, &b)):0;
	printf("number of mistmatching trailing bits are: %"PRIu32"\n", res);
	return 0;
}
