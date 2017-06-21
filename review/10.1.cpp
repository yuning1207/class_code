#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main(void)
{
	vector<string>name;
	int i,n=0;
	string s;
	cin>>s;
	while(s.compare("end"))
	{
		name.push_back(s);
		cin>>s;
		n++;
	}
	sort(name.begin(),name.end());
	for(i=0;i<n;i++)
	{
		cout<<name[i]<<" ";
	}
	cout<<endl;
	return 0;
}