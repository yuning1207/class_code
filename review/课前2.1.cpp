#include <iostream>
using namespace std;

int abs(int x)
{
        if(x<0)
                return -x;
        else
                return x;
}

long abs(long x)
{
        if(x<0)
                return -x;
        else
                return x;
}

double abs(double x)
{
        if(x<0)
                return -x;
        else
                return x;
}

int main(void)
{
        int x1;long x2;double x3;
        cin>>x1>>x2>>x3;
        cout<<"x1= "<<abs(x1)<<endl;
        cout<<"x2= "<<abs(x2)<<endl;
        cout<<"x3= "<<abs(x3)<<endl;
        return 0;
}
