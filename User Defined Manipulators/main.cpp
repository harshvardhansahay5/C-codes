#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int value;
	float a, b, c;
	a = 350;
	b = 200;
	c = a / b;
	cout << "Enter number:\t";
	cin >> value;
	cout << "Hexadecimal base:\t" << hex << value << endl;
	cout << "Octal base:\t" << oct << value << endl;
	cout << "Hexadecimal base:\t" << setbase(16);
	cout << value << endl;
	cout << "Octal base\t" << setbase(8) << value << endl;
	cout << setfill('*');
	cout << setw(5) << a << setw(5) << b << endl;
	cout << setw(6) << a << setw(6) << b << endl;
	cout << setw(7) << a << setw(7) << b << endl;
	cout << fixed << setprecision(2) << c << endl;
	return 0;
}
