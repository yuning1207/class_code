#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
	string s;
	int a,b;
	getline(cin,s);
	a=s.find_last_of("/\\");//�᷵�ز��Ҷ���ַ����е�����λ�� 
	s[a]='\n';
	s+='\n';
	cout<<s;
	return 0;
}