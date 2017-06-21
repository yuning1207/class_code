#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main(void)
{
	int i,n;
	cin>>n;
	string s;
	vector<string>name;
	for(i=0;i<n;i++)
	{
		cin>>s;
		name.push_back(s);
	}
	sort(name.begin(),name.end());
	for(i=0;i<n;i++)
	{
		cout<<name[i]<<endl;
	}
	return 0;
}