#include <iostream>
using namespace std;

bitset<64> key_64;
bitset<48> key[16];

int PC_1[] = {57, 49, 41, 33, 25, 17, 9,
			   1, 58, 50, 42, 34, 26, 18,
			  10,  2, 59, 51, 43, 35, 27,
			  19, 11,  3, 60, 52, 44, 36,
			  63, 55, 47, 39, 31, 23, 15,
			   7, 62, 54, 46, 38, 30, 22,
			  14,  6, 61, 53, 45, 37, 29,
			  21, 13,  5, 28, 20, 12,  4}; 

void key_gen()
{
	bitset<56> key_56;
    bitset<28> left;
    bitset<28> right;
    bitset<48> key_48;

    // Slimming down 64 bits key to 56 bits
    for (int i = 0; i < 56; ++i)
    {
		key_56[55-i] = key_64[64 - PC_1[i]];

    }

    for (int round = 0; round < 8; ++round)
    {
    	for (int i = )
    }


}

int main()
{

	return 0;
}