#include<iostream.h> 

using namespace std;

class complex //����������
{ 
	public: //�ⲿ�ӿ�
	complex(double r=0.0,double i=0.0) //���캯�� 
	{
		real=r;
		imag=i;
	} 
	complex operator + (complex c2); //+����Ϊ��Ա����
	complex operator - (complex c2); //-����Ϊ��Ա����
	void display(); //�������
	private: //˽�����ݳ�Ա 
	double real; //����ʵ�� 
	double imag; //�����鲿
}; 

complex complex::operator+(complex c2)
{
	complex c;
	c.real=real+c2.real;
	c.imag=imag+c2.imag;
	return c;
}

complex complex::operator-(complex c2)
{
	complex d;
	d.real=real-c2.real;
	d.imag=imag-c2.imag;
	return d;
}

void complex::display()
{
	cout<<"���Ϊ��"<<real<<"i+"<<imag<<endl; 
}
int main(void)
{
	complex a(4.0,5.0);
	complex b(1.0,2.0);
	complex c,d;
	c=a+b;
	d=a-b;
	c.display();
	d.display();
	return 0;
}