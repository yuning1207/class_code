#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
        int k;
        char c;
        int n,num;
        int i,j;
        cin>>k;
        while(1)
        {
                j=0;
                num=0;
                for(i=0;i<k;i++)
                {
                        j++;
                        cin>>n;
                        if(n>=100)
                        {
                                return 0;
                        }
                        num+=n;
                        c=cin.get();
                        if(c=='\n')
                        {
                                break;
                        }
                }
                cout<<num/j<<endl;
                cin.sync();
        }
        return 0;
}
