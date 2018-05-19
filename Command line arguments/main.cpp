#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    int sum = 0, i;
    if (argc < 2) {
        cout << "Please enter at least two arguments\nExiting";
        exit(0);
    }
    cout << "The sum of ";
    for (i = 1; i < argc; ++i) {
        if (i < argc - 1) {
            cout << strtol(argv[i], argv, 0);
        }
        if (i < argc - 2) {
            cout << ", ";
        }
        sum += strtol(argv[i], argv, 0);
    }
    cout << " and " << strtol(argv[i - 1], argv, 0) << " is " << sum << ".";
    return 0;
}