#include <iostream>

using namespace std;

class Rectangle
{
	private:
	double length;
	double width;
	public:
	Rectangle(double length1,double width1);
	double getArea();
};

Rectangle::Rectangle(double length1,double width1)
{
	length=length1;
	width=width1;
}

double Rectangle::getArea()
{
	return width*length;
}

int main()
{
	double x,y;
	cout<<"enter the length:"<<endl;
	cin>>x;
	if(x<0)
	{
		cout<<"false!"<<endl;
		exit(-1);
	}
		
	cout<<"enter the width:"<<endl;
	cin>>y;
	if(y<0)
	{
		cout<<"false!"<<endl;
		exit(-1);
	}	
	Rectangle re(x,y);
	cout<<"the area is: "<<re.getArea()<<endl;
	return 0;
} 