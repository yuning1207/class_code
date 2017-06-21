#include <iostream>
#include <cstring>
using namespace std;

template <typename T>

T Max(T a,T b)
{
	if(a>b)
		return a;
	else
		return b;
}

int main(void)
{
	int a,b;
	char c,d;
	string s1,s2;
	cin>>a>>b;
	cin>>c>>d;
	cin>>s1>>s2;
	cout<<Max(a,b)<<endl;
	cout<<Max(c,d)<<endl;
	cout<<Max(s1,s2)<<endl;
	return 0;
} 