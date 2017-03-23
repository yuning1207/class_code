#include <iostream>

using namespace std;

class counter{
	int value;
	public:
	counter(int number);
	void increment();//给原值加1 
	void decrement();//给原值减1
	int getvalue();//取得计数器的值
	void print();//显示计数器的值 
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
	cout<<"加1后的值："<<endl;
	t.print();
	cout<<"减1后的值："<<endl;
	t.decrement();
	t.print();
	cout<<"取其值："<<endl;
	cout<<t.getvalue()<<endl;
	cout<<"显示其值："<<endl;
	t.print();
	return 0;
}
 