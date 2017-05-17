#include<iostream.h> 

using namespace std;

class complex //复数类声明
{ 
	public: //外部接口
	complex(double r=0.0,double i=0.0) //构造函数 
	{
		real=r;
		imag=i;
	} 
	complex operator + (complex c2); //+重载为成员函数
	complex operator - (complex c2); //-重载为成员函数
	void display(); //输出复数
	private: //私有数据成员 
	double real; //复数实部 
	double imag; //复数虚部
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
	cout<<"结果为："<<real<<"i+"<<imag<<endl; 
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