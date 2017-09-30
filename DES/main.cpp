#include <iostream>
#include <vector>
using namespace std;

bitset<64> key_64;
bitset<48> key[8];

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

void key_gen()
{
    bitset<56> key_56;
    bitset<48> key_48;
    bitset<28> left;
    bitset<28> right;

    // Slimming down 64 bits key to 56 bits
    for (int i = 0; i < 56; ++i)
    {
        key_56[55-i] = key_64[64 - PC_1[i]];
    }

    // Preps 8 rounds of keys
    for (int round = 0; round < 8; ++round)
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
    }
}

// Pads the text with 'x'
string pad_text(string message_text)
{
    while ( (message_text.length() % 8) != 0)
    {
        message_text += 'x';
    }
    return message_text;
}

// Returns binary of 8 chars as a bitset
bitset<64> to_bits(string message_text)
{
    bitset<64> message;
    bitset<8> temp;

    for (int i = 0; i < message_text.length(); i++)
    {
        temp = (int(message_text[i]));
        message <<= 8;
        message |= (int(message_text[i]));
    }
    return message;
}

int main()
{
    string message_text = "12345678";
    string key_text = "KEY01234";

    message_text = pad_text(message_text);
    bitset<64> message = to_bits(message_text);                 // Convert plaintext to bits
    key_64 = to_bits(key_text);                                 // Convert key to bits

    cout << "message text: " << message_text << endl;			// pad test, delete later
    cout << "binary message: "<< message << endl;				// binary test, delete later
    cout << "64 bit key: " << key_64 << endl;                   // binary key test, delete later
    key_gen();

    return 0;
}