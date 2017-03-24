#include <iostream>
#include <string>
using namespace std;
int main()
{
	std::string str,str0,str1,str2;
	int found;
	getline(cin,str);
	while(1){
		getline(cin,str0);
		if(str0.compare("end") == 0)  break;
		str+='\n';
		str+=str0;
	}
	str+='\n';
	cin>>str1>>str2;
	found = str.find(str1);
	while(found != -1)
	{
		str.replace(found,str1.length(),str2);
		found = str.find(str1,found + 1);
	}
	cout<<str;
	return 0;
} 