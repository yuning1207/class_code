#include <iostream>
#include <cstring>
using namespace std;

int main(void)
{
	string a,b,c,m;
	int found,i;
	getline(cin,a);//��ȡһ�� 
	while(1)
	{
		getline(cin,m);
		if(!m.compare("end"))//m��"end"�Ƚϣ���ȷ���0��>����1��<����-1 
		{
			break;
		}
		a.append(m);//���ַ���m���ӵ���ǰ�ַ�����β 
	}
	cin>>b;
	cin>>c;
	found=a.find(b);//��a�в���b�������׵�ַ 
	while(found!=-1)
	{
		a.replace(found,b.length(),c);//�ӵ�һ������λ�ÿ�ʼɾ���ڶ��������������������������ַ����ӵ�һ�������� 
		found=a.find(b);
	}
	cout<<a<<endl;
	return 0;
} 