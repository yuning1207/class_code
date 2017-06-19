#include <iostream>
using namespace std;

class Rectangle
{
        double width,height;
public:
        void set(double m,double n)
        {
                width=m;
                height=n;
        }
        double getArea();
        double getPerimeter();
};
double Rectangle::getArea()
{
        return width*height;
}
double Rectangle::getPerimeter()
{
        return 2*(width+height);
}
int main(void)
{
        double m,n;
        cin>>m>>n;
        Rectangle c;
        c.set(m,n);
        cout<<c.getArea()<<endl;
        cout<<c.getPerimeter()<<endl;
        return 0;
}
