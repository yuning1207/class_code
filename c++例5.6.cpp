#include <iostream>
#include <cstring>
using namespace std;

class my_string
{
	char * s;
	public:
	my_string(char * str);
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
	cout<<"Normal constructor called.\n";
	strcpy(s,str);
}

my_string input()
{
	char instr[80];
	cout<<"Enter a string: ";
	cin>>instr;
	my_string ob(instr); 
	return ob;
}

int main(void)
{
	my_string obj=input();
	obj.show();
	return 0;
}