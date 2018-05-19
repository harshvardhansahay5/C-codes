#include<iostream>
using namespace std;
class STUDENT
{
	char name[20], Grade;
	long unsigned int rno;
	float sub1, sub2, sub3, percent;
	void percentage ();
	void grade ();
	public:
	STUDENT ()
	{
		strcpy(name,"No");
		Grade='Z';
		rno=0;
		sub1=sub2=sub3=percent=-1;
	}
	STUDENT (char a[], long unsigned int c, float d, float e, float f)
	{
		strcpy(name,a);
		rno=c;
		sub1=d;
		sub2=e;
		sub3=f;
		percentage();
		grade();
	}
	STUDENT (STUDENT &a)
	{
		strcpy(name,a.name);
		Grade=a.Grade;
		rno=a.rno;
		sub1=a.sub1;
		sub2=a.sub2;
		sub3=a.sub3;
		percent=a.percent;
		Grade=a.Grade;
	}
	~STUDENT ()
	{
		cout<<"\nBye "<<name;
	}
	void get_details ();
	void put_details ();
	char* ret_name()
	{
		return name;
	}
};
void STUDENT::get_details ()
{
	cout<<"Enter The Name Of The Student:\t";
	gets(name);
	cout<<"Enter His/Her Roll Number:\t";
	cin>>rno;
	do
	{
		cout<<"Enter The Marks Of The First Subject:\t";
		cin>>sub1;
	}while(sub1<0||sub1>100);
	do
	{
		cout<<"Enter The Marks Of The Second Subject:\t";
		cin>>sub2;
	}while(sub2<0||sub2>100);
	do
	{
		cout<<"Enter The Marks Of The Third Subject:\t";
		cin>>sub3;
	}while(sub3<0||sub3>100);
	percentage ();
	grade ();
}
void STUDENT::put_details()
{
	cout<<"\n\nName Of The Student:\t";
	cout<<name;
	cout<<"\nRoll Number:\t";
	cout<<rno;
	cout<<"\nThe Marks In First Subject:\t";
	cout<<sub1;
	cout<<"\nThe Marks In Second Subject:\t";
	cout<<sub2;
	cout<<"\nThe Marks In Third Subject:\t";
	cout<<sub3;
	cout<<"\nPercentage:\t";
	cout<<percent;
	cout<<"\nGrade:\t";
	cout<<Grade;
}
void STUDENT::percentage()
{
	percent=(sub1+sub2+sub3)/3;
}
void STUDENT::grade()
{
	if(percent<50)
	Grade='F';
	else if(percent<60)
	Grade='D';
	else if(percent<75)
	Grade='C';
	else if(percent<90)
	Grade='B';
	else if(percent<=100)
	Grade='A';
}
int main ()
{
	STUDENT a, b("Harshvardhan Sahay", 17, 95, 96, 97), c(b);
	a.get_details();
	a.put_details();
	b.put_details();
	c.put_details();
	return 0;
}
