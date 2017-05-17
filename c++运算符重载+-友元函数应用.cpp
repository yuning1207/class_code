#include<iostream.h> 

using namespace std;

class complex 
{ 
	public: 
	complex(double r=0.0,double i=0.0) 
	{
		real=r; 
		imag=i; 
	} //���캯��
	friend complex operator + (complex c1,complex c2); //���������+Ϊ��Ԫ����
	friend complex operator - (complex c1,complex c2); //���������-Ϊ��Ԫ���� 
	void display(); //��ʾ������ֵ
	private: //˽�г�Ա 
	double real; 
	double imag; 
};

complex operator +(complex c1,complex c2)
{
	complex c;
	c.real=c1.real+c2.real;
	c.imag=c1.imag+c2.imag;
	return c;
}

complex operator - (complex c1,complex c2)
{
	complex d;
	d.real=c1.real-c2.real;
	d.imag=c1.imag-c2.imag;
	return d;
}
void complex::display()
{
	cout<<"����ǣ�"<<endl;
	cout<<real<<"i+"<<imag<<endl;
}
int main(void)
{
	complex a(4.0,3.0);
	complex b(0.6,1.2);
	complex c,d;
	c=a+b;
	d=a-b;
	c.display();
	d.display();
	return 0;
}