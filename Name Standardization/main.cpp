#include <iostream>
using namespace std;

int main() {
	char a[50],b[50]; int i=0,j=0,k=0;
	cout<<"Enter the Name:\t";
	gets(a);
	for(i=strlen(a)-1;;--i)
	{
		if(isalpha(a[i]))
			++k;
		if(k&&a[i]==' ')
			break;
	}
	for(k=0;j<i;++j)
		if((k==0||a[j-1]==' ')&&a[j]!=' ')
		{
			b[k++]=toupper(a[j]);
			b[k++]='.';
			b[k++]=' ';
		}
	for(;a[j]!='\0';++j)
	{
		if(j==i)
			b[k++]=toupper(a[++j]);
		else
			{
				if(a[j]==' ')
					break;
				b[k++]=tolower(a[j]);
			}
	}
	b[k]='\0';
	strcpy(a,b);
	a[0]=toupper(a[0]);
	puts(a);
	return 0;
}
