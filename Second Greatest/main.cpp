#include<iostream>
using namespace std;
int main ()
{
	int w,x,y,z;
	cout<<"Enter The First Number: ";
	cin>>w;
	cout<<"Enter The Second Number: ";
	cin>>x;
	cout<<"Enter The Third Number: ";
	cin>>y;
	cout<<"Enter The Fourth Number: ";
	cin>>z;
	if((w>x&&w>y&&w<z)||(w>x&&w<y&&w>z)||(w<x&&w>y&&w>z))
	cout<<"The First Number Is The Second Greatest.";
	else if((x>w&&x>y&&x<z)||(x>w&&x<y&&x>z)||(x<w&&x>y&&x>z))
	cout<<"The Second Number Is The Second Greatest.";
	else if((y>x&&y>w&&y<z)||(y>x&&y<w&&y>z)||(y<x&&y>w&&y>z))
	cout<<"The Third Number Is The Second Greatest.";
	else if((z>x&&z>y&&z<w)||(z>x&&z<y&&z>w)||(z<x&&z>y&&z>w))
	cout<<"The Fourth Number Is The Second Greatest.";
	else
	{
		cout<<"!!!ENTER VALID NUMBERS!!!!";
	}
	return 0;
}
