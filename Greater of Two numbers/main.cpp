#include<iostream>
using namespace std;
inline int Max(int x, int y)
{
    return (x > y)? x : y;
}
int main() {
    int a, b;
    cout<<"Enter the Numbers to be Compared"<<endl;
    cout<<"Enter the First Number:\t";
    cin>>a;
    cout<<"Enter the Second Number:\t";
    cin>>b;
    cout <<"Max ("<<a<<","<<b<<"):\t"<<Max(a,b)<<endl;
    return 0;
}