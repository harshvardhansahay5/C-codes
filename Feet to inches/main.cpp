#include<iostream>
using namespace std;
int main()
{
    int feet;
    int inches;
    cout<<"Please enter the information as it appears on the screen"<<endl;
    cout<<"Enter amount of feet:\t";
    cin>>feet;
    cin.ignore();
    cout<<"Enter amount of inches:\t";
    cin>>inches;
    cin.ignore();
    inches+=12*feet;
    cout<<"Total Inches:\t";
    cout<<inches;
    return 0;
}