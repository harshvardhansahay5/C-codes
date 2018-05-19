#include<iostream>
using namespace std;
class complex
{
	int i,r;
public:
	void read()
	{
		cout<<"\nEnter Real Part:\t";
		cin>>r;
		cout<<"Enter Imaginary Part:\t";
		cin>>i;
	}
	void display()
	{
		cout<<r<<"+"<<i<<"i"<<"\n\n";
	}
	complex operator+(complex a2)
	{
		complex a;
		a.r=r+a2.r;
		a.i=i+a2.i;
		return a;
	}
	complex operator-(complex a2)
	{
		complex a;
		a.r=r-a2.r;
		a.i=i-a2.i;
		return a;
	}
	complex operator*(complex a2)
	{
		complex a;
		a.r=(r*a2.r)-(i*a2.i);
		a.i=(r*a2.i)+(i*a2.r);
		return a;
	}
	complex operator/(complex a2)
	{
		complex a;
		a.r=((r*a2.r)+(i*a2.i))/((a2.r*a2.r)+(a2.i*a2.i));
		a.i=((i*a2.r)-(r*a2.i))/((a2.r*a2.r)+(a2.i*a2.i));
		return a;
	}
};
int main()
{
	int ch;
	complex a,b,c;
	do
	{
		cout<<"\n1.Addition 2.Substraction";
		cout<<" 3.Mulitplication 4.Division 5.Exit\n";
		cout<<"\nEnter the choice:\t";
		cin>>ch;
		switch(ch)
		{
		case 1:  cout<<"\nEnter The First Complex Number:";
				 a.read();
				 cout<<"\na= ";
				 a.display();
				 cout<<"\nEnter The Second Complex Number:";
				 b.read();
				 cout<<"\nb= ";
				 b.display();
				 c=a+b;
				 cout<<"\nsum= ";
				 c.display();
				 break;
		case 2:  cout<<"\nEnter The First Complex Number:";
				 a.read();
				 cout<<"\na= ";
				 a.display();
				 cout<<"\nEnter The Second Complex Number:";
				 b.read();
				 cout<<"\nb= ";
				 b.display();
				 c=a-b;
				 cout<<"\ndifference= ";
				 c.display();
				 break;
		case 3:  cout<<"\nEnter The First Complex Number:";
				 a.read();
				 cout<<"\na= ";
				 a.display();
				 cout<<"\nEnter The Second Complex Number:";
				 b.read();
				 cout<<"\nb= ";
				 b.display();
				 c=a*b;
				 cout<<"\nproduct= ";
				 c.display();
				 break;
		case 4:  cout<<"\nEnter The First Complex Number:";
				 a.read();
				 cout<<"\na= ";
				 a.display();
				 cout<<"\nEnter The Second Complex Number:";
				 b.read();
				 cout<<"\nb= ";
				 b.display();
				 c=a/b;
				 cout<<"\nquotient= ";
				 c.display();
				 break;
		}
	}while(ch!=5);
	return 0;;
}