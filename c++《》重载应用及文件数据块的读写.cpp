#include <iostream>
#include <fstream> 
#include <string>

using namespace std;

class Student
{
	private:
	int number;
	string name;
	float score;
	public:
	Student(int number1=0,string name1="noname",float score1=0);
	void modify(float score1)
	{
		score=score1;
	}
	friend istream & operator >>(istream & input,Student & stu)
	{
		cout<<"please input a student's number,name,score:\n";
		input>>stu.number>>stu.name>>stu.score;
		return input;
	}
	friend ostream & operator <<(ostream & output,Student & stu)
	{
		output<<"number: "<<stu.number<<" name: "<<stu.name<<" score: "<<stu.score<<endl;
		return output;
	}
}; 
Student::Student(int number1,string name1,float score1)
{
	number=number1;
	name=name1;
	score=score1;
}
int main(void)
{
	Student stu1,stu2;
	cin>>stu1;
	cin>>stu2;
	ofstream fout("stud.dat",ios::binary);
	fout.write((char * )&stu1,sizeof(stu1));
	fout.write((char * )&stu2,sizeof(stu2));
	fout.close();
	ifstream fin("stud.dat",ios::binary);
	fin.read((char * )&stu1,sizeof(stu1));
	fin.read((char * )&stu2,sizeof(stu2));
	cout<<"stu1 is: "<<stu1<<"stu2 is: "<<stu2;
	fin.close();
	return 0;
}