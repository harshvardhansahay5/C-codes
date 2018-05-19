#include<iostream>
using namespace std;
int main()
{
   long int n, c, first=0, second=1, next;
   cout<<"Enter the number of terms of Fibonacci series you want:\t";
   cin>>n;
   cout<<"First "<<n<<" terms of Fibonacci series are :\t"<<endl;
   for (c=0;c<n;c++)
   {
      if (c<=1)
         next=c;
      else
      {
         next=first+second;
         first=second;
         second=next;
      }
      cout<<next<<endl;
   }
   return 0;
}