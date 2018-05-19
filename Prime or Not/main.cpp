#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int n;
	cout <<"Enter the Number to be Checked:\t";
	cin>>n;
	if(n<1)
	{
		cout<<"Invalid Input";
		exit(0);
	}
	if(n==1)
	{
		cout<<"Neither Prime nor Composite";
		exit(0);
	}
	if(n==2)
	{
		cout<<"Number is Composite";
		exit(0);
	}
	for(int i=2; i<=sqrt(n); ++i)
	{
		if((n%i)==0)
		{
			cout<<"Number is Composite";
			exit(0);
		}
	}
	cout<<"Number is Prime";
	return 0;
}
