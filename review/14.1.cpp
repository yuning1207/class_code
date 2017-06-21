#include <iostream> 
using namespace std; 
// 你提交的代码将嵌入到这里

class X
{
	int * p;
	public:
	X()
	{
		p=new int[2];
		cout<<"X().		";
	}
	virtual ~X()
	{
		delete[]p;
		cout<<"~x().\n";
	}
};
class Y : public X
{
public:
   Y( ) { q = new int[1023]; cout << "Y( )    "; }
   ~Y( ) { delete [] q; cout << "~Y().    "; }
private:
   int* q;
};
int main()
{
  int n;
  cin>>n; 
  for (int i = 0; i < n; i++)
  {
    X* r = new Y;
    delete r;
  }
  return 0;
}