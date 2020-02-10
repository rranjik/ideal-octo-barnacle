#include<iostream>

template<typename T>
auto matching_leading_bits(const T a, const T b)-> uint8_t{
	auto bitwidth = sizeof(T)*8;
	//compute xor
	auto diff = a^b;
	//mask to extact the MSB
	auto mask = (T)1<<(bitwidth-1);
	auto count = 0;
	auto bitwidthc = bitwidth;
	//unitl there are bits left and the MSB was same
	while(bitwidth&&(!(diff&mask))){
		bitwidth--;
		diff<<=1;
		count++;
	}
	//if we ran out of bits they were same to begin width
	return (!bitwidth)?(bitwidthc):count;
}

int main(){
	uint8_t a8 = 0XFF;
	uint8_t b8 = 0X00;
	std::cout<<"ans = "<<(unsigned)matching_leading_bits(a8, b8)<<std::endl;
	uint16_t a16 = 0XAEFF;
	uint16_t b16 = 0XDE00;
	std::cout<<"ans = "<<(unsigned)matching_leading_bits(a16, b16)<<std::endl;
	uint32_t a32 = 0x1334DDEF;
	uint32_t b32 = 0X1234DDEE;
	std::cout<<"ans = "<<(unsigned)matching_leading_bits(a32, b32)<<std::endl;
	uint64_t a64 = 0XFFFFFFFF00000000;
	uint64_t b64 = 0XFFFFFFFFFFFFFFFF;
	std::cout<<"ans = "<<(unsigned)matching_leading_bits(a64, b64)<<std::endl;
	return 0;
}
