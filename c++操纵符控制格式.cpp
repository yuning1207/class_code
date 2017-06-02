#include <iostream>
#include <iomanip>
using namespace std;
 
int main(void)
{
	int a=1999;
	double b=3.1415926;
	cout<<showpos<<a<<' '<<showpos<<scientific<<b<<endl;
	cout<<dec<<showpos<<a<<' '<<showpos<<uppercase<<scientific<<b<<endl;
	return 0;
}