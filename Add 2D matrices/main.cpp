#include<iostream>
using namespace std;
int main()
{
    int add[10][10], i, j, k, l;
    cout<<"Enter the Number of Rows and Columns in the First Array"<<endl;
    cout<<"Rows:\t";
    cin>>i;
    cout<<"Columns:\t";
    cin>>j;
    cout<<"\nEnter the Number of Rows and Columns in the Second Array"<<endl;
    cout<<"Rows:\t";
    cin>>k;
    cout<<"Columns:\t";
    cin>>l;
    if(i!=k||j!=l)
    {
        cout<<"\n!!!Addition Not Possible!!!";
        exit(0);
    }
    cout<<"Enter the First 3d Array (Row Major)\n";
    for(int r=0;r<i;r++)
        for(int c=0;c<j;c++)
            cin>>add[r][c];
    cout<<"\nThe First Matrix is:";
    for(int r=0;r<i;r++)
    {
        cout<<"\n\n";
        for(int c=0;c<j;c++)
        {
            cout<<add[r][c]<<"  ";
        }
    }
    cout<<"\nEnter the Second 3d Array (Row Major)\n";
    for(int r=0;r<i;r++)
        for(int c=0;c<j;c++)
        {
            cin>>k;
            add[r][c]+=k;
        }
    cout<<"\nThe Addition of Both Matrices is:";
    for(int r=0;r<i;r++)
    {
        cout<<"\n\n";
        for(int c=0;c<j;c++)
        {
            cout<<add[r][c]<<"  ";
        }
    }
    return 0;
}