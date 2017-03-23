#ifndef _STUDENT_H
#define _STUDENT_H

class student
{
	private:
	int number;
	char * name;
	Score s1;
	public:
	student(int number1,char * name1,Score s);
	~student();
	void modify(float score1);
	void print();	
};

class Score
{
	float computer;
	float english;
	float mathematics;
	public:
	Score(float x1,float y1,float z1);
	Score();
	void print();
	void modify(float x2,float y2,float z2);
};

#endif