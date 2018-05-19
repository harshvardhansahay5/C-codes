#include <iostream>
using namespace std;

int main() {
    char *str = "To be, or not to be, that is the question";
    puts(str);
    char *ptr;
    ptr = new char[strlen(str) + 1];
    strcpy(ptr, str);
    puts(ptr);
    delete ptr;
    return 0;
}