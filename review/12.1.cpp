#include <iostream>
#include <cstdlib>
using namespace std;
const int SIZE = 3;

class atype {
    int a[SIZE];
public:
   atype( ) {
       register int i;
       for(i=0; i<SIZE; i++) a[i] = i;
  }
  int &operator[](int i);
};
//���ύ�Ĵ��뽫��Ƕ�뵽����

int & atype::operator[](int i)
{
	if(i<0||i>SIZE-1)
	{
		cout<<endl<<"Index value of "<<i<<" is out-of-bounds."<<endl;
		exit(0);
	}
	return a[i];
}

int main( )
{
   atype ob;
   cin >> ob[1];  
   ob[2] = ob[1];  // �±������[]�����ڸ�ֵ���������ߺ��ұ� 
   cout << ob[2];  
   ob[3] = 44; // ��������ʱ�����±�3����������߽�
   return 0;
}