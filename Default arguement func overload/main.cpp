#include<iostream>
using namespace std;
int area(int);
int area(int,int);
float area(float);
float area(float,float);
int main()
{
	int s,l,b;
	float r,bs,ht;
	cout<<"Enter side of a square:\t";
	cin>>s;
	cout<<"Enter length and breadth of rectangle:\t";
	cin>>l>>b;
	cout<<"Enter radius of circle:\t";
	cin>>r;
	cout<<"Enter base and height of triangle:\t";
	cin>>bs>>ht;
	cout<<"Area of square is:\t"<<area(s);
	cout<<"\nArea of rectangle is:\t"<<area(l,b);
    cout<<"\nArea of circle is:\t"<<area(r);
    cout<<"\nArea of triangle is:\t"<<area(bs,ht);
}
int area(int s=0)
{
    return(s*s);
}
int area(int l=0,int b=0)
{
    return(l*b);
}
float area(float r=0)
{
    return(3.14*r*r);
}
float area(float bs=0,float ht=0)
{
   return((bs*ht)/2);
}