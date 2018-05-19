#include<iostream>
using namespace std;
void swap_by_ref(int &,int &);
void swap_by_val(int ,int );
int main()
{
	int n1,n2,n3,n4;
	cout<<"Enter the value of n1 , n2 , n3, n4\n";
	cin>>n1>>n2>>n3>>n4;
	swap_by_ref(n1,n2);
	swap_by_val(n3,n4);
	cout<<"After Swapping (n1 with n2) & (n3 with n4), Values are :\nn1 = "<<n1<<"\nn2 = "<<n2<<"\nn3 = "<<n3<<"\nn4 = "<<n4;
	cout<<"\nn3 and n4 aren't swapped cuz they were called by value.";
	return 0;
}
void swap_by_ref(int &a,int &b)
{
	a=a+b;
	b=a-b;
	a=a-b;
}
void swap_by_val(int a,int b)
{
	a=a+b;
	b=a-b;
	a=a-b;
}
