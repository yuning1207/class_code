#include <iostream>

using namespace std;

class counter{
	int value;
	public:
	counter(int number);
	void increment();//��ԭֵ��1 
	void decrement();//��ԭֵ��1
	int getvalue();//ȡ�ü�������ֵ
	void print();//��ʾ��������ֵ 
};

counter::counter(int number)
{
	value=number;
}

void counter::increment()
{
	value++;
}

void counter::decrement()
{
	value--;
}

int counter::getvalue()
{
	return value;
}

void counter::print()
{
	cout<<value<<endl;
}

int main(void)
{
	int x;
	cin>>x;
	counter t(x);
	t.increment();
	cout<<"��1���ֵ��"<<endl;
	t.print();
	cout<<"��1���ֵ��"<<endl;
	t.decrement();
	t.print();
	cout<<"ȡ��ֵ��"<<endl;
	cout<<t.getvalue()<<endl;
	cout<<"��ʾ��ֵ��"<<endl;
	t.print();
	return 0;
}
 