#include <iostream>

using namespace std;

template <typename T>

T abs(T x)
{
	if(x<0)
		return -x;
	else
		return x;
}

int main(void)
{
	int a=2;
	float b=-1.2;
	cout<<abs(a)<<endl<<abs(b)<<endl;
	return 0;
} 