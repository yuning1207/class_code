#include<iostream>
#include <string>
using namespace std;

class Vehicle
{
protected:
    string NO;//编号
public:
    Vehicle(string n)
	{				    
		NO = n;  
	}
    virtual int fee()=0;//计算应收费用
};

class Car:public Vehicle
{
	int weight,guest;
	public:
	Car(string n,int g,int w);
	int fee();
};
Car::Car(string n,int g,int w):Vehicle(n)
{
	weight=w;
	guest=g;
}
int Car::fee()
{
	return guest*8+weight*2;
}

class Truck:public Vehicle
{
	int weight;
	public:
	Truck(string n,int w);
	int fee();
};
Truck::Truck(string n,int w):Vehicle(n)
{
	weight=w;
}
int Truck::fee()
{
	return weight*5;
}

class Bus:public Vehicle
{
	int guest;
	public:
	Bus(string n,int g);
	int fee();
};

Bus::Bus(string n,int g):Vehicle(n)
{
	guest=g;
}
int Bus::fee()
{
	return guest*3;
}
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