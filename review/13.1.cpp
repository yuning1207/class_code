#include<iostream>
#include <string>
using namespace std;
class Vehicle
{
protected:
    string NO;//编号
public:
    Vehicle(string n){				    NO = n;  }
    virtual int fee()=0;//计算应收费用
};

/* 请在这里填写答案 */
class Car :public Vehicle
{
	int guest,weight;
	public:
	Car(string no,int g,int w):Vehicle(no)
	{
		guest=g;
		weight=w;
	}
	int fee()
	{
		return guest*8+weight*2;
	}
};
class Truck:public Vehicle
{
	int weight;
	public:
	Truck (string no,int w):Vehicle(no)
	{
		weight=w;
	}
	int fee()
	{
		return weight*5;
	}
};
class Bus:public Vehicle
{
	int guest;
	public:
	Bus(string no,int g):Vehicle(no)
	{
		guest=g;
	}
	int fee()
	{
		return guest*3;
	}
};

int main()
{
    Car c("",0,0);
    Truck t("",0);
    Bus b("",0);
    int i, repeat, ty, weight, guest;
    string no;
    cin>>repeat;
    for(i=0;i<repeat;i++){
        cin>>ty>>no;
        switch(ty){
            case 1: cin>>guest>>weight; c=Car(no, guest, weight); cout<<no<<' '<<c.fee()<<endl; break;
            case 2: cin>>weight; t=Truck(no, weight); cout<<no<<' '<<t.fee()<<endl; break;
            case 3: cin>>guest; b=Bus(no, guest); cout<<no<<' '<<b.fee()<<endl; break;
        }
    }
    return 0;
}