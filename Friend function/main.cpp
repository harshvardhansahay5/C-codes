#include <iostream>
using namespace std;
class Distance
{
    private:
        int meter, centimeter;
    public:
        Distance(int a, int b)
    		{
        		meter=a;
        		centimeter=b;
        }
        friend int conv(Distance);
};
int conv(Distance d)
{
    d.centimeter+=100*d.meter;
    return d.centimeter;
}

int main()
{
    Distance D(29,31);
    cout<<"Distance 29m 31cm in centimeters: "<<conv(D);
    return 0;
}