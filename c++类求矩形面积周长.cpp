#include <iostream>
using namespace std;
//���ύ�Ĵ��뽫Ƕ�뵽����
class Rectangle
{
	double width;
	double height;
	public:
	void set(double m,double n)
	{
		width=m;
		height=n;
	}
	double getArea(void)
	{
		double s;
		s=width*height;
		return s;
	}
	double getPerimeter(void)
	{
		double c;
		c=2*(width+height);
		return c;
	}
};
int main()
{    
    double m,n;
    cin>>m;
    cin>>n;
    Rectangle a;
    a.set(m,n);
    cout<<a.getArea()<<endl;
    cout<<a.getPerimeter()<<endl;
    return 0;
}