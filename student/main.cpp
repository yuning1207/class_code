#include <iostream>
#include <string.h>
#include "student.h"

using namespace std;

Score::Score(float x1,float y1,float z1)
{
	computer=x1;
	english=y1;
	mathematics=z1;
}
Score::Score()
{
	computer=60;
	english=60;
	mathematics=60;
}
void Score::print()
{
	cout<<"computer: "<<computer<<" english: "<<english<<" mathematics: "<<mathematics<<endl;
}
void Score::modify(float x2,float y2,float z2)
{
	computer=x2;
	english=y2;
	mathematics=z2;
}

void student::modify(Score s)
{
	s1.computer=s.computer;
	s1.english=s.english;
	s1.mathematics=s.mathematics;
}

student::student(int number1,char * name1,Score s)
{
	number=number1;
	name=new char [strlen(name1)+1];
	strcpy(name,name1);
	s1.computer=s.computer;
	s1.english=s.english;
	s1.mathematics=s.mathematics;
}

student::~student()
{
	delete []name;
}

void student::print()
{
	cout<<"number: "<<number<<" name: "<<name<<" score: "<<s1.computer<<" "<<s1.englishendl;
}

int main()
{
	int numberi;
	char namei[15];
	float score1,score2,score3;
	cout<<"enter number:"<<endl;
	cin>>numberi;
	cout<<"enter name:"<<endl;
	cin>>namei;
	cout<<"enter score:"<<endl;
	cin>>score1>>score2>>score3;
	Score s2(score1,score2,score3);
	student stu1(numberi,namei,s2);
	cout<<"enter number:"<<endl;
	cin>>numberi;
	cout<<"enter name:"<<endl;
	cin>>namei;
	student stu2(numberi,namei,s2);
	Score s3();
	stu2.modify(s3);
	stu1.print();
	stu2.print();
	return 0;
}