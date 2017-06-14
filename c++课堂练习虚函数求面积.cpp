#include <iostream>
#include <cmath>
using namespace std;

class Figure {
public:
    virtual double getArea() = 0; // ´¿ÐéÄâº¯Êý
};

class Rectangle :  public Figure
{ 
protected:
    double height;
    double width;
public:
    Rectangle( ){};
    Rectangle(double height, double width)
    {
      this->height = height;
      this->width = width;
    }
    double getArea ( )
    {
      return  height*width;
    }
};

class Square : public Rectangle{ 
public:
    Square(double width)
  	{
		this->height=this->width=width;
    }
};

class Triangle : public Figure {
    double la;
    double lb;
    double lc;
public:
	Triangle(double la, double lb, double lc) 
	{
      this->la = la; 
	  this->lb = lb; 
	  this->lc = lc;
    }
    double getArea() 
   	{
      double s = (la+lb+lc)/2.0;
      return sqrt(s*(s-la)*(s-lb)*(s-lc));
    }
};

int main(void) 
{
    Figure* figures[3] = {
         new Triangle(2,3,3), new Rectangle(5,8), new Square(5) };
    for (int i = 0; i < 3; i++) 
	{
         cout<<(figures[i])->getArea()<<endl;
    }
    return 0;
}