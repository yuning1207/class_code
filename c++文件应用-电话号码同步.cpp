#include <iostream>
#include <set>
#include <fstream> 
#include <string>

using namespace std;

int main(void)
{
	int i=0;
	char str[256];
	set<char> a;
	set<char>::iterator p;
	ifstream fin1("phonebook1.txt");
	if(!fin1.is_open())
	{
		cout<<"can't open file.\n";
		return 1;
	}
	while(!fin1.eof())
	{
		fin1.getline(str,80);
		a.insert(* str);
	}
	ifstream fin2("phonebook2.txt");
	if(!fin2.is_open())
	{
		cout<<"can't open file.\n";
		return 1;
	}
	while(!fin2.eof())
	{
		fin2.getline(str,80);
		a.insert(* str);
	}
	ofstream fout("phonebook3.txt");
	p=a.begin();
	while(p!=a.end())
	{
		fout<<*p++<<endl;
	}
}