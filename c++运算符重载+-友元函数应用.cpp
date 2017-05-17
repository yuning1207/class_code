#include<iostream.h> 

using namespace std;

class complex 
{ 
	public: 
	complex(double r=0.0,double i=0.0) 
	{
		real=r; 
		imag=i; 
	} //构造函数
	friend complex operator + (complex c1,complex c2); //重载运算符+为友元函数
	friend complex operator - (complex c1,complex c2); //重载运算符-为友元函数 
	void display(); //显示复数的值
	private: //私有成员 
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
	cout<<"结果是："<<endl;
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