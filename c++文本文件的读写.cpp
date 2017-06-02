#include <fstream>
#include <iostream>

using namespace std;

int main(void)
{
	char str1[80];
	ofstream fout("text1.txt");
	if(!fout)
	{
		cout<<"can't open file text1.txt\n";
		return 1;
	}
	fout<<"Learning C++ programming is fun!\n";
	fout.close();
	ifstream fin("text1.txt");
	if(!fin.is_open())
	{
		cout<<"can't open file.\n";
		return 1;
	}
	fin.getline(str1,80);
	cout<<str1<<endl;
	fin.close();
	return 0;
} 