#include<iostream>
using namespace std;
int main()
{
	int a;
	cout<<"Enter the Number of The Day You Wish to See:\t";
	cin>>a;
	if(a==1)
		cout<<"Monday";
	if(a==2)
		cout<<"Tuesday";
	if(a==3)
		cout<<"Wednesday";
	if(a==4)
		cout<<"Thursday";
	if(a==5)
		cout<<"Friday";
	if(a==6)
		cout<<"Saturday";
	if(a==7)
		cout<<"Sunday";
	return 0;
}