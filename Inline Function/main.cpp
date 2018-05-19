#include<iostream>
using namespace std;
inline int fact(int b)
{
    if (b==1||b==0)
        return 1;
    b*=fact(b-1);
    return b;
}
int main()
{
    int n;
    cout<<"Enter the Number whose Factorial is to be Found: ";
    cin>>n;
    cout<<"The factorial of "<<n<<" is "<<fact(n)<<".";
    return 0;
}
