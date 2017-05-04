#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
	queue <double> q;
	q.push(1.2);
	q.push(2.4);
	q.push(3.6);
	cout<<q.front()<<endl;
	q.pop();
	cout<<q.front()<<endl;
	q.pop();
	cout<<q.front()<<endl;
	q.pop();
	return 0;
} 