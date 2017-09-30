#include <iostream>
using namespace std;

// bitset<64> key_64;
bitset<48> key[8];
bitset<64> key_64("0100101101000101010110010011000000110001001100100011001100110100");

int shift_count[] = {1, 1, 2, 2, 2, 2, 2, 2};

int PC_1[] = {57, 49, 41, 33, 25, 17, 9,
			   1, 58, 50, 42, 34, 26, 18,
			  10,  2, 59, 51, 43, 35, 27,
			  19, 11,  3, 60, 52, 44, 36,
			  63, 55, 47, 39, 31, 23, 15,
			   7, 62, 54, 46, 38, 30, 22,
			  14,  6, 61, 53, 45, 37, 29,
			  21, 13,  5, 28, 20, 12,  4}; 

int PC_2[] = {14, 17, 11, 24,  1,  5,
			   3, 28, 15,  6, 21, 10,
			  23, 19, 12,  4, 26,  8,
			  16,  7, 27, 20, 13,  2,
			  41, 52, 31, 37, 47, 55,
			  30, 40, 51, 45, 33, 48,
			  44, 49, 39, 56, 34, 53,
			  46, 42, 50, 36, 29, 32};

bitset<28> shift_left(bitset<28> k, int shift)
{
	bitset<28> temp = k;

	for(int i = 27; i >= 0; --i)
	{
		if(i-shift < 0)
			k[i] = temp[i-shift+28];
		else
			k[i] = temp[i-shift];
	}
	return k;
}


void key_generate()
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

    // Preps 8 rounds of keys
    for (int round = 0; round < 8; round++)
    {
    	// Divides 56 bit key to right and left
    	for (int i = 0; i < 28; ++i)
    	{
    		right[i] = key_56[i];
    	}
    	for (int i = 28; i < 56; ++i)
    	{
    		left[i-28] = key_56[i];
    	}

    	// Shifting the subkeys per their shift count
	    left = shift_left(left, shift_count[round]);
		right = shift_left(right, shift_count[round]);

		for(int i = 28; i < 56; ++i)
		{
			key_56[i] = left[i-28];
		}
		for(int i = 0; i < 28; ++i)
		{
			key_56[i] = right[i];
		}
		for(int i = 0; i < 48; ++i)
		{
			key_48[47-i] = key_56[56 - PC_2[i]];
		}
		key[round] = key_48;

		cout << "key " << round << ": " << key[round+1] << endl;
	}
}

int main()
{
	cout << "test";
	key_generate();
	return 0;
}