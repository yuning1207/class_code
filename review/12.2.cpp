#include <iostream>
using namespace std;

class complex
{
	double real,imag;
	public:
	complex(double r=0.0,double i=0.0);
	complex operator +(const complex & c);
	void print();
};

complex::complex(double r,double i)
{
	real=r;
	imag=i;
}
complex complex::operator+(const complex & c)
{
	double r,i;
	r=real+c.real;
	i=imag+c.imag;
	return complex(r,i);
}
void complex::print()
{
	cout<<real<<" + "<<imag<<"i"<<endl;
}

int main(void)
{
	double a,b,e,f;
	complex c;
	cin>>a>>b;
	cin>>e>>f;
	complex c1(a,b);
	complex c2(e,f);
	c=c1+c2;
	c.print();
	return 0;
}