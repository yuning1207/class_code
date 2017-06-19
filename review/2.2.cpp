#include <iostream>
using namespace std;

int area(int x,int y);
int area(int x,int y,int z);

int area(int x,int y)
{
        return (x*y);
}

int area(int x,int y,int z)
{
        return (x*y+x*z+y*z)*2;
}

int main(void)
{
        int repeat,i,c,x,y,z;
        cin>>repeat;
        for(i=0;i<repeat;i++)
        {
              cin>>c;
              if(c==2)
              {
                      cin>>x>>y;
                      cout<<area(x,y);
              }
              else if(c==3)
              {
                      cin>>x>>y>>z;
                      cout<<area(x,y,z);
              }
        }
        return 0;
}
