#include <iostream>
#include <bitset>

using namespace std;


string to_string(bitset<64> bits)
{
    string str;
    for(int i = 0; i < 8; ++i)
    {
        char c = 0;
        for(int j = 7; j >= 0; j--){
            c = c + bits[i*8 + j];
            if(j!=0) c = c *2;//left shift
        }
        str.push_back(c);
    }
    return str;
}

int main()
{
	
	return 0;
}