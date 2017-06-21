#include <iostream>
using namespace std;

class shape {
public:
  double getArea(){ return -1; }// 求面积
  double getPerimeter(){ return -1;  } // 求周长
};

/* 你提交的代码将被嵌入到这里 */
const double PI=3.1415926;
class Circle :public shape
{
	double radius;
	public:
	Circle(double r)
	{
		radius=r;
	}
	double getArea()
	{
		return PI*radius*radius;
	}
	double getPerimeter()
	{
		return 2*PI*radius;
	}	
};

int main() {
  double r;
  cin>>r;
  Circle c(r);
  cout<<c.getArea()<<endl;
  cout<<c.getPerimeter()<<endl;
  return 0;
}
/* 请在这里填写答案 */