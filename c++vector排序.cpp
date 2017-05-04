#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main()
{
	int n=0;
	int i;
	string str;
	vector<string> name;
	cin>>str;
	while(str.compare("end")!=0)
	{
		name.push_back(str);
		cin>>str;
		n++;
	}
	sort(name.begin(),name.end());
	for(i=0;i<n;i++)
	{
		cout<<name[i]<<' ';
	}
	cout<<endl;
}