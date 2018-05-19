#include<iostream>
using namespace std;
class student
{
	char name[25], course[15];
	long unsigned int rollno;
public:
	student ()
	{
		strcpy(name,"NoName");
		strcpy(course,"NoCourse");
		rollno=0;
	}
	void getdata()
	{
		cout<<"Enter the Name of the Student:\t";
		gets( name );
		cout<<"Enter "<<getname()<<"'s Course:\t";
		gets( course );
		rollno++;
	}
	char* getname()
	{
		return name;
	}
	void putdata()
	{
		cout<<"Name:\t"<<name<<endl;
		cout<<"Roll No.:\t"<<rollno<<endl;
		cout<<"Course:\t"<<course<<endl;
	}
};
class marks:private student
{
	float science, english, maths;
public:
	marks()
	{
		science=english=maths=0;
	}
	void getdata()
	{
		student::getdata();
		cout<<"Enter the Marks of "<<getname()<<" in Science:\t";
		cin>>science;
		cout<<"Enter the Marks of "<<getname()<<" in English:\t";
		cin>>english;
		cout<<"Enter the Marks of "<<getname()<<" in Mathematics:\t";
		cin>>maths;

	}
	void putdata()
	{
			student::putdata();
			cout<<"Science:\t"<<science<<endl;
			cout<<"English:\t"<<english<<endl;
			cout<<"Mathematics:\t"<<maths<<endl;
	}
	float return_avg ()
	{
		return (science+english+maths)/3;
	}
};
int main ()
{
	marks stud;
	stud.getdata();
	stud.putdata();
	cout<<"Average Marks of Three Students is:\t"<<stud.return_avg();
	return 0;
}
