#include <iostream.h>
#include <cstring>

using namespace std;

class Student
{
	string name;
	int number;
	int score;
	public:
	Student()
	{
	}
	void input(string name2,int number2,int score2)
	{
		name=name2;
		number=number2;
		score=score2;
	}
	void out()
	{
		cout<<name<<"  "<<number<<"  "<<score<<endl;
	}
};

int main(void)
{
	Student stu[5];
	Student * p;
	p=stu;
	int i=0; 
	string name1;
	int number1,score1;
	for(i;i<5;i++)
	{
		cin>>name1;
		cin>>number1;
		cin>>score1;
		stu[i].input(name1,number1,score1);
	}
	for(i=0;i<5;i++)
	{
		stu[i].out();
	}
	return 0;
}