#include <iostream>
#include <cmath> 
using namespace std;

class shape {// ������
public:
 virtual double getArea()=0;// �����
 virtual double getPerimeter()=0; // ���ܳ�
};

class RPentagon:public shape
{
	double s1;
	public:
	RPentagon(double s2)
	{
		s1=s2;
	}
	double getArea()
	{
		return s1*s1*sqrt(25+10*sqrt(5))/4;
	}
	double getPerimeter()
	{
		return 5*s1;
	}
};
int main()
{
  double s;
  cin>>s;
  RPentagon p(s);
  cout<<p.getArea()<<endl;
  cout<<p.getPerimeter()<<endl;				
}