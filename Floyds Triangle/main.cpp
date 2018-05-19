#include<iostream>
using namespace std;
int main()
{
    int rows;
    cout<<"Number of rows of Floyd's triangle to print:";
    cin>>rows;
    for (int i=1; i<=rows; ++i)
    {
        for (int j=1,k=i; j<=i; ++j)
        {
            cout<<k++<<" ";
        }
        cout<<"\n";
    }
    return 0;
}