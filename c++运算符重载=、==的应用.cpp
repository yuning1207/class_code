#include <iostream>
#include <string>

using namespace std;
 
class String 
{ 
	public: 
	String(const char *str = NULL); //constructor 
	//String(const String &other); //copy constructor 
	~ String(void); //destructor 
	String & operate =(char *str); 
	String & operate =(const String &other);//重载=运算符
	int operator==(String &other); //重载==运算符
	int operator==(char *str); 
	private: 
	char *m_data; //used for storing the string 
	int length; 
}; 

String::String(const char * str=NULL)
{
	m_data=new char[strlen(str)+1];
	strcpy(m_data,str);
}
String::~ String(void)
{
	delete m_data;
}
int main(void)
{
	return 0;
}