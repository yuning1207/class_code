#include <iostream>
using namespace std;

class Triangle
{
	double width,height;
	public:
	Triangle(double w,double h);
	double getArea();
};

Triangle::Triangle(double w,double h)
{
	width=w;
	height=h;
}

double Triangle::getArea()
{
	return width*height/2;
}
int main(void)
{
	double w,h;
	cin>>w>>h;
	Triangle t(w,h);
	cout<<"The area of the Triangle is: "<<t.getArea()<<endl;
	return 0;
} 
