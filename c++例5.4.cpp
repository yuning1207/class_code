#include <iostream>
#include <cstring>
using namespace std;

class my_string
{
	char * s;
	public:
	my_string(char * str);
	my_string(const my_string &obj);
	~my_string()
	{
		if(s)
			delete [] s;
		cout<<"Freeing s\n";
	}
	void show()
	{
		cout<<s<<"\n";
	}
};

my_string::my_string(char * str)
{
	s=new char[strlen(str)+1];
	cout<<"Allocating room for s\n";
	strcpy(s,str);
}

my_string::my_string(const my_string &obj)
{
	s=new char[strlen(obj.s)+1];
	strcpy(s,obj.s);
	cout<<"Copy constructor called.\n";
}

void display(my_string ob)
{
	ob.show();
}

int main(void)
{
	my_string obj("Hello!");
	display(obj);
	obj.show();
	return 0;
}