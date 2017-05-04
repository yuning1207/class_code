#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void load(vector <int> &);
void print(vector <int>);

void load(vector <int> & v)
{
	int i=0;
	for(i;i<5;i++)
	{
		v[i]=i;
	}
}
void print(vector <int> v)
{
	int i=0;
	for(i;i<5;i++)
	{
		cout<<v[i]<<endl;
	}
	cout<<endl;
}
int main(void)
{
	vector <int> v(5);
	load(v);
	sort(v.begin(),v.end());
	print(v);
	return 0;
}
 