#include<iostream>
#include <string>  
#include <iomanip> 

using namespace std;

class Student
{
	public:
	int sushi;
	string name;
	int height;
	int weight;
	int getheight()
	{
		return height;
	}
	void print()
	{
		cout.fill('0');
	 	cout<<setw(6)<<sushi<<' '<<name<<' '<<height<<' '<<weight<<endl;
	}
}student[1000000];

int main()
{
	int sushi,height,weight;
	string name;
	int num=0;
	cin>>num;
	while(num--)
	{
		cin>>sushi>>name>>height>>weight;
		if(student[sushi].height<height)
		{
			student[sushi].sushi=sushi;
			student[sushi].name=name;
			student[sushi].height=height;
			student[sushi].weight=weight;
		}
	}
	for(int i=0;i<1000000;i++) 
	{
		if(student[i].height)
			student[i].print();
	}
	return 0;
}