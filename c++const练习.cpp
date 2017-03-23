#include <iostream>

//using namespace std;

class Date
{
	int d,m,y;
	public:
	int day()const;
	int month()const;
	int year()const;
	Date(int d1,int m1,int y1);
};

Date::Date(int d1,int m1,int y1)
{
	d=d1;
	m=m1;
	y=y1;
}

inline int Date::day()const
{
	return d;
}

inline int Date::month()const
{
	return m;
}

inline int Date::year()const 
{
	return y; 
}

int main(void)
{
	int a,b,c;
	cout<<"enter the day:"<<endl;
	cin>>a;
	cout<<"enter the month:"<<endl;
	cin>>b;
	cout<<"enter the year:"<<endl;
	cin>>c;
	Date date(a,b,c);
	cout<<date.year()<<" "<<date.month()<<" "<<date.day()<<endl;
	return 0;
} 