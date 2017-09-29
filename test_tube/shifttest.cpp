#include <iostream>
#include <string>
#include <bitset>

using namespace std;

int main()
{
	bitset<8> test(15);
	cout << (test << 2);
	return 0;
}