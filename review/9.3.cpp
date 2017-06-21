#include <iostream>
#include <cstring>
using namespace std;

const int size=100;
template<class T>

class Queue
{
	T q[size];
	int front,rear;
	public:
	Queue()
	{
		front=rear=0;
	}
	void put(T i)
	{
		q[rear++]=i;
	}
	T get()
	{
		return q[front++];
	}
};

int main(void)
{
	Queue <int> a;
	int m,n;
	cin>>m>>n;
	a.put(m);
	a.put(n);
	cout<<a.get()<<" ";
	cout<<a.get()<<endl;
	Queue <double> b;
	double x,y;
	cin>>x>>y;
	b.put(x);
	b.put(y);
	cout<<b.get()<<" ";
	cout<<b.get()<<endl;
	Queue <string> c;
	string s1,s2,s3;
	cin>>s1>>s2>>s3;
	c.put(s1);
	c.put(s2);
	c.put(s3);
	cout<<c.get()<<" ";
	cout<<c.get()<<" ";
	cout<<c.get()<<endl;
	return 0;
}