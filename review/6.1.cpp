#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

class Student
{
	public:
	int weight;
	int height;
	string name;
	int number;
	int getheight();
	void print();
}stu[1000000];

int Student::getheight()
{
	return height;
}

void Student::print()
{
	cout.fill('0');
	cout<<setw(6)<<number<<" "<<name<<" "<<height<<" "<<weight<<" "<<endl;
}
int main(void)
{
	int height,weight,number,n,i=0;
	string name;
	cin>>n;
	while(n--)
	{
		cin>>number>>name>>height>>weight;
		if(height>stu[number].height)
		{
			stu[number].name=name;
			stu[number].height=height;
			stu[number].weight=weight;
			stu[number].number=number;
		}
		if(name.length()>=16)
		{
			cout<<"姓名输入长度没有小于16！"<<endl;
			return 0;
		}
	}
	while(i<1000000)
	{
		if(stu[i].height)
		{
			stu[i].print();
		}
		i++;
	}
	return 0;
}