#include <iostream>
#include <vector>
using namespace std;

bitset<64> key;
bitset<48> key2[16];

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
    string message_text = "12345678x";
    string key_text = "KEY01234";

    key = to_bits(key_text);

    message_text = pad_text(message_text);
    cout << message_text << endl;			// pad test

    bitset<64> message = to_bits(message_text);
    cout << message << endl;				// binary test
    return 0;
}