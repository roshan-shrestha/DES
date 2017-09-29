#include <iostream>
#include <vector> 
using namespace std;

bitset<64> to_bits(string message_text)
{
	bitset<64> message;
	bitset<8> temp;

	for (int i = 0; i < message_text.length(); i++)
	{
		temp = (int(message_text[i]));
		cout << temp << " ";

		message <<= 8;
		message |= (int(message_text[i]));
	}
	return message;
}

int main()
{
	string message_text = "this1234";
	bitset<64> message = to_bits(message_text);

	cout << endl << message;
	return 0;
}