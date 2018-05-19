#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout << "Enter 2 numbers: ";
    cin >> a >> b;
    try {
        if (b != 0) {
            float div = (float) a / b;
            if (div < 0)
                throw 'e';
            cout << "a/b = " << div;
        } else
            throw b;

    } catch (int e) {
        cout << "Exception: Division by zero";
    } catch (char st) {
        cout << "Exception: Division is less than 0";
    } catch (...) {
        cout << "Exception: Unknown";
    }
    return 0;
}